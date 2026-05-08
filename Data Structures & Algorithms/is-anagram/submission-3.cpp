class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        vector<int> s1(26,0) , t1(26,0);

        for(auto &si: s){
            s1[si-'a']++;

        }
        for(auto & ti: t){
            t1[ti-'a']++;
        }
        return s1==t1;
    }
};
