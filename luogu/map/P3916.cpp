#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,a,b,aaa[1000001],maxx[100001];
vector<int> adj[100001];

void map(int u,int v){
    adj[v].push_back(u);
}

void dfs(int sy,int ans){
    aaa[sy]=1;
    maxx[sy]=ans;
    for(int v:adj[sy]){
        if(aaa[v]==1) continue; 
        dfs(v,ans);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        map(a,b);
    }
    for(int i=n;i>=1;i--){
        if(aaa[i]==1) continue; 
        dfs(i,i);   
    }
    for(int i=1;i<=n;i++){
        printf("%d ",maxx[i]);
    }
    printf("\n");
    return 0;
}