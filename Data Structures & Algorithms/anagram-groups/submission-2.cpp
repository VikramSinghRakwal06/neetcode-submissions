class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> mp;
       for(auto &s: strs){
        string k = s;
        sort(k.begin(),k.end());
        mp[k].push_back(s);
       } 
       vector<vector<string>> ans;
       for(auto & c: mp){
        ans.push_back(c.second);
       }
       return ans;
    }
};
