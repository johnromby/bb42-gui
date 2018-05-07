echo "Running webSocketd"
g++ -pthread -o main main2.cpp
# clang++ -std=c++11 -pthread -o main main.cpp
# g++ -pthread -std=c++0x main.cpp -o main
./websocketd --port=8080 --staticdir=. ./main