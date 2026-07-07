class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posi=0, negi=0;
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[negi*2+1]=nums[i];
                negi++;
            }
            else {
                ans[posi*2]=nums[i];
                posi++;
            }
        }
        return ans;
    }
};