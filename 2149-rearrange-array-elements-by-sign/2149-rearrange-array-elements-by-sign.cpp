class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        int posindx=0;
        int negindx = 1;

        for(int i=0 ;i<nums.size(); i++){
            if(nums[i]>0){
                ans[posindx] = nums[i];
                posindx += 2;
            }
            if(nums[i]<0){
                ans[negindx] = nums[i];
                negindx +=2;
            }
        }
        return ans;

        
    }
};