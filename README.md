# Problema da Mochila
## Descrição
Este repositório é o código-fonte do Trabalho Prático 1 da disciplina AEDS - CEFET/MG 2017/2.
Algoritmos Implementados:
- Backtracking;
- Algoritmo Guloso;

## Compilação
- `make` - Compila o código
- `make clean` - Apaga todos os arquivos compilados e executáveis

## Execução
- `./mochila.out [arquivo.txt] [1 - Backtracking | 2 - Algoritmo Guloso]`
- Exemplo: `./mochila.out dataset/N10-50%-W10-T20.txt 1` executa o algoritmo guloso com o arquivo dataset/N10-50%-W10-T20.txt de entrada

## Dataset
O padrão de nome utilizado nos arquivos de dados é `N[Valor de N]-[Percentual W/Peso itens]%-W[Valor de W]-T-[Total peso itens].txt`.
Os arquivos de saída vão para a pasta `out`.

### Script
Um script foi criado usando Shell Script e POG (Programação Orientada a Gambiarra) para gerar casos de entrada.
A utilização do mesmo se dá usando:
`./gerarData.sh [Valor de N] [Valor de W] [Peso mínimo] [Peso máximo] [Valor mínimo] [Valor máximo] [Soma dos pesos]`
