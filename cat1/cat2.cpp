#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define ROOM_WIDTH 12
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)
#define CAT_NAME "고양이"

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


    printf("**** 야옹이와 수프 ****\n\n");
    printf("@@@ 여기에 ASCII art 그리기 @@@\n\n");
    printf("        /＼_/＼\n");
    printf(" /＼   / o  o ＼  \n");
    printf("//＼＼ ＼~(*)~/ \n");
    printf("   ＼/    ^ /\n");
    printf("     |  ＼|| ||\n");
    printf("     ＼  '|| ||\n");
    printf("       ＼)()-())\n");

    printf("고양이 이름은 '%s'입니다.\n\n", CAT_NAME);

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

        // 상태창
        printf("==================== 현재상태 ====================\n");
        printf("현재까지 만든 수프: %d개\n", soupCount);
        printf("CP: %d 포인트\n", cp);
        printf("쫀떡이 기분(0~3): %d\n", mood);
        switch (mood) {
        case 0: printf(" 기분이 매우 나쁩니다.\n"); break;
        case 1: printf(" 심심해합니다.\n"); break;
        case 2: printf(" 식빵을 굽습니다.\n"); break;
        case 3: printf(" 골골송을 부릅니다.\n"); break;
        }
        printf("집사와의 관계(0~4): %d\n", intimacy);
        switch (intimacy) {
        case 0: printf(" 곁에 오는 것조차 싫어합니다.\n"); break;
        case 1: printf(" 간식자판기 취급입니다.\n"); break;
        case 2: printf(" 그럭저럭 쓸 만한 집사입니다.\n"); break;
        case 3: printf(" 훌륭한 집사로 인정 받고 있습니다.\n"); break;
        case 4: printf(" 집사 껌딱지입니다.\n"); break;
        }
        printf("============================================\n\n");
        Sleep(3000);
        system("cls");

        //방 그리기
        drawRoom(catPos, prevPos, hasScratcher, hasTower);
        Sleep(3000);
        system("cls");


        //기분 나빠짐
        printf("6~2: 주사위 눈이 4이하이면 그냥 기분이 나빠집니다.\n");

        int moodDice = rand() % 6 + 1;

        printf("주사위를 굴립니다. 또르륵...\n %d이(가) 나왔습니다!\n", moodDice);
        if (moodDice <= (6 - intimacy)) {
            if (mood > 0) mood--;
            printf("아무 이유 없이 기분이 나빠집니다. 고양이니까?\n쫀떡의 기분이 나빠집니다.\n");
        }
        else {
            printf("쫀떡의 기분은 그대로입니다.\n");
        }
        Sleep(3000);
        system("cls");


        // 이동
        prevPos = catPos;
        if (mood == 0 && catPos != HME_POS) {
            catPos--;
            printf("기분이 매우 나쁜 쫀떡이는 집으로 향합니다.\n");
        }
        else if (mood == 1) {
            if (hasScratcher || hasTower) {
                catPos = (hasScratcher ? 2 : 3);
                printf("쫀떡은 심심해서 스크래처 쪽으로 이동합니다.\n");
            }
            else {
                printf("놀 거리가 없어서 기분이 매우 나빠집니다.\n");
                if (mood > 0) mood--;
            }
        }
        else if (mood == 2) {
            printf("쫀떡은 기분좋게 식빵을 굽고 있습니다.\n");
        }
        else if (mood == 3 && catPos != BWL_POS) {
            catPos++;
            printf("쫀떡은 골골송을 부르며 수프를 만들러 갑니다.\n");
        }
        Sleep(5000);
        system("cls");










    }


