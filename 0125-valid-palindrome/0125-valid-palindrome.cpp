class Solution {
public:
    bool helper(int i, int j, string &s) {
       
        while (i < j && !isalnum(s[i])) i++;
        while (i < j && !isalnum(s[j])) j--;

      
        if (i >= j)
            return true;
        if (tolower(s[i]) != tolower(s[j]))
            return false;

        return helper(i + 1, j - 1, s);
    }

    bool isPalindrome(string s) {
        return helper(0, s.size() - 1, s);
    }
};