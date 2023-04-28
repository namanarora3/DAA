#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int count(int coins[],int n,int w){
    int dp[n+1][w+1];
    for (int j= 0; j < w+1; j++)
    {
        dp[0][j]=0;
    }
    for (int i = 0; i < n+1; i++)
    {
        dp[i][0]=1;
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < w+1; j++)
        {
            if(coins[i-1]<=j){
                dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
    

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
}

int main(){
int coins[]={1,2,3};
int n=sizeof(coins)/sizeof(coins[0]);
int w=4;
cout << count(coins, n, w);
return 0;
}