#include <iostream>
#include "TelloClientUDP.h"

using namespace std;

void AfficherReponse(const string& commande, const string& reponse) {
    cout << commande << " : "
         << (reponse.empty() ? "aucune reponse recue" : reponse) << endl;
}

int main() {
    TelloClientUDP client;
    cout << "Test du simulateur local sur 127.0.0.1:8889" << endl;

    AfficherReponse("command", client.ModeCommande());
    AfficherReponse("takeoff", client.Decoller());
    AfficherReponse("right 50", client.Droite(50));
    AfficherReponse("land", client.Atterrir());
    return 0;
}
