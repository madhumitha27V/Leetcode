#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* countMentions(int numberOfUsers, char*** events, int eventsSize, int* eventsColSize, int* returnSize) {
    *returnSize = numberOfUsers;
    int* mentions = calloc(numberOfUsers, sizeof(int));
    int offlineUntil[101] = {0};
    int online[101];

    for (int i = 0; i < numberOfUsers; i++) online[i] = 1;

    for (int i = 0; i < eventsSize; i++) {
        char* type = events[i][0];
        int t = atoi(events[i][1]);
        char* info = events[i][2];

        for (int u = 0; u < numberOfUsers; u++) {
            if (!online[u] && offlineUntil[u] <= t)
                online[u] = 1;
        }

        if (strcmp(type, "OFFLINE") == 0) {
            int uid = atoi(info);
            online[uid] = 0;
            offlineUntil[uid] = t + 60;
        } else { 
            if (strcmp(info, "ALL") == 0) {
                for (int u = 0; u < numberOfUsers; u++) mentions[u]++;
            } else if (strcmp(info, "HERE") == 0) {
                for (int u = 0; u < numberOfUsers; u++)
                    if (online[u]) mentions[u]++;
            } else {
                char* p = info;
                while (*p) {
                    if (*p == 'i' && *(p+1) == 'd') {
                        p += 2;
                        int uid = 0;
                        while (*p >= '0' && *p <= '9') {
                            uid = uid * 10 + (*p - '0');
                            p++;
                        }
                        if (uid >= 0 && uid < numberOfUsers)
                            mentions[uid]++;
                    } else {
                        p++;
                    }
                }
            }
        }
    }

    return mentions;
}
