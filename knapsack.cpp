#include<bits/stdc++.h>
using namespace std;

struct List{
    int profit,weight;
    float d;
};

void input(List list[], int N){
    for(int i=0; i<N; i++){
        cout<<"\n Profit "<<i+1;cin>>list[i].profit;
        cout<<"\n Weight "<<i+1;cin>>list[i].weight;
        list[i].d=(float)list[i].profit / (float)list[i].weight;
    }
}

void Display(List list[], int N){
    for(int i=0; i<N; i++){
        cout<<"\n Profit "<<i+1<<" "<<list[i].profit<<endl;
        cout<<"\n Weight "<<i+1<<" "<<list[i].weight<<endl;
        cout<<"\n Profit/Weight "<<i+1<<" "<<list[i].d<<endl;
    }
}

bool compare(List l1,List l2){
    return (l1.d>l2.d);
}

void Knapsack(List list[], int N, int W){
    float sw=0,sp=0;
    for(int i=0;i<N;i++){
        if(sw+list[i].weight <= W){
            sw+=list[i].weight;
            sp+=list[i].profit;
        }
        else{
            float frac=0;
            frac=(float)(W-sw)/(float)list[i].weight;
            sw+=frac*list[i].weight;
            sp+=frac*list[i].profit;
            break;
        }
    }
    cout<<"\n Max Profit :- "<<sp<<endl;
}

int main(){      
    int n;
    cout<<"\nEnter No of items :- ";    cin>>n;
    List list[n];
    input(list,n);
    sort(list,list+n,compare);
    Display(list,n);

    int W;
    cout<<"\nEnter Max Weight :- "; cin>>W;
    Knapsack(list,n,W);

}