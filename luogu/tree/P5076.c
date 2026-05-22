#include <stdio.h>
#include <stdlib.h>

int q,op,ct,gen,x,ansq,ansh,anspm,qq,hh;
typedef struct node {
    int l,r,cnt,data,size;
}node;
node m[1000001];

int add(int sy,int x){
    if(sy==0){
        ct++;
        m[ct].data=x;
        m[ct].size=m[ct].cnt=1;
        return ct; 
    }
    if(x==m[sy].data){
        m[sy].cnt++;
    }else if(x<m[sy].data){
        m[sy].l=add(m[sy].l,x);
    }else m[sy].r=add(m[sy].r,x);
    m[sy].size=m[m[sy].l].size+m[m[sy].r].size+m[sy].cnt;
    return sy;
}

int qx(int sy,int x){
    int ans=-2147483647;
    while(sy!=0){
        if(m[sy].data<x){
            ans=m[sy].data;
            sy=m[sy].r;
        }else sy=m[sy].l;
    }
    return ans;
}
int hx(int sy,int x){
    int ans=2147483647;
    while(sy!=0){
        if(m[sy].data>x){
            ans=m[sy].data;
            sy=m[sy].l;
        }else sy=m[sy].r;
    }
    return ans;
}

int xpm(int sy,int x){
    if(sy==0) return 1;
    if(x==m[sy].data) return m[m[sy].l].size+1;
    if(x<m[sy].data){
        return xpm(m[sy].l,x);
    }else{
        return xpm(m[sy].r,x)+m[m[sy].l].size+m[sy].cnt;
    }
}

int pmx(int sy,int x){
    if(sy==0) return 0;
    if(x<=m[m[sy].l].size) return pmx(m[sy].l,x);
    else if(x<=m[m[sy].l].size+m[sy].cnt) return m[sy].data;
    else return pmx(m[sy].r,x-m[m[sy].l].size-m[sy].cnt);
}

int main(){
    scanf("%d",&q);
    for(int i=0;i<=q;i++){
        m[i].l=m[i].r=m[i].cnt=0;
        m[i].data=2147483647;
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&op,&x);
        if(op==1){
            anspm=xpm(gen,x);
            printf("%d\n",anspm);
        }else if(op==2){
            anspm=pmx(gen,x);
            printf("%d\n",anspm);
        }else if(op==3){
            ansq=qx(gen,x);
            printf("%d\n",ansq);
        }else if(op==4){
            ansh=hx(gen,x);
            printf("%d\n",ansh);
        }else if(op==5){
            gen=add(gen,x);
        }
    }
    return 0;
}