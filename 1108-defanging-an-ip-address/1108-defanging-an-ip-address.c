char * defangIPaddr(char * address){
        int n = strlen(address);
        char* result = malloc(n + n + 1); 
        int k = 0;

    for(int i = 0 ; i < n ; i++){
        if(address[i] == '.'){
            result[k++] = '[';
            result[k++] = '.';
            result[k++] = ']';
        }
        else{
            result[k++] = address[i];
        }
    }
    result[k] = '\0';
    return result;;
}

