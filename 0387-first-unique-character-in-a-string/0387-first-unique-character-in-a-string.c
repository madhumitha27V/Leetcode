int firstUniqChar(char* s) {
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        int count = 0;  

        for (int j = 0; j < len; j++) {
            if (i != j && s[i] == s[j]) {
                count++;   
                break;     
            }
        }

        if (count == 0) {
            return i; 
        }
    }

    return -1;  
}