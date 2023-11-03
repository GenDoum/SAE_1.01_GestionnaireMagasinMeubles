# Compte rendu de la SAE1.01 - Implémentation des besoins du client

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
3. mdp.txt :
   - Mot de passe du responsable chiffré par le code de César

## Répartition du travail :

**Mathéo** a conçu l'architecture du projet. La documentation a été rédigée par **Yannis** et **Mathéo**.

Dans ce projet, nous avons réparti les tâches de la manière suivante :

- **Mathéo** s'occupe principalement de la partie client
- **Yannis** est en charge principalement de la partie responsable.

Cependant, il va sans dire que même avec une telle organisation nous avons tout de même collaboré sur les deux parties du projet. Chacun de nous a contribué aux deux parties. Vous pouvez identifier l'auteur des fonctions en fonction de leur style de codage : généralement, **Mathéo** place les accolades ouvrantes sur la même ligne que le prototype de la fonction etc. En revanche, **Yannis** a tendance à sauter une ligne après les prototypes et les structures de contrôle.

## Comment démarrer l'application ?

Pour démarrer l'application, nous vous recommandons d'utiliser le script `build.sh`. Ce script vous permet de compiler et de lancer l'application en utilisant l'option `-rb`. Vous n'avez pas besoin de compiler l'application manuellement ni d'exécuter l'exécutable vous-même. Exécutez simplement la commande `./build.sh -rb` pour que l'ensemble du processus soit automatisé.
Pour plus détail vous pouvez consulter le `README.md` afin d'y voir les différentes fonctionnalités.

**En cas d'erreurs :** Si il y a un problème d'exécution avec le script faire un `make all` et ensuite faire un `./app`

## Conception

### Architecture :

L'architecture du projet a été pensée de sorte a séparer l'interface de l'application de la logique.

### Pourquoi avons-nous fait ceci ?

L'adoption d'une telle architecture permet, comme précédemment expliqué, de démarquer l'interface du reste du programme. Cette approche facilite considérablement la création d'autres types d'interfaces en se concentrant exclusivement sur leur aspect visuel, tandis que la logique est encapsulée dans la couche "logique". Par exemple, nous avons ici conçus une interface orientée vers les adhérents, où ces derniers ont accès à des opérations spécifiques offertes par l'interface par défaut, mais limitées à leurs besoins.
Mais nous avons, grâce a cette architecture aucun problème pour créer d'autre interface comme l'interface des responsable.

Un autre bénéfice majeur réside dans la facilité de maintenance. En segmentant le programme en couches et en composants distincts, nous avons la possibilité d'apporter des modifications à chacun d'eux sans altérer le code source des autres parties qui ne dépendent pas de ces modifications, préservant ainsi leur fonctionnement initial.

## Les fonctionnalités en plus : 

### Pourquoi avons-nous chiffré le mot de passe du responsable avec le code de César ?

Le code de César est un chiffrement que nous avons vu en cours de **bases mathématiques 1**. Il s'agit d'un chiffrement simple qui fonctionne grâce à un numéro qui correspond au décalage des lettres de l'alphabet. Pour obtenir le mot de passe, si nous n'avions pas mis en place ce chiffrement, il aurait simplement fallu ouvrir le fichier `mdp.txt`. Alors nous avons pensé qu'un minimum de sécurité était nécessaire.