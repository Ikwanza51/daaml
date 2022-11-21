#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
};

int Min(int a,int b){
    if(a<b) return a;
    else return b;
}

int main(){
    int n,m;
    cout<<"\nEnter the number of vertices :- "; cin>>n;
    cout<<"\nEnter the number of Edges :- "; cin>>m;

    vector<Edge> e(m+1);
    vector<int> dist(n+1,INT32_MAX);

    for(int i=0;i<m;i++){
        cout<<"\nEdge "<<i+1<<" :- ";
        cout<<"\nSource :- ";   cin>>e[i].u;
        cout<<"\nEnd :- ";   cin>>e[i].v;
        cout<<"\nWeight :- ";   cin>>e[i].w;
    }

    int src;
    cout<<"\nEnter the Source Node :- "; cin>>src;
    
    dist[src]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(dist[e[j].u]<INT32_MAX){
                dist[e[j].v]=Min(dist[e[j].v],dist[e[j].u]+e[j].w);
            }
        }
        cout<<"\n Pass "<<i+1<<endl;
        for(int k=1;k<n;k++){
            cout<<k<<" ----> "<<dist[k]<<endl;
        }
        cout<<endl;
    }
    
    cout<<"Final distances :- "<<endl;
    for(int k=1;k<n;k++){
        cout<<k<<" ----> "<<dist[k]<<endl;
    }
    cout<<endl;

}