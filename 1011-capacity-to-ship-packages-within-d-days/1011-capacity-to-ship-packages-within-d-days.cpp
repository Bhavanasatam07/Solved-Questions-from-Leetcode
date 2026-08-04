class Solution {
public:
    int noofdays(vector<int>& weights,int cap){
        int load =0 ;
        int nfdays =1;
        for (int i=0 ; i<weights.size(); i++){
            if (load + weights[i]<= cap){
                load += weights[i];
            }
            else {
             nfdays++;
             load = weights[i];
            } 
        }
        return nfdays;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low =*max_element(weights.begin(),weights.end());
        int high =accumulate(weights.begin(),weights.end(),0);
        int ans = 0;

        while(low <= high){
            int mid = (low + high)/2;
            int finddays = noofdays(weights,mid);
            if (finddays <= days){
                ans = mid;
                high = mid - 1;
            }
            else
               low = mid + 1;
        }
        return low;
    }
};