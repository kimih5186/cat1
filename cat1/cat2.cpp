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





}