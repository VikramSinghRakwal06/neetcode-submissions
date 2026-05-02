class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);
        if(!st.count(endWord))return 0;
        int count = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto  curr = q.front();
                q.pop();
                if(curr==endWord)return count;
                for(int i = 0;i<curr.length();i++){
                    string c = curr;
                    for(int j = 0;j<26;j++){
                        c[i]='a'+j;
                        if(st.count(c)){q.push(c);
                        st.erase(c);
                        }
                    }
                    c=curr;
                }
            }count++;
        }
    return 0;
    }
};
