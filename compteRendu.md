# Compte rendu de la SAE1.01 - Implémentation des besoins du client

## Informations sur les clients :

-   Numéro de client
-   Solde du client
-   Son état (suspension ou non)

## Informations sur les articles :

-   Référence de l'article
-   Poids de l'article
-   Volume de l'article
-   Prix unitaire de l'article

## Informations sur les mots de passe :

-   Mot de passe décalé
-   Chiffre correspondant au décalage des lettres.

## Fichiers de données :

1.  articles.txt :
    -   Référence, Poids, Volume, PrixUnitaire
2.  clients.txt :
    -   Numéro de client, solde, suspension
3.  mdp.txt :
    -   Mot de passe du responsable chiffré par le code de César

## Répartition du travail :

**Mathéo** a conçu l'architecture du projet. La documentation a été rédigée par **Yannis** et **Mathéo**.

Dans ce projet, nous avons réparti les tâches de la manière suivante :

-   **Mathéo** s'occupe principalement de la partie client.
-   **Yannis** est en charge principalement de la partie responsable.

Cependant, il va sans dire que même avec une telle organisation, nous avons tout de même collaboré sur les deux parties du projet. Chacun de nous a contribué aux deux parties. Vous pouvez identifier l'auteur des fonctions en fonction de leur style de codage : généralement, **Mathéo** place les accolades ouvrantes sur la même ligne que le prototype de la fonction, etc. En revanche, **Yannis** a tendance à sauter une ligne après les prototypes et les structures de contrôle.

## Comment démarrer l'application ?

Pour démarrer l'application, nous vous recommandons d'utiliser le script `build.sh`. Ce script vous permet de compiler et de lancer l'application en utilisant l'option `-rb`. Vous n'avez pas besoin de compiler l'application manuellement ni d'exécuter l'exécutable vous-même. Exécutez simplement la commande `./build.sh -rb` pour que l'ensemble du processus soit automatisé. Pour plus de détails, vous pouvez consulter le fichier `README.md` afin d'y voir les différentes fonctionnalités.

**En cas d'erreurs :** En cas de problème d'exécution avec le script, exécutez `make all`, puis lancez `./app`.

## Conception

### Architecture :

L'architecture du projet a été pensée de manière à séparer l'interface de l'application de la logique.

### Pourquoi avons-nous fait ceci ?

L'adoption d'une telle architecture permet, comme précédemment expliqué, de démarquer l'interface du reste du programme. Cette approche facilite considérablement la création d'autres types d'interfaces en se concentrant exclusivement sur leur aspect visuel, tandis que la logique est encapsulée dans la couche "logique". Par exemple, nous avons ici conçu une interface orientée vers les adhérents, où ces derniers ont accès à des opérations spécifiques offertes par l'interface par défaut, mais limitées à leurs besoins. Cependant, grâce à cette architecture, nous n'avons aucun problème pour créer d'autres interfaces, comme l'interface des responsables.

Un autre bénéfice majeur réside dans la facilité de maintenance. En segmentant le programme en couches et en composants distincts, nous avons la possibilité d'apporter des modifications à chacun d'eux sans altérer le code source des autres parties qui ne dépendent pas de ces modifications, préservant ainsi leur fonctionnement initial.

## Les fonctionnalités en plus :

### Pourquoi avons-nous chiffré le mot de passe du responsable avec le code de César ?

Le code de César est un chiffrement que nous avons vu en cours de **bases mathématiques 1**. Il s'agit d'un chiffrement simple qui fonctionne grâce à un numéro correspondant au décalage des lettres de l'alphabet. Pour obtenir le mot de passe, si nous n'avions pas mis en place ce chiffrement, il aurait simplement fallu ouvrir le fichier `mdp.txt`. Nous avons donc pensé qu'un minimum de sécurité était nécessaire.

### Fonctionnalités de sortie de l'application

Lorsqu'un utilisateur décide de quitter l'application, plusieurs scénarios sont possibles en fonction de sa situation financière et des fonctionnalités de l'application.

-   Si l'utilisateur n'a pas défini de budget, il a simplement à payer ses articles et quitter l'application.
    
-   Si l'utilisateur a respecté son budget et a suffisamment d'argent dans son solde, il peut simplement quitter l'application sans aucune autre action requise.
    
-   Si l'utilisateur a dépassé son budget autorisé, l'application l'informera du montant excédentaire et de la possibilité d'utiliser sa cagnotte pour couvrir cet excédent. L'utilisateur aura alors le choix de déduire un montant de sa cagnotte pour payer l'excédent.
    
-   Si l'utilisateur n'a pas assez d'argent dans sa cagnotte pour couvrir l'excédent, l'application lui indiquera qu'il n'a pas assez d'argent et l'application se fermera.
    
-   Si l'utilisateur a utilisé sa cagnotte pour couvrir un excédent de dépenses, l'application déduira le montant approprié de sa cagnotte et informera l'utilisateur que le montant a été déduit avec succès.
    
-   Si l'utilisateur n'a pas déduit suffisamment de sa cagnotte pour couvrir le montant dû, l'application lui indiquera le montant minimum à déduire pour effectuer le paiement complet.
    

Ces fonctionnalités garantissent que l'application aide les utilisateurs à gérer leur budget et à utiliser leur cagnotte de manière efficace pour éviter les problèmes financiers.