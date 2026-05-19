class Solution {
public:
    int climbStairs(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        if(n==2)return 2;
        int prev1= 1;
        int prev2 = 2;
        for(int i = 2;i<n;i++){
            prev2=prev1+prev2;
            prev1 = prev2-prev1;
        }
        return prev2;
    }
};
