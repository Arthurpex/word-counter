#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

struct timeval t1, t2;

#define BUFFER_SIZE 1000

int contaOcorrencias(const char *palavra) {   
    FILE *arquivo;
    arquivo = fopen("words.txt", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");

        exit(EXIT_FAILURE);
    }

    char str[BUFFER_SIZE];
    char *pos;

    int index, count;
    
    count = 0;

    // Lê linha a linha até fim do arquivo
    while ((fgets(str, BUFFER_SIZE, arquivo)) != NULL) {
        index = 0;

        // Acha próxima ocorrência da palavra em string
        while ((pos = strstr(str + index, palavra)) != NULL) {
            index = (pos - str) + 1;
            count++;
        }
    }

    fclose(arquivo);
    return count;
}

int main(int argc, char const *argv[]) {   
    
    if (argc < 2) {
        printf("Não há número suficiente de argumentos para iniciar o programa\n");
        exit(EXIT_FAILURE);
    }

    int qt_palavras = atoi(argv[1]);

    int i;
    int contagens;

    if (qt_palavras > 80) {
        printf("Quantidade de palavras a serem pesquisadas não pode execeder 80\n");
        exit(EXIT_FAILURE);
    }

    char palavras[80][30] = {
        "Hobbit", "ring", "Bilbo", "Gandalf", "yes", "no", "why", "because", "are", "you", 
        "Hobbit", "ring", "Bilbo", "Gandalf", "yes", "no", "why", "because", "are", "you",
        "Hobbit", "ring", "Bilbo", "Gandalf", "yes", "no", "why", "because", "are", "you",
        "Hobbit", "ring", "Bilbo", "Gandalf", "yes", "no", "why", "because", "are", "you",
        "Hobbit", "ring", "Bilbo", "Gandalf", "yes", "no", "why", "because", "are", "you", 
        "Hobbit", "ring", "Bilbo", "Gandalf", "yes", "no", "why", "because", "are", "you",
        "Hobbit", "ring", "Bilbo", "Gandalf", "yes", "no", "why", "because", "are", "you",
        "Hobbit", "ring", "Bilbo", "Gandalf", "yes", "no", "why", "because", "are", "you"
    };

    gettimeofday(&t1, NULL);
    printf("Programa contador de palavras, Resultado: \n");
    printf("num_ocorrencias -> palavra \n");

    for (i=0; i < qt_palavras; i++) {
        contagens = contaOcorrencias(palavras[i]);
        printf(" %d -> '%s'\n", contagens, palavras[i]);
    }
    gettimeofday(&t2, NULL);

    double t_total= (t2.tv_sec - t1.tv_sec) + ((t2.tv_usec -t1.tv_usec)/1000000.0);
    printf("\nTempo: %f\n", t_total);

    return 0;
}
