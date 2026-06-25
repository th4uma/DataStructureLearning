#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int m,n,ans,a,b,c,mx[100001];
long long err=-1000000001;

typedef struct bian{
    int next;
    int w;
}bian;

vector<bian> adj[100001];
void map(int u,int v,int w){
    adj[u].push_back({v,w});
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        map(a,b,c);
    }  
    
    for(int i=1;i<=n;i++) mx[i]=err;
    mx[1]=0;
    
    for(int i=1;i<n;i++){
        if(mx[i]==err) continue;
        for(bian v:adj[i]){
            if(v.w+mx[i]>mx[v.next]) mx[v.next]=v.w+mx[i];
        }
    }
    if(mx[n]==err) printf("-1\n");
    else printf("%d\n",mx[n]);
    
    printf("\n");
    return 0;
}
