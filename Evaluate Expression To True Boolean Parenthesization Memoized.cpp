class Solution{
public:
    int dp[201][201][2];
int solve(string S,int i, int j, bool isTrue)
{
    if(i > j)
    {
        return dp[i][j][isTrue] = false;
    }
    if(i == j)
    {
        if(isTrue == true)
        {
            dp[i][j][1] = S[i] == 'T';
        }
        else
        {
            dp[i][j][0] = S[i] == 'F';
        }
        return dp[i][j][isTrue];
    }

    if(dp[i][j][isTrue] != -1)
    {
        return dp[i][j][isTrue];
    }

    int ans = 0;
    for(int k=i+1; k<=j-1; k=k+2)
    {
        int lt, lf, rt, rf;
        if(dp[i][k-1][true] == -1)
        {
            lt = solve(S, i, k-1, true);
        }
        else
        {
            lt = dp[i][k-1][true];
        }

        if(dp[i][k-1][false] == -1)
        {
            lf = solve(S, i, k-1, false);
        }
        else
        {
            lf = dp[i][k-1][false];
        }

        if(dp[k+1][j][true] == -1)
        {
            rt = solve(S, k+1, j, true);
        }
        else
        {
            rt = dp[k+1][j][true];
        }

        if(dp[k+1][j][false] == -1)
        {
            rf = solve(S, k+1, j, false);
        }
        else
        {
            rf = dp[k+1][j][false];
        }


        if(S[k] == '&')
        {
            if(isTrue == true)
            {
                ans += (lt*rt);
            }
            else
            {
                ans += (lt*rf) + (lf*rt) + (lf*rf);
            }
        }

        else if(S[k] == '|')
        {
            if(isTrue == true)
            {
                ans += (lt*rf) + (lf*rt) + (lt*rt);
            }
            else
            {
            ans += (lf*rf);
            }
        }
        else if(S[k] == '^')
        {
            if(isTrue == true)
            {
                ans += (lt*rf) + (lf*rt);
            }
            else
            {
                ans += (lf*rf) + (lt*rt);
            }
        }

    }
    return dp[i][j][isTrue] = ans%1003;
    }

    int countWays(int N, string S)
    {

        memset(dp, -1, sizeof(dp));
        return solve(S, 0, N-1, true);
    }   
};
