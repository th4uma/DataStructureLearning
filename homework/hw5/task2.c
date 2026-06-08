#include <stdio.h>
#include <stdlib.h>

int x,y,a[10001],cnt;
int head=-1,tail=-1;

void push (int n){
    if(cnt==10000){
        printf("full,failed to ");
        return;
    }
    tail=(tail+1)%10000;
    a[tail]=n;
    cnt++;
}

void pop (){
    if(cnt==0){
        printf("empty,failed to ");
        return;
    }
    head=(head+1)%10000;
    cnt--;
}

void show(){
    if(cnt==0){
        printf("empty");
        return;
    }
    for(int i=1;i<=cnt;i++){
        printf("%d ",a[(head+i)%10000]);
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