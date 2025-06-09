#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define ROOM_WIDTH 12
#define HME_POS 0
#define BWL_POS (ROOM_WIDTH - 1)
#define CAT_NAME "�˶���"

int posScratcher = -1;
int posTower = -1;

// ��ũ��ó�� ĹŸ���� ��ġ�� �������� ��ġ�ϴ� �Լ�
void setRandomFurniturePositions() {
    do {
        posScratcher = rand() % ROOM_WIDTH;
    } while (posScratcher == HME_POS || posScratcher == BWL_POS);

    do {
        posTower = rand() % ROOM_WIDTH;
    } while (posTower == HME_POS || posTower == BWL_POS || posTower == posScratcher);
}

// ���� �׸��� �Լ�
void drawRoom(int catPos, int prevPos, int hasScratcher, int hasTower) {
    // �� ��
    for (int i = 0; i < ROOM_WIDTH + 2; i++) printf("#");
    printf("\n");

    // ù ��° ��: �� + �� ���� + ��
    for (int i = 0; i < ROOM_WIDTH + 2; i++) {
        if (i == 0) {
            printf("#");  // ���� ��
        }
        else if (i == ROOM_WIDTH + 1) {
            printf("#");  // ������ ��
        }
        else {
            int pos = i - 1;  // �� ���� �ε��� (0~ROOM_WIDTH-1)
            if (pos == HME_POS)
                printf("H");
            else if (pos == BWL_POS)
                printf("B");
            else if (hasTower && pos == posTower)
                printf("T");
            else if (hasScratcher && pos == posScratcher)
                printf("S");
            else
                printf(" ");
        }
    }
    printf("\n");

    // �� ��° ��: �� + ����� ��ġ + ��
    for (int i = 0; i < ROOM_WIDTH + 2; i++) {
        if (i == 0) {
            printf("#");
        }
        else if (i == ROOM_WIDTH + 1) {
            printf("#");
        }
        else {
            int pos = i - 1;
            if (pos == catPos)
                printf("C");
            else if (pos == prevPos && catPos != prevPos)
                printf(".");
            else
                printf(" ");
        }
    }
    printf("\n");

    // �Ʒ� ��
    for (int i = 0; i < ROOM_WIDTH + 2; i++) printf("#");
    printf("\n\n");
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


        // �̵�
        prevPos = catPos;
        if (mood == 0 && catPos != HME_POS) {
            catPos--;
            printf("����� �ſ� ���� �˶��̴� ������ ���մϴ�.\n");
        }
        else if (mood == 1) {
            if (hasScratcher || hasTower) {
                catPos = (hasScratcher ? 2 : 3);
                printf("�˶��� �ɽ��ؼ� ��ũ��ó ������ �̵��մϴ�.\n");
            }
            else {
                printf("�� �Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
                if (mood > 0) mood--;
            }
        }
        else if (mood == 2) {
            printf("�˶��� ������� �Ļ��� ���� �ֽ��ϴ�.\n");
        }
        else if (mood == 3 && catPos != BWL_POS) {
            catPos++;
            printf("�˶��� ������ �θ��� ������ ���鷯 ���ϴ�.\n");
        }
        Sleep(5000);
        

        //�ൿ

        int prevMood = mood;

        if (catPos == HME_POS && prevPos == HME_POS && mood < 3) {
            mood++;
            printf("�˶��� ������ ���� ����� �������ϴ�: %d -> %d\n", prevMood, mood);
        }
        else if (hasScratcher && catPos == 2 && mood < 3) {
            mood++;
            printf("�˶��� ��ũ��ó�� �ܰ� ����� ���������ϴ�: %d -> %d\n", prevMood, mood);
        }
        else if (hasTower && catPos == 3) {
            int increase = (mood <= 1) ? 2 : 1;
            mood += increase;
            if (mood > 3) mood = 3;
            printf("�˶��� ĹŸ������ ��� ����� ���� ���������ϴ�: %d -> %d\n", prevMood, mood);
        }
        else if (catPos == BWL_POS) {
            char soups[3][20] = { "���ڼ���", "����̼���", "����ݸ�����" };
            int s = rand() % 3;
            printf("�˶��� %s�� ��������ϴ�!\n", soups[s]);
            soupCount++;
        }
        Sleep(5000);
        system("cls");


        //��ȣ�ۿ�
        printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n");
        printf(" 0. �ƹ��͵� ���� ����\n 1. �ܾ� �ֱ�\n");
        if (hasToyMouse && hasLaser) {
            printf(" 2. �峭�� ��� ��� �ֱ�\n 3. ������ �����ͷ� ��� �ֱ�\n");
        }
        else if (hasToyMouse) {
            printf(" 2. �峭�� ��� ��� �ֱ�\n");
        }
        else if (hasLaser) {
            printf(" 2. ������ �����ͷ� ��� �ֱ�\n");
        }
        printf(">> ");

        //��ȣ�ۿ� ó��
        int act;
        scanf_s("%d", &act);
        roll = rand() % 6 + 1;

        switch (act) {
        case 0:
            if (mood > 0) mood--;
            printf("�˶��� ����� ���������ϴ�: %d->%d\n", beforeMood, mood);
            if (roll <= 5 && intimacy > 0) {
                intimacy--;
                printf("������� ���谡 �������ϴ�.\n");
            }
      
        case 1:
            printf("�˶��� ����� �״���Դϴ�: %d\n", mood);
            if (roll >= 5 && intimacy < 4) {
                intimacy++;
                printf("������� ���谡 ���������ϴ�.\n");
            }
         

        case 2:
            if (hasToyMouse) {
                printf("�峭�� ��� �˶��� ��� �־����ϴ�.\n");
                if (mood < 3) mood++;
                printf("�˶��� ����� ���� ���������ϴ�: %d->%d\n", beforeMood, mood);
                if (roll >= 4 && intimacy < 4) {
                    intimacy++;
                    printf("������� ���谡 ���������ϴ�.\n");
                }
            }
            

        case 3:
            if (hasLaser) {
                printf("������ �����ͷ� �˶��� �ų��� ��� �־����ϴ�.\n");
                mood += 2;
                if (mood > 3) mood = 3;
                printf("�˶��� ����� �� ���������ϴ�: %d->%d\n", beforeMood, mood);
                if (roll >= 2 && intimacy < 4) {
                    intimacy++;
                    printf("������� ���谡 ���������ϴ�.\n");
                }
            }
            

            Sleep(5000);
            system("cls");

            // CP ����
            int cpGain = (mood > 1 ? (mood - 1) : 0) + intimacy;
            cp += cpGain;
            printf("�˶��� ���(0~3): %d\n", mood);
            printf("������� ģ�е�(0~4): %d\n", intimacy);
            printf("�˶��� ��а� ģ�е��� ���� CP�� %d ����Ʈ ����Ǿ����ϴ�.\n", cpGain);
            printf("���� CP: %d ����Ʈ\n", cp);

            Sleep(5000);
            system("cls");

            // ����
            int buy = -1;
            do {
                printf("�������� ������ �� �� �ֽ��ϴ�. ������ �����Ͻðڽ��ϱ�?\n");
                printf("0. �ƹ��͵� ���� �ʴ´�.\n");
                printf("1. �峭�� ��: 1 CP %s\n", hasToyMouse ? "(ǰ��)" : "");
                printf("2. ������ ������: 2 CP %s\n", hasLaser ? "(ǰ��)" : "");
                printf("3. ��ũ��ó: 4 CP %s\n", hasScratcher ? "(ǰ��)" : "");
                printf("4. ĹŸ��: 6 CP %s\n", hasTower ? "(ǰ��)" : "");
                printf(">> ");
                scanf_s("%d", &buy);
            } while (buy < 0 || buy > 4);

            switch (buy) {
            case 1:
                if (hasToyMouse) printf("�̹� �����߽��ϴ�.\n");
                else if (cp >= 1) { cp--; hasToyMouse = 1; printf("�峭�� �㸦 �����߽��ϴ�.\n"); }
                else printf("CP�� �����մϴ�.\n");
                break;
            case 2:
                if (hasLaser) printf("�̹� �����߽��ϴ�.\n");
                else if (cp >= 2) { cp -= 2; hasLaser = 1; printf("������ �����͸� �����߽��ϴ�.\n"); }
                else printf("CP�� �����մϴ�.\n");
                break;
            case 3:
                if (hasScratcher) printf("�̹� �����߽��ϴ�.\n");
                else if (cp >= 4) {
                    cp -= 4;
                    hasScratcher = 1;
                    do { posScratcher = rand() % ROOM_WIDTH; } while (posScratcher == HME_POS || posScratcher == BWL_POS);
                    printf("��ũ��ó�� ��ġ�߽��ϴ�!\n");
                }
                else printf("CP�� �����մϴ�.\n");
                break;
            case 4:
                if (hasTower) printf("�̹� �����߽��ϴ�.\n");
                else if (cp >= 6) {
                    cp -= 6;
                    hasTower = 1;
                    do {
                        posTower = rand() % ROOM_WIDTH;
                    } while (posTower == HME_POS || posTower == BWL_POS || posTower == posScratcher);
                    printf("ĹŸ���� ��ġ�߽��ϴ�!\n");
                }
                else printf("CP�� �����մϴ�.\n");
                break;
            }
            Sleep(3000);
            system("cls");
        }
		// ���� ����Ʈ
        if (turn == 3) {
            printf("�� ���� ����Ʈ �߻�! �˶��� ���� ���� ������ ã���ּ���! [���͸� ��������]\n");
            getchar(); getchar();
            int answer = rand() % 3 + 1;
            int input;
            printf("1~3 �� ��� ���������? >> ");
            scanf_s("%d", &input);
            if (input == answer) {
                printf("�����Դϴ�! ģ�е��� 1 ����մϴ�.\n");
                if (intimacy < 4) intimacy++;
            }
            else {
                printf("Ʋ�Ƚ��ϴ�! �˶��� �������ϴ�. ��� -1\n");
                if (mood > 0) mood--;
            }
            Sleep(3000);
            system("cls");
        }

        
        }
        return 0;
    }


