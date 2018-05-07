echo "Running webSocketd"
# g++ -o main main.cpp
# clang++ -std=c++11 -pthread -o test test.cpp
g++ -pthread -std=c++0x main.cpp -o main
./websocketd --port=8080 --staticdir=. ./test2