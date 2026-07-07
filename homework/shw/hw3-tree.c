#include <stdio.h>
#include <stdlib.h>

int n, x;
// 存储树的节点
typedef struct node
{
    struct node *l, *r;
    int data;
} node;
// 在树中新增节点
node *add(node *sy, int x)
{
    if (sy == NULL)
    {
        node *nw = (node *)malloc(sizeof(node));
        nw->l = NULL;
        nw->r = NULL;
        nw->data = x;
        return nw;
    }
    else if (x < sy->data)
    {
        // 小于根节点的去左子节点
        sy->l = add(sy->l, x);
    }
    else
        sy->r = add(sy->r, x);
    return sy;
}

// 递减序列，也就是右中左遍历
void djxl(node *sy)
{
    if (sy == NULL)
        return;
    djxl(sy->r);
    printf("%d ", sy->data);
    djxl(sy->l);
}

int main()
{
    node *gen = NULL;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        gen = add(gen, x);
    }
    djxl(gen);
    printf("\n");
    return 0;
}