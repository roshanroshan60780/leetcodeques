class Solution {
public:
    int reverse(int x) {
        if(x==-2147483648) return 0;
        string xstr = to_string(abs(x));
        string revstr(xstr.rbegin(), xstr.rend());
        string maxint="2147483647";
        string minint="2147483648";
        if(x>0){
        if(revstr.size()==10 && revstr>maxint) return 0;
            int rev=stoi(revstr);
            return rev;
        }
        if(x<0){
            if(revstr.size()==10 && revstr>minint) return 0;
            int rev=stoi(revstr);
            return -1*rev;
        }

        int rev=stoi(revstr);
        return rev;
    }
};