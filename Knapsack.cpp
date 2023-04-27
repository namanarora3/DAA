#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int knapsack(int w[],int p[],int c){
    int dp[4][c+1];
    int i=0;
    int j=0;
    for(j=0;j<c+1;j++){
        dp[i][j]=0;
    }
    i=0;
    j=0;
    for(j=0;j<4;j++){
        dp[j][i]=0;
    }

    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < c+1; j++)
        {
            if(w[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i-1]]+p[i-1]);
            }        
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[3][c];




    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < c+1; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    

    return 0;
}

int main(){
int w[]={10,20,30};
int p[]={60,100,120};
int capacity=50;
knapsack(w,p,capacity);
return 0;
}