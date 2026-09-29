# Serveur UDP — pages 9–10 du TP

Le programme principal est dans `main.cpp`.

1. Ouvrir la socket sur `0.0.0.0`, port `8890`.
2. Recevoir les données dans une boucle.
3. Afficher chaque message et l’écrire dans `serveur.log`.
4. Quitter la boucle lorsque le nombre d’octets reçus est nul ou négatif.

Le délai de réception est de 30 secondes (`30000000` microsecondes). Démarrer l’envoi des données du simulateur avant l’expiration de ce délai. Le port `8889` reste réservé aux commandes de pilotage.

Le journal est créé dans le dossier de travail du programme (généralement `cmake-build-debug` dans CLion). Les anciennes données sont conservées grâce à `ios::app`.

La conversion JSON et la classe `ServeurDonneeDrone` viendront aux étapes suivantes du TP.
