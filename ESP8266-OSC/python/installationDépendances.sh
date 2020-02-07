#!/bin/bash
echo "
-----------------------------------------------------------------------------------
installation des dépendances en cours, cette machine doit être connectée à internet
votre mot de passe peut vous être demandé
-----------------------------------------------------------------------------------
"
sudo apt-get update||exit 1
sudo apt-get -y --fix-missing install python3-pip python3-dev liblo-dev libasound2-dev ||exit 1
pip3 install Cython||exit 2
pip3 install pyliblo ||exit 2

echo "
------------------------------terminé avec succès-----------------------------------
"
