#include <stdio.h>
#include <stdlib.h>

int m, n;

// 存储节点的结构体
typedef struct node
{
    struct node *next;
    int data;
} node;

// 插入排序函数
void cr(node *head, int a)
{
    node *nw = (node *)malloc(sizeof(node));
    nw->data = a;
    node *p = head;
    // 找到合适的位置
    while (p->next != NULL && p->next->data < nw->data)
    {
        p = p->next;
    }
    nw->next = p->next;
    p->next = nw;
}

int main()
{
    node *head = (node *)malloc(sizeof(node));
    head->next = NULL;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        cr(head, m);
    }
    node *ans = head->next;
    printf("有序链表：");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans->data);
        ans = ans->next;
    }
    printf("\n");
    return 0;
}