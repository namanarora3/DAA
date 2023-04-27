#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];
    int i = 0;
    // making first row 0
    for (int j = 0; j < n + 1; j++)
    {
        dp[i][j] = 0;
    }
    int j = 0;
    // making first column 0
    for (int j = 0; j < m + 1; j++)
    {
        dp[j][i] = 0;
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[m][n] << endl;
    // for finding the common string
    string s = "";
    i = m;
    j = n;
    while (i >= 0 && j >= 0)
    {
        int num = dp[i][j];
        if (num == dp[i - 1][j])
        {
            i--;
        }
        else if (num == dp[i][j - 1])
        {
            j--;
        }
        else
        {
            s.push_back(s2[j - 1]);
            i--;
            j--;
        }
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
    // for checking the matrix
    // for(int i=0;i<m+1;i++){
    //     for(int j=0;j<n+1;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}

int main()
{
    string s1 = "stone";
    string s2 = "toe";
    int m = s1.size();
    int n = s2.size();
    lcs(s1, s2, m, n);
    return 0;
}