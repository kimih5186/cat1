#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define ROOM_WIDTH 12
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)
#define CAT_NAME "�����"

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
    }


}

