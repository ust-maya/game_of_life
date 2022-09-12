FLAGS = -Wall -Werror -Wextra
OBJDIR = build/objdir/

all: game_of_life

game_of_life:
	mkdir build
	mkdir build/objdir
	gcc $(FLAGS) -c src/game_of_life.c -o $(OBJDIR)game_of_life.o
	gcc $(FLAGS) -c src/field.c -o $(OBJDIR)field.o
	gcc $(OBJDIR)game_of_life.o $(OBJDIR)field.o -lncurses -o build/game_of_life

clean:
	rm -rf build

rebuild: clean game_of_life