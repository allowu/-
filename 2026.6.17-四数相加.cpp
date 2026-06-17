/*
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/
//实际就是考察你对map是否熟悉,思维难度不高;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt=0,i,j,n=nums1.size();
        unordered_map<int,int>map;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                map[nums3[i]+nums4[j]]++;
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                auto it = map.find(-(nums1[i]+nums2[j]));
                if(it!=map.end()){
                    cnt+=map[-(nums1[i]+nums2[j])];
                }
            }
        }
        return cnt;
    }
};