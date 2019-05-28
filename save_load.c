#include "game.h"

struct typing_score type_score;
struct minigame_score mini_score;
struct timeattack_score timeat_score;

int slMenu() {
    int user_input_typing;
    static char save_file_dir[100] = {0}, info_file[] = "���� ���� ���: %s\n";

    printf("1. �������� ��� �Է�.\n");
    printf("2. ��ο� �����ϱ�!\n");
    printf("3. ��ο��� �ҷ�����!\n");
    printf("0. �� �޴��� ���ư���\n");
    printf(info_file, save_file_dir);
    printf("���ϴ� �ܰ踦 �Է����ּ���! ");
    scanf("%d", &user_input_typing);

    switch (user_input_typing) {
        case 1:
            // Input save-load file directory
            while(getchar() != '\n');
            printf("���������� ��θ� �Է��ϼ���: ");
            fgets(save_file_dir, sizeof(save_file_dir), stdin);
            save_file_dir[strlen(save_file_dir) - 1] = 0;
        return 1;
        case 2:
            // Save
            if (strlen(save_file_dir) == 0) {
                printf("1�� �޴��� ���� ���� ��θ� �Է����ּ���!\n");
                sleepfor(2);
            } else {
                saveLogic(save_file_dir);
                printf("���� ������ �Ϸ�Ǿ����ϴ�!\n");
                sleepfor(2);
            }
        return 1;
        case 3:
            // Load
            if (strlen(save_file_dir) == 0) {
                printf("1�� �޴��� ���� ���� ��θ� �Է����ּ���!\n");
                sleepfor(2);
            } else {
                load(save_file_dir);
                printf("�ε��� �Ϸ�Ǿ����ϴ�!\n");
                sleepfor(2);
            }
        return 0;
        case 0:
            // Return to last menu
        return 0;
        default:
            // Get another input;
        return 10;
    }
}

void saveLogic(char *save_dir) {
    char test[50] = {0};

    // type_score
    makeArray(type_score.easy, test);
    makeArray(type_score.moderate, test);
    makeArray(type_score.hard, test);
    makeArray(type_score.extreme, test);

    // mini_score
    makeArray(mini_score.timecalc, test);
    makeArray(mini_score.find_road, test);
    makeArray(mini_score.fight_computer, test);
    makeArray(mini_score.mem_word, test);

    // timeat_score
    makeArray(timeat_score.word_n1, test);
    makeArray(timeat_score.word_n2, test);
    makeArray(timeat_score.word_n3, test);

    //finally, save it
    save(test, save_dir);
}

void makeArray(int value, char* wtf) {
    char temp[20] = {0};
    int temp_counter = 0, wtf_counter = strlen(wtf);

    if (value == 0) {
        temp[temp_counter] = '0';
    } else {
        while (value != 0) {
            temp[temp_counter] = (value % 10) + '0';
            value = value / 10;
            temp_counter++;
        }
    }

    // Roll back to positive way.
    for (int i = strlen(temp); i >= 0; i--) {
        if (i != 0) {
            wtf[wtf_counter] = temp[i-1];
        }
        wtf_counter++;
    }

    // Put blank on last bits
    wtf[strlen(wtf)] = ' ';
}

void save(char* wtf, char *save_file_dir) {
    //int temp_counter = 0, wtf_counter = 0;
    FILE *test_file = fopen(save_file_dir, "w");
    
    // Trail last bits
    wtf[strlen(wtf) - 1] = 0;
    fputs(wtf, test_file);
    fclose(test_file);
}

void load(char *save_file_dir) {
    FILE *test_file = fopen(save_file_dir, "r");
    char test[40];
    int score_saved[40] = {0,}, counter = 0, res = 0, intcounter = 0;

    fgets(test, sizeof(test), test_file);

    while (counter != strlen(test)) {
        if (test[counter] == ' ') {
            score_saved[intcounter] = res;
            res = 0;
            counter++;
            intcounter++;
            continue;
        }
        res = res * 10 + (test[counter] - '0');
        counter++;
    }

    //last bit calculated
    score_saved[intcounter] = res;
    for (int i = 0; i < intcounter + 1; i++) {
        printf("array: %d\n", score_saved[i]);
    }
    fclose(test_file);
}