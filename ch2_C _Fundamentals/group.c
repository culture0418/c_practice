// input i 表示有多少學生，範圍是 50-200；j 表示要分幾組，範圍是 2-25
// output 程式會印出每組的人數，以及沒有組別的人數，兩者以空白分隔。

#include <stdio.h>

int main()
{
    int student, group, group_num, student_no_group;
    scanf("%d %d", &student, &group);

    group_num = student / group;
    student_no_group = student % group;

    printf("%d %d", group_num, student_no_group);
}