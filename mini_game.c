#include "game.h"

int showMiniGameMenu() {
    int user_input_typing;

    printf("1. ������\n");
    printf("2. ��ã��\n");
    printf("3. ��ǻ�Ϳ��� ���!\n");
    printf("4. �ܾ� ����!\n");
    printf("0. �� �޴��� ���ư���\n");
    printf("���ϴ� �ܰ踦 �Է����ּ���! ");
    scanf("%d", &user_input_typing);

    switch (user_input_typing) {
        case 1:
            // GAME STARTS
			times_table();
        return 0;
        case 2:
            // GAME STARTS
            mini_maze();
        return 0;
        case 3:
            // GAME STARTS
			fight_computer();
        return 0;
        case 4:
            // GAME STARTS
        return 0;
        case 0:
            // Return to last menu
        return 0;
        default:
            // Get another input;
        return 10;
    }
}