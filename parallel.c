// https://codeforwin.org/2018/02/c-program-count-occurrences-of-a-word-in-file.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

int contaOcorrencias(const char *word);

int main(int argc, char const *argv[])
{   
    if (argc < 2){
        printf("Not enough arguments to start program\n");
        exit(EXIT_FAILURE);
    }

    int i;
    int contagens[4] = {0, 0, 0, 0};
    int qt_palavras;

    qt_palavras = atoi(argv[1]);

    if (qt_palavras > 10){
        printf("Quantidade de palavras a serem pesquisadas não pode execeder 10\n");
        exit(EXIT_FAILURE);
    }


    char palavras[10][30] = {"Hobbit", "ring", "Bilbo", "Gandalf", "yes", "no", "why", "because", "are", "you"};

    printf("Programa contador de palavras, Resultado: \n");
    printf("num_ocorrencias -> palavra \n");

    #pragma omp parallel 
    {
        #pragma omp for
        for (i=0; i < qt_palavras; i++) {
            contagens[i] = contaOcorrencias(palavras[i]);
            printf(" %d -> '%s'\n", contagens[i], palavras[i]);
        }
    }

    return 0;
}



int contaOcorrencias(const char *palavra)
{   
    FILE *arquivo;
    arquivo = fopen("words.txt", "r");

    if (arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo.\n");

        exit(EXIT_FAILURE);
    }

    char str[BUFFER_SIZE];
    char *pos;

    int index, count;
    
    count = 0;

    // Le linha a linha até fim do arquivo
    while ((fgets(str, BUFFER_SIZE, arquivo)) != NULL)
    {
        index = 0;

        // acha proxima ocorrencia da palavra em str
        while ((pos = strstr(str + index, palavra)) != NULL)
        {
            // Index of word in str is
            // Memory address of pos - memory
            // address of str.
            index = (pos - str) + 1;
            count++;
        }
    }

    fclose(arquivo);
    return count;
}