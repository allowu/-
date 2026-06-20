class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size(),left,right,i;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(i=0;i+2<n;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            left=i+1;
            right=n-1;
            while(left<right){
                int sum=nums[left]+nums[right]+nums[i];
                if(sum==0){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    while(left<n-1&&nums[left]==nums[left+1]){
                        left++;
                    }
                    while(right>0&&nums[right]==nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }
                if(sum<0){
                    left++;
                }
                else if(sum>0){
                    right--;
                }
            }
        }
        return ans;
    }
};