#include <stdio.h>
#include <stdlib.h>

int n, x,d;
char y;
char c[10000];
int bcbm,dcbm,mx;

typedef struct huff
{
    struct huff *l, *r;
    int data;
    char c;
} huff;

typedef struct node
{
    struct node *next;
    int data;
    huff *t;
} node;

void cr(node *head,huff *t)
{
    node *nw = (node *)malloc(sizeof(node));
    nw->t = t;
    nw->data=t->data;
    node *p = head;
    while (p->next != NULL && p->next->data < nw->data)
    {
        p = p->next;
    }
    nw->next = p->next;
    p->next = nw;
}

void huffmantree(node *head){
    node *a=head->next;
    node *b=head->next->next;
    huff *f=(huff *)malloc(sizeof(huff));
    f->l=a->t;
    f->r=b->t;
    f->data=a->data+b->data;
    head->next=b->next;
    free(a);
    free(b);
    cr(head,f);
}

void dfs(huff *f,char c[10000],int d){
    if(f==NULL) return;
    if(f->l==NULL&&f->r==NULL){
        printf("\n%c:",f->c);
        for(int i=0;i<d;i++){
            printf("%c",c[i]);
        }
        return;
    }
    if(f->l!=NULL&&f->r!=NULL){
        bcbm+=f->data;
    }
    if(f->l!=NULL){
        c[d]='0';
        dfs(f->l,c,d+1);
    }
    if(f->r!=NULL){
        c[d]='1';
        dfs(f->r,c,d+1);
    }
}
int main()
{
    node *head = (node *)malloc(sizeof(node));
    head->next = NULL;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf(" %c%d", &y,& x);
        huff *nw = (huff *)malloc(sizeof(huff));
        nw->c=y;
        nw->data=x;
        nw->l = NULL;
        nw->r = NULL;
        cr(head, nw);
    }
    if(n==1){
        printf("0");
        return 0;
    }
    while(head->next != NULL && head->next->next != NULL){
        huffmantree(head);
    }
    dfs(head->next->t,c,d);

    int dc=1;
    while(dc<n){
        dc*=2;
        mx++;
    }

    dcbm=head->next->t->data*mx;
    printf("\n定长编码：%d\n",dcbm);
    printf("变长编码：%d\n",bcbm);
    printf("压缩比:%.2f\n", (double)dcbm / bcbm);
    return 0;
}