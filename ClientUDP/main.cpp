#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include "TelloClientUDP.h"

using namespace std;

int main()
{
    string IP = "127.0.0.1";
    ifstream f("telloConfig.txt");
    if (f.is_open()){
        f >> IP;
        f.close();
    }
    else{
        ofstream fichierConfig("telloConfig.txt");
        fichierConfig << "192.168.10.1";
        fichierConfig.close();
    }
    cout << "Connexion au drone : " << IP << endl;
    TelloClientUDP drone(IP);
    char choix[100];
    int x;
    int a;
    int dx, dy, dz;
    do{
        cout << "\n==============================" << endl;
        cout << "       PILOTAGE TELLO" << endl;
        cout << "==============================" << endl;
        cout << "\tC\tdecoller\n";
        cout << "\tS\tatterrir\n";
        cout << "\tH\thaut     [H=25cm HH=50cm HHH=75cm]\n";
        cout << "\tB\tbas      [B=25cm BB=50cm BBB=75cm]\n";
        cout << "\tG\tgauche   [G=25cm GG=50cm GGG=75cm]\n";
        cout << "\tD\tdroite   [D=25cm DD=50cm DDD=75cm]\n";
        cout << "\tA\tavance   [A=25cm AA=50cm AAA=75cm]\n";
        cout << "\tR\trecul    [R=25cm RR=50cm RRR=75cm]\n";
        cout << "\tP\trotation horaire [P=30deg PP=60deg]\n";
        cout << "\tT\trotation trigo   [T=30deg TT=60deg]\n";
        cout << "\tX\tdeplacement XYZ\n";
        cout << "\tM\tmode commande\n";
        cout << "\tQ\tquitter\n";
        cout << "\nCommande : ";
        cin >> choix;
        string reponse;
        x = strlen(choix) * 25;
        if (x > 100){
            x = 100;
        }
        a = strlen(choix) * 30;
        if (a > 180){
            a = 180;
        }
        switch (choix[0]){
            case 'c':
            case 'C':
                reponse = drone.Decoller();
                break;
            case 's':
            case 'S':
                reponse = drone.Atterrir();
                break;
            case 'h':
            case 'H':
                reponse = drone.Monter(x);
                break;
            case 'b':
            case 'B':
                reponse = drone.Descendre(x);
                break;
            case 'g':
            case 'G':
                reponse = drone.Gauche(x);
                break;
            case 'd':
            case 'D':
                reponse = drone.Droite(x);
                break;
            case 'a':
            case 'A':
                reponse = drone.Avant(x);
                break;
            case 'r':
            case 'R':
                reponse = drone.Arriere(x);
                break;
            case 'p':
            case 'P':
                reponse = drone.TournerHoraire(a);
                break;
            case 't':
            case 'T':
                reponse = drone.TournerTrigo(a);
                break;
            case 'x':
            case 'X':
                cout << "Entrer X Y Z : ";
                cin >> dx >> dy >> dz;
                reponse = drone.go(dx, dy, dz, 100);
                break;
            case 'm':
            case 'M':
                reponse = drone.ModeCommande();
                break;
            case 'q':
            case 'Q':
                cout << "Arret du programme." << endl;
                break;
            default:
                cout << "Commande inconnue." << endl;
                continue;
        }
        if (choix[0] != 'q' && choix[0] != 'Q'){
            cout << "Reponse du drone : " << reponse << endl;
        }

    }
    while (choix[0] != 'Q' && choix[0] != 'q');
    return 0;
}