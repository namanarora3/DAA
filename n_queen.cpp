#include<iostream>
#include <bits/stdc++.h>
#define N 4
using namespace std;

void printSolution(int b[N][N]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(b[i][j]){
                cout<<"Q ";
            }
            else{
                cout<<".";
            }
        }
        cout<<endl;
    }
    
}


bool isSafe(int b[N][N],int r,int c){
    for(int j=0;j<c;j++){
        if(b[r][j])
        return false;
    }
    for(int i=r,j=c;i>=0 && j>=0;i--,j--){
        if(b[i][j])
        return false;
    }
    for(int i=r,j=c;i<N && j>=0;i++,j--){
        if(b[i][j])
        return false;
    }
    return true;
}

bool solve(int b[N][N],int c){
    if(c>=N)
    return true;

    for(int i=0;i<N;i++){
        if(isSafe(b,i,c)){
        b[i][c]=true;
        if(solve(b,c+1))
        return true;
        b[i][c]=0;
        }
    }
    return false;
}


bool solveP() {
    int b[N][N]={0};
if(solve(b,0)==false){
    cout<<"Solution not possible"<<endl;
    return false;
}
printSolution(b);
return true;
}

int main(){
    solveP();
return 0;
}