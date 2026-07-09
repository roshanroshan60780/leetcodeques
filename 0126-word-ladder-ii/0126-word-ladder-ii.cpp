class Solution {
private:
    void dfs(string beginword, string curr,unordered_map<string,vector<string>>& parent ,vector<vector<string>>& ans , vector<string> &seq){
        if(curr==beginword){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        vector<string>& parentscurr = parent[curr];
        for (string& p : parentscurr) {
            seq.push_back(p);
            dfs(beginword, p, parent , ans , seq);
            seq.pop_back();
        }
        
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()) return{};
        q.push(beginWord);
        st.erase(beginWord);
        int level=1;
        int flag=0;
        unordered_map<string,vector<string>> parent;
        int n=beginWord.size();
        while(!q.empty()){
            if(flag) break;
            unordered_set<string> used;
            int size=q.size();
            for(int k=0 ; k<size ; k++){
                string word=q.front();
                q.pop();
                
                for(int i=0 ; i<n ; i++){
                    string nword=word;
                    for(int j=97 ; j<=122 ; j++){
                        nword[i]=j;
                        if(st.find(nword)!=st.end()){
                            if(nword==endWord) flag=1;
                            if(!used.count(nword)){ 
                                q.push(nword);
                                used.insert(nword);
                            }
                            parent[nword].push_back(word);
                        }
                    }
                }
            }
            for(string s: used){
                st.erase(s);
            }
            level++;
        }
        if(!flag) return {};
        vector<vector<string>> ans;
        vector<string> seq;
        seq.push_back(endWord);
        dfs(beginWord,endWord,parent,ans,seq);
        return ans;
    }
};