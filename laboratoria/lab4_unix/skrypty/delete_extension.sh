#!/bin/bash
###################################################################
#skrypt przeszukuje biezacy katalog i jego podkatalogi pod katem  #	
#obecnosci plikow z rozszerzeniem podanym jako argument wywolania #
#wywolania skryptu by nastepnie je usunac                         #
###################################################################
find ./ -name "*.$1" -exec rm {} \;
