#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,a,b,aaa[1000001],dl[1000001];
vector<int> adj[100001];

void tree(int u,int v){
    adj[u].push_back(v);
}

void dfs(int sy,int f){
    if(sy==0) return;
    printf("%d ",sy);
    aaa[sy]=1;
    for(int v:adj[sy]){
        if(v==f||aaa[v]==1) continue;
        dfs(v,sy);
    }
}

void bfs(int sy){
    int head=0,tail=0;
    aaa[sy]=1;
    dl[tail]=sy;
    tail++;

    while(head!=tail){
        int u=dl[head];
        printf("%d ",u);
        for(int v:adj[u]){
            if(aaa[v]==1) continue;
            dl[tail]=v;
            tail++;
            aaa[v]=1;
        }
        head++;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        tree(a,b);
    }
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end()); 
    }
    for(int i=0;i<=n;i++) aaa[i]=0;
    dfs(1,0);
    printf("\n");
    for(int i=0;i<=n;i++) aaa[i]=0;
    bfs(1);
    printf("\n");
    return 0;
}
