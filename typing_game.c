#include "game.h"

int showTypingMenu() {
    int user_input_typing;

    printf("1. �ʱ�\n");
    printf("2. �߱�\n");
    printf("3. ���\n");
    printf("4. �ֻ��\n");
    printf("0. �� �޴��� ���ư���\n");
    printf("���ϴ� �ܰ踦 �Է����ּ���! ");
    scanf("%d", &user_input_typing);

    switch (user_input_typing) {
        case 1:
            // Beginner
        return 0;
        case 2:
            // Intermediates
        return 0;
        case 3:
            // Expert
        return 0;
        case 4:
            // Extremely-hard
        return 0;
        case 0:
            // Return to last menu
        return 0;
        default:
            // Get another input;
        return 10;
    }
}