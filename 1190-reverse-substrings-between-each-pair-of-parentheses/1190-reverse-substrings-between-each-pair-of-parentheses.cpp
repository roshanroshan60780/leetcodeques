class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        int i=0;
        stack<char> st;
        while(i<n){
            if(s[i]==')'){
                string str="";
                while(st.top()!='('){
                    str.push_back(st.top());
                    st.pop();
                }
                st.pop();  //to remove'('
                for(char ch : str){
                    st.push(ch);
                }
                i++;
            }
            else{
                st.push(s[i]);
                i++;
            }
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};