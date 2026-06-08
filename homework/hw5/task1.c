#include <stdio.h>
#include <stdlib.h>

int x,y,a[10001],cnt;
int head=-1,tail=-1;

void push (int n){
    if(tail==10000){
        printf("full,failed to ");
        return;
    }
    tail++;
    a[tail]=n;
    cnt++;
}

void pop (){
    if(cnt==0){
        printf("empty,failed to ");
        return;
    }
    head++;
    cnt--;
}

void show(){
    if(cnt==0){
        printf("empty");
        return;
    }
    for(int i=head+1;i<=tail;i++){
        printf("%d ",a[i]);
    }
}

int main(){
    scanf("%d",&x);
    while(x!=22){
        if(x==1){
            scanf("%d",&y);
            push(y);
            printf("push %d\n",y);
        }else if(x==2){
            pop();
            printf("pop \n");
        }else if(x==3){
            show();
            printf("\n");
        }
        scanf("%d",&x);
    }
    return 0;
}