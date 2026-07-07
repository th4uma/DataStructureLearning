#include <stdio.h>
#include <stdlib.h>

int n,m,x,cnt[100000];

int main(){
    for(int i=1;i<=100000;i++){
        cnt[i]=0;
    }
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        cnt[x]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cnt[i];j++){
            printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}
