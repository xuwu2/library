//
// Created by ����XuWu on 2023/4/14.
//
#include <stdio.h>
#include <string.h>

int main() {
    int a;
    int choice;
    int usernum = 0;
    int found = 0;
    char newuser[100];
    char newpassword[100];
    char inputuser[100];
    char inputpassword[100];
    char user[usernum][100];
    char password[usernum][100];
    int borrowed_books[6] = {0};
    char books[6][100] = {"��", "��", "��", "��", "��","��"};
    for (choice = 0; choice != 48;) {
        printf("��ӭʹ��ͼ�����ϵͳ!\n");
        printf("ѡ����������:(�������ּ���:)\n");
        printf("1.ע��\n");
        printf("2.��¼\n");
        printf("3.����\n");
        printf("4.����\n");
        printf("0.�˳�����\n");
        a = getchar();
        getchar();
        choice = a;
        if (a <= '9' && a >= '0') {
//            scanf("%d", &choice);
            switch (choice) {
                case 49: //49��1��ASCII��
                    printf("�����������û���:");
                    scanf("%s", newuser);
                    printf("��������������:");
                    scanf("%s", newpassword);
                    printf("ע��ɹ�!\n");
                    strcpy(user[usernum], newuser);
                    strcpy(password[usernum], newpassword);
                    usernum++;
                    getchar();
                    break;
                case 50: //50��2��ASCII��
                    printf("�����������û���:");
                    scanf("%s", inputuser);
                    printf("��������������:");
                    scanf("%s", inputpassword);
                    for (int i = 0; i < usernum; i++) {
                        if (strcmp(user[i], inputuser) == 0 && strcmp(password[i], inputpassword) == 0) {
                            found = 1;
                            break;
                        }
                    }
                    if(found == 1) {
                        printf("��¼�ɹ�!\n");
                    } else {
                        printf("��¼ʧ��!\n");
                    }
                    getchar();
                    break;
                case 51: //51��3��ASCII��
                    printf("Book List:\n");
                    for (int i = 0; i < 6; i++) {
                        printf("%d. %s", i+1, books[i]);
                        if (borrowed_books[i]) {
                            printf(" (borrowed)");
                        }
                        printf("\n");
                    }
                    break;
                case 52: //52��4��ASCII��
                    break;
                case 48: //48��0��ASCII��
                    printf("��л����ʹ��!\n");
                    break;
                default: //�������
                    printf("�������!\n");
                    break;
            }
        } else {
            printf("�������!����������!\n");
        }
    }
    return 0;
}