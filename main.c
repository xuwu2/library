//
// Created by ����XuWu on 2023/4/14.
//
#include <stdio.h>
#include <string.h>

int main() {
    int a;
    int booknum = 9;
    int choicebooks;
    int choicebooks2;
    int borrownum = 0;
    int choice;
    int usernum = 0;
    int found = 0;
    int islogin = 0;
    char iscontinue;
    char newuser[100];
    char newpassword[100];
    char inputuser[100];
    char inputpassword[100];
    char user[usernum][100];
    char password[usernum][100];
    char borrowed_books[9][100];
    char borrowbookname[100];
    char bookname[100];
    char books[9][100] = {"��ѧ", "����", "Ӣ��", "��ѧ", "����", "����","����", "��ʷ", "����"};

//    char books8[8][100] = {"��ѧ", "����", "Ӣ��", "��ѧ", "����", "����","����", "��ʷ"};
//    char books7[7][100] = {"��ѧ", "����", "Ӣ��", "��ѧ", "����", "����","����"};
//    char books6[6][100] = {"��ѧ", "����", "Ӣ��", "��ѧ", "����", "����"};
//    char books5[5][100] = {"��ѧ", "����", "Ӣ��", "��ѧ", "����"};
//    char books4[4][100] = {"��ѧ", "����", "Ӣ��", "��ѧ"};
//    char books3[3][100] = {"��ѧ", "����", "Ӣ��"};
//    char books2[2][100] = {"��ѧ", "����"};
//    char books1[1][100] = {"��ѧ"};

    printf("��ӭʹ��ͼ�����ϵͳ!\n");
    for (choice = 0; choice != 48;) {
        printf("ѡ����������:(�������ּ���:)\n");
        printf("1.ע��\n");
        printf("2.��¼\n");
        printf("3.����\n");
        printf("4.����\n");
        if (islogin == 1) {
            printf("5.ע��\n");
        }
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
                    if (usernum == 0) {
                        printf("����ע��!\n");
                        break;
                    }
                    if (islogin == 1) {
                        printf("���Ѿ�������!\n");
                        break;
                    }
                    printf("�����������û���:");
                    scanf("%s", inputuser);
                    printf("��������������:");
                    scanf("%s", inputpassword);
                    for (int i = 0; i < usernum; i++) {
                        if (strcmp(inputuser, user[i]) == 0 && strcmp(inputpassword, password[i]) == 0) {
                            found = 1;
                            break;
                        }
                    }
                    if(found == 1) {
                        printf("��¼�ɹ�!\n");
                        islogin = 1;
                    } else {
                        printf("��¼ʧ��!\n");
                    }
                    getchar();
                    break;
                case 51: //51��3��ASCII��
                    if (islogin == 0) {
                        printf("�������ٳ���!\n");
                        break;
                    }
                    if (booknum == 0) {
                        printf("���������鼮!\n");
                        break;
                    }
                    printf("����Ŀǰ�������:\n");

                    for (int i = 0; i < booknum; i++) {
                        printf("%d. %s", i+1, books[i]);
                        printf("\n");
                    }

                    printf("��������Ҫ���ĵ��鼮���:");
                    scanf("%d", &choicebooks);
                    if (choicebooks > booknum || choicebooks < 1) {
                        printf("�������!\n");
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
                    strcpy(borrowed_books[borrownum], bookname);
                    borrownum++;
//                    strcpy(books8[8],books[8]);
                    printf("���ĳɹ�!\n");
                    booknum--;
                    for (int i = 0; i < booknum; i++) {
                        printf("%d. %s", i+1, books[i]);
                        printf("\n");
                    }
                    getchar();
                    break;
                case 52: //52��4��ASCII��
                    if (islogin == 0) {
                        printf("�������ٳ���!\n");
                        break;
                    }
                    if (borrownum == 0) {
                        printf("��û�н����κ��鼮!\n");
                        break;
                    }
                    printf("��Ŀǰ���ĵ��鼮��:\n");
                    for (int i = 0; i < borrownum; i++) {
                        printf("%d. %s", i+1, borrowed_books[i]);
                        printf("\n");
                    }
                    printf("��������Ҫ�黹���鼮���:");
                    scanf("%d", &choicebooks2);
                    if (choicebooks2 > borrownum || choicebooks2 < 1) {
                        printf("�������!\n");
                        break;
                    }
                    booknum++;
                    strcpy(borrowbookname, borrowed_books[choicebooks2-1]);
                    strcpy(books[booknum-1], borrowbookname);
                        for (int i = choicebooks2 - 1; i < 8; i++) {
                        strcpy(borrowed_books[i], borrowed_books[i + 1]);
                    }
//                    booknum++;
                    borrownum--;
                    printf("����ɹ�!\n");
                    printf("����Ŀǰ�������:\n");
                    for (int i = 0; i < booknum; i++) {
                        printf("%d. %s", i+1, books[i]);
                        printf("\n");
                    }
                    getchar();
                    break;
                case 53: //53��5��ASCII��
                    printf("ע���ɹ�!\n");
                    islogin = 0;
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
        printf("�Ƿ����?(y/n)\n");
        scanf("%c", &iscontinue);
        getchar();
        for (;iscontinue != 'Y' && iscontinue != 'N' && iscontinue != 'y' && iscontinue != 'n';) {
            printf("�������!������y��n!\n");
            scanf("%c", &iscontinue);
            getchar();
        }
        if (iscontinue == 'Y') {
            continue;
        } else if (iscontinue == 'N') {
            printf("��л����ʹ��!\n");
            break;
        } else if (iscontinue == 'y') {
            continue;
        } else if (iscontinue == 'n') {
            printf("��л����ʹ��!\n");
            break;
        } else {
            printf("�������!\n");
            break;
        }
    }
    return 0;
}