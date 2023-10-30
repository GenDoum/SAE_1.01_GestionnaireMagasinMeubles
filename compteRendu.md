# # Compte rendu de la SAE1.01 - Implémentation des besoins du client

## Informations sur les clients :

- Numéro de client
- Solde du client
- Son état (suspension ou non)

## Informations sur les articles :

- Référence de l'article
- Poids de l'article
- Volume de l'article
- Prix unitaire de l'article

## Fichiers de données :

1. articles.txt :
   - Référence, Poids, Volume, PrixUnitaire
2. clients.txt :
   - Numéro de client, solde, suspension

## Répartition du travail :

**Mathéo** a conçu l'architecture du projet. La documentation a été rédigée par **Yannis** et **Mathéo**.

Dans ce projet, nous avons réparti les tâches de la manière suivante :

- **Mathéo** s'occupe principalement de la partie client
- **Yannis** est en charge principalement de la partie responsable.

Cependant il est important de noter que nous avons collaboré sur les deux parties du projet. Chacun de nous a contribué aux deux parties. Vous pouvez identifier l'auteur des fonctions en fonction de leur style de codage : généralement, **Mathéo** place les accolades ouvrantes sur la même ligne que le prototype de la fonction etc. En revanche, **Yannis** a tendance à sauter une ligne après les prototypes et les structures de contrôle.

## Comment démarrer l'application ?

Pour démarrer l'application, nous vous recommandons d'utiliser le script `build.sh`. Ce script vous permet de compiler et de lancer l'application en utilisant l'option `-rb`. Vous n'avez pas besoin de compiler l'application manuellement ni d'exécuter l'exécutable vous-même. Exécutez simplement la commande `./build.sh -rb` pour que l'ensemble du processus soit automatisé.
