class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin() , wordList.end());
        int n=beginWord.size();
        if(st.find(endWord)==st.end()) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord , 1});
        st.erase(beginWord);
        while(!q.empty()){
            pair<string,int> temp = q.front();
            q.pop();
            string word=temp.first;
            int step=temp.second;
            if(word==endWord) return step;
            for(int i=0 ; i<n ; i++){
                string nword=word;
                for(int j=97 ; j<=122 ; j++){
                    nword[i]=j;
                    if(st.find(nword)!=st.end()){
                        q.push({nword,step+1});
                        st.erase(nword);
                    }
                }
            }
        }
        return 0;
    }
};