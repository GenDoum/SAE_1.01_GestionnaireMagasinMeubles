#!/bin/bash

BUILD_DIR="build"
OBJ_DIR="obj"
SRC_DIR="src"
APP_NAME="APP"

# success 
function afficher_succes {
    tput setaf 2
    echo "✔ $1"
    tput sgr0
}

# error
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

# --help
function afficher_aide {
    echo "Utilisation : $0 [options]"
    echo "Options :"
    echo -e "\t-rbuild, -rb  : \t➔ Nettoyer avant de reconstruire et exécuter"
    echo -e "\t-debug        : \t➔ Configurer la compilation en mode debug"
    echo -e "\t-run          : \t➔ Exécuter l'exécutable généré"
    echo -e "\t-clean        : \t➔ Nettoyer les fichiers générés"
    echo -e "\t--help        : \t➔ Afficher l'aide"
}

# errors
function gerer_erreur {
    local message=$1
    local code=${2:-1}  # Code de sortie par défaut : 1
    afficher_erreur "$message"
    exit "$code"
}

# build exist ?
if [ ! -d "$BUILD_DIR" ] && [ "$#" -gt 0 ] && [ "$1" != "--help" ]; then
    mkdir "$BUILD_DIR" || gerer_erreur "Impossible de créer le répertoire $BUILD_DIR."
fi


BUILD_DIR="build"

# Clean
function nettoyer {
    local commande="rm -rf $OBJ_DIR $BUILD_DIR"
    echo -e "➔ Nettoyage en cours..."
    afficher_commande "$commande"
    make clean > /dev/null|| gerer_erreur "Erreur lors du nettoyage."
    afficher_succes "Nettoyage terminé."
}

# build
function construire {
    local commande="gcc -c -O3 -o $OBJ_DIR/main.o $SRC_DIR/main.c"
    echo -e "➔ Compilation en cours..."
    afficher_commande "$commande"
    make > /dev/null|| gerer_erreur "Erreur lors de la compilation."
    afficher_succes "Compilation terminée."
}

# Execute
function executer {
    local commande="./$BUILD_DIR/$APP_NAME"
    echo -e "➔ Exécution de l'exécutable..."
    afficher_commande "$commande"
    if [ -x "$commande" ]; then
        "$commande" || gerer_erreur "Erreur lors de l'exécution."
    else
        gerer_erreur "Erreur lors de l'exécution. Le fichier $BUILD_DIR/$APP_NAME n'est pas exécutable."
    fi
}

if [ "$#" -eq 0 ] || [ "$1" == "--help" ]; then
    afficher_aide
    exit 1
fi

# arguments
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
            make debug || gerer_erreur "Erreur lors de la configuration en mode debug."
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
            gerer_erreur "Option non reconnue : $1. Utilisez --help pour afficher l'aide."
            ;;
    esac
    shift
done

