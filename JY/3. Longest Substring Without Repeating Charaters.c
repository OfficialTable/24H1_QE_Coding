#define MAX(x,y) (x)>(y) ? (x) : (y)

int lengthOfLongestSubstring(char* s) {
    
    int s_length = 0;
    while (s[s_length] != '\0'){
        s_length++;
    }

    int *lastIndex = (int*)malloc(256*sizeof(int));
    for (int i =0 ; i <256 ; i++){
        lastIndex[i] = -1;
    }

    int start = 0 ;
    int max_length = 0;

    for (int end = 0; end < s_length ; end++){
        start = MAX(start, lastIndex[s[end]] +1 );
        max_length = MAX(max_length, end-start+1);
        lastIndex[s[end]] = end;
    }
    return max_length;
}