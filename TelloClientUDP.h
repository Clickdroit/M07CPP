//
// Created by Maxime on 23/09/2026.
//

#ifndef UNTITLED_TELLOCLIENTUDP_H
#define UNTITLED_TELLOCLIENTUDP_H
#include "IRClientUDP.h"
using namespace std;


class TelloClientUDP {
    private:
        IRClientUDP client;
    public:
        TelloClientUDP();
        string EnvoyerCommande(string commande);
        string ModeCommande();
        string Decoller();
        string Atterrir();
        string Monter(int cm);
        string Descendre(int cm);
        string Gauche(int cm);
        string Droite(int cm);
        string Avant(int cm);
        string Arriere(int cm);
        string TournerHoraire(int deg);
        string TournerTrigo(int deg);
};


#endif //UNTITLED_TELLOCLIENTUDP_H
