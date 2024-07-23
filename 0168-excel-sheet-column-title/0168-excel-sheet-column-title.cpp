class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        while(columnNumber > 0){
            int remainder = (columnNumber - 1) % 26;
            s += 'A' + remainder;
            columnNumber = (columnNumber - 1) / 26;
        }    
        reverse(s.begin(),s.end());
        return s;
    }
};