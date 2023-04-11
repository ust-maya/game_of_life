Game of Life
============
Simple program in terminal. Required `ncurses.h`.

Compiling and run
-----------
Run `make`, next `./game_of_life`.

How to change the first generation?
-----------
Edit the file `presets/preset.txt`. Then run `make rebuild`.

How to run it in Docker?
-----------
Run `make docker-build`, then `make docker-start`.
After editing file `preset.txt`, run `make docker-rebuild`.