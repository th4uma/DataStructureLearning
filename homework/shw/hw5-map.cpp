#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// biaozhu是标注节点是否被访问过
int n, m, a, b, biaozhu[1000001];
vector<int> ljjz[100001];
vector<int> ljb[100001];

// 建立图
void map(int u, int v, vector<int> mp[])
{
    mp[u].push_back(v);
}

void dfs(int sy, vector<int> mp[])
{
    if (sy == 0)
        return;
    printf("%d ", sy);
    for (int v : mp[sy])
    {
        if (biaozhu[v] == 1)
            continue;
        biaozhu[v] = 1;
        dfs(v, mp);
    }
}

void bfs(int sy, vector<int> mp[])
{
    queue<int> q;
    q.push(sy);
    biaozhu[sy] = 1;
    while (!q.empty())
    {
        int u = q.front();
        printf("%d ", u);
        q.pop();
        for (int v : mp[u])
        {
            if (biaozhu[v] == 1)
                continue;
            biaozhu[v] = 1;
            q.push(v);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    // 邻接表建图
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a, &b);
        map(a, b, ljb);
    }
    // 邻接矩阵建图
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a);
            if (a == 1)
                map(i, j + 1, ljjz);
        }
    }
    scanf("%d%d", &a, &b);
    for (int i = 0; i <= n; i++)
        biaozhu[i] = 0;
    biaozhu[a] = 1;
    dfs(a, ljjz);
    printf("\n");
    for (int i = 0; i <= n; i++)
        biaozhu[i] = 0;
    bfs(b, ljb);
    printf("\n");
    return 0;
}
