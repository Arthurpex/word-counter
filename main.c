

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

/* Function declarations */
int countOccurrences(FILE *fptr, const char *word);

int main(int argc, char const *argv[])
{
    FILE *fptr;

    if(argc < 2){
        printf("Not enough arguments to start program\n");
        printf("Usage: ./sequential <word> \n");
        exit(EXIT_FAILURE);
    }

    fptr = fopen("words.txt", "r");
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read/write previleges.\n");

        exit(EXIT_FAILURE);
    }

    char word[50];
    int wCount;


    strcpy(word, argv[1]);

    // Call function to count all occurrence of word

    // For i in len(words){
    //      wCount = countOccourrences(words[i])
    //     wordsDict = {words[i]: Wcount}
    //}

    wCount = countOccurrences(fptr, word);

    printf("'%s' is found %d times in file.\n", word, wCount);

    // Close file
    fclose(fptr);
    return 0;
}


/**
 * Returns total occurrences of a word in given file.
 */
int countOccurrences(FILE *fptr, const char *word)
{
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

    return count;
}