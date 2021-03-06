class Solution {
public:
    //动态规划，空间复杂度O(n)
    int numDecodings(string s) {
        if('0' == s[0])
            return 0;
        vector<int> dp(s.size() + 1);   //dp数组和参数s的下标对应关系是，dp的n - 1，对应s的n，dp保存的是s[0,1,2,3...n]的译码总数
        dp[0] = 1;
        dp[1] = 1;      //在s的i位置上，对应的是dp[i+1]，而dp[i+1] = dp[i] + dp[i-1]是一种可能的情况
        //考虑，当s大小为1时，只有一种解码方法
        //当s大小为2，但s[0] = 1 or 2，s[1] != 0时，解码方法有2种
        //当s小为2，但s[0] = 1 or 2，s[1] == 0时，解码方法只有一种
        //当s为3时，问题就回到了s大小为2时候的解法，因为编码的数字组合只能是两位
        for(int i = 1;i < s.size(); ++i)
        {
            //如果s[i] == '0'，那么s[i - 1]s[i]只能被作为一个数字组合来解释，所以它的解法是哈dp的前一项相同的，同时，在这种特殊情况下，s[i - 1]要么是'1'，要么是'2'，如果是其它值则不能解码
            if('0' == s[i])
                if( '1' == s[i-1] || '2' == s[i - 1])
                    dp[i + 1] = dp[i - 1];      //s[i]对应的是dp[i+1]
                else
                    return 0;
            else 
                //这里就有斐波那契数列和的意思了
                if('1' == s[i - 1] || ('2' == s[i - 1] && s[i] <= '6'))
                    dp[i + 1] = dp[i] + dp [i - 1];
                else
                    dp[i + 1] = dp[i];
        }
        
        return dp[s.size()];
    }
};
