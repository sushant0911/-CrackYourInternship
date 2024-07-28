class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int original = x;
        long a = 0;
        while(x != 0){
            a = a*10 + x%10;
            x = x/10;
        }
        return ((int)a == original);
    }
};
