#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include "TelloClientUDP.h"

using namespace std;

void AfficherReponse(const string& commande, const string& reponse) {
    cout << commande << " : "
         << (reponse.empty() ? "aucune reponse recue" : reponse) << endl;
}

    }
    while (choix[0] != 'Q' && choix[0] != 'q');
    return 0;
}