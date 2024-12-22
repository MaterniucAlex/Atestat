libs  := -lSDL3 -lm -lSDL3_image
files :=  src/main.cpp src/arrayFunctions/arrayFunctions.cpp src/algorithms/**/*.cpp
filesW :=  src/main.cpp src/arrayFunctions/arrayFunctions.cpp src/algorithms/bubblesort/bubblesort.cpp src/algorithms/mergesort/mergesort.cpp src/algorithms/quicksort/quicksort.cpp src/algorithms/insertionsort/insertionsort.cpp src/algorithms/simplesort/simplesort.cpp

all: linux

linux:
	@clear
	@mkdir -p build
	gcc -o build/app ${files} -Llib/linux -Iinclude ${libs}

windows:
	@if not exist "build" mkdir build
	@copy lib\\windows\\*.dll build\\
	@cls
	gcc -o build/app.exe ${filesW} -Llib/windows -Iinclude ${libs}
	
run:
	build/app
