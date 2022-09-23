FLAGS = -Wall -Werror -Wextra

all: game_of_life

game_of_life:
	gcc $(FLAGS) -c src/game_of_life.c
	gcc $(FLAGS) -c src/field.c
	gcc game_of_life.o field.o -lncurses -o game_of_life

clean:
	rm -rf build

rebuild: clean game_of_life