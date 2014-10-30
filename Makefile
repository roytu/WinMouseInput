main: src/MouseInput.cpp src/gazeapi.cpp main.cpp
	g++ -static-libgcc -static-libstdc++ -Iinclude -IC:\libs\boost_1_53_0 src/MouseInput.cpp src/gazeapi.cpp main.cpp -Llibs -LC:\libs\boost_1_53_0\stage\libbah -lwsock32 -lboost_system-vc110-mt-1_53 -o main -D_WIN32_WINNT=0x0501 -DWINVER=0x0501
