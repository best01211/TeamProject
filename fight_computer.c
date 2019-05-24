#include "game.h"

void fight_computer()
{
	char user_input[30], computer_input[30], start[10] = "start", quit[10] = "quit", rule[10] = "rule", normal[15] = "normal", difficulty[15] = "difficulty", difficult[15] = "difficult", user_start[20], user_difficult[15];
	//	����� �Է�			��ǻ�� �Է�																	����					���̵� ����						�����
	int user_power = 0, computer_power = 0, i, n = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, rand_number = 0, array[5], judgement, user_burf, computer_burf, com_penalty, burf, difficult_lock = 0, sleep_time = 0, game_duration = 0, time_attack = 0;
	//	����� ���ݷ�	��ǻ�� ���ݷ�				t1,t2 �ܾ��Է½ð� t3,t4 ���ӽð�				���� ���� ����						com_penalty: ��ǻ�� ���ݷ� �������� ����			�ܾ� �����ִ� �ð�					�ܾ� �Է� �ð�
	//																										�ð� �ʰ�, ���� ó��																			���� ���� �ð�
	srand(time(NULL));

	printf("��ǻ�Ϳ� ����ϱ� ������ �����մϴ�.\n");

	do
	{
		printf("���� : start, ��Ģ : rule, ���̵� ���� : difficulty, ������ : quit\n");	// �޴�

		fgets(user_start, 20, stdin);
		for (i = 0; user_start[i] != 0; i++)
		{
			if (user_start[i] == '\n')
			{
				user_start[i] = 0;
				break;
			}
		}
		if (!(strcmp(user_start, start)) && sleep_time == 0)	// ���̵� ���� ���� ���� ���� �Ұ�
		{
			printf("���̵��� �������ּ���.\n");
			continue;
		}

		else if (!(strcmp(user_start, rule)))	// ��
		{
			printf("--------------------------------------------------------------------------\n");
			printf("��ǻ�Ϳ� ����ϱ�\n");
			printf("40�ʵ��� ������ �ܾ �Է��ϼ���.\n");
			printf("�ܾ��Է��� 4���̻� �ɸ��� ���ݷ��� �������� �ʽ��ϴ�.\n");
			printf("��ǻ�ʹ� ��Ű� ���� �Է������� ���̵��� ���� �г�Ƽ�� �־����ϴ�.\n");
			printf("�ܾ� �Է� �� �������� ������ �־����ϴ�.\n");
			printf("�ܾ� �Է� �� 3�� ���� 5���� �ܾ ���õ˴ϴ�.\n");
			printf("���õ� 5���� �ܾ� �� �ϳ��� �Է��ؾ� �մϴ�.\n");
			printf("���� ���ݷ¿� ���� ���а� �����˴ϴ�.\n\n");
			printf("���� : �ܾ� ���� �ð��� �÷��̽ð��� ���Ե˴ϴ�.\n");
			printf("--------------------------------------------------------------------------\n");
		}
		else if (!(strcmp(user_start, difficulty)))	// ���̵� ����
		{
			printf("---------------------------------------------\n");
			printf("���̵� ����\n");
			printf("---------------------------------------------\n");
			printf("\'normal\' �Ǵ� \'difficult\' �� �Է��ϼ���.\n");
			printf("---------------------------------------------\n");
			do                            // 3�� ȹ���ؾ� ����� ���� ����
			{
				fgets(user_difficult, 15, stdin);
				for (i = 0; user_start[i] != 0; i++)
				{
					if (user_difficult[i] == '\n')
					{
						user_difficult[i] = 0;
						break;
					}
				}
				if (!(strcmp(user_difficult, normal)))	// ���� ���̵� ����
				{
					sleep_time = 7000;
					game_duration = 50;
					time_attack = 7;
					com_penalty = 3;
					break;
				}
				else if (!(strcmp(user_difficult, difficult)) && difficult_lock < 3)
				{
					printf("����� ���̵��� ���� ���̵����� 3�� �̻� ȹ���ϼž� ������ �� �ֽ��ϴ�.\n");
					continue;
				}
				else if (!(strcmp(user_difficult, difficult)))	// ����� ���̵� ����
				{
					sleep_time = 3000;
					game_duration = 30;
					time_attack = 4;
					com_penalty = 1;
					break;
				}
				else
					printf("�߸� �Է��ϼ̽��ϴ�.\n");
			} while (1);

		}
		else if (!(strcmp(user_start, start)))	// ����
		{
			for (i = 0; i < 3; i++)			// 3�� �� ����
			{
				system("cls");
				printf("%d...\n", 3 - i);
				Sleep(1000);
			}
			system("cls");
			printf("����!\n");
			Sleep(1000);

			t3 = time(0);
			do
			{
				user_burf = 0;
				computer_burf = 0;
				for (i = 0; i < 5; i++)
				{
					array[i] = rand() % MAX_WORD;
				}
				printf("%s %s %s %s %s\n", word_list[array[0]], word_list[array[1]], word_list[array[2]], word_list[array[3]], word_list[array[4]]);
				Sleep(sleep_time);		// ���̵��� ���� �ð� ���� 5�� �ܾ� ���
				system("cls");
				burf = rand() % 6;		// ���� ����
				switch (burf)
				{
				case(0):
				case(1):
					break;		// 33% Ȯ���� ���� X
				case(2):
					printf("************************************************\n");
					printf("�������� ���׳װ� ��ſ��� ���𰡸� �������ϴ�.\n");
					printf("�ߵ�! ����� ���ݷ��� 1 �����մϴ�.\n");
					printf("************************************************\n\n");
					user_burf--;
					break;
				case(3):
					printf("************************************************\n");
					printf("�������� ���׳װ� ��ſ��� ���𰡸� �������ϴ�.\n");
					printf("������ ����� ��ϴ�. ����� ���ݷ��� 1 �����մϴ�.\n");
					printf("************************************************\n\n");
					user_burf++;
					break;
				case(4):
					printf("************************************************\n");
					printf("�������� ���׳װ� ��ǻ�Ϳ��� ���𰡸� �������ϴ�.\n");
					printf("emp�ߵ�! ��ǻ���� ���ݷ��� 2 �����մϴ�.\n");
					printf("************************************************\n\n");
					computer_burf -= 2;
					break;
				case(5):
					printf("************************************************\n");
					printf("�������� ���׳װ� ��ǻ�Ϳ��� ���𰡸� �������ϴ�.\n");
					printf("��ǻ�Ͱ� ���͸��� ������ϴ�. ��ǻ���� ���ݷ��� 1 �����մϴ�.\n");
					printf("************************************************\n\n");
					computer_burf++;
				}

				printf("�ܾ �Է��ϼ��� : ");
				t1 = time(0);
				fgets(user_input, 30, stdin);
				t2 = time(0);
				for (i = 0; user_input[i] != 0; i++)
				{
					if (user_input[i] == '\n')
					{
						user_input[i] = 0;
						break;
					}
				}

				for (i = 0; i < 30; i++)
				{
					if (user_input[i] == 0)
					{
						n = i + user_burf;
						break;
					}
				}
				judgement = 0;
				if (t2 - t1 >= time_attack)
				{
					printf("�ð� �ʰ��Ǿ����ϴ�.\n");
					judgement++;
				}
				if (!(!strcmp(user_input, word_list[array[0]]) || !strcmp(user_input, word_list[array[1]]) || !strcmp(user_input, word_list[array[2]]) || !strcmp(user_input, word_list[array[3]]) || !strcmp(user_input, word_list[array[4]])))
				{
					printf("���õ� �ܾ�� ���� �ʽ��ϴ�.\n");
					judgement++;
				}
				if (judgement == 0)		// judgement �� 0�̻��� ��� ���ݷ� �������� ����
					user_power += n;

				rand_number = rand() % MAX_WORD;
				word_list[rand_number];


				for (i = 0; i < 30; i++)
				{
					if (word_list[rand_number][i] == 0)
					{
						n = i - com_penalty + computer_burf;
						break;
					}
				}
				computer_power += n;

				printf("����ڰ� %s �� �Է��Ͽ� ���ݷ��� %d �� �Ǿ����ϴ�.\n", user_input, user_power);
				printf("��ǻ�Ͱ� %s �� �Է��Ͽ� ���ݷ��� %d �� �Ǿ����ϴ�.\n\n", word_list[rand_number], computer_power);
				t4 = time(0);
			} while (t4 - t3 < game_duration);
			printf("����� ���ݷ��� %d �̰� ��ǻ���� ���ݷ��� %d �Դϴ�.\n", user_power, computer_power);		// �Է¿� ���� ��� ���
			if (user_power > computer_power)
			{
				printf("�е����� ���� ���̷� ����� �¸��ϼ̽��ϴ�.\n\n");
				difficult_lock += 2;
				// ��ü ���ھ� +2��
			}
			else if (user_power == computer_power)
			{
				printf("��ǻ�͸� �������� ��ŵ� �̳� �������� ���ϴ�.\n\n");
				difficult_lock++;
				// ��ü ���ھ� +1��
			}
			else if (user_power < computer_power)
			{
				printf("������ ����� ���� ��ǻ�ʹ� �⻵�մϴ�.\n\n");
				// ��ü ���ھ� +0��
			}
		}
		else if (!(strcmp(user_start, quit)))
			break;
		else
			printf("�߸��Է��ϼ̽��ϴ�.\n");
	} while (1);
	return 0;
}