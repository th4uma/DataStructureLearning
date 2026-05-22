#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
        int a;
        int b;
        struct node*next;
    }node;

char c1[10001];
char c2[10001];

node*add_char_to_node(char cc[10001],node*nn){
    int i=0;
    while(cc[i]!='\0'){
        int x=1;
        if(cc[i]=='-'){
            x=-1;
            i++;
        }else if(cc[i]=='+'){
            x=1;
            i++;
        }
        char c[1000];
        int j=0;
        while(cc[i]!='+'&&cc[i]!='-'&&cc[i]!='\0'){
            c[j]=cc[i];
            j++;
            i++;
        }
        c[j]='\0';
        
        int k=0,a=0,b=0,r=0;
        while(c[k]!='x'&&c[k]!='\0'){
            a=a*10+(c[k]-'0');
            k++;
            r=1;
        }
        if(c[k]=='x'&&r==0) a=1;
        a*=x;
        if(c[k]=='x'){
            k++;
            while(c[k]!='\0'){
                b=b*10+(c[k]-'0');
                k++;
            }
        }

        node*new=(node*)malloc(sizeof(node));
        new->next=NULL;
        new->a=a;
        new->b=b;
        nn->next=new;
        nn=new;
    }
    return nn;
}

void freee(node*fr){
    node*head=fr;
    node*next;
    while(head!=NULL){
        next=head->next;
        free(head);
        head=next;
    }
}

int main()
{
    node*p=(node*)malloc(sizeof(node));
    p->next=NULL;
    node*pn=p;

    node*q=(node*)malloc(sizeof(node));
    q->next=NULL;
    node*qn=q;

    scanf("%10000s",c1);
    scanf("%10000s",c2);

    pn=add_char_to_node(c1,pn);
    qn=add_char_to_node(c2,qn);

    node*r=(node*)malloc(sizeof(node));
    r->next=NULL;
    node*rn=r;

    node*ps=p->next;
    node*qs=q->next;
    while(ps!=NULL&&qs!=NULL){
        if(ps->b==qs->b){
            int aa=ps->a+qs->a;
            if(aa!=0){
                node*new=(node*)malloc(sizeof(node));
                new->next=NULL;
                new->a=ps->a+qs->a;
                new->b=ps->b;
                rn->next=new;
                rn=new;
            }
            ps=ps->next;
            qs=qs->next;
        }else if(ps->b>qs->b){
            node*new=(node*)malloc(sizeof(node));
            new->next=NULL;
            new->a=ps->a;
            new->b=ps->b;
            rn->next=new;
            rn=new;

            ps=ps->next;
        }else if(ps->b<qs->b){
            node*new=(node*)malloc(sizeof(node));
            new->next=NULL;
            new->a=qs->a;
            new->b=qs->b;
            rn->next=new;
            rn=new;

            qs=qs->next;
        }
    }
    if(ps!=NULL) rn->next=ps;
    else if(qs!=NULL) rn->next=qs;

    node*print=r->next;
    while(print!=NULL){
        if(print->a>0&&print!=r->next) printf("+");
        if(print->b==0) printf("%d",print->a);
        else printf("%dx%d",print->a,print->b);
        print=print->next;
    }
    printf("\n");

    freee(p);
    freee(q);
    freee(r);

    return 0;
}   