#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define ROOM_WIDTH 12
#define HME_POS 0
#define BWL_POS (ROOM_WIDTH - 1)
#define CAT_NAME "쫀떡이"

int posScratcher = -1;
int posTower = -1;

// 스크래처와 캣타워의 위치를 랜덤으로 배치하는 함수
void setRandomFurniturePositions() {
    do {
        posScratcher = rand() % ROOM_WIDTH;
    } while (posScratcher == HME_POS || posScratcher == BWL_POS);

    do {
        posTower = rand() % ROOM_WIDTH;
    } while (posTower == HME_POS || posTower == BWL_POS || posTower == posScratcher);
}

// 방을 그리는 함수
void drawRoom(int catPos, int prevPos, int hasScratcher, int hasTower) {
    // 윗 벽
    for (int i = 0; i < ROOM_WIDTH + 2; i++) printf("#");
    printf("\n");

    // 첫 번째 줄: 벽 + 방 내용 + 벽
    for (int i = 0; i < ROOM_WIDTH + 2; i++) {
        if (i == 0) {
            printf("#");  // 왼쪽 벽
        }
        else if (i == ROOM_WIDTH + 1) {
            printf("#");  // 오른쪽 벽
        }
        else {
            int pos = i - 1;  // 방 내부 인덱스 (0~ROOM_WIDTH-1)
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

    // 두 번째 줄: 벽 + 고양이 위치 + 벽
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

    // 아랫 벽
    for (int i = 0; i < ROOM_WIDTH + 2; i++) printf("#");
    printf("\n\n");
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
        

        //행동

        int prevMood = mood;

        if (catPos == HME_POS && prevPos == HME_POS && mood < 3) {
            mood++;
            printf("쫀떡이 집에서 쉬며 기분이 좋아집니다: %d -> %d\n", prevMood, mood);
        }
        else if (hasScratcher && catPos == 2 && mood < 3) {
            mood++;
            printf("쫀떡이 스크래처를 긁고 기분이 좋아졌습니다: %d -> %d\n", prevMood, mood);
        }
        else if (hasTower && catPos == 3) {
            int increase = (mood <= 1) ? 2 : 1;
            mood += increase;
            if (mood > 3) mood = 3;
            printf("쫀떡이 캣타워에서 놀며 기분이 제법 좋아졌습니다: %d -> %d\n", prevMood, mood);
        }
        else if (catPos == BWL_POS) {
            char soups[3][20] = { "감자수프", "양송이수프", "브로콜리수프" };
            int s = rand() % 3;
            printf("쫀떡이 %s를 만들었습니다!\n", soups[s]);
            soupCount++;
        }
        Sleep(5000);
        system("cls");


        //상호작용
        printf("어떤 상호작용을 하시겠습니까?\n");
        printf(" 0. 아무것도 하지 않음\n 1. 긁어 주기\n");
        if (hasToyMouse && hasLaser) {
            printf(" 2. 장난감 쥐로 놀아 주기\n 3. 레이저 포인터로 놀아 주기\n");
        }
        else if (hasToyMouse) {
            printf(" 2. 장난감 쥐로 놀아 주기\n");
        }
        else if (hasLaser) {
            printf(" 2. 레이저 포인터로 놀아 주기\n");
        }
        printf(">> ");

        //상호작용 처리
        int act;
        scanf_s("%d", &act);
        roll = rand() % 6 + 1;

        switch (act) {
        case 0:
            if (mood > 0) mood--;
            printf("쫀떡의 기분이 나빠졌습니다: %d->%d\n", beforeMood, mood);
            if (roll <= 5 && intimacy > 0) {
                intimacy--;
                printf("집사와의 관계가 나빠집니다.\n");
            }
      
        case 1:
            printf("쫀떡의 기분은 그대로입니다: %d\n", mood);
            if (roll >= 5 && intimacy < 4) {
                intimacy++;
                printf("집사와의 관계가 좋아졌습니다.\n");
            }
         

        case 2:
            if (hasToyMouse) {
                printf("장난감 쥐로 쫀떡과 놀아 주었습니다.\n");
                if (mood < 3) mood++;
                printf("쫀떡의 기분이 조금 좋아졌습니다: %d->%d\n", beforeMood, mood);
                if (roll >= 4 && intimacy < 4) {
                    intimacy++;
                    printf("집사와의 관계가 좋아졌습니다.\n");
                }
            }
            

        case 3:
            if (hasLaser) {
                printf("레이저 포인터로 쫀떡과 신나게 놀아 주었습니다.\n");
                mood += 2;
                if (mood > 3) mood = 3;
                printf("쫀떡의 기분이 꽤 좋아졌습니다: %d->%d\n", beforeMood, mood);
                if (roll >= 2 && intimacy < 4) {
                    intimacy++;
                    printf("집사와의 관계가 좋아졌습니다.\n");
                }
            }
            

            Sleep(5000);
            system("cls");

            // CP 생산
            int cpGain = (mood > 1 ? (mood - 1) : 0) + intimacy;
            cp += cpGain;
            printf("쫀떡의 기분(0~3): %d\n", mood);
            printf("집사와의 친밀도(0~4): %d\n", intimacy);
            printf("쫀떡의 기분과 친밀도에 따라서 CP가 %d 포인트 생산되었습니다.\n", cpGain);
            printf("보유 CP: %d 포인트\n", cp);

            Sleep(5000);
            system("cls");

            // 상점
            int buy = -1;
            do {
                printf("상점에서 물건을 살 수 있습니다. 무엇을 구매하시겠습니까?\n");
                printf("0. 아무것도 사지 않는다.\n");
                printf("1. 장난감 쥐: 1 CP %s\n", hasToyMouse ? "(품절)" : "");
                printf("2. 레이저 포인터: 2 CP %s\n", hasLaser ? "(품절)" : "");
                printf("3. 스크래처: 4 CP %s\n", hasScratcher ? "(품절)" : "");
                printf("4. 캣타워: 6 CP %s\n", hasTower ? "(품절)" : "");
                printf(">> ");
                scanf_s("%d", &buy);
            } while (buy < 0 || buy > 4);

            switch (buy) {
            case 1:
                if (hasToyMouse) printf("이미 구매했습니다.\n");
                else if (cp >= 1) { cp--; hasToyMouse = 1; printf("장난감 쥐를 구매했습니다.\n"); }
                else printf("CP가 부족합니다.\n");
                break;
            case 2:
                if (hasLaser) printf("이미 구매했습니다.\n");
                else if (cp >= 2) { cp -= 2; hasLaser = 1; printf("레이저 포인터를 구매했습니다.\n"); }
                else printf("CP가 부족합니다.\n");
                break;
            case 3:
                if (hasScratcher) printf("이미 구매했습니다.\n");
                else if (cp >= 4) {
                    cp -= 4;
                    hasScratcher = 1;
                    do { posScratcher = rand() % ROOM_WIDTH; } while (posScratcher == HME_POS || posScratcher == BWL_POS);
                    printf("스크래처를 설치했습니다!\n");
                }
                else printf("CP가 부족합니다.\n");
                break;
            case 4:
                if (hasTower) printf("이미 구매했습니다.\n");
                else if (cp >= 6) {
                    cp -= 6;
                    hasTower = 1;
                    do {
                        posTower = rand() % ROOM_WIDTH;
                    } while (posTower == HME_POS || posTower == BWL_POS || posTower == posScratcher);
                    printf("캣타워를 설치했습니다!\n");
                }
                else printf("CP가 부족합니다.\n");
                break;
            }
            Sleep(3000);
            system("cls");
        }
		//////// 돌발 퀘스트 
        if (turn == 3) {
            printf("★ 돌발 퀘스트 발생! 쫀떡이 숨겨 놓은 간식을 찾아주세요! [엔터를 누르세요]\n");
            getchar(); getchar();
            int answer = rand() % 3 + 1;
            int input;
            printf("1~3 중 어디에 숨었을까요? >> ");
            scanf_s("%d", &input);
            if (input == answer) {
                printf("정답입니다! 친밀도가 1 상승합니다.\n");
                if (intimacy < 4) intimacy++;
            }
            else {
                printf("틀렸습니다! 쫀떡은 삐졌습니다. 기분 -1\n");
                if (mood > 0) mood--;
            }
            Sleep(3000);
            system("cls");
        }

        
        }
        return 0;
    }


