class Solution {
public:
    int reverseBits(int n) {
        int rev=0;
        int i=0;
        while(i<32){
            rev=rev<<1;
            if(n&1) rev++;
            n=n>>1;
            i++;
        }
        return rev;
    }
};