#include<bits/stdc++.h>
using namespace std;

int n;
int c[100][100],r[100][100],w[100][100];
int p[100],k[100];

int optCost(int i,int j){
    if(i>j)return 0;
    if(c[i][j] != -1) return c[i][j];
    c[i][j] = INT_MAX;
    
    for(int q = i;q<=j;q++){
        int cost = optCost(i,q-1) + optCost(q+1,j);
        if(cost < c[i][j]){
            c[i][j] = cost;
            r[i][j] = q;
        }
    }
    c[i][j] += w[i][j];
    return c[i][j];
}

void calWeight(){
    for(int i = 1;i<=n;i++){
        w[i][i] = p[i];
        for(int j = i+1;j<=n;j++){
            w[i][j] += w[i][j-1] + p[j];
        }
    }
}

int main(){
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>k[i];
    for(int i = 0;i<=n;i++) cin>>p[i];
    
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            c[i][j] = -1;
            w[i][j] = 0;
            r[i][j] = 0;
        }
    }
    
    calWeight();
    int minCost = optCost(1,n);
    cout<<minCost<<endl;
    
}
