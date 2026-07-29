class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0 , mid =0;
        int high = nums.size() - 1;
        while(low<=high){
            mid = (low + high ) / 2;
            if (nums[mid]== target){
                return true;
            }
            if (nums[low] == nums[mid] && nums[mid] == nums[high]){
                high--;
                low++;
                continue;
            }
            if (nums[mid]<= nums[high]){
                if (nums[mid] <=target && nums[high] >= target){
                    low = mid+1;
                }
                else 
                   high = mid -1;
            }
            else 
               if (nums[mid]>=target && target>= nums[low]){
                  high = mid -1;
               }
                else
                  low = mid +1;
        }
        return false;
    }
};
   