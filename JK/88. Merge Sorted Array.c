void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    for(int i = m - 1; i >= 0; i--) {
        nums1[i + n] = nums1[i];
    }
    
    int i = n;
    int j = 0;
    int k = 0;

    while (j < n && i < m + n) {
        if (nums1[i] < nums2[j]) {
            nums1[k] = nums1[i];
            i++;
        } else {
            nums1[k] = nums2[j];
            j++;
        }
        k++;
    }

    while (j < n) {
        nums1[k] = nums2[j];
        j++;
        k++;
    }

}

int main() {
    int nums1[6] = {1, 2, 3, 0, 0, 0}; // The size should be m + n, with m elements initialized
    int nums2[3] = {2, 5, 6};          // n elements
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    printf("Merged array: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}