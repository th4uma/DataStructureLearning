#include <stdio.h>
#include <stdlib.h>

int n;
typedef struct student{
    int score,rank;
    char name[100];
}student;
student list[10000];

void swap(int m,int n,student a[10000]){
    student t=a[m];
    a[m]=a[n];
    a[n]=t;
}

void qsortstu(student a[10000],int head,int tail){
    if(head>=tail) return;
    int x=a[(head+tail)/2].score;
    int m=head,n=tail;
    while(m<=n){
        while(a[m].score>x&&m<tail) m++;
        while(a[n].score<x&&n>head) n--;
        if(a[m].score<=x&&a[n].score>=x) {
            swap(m,n,a);
            m++;
            n--;
        }      
    }
    qsortstu(a,head,m-1);
    qsortstu(a,m+1,tail);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s%d",list[i].name,&list[i].score);
    }
    qsortstu(list,1,n);
    int r=0,s=10000000;
    for(int i=1;i<=n;i++){
        printf("%s ",list[i].name);
        printf("分数：%d ",list[i].score);
        if(list[i].score<s) r++;
        s=list[i].score;
        list[i].rank=r;
        printf("排名：%d\n",list[i].rank);
    }
    return 0;
}
