Pour compiler le projet : 
make clean;make

Pour lancer le projet :
./exec res/obj/fichier.geo res/obj/ficher2.geo (choisir les fichiers que l'on souhaite)

Pour les controles :
A pour dézooomer
E pour zoomer
Z pour déplacer la caméra vers le haut
S pour déplacer la caméra vers le bas
Q pour déplacer la caméra à gauche
D pour déplacer la caméra à droite
Fleche Gauche pour rotationner vers la gauche
Fleche droite pour rotationner vers la droite
Fleche Haut pour rotationner vers l'avant
Fleche Bas pour rotationner vers l'arrière

Je sais que j'ai un problème lorsque le cube est petit, il sort du frustum si on le déplace puisque la fenetre ne refléte pas le frustum de la caméra.
