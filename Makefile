main: src/MouseInput.cpp src/gazeapi.cpp main.cpp
	g++ -Iinclude -static-libgcc -static-libstdc++ -o main src/MouseInput.cpp src/gazeapi.cpp main.cpp