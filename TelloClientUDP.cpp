//
// Created by Maxime on 23/09/2026.
//

#include "TelloClientUDP.h"

TelloClientUDP::TelloClientUDP() {
    client.OuvrirLaSocketDeCommunication("127.0.0.1", 8889);
}

string TelloClientUDP::EnvoyerCommande(string commande) {
    if (!client.EnvoyerUnMessage(commande)) {
        return "";
    }
    string reponse;
    int nbOctets = client.RecevoirUnMessage(reponse, 500);
    if (nbOctets > 0) {
        return reponse;
    }
    return "";
}

string TelloClientUDP::ModeCommande() {
    return EnvoyerCommande("command");
}
string TelloClientUDP::Decoller(){
    return EnvoyerCommande("takeoff");
}

string TelloClientUDP::Atterrir() {
    return EnvoyerCommande("land");
}
string TelloClientUDP::Monter(int cm) {
    return EnvoyerCommande("up " + to_string(cm));
}
string TelloClientUDP::Descendre(int cm) {
    return EnvoyerCommande("down " + to_string(cm));
}
string TelloClientUDP::Gauche(int cm) {
    return EnvoyerCommande("left " + to_string(cm));
}
string TelloClientUDP::Droite(int cm) {
    return EnvoyerCommande("right " + to_string(cm));
}
string TelloClientUDP::Avant(int cm) {
    return EnvoyerCommande("forward " + to_string(cm));
}
string TelloClientUDP::Arriere(int cm) {
    return EnvoyerCommande("back " + to_string(cm));
}
string TelloClientUDP::TournerHoraire(int deg) {
    return EnvoyerCommande("cw " + to_string(deg));
}
string TelloClientUDP::TournerTrigo(int deg) {
    return EnvoyerCommande("ccw " + to_string(deg));
}