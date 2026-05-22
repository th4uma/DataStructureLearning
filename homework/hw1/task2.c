#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
        char name[20];
        char number[20];
        struct student*next;
    }student;
int main()
{
    student*head=(student*)malloc(sizeof(student));
    head->next=NULL;
    student* prev=head;

    while(1){
        char search;
        scanf(" %c",&search);
        if(search=='a'){
            prev = head;
            while(prev->next != NULL) {
                prev = prev->next;
            }
            printf("输入姓名电话：");
            student*nw=(student*)malloc(sizeof(student));
            nw->next=NULL;
            scanf("%19s",nw->name);
            scanf("%19s",nw->number);
            prev->next=nw;
            prev=nw;
            printf("添加成功");
            printf("\n");
        }
        else if(search=='d'){
            printf("输入需要删除的姓名或电话：");
            char a[20];
            int found=0;
            scanf("%19s",a);
            student*i=head;
            while(i->next!=NULL){
                if(strcmp(i->next->name, a) == 0){
                    student*p=i->next;
                    i->next=p->next;
                    found=1;
                    free(p);
                    break;
                }
                else if(strcmp(i->next->number, a) == 0){
                    student*p=i->next;
                    i->next=p->next;
                    found=1;
                    free(p);
                    break;
                }
                else{
                    i=i->next;
                }
            }
            if(!found) printf("无此信息");
            else printf("删除成功");
            printf("\n");
        }
        else if(search=='c'){
            printf("输入需要更改和更改后的信息：");
            char b[20],c[20];
            int found=0;
            scanf("%19s %19s",b,c);
            student* j=head;
            while(j->next!=NULL){
                if(strcmp(j->next->name, b) == 0){
                    strcpy(j->next->name, c);
                    found=1;
                    break;
                }
                else if(strcmp(j->next->number, b) == 0){
                    strcpy(j->next->number, c);
                    found=1;
                    break;
                }
                else{
                    j=j->next;
                }
            }
            if(!found) printf("无此信息");
            else printf("更改成功");
            printf("\n");
        }
        else if(search=='f'){
            printf("输入查找的信息：");
            char d[20];
            int found=0;
            scanf("%19s",d);
            student*k=head;
            while(k->next!=NULL){
                if(strcmp(k->next->name, d) == 0){
                    printf("号码：%19s ",k->next->number);
                    found=1;
                    break;
                }
                else if(strcmp(k->next->number, d) == 0){
                    printf("姓名：%19s ",k->next->name);
                    found=1;
                    break;
                }
                else{
                    k=k->next;
                }
            }
            if(!found) printf("无此信息");
            printf("\n");
        }
        else if(search=='i'){
            student*l=head;
            printf("通讯录信息:\n");
            while(l->next!=NULL){
            printf("姓名：%19s ",l->next->name);
            printf("电话：%19s\n",l->next->number);
            l=l->next;
            }
            printf("\n");
        }
        else if(search=='q'){
            break;
        }
    }
    return 0;
}