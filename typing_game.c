#include "game.h"

int showTypingMenu() {
    int user_input_typing;

    printf("1. 초급\n");
    printf("2. 중급\n");
    printf("3. 고급\n");
    printf("4. 최상급\n");
    printf("0. 전 메뉴로 돌아가기\n");
    printf("원하는 단계를 입력해주세요! ");
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