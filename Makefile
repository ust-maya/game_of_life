FLAGS = -Wall -Werror -Wextra

all: game_of_life

game_of_life:
	gcc $(FLAGS) -c src/game_of_life.c
	gcc $(FLAGS) -c src/field.c
	gcc game_of_life.o field.o -lncurses -o game_of_life

docker-build: clean
	docker build -t game_of_life .

docker-start:
	docker run -it --name gol game_of_life

docker-clean:
	docker stop gol
	docker rm gol
	docker rmi game_of_life

docker-rebuild: docker-clean docker-build docker-start

clean:
	rm -rf *.o
	rm -rf game_of_life

rebuild: clean game_of_life
