#include "game.h"

int showTimeAttackMenu() {
    int user_input_typing;

    printf("1. �ܾ� n��\n");
    printf("2. �ܾ� n��\n");
    printf("3. �ܾ� n��\n");
    printf("0. �� �޴��� ���ư���\n");
    printf("���ϴ� �ܰ踦 �Է����ּ���! ");
    scanf("%d", &user_input_typing);

    switch (user_input_typing) {
        case 1:
            // GAME STARTS
        return 0;
        case 2:
            // GAME STARTS
        return 0;
        case 3:
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