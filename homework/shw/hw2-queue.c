#include <stdio.h>
#include <stdlib.h>

int n, cnt = 3,mxtime=0;
char ad;
int nm, t;

typedef struct car
{
    struct car *next;
    int num, time;
    int realtime;
} car;

void arrive(car **p, car **q)
{
    car *carr = (car *)malloc(sizeof(car));
    carr->num = nm;
    carr->time = t;
    carr->next = NULL;
    if (cnt <= 0)
    {
        printf("车位已满\n");
        (*q)->next = carr;
        (*q) = carr;
        printf("车牌号：%d 入道时间：%d\n", carr->num, carr->time);
    }
    else
    {
        cnt--;
        (*p)->next = carr;
        (*p) = carr;
        printf("车牌号：%d 入场时间：%d\n", carr->num, carr->time);
        printf("车位剩余：%d\n", cnt);
        carr->realtime = t;
    }
}
void leavepark(car *pre, car *ans, car *headbd, car **p, car **q)
{
    pre->next = ans->next;
    if (ans == (*p))
    {
        (*p) = pre;
    }
    cnt++;
    printf("车牌号：%d 出场时间：%d\n", ans->num, t);
    printf("停车费用：%d\n", (t - ans->realtime) * 5);
    printf("车位剩余：%d\n", cnt);
    free(ans);
    if (headbd->next != NULL)
    {
        car *tmp = headbd->next;
        headbd->next = tmp->next;
        tmp->realtime = t;
        (*p)->next = tmp;
        (*p) = tmp;
        (*p)->next = NULL;
        cnt--;
        if (tmp == (*q))
        {
            (*q) = headbd;
        }
        printf("车牌号：%d 入场时间：%d\n", tmp->num, tmp->realtime);
        printf("车位剩余：%d\n", cnt);
    }
}
void leavebd(car *headbd, car **q)
{
    car *ans = headbd->next;
    car *pre = headbd;
    while (ans != NULL && ans->num != nm)
    {
        ans = ans->next;
        pre = pre->next;
    }
    if (ans == NULL)
        printf("车牌号：%d 不存在\n", nm);
    else
    {
        pre->next = ans->next;
        if (ans == (*q))
        {
            (*q) = pre;
        }
        printf("车牌号：%d 出场时间：%d\n由便道离开\n", nm, t);
        free(ans);
    }
}
int main()
{
    car *head = (car *)malloc(sizeof(car));
    car *headbd = (car *)malloc(sizeof(car));
    car *p = head;
    car *q = headbd;
    headbd->next = NULL;
    head->next = NULL;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf(" %c", &ad);
        scanf("%d%d", &nm, &t);
        if(t<mxtime){
            printf("时间有误\n");
            return 0;
        }else mxtime=t;
        if (ad == 'A')
        {
            arrive(&p, &q);
        }
        else if (ad == 'D')
        {
            car *ans = head->next;
            car *pre = head;
            while (ans != NULL && ans->num != nm)
            {
                ans = ans->next;
                pre = pre->next;
            }
            if (ans == NULL)
            {
                leavebd(headbd, &q);
            }
            else
            {
                leavepark(pre, ans, headbd, &p, &q);
            }
        }
    }
    return 0;
}