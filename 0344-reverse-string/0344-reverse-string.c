void reverseString(char* s, int sSize) {
    char temp[sSize];
    int k = 0;

    for (int i = sSize - 1; i >= 0; i--) {
        temp[k] = s[i];
        k++;
    }

    for (int i = 0; i < sSize; i++) {
        s[i] = temp[i];
    }
}
