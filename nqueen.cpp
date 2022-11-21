#include<bits/stdc++.h>
using namespace std;

int n,queen[20];

bool check(int row,int col){
    for(int i=0;i<row;i++){
        int prow=i;
        int pcol=queen[i];
        if(pcol==col || abs(row-prow)==abs(col-pcol)){
            
            return 0;
        }
    }
    return 1;
}

int nqueen(int level){
    if(level==n){
        cout<<"\n[ ";
        for(int i=0;i<n;i++){
            cout<<" ("<<i<<" , "<<queen[i]<<") ";
        }
        cout<<" ]"<<endl;
        return 1;
    }

    int ans=0;
    for(int col=0;col<n;col++){
        if(check(level, col)){
            queen[level]=col;
            ans+=nqueen(level+1);
            queen[level]=-1;
        }
    }

    return ans;
}

int main(){
    cin>>n;
    memset(queen,-1,sizeof(queen));
    cout<<"\n"<<nqueen(0)<<endl;
}