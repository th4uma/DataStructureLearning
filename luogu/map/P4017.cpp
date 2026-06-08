#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,r[1000001],c[1000001],aaa[1000001],a,b,ans;
vector<int> adj[100001];
void map(int u,int v){
    adj[u].push_back(v);
    c[u]++;
    r[v]++;
}

void bfs(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(r[i]==0){
            q.push(i);
            aaa[i]=1;
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            aaa[v]=(aaa[v]+aaa[u])%80112002;
            r[v]--;
            if(r[v]==0) q.push(v);
        }
    }
    for(int i=1;i<=n;i++){
        if(c[i]==0){
            ans=(aaa[i]+ans)%80112002;
        }
    }
}

int main(){
    // 输入建图
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        map(a,b);
    }                        
    bfs();
    printf("%d\n",ans);
    
    printf("\n");
    return 0;
}
