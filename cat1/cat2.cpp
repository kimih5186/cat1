#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define ROOM_WIDTH 12
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)
#define CAT_NAME "�����"

int posScratcher = -1;
int posTower = -1;

void drawRoom(int catPos, int prevPos, int hasScratcher, int hasTower) {
    printf("###############\n#");
    for (int i = 0; i < ROOM_WIDTH; i++) {
        if (i == HME_POS) printf("H");
        else if (i == BWL_POS) printf("B");
        else if (hasTower && i == posTower) printf("T");
        else if (hasScratcher && i == posScratcher) printf("S");
        else printf(" ");
    }
    printf("#\n#");
    for (int i = 0; i < ROOM_WIDTH; i++) {
        if (i == catPos) printf("C");
        else if (i == prevPos && catPos != prevPos) printf(".");
        else printf(" ");
    }
    printf("#\n###############\n\n");
}

int main(void) {
    srand((unsigned int)time(NULL));


    printf("**** �߿��̿� ���� ****\n\n");
    printf("@@@ ���⿡ ASCII art �׸��� @@@\n\n");
    printf("        /��_/��\n");
    printf(" /��   / o  o ��  \n");
    printf("//���� ��~(*)~/ \n");
    printf("   ��/    ^ /\n");
    printf("     |  ��|| ||\n");
    printf("     ��  '|| ||\n");
    printf("       ��)()-())\n");

    printf("����� �̸��� '%s'�Դϴ�.\n\n", CAT_NAME);

    Sleep(3000);
    system("cls");
    

    int intimacy = 2;
    int mood = 3;
    int cp = 0;
    int soupCount = 0;
    int hasToyMouse = 0, hasLaser = 0, hasScratcher = 0, hasTower = 0;
    int catPos = HME_POS;
    int prevPos = catPos;
    int turn = 0;

    while (1) {
        turn++;
        int roll;
        int beforeMood = mood;
        int beforeIntimacy = intimacy;

        // ����â
        printf("==================== ������� ====================\n");
        printf("������� ���� ����: %d��\n", soupCount);
        printf("CP: %d ����Ʈ\n", cp);
        printf("�˶��� ���(0~3): %d\n", mood);
        switch (mood) {
        case 0: printf(" ����� �ſ� ���޴ϴ�.\n"); break;
        case 1: printf(" �ɽ����մϴ�.\n"); break;
        case 2: printf(" �Ļ��� �����ϴ�.\n"); break;
        case 3: printf(" ������ �θ��ϴ�.\n"); break;
        }
        printf("������� ����(0~4): %d\n", intimacy);
        switch (intimacy) {
        case 0: printf(" �翡 ���� ������ �Ⱦ��մϴ�.\n"); break;
        case 1: printf(" �������Ǳ� ����Դϴ�.\n"); break;
        case 2: printf(" �׷����� �� ���� �����Դϴ�.\n"); break;
        case 3: printf(" �Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n"); break;
        case 4: printf(" ���� �������Դϴ�.\n"); break;
        }
        printf("============================================\n\n");
        Sleep(3000);
        system("cls");
		
        //�� �׸���
        drawRoom(catPos, prevPos, hasScratcher, hasTower);
        Sleep(3000);
        system("cls");


        //��� ������
        printf("6~2: �ֻ��� ���� 4�����̸� �׳� ����� �������ϴ�.\n");

        int moodDice = rand() % 6 + 1;
        
        printf("�ֻ����� �����ϴ�. �Ǹ���...\n %d��(��) ���Խ��ϴ�!\n", moodDice);
        if (moodDice <= (6 - intimacy)) {
            if (mood > 0) mood--;
            printf("�ƹ� ���� ���� ����� �������ϴ�. ����̴ϱ�?\n�˶��� ����� �������ϴ�.\n");
        }
        else {
            printf("�˶��� ����� �״���Դϴ�.\n");
        }
        Sleep(3000);
        system("cls");




