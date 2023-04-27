#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int sumFrequency(int freq[],int i,int j){
    int sum=0;
    for (int k = i+1; k <=j; k++)
    {
        sum+=freq[k];
    }
    return sum;
}

int obst(int keys[], int freq[],int n){
    int x=n+1;
    int dp[x][x]={0};

    for(int i=0,j=1;i<n+1 && j<n+1;i++,j++){
        dp[i][j]=sumFrequency(freq,i-1,j-1);
    }

    for(int d=2;d<=n;d++){
        for(int i=0;i<=n-d;i++){
            int j=d+i;
            int min=INT_MAX;
            int freqsum=sumFrequency(freq,i-1,j-1);

            for(int k=i+1;k<=j;k++){
                int q=dp[i][k-1]+dp[k][j];
                if(q<min){
                    min=q;
                }
                dp[i][j]=min+freqsum;
            }
        }
    }

// return dp[1][n-1];



    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main(){
int keys[]={10,12,20};
int freq[]={34,8,50};
int n=sizeof(keys)/sizeof(keys[0]);
cout<<obst(keys,freq,n);
return 0;
}