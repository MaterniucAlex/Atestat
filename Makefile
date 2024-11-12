libs  := -lSDL3 -lm -SDL3_image
files := src/main.c  

all:
	@clear
	@mkdir -p build
	gcc -o build/app ${files} -Llib -Iinclude ${libs}

run:
	build/app
