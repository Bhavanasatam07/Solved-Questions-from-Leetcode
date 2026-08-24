class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftindx = k-1 ;
        int rightindx = n-1;
        int sum =0 ;

        for(int i =0 ; i < k; i++){
            sum += cardPoints[i];
        }

        int ans = sum;

        for(int i =0 ; i < k ;i++){
            sum -= cardPoints[leftindx];
            leftindx--;

            sum += cardPoints[rightindx];
            rightindx--;

            ans = max(ans,sum);
        }
        return ans;
    }

};