class Solution {
public:
    int dp[1001][1001];
    int n,m;
    int solve(int i ,int j,string &text1, string &text2){
        if(i==n||j==m)return 0;
        int &ret=dp[i][j];
        if(~ret)return ret;
        if(text1[i]==text2[j])
            ret=max(ret,solve(i+1,j+1,text1,text2)+1);
        ret=max(ret,solve(i+1,j,text1,text2));
        ret=max(ret,solve(i,j+1,text1,text2));
        return ret;
    }
    int LCS (string a, string b){
        int dp [1001][1001] = {};
        for(int i = 0 ; i < a.size(); i++){
            for(int j = 0 ; j <b.size();j++){
                dp[i+1][j+1]=(a[i]==b[j] ? dp[i][j]+1 : max(dp[i][j+1],dp[i+1][j]));
            }
        }
        return dp[a.size()][b.size()];
    }
    int LCS2 (string a, string b){
        int dp [2][1001] = {};
        for(int i = 0 ; i < a.size(); i++){
            for(int j = 0 ; j <b.size();j++){
                dp[(i+1)&1][j+1]=(a[i]==b[j] ? dp[i&1][j]+1 : max(dp[i&1][j+1],dp[(i+1)&1][j]));
            }
        }
        return dp[(a.size())&1][b.size()];
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof dp);
        n=text1.size();
        m=text2.size();
        
        return LCS2(text1,text2);
    }
};
