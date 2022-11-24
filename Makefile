all: 
	g++ -Iinclude -Iinclude/sdl -Iinclude/headers -Llib -o Main src/*cpp -lmingw32 -lSDL2 -lSDL2main -lSDL2_image