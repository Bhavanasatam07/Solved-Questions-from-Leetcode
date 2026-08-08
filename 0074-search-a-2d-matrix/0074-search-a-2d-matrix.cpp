class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column= matrix[0].size();
        int low = 0;
        int high = row * column -1;
        while(low<=high){
            int mid = (low + high)/2;
            int rowno = mid / column;
            int colno = mid % column;
            if (matrix[rowno][colno] == target){
                return true;
            }
            else if (matrix[rowno][colno]<target){
                low = mid + 1;
            }
            else{ 
                high = mid -1;
            }
        }
        return false;
    }
};