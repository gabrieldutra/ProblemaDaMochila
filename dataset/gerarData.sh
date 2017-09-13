#!/bin/bash

if [ "$#" -lt 6 ]  
then
    echo "Uso: $0 [Valor de N] [Valor de W] [Peso minimo] [Peso máximo] [Valor minimo] [Valor máximo]";
else
    n=$1;
    w=$2;
    pesoMinimo=$3;
    pesoMaximo=$4;
    valorMinimo=$5;
    valorMaximo=$6;
    arquivo="N"$n"-W"$w;
    echo "$w" > $arquivo
    echo "$n" >> $arquivo
    t=0;
    for (( i=1; i <= $n; i++))
    do
        pesoItem=$(( ( RANDOM % ($pesoMaximo-$pesoMinimo+1) )  + $pesoMinimo ))
        valorItem=$(( ( RANDOM % ($valorMaximo-$valorMinimo+1) )  + $valorMinimo ))
        t=$((pesoItem+t));
        echo "$pesoItem $valorItem" >> $arquivo
    done
    mv $arquivo $arquivo"T"$t".txt"
fi