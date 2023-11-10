# Table des matières

1. [Compte rendu de la SAE1.01 - Implémentation des besoins du client](#compte-rendu-de-la-sae101---implémentation-des-besoins-du-client)
    1. [Informations sur les clients](#informations-sur-les-clients)
    2. [Informations sur les articles](#informations-sur-les-articles)
    3. [Informations sur les mots de passe](#informations-sur-les-mots-de-passe)
    4. [Information sur les promotions](#information-sur-les-promotions)
    5. [Fichiers de données](#fichiers-de-données)
    6. [Répartition du travail](#répartition-du-travail)
    7. [Comment démarrer l'application](#comment-démarrer-lapplication)
    8. [Conception](#conception)
        1. [Architecture](#architecture)
    9. [Les fonctionnalités en plus](#les-fonctionnalités-en-plus)
        1. [Pourquoi avons-nous chiffré le mot de passe du responsable avec le code de César ?](#pourquoi-avons-nous-chiffré-le-mot-de-passe-du-responsable-avec-le-code-de-césar)
        2. [Fonctionnalités de sortie de l'application](#fonctionnalités-de-sortie-de-lapplication)
    10. [Jeu de données](#jeu-de-données)
        1. [Voici un jeu de données pour articles.txt](#voici-un-jeu-de-données-pour-le-fichier-articles)
        2. [Voici un jeu de données pour client.txt](#voici-un-jeu-de-données-pour-le-fichier-client)
        3. [Voici un jeu de données pour mdp.txt](#voici-un-jeu-de-données-pour-le-fichier-mdp)
        4. [Voici un jeu de données pour promotion.txt](#voici-un-jeu-de-données-pour-le-fichier-promotion)
    11. [Traces d'exécution](#traces-dexécution)
        1.  [Voici les traces d'exécution pour la partie client](#voici-les-traces-dexécution-pour-la-partie-client)
        2.  [Voici les traces d'exécution pour la partie responsable](#voici-les-traces-dexécution-pour-la-partie-responsable)
    12. [Contributeurs](#contributeurs)


# Compte rendu de la SAE1.01 - Implémentation des besoins du client


## Informations sur les clients :

-   Numéro de client.
-   Solde du client.
-   Son état (suspension ou non).

## Informations sur les articles :

-   Référence de l'article.
-   Poids de l'article.
-   Volume de l'article.
-   Prix unitaire de l'article.

## Informations sur les mots de passe :

-   Mot de passe décalé.
-   Chiffre correspondant au décalage des lettres.

## Information sur les promotions : 
-	La référence de l'article en promotion.
-	La promotion appliquée.

## Fichiers de données :

1.  articles.txt :
    -   Référence, Poids, Volume, PrixUnitaire
2.  clients.txt :
    -   Numéro de client, solde, suspension
3.  mdp.txt :
    -   Mot de passe du responsable chiffré par le code de César 
4.	promotion.txt
	-	Référence, promotion

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

### Pourquoi avons-nous chiffré le mot de passe du responsable avec le code de César

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

## Jeu de données : 

### Voici un jeu de données pour le fichier articles :
```
464		50.00	50.00	50.00
958	   	4.75	60.00	32.00
101	   	2.00	2.00	3.00
32	  	123.00	123.00	123.00
```

### Voici un jeu de données pour le fichier client : 
```
32	73.70	1
5079	575.10	0
53	0.00	0
```

### Voici un jeu de données pour le fichier mdp : 
#### (Le mot de passe actuel est `aaa`, il ne s'affiche pas lors de l'entrée au clavier)
```
lll 89
```

### Voici un jeu de données pour le fichier promotion : 
```
958	50
101	25
464	50
```

## Traces d'exécution :
### Voici les traces d'exécution pour la partie **client** :
#### Tout d'abord les cas ou le client n'a pas de carte suspendu et ne choisis pas de budget:
```
(lldb) target create "app"
Current executable set to '/Users/matheohersan/1A/IUT/Cours/SAE/SAE_101/app' (arm64).
(lldb) run
Process 10731 launched: '/Users/matheohersan/1A/IUT/Cours/SAE/SAE_101/app' (arm64)
Choix de l'interface:
1. Interface 'responsable': Pour les responsables
2. Interface 'Client'     : Pour les clients
Vous choisissez l'interface n°: 2
Vous avez choisi l'interface client.
Veuillez saisir votre numéro de client : 5079
Voulez-vous définir un budget à ne pas dépasser ? (1 pour Oui, 0 pour Non) : 0
Veuillez saisir la taille disponible du véhicule (en litres) : 100
Veuillez saisir la charge maximale autorisée (en kg) : 100

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 2
	 Liste des articles

	 Ref		 Poids		 Volume		 Prix
	 464		  50.00		  50.00		  50.00

	 958		  4.75		  60.00		  32.00

	 101		  2.00		  2.00		  3.00

	 32		  123.00		  123.00		  123.00


+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 3
Entrez la référence de l'article : 958
Entrez la quantité : 10
Contenu du panier : 958
Récap :
Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot
958	 10	 4.75	 60.00	 32.00	 47.50	 600.00	 320.00
Prix total à payer: 320.00 euros
Cagnotte totale : 632.70 euros
Volume utilise : 600.00 litres
Charge Actuelle: 47.50 kg
Attention :
Dépassement du volume autorisé de 500.00 litres.

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 3
Entrez la référence de l'article : 101
Entrez la quantité : 1
Contenu du panier : 958 101
Référence : 101
Quantité : 1
Récap :
Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot   Cagnotte
101   1     2.00        2.00      3.00     2.00           2.00      3.00      633.00
Prix total à payer: 3.00 euros
Cagnotte totale : 633.00 euros
Volume utilise : 2.00 litres
Volume restant : 98.00 litres
Charge Actuelle: 2.00 kg
Charge restante: 98.00 kg

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 1
Récap :
Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot
958	 10	 4.75	 60.00	 32.00	 47.50	 600.00	 320.00
101	 1	 2.00	 2.00	 3.00	 2.00	 2.00	 3.00
Prix total à payer: 323.00 euros
Cagnotte totale : 633.00 euros
Volume utilise : 602.00 litres
Charge Actuelle: 49.50 kg
Attention :
Dépassement du volume autorisé de 502.00 litres.

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 4
Entrez la référence de l'article à supprimer : 101
Article supprimé du panier avec succès.
Récap :
Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot
958	 10	 4.75	 60.00	 32.00	 47.50	 600.00	 320.00
Prix total à payer: 320.00 euros
Cagnotte totale : 632.70 euros
Volume utilise : 600.00 litres
Charge Actuelle: 47.50 kg
Attention :
Dépassement du volume autorisé de 500.00 litres.

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 7
Prix total à payer: 320.00 euros
Volume utilise : 600.00 litres
Charge Actuelle: 47.50 kg
Attention : Dépassement du volume autorisé de 500.00 litres.
Vous ne pourrez pas payer. De plus vous ne pourrez pas utiliser votre cagnotte car votre coffre est plein.
Voulez vous revenir en arrière pour modifier votre panier ? (1 pour Oui, 0 pour Non) : 1

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 5
Entrez la référence de l'article : 958
Entrez la quantité : 1
Quantité modifiée avec succès.

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 7
Prix total à payer: 32.00 euros
Volume utilise : 60.00 litres
Charge Actuelle: 4.75 kg
Cagnotte totale : 603.90 euros
Voulez-vous déduire de votre cagnotte avant de quitter ? (1 pour Oui, 0 pour Non) : 1
Entrez le montant à déduire de votre cagnotte : 10
Montant déduit de la cagnotte avec succès.
Il vous reste 593.90 euros dans votre cagnotte.
Payement effectué.

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 9
Au revoir !
Process 10731 exited with status = 0 (0x00000000)
```
Dans ce cas je n'ai pas montré si le client refuse de revenir en arrière si son coffre est plein. Si il aurais refusé de revenir en arrière il aurais eu ce message :

```Payement non effectué.```

#### Maintenant voici les traces d'execution pour le cas ou le client n'a pas de carte suspendu mais choisis un budget :
```
(lldb) target create "app"
Current executable set to '/Users/matheohersan/1A/IUT/Cours/SAE/SAE_101/app' (arm64).
(lldb) run
Process 10832 launched: '/Users/matheohersan/1A/IUT/Cours/SAE/SAE_101/app' (arm64)
Choix de l'interface:
1. Interface 'responsable': Pour les responsables
2. Interface 'Client'     : Pour les clients
Vous choisissez l'interface n°: 2
Vous avez choisi l'interface client.
Veuillez saisir votre numéro de client : 5079
Voulez-vous définir un budget à ne pas dépasser ? (1 pour Oui, 0 pour Non) : 1
Entrez le budget à ne pas dépasser : 10
Veuillez saisir la taille disponible du véhicule (en litres) : 100
Veuillez saisir la charge maximale autorisée (en kg) : 100

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 3
Entrez la référence de l'article : 958
Entrez la quantité : 5
Contenu du panier : 958
Récap :
Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot
958	 5	 4.75	 60.00	 32.00	 23.75	 300.00	 160.00
Prix total à payer: 160.00 euros
Cagnotte totale : 609.90 euros
Volume utilise : 300.00 litres
Charge Actuelle: 23.75 kg
Attention :
Dépassement du volume autorisé de 200.00 litres.
Dépassement du budget autorisé de 150.00 euros.

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 7
Prix total à payer: 160.00 euros
Budget : 10.00 euros
Volume utilise : 300.00 litres
Charge Actuelle: 23.75 kg
Attention : Dépassement du volume autorisé de 200.00 litres.
Dépassement du budget autorisé de 150.00 euros.
Vous ne pourrez pas payer. De plus vous ne pourrez pas utiliser votre cagnotte car votre coffre est plein.
Voulez vous revenir en arrière pour modifier votre panier ? (1 pour Oui, 0 pour Non) : 1

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 6
Le panier a été réinitialisé avec succès.

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 1
Récap :
Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot
Prix total à payer: 0.00 euros
Cagnotte totale : 593.90 euros
Volume utilise : 0.00 litres
Charge Actuelle: 0.00 kg

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 3
Entrez la référence de l'article : 958
Entrez la quantité : 1
Contenu du panier : 958
Référence : 958
Quantité : 1
Récap :
Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot   Cagnotte
958   1     4.75        60.00      32.00     4.75           60.00      32.00      597.10
Prix total à payer: 32.00 euros
Cagnotte totale : 597.10 euros
Volume utilise : 60.00 litres
Volume restant : 40.00 litres
Charge Actuelle: 4.75 kg
Charge restante: 95.25 kg

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 1
Récap :
Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot
958	 1	 4.75	 60.00	 32.00	 4.75	 60.00	 32.00
Prix total à payer: 32.00 euros
Cagnotte totale : 597.10 euros
Volume utilise : 60.00 litres
Charge Actuelle: 4.75 kg
Attention :
Dépassement du budget autorisé de 22.00 euros.

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 7
Prix total à payer: 32.00 euros
Budget : 10.00 euros
Volume utilise : 60.00 litres
Charge Actuelle: 4.75 kg
Cagnotte totale : 597.10 euros
Attention : Dépassement du budget autorisé de 22.00 euros.
Vous ne pourrez pas payer, mais vous avez suffisamment dans votre cagnotte pour déduire le prix.
Voulez-vous déduire de votre cagnotte avant de quitter ? (1 pour Oui, 0 pour Non) : 1
Entrez le montant à déduire de votre cagnotte : 1
ERREUR : Vous devez déduire suffisamment pour payer l'intégralité du montant dû.
Montant minimum à déduire pour payer : 22.00
Entrez le montant à déduire de votre cagnotte : 22
Montant déduit de la cagnotte avec succès.
Il vous reste 575.10 euros dans votre cagnotte.
Payement effectué.

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 9
Au revoir !
Process 10832 exited with status = 0 (0x00000000)
```

Dans ce cas je n'ai pas montré si le client refuse de déduire de sa cagnotte si il a depassé le budget. Si il aurais refusé de déduire de sa cagnotte il aurais eu ce message :

```Payement non effectué.```

Il aurais eu le même message si il n'avais pas assez de cagnotte pour déduire le montant.

#### Maintenant voici les traces d'execution pour le cas ou le client a une carte suspendu et ne choisis pas de budget :
```
(lldb) target create "app"
Current executable set to '/Users/matheohersan/1A/IUT/Cours/SAE/SAE_101/app' (arm64).
(lldb) run
Process 10870 launched: '/Users/matheohersan/1A/IUT/Cours/SAE/SAE_101/app' (arm64)
Choix de l'interface:
1. Interface 'responsable': Pour les responsables
2. Interface 'Client'     : Pour les clients
Vous choisissez l'interface n°: 2
Vous avez choisi l'interface client.
Veuillez saisir votre numéro de client : 32
Voulez-vous définir un budget à ne pas dépasser ? (1 pour Oui, 0 pour Non) : 0
Veuillez saisir la taille disponible du véhicule (en litres) : 100
Veuillez saisir la charge maximale autorisée (en kg) : 100

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 3
Entrez la référence de l'article : 101
Entrez la quantité : 5
Contenu du panier : 101
Référence : 101
Quantité : 5
Récap :
Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot   Cagnotte
101   5     2.00        2.00      3.00     10.00           10.00      15.00      70.50
Prix total à payer: 15.00 euros
Cagnotte totale : 70.50 euros
Volume utilise : 10.00 litres
Volume restant : 90.00 litres
Charge Actuelle: 10.00 kg
Charge restante: 90.00 kg

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 7
Prix total à payer: 15.00 euros
Volume utilise : 10.00 litres
Charge Actuelle: 10.00 kg
Vous ne pourrez pas utiliser votre cagnotte car votre carte est suspendu.
Payement effectué.

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 9
Au revoir !
Process 10870 exited with status = 0 (0x00000000)
```

Maintenant voici les traces d'execution pour le cas ou le client a une carte suspendu et choisis un budget :
```
(lldb) target create "app"
Current executable set to '/Users/matheohersan/1A/IUT/Cours/SAE/SAE_101/app' (arm64).
(lldb) run
Process 10916 launched: '/Users/matheohersan/1A/IUT/Cours/SAE/SAE_101/app' (arm64)
Choix de l'interface:
1. Interface 'responsable': Pour les responsables
2. Interface 'Client'     : Pour les clients
Vous choisissez l'interface n°: 2
Vous avez choisi l'interface client.
Veuillez saisir votre numéro de client : 32
Voulez-vous définir un budget à ne pas dépasser ? (1 pour Oui, 0 pour Non) : 1
Entrez le budget à ne pas dépasser : 10
Veuillez saisir la taille disponible du véhicule (en litres) : 100
Veuillez saisir la charge maximale autorisée (en kg) : 100

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 3
Entrez la référence de l'article : 958
Entrez la quantité : 1
Contenu du panier : 958
Référence : 958
Quantité : 1
Récap :
Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot   Cagnotte
958   1     4.75        60.00      32.00     4.75           60.00      32.00      73.70
Prix total à payer: 32.00 euros
Cagnotte totale : 73.70 euros
Volume utilise : 60.00 litres
Volume restant : 40.00 litres
Charge Actuelle: 4.75 kg
Charge restante: 95.25 kg

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 1
Récap :
Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot
958	 1	 4.75	 60.00	 32.00	 4.75	 60.00	 32.00
Prix total à payer: 32.00 euros
Cagnotte totale : 73.70 euros
Volume utilise : 60.00 litres
Charge Actuelle: 4.75 kg
Attention :
Dépassement du budget autorisé de 22.00 euros.

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 7
Prix total à payer: 32.00 euros
Budget : 10.00 euros
Volume utilise : 60.00 litres
Charge Actuelle: 4.75 kg
Attention : Dépassement du budget autorisé de 22.00 euros.
Vous ne pourrez pas payer. De plus vous ne pourrez pas utiliser votre cagnotte car votre carte est suspendu.
Payement non effectué.

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
||	1 : Afficher le récapitulatif du panier.	 	||
||	2 : Afficher les articles disponibles.			||
||	3 : Ajouter un article au panier.   			||
||	4 : Supprimer un article du panier. 			||
||	5 : Modifier la quantité d'un article du panier. 	||
||	6 : Réinitialiser le panier.				||
||	7 : Passer au payement.					||
||	9 : Quitter.						||
+----------------------------------------------------------------+
Vous choisissez: 9
Au revoir !
Process 10916 exited with status = 0 (0x00000000)
```


### Voici les traces d'exécution pour la partie **responsable** :
### La partie responsable possède un menu divisé en trois parties, la partie clients, la partie articles et la partie promotions. Par conséquent, cette partie sera divisé en 3 sous parties.

#### Menu clients :
#### Une fois la demande faite, le programme affiche à nouveau le menu.

#### 1. Afficher la liste des clients.

```
Choix de l'interface: 
1. Interface 'responsable': Pour les responsables
2. Interface 'Client'     : Pour les clients
Vous choisissez l'interface n°: 1
Vous avez choisi l'interface responsable.
Entrer le mot de passe responsable : 
+--------------------------------------------+
|| Mot de passe correct, bienvenue patron ! ||
+--------------------------------------------+

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 2
	 Liste des clients
	 NumClient	 Cagnotte	 Etat
	 32		 69.00		 1

	 5079		 696.70		 0

	 53		 0.00		 0

	 Fin de la liste !

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 
```

#### 2. Afficher les informations d'un client

```
+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 1
Veuillez entrer le numéro du client à rechercher : 32
	 NumClient	 Cagnotte	 Etat
	 32		 69.00		 1


+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 
```
#### 3. Ajouter un client
##### précision : pour montrer que la création du client a bien fonctionné, j'ai affiché la liste des clients juste après.
```
+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 3
Veuillez entrer le numéro du nouveau client : 999

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 2
	 Liste des clients
	 NumClient	 Cagnotte	 Etat
	 32		 69.00		 1

	 5079		 696.70		 0

	 53		 0.00		 0

	 999		 0.00		 0

	 Fin de la liste !

```

#### 4. Supprimer un client
##### précision : pour montrer que la création du client a bien fonctionné, j'ai affiché la liste des clients juste après.


```
+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 4
Entrez le numéro du client : 999
Êtes-vous sur de vouloir supprimer ce client ? ( Oui = 1 / Non = 0 ) : 1
Le client 999 a été supprimé avec succès.

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 2
	 Liste des clients
	 NumClient	 Cagnotte	 Etat
	 32		 69.00		 1

	 5079		 696.70		 0

	 53		 0.00		 0

	 Fin de la liste !


```

#### 5. Modifier le statut d'un client
##### Dans le cas où la cagnotte est suspendu.
```
+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 5
Entrez le numéro du client : 32
La cagnotte du client 32 est suspendue, voulez-vous l'activer à nouveau ? ( Oui = 1 / Non = 0 ) : 1
La cagnotte n'est plus suspendu
```
##### Dans le cas où la cagnotte n'est pas suspendu
```
+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 5
Entrez le numéro du client : 32
La cagnotte du client n'est pas suspendu, voulez-vous le suspendre ? ( Oui = 1 / Non = 0 ) : 1
La cagnotte est maintenant suspendu
```
#### Menu articles :

#### 6. Afficher un article

```
+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 6
Entrez la référence de l'article à rechercher : 464
	 Ref		 Poids		 Volume		 Prix
	 464		 50.00		 50.00		  50.00

```

#### 7. Afficher la liste des articles

```
-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 7
	 Liste des articles

	 Ref		 Poids		 Volume		 Prix
	 464		  50.00		  50.00		  50.00

	 958		  4.75		  60.00		  32.00

	 101		  2.00		  2.00		  3.00

	 32		  123.00		  123.00		  123.00
```

#### 8. Ajouter un article

```
+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 
8
Entrez la ref du nouveau produit : 32
Entrez le poids du nouveau produit : 15
Entrez le volume du nouveau produit : 13
Entrez le prix du nouveau produit : 500

```

#### 9. Supprimer un article

```
+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 9
Entrez la référence de l'article que vous voulez supprimer : 32
L'article 32 a été supprimé avec succès.

```

10. Modifier un article

```
+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 10
	 Quelle est la référence de l'article que vous voulez modifier ?
32
	 Quel est le nouveau poids à entrer ?
99 
	 Quel est le nouveau volume à entrer ?
99
	 Quel est le nouveau prix à entrer ?
99

+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 6
Entrez la référence de l'article à rechercher : 32
	 Ref		 Poids		 Volume		 Prix
	 32		 99.00		 99.00		  99.00

```

#### Menu réductions

#### 11. Ajouter une réduction
##### Dans le cas où l'article n'a pas de réduction

```
+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 11
A quel article voulez-vous ajouter une promotion : 32
Entrez le pourcentage pourcentage : 50

	Modification réussi !


+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 7
	 Liste des articles

	 Ref		 Poids		 Volume		 Prix
	 464		  50.00		  50.00		  50.00

	 958		  4.75		  60.00		  32.00

	 101		  2.00		  2.00		  3.00

	 32			  99.00		  99.00		  49.50
```

##### Dans le cas où l'article a une réduction

```
+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 11
A quel article voulez-vous ajouter une promotion : 101
ERREUR : Cet article est déjà en promotion ! : 101
ERREUR : Cet article est déjà en promotion ! : 32
Entrez le pourcentage pourcentage : 50

	Modification réussi !

```

#### 12. Supprimer une promotion
##### Dans le cas où la promotion existe

```
+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 12
Entrez la référence de l'article auquel il faut supprimer la réduction : 464

	Suppression réussi !

```

##### Dans le cas où la promotion n'existe pas

```
+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 12
Entrez la référence de l'article auquel il faut supprimer la réduction : 32
ERREUR : Entrez une référence qui a une réduction ! : 32

```

#### 13. Modification du mot de passe
##### Dans le cas où les conditions sont respectées

```
+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 13
	 /!/ Vous entrez dans le menu de modification du mot de passe /!/
	 Êtes-vous sur de vouloir changer le mot de passe ?
 Si oui, entrez 1 et sinon entrez 0
1
Veuillez entrer le nouveau mot de passe.

	MAXIXMUM 20 CARACTERES ET SEULEMENT DES LETTRES
	abcdefghijklmnopqrstuvwxyz       
	 /!/ Mot de passe trop long /!/ 

```

##### Dans le cas où les conditions ne sont pas respectées

```
+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 13
	 /!/ Vous entrez dans le menu de modification du mot de passe /!/
	 Êtes-vous sur de vouloir changer le mot de passe ?
 Si oui, entrez 1 et sinon entrez 0
1
Veuillez entrer le nouveau mot de passe.

	MAXIXMUM 20 CARACTERES ET SEULEMENT DES LETTRES
	bonjour
Veuillez entrer à nouveau le mot de passe.
	bonjour
	 Veuillez entrer le nouveau décalage
89
	Mot de passe modifié avec succès!

```

#### 14. Quittez

```
+-------------+
|| Bonjour ! ||
+-------------+

+----------------------------------------------------------------+
|| Que voulez-vous faire ?					||
|| 		 - Clients -					||
||								||
||	1 : Afficher un client					||
||	2 : Afficher les clients				||
||	3 : Ajouter un client					||
||	4 : Supprimer un client					||
||	5 : Modifier le statut du client			||
||								||
|| 		 - Articles -					||
||								||
||	6 : Afficher un article					||
||	7 : Afficher les articles				||
||	8 : Ajouter un article					||
||	9 : Supprimer un article				||
||	10 : Modifier un article				||
||								||
|| 		 - Réductions -					||
||								||
||	11 : Ajouter réduction					||
||	12 : Supprimer réduction				||
||								||
|| 		 - Autres -					||
||								||
||	13 : Modifier le mot de passe				||
||	14 : Quittez.						||
+----------------------------------------------------------------+
Vous choisissez: 14
Sauvegarde des articles effectuée.
Sauvegarde des clients effectuée.
Sauvegarde des réductions effectuée.
Au revoir !
``` 

# Contributeurs

Ce compte rendu a été préparé par :

- Mathéo : Concepteur de l'architecture du projet et en majorité de la partie client.
- Yannis : En majorité concepteur de la partie responsable et d'une partie de la logique.