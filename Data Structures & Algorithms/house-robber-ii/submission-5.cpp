class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0 )return 0;
        if(n==1)return nums[0];
        vector<int> dp(n), dp2(n);

        dp[0]=0;
        dp2[0]=0;
        dp[1]=nums[0], dp2[1]=nums[1];
        // dp[2]=max(nums[0],nums[1]), dp2[2]=max(nums[1],nums[2]);
        for(int i = 2;i<n;i++){
            dp[i]= max(nums[i-1]+dp[i-2], dp[i-1]);
      
            dp2[i]=max(nums[i]+dp2[i-2],dp2[i-1]);
        }
        return max(dp[n-1], dp2[n-1]);
    }
};
