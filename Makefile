FLAGS = -Wall -Werror -Wextra
PROJECT_NAME = game_of_life

all: clean $(PROJECT_NAME)

$(PROJECT_NAME):
	gcc $(FLAGS) -c src/*.c
	gcc *.o -lncurses -o $(PROJECT_NAME)

docker-build: clean
	docker build -t game_of_life .

docker-start:
	docker run -it --name gol $(PROJECT_NAME)

docker-clean:
	docker stop gol
	docker rm gol
	docker rmi $(PROJECT_NAME)

docker-rebuild: docker-clean docker-build docker-start

clean:
	rm -rf *.o
	rm -rf $(PROJECT_NAME)

rebuild: clean $(PROJECT_NAME)
