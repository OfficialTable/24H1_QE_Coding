bool isPalindrome(int x){
    if (x<0){
        return false;
    }
    
    //leetcode 케이스 같은 경우에는 long 붙여야 pass됐음 (testcase가 길어서.)
    long int reversed = 0;
    int original = x;
    //이 밑에 수행하면서 x값이 변하기 때문에 x값을 미리 copy해두어야함.
    while(x>0){
        int remainder = x % 10;
        reversed = reversed * 10 + remainder;
        x /= 10;
    }
    return reversed == original;
}