#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> sol;

void display() {
    for(int i=0;i<sol.size();i++){
        cout<<sol[i]<<" ";
    }
    cout<<endl;
}

void pop_front() {
    vector<int> temp;
    for(int i=1;i<sol.size();i++){
        temp.push_back(sol[i]);
    }
    sol.clear();
    for(int i=0;i<temp.size();i++){
        sol.push_back(temp[i]);
    }
}

int solution(int arr[],int n,int sum,int s=0,int ind=0){
    if(s>sum){
        return 0;
    }
    if(s==sum){
        cout<<"Solution is:"<<endl;
        display();
        return 0;
    }
    for(int i=ind;i<n;i++){
        sol.push_back(arr[i]);
        solution(arr,n,sum,s+arr[i],i+1);
        pop_front();
    }
}

int main(){
int arr[4]={7,11,13,14};
int n=4;
int sum=31;
solution(arr,n,sum);
return 0;
}