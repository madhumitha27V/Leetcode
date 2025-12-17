#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    char concat1[1000] = "";  
    char concat2[1000] = "";

    for(int i = 0; i < word1Size; i++) {
        strcat(concat1, word1[i]);
    }

    for(int i = 0; i < word2Size; i++) {
        strcat(concat2, word2[i]);
    }

    if(strcmp(concat1, concat2) == 0) {
        return true;
    } else {
        return false;
    }
}
