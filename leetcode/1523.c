#include <stdio.h>
#include <stdlib.h>

int low,high;
int main(){
    scanf("%d%d",&low,&high);
    printf("%d\n",(high+1)/2-low/2);
    return 0;
}
