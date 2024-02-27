#include<stdio.h>
#include <time.h> 
#include <stdlib.h>

int board[4][4];

int get_null_count() {
    int n = 0;
    int i;
    for (i = 0; i < 4; ++i) {
        int j;
        for (j = 0; j < 4; ++j) {
            board[i][j] == 0 ? ++n : 1;
        }
    }
    return n;
}

void add_rand_num() {
    srand((unsigned int) time(0));//srand需要的是unsigned int这个类型的，所以对时间进行强制类型转换 
    int n = rand() % get_null_count(); /* 确定在何处空位置生成随机数 */
    int i;
    for (i = 0; i < 4; ++i) {
        int j;
        for (j = 0; j < 4; ++j) {
            /* 定位待生成的位置 */
            if (board[i][j] == 0 && n-- == 0) {
                board[i][j] = (rand() % 10 ? 2 : 4); /* 生成数字2或4，生成概率为9:1 */
                return;
            }
        }
    }
}

int main(){
	printf("\n\n\n\n");
    printf("               --------------------------------------------------");

    /* 绘制方格和数字 */
    printf("\n\n                             ┌────┬────┬────┬────┐\n");
    int i;
    for (i = 0; i < 4; ++i) {
        printf("                             │");
        int j;
        for (j = 0; j < 4; j++) {
            if (board[i][j] != 0) {
                if (board[i][j] < 10) {
                    printf("  %d │", board[i][j]);
                } else if (board[i][j] < 100) {
                    printf(" %d │", board[i][j]);
                } else if (board[i][j] < 1000) {
                    printf(" %d│", board[i][j]);
                } else {
                    printf("%4d│", board[i][j]);
                } 
            } else printf("    │");
        }
        if (i < 3) {
            printf("\n                             ├────┼────┼────┼────┤\n");
        } else {
            printf("\n                             └────┴────┴────┴────┘\n");
        }
    }
    printf("\n");
    printf("               --------------------------------------------------\n");
    printf("                  [W]:UP [S]:DOWN [A]:LEFT [D]:RIGHT [Q]:EXIT");

}
