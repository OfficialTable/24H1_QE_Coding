#include <stdio.h>
#include <string.h>

int romanToInt(char *s) {
    int val[256];
    val['I'] = 1;
    val['V'] = 5;
    val['X'] = 10;
    val['L'] = 50;
    val['C'] = 100;
    val['D'] = 500;
    val['M'] = 1000;

    int ans = 0;
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        if (i < (length - 1) && val[s[i]] < val[s[i + 1]]) {
            ans -= val[s[i]];
        } else {
            ans += val[s[i]];
        }
    }

    return ans;
}



int main() {
    // Test the function
    char roman[] = "MCMXCIV";
    printf("The integer value of %s is %d\n", roman, romanToInt(roman));

    return 0;
}
