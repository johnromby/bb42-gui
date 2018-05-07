echo "Copying to RPi"
arm-rpizw-g++ -o main main.cpp
cp main.html index.html
scp -P 22 main root@192.168.0.1:~/
scp -P 22 index.html root@192.168.0.1:/www/pages/
rm index.html