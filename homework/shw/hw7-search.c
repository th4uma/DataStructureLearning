#include <stdio.h>
#include <stdlib.h>

int n, m, a, b, c, d;
long long val;
typedef struct ip
{
    long long val;
    char place[1000];
} ip;
ip data[100000];

int qcmp(const void *x, const void *y)
{
    ip *h = (ip *)x;
    ip *t = (ip *)y;
    if (h->val < t->val)
        return -1;
    if (h->val > t->val)
        return 1;
    return 0;
}

void search2(int head,int tail,long long val,ip data[100000])
{
    if(head>=tail){
        if(tail==n){
            printf("%s\n",data[tail].place);
        }else printf("未找到\n");
        return;
    }
    int x=(head+tail)/2;
    if(data[x].val<=val&&data[x+1].val>val){
        printf("%s\n",data[x].place);
        return;
    }else if(data[x].val<val&&data[x+1].val<=val){
        search2(x+1,tail,val,data);
    }else if(data[x].val>val){
        search2(head,x,val,data);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d.%d.%d.%d", &a, &b, &c, &d);
        data[i].val = a * 256LL * 256 * 256 + b * 256LL * 256 + c * 256LL + d;
        scanf("%s", data[i].place);
    }

    qsort(data+1, n, sizeof(data[0]), qcmp);

    for (int i = 1; i <= m; i++)
    {
        scanf("%d.%d.%d.%d", &a, &b, &c, &d);
        val=a * 256LL * 256 * 256 + b * 256LL * 256 + c * 256LL + d;
        printf("IP地址 %d.%d.%d.%d 对应省市：",a,b,c,d);
        search2(1,n,val,data);
    }
    return 0;
}
