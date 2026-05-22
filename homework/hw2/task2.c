#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct link{
        int data;
        struct link*next;
        struct link*before;
    }link;
int main()
{
    srand(time(NULL));
    link*head=(link*)malloc(sizeof(link));
    head->next=NULL;
    head->before=NULL;
    link*nx=head;

    for(int x=0;x<10;x++){
        link*nw=(link*)malloc(sizeof(link));
        nw->next=NULL;
        nw->data=rand()%10;
        nw->before=nx;
        nx->next=nw;
        nx=nw;
    }

    link*p=head->next;
    printf("before:");
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");

    link*tail=head->next;
    while (tail->next!=NULL)
    {
        tail=tail->next;
    }
    head->before=tail;

    link*p1=tail;
    printf("after:");
    while(p1!=head){
        printf("%d ",p1->data);
        p1=p1->before;
    }
    printf("\n");

    head->before=NULL;
    
    return 0;
}   