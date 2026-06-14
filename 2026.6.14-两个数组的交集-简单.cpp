/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int i,j=0,max=0,returnsize=0;
    for(i=0;i<nums1Size;i++){
        max=max>nums1[i]?max:nums1[i];
    }
    for(i=0;i<nums2Size;i++){
        max=max>nums2[i]?max:nums2[i];
    }
    int *arr=(int *)calloc(max+1,sizeof(int));
    int *brr=(int *)calloc(max+1,sizeof(int));
    for(i=0;i<nums1Size;i++){
        arr[nums1[i]]++;
        if(arr[nums1[i]]>1){
            arr[nums1[i]]=1;
        }
    }
    for(i=0;i<nums2Size;i++){
        arr[nums2[i]]++;
        if(arr[nums2[i]]>1&&brr[nums2[i]]==0){
            returnsize++;
            brr[nums2[i]]++;
        }
        else{
            arr[nums2[i]]--;
        }
    }
    int *crr=(int *)calloc(returnsize,sizeof(int));
    for(i=0;i<max+1;i++){
        if(brr[i]){
            crr[j++]=i;
        }
    }
    *returnSize=returnsize;
    return crr;
}