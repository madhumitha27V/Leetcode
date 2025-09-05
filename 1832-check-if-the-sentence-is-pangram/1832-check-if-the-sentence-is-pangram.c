bool checkIfPangram(char* sentence) {
      int seen[26] = {0}; 
    int len = strlen(sentence);

    for (int i = 0; i < len; i++) {
        if (isalpha(sentence[i])) {   
            char lower = tolower(sentence[i]);   
            seen[lower - 'a'] = 1;   
        }
    }

    for (int i = 0; i < 26; i++) {
        if (seen[i] == 0) {
            return false; 
        }
    }

    return true;
}