#!/bin/bash

# Fonction pour afficher l'aide
function afficher_aide {
    echo "Utilisation : $0 [options]"
    echo "Options :"
    echo "  -rbuild, -rb  : Nettoyer avant de reconstruire et exécuter"
    echo "  -debug        : Configurer la compilation en mode debug"
    echo "  -run          : Exécuter l'exécutable généré"
    echo "  -clean        : Nettoyer les fichiers générés"
    echo "  --help        : Afficher l'aide"
}

# Configuration du répertoire de construction
BUILD_DIR="build"

# Vérification et création du répertoire de construction
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

# Fonction pour nettoyer
function nettoyer {
    echo "Nettoyage en cours..."
    make clean
}

# Fonction pour construire
function construire {
    echo "Compilation en cours..."
    make
}

# Fonction pour exécuter
function executer {
    echo "Exécution de l'exécutable..."
    ./build/CMAKE
}

# Vérification des arguments
if [ "$#" -eq 0 ]; then
    echo "Erreur : Aucune option spécifiée. Utilisez --help pour afficher l'aide."
    exit 1
fi

# Traitement des arguments
while [ "$#" -gt 0 ]; do
    case "$1" in
        -rbuild | -rb)
            nettoyer
            construire
            executer
            ;;
        -debug)
            echo "Configuration de la compilation en mode debug..."
            make debug
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
            echo "Option non reconnue : $1. Utilisez --help pour afficher l'aide."
            exit 1
            ;;
    esac
    shift
done

