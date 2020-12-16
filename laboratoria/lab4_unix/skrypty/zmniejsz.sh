#!/bin/bash
for file in *.PNG; do
mv $file `basename $file .PNG`.png; done
for file in *.JPEG; do
mv $file `basename $file .JPEG`.jpeg; done
