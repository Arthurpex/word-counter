# word-counter
Atividade 4 de Programação Paralela e Distribuída (INE5645) - UFSC
O objetivo dessa atividade é de contruir dois programas para contar palavras em arquivo de texto.
o primeiro de forma sequencial e o segundo de forma paralela utilizando a biblioteca OpenMP.

num_palavras refere-se as quantidade de palavras ( pré-determinadas ) a serem contadas no arquivo de texto.


## To Run
### Sequencial
`gcc sequential.c -o sequential`<br>
`./sequential <num_palavras>`

### Parelelo
`gcc -fopenmp parallel.c -o parallel`<br>
`./parallel <num_palavras> <num_threads>`
