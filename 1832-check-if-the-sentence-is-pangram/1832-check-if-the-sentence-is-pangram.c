#include <string.h>
#include <stdbool.h>

bool checkIfPangram(char *sentence) {
    for(char ch = 'a'; ch <= 'z'; ch++) {
        bool found = false;

        for(int i = 0; i < strlen(sentence); i++) {
            if(sentence[i] == ch) {
                found = true;
                break;
            }
        }

        if(!found) return false;   
    }
    return true; 
}