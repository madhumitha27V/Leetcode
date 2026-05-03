#include <string.h>
#include <stdbool.h>
bool rotateString(char* s, char* goal) {
  if(strcmp(s,goal) == 0){
    return true;
  }
  return false;
}