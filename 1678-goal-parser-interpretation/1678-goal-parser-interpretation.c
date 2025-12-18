char* interpret(char* command) {
    int j = 0;

    for (int i = 0; command[i] != '\0'; i++) {

        if (command[i] == '(' && command[i + 1] == ')') {
            command[j++] = 'o';
            i++;   
        }
        else if (command[i] == '(' && command[i + 1] == 'a') {
            command[j++] = 'a';
            command[j++] = 'l';
            i += 3; 
        }
        else {
            command[j++] = command[i];
        }
    }

    command[j] = '\0';
    return command;
}
