#!/bin/bash

if [ "$#" -lt 7 ]  
then
    echo "Uso: $0 [Valor de N] [Valor de W] [Peso minimo] [Peso máximo] [Valor minimo] [Valor máximo] [Soma dos pesos]";
else
    # POG para gerar soma de pesos específica de maneira fácil
    fim=0;
    until [ $fim = 1 ]
    do
        n=$1;
        w=$2;
        pesoMinimo=$3;
        pesoMaximo=$4;
        valorMinimo=$5;
        valorMaximo=$6;
        somaPesos=$7;
        percentual=$(((w*100)/somaPesos));
        arquivo="N"$n"-"$percentual"%-W"$w;
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
        if [ $t = $somaPesos ] 
        then 
            fim=1
            mv $arquivo $arquivo"T"$t".txt"
        else
            echo $t # Para poder enxergar a variância (A curva de Gauss se faz presente)
            rm $arquivo
        fi
    done
fi