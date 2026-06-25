#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *l,*r;
    char data;
}node;
char c[1000001];
int n=-1;

node *build(){
    n++;
    if(c[n]>='A'&&c[n]<='Z'||c[n]>='a'&&c[n]<='z'){
        node *nw=(node*)malloc(sizeof(node));
        nw->data=c[n];
        nw->l=build();
        nw->r=build();
        return nw;
    }else if(c[n]=='#') return NULL;
    else return 0;
}

void zxbl(node *zx){
    if(zx==NULL) return;
    if(zx->l!=NULL){
        zxbl(zx->l);
    }
    printf("%c ",zx->data);
    if(zx->r!=NULL){
        zxbl(zx->r);
    }
}
void qxbl(node *x){
    if(x==NULL) return;
    printf("%c ",x->data);
    if(x->l!=NULL){
        qxbl(x->l);
    }
    if(x->r!=NULL){
        qxbl(x->r);
    }
}
void hxbl(node *x){
    if(x==NULL) return;
    if(x->l!=NULL){
        hxbl(x->l);
    }
    if(x->r!=NULL){
        hxbl(x->r);
    }
    printf("%c ",x->data);
}
int main(){
    scanf("%s",c);
    node *gen=build();
    printf("前序遍历：");
    qxbl(gen);
    printf("\n");
    printf("中序遍历：");
    zxbl(gen);
    printf("\n");
    printf("后序遍历：");
    hxbl(gen);
    printf("\n");
}