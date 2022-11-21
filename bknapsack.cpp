#include<bits/stdc++.h>
using namespace std;

int Max(int a,int b){
    if(a>=b) return a;
    else return b;
}

int main(){
    int n,W;
    cout<<"\n Enter No. Of items :- ";  cin>>n;
    cout<<"\n Enter Max Weight :- ";  cin>>W;

    int p[n],w[n],dp[n+1][W+1];

    for(int i=0;i<n;i++){
        cout<<"\n"<<i+1<<" Profit:- "; cin>>p[i];
        cout<<"\n"<<i+1<<" Weight:- "; cin>>w[i];
        cout<<endl;
    }

    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=0;i<=W;i++) dp[0][i]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(w[i-1]<=j){
                dp[i][j]=Max(dp[i-1][j],p[i-1]+dp[i-1][j-(w[i-1])]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    
    cout<<"\nMatrix :- "<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n Max Profit :- "<<dp[n][W];

    vector<int> sack;
    for(int i=n;i>0;i--){
        if(dp[i][W]==dp[i-1][W]) continue;
        else sack.push_back(i);
    }

    cout<<"\n Sack :- ";
    for(int i=0;i<sack.size();i++) cout<<sack[i]<<" ";
    cout<<endl;
    return 0;
}