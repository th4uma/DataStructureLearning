#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,a,b,aaa[1000001],maxx[100001],dp[100001];

queue<int> q;   

typedef struct node {
    int rd,cd;
}node;

node rr[500001];

vector<int> adj[100001];

void map(int u,int v){
    adj[u].push_back(v);
    rr[u].cd++;
    rr[v].rd++;
}

void bfs(){
    for(int i=1;i<=n;i++){
        if(rr[i].rd==0){
            dp[i]=1;
            q.push(i);
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

    
    printf("\n");
    return 0;
}
