#!/bin/bash 
#odniesienie do wybranego katalogu (jako 1 argument wywolania)
cd "$1" 
#zmiana rozszerzenia plikow z wielkich liter na male
for files in *.JPEG; do 
cp "$files" "${files/.JPEG/.jpeg}"; done
for files in *.PNG; do 
cp "$files" "${files/.PNG/.png}"; done
#zamiana bialych znakow na podkreslenia
for files in *.jpeg *.png; do 
mv "$files" `echo $files | tr ' ' '_'`; done
#Zmiana rozmiarow obrazow (jako drugi argument wywolania)
for files in *.jpeg *.png; do 
convert "$files" -resize "$2" "$files"; done
#Tworzenie archiwum ze zmodyfikowanymi obrazami
tar -cvf Photos.tar *.jpeg *.png --remove-files



