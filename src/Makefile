FLAGS = -Wall -Werror -Wextra

all: game_of_life

game_of_life:
	gcc $(FLAGS) -c game_of_life.c
	gcc $(FLAGS) -c field.c
	gcc game_of_life.o field.o -lncurses -o ../build/game_of_life

clean:
	rm -rf *.o
	rm -rf ../build/game_of_life

rebuild: clean game_of_life