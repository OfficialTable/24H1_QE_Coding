
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int a = m-1;
    int b = n-1;
    int idx = m+n-1;

    while(b>=0){
        if(a>=0 && nums1[a]>nums2[b]){
            nums1[idx] = nums1[a];
            a -= 1;
        }
        else{
            nums1[idx] = nums2[b];
            b -= 1;
        }
        idx -= 1;
    }

}

// Driver code from JP
int main(void) {
    int nums1[6] = {1,2,3,0,0,0};
    int nums2[3] = {2,5,6};
    merge(nums1, 6, 3, nums2, 3, 3);
    for(int i=0; i<6; i++) {
        printf("%d ", nums1[i]);
    }
}

