class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        if(n==0) return 0;
        if(n==1)return 1;
        int count = 0;
       
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i = 0;i<n;i++){
            dp[i][i]=true;
            count++;
        }
        for(int i = 0;i<n-1;i++){
            if(s[i]==s[i+1]){
                count++;
                dp[i][i+1]=true;
            }
        }
        for(int len = 3;len<=n;len++){
            for(int i = 0;i<=n-len;i++){
                int j = i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    count++;
                }
            }
        }
        return count;
    }
};
