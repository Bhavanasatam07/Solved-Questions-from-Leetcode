class Solution {
public:
    bool isPalindrome(int x) {
       
        int dup = x;
        long long RevNum =0;

        while (x >0){
        int lastdigit= x%10;
        x = x / 10;
        RevNum = (RevNum * 10)+ lastdigit;
    }; 
       if (RevNum == dup){
            return true;
        }
            else {
                return false;

            }
        
        }
};
