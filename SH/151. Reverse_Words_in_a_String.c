#include <string.h>

void reverse(char *w){
    int l = 0;
    int r = strlen(w)-1;
    while( l < r ){
        w[l] ^= w[r]; // Bitwise XOR
        w[r] ^= w[l];
        w[l++] ^= w[r--];
    }
}
char * reverseWords(char * s){
    int size = strlen(s);

    char temp[50] = "";
    int temp_size = 0;
    char res[10001] = "";
    int res_size = 0;
    for(int i = size-1; i >= 0; i--){
        // First storing all the possible characters
        if ( s[i] != ' ' ){
            temp[temp_size++] = s[i];
            temp[temp_size] = '\0';
        }
        // If it reaches the end, or if one of them are whitespace
        if ( (s[i] == ' ' && i != size-1 && s[i+1] != ' ') || (s[i] != ' ' && i == 0) ){
            reverse(temp);
            
            // Concatenating with space 
            strcat(res, temp);
            strcat(res, " ");
            
            res_size += temp_size + 1; 
            
            temp_size = 0;
        }
    }
    res[res_size-1] = '\0'; // whitespace
    // copy the contents of res into string s
    strcpy(s, res);
    return s;
}



/* For C++
#include <sstream>

char* reverseWords(char* s) {
    stringstream ss(s);
    string word;
    stack<string> st;
    while(ss>>word){
        std
    }
    int i = 0;
    char *iter = strtok(s, " ");
    while(iter){
        arr[i] = token;
        i++;
        iter = strtok(NULL, " ");
    }
    for(int j=strlen(s)-1;j>=0;j--){
        printf(arr[j]);
    }
    return 0;
}

// AddressError
char* reverseWords(char* s) {
    int arr[strlen(s)];
    int i = 0;
    char *iter = strtok(s, " ");
    while(iter){
        arr[i] = iter;
        i++;
        iter = strtok(NULL, " ");
    }
    for(int j=strlen(s)-1;j>=0;j--){
        printf(arr[j]);
    }
    return 0;
}
*/

/*
// To check whether the string is a Palindrome or not
#include <stdio.h>  
#include <string.h>  
int main ()  
{     
    // declare variables  
    char str1[30];  
    int i, len, flag = 0;  
      
    printf (" Enter a string: ");  
    scanf ("%s", str1);  
    len = strlen( str1 ); // get the string length  
      
      
    for ( i = 0; i < len; i++)  
    {     
        // str1[i] is not equal to str1[len-i-1]  
        if (str1[i] != str1[len - i - 1])  
        {  
            flag = 1;   
            break; // exit from if statement  
        }  
    }  
    if (flag)  
    {  
        printf (" %s is not a palindrome string", str1);  
    }  
    else  
    {  
        printf (" %s is a palindrome", str1);  
    }  
    return 0;  
}  
*/