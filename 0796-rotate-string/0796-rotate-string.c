#include <string.h>
#include <stdbool.h>

bool rotateString(char* s, char* goal) {
    if (strlen(s) != strlen(goal)) return false;

    char temp[201];  
    strcpy(temp, s);
    strcat(temp, s);

    return strstr(temp, goal) != NULL;
}