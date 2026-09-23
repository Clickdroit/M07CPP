# Roadmap — TP TelloClientUDP

Les cases cochées correspondent aux éléments vérifiés dans le projet.

### 1. Préparer les fichiers

- [x] Conserver un seul `TelloClientUDP.h`.
- [x] Créer le fichier `TelloClientUDP.cpp` associé.
- [x] Ajouter les fichiers à CMake et la bibliothèque réseau Windows.

### 2. Déclarer la classe dans le `.h` — terminé

- [x] Déclarer l’attribut privé `IRClientUDP client`.
- [x] Déclarer le constructeur et toutes les méthodes demandées.
- [x] Corriger deux noms pour correspondre au sujet : `Aterrir` → `Atterrir` et `TournerHorraire` → `TournerHoraire`.

### 3. Définir le constructeur

- [x] Écrire le constructeur dans `TelloClientUDP.cpp`.
- [x] Y ouvrir la socket de communication.

Le constructeur ouvre maintenant la socket vers `127.0.0.1`, port `8889` (simulateur sur le même ordinateur).

### 4. Définir `EnvoyerCommande`

- [x] Envoyer la commande avec `client.EnvoyerUnMessage`.
- [x] Recevoir la réponse avec `client.RecevoirUnMessage`.
- [x] Renvoyer le message reçu si la réception réussit.
- [x] Prévoir le résultat en cas d’absence de réponse ou d’erreur.

Le délai de réception est fixé à 5 secondes (`5000000` microsecondes). Un échec d’envoi ou une absence de réponse entraîne un retour vide.

### 5. Définir les commandes simples

- [x] `ModeCommande()`.
- [x] `Decoller()`.
- [x] `Atterrir()`.

Chaque méthode doit appeler `EnvoyerCommande` et retourner son résultat.

### 6. Définir les commandes avec paramètre

- [x] `Monter(cm)` et `Descendre(cm)`.
- [x] `Gauche(cm)` et `Droite(cm)`.
- [x] `Avant(cm)` et `Arriere(cm)`.
- [x] `TournerHoraire(deg)` et `TournerTrigo(deg)`.

Chaque commande est construite avec sa valeur via `to_string`, puis transmise à `EnvoyerCommande`. Le sujet propose `stringstream` en exemple ; `to_string` convient également ici.

### 7. Compléter le programme principal — commencé

- [x] Écrire un premier envoi de commandes : `command`, `takeoff`, `right 50`.
- [x] Utiliser un objet `TelloClientUDP` et ses méthodes.
- [x] Vérifier l’adresse du destinataire : `127.0.0.1` désigne actuellement ton propre ordinateur.
- [x] Compléter le scénario de pilotage, notamment l’atterrissage.
- [ ] Vérifier la compilation et le fonctionnement.

Le programme utilise `TelloClientUDP` pour envoyer `command`, `takeoff`, `right 50` et `land`, et affiche chaque réponse. La compilation a été tentée, mais l’exécution de CMake est bloquée par un refus d’accès. Le scénario n’a donc pas été exécuté ni validé avec le simulateur.

### 8. Vérifier avec Wireshark

- [ ] Contrôler les commandes envoyées.
- [ ] Sauvegarder les captures.

Aucun fichier de capture trouvé dans le dossier du projet. Cette étape reste à confirmer si les captures sont enregistrées ailleurs.

### 9. Versionner le code complet — commencé

- [x] Initialiser Git et créer un premier commit.
- [ ] Enregistrer les modifications actuelles dans un nouveau commit.
- [ ] Versionner la version complète une fois le TP terminé.

**Prochaine étape : compiler depuis CLion, démarrer le serveur UDP du simulateur sur le port 8889, puis exécuter le programme et vérifier les quatre commandes ainsi que les réponses.**
