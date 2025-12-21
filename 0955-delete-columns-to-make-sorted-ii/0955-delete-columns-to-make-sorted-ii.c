int minDeletionSize(char** strs, int strsSize) {

    if (strsSize <= 1) {
        return 0;
    }

    int n = strsSize;
    int m = strlen(strs[0]);
    int deleteCount = 0;

    bool* sorted = (bool*)calloc(n - 1, sizeof(bool));

    for (int col = 0; col < m; col++) {

        bool needDelete = false;

        for (int i = 0; i < n - 1; i++) {
            if (!sorted[i] && strs[i][col] > strs[i + 1][col]) {
                needDelete = true;
                break;
            }
        }

        if (needDelete) {
            deleteCount++;
            continue;
        }

        for (int i = 0; i < n - 1; i++) {
            if (!sorted[i] && strs[i][col] < strs[i + 1][col]) {
                sorted[i] = true;
            }
        }
    }

    free(sorted);
    return deleteCount;
}
