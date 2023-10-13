#!/bin/bash

BUILD_DIR="build"
OBJ_DIR="obj"
SRC_DIR="src"
APP_NAME="APP"
GCC_OPTIONS="-c -O3"

# Fonctions d'affichage
function afficher_succes {
    tput setaf 2
    echo "✔ $1"
    tput sgr0
}

function afficher_erreur {
    tput setaf 1
    echo "✖ Erreur: $1"
    tput sgr0
}

function afficher_commande {
    tput setaf 3
    echo -e "\t$1"
    tput sgr0
}

# Fonction pour afficher les points avec un effet de saut
function afficher_points_saut {
    for _ in {1..1}; do
        echo -ne "\n\t⬇  ⬇  ⬇ \n\n"
        sleep 0.5
    done
}

# Vérification et création des répertoires
if [ ! -d "$BUILD_DIR" ] && [ "$#" -gt 0 ] && [ "$1" != "--help" ]; then
    mkdir "$BUILD_DIR" || afficher_erreur "Impossible de créer le répertoire $BUILD_DIR."
fi

# Nettoyer les fichiers générés
function nettoyer {
    local commande="rm -rf $OBJ_DIR $BUILD_DIR"
    echo -e "➔ Nettoyage en cours..."
    afficher_commande "$commande"
    make clean > /dev/null || afficher_erreur "Erreur lors du nettoyage."
    afficher_succes "Nettoyage terminé."
}

# Compilation
function construire {
    local commande="gcc $GCC_OPTIONS -o $OBJ_DIR/main.o $SRC_DIR/main.c"
    echo -e "➔ Compilation en cours..."
    afficher_commande "$commande"
    make > /dev/null|| afficher_erreur "Erreur lors de la compilation."
    afficher_succes "Compilation terminée."
}

# Exécuter l'exécutable
function executer {
    local executable="$BUILD_DIR/$APP_NAME"
    local commande="./$executable"
    echo -e "➔ Exécution de l'exécutable..."
    afficher_commande "$commande"
    if [ -x "$executable" ]; then
        afficher_points_saut
        "$commande" || afficher_erreur "Erreur lors de l'exécution."
    else
        afficher_erreur "Erreur lors de l'exécution. Le fichier $executable n'est pas exécutable."
    fi
}

# Afficher l'aide
function afficher_aide {
    echo "Utilisation : $0 [options]"
    echo "Options :"
    echo -e "\t-rbuild, -rb  : \t➔ Nettoyer avant de reconstruire et exécuter"
    echo -e "\t-debug        : \t➔ Configurer la compilation en mode debug"
    echo -e "\t-run          : \t➔ Exécuter l'exécutable généré"
    echo -e "\t-clean        : \t➔ Nettoyer les fichiers générés"
    echo -e "\t--help        : \t➔ Afficher l'aide"
}

# Boucle d'options
while [ "$#" -gt 0 ]; do
    case "$1" in
        -rbuild | -rb)
            nettoyer
            construire
            executer
            ;;
        -debug)
            echo -e "➔ Configuration de la compilation en mode debug..."
            afficher_commande "make debug"
            make debug || afficher_erreur "Erreur lors de la configuration en mode debug."
            construire
            executer
            ;;
        -run)
            construire
            executer
            ;;
        -clean)
            nettoyer
            ;;
        --help)
            afficher_aide
            exit 0
            ;;
        *)
            afficher_erreur "Option non reconnue : $1. Utilisez --help pour afficher l'aide."
            ;;
    esac
    shift
done

