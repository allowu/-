/*给定两个数组 nums1 和 nums2 ，返回 它们的 交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
 

提示：

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000*/

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
/*c++版本
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> res;
        unordered_set <int> arr(nums2.begin(),nums2.end());
        for(int num : nums1){
            if(arr.find(num)!=arr.end()){
                res.insert(num);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
};*/
/*更新后的c版本
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int i,j=0;
    int arr[1005]={0};
    int* brr=(int *)calloc(1005,sizeof(int));
    for(i=0;i<nums1Size;i++){
        arr[nums1[i]]++;
    }
    for(i=0;i<nums2Size;i++){
        if(arr[nums2[i]]){
            brr[j++]=nums2[i];
            arr[nums2[i]]=0;
        }
    }
    *returnSize=j;
    return brr;
}
*/
