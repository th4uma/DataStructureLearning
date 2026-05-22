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
    link*prev=head;

    for(int x=0;x<10;x++){
        link*nw=(link*)malloc(sizeof(link));
        nw->next=NULL;
        nw->data=rand()%10;
        prev->next=nw;
        prev=nw;
    }

    link*p=head->next;
    printf("before:");
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");

    link*i=head->next;
    link*j=NULL;
    link*k=NULL;
    while (i!=NULL)
    {
        k=i->next;
        i->next=j;
        j=i;
        i=k;
    }
    head->next=j;

    link*p1=j;
    printf("after:");
    while(p1!=NULL){
        printf("%d ",p1->data);
        p1=p1->next;
    }
    printf("\n");
    
    return 0;
}   