# SAE_101

# Guide pour lancer l'application

## Prérequis
Assurez-vous d'avoir les éléments suivants installés sur votre système :
- [Git](https://git-scm.com/)
- [Make](https://www.gnu.org/software/make/)
- [GCC](https://gcc.gnu.org/) 

## Étapes

1. **Cloner le dépôt Git :**
   ```bash
   git clone https://codefirst.iut.uca.fr/git/yannis.doumir_fernandes/SAE_101.git
   cd SAE_101
2. **Exécuter le script de lancement :**
   ```bash
   ./build.sh -rbuild
Cette commande nettoie, construit et exécute l'application.

3. **Optionnel - Mode Debug :**
   Si vous souhaitez exécuter l'application en mode débogage, utilisez l'option `-debug` :
   ```bash
   ./build.sh -debug
4. **Optionnel - Nettoyer les fichiers générés :**
   Pour nettoyer les fichiers générés (objets et exécutable), utilisez l'option `-clean` :
   ```bash
   ./build.sh -clean
5. **Exécuter l'application (après la construction) :**
   Si vous avez déjà construit l'application et souhaitez simplement l'exécuter, utilisez l'option `-run` :
   ```bash
   ./build.sh -run
**Notes**
- Assurez-vous que le script (`script.sh) a les permissions d'exécution :
   ```bash
   chmod +x build.sh
- Si vous ne spécifiez aucune option lors de l'exécution du script, il affichera un message d'erreur vous indiquant d'utiliser --help pour afficher l'aide :
   ```bash
   ./build.sh --help