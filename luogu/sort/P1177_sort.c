#include <stdio.h>
#include <stdlib.h>

int n,m,x,cnt[100000];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        cnt[x]++;
    }
    for(int i=1;i<=m;i++){
        if(cnt[i]==0){
            i++;
        }else{
            printf("%d ",cnt[i]);
        }
    }
    printf("\n");
    return 0;
}
