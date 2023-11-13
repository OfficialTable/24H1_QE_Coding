#include <stdio.h>
#include <string.h>


char* longestCommonPrefix(char **strs, int strsSize) {

    if (strsSize == 0) return "";

    char *prefix = strs[0];

    for (int i = 1; i < strsSize; i++) {
        if (strlen(prefix) > strlen(strs[i])) {
            prefix = strs[i];
        }
    }

    for (int i = 0; i < strsSize; i++) {
        while (strlen(prefix) > 0) {
            if (strncmp(strs[i], prefix, strlen(prefix)) == 0) {
                break;
            } else {
                prefix[strlen(prefix) - 1] = '\0';
            }
        }
    }

    return prefix;
}




int main() {
    // Example usage
    char *strs[] = {"flower", "flow", "flight"};
    int strsSize = 3;

    char *result = longestCommonPrefix(strs, strsSize);
    printf("Longest common prefix: %s\n", result);

    return 0;
}
