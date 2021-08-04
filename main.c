// https://codeforwin.org/2018/02/c-program-count-occurrences-of-a-word-in-file.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

int countOccurrences(FILE *fptr, const char *word);

int main(int argc, char const *argv[])
{
    FILE *fptr;

    int words_qt;

    if (argc < 2){
        printf("Not enough arguments to start program\n");
        exit(EXIT_FAILURE);
    }

    words_qt = atoi(argv[1]);

    if (words_qt > 10){
        printf("Quantity of words to be searched cannot be greater than 10\n");
        exit(EXIT_FAILURE);
    }

    char word[10][30] = {"Morty", "Rick", "Summer", "Pickle", "yes", "no", "why", "because", "are", "you"};
    int wCount;

    int i;
    int counts[4] = {0, 0, 0, 0};

    printf("Word Counter Program, Result: \n");
    for (i=0; i < words_qt; i++){
        counts[i] = countOccurrences(fptr, word[i]);
        printf("'%s' -> %d times\n", word[i], counts[i]);
    }

    
    return 0;
}



int countOccurrences(FILE *fptr, const char *word)
{   
    fptr = fopen("words.txt", "r");
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read/write previleges.\n");

        exit(EXIT_FAILURE);
    }


    char str[BUFFER_SIZE];
    char *pos;

    int index, count;
    
    count = 0;

    // Read line from file till end of file.
    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        index = 0;

        // Find next occurrence of word in str
        while ((pos = strstr(str + index, word)) != NULL)
        {
            // Index of word in str is
            // Memory address of pos - memory
            // address of str.
            index = (pos - str) + 1;
            count++;
        }
    }

    fclose(fptr);
    return count;
}