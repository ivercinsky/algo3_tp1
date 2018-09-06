#!/bin/bash

make all
for F1 in $(ls instancias)
do
    make $F1
done