# Roadmap — Module 07, pages 1 à 25

Source : M07_V2026_v2.pdf, pagination imprimée 1/47 à 25/47. État vérifié dans le projet `untitled` le 23/09/2026.

Une case cochée indique du code présent et relu. Les essais, captures et travaux écrits restent décochés lorsqu'aucune preuve n'est disponible dans le projet ; ils peuvent avoir été faits ailleurs. La présence d'une classe fournie ne suffit pas à valider son utilisation. Les tâches Git et de versionnement sont volontairement exclues.

## Pages 1–2 — Présentation et objectifs

Présentation du module et de la séance SS01 : aucune réalisation distincte à cocher.

## Page 3 — SS01 : pilotage en console

- [x] Tester le simulateur avec UdpClientServer.exe en s'appuyant sur la documentation du SDK.
- [x] Tester les différentes commandes et vérifier leur effet dans le simulateur.
- [x] Utiliser la classe fournie `IRClientUDP` pour communiquer avec le drone ou le simulateur.
- [x] Écrire un programme console envoyant les commandes de décollage et d'atterrissage.
- [x] Ajouter les déplacements linéaires : haut, bas, gauche, droite, avant et arrière (méthodes présentes dans `TelloClientUDP`).
- [x] Vérifier les échanges avec Wireshark et sauvegarder les captures.
- [x] **Bonus — code :** ajouter les rotations horaire et antihoraire.
- [x] **Bonus :** ajouter la commande `go` pour un déplacement XYZ.

## Page 4 — Objectifs de la séance SS02

Présentation de la programmation de la classe de pilotage ; réalisation détaillée page 5.

## Page 5 — SS02 : classe TelloClientUDP

- [x] Déclarer la classe, son attribut privé `IRClientUDP client`, son constructeur et les méthodes demandées.
- [x] Ouvrir la socket dans le constructeur.
- [x] Configurer la destination du simulateur local : `127.0.0.1:8889`.
- [x] Définir `EnvoyerCommande` : envoyer la commande, recevoir la réponse et la retourner si le nombre d'octets est positif.
- [x] Retourner une chaîne vide en cas d'échec d'envoi ou de réception.
- [x] Définir `ModeCommande()`, `Decoller()` et `Atterrir()`.
- [x] Définir `Monter`, `Descendre`, `Gauche`, `Droite`, `Avant` et `Arriere` avec une distance.
- [x] Définir `TournerHoraire` et `TournerTrigo` avec un angle.
- [x] Construire les commandes paramétrées avec `to_string` (alternative à l'exemple `stringstream`).
- [x] Utiliser un objet `TelloClientUDP` dans le programme principal.
- [x] Écrire le scénario `command` → `takeoff` → `right 50` → `land`, avec affichage des réponses.
- [x] Intégrer les sources à CMake et lier la bibliothèque Windows `ws2_32`.
- [x] Valider la compilation actuelle dans CLion.
- [x] Exécuter le scénario et vérifier les commandes et réponses avec le simulateur.
- [x] Vérifier les envois avec Wireshark et sauvegarder la capture.

**Point à vérifier avant les essais :** le code actuel appelle `RecevoirUnMessage(reponse, 500)`, soit 500 microsecondes (0,5 ms), et non 5 secondes. Ajuster le délai si nécessaire. La compilation précédente a été bloquée par un refus d'accès à CMake ; aucun essai réussi n'a été confirmé ici.

## Page 6 — Bonus : menu de pilotage

- [x] Ajouter un menu interactif permettant d'envoyer plusieurs commandes et de quitter.
- [x] Proposer le mode commande, le décollage, l'atterrissage, les déplacements et les rotations.
- [x] Choisir les distances et les angles depuis le menu (par exemple par répétition des lettres comme dans le sujet).
- [x] Ajouter le déplacement XYZ au menu.
- [x] Si l'exemple est repris : lire ou créer `telloConfig.txt` et permettre au constructeur de recevoir l'adresse IP.
- [x] Tester les choix du menu et afficher les réponses reçues.

## Page 7 — Objectifs de la séance SS03

Présentation de la réception des données de vol et du fichier LOG.

## Pages 8–10 — SS03 : serveur UDP et journal des données de vol

- [x] Capturer un décollage et un atterrissage avec Wireshark, puis sauvegarder en `.pcapng`.
- [x] Identifier une trame de données de vol et relever son contenu exact, y compris `\r` et `\n`.
- [x] Expliquer les champs `pitch`, `roll`, `yaw`, `vgx`, `vgy`, `vgz`, `templ`, `temph`, `tof`, `h`, `bat`, `baro`, `time`, `agx`, `agy` et `agz`.
- [x] Utiliser `IRServeurUDP` dans un programme de réception des données de vol.
- [x] Ouvrir la socket d'écoute sur `0.0.0.0` et sur le port des données de vol identifié dans la documentation ou la capture.
- [x] Recevoir et afficher les données dans une boucle ; sortir quand le nombre d'octets reçus n'est plus strictement positif.
- [x] Identifier la classe C++ d'écriture de fichiers (`ofstream`) et ouvrir `serveur.log`.
- [x] Enregistrer toutes les trames reçues dans `serveur.log`.
- [x] Tester réception, affichage et sauvegarde avec le simulateur.
- [x] **Bonus :** déclarer une structure C contenant les données de vol et extraire les champs avec `sscanf`.

Le code de `ServeurUDP/main.cpp` utilise maintenant `IRServeurUDP` sur `0.0.0.0:8890`, affiche les trames reçues et les ajoute à `serveur.log`. Le test avec le simulateur reste à confirmer.

## Page 11 — Objectifs de la séance SS04

Présentation de la conversion des données de vol en JSON.

## Pages 12–13 — SS04 : convertir une trame en JSON

- [ ] Relever les prototypes des méthodes de `string` pour rechercher, remplacer, insérer et effacer des caractères.
- [ ] Supprimer `\r` et `\n` de la trame et afficher sa longueur avant et après pour vérifier.
- [ ] Ajouter l'accolade ouvrante et le guillemet de début.
- [ ] Remplacer les séparateurs `:` pour entourer les clés et les valeurs de guillemets.
- [ ] Transformer les `;` intermédiaires en séparateurs entre les champs JSON.
- [ ] Traiter le dernier `;` pour fermer la dernière valeur et l'objet JSON sans virgule finale.
- [ ] Produire un objet JSON compact contenant les 16 champs, avec les valeurs sous forme de chaînes comme dans le sujet.
- [ ] Tester la conversion avec les données du simulateur.
- [ ] Ajouter la trame convertie en JSON au fichier LOG dans la boucle de réception.
- [ ] **Bonus :** afficher chaque caractère de la trame en hexadécimal.

## Page 14 — Objectifs de la séance SS05

Présentation du fichier JSON complet d'un vol.

## Pages 15–16 — SS05 : générer drone.json

- [ ] Créer la chaîne `leJSON` et l'en-tête `donneesVol` avec `nom`, `numero` et le timestamp `time`.
- [ ] Ouvrir le tableau `etats` destiné aux trames successives.
- [ ] Ajouter chaque trame convertie au tableau avec une virgule uniquement entre les objets.
- [ ] Détecter la fin de réception du vol à la sortie de la boucle.
- [ ] Fermer le tableau et les objets JSON sans virgule finale.
- [ ] Sauvegarder le résultat dans `drone.json`.
- [ ] Ouvrir le fichier dans un navigateur ou un éditeur et vérifier sa validité JSON.

Le modèle de la page 15 utilise `etats` au pluriel ; conserver ce nom malgré la mention `etat` dans le texte de la page 16.

## Page 17 — Objectifs de la séance SS06

Présentation de l'encapsulation du serveur de données de vol dans une classe.

## Pages 18–19 — SS06 : classe ServeurDonneeDrone

- [ ] Déclarer `ServeurDonneeDrone` selon le diagramme, avec `fichierLog`, `serveurUDP`, `leJSON` et les méthodes indiquées.
- [ ] Écrire le constructeur prenant le pilote et le numéro de drone : ouvrir le LOG, ouvrir la socket et débuter le JSON.
- [ ] Implémenter `OuvrirFichierLog`, `AjoutFichierLog` et `FermerFichierLog`.
- [ ] Implémenter `DebuterJSON` pour créer l'en-tête du vol.
- [ ] Organiser la création du JSON selon le diagramme, notamment `CreerJSON` et `AjouterDonneesJSON`.
- [ ] Implémenter `RecevoirDonneesDrone` : recevoir un seul message, l'ajouter au LOG et au JSON, puis retourner le nombre d'octets reçus (sans boucle interne).
- [ ] Implémenter `CloreJSON` : terminer le JSON et sauvegarder `drone.json`.
- [ ] Adapter le programme principal : attendre la première trame, poursuivre tant que des données arrivent, puis appeler la clôture sur l'objet serveur.
- [ ] Tester le fonctionnement complet de la classe avec le simulateur.

`EnvoyerDonneesBDD`, déjà mentionnée dans le diagramme, est détaillée aux pages 24–25.

## Page 20 — Objectifs de la séance SS07

Présentation de l'installation et des tests d'un serveur HTTP.

## Pages 21–22 — SS07 : serveur HTTP et test REST

- [ ] Installer et démarrer un serveur Web local prenant en charge PHP (par exemple WAMP).
- [ ] Analyser `restTello.php` et commenter son code.
- [ ] Identifier le dossier Web adapté et y placer `restTello.php`.
- [ ] Préparer un test avec un client REST : méthode `POST`, URL du script suivie de `/vol`, corps contenant le JSON du vol.
- [ ] Envoyer la requête et examiner la réponse PHP.
- [ ] Analyser les échanges HTTP avec Wireshark et expliquer la réponse du serveur.
- [ ] Sauvegarder la capture HTTP au format `.pcapng`.

Installation et essais externes non confirmés : aucun résultat fourni ici ne permet de les cocher.

## Page 23 — Objectifs de la séance SS08

Présentation du client REST écrit en C++.

## Pages 24–25 — SS08 : envoyer le vol au serveur HTTP

- [ ] Utiliser la classe fournie `IRClientTCP` pour les échanges HTTP.
- [ ] Implémenter `ServeurDonneeDrone::EnvoyerDonneesBDD(IPREST, urlREST)`.
- [ ] Appeler `CloreJSON` avant l'envoi.
- [ ] Créer le client TCP et le connecter au serveur HTTP.
- [ ] Déterminer la longueur du JSON pour `Content-Length`.
- [ ] Construire la requête `POST` : chemin REST, version HTTP, en-têtes, séparateurs `\r\n`, ligne vide et corps JSON.
- [ ] Envoyer la requête HTTP complète.
- [ ] Recevoir la réponse du serveur dans une boucle.
- [ ] Ajouter la réponse au LOG, puis fermer le fichier LOG.
- [ ] Appeler `EnvoyerDonneesBDD` dans le programme principal après la réception du vol, avec l'adresse et le chemin du serveur local.
- [ ] Tester la chaîne complète : simulateur → réception UDP → JSON → serveur HTTP.
- [ ] Vérifier les échanges avec Wireshark.
- [ ] **Bonus :** réaliser le diagramme UML de séquence des échanges avec le drone.
- [ ] **Bonus :** réaliser le diagramme de composants des programmes.
- [ ] **Bonus ++ :** afficher le flux vidéo de la caméra Tello, si disponible dans l'environnement utilisé.

`IRClientTCP.h/.cpp` sont présents, mais aucun client HTTP ni `ServeurDonneeDrone` n'est encore implémenté dans ce projet. La page 25 concerne l'envoi au script REST ; ne pas confondre cet envoi avec une sauvegarde en base effectivement vérifiée.

## Prochaine étape

Valider le programme actuel dans CLion et dans le simulateur, vérifier le délai de réponse et sauvegarder une capture des commandes. Ensuite, commencer le serveur de réception des données de vol des pages 8–10. Le menu de la page 6 reste un bonus.


