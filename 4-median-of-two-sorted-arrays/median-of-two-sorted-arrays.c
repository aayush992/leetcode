double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  
  int totalSize=nums1Size+nums2Size;
   int n3[totalSize];
   int i=0,j=0,k=0;
  while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            n3[k++] = nums1[i++];
        } else {
            n3[k++] = nums2[j++];
        }
    }

    // Copy any remaining elements from nums1
    while (i < nums1Size) {
        n3[k++] = nums1[i++];
    }

    // Copy any remaining elements from nums2
    while (j < nums2Size) {
        n3[k++] = nums2[j++];
    }
   
    double median;
        if(totalSize % 2 == 0) {
        median = (n3[totalSize / 2 - 1] + n3[totalSize / 2]) / 2.0;
    } else {
        median = n3[totalSize / 2];
    }
    return median;
}
