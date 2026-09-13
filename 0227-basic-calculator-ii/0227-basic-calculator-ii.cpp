class Solution {
private:
    void removespace(int& i , string& s){
        int n=s.size();
        while (i<n && s[i] == ' ')
            i++;
    }
public:
    int calculate(string s) {
        int n = s.size();
        int i = 0;
        stack<int> st;
        int num = 0;
        removespace(i,s);
        int sign1 = 0;
        if (sign1 == '-') {
            sign1 = 1;
            i++;
        }
        while (i < n && 0 <= s[i] - '0' && s[i] - '0' <= 9) {
            num = 10 * num + (s[i] - '0');
            i++;
        }
        if (sign1)
            st.push(-1 * num);
        else
            st.push(num);

        while (i < n) {
            removespace(i,s);
            int op=s[i];
            i++;
            removespace(i,s);
            num=0;
            if(i>n) break;
            while (i < n && 0 <= s[i] - '0' && s[i] - '0' <= 9) {
                num = 10 * num + (s[i] - '0');
                i++;
            }
            if(op=='*'){
                int temp=st.top();
                st.pop();
                st.push(temp*num);
            }
            else if(op=='/'){
                int temp=st.top();
                st.pop();
                st.push(temp/num);
            }
            else if(op=='-'){
                st.push(-1*num);
            }
            else st.push(num);
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};