bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) -1;

    while(left < right){
        while(isalnum(s[left]) == false && left < right){
            left++;
        }
        while(isalnum(s[right]) == false && left < right){
            right--;
        }
        if(tolower(s[left]) != tolower(s[right])){
            return false;
        }
        left++;
        right--;
    }
    return true;
}


//사실 이버젼도 문제없다고 생각하는데 리트코드 돌리면 테스트케이스는 맞고 Result는 Runtime Error뜸.. ㅜㅜ left<right를 두번째 while문에서도 넣으면 각 str의 반만 보면 돼서인것같은데 정확히는 모르겠음
bool isPalindrome2(char* s) {
    int left = 0;
    int right = strlen(s) -1;

    while(left < right){
        while(isalnum(s[left]) == false){
            left++;
        }
        while(isalnum(s[right]) == false){
            right--;
        }
        if(tolower(s[left]) != tolower(s[right])){
            return false;
        }
        left++;
        right--;
    }
    return true;
}