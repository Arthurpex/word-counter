# word-counter
Atividade 4 de Programação Paralela e Distribuída (INE5645) - UFSC

## To Run
### Sequencial
`gcc sequential.c -o sequential`<br>
`./sequential <num_palavras>`

### Parelelo
`gcc -fopenmp parallel.c -o parallel`<br>
`./parallel <num_palavras> <num_threads>`
