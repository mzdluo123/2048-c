#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int panel[4][4];
int score = 0;

/*
   a[0]1 2 3
i[0] 0 0 0 0
i[1] 0 0 0 0
i[2] 0 0 0 0
i[3] 0 0 0 0

防止搞混
*/

void init()
{
    srand(time(NULL)); //随机数种子
    for (int i = 0; i < 4; i++)
    {
        for (int a = 0; a < 4; a++)
        {
            panel[i][a] = 0;
        }
    }
}

int canMoveUp()
{
    for (int i = 0; i < 4; i++)
    {
        for (int a = 0; a < 4; a++)
        {
            if (i == 0 || panel[i][a] == 0) //第一行或者是0的位置
            {
                continue;
            }
            if (panel[i - 1][a] == 0 || panel[i - 1][a] == panel[i][a]) //上方有空或者是可以组合
            {

                return 1;
            }
        }
    }
    return 0;
}

void moveUp()
{
    while (canMoveUp()) //一步一步移动，移动到不能动为止
    {
        for (int i = 0; i < 4; i++)
        {
            for (int a = 0; a < 4; a++)
            {
                if (i == 0 || panel[i][a] == 0)
                {
                    continue;
                }
                if (panel[i - 1][a] == 0) //上方有空
                {
                    panel[i - 1][a] = panel[i][a];
                    panel[i][a] = 0;
                    continue;
                }
                if (panel[i - 1][a] == panel[i][a]) //可以组合
                {
                    score += panel[i][a] * 2;
                    panel[i - 1][a] = panel[i][a] * 2;
                    panel[i][a] = 0;
                }
            }
        }
    }
}

int canMoveDown()
{
    for (int i = 0; i < 4; i++)
    {
        for (int a = 0; a < 4; a++)
        {
            if (i == 3 || panel[i][a] == 0) //第一行或者是0的位置
            {
                continue;
            }
            if (panel[i + 1][a] == 0 || panel[i + 1][a] == panel[i][a]) //上方有空或者是可以组合
            {

                return 1;
            }
        }
    }
    return 0;
}

int moveDown()
{
    while (canMoveDown())
    {
        for (int i = 0; i < 4; i++)
        {
            for (int a = 0; a < 4; a++)
            {
                if (i == 3 || panel[i][a] == 0)
                {
                    continue;
                }
                if (panel[i + 1][a] == 0)
                {
                    panel[i + 1][a] = panel[i][a];
                    panel[i][a] = 0;
                    continue;
                }
                if (panel[i + 1][a] == panel[i][a])
                {
                    score += panel[i][a] * 2;
                    panel[i + 1][a] = panel[i][a] * 2;
                    panel[i][a] = 0;
                }
            }
        }
    }
}
int canMoveLeft()
{
    for (int i = 0; i < 4; i++)
    {
        for (int a = 0; a < 4; a++)
        {
            if (a == 0 || panel[i][a] == 0)
            {
                continue;
            }
            if (panel[i][a - 1] == 0 || panel[i][a - 1] == panel[i][a])
            {
                return 1;
            }
        }
    }
    return 0;
}
void moveLeft()
{

    while (canMoveLeft()) //一步一步移动，移动到不能动为止
    {
        for (int i = 0; i < 4; i++)
        {
            for (int a = 0; a < 4; a++)
            {
                if (a == 0 || panel[i][a] == 0)
                {
                    continue;
                }
                if (panel[i][a - 1] == 0)
                {
                    panel[i][a - 1] = panel[i][a];
                    panel[i][a] = 0;
                    continue;
                }
                if (panel[i][a - 1] == panel[i][a]) //可以组合
                {
                    score += panel[i][a] * 2;
                    panel[i][a - 1] = panel[i][a] * 2;
                    panel[i][a] = 0;
                }
            }
        }
    }
}

int canMoveRight()
{
    for (int i = 0; i < 4; i++)
    {
        for (int a = 0; a < 4; a++)
        {
            if (a == 3 || panel[i][a] == 0)
            {
                continue;
            }
            if (panel[i][a + 1] == 0 || panel[i][a + 1] == panel[i][a])
            {

                return 1;
            }
        }
    }
    return 0;
}
void moveRight()
{

    while (canMoveRight()) //一步一步移动，移动到不能动为止
    {
        for (int i = 0; i < 4; i++)
        {
            for (int a = 0; a < 4; a++)
            {
                if (a == 3 || panel[i][a] == 0)
                {
                    continue;
                }
                if (panel[i][a + 1] == 0)
                {
                    panel[i][a + 1] = panel[i][a];
                    panel[i][a] = 0;
                    continue;
                }
                if (panel[i][a + 1] == panel[i][a]) //可以组合
                {
                    score += panel[i][a] * 2;
                    panel[i][a + 1] = panel[i][a] * 2;
                    panel[i][a] = 0;
                }
            }
        }
    }
}

int spawnNewBlock()
{ //每一回合生成新的块
    int i, a;
    int haveBlank = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int a = 0; a < 4; a++)
        {
            if (panel[i][a] == 0)
            {
                haveBlank = 1;
            }
        }
    }
    if (haveBlank == 0)
    {
        return 0; //没有空位了，游戏结束
    }

    do
    {
        i = rand() % 4; //0-3随机数
        a = rand() % 4;
        // printf("%d %d \n",i,a);
    } while (panel[i][a] != 0); //找到一个空位
    panel[i][a] = 2;
    return 1;
}

void printNumber(int number)
{
    int color;
    switch (number)
    {

    case 2:
        color = 32;
        break;
    case 4:
        color = 33;
        break;
    case 8:
        color = 31;
        break;
    case 16:
        color = 34;
        break;
    case 32:
        color = 35;
        break;
    case 64:
        color = 36;
        break;
    case 128:
        color = 31;
        break;
    case 256:
        color = 32;
        break;
    case 512:
        color = 33;
        break;
    case 1024:
        color = 34;
        break;
    case 2048:
        color = 35;
        break;
    case 0:
    default:
        color = 37;
        break;
    }
    printf("\033[%d;1m %5d\033[0m", color, number);
}

void printPanel()
{
    system("cls"); // 清除屏幕
    printf("Press WASD to move\n");
    for (int i = 0; i < 4; i++)
    {
        for (int a = 0; a < 4; a++)
        {
            printNumber(panel[i][a]); // 格式输出
        }
        printf("\n\n");
    }
    printf("Score:%d \n", score);
}

void play()
{
    char action;
    int re = scanf("%c", &action);
    if (re == 0)
    {
        printf("Input error ,try again \n");
        play();
        return;
    }
    switch (action)
    {
    case 'w':
        moveUp();
        break;
    case 's':
        moveDown();
        break;
    case 'a':
        moveLeft();
        break;
    case 'd':
        moveRight();
        break;
    default:

        play();
        return;
    }
}

int main(int argc, char const *argv[])
{
    init();

    while (spawnNewBlock())
    {
        printPanel();
        play();
    }
    printf("Game Over!\n");
    printf("Your score: %d\n", score);
    system("pause");
    return 0;
}
