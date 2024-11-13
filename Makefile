libs  := -lSDL3 -lm -lSDL3_image
files := src/main.c

all: linux

linux:
	@clear
	@mkdir -p build
	gcc -o build/app ${files} -Llib/linux -Iinclude ${libs}

windows:
	@if not exist "build" mkdir build
	@copy lib\\windows\\*.dll build\\
	@cls
	gcc -o build/app.exe ${files} -Llib/windows -Iinclude ${libs}
	
run:
	build/app
