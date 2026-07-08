#include <stdio.h>
#include <stdlib.h>

// n是剩余车位数量,m是事件数量
int n, m, mxtime = 0;
char ad;
int nm, t;

// 存储车辆的结构体
typedef struct car
{
    struct car *next;
    int num, time;
    // 在停车场内滞留时间
    int realtime;
} car;

// 新车辆到达
void arrive(car **p, car **q)
{
    car *carr = (car *)malloc(sizeof(car));
    carr->num = nm;
    carr->time = t;
    carr->next = NULL;
    if (n <= 0)
    {
        printf("车位已满\n");
        (*q)->next = carr;
        (*q) = carr;
        printf("车牌号：%d 入道时间：%d\n", carr->num, carr->time);
    }
    else
    {
        n--;
        (*p)->next = carr;
        (*p) = carr;
        printf("车牌号：%d 入场时间：%d\n", carr->num, carr->time);
        printf("车位剩余：%d\n", n);
        carr->realtime = t;
    }
}

// 车辆离开停车场
void leavepark(car *pre, car *ans, car *headbd, car **p, car **q)
{
    pre->next = ans->next;
    if (ans == (*p))
    {
        (*p) = pre;
    }
    n++;
    printf("车牌号：%d 出场时间：%d\n", ans->num, t);
    printf("停车时间：%d\n", t - ans->realtime);
    printf("停车费用：%d\n", (t - ans->realtime) * 5);
    printf("车位剩余：%d\n", n);
    free(ans);
    if (headbd->next != NULL)
    {
        car *tmp = headbd->next;
        headbd->next = tmp->next;
        tmp->realtime = t;
        (*p)->next = tmp;
        (*p) = tmp;
        (*p)->next = NULL;
        n--;
        if (tmp == (*q))
        {
            (*q) = headbd;
        }
        printf("车牌号：%d 入场时间：%d\n", tmp->num, tmp->realtime);
        printf("车位剩余：%d\n", n);
    }
}

// 车辆离开便道
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
    // 停车场链表头
    car *head = (car *)malloc(sizeof(car));
    car *p = head;
    head->next = NULL;

    // 便道链表头
    car *headbd = (car *)malloc(sizeof(car));
    car *q = headbd;
    headbd->next = NULL;

    scanf("%d%d", &n,&m);
    for (int i = 1; i <= m; i++)
    {
        scanf(" %c", &ad);
        scanf("%d%d", &nm, &t);
        // 检查时间是否有序
        if (t < mxtime)
        {
            printf("时间有误\n");
            return 0;
        }
        else
            mxtime = t;
        if (ad == 'A')
        {
            arrive(&p, &q);
        }
        else if (ad == 'D')
        {
            // 查找车辆
            car *ans = head->next;
            // 前一个节点
            car *pre = head;
            while (ans != NULL && ans->num != nm)
            {
                ans = ans->next;
                pre = pre->next;
            }
            if (ans == NULL)
            {
                // 停车场没找到目标
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