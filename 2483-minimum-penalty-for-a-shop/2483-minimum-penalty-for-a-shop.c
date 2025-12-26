int bestClosingTime(char* customers) {
    int penalty = 0;
    int n = 0;

    for (int i = 0; customers[i] != '\0'; i++) {
        if (customers[i] == 'Y') penalty++;
        n++;
    }

    int minPenalty = penalty;
    int bestHour = 0;

    for (int i = 0; i < n; i++) {
        if (customers[i] == 'Y') {
            penalty--;   
        } else {
            penalty++;   
        }

        if (penalty < minPenalty) {
            minPenalty = penalty;
            bestHour = i + 1;
        }
    }

    return bestHour;
}
