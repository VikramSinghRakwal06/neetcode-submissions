class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n==0)return 1;
        if(n==1 && s=="0")return 0;
        if(n==1)return 1;
        vector<int> dp(n+1);
        dp[0]=1;
        if(s[0]=='0')dp[1]=0; 
        else dp[1]=1;
        for(int i = 2;i<=n;i++){
            if(s[i-1]!='0'){
                dp[i]+=dp[i-1];
            }
            int two = stoi(s.substr(i-2,2));
            if(two>=10&& two<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};
