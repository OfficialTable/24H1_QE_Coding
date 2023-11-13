


// Old Solution
int maxArea(int* height, int heightSize){
    int l = 0, r = heightSize - 1;
    int maxArea = 0;
    while ( l < r ){
        int area = height[l] < height[r] ? height[l] * (r-l) : height[r] * (r-l);
        if ( area > maxArea ){
            maxArea = area;
        } 
        
        if ( height[l] < height[r]) l++;
        else r--;
    }
    return maxArea;
}