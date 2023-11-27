void reverse(char *left, char *right) {

    while (left < right) {

        int temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}


char* reverseWords(char* s) {
    
    // Allocate memory
    char *reversed_words = calloc(strlen(s) + 1, sizeof(char));

    // Remove spaces first
    char *new_start = s;
    char *new_end = s + strlen(s) - 1;

    while (*new_start == ' ') new_start++;
    while (*new_end == ' ') new_end--;

    // Get the substring
    char *ptr = new_start;
    char *ptr_reversed_words = reversed_words;

    while (ptr <= new_end) {

        if (*ptr != ' ' && *ptr != '\0') {

            *ptr_reversed_words = *ptr;

            ptr_reversed_words++;
        } else if (*ptr == ' ' && *(ptr + 1) != ' ') {

            *ptr_reversed_words = *ptr;

            ptr_reversed_words++;   
        }
        ptr++;
    }

    // Reverse words
    char *curr = reversed_words;
    char *prev = reversed_words;

    while (*curr != '\0') {

        curr++;

        if (*curr == '\0') {

            reverse(prev, curr - 1);
        }
        if (*curr == ' ') {

            reverse(prev, curr - 1);
            prev = curr + 1;
        }
    }

    // Reverse reversed_word
    reverse(reversed_words, reversed_words + strlen(reversed_words) - 1);

    // Return reversed_words ptr
    return reversed_words;
}