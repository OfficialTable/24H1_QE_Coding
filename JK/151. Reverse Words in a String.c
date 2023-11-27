#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(char *s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}

char* reverseWords(char *s) {
    if (s == NULL) return NULL;

    int i = 0, j = 0, len = strlen(s);
    int start, end = 0, wordCount = 0;

    reverse(s, 0, len - 1);

    while (s[i]) {
        while (s[i] == ' ') i++; 
        if (s[i] == '\0') break;

        if (wordCount) s[j++] = ' '; 

        start = j;

        while (s[i] != '\0' && s[i] != ' ') s[j++] = s[i++]; 

        reverse(s, start, j - 1);

        wordCount++;
    }

    s[j] = '\0'; 

    return s;
}

int main() {
    char str[] = "  hello world  ";
    printf("Original: '%s'\n", str);
    printf("Reversed: '%s'\n", reverseWords(str));
    return 0;
}
