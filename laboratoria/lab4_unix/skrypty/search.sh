#!/bin/bash
#####################################################################
#Przeszukiwanie katalogu i podkatalogow w czasie podanym w PIERWSZYM#
#argumencie wywolania (-t dla 7 dni i -m dla 30 dni) w poszukiwaniu #
#wyrazen podanych jako DRUGI argument wywolania                     #
#####################################################################
case "$1" in
-t) find . -type f -mtime -7 -print0 | xargs -0 grep -i -l "$2";;
-m) find . -type f -mtime -30 -print0 | xargs -0 grep -i -l "$2";;
esac 

