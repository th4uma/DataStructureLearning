#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct link{
        int data;
        struct link*next;
    }link;
int main()
{
    srand(time(NULL));
    link*head=(link*)malloc(sizeof(link));
    head->next=NULL;
    link* prev=head;

    for(int x=0;x<10;x++){
        link*nw=(link*)malloc(sizeof(link));
        nw->next=NULL;
        nw->data=rand()%10;
        prev->next=nw;
        prev=nw;
    }

    link*d=head;
    printf("add:");
    while(d->next!=NULL){
        printf("%d ",d->next->data);
        d=d->next;
    }
    printf("\n");
    
    for(int i=0;i<10;i++){
        int b=rand()%10;
        int c=rand()%10;
        link*j=head;
        while(j->next!=NULL){
            if(j->next->data==b){
                j->next->data=c;
                break;
            }
            else{
                j=j->next;
            }
        }
    }

    link*d2=head;
    printf("change:");
    while(d2->next!=NULL){
        printf("%d ",d2->next->data);
        d2=d2->next;
    }
    printf("\n");
    
    for(int k=0;k<10;k++){
        int a=rand()%10;
        link*i=head;
        while(i->next!=NULL){
            if(i->next->data==a){
                link*p=i->next;
                i->next=p->next;
                free(p);
                break;
            }
            else{
                i=i->next;
            }
        }
    }
    
    link*d3=head;
    printf("delete:");
    while(d3->next!=NULL){
        printf("%d ",d3->next->data);
        d3=d3->next;
    }
    printf("\n");
    return 0;
}