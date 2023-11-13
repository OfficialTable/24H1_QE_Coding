#include <stdio.h>
#include <string.h>

int strStr(char *haystack, char *needle) {
    int ans = -1;

    if (strlen(needle) == 0) return 0;

    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);

    for (int i = 0; i <= haystackLen - needleLen; i++) {
        if (strncmp(&haystack[i], needle, needleLen) == 0) {
            ans = i;
            break;
        }
    }

    return ans;
}




int main() {
    // Test the function
    char haystack[] = "hello";
    char needle[] = "ll";
    int result = strStr(haystack, needle);

    printf("Index of '%s' in '%s' is %d\n", needle, haystack, result);

    return 0;
}
