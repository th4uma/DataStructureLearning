#include <stdio.h>
#include <stdlib.h>

int n;
typedef struct student
{
    int score, rank;
    char name[100];
} student;
student list[10000];
// 换位置函数
void swap(int m, int n, student a[10000])
{
    student t = a[m];
    a[m] = a[n];
    a[n] = t;
}
// 快速排序
void qsortstu(student a[10000], int head, int tail)
{
    if (head >= tail)
        return;
    int x = a[(head + tail) / 2].score;
    int m = head, n = tail;
    while (m <= n)
    {
        // head向右tail向左扫
        while (a[m].score > x && m < tail)
            m++;
        while (a[n].score < x && n > head)
            n--;
        if (m <= n)
        {
            swap(m, n, a);
            m++;
            n--;
        }
    }
    // 递归
    qsortstu(a, head, n);
    qsortstu(a, m, tail);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s%d", list[i].name, &list[i].score);
    }
    qsortstu(list, 1, n);

    for (int i = 1; i <= n; i++)
    {
        // 排名计算 
        if (i == 1)
            list[i].rank = 1;
        else if (list[i].score == list[i - 1].score)
            list[i].rank = list[i - 1].rank;
        else
            list[i].rank = i;

        printf("%s 分数：%d 排名：%d\n", list[i].name, list[i].score, list[i].rank);
    }
    return 0;
}
