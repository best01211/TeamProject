CC=gcc-8
CFLAGS=-Wall -O3

all: main.o check_vocab.o score_menu.o time_attack.o mini_game.o typing_game.o
	$(CC) $(CFLAGS) -o app.out main.o check_vocab.o score_menu.o time_attack.o mini_game.o typing_game.o

main.o:
	$(CC) $(CFLAGS) -c -o main.o main.c

check_vocab.o:
	$(CC) $(CFLAGS) -c -o check_vocab.o check_vocab.c

score_menu.o:
	$(CC) $(CFLAGS) -c -o score_menu.o score_menu.c

time_attack.o:
	$(CC) $(CFLAGS) -c -o time_attack.o time_attack.c

mini_game.o:
	$(CC) $(CFLAGS) -c -o mini_game.o mini_game.c

typing_game.o:
	$(CC) $(CFLAGS) -c -o typing_game.o typing_game.c

clean:
	rm -rf ./*.out ./*.o