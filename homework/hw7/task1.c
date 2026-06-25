#include <stdio.h>
#include <stdlib.h>

int m,n,c[100001],b[100001];

typedef struct bj{
    int compare,recnt;
}bj;
bj crpx,xzpx,mppx;

void cr(){
    typedef struct node{
        struct node *next;
        int data;
    }node;
    node *head=(node*)malloc(sizeof(node));
    head->next=NULL;
    node *p=head;
    for(int i=1;i<=n;i++){
        node *nw=(node*)malloc(sizeof(node));
        nw->data=c[i];
        node *p=head;
        crpx.compare++;
        while(p->next!=NULL&&p->next->data<nw->data){
            p=p->next;
            crpx.compare++;
        }
        nw->next=p->next;
        p->next=nw;
        crpx.recnt++;
    }
    node *ans=head->next;
    printf("插入排序结果：");
    for(int i=1;i<=n;i++){
        printf("%d ",ans->data);
        ans=ans->next;
    }
    printf("\n");
    printf("比较次数：");
    printf("%d",crpx.compare);
    printf("\n");
    printf("插入次数：");
    printf("%d",crpx.recnt);
    printf("\n");
}

void xz(){
    for(int i=1;i<=n;i++){
        int mn=100000000,sy=0;
        for(int j=i;j<=n;j++){
            xzpx.compare++;
            if(c[j]<mn){
                mn=c[j];
                sy=j;
            }
        }
        int sw=c[i];
        c[i]=c[sy];
        c[sy]=sw;
        xzpx.recnt++;
    }
    
    printf("选择排序结果：");
    for(int i=1;i<=n;i++){
        printf("%d ",c[i]);
    }
    printf("\n");
    printf("比较次数：");
    printf("%d",xzpx.compare);
    printf("\n");
    printf("交换次数：");
    printf("%d",xzpx.recnt);
    printf("\n");
}

void mp(){
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            mppx.compare++;
            if(b[j]>b[j+1]){
                int sw=b[j];
                b[j]=b[j+1];
                b[j+1]=sw;
                mppx.recnt++;
            }
        }
    }

    printf("冒泡排序结果：");
    for(int i=1;i<=n;i++){
        printf("%d ",c[i]);
    }
    printf("\n");
    printf("比较次数：");
    printf("%d",mppx.compare);
    printf("\n");
    printf("交换次数：");
    printf("%d",mppx.recnt);
    printf("\n");
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
        b[i]=c[i];
    }
    cr();
    xz();
    mp();
}