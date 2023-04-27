#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int matrix(int arr[],int n){
    int dp[n][n]={0};

    for(int d=1;d<=n-1;d++){
        for(int i=1;i<n-d;i++){
            int j=d+i;
            int min=INT_MAX;
            for(int k=i;k<j;k++){
                int q=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(q<min){
                    min=q;
                }
                dp[i][j]=q;
            }
        }
    }

// return dp[1][n-1];



    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main(){
int arr[]={1,2,3,4};
int n=sizeof(arr)/sizeof(arr[0]);
cout<<matrix(arr, n);
return 0;
}