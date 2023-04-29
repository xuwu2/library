//
// Created by 虚无XuWu on 2023/4/14.
//
#include <stdio.h>
#include <string.h>

int main() {
    int a;
    int choicebooks;
    int choice;
    int usernum = 0;
    int found = 0;
    int islogin = 0;
    char newuser[100];
    char newpassword[100];
    char inputuser[100];
    char inputpassword[100];
    char user[usernum][100];
    char password[usernum][100];
    int borrowed_books[9];
    char bookname[100];
    char books[9][100] = {"数学", "语文", "英语", "化学", "物理", "生物","政治", "历史", "地理"};

    char books8[8][100] = {"数学", "语文", "英语", "化学", "物理", "生物","政治", "历史"};
    char books7[7][100] = {"数学", "语文", "英语", "化学", "物理", "生物","政治"};
    char books6[6][100] = {"数学", "语文", "英语", "化学", "物理", "生物"};
    char books5[5][100] = {"数学", "语文", "英语", "化学", "物理"};
    char books4[4][100] = {"数学", "语文", "英语", "化学"};
    char books3[3][100] = {"数学", "语文", "英语"};
    char books2[2][100] = {"数学", "语文"};
    char books1[1][100] = {"数学"};

    printf("欢迎使用图书管理系统!\n");
    for (choice = 0; choice != 48;) {
        printf("选择您的需求:(输入数字即可:)\n");
        printf("1.注册\n");
        printf("2.登录\n");
        printf("3.借书\n");
        printf("4.还书\n");
        if (islogin == 1) {
            printf("5.注销\n");
        }
        printf("0.退出程序\n");
        a = getchar();
        getchar();
        choice = a;
        if (a <= '9' && a >= '0') {
//            scanf("%d", &choice);
            switch (choice) {
                case 49: //49是1的ASCII码
                    printf("请输入您的用户名:");
                    scanf("%s", newuser);
                    printf("请输入您的密码:");
                    scanf("%s", newpassword);
                    printf("注册成功!\n");
                    strcpy(user[usernum], newuser);
                    strcpy(password[usernum], newpassword);
                    usernum++;
                    getchar();
                    break;
                case 50: //50是2的ASCII码
                    if (usernum == 0) {
                        printf("请先注册!\n");
                        break;
                    }
                    if (islogin == 1) {
                        printf("您已经登入了!\n");
                        break;
                    }
                    printf("请输入您的用户名:");
                    scanf("%s", inputuser);
                    printf("请输入您的密码:");
                    scanf("%s", inputpassword);
                    for (int i = 0; i < usernum; i++) {
                        if (strcmp(inputuser, user[i]) == 0 && strcmp(inputpassword, password[i]) == 0) {
                            found = 1;
                            break;
                        }
                    }
                    if(found == 1) {
                        printf("登录成功!\n");
                        islogin = 1;
                    } else {
                        printf("登录失败!\n");
                    }
                    getchar();
                    break;
                case 51: //51是3的ASCII码
                    if (islogin == 0) {
                        printf("请登入后再尝试!\n");
                        break;
                    }
                    printf("本馆目前库存如下:\n");
                    for (int i = 0; i < 9; i++) {
                        printf("%d. %s", i+1, books[i]);
                        printf("\n");
                    }
                    printf("请输入您要借阅的书籍编号:");
                    scanf("%d", &choicebooks);
                    if (choicebooks > 9 || choicebooks < 1) {
                        printf("输入错误!\n");
                        break;
                    }
//                    strcpy(bookname, books[choicebooks-1]);
//                    for (int i = bookname[0]; i < 9; i++) {
//                        strcpy(books[i-1], books[i]);
//                    }
                    strcpy(bookname, books[choicebooks-1]);
                    for (int i = choicebooks - 1; i < 8; i++) {
                        strcpy(books[i], books[i + 1]);
                    }
                    strcpy(books[8], "");
                    break;
                case 52: //52是4的ASCII码
                    break;
                case 53: //53是5的ASCII码
                    printf("注销成功!\n");
                    islogin = 0;
                    break;
                case 48: //48是0的ASCII码
                    printf("感谢您的使用!\n");
                    break;
                default: //其他情况
                    printf("输入错误!\n");
                    break;
            }
        } else {
            printf("输入错误!请输入数字!\n");
        }
    }
    return 0;
}