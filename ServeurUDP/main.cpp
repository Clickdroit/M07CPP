#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "IRServeurUDP.h"

using namespace std;

struct DonneesVol {
    int pitch;
    int roll;
    int yaw;
    int vgx;
    int vgy;
    int vgz;
    int templ;
    int temph;
    int tof;
    int h;
    int bat;
    float baro;
    int time;
    float agx;
    float agy;
    float agz;
};

bool ExtraireDonneesVol(const string& message, DonneesVol& donnees) {
    const int champsLus = sscanf(
        message.c_str(),
        "pitch:%d;roll:%d;yaw:%d;vgx:%d;vgy:%d;vgz:%d;templ:%d;temph:%d;tof:%d;h:%d;bat:%d;baro:%f;time:%d;agx:%f;agy:%f;agz:%f;",
        &donnees.pitch, &donnees.roll, &donnees.yaw,
        &donnees.vgx, &donnees.vgy, &donnees.vgz,
        &donnees.templ, &donnees.temph, &donnees.tof,
        &donnees.h, &donnees.bat, &donnees.baro, &donnees.time,
        &donnees.agx, &donnees.agy, &donnees.agz);
    return champsLus == 16;
}

void AfficherDonneesVol(const DonneesVol& d) {
    cout << "Donnees extraites :\n"
         << "  pitch=" << d.pitch << ", roll=" << d.roll << ", yaw=" << d.yaw << '\n'
         << "  vgx=" << d.vgx << ", vgy=" << d.vgy << ", vgz=" << d.vgz << '\n'
         << "  templ=" << d.templ << ", temph=" << d.temph << '\n'
         << "  tof=" << d.tof << ", h=" << d.h << ", bat=" << d.bat << '\n'
         << "  baro=" << d.baro << ", time=" << d.time << '\n'
         << "  agx=" << d.agx << ", agy=" << d.agy << ", agz=" << d.agz << endl;
}

int main()
{
    IRServeurUDP serveur;
    string message;
    int octets;
    if (!serveur.OuvrirLaSocketDEcoute(8890, "0.0.0.0")){
        cout << "Erreur socket" << endl;
        return 1;
    }
    ofstream fichier("serveur.log", ios::app);
    if (!fichier){
        cout << "Erreur fichier" << endl;
        return 1;
    }
    cout << "Serveur en attente..." << endl;
    octets = serveur.RecevoirUnMessage(message,30000000);
    while (octets > 0){
        cout << message << endl;
        DonneesVol donnees{};
        if (ExtraireDonneesVol(message, donnees)) {
            AfficherDonneesVol(donnees);
        } else {
            cout << "Trame recue, mais son format ne correspond pas aux 16 champs attendus." << endl;
        }
        fichier << message << endl;
        octets = serveur.RecevoirUnMessage(message, 30000000);
    }
    if (octets < 0){
        cout << "Erreur reception" << endl;
    }
    else{
        cout << "Fin du serveur" << endl;
    }
    fichier.close();
    return 0;
}
