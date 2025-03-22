libs  := -lSDL3 -lm -lSDL3_image
files :=  src/main.cpp src/arrayFunctions/arrayFunctions.cpp src/algorithms/**/*.cpp src/button/Button.cpp
filesW :=  src/main.cpp src/arrayFunctions/arrayFunctions.cpp src/algorithms/bubblesort/bubblesort.cpp src/algorithms/mergesort/mergesort.cpp src/algorithms/quicksort/quicksort.cpp src/algorithms/insertionsort/insertionsort.cpp src/algorithms/simplesort/simplesort.cpp src/button/Button.cpp

all: windows

linux:
	@clear
	@mkdir -p build
	gcc -o build/app ${files} -Llib/linux -Iinclude ${libs}

windows:
	@if not exist "build" mkdir build
	@copy lib\\windows\\*.dll build\\
	@cls
	gcc -fpermissive -o build/app.exe ${filesW} -L lib/windows -I include ${libs}
	
run:
	build/app
