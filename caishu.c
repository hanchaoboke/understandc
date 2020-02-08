/*
猜数游戏
根据用户选择的难度等级，随机生成一个数字，用户选择猜的次数，然后根据输入的内容与数字比较，显示结果是大了，小了，还是猜中了。

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<setjmp.h>

jmp_buf jump_buffer;
// 随机数
int xrand = 0;

// 函数原型声明
int randomNum(int a, int b);
int difficulty();
int times(int diff);
void guess(int xrand, int times, int diff);
void guessRight(int guessNum);
void guessWrong(int guessNum);
void guessContinue();

// 给定范围 计算随机数
int randomNum(int a, int b) {
    if (a > b) {
        int temp = 0;
        temp = a;
        a = b;
        b = temp;
    }
    int x = 0;
    srand(time(NULL));
    x = a + rand() % (b - a + 1);
    return x;
}

// 选择难度菜单 返回难度选项
int difficulty() {
    int diff = 0;
    puts("请选择难度等级");
    puts("1.0~9\n2.0~99\n3.0~999\n0.退出");
    printf("你的输入：");      scanf("%d", &diff);
    if (diff == 0)
        exit(0);
    return diff;
}

// 接收难度选项 设置随机数 输入猜的次数，0返回上一级
int times(int diff) {
    int times = 0;
    switch (diff) {
    case 1:
        xrand = randomNum(0, 9);
        puts("你当前选择的难度等级0~9\n请输入想要猜的次数，0返回上一级");
        printf("你的输入：");      scanf("%d", &times);
        if (times == 0)
            longjmp(jump_buffer, 1);
        break;
    case 2:
        xrand = randomNum(0, 99);
        puts("你当前选择的难度等级0~99\n请输入想要猜的次数，0返回上一级");
        printf("你的输入：");      scanf("%d", &times);
        if (times == 0)
            longjmp(jump_buffer, 1);
        break;
    case 3:
        xrand = randomNum(0, 999);
        puts("你当前选择的难度等级0~999\n请输入想要猜的次数，0返回上一级");
        printf("你的输入：");      scanf("%d", &times);
        if (times == 0)
            longjmp(jump_buffer, 1);
        break;
    }
    return times;
}


// 接收猜的次数 接收对应随机数 输入猜测数 判断对错
void guess(int xrand, int times, int diff) {
    int guessNum = 0;
    puts("现在开始猜数");
    int a = 0;
    switch (diff) {
    case 1:
        a = 9;  break;
    case 2:
        a = 99; break;
    case 3:
        a = 999;    break;

    }
    for (int i = times; i >= 0; i--) {
        if (i == 0)
            guessWrong(guessNum);

        printf("剩余次数%d，请输入数字（0~%d，-1返回难度选择）：", i, a);   scanf("%d", &guessNum);
        if (guessNum == -1)
            break;


        if (guessNum > xrand)
            printf("输入的是%d,没有猜中，猜大了\n", guessNum );
        if (guessNum < xrand && guessNum != -1)
            printf("输入的是%d,没有猜中，猜小了\n", guessNum );
        if (guessNum == xrand) {
            guessRight(guessNum);

        }


    }

}

// 最后一次猜对
void guessRight(int guessNum) {
    printf("输入的是%d,恭喜你，猜中了\n", guessNum );
    guessContinue();
}

// 最后一次猜错
void guessWrong(int guessNum) {
    printf("输入的是%d,没有猜中，请在再接再厉\n", guessNum );
    guessContinue();
}

// 是否继续
void guessContinue() {
    int a = 0;
    puts("是否继续？\n1.继续，0.退出\n");
    printf("你的输入：");        scanf("%d", &a);
    if (a == 1)
        longjmp(jump_buffer, 1);
    if (a == 0)
        exit(0);
}



int main() {
    int diffNum = 0;
    int timesNum = 0;
    if (setjmp(jump_buffer) == 0) {

        while (1) {
            diffNum = difficulty();
            timesNum = times(diffNum);
            guess(xrand, timesNum, diffNum);

        }
    } else {
        while (1) {
            diffNum = difficulty();
            timesNum = times(diffNum);
            guess(xrand, timesNum, diffNum);
        }
    }

    return 0;
}