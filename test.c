#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

char *const unalterable_pointer = "abcdefghijklmnopqrstuvwxyz";

void magic(char *veccar, int *index, long *counter, char car, int size, int *index2, char *auxalphabet)
{
    int i=0;
    if (*counter == 26) return;
    if (*index == size) return;
    if (veccar[*index + 1] != car) magic(veccar, index, counter, unalterable_pointer[*index2 = *index2 + 1], size, index2,auxalphabet);
    if (veccar[*index + 1] == car)
    {
        for(i=0;i<26;i++) {if (auxalphabet[i] == car) {*counter = *counter-1; break;}};
        auxalphabet[*counter+1] = car; *counter = *counter + 1; *index2 = 0; *index = *index + 1;
        magic(veccar, index, counter, unalterable_pointer[*index2], size, index2,auxalphabet);
    }
}

void main(int argc, char *argv[])
{
    long counter = 0; int size = 0; char *string; int i = 0; int index = 0; int index2 = 0; char *auxalphabet =calloc(27,sizeof(char));
    if (argc > 2 || argc < 2) return;
    string = (char *)malloc((strlen(argv[1]) + 1) * sizeof(char));
    strcpy(string, argv[1]);
    size = strlen(string);
    for (; *string; ++string) *string = tolower(*string);
    for (i = 0; i < size + 1; i++) --string;
    magic(string, &index, &counter, unalterable_pointer[index2], size, &index2,auxalphabet);
    if (counter == 26){printf("*************TRUE**********************"); return;};
    printf("*************False**********************");
}