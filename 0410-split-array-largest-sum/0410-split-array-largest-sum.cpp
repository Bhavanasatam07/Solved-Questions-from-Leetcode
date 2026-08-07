class Solution {
public:
    int allstudent(vector<int> &nums,int pages){
        int students =1;
        int totalpages =0;
        for (int i = 0 ; i< nums.size();i++){
            if ( totalpages + nums[i] <= pages){
                totalpages += nums[i];
            }
            else{
                students++;
                totalpages = nums[i];
            }
        }
        return students;
    }
    int findPages(vector<int> &nums, int m)  {
        int high =accumulate(nums.begin(),nums.end(),0);
        int low =*max_element(nums.begin(),nums.end());
        int mid = 0;
        int n = nums.size();
       
        while( low <= high){
            mid = (low + high)/ 2;
            int nfstudents = allstudent(nums,mid);
            if (nfstudents > m) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums , k);
    }
};