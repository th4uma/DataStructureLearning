#include <stdio.h>
#include <stdlib.h>

int m,n,z[1000001],f[1000001],a,head,tail,ans;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(a>=0) z[a]=1;
        else f[-a]=1;
        head=tail=-a;
        int b=0;
        if(a<=0){
            while(z[head]==0&&z[tail]==0){
                head++;
                tail--;
                if(tail<0){
                    b=1;
                    tail=1;
                    break;
                }
            }
            if(b==1){
                while(z[head]==0&&f[tail]==0){
                head++;
                tail++;
                }
            }
            if(head-a<0) ans-=head-a;
            else ans+=head-a;
        }else {
            while(f[head]==0&&f[tail]==0){
                head++;
                tail--;
                if(tail<0){
                    b=1;
                    break;
                }
            }
            if(b=1){
                while(f[head]==0&&z[tail]==0){
                head++;
                tail++;
                }
            }
            if(-head-a<0) ans-=-head-a;
            else ans+=-head-a;
        }
        printf("%d\n",ans);
    }
    printf("%d\n",ans);
    return 0;
}
