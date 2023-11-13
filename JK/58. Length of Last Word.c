#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s) {
    int ans = 0;
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        if (s[i] == ' ' && i < length - 1 && s[i + 1] != ' ') {
            ans = 0;
        } else if (s[i] != ' ') {
            ans++;
        }
    }

    return ans;
}





int main() {
    // Test the function
    char str[] = "Hello World";
    printf("Length of the last word in '%s' is %d\n", str, lengthOfLastWord(str));

    return 0;
}
