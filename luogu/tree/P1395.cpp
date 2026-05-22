#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,x,y,a,b,ansy;
vector<int> adj[100001];
long long sizee[100001],ans,anss=10000000000000000;

void tree(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void lon(int sy,int way,int f){
    if(sy==0) return;
    ans+=way;
    int size=1;
    for(int v:adj[sy]){ 
        if(v==f) continue;
        lon(v,way+1,sy);
        size+=sizee[v];
    }
    sizee[sy]=size;
}

void dfs(int sy,int as,int f){
    if(sy==0) return;
    if(as<anss) anss=as,ansy=sy;
    else if(as==anss){
        if(ansy>sy){
            ansy=sy;
        }
    }
    for(int v:adj[sy]){
        if(v==f) continue;
        dfs(v,as-sizee[v]*2+n,sy);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        tree(a,b);
    }
    lon(1,0,0);
    dfs(1,ans,0);
    printf("%d %d\n",ansy,anss);
    return 0;
}
