/*
多人猜拳游戏
用户输入多少人参与猜拳（2~5人）
计算机控制除1个玩家以外的其他人出拳
每次出拳比较后，输的人被淘汰，剩余玩家继续出拳直到一人胜出。
每次比较 后，输出每个玩家（编号）的出拳和胜负情况
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<setjmp.h>
#include<string.h>

jmp_buf jump_buffer;
// 数组用于接收猜拳结果 fingerResult[0]存储玩家输入的结果
int fingerRes[5];

// 猜拳失败人数
int fingerFaol = 0;

// 玩家输赢标识，如果玩家赢了置0，输了置1
int a = 0;

// 函数原型声明
int randomNum(int a,int b);
void fingerGuessing(int player);
void twoFinger();
void threeFinger(int player);
void fingerResult();


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

// 猜拳 接收游戏人数
void fingerGuessing(int playerNum) {
    int player = playerNum;
	if (player == 1) {
        fingerResult();
    }
    printf("当前剩余人数%d\n", player);
    int playerOne = 0;
    if (a == 0) {
        printf("请输入，0-剪刀，1-石头，2-布： ");	scanf("%d", &playerOne);
        fingerRes[0] = playerOne;
    }
    if (player == 2) {
        twoFinger();
    }
    if (player > 2) {
        threeFinger(player);
    }
    
}

// 两人猜拳
void twoFinger() {
    int x = randomNum(0, 2);
    sleep(1);
    if (fingerRes[0] == x) {
        printf("你与电脑1平局");
        fingerGuessing(2);
    }
    if (fingerRes[0] > x) {
        char str[10] = {0};
        if (fingerRes[0] == 0)
            strcpy(str, "剪刀");
        if (fingerRes[0] == 1)
            strcpy(str, "石头");
        if (fingerRes[0] == 2)
            strcpy(str, "布");
        printf("你出了 %s 胜利，玩家胜利", str);

        fingerResult();
    }
    if (fingerRes[0] < x) {
        char str[10] = {0};
        if (x == 0)
            strcpy(str, "剪刀");
        if (x == 1)
            strcpy(str, "石头");
        if (x == 2)
            strcpy(str, "布");
        printf("电脑1出了 %s 胜利，电脑1胜利", str);
        fingerResult();
    }
}

// 三人以上猜拳
void threeFinger(int player) {
    switch(player){
        case 3:     break;
        case 4:     break;
        case 5:     break;
    }


}
// 猜拳结束
void fingerResult() {
    int r = 0;
    printf("再来一次吗？ 0退出，1继续， 选择 ");		scanf("%d", &r);
    if (r == 0)
        exit(0);
    if (r == 1)
        longjmp(jump_buffer, 1);

}


int main() {
    int player = 0;
    if (setjmp(jump_buffer) == 0) {

        printf("猜拳游戏开始：请输入参与猜拳的人数(2~5)");	scanf("%d", &player);

        for (int i = player; i > 0; i - fingerFaol) {
            fingerGuessing(i);
        }
    } else {

        printf("猜拳游戏开始：请输入参与猜拳的人数(2~5)");	scanf("%d", &player);

        for (int i = player; i > 0; i - fingerFaol) {
            fingerGuessing(i);
        }
    }


    return 0;
}