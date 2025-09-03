void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int size=m+n,i=0,j=0,k=0;
    int arr[size];
    while(i<m && j<n)
    {
        if(nums1[i]<nums2[j])
        {
            arr[k]=nums1[i];
            i++;
        }
        else{
            arr[k]=nums2[j];
            j++;
        }
        k++;
    }
    while(i<m)
    {
        arr[k]=nums1[i];
        i++;
        k++;
    }
    while(j<n)
    {
        arr[k]=nums2[j];
        j++;
        k++;
    }

    i=0;
    while(i<k)
    {
        nums1[i]=arr[i];
        i++;
    }
}