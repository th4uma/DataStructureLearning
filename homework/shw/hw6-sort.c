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
        if (m<=n)
        {
            swap(m, n, a);
            m++;
            n--;
        }
    }
    // 递归
    qsortstu(a, head, n );
    qsortstu(a, m , tail);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s%d", list[i].name, &list[i].score);
    }
    qsortstu(list, 1, n);
    // r是排名s是当前最低分
    int r = 0, s = 10000000;
    for (int i = 1; i <= n; i++)
    {
        printf("%s ", list[i].name);
        printf("分数：%d ", list[i].score);
        // 遇到新的最低分便排名加一
        if (list[i].score < s)
            r++;
        s = list[i].score;
        list[i].rank = r;
        printf("排名：%d\n", list[i].rank);
    }
    return 0;
}
