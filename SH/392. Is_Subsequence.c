bool isSubsequence(char* s, char* t) {
    int start_1, start_2, end_1, end_2;
    start_1 = start_2 = 0;
    end_1 = strlen(s);
    end_2 = strlen(t);
    while((start_1<end_1)&&(start_2<end_2)){
        if(s[start_1]==t[start_2]){start_1++;}
        start_2++;
    }
    return start_1 == end_1;
}
