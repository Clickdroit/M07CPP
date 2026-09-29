# 🛰️ M07CPP — Programmation Réseau C++ & Télémétrie Drone (UDP / TCP)

Projet de programmation système et réseau en **C++ moderne** avec **CMake**, implémentant des architectures client/serveur UDP et TCP pour le contrôle et la capture de télémétrie en temps réel (notamment pour drone **DJI Tello**).

---

## 📋 Présentation du projet

Ce projet met en œuvre des sockets bas-niveau pour échanger des datagrammes et des flux réseau entre différentes entités :
1. **Pilotage & Contrôle UDP :** Envoi de commandes de vol et réceptions d'acquittements vers le drone (ou simulateur).
2. **Serveur de Télémétrie UDP :** Écoute passive sur les flux de télémétrie du drone (`0.0.0.0:8890`), décodage des trames d'état en direct et journalisation.
3. **Parseur de Télémétrie vers JSON :** Conversion des trames de vol brutes en objets JSON structurés.
4. **Client TCP / HTTP :** Envoi des données de télémétrie agrégées vers une API REST via requêtes HTTP `POST`.

```
                    +------------------------------------+
                    |       Drone DJI Tello (ou Simu)    |
                    +-----------------+------------------+
                             ^                 |
                 Commandes   |                 | Données de vol
                 UDP (8889)  |                 | UDP (8890)
                             |                 v
                    +--------+-------+   +-----+--------------+
                    | TelloClientUDP |   |    IRServeurUDP    |
                    | (ClientUDP)    |   |    (ServeurUDP)    |
                    +----------------+   +-----+--------------+
                                               |
                                               v
                                        +--------------+
                                        | Parseur JSON |
                                        +------+-------+
                                               |
                                               v
                                        +--------------+
                                        | IRClientTCP  | ---> API REST (HTTP POST)
                                        +--------------+
```

---

## 🛠️ Composants & Architecture

### 1. `ClientUDP` (Contrôle & Pilotage)
- **`TelloClientUDP`** : Encapsulation des commandes de vol du SDK Tello (`command`, `takeoff`, `land`, déplacements dans l'espace `x y z`, rotations).
- **`IRClientUDP`** : Classe wrapper pour sockets UDP en C++ (émission et réception de datagrammes).
- **`IRClientTCP`** : Client socket TCP permettant la communication avec des serveurs d'API HTTP REST.
- **Menu interactif** : Interface CLI permettant d'exécuter et d'enchaîner des manœuvres de vol.

### 2. `ServeurUDP` (Serveur de Télémétrie)
- **`IRServeurUDP`** : Socket serveur UDP non-bloquante écoutant en écoute passive.
- **Champs de télémétrie décodés :**
  - **Attitude :** `pitch`, `roll`, `yaw`
  - **Vélocité :** `vgx`, `vgy`, `vgz`
  - **Accélération :** `agx`, `agy`, `agz`
  - **Capteurs :** Batterie (`bat`), Hauteur (`h`), Capteur de distance ToF (`tof`), Baromètre (`baro`), Température (`templ`, `temph`).
- **Journalisation :** Écriture automatique des trames horodatées dans `serveur.log` et conversion en flux JSON.

---

## ⚙️ Compilation & Exécution

### Prérequis
- Compilateur C++ supportant **C++17** ou supérieur (GCC, Clang ou MSVC).
- **CMake 3.20+**.

### Compilation avec CMake
```bash
# Générer les fichiers de build
cmake -B build -S .

# Compiler tous les exécutables
cmake --build build --config Release
```

### Lancement
- **Lancer le serveur de télémétrie :**
  ```bash
  ./build/ServeurUDP/ServeurUDP
  ```
- **Lancer le client de pilotage :**
  ```bash
  ./build/ClientUDP/ClientUDP
  ```

---

## 🔬 Analyse Réseau & Wireshark
Le projet inclut une validation des trames réseau et des temps de réponse via captures Wireshark (`.pcapng`) pour garantir l'intégrité et la faible latence des flux UDP.
