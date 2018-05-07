#include <unistd.h>   // Used for the sleep() and usleep() functions
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

// Using global variables so far...
std::mutex msg_mutex;
std::string msg;

std::string kp_value = "110,000";
std::string ki_value = "20,033";
std::string kd_value = "32,000";
std::string new_kp_value = kp_value;
std::string new_ki_value = ki_value;
std::string new_kd_value = kd_value;


void ws_read()
{
  while (true)
  {
    std::string all = "";
    std::string msg = "";
    int id = 0;
    
    std::cin >> all;

    id = stoi(all.substr(0,1));
    msg = all.substr(1);

    std::lock_guard<std::mutex> lock{msg_mutex};

    switch (id) {
      case 1:
        new_kp_value = msg;
        break;
      case 2:
        new_ki_value = msg;
        break;
      case 3:
        new_kd_value = msg;
        break;
    }
  }
}

void ws_write()
{
  while (true)
  {
    std::lock_guard<std::mutex> lock{msg_mutex};

    if (kp_value != new_kp_value) { std::cout << new_kp_value << std::endl; usleep(500000); }
    if (ki_value != new_ki_value) { std::cout << new_ki_value << std::endl; usleep(500000); }
    if (kd_value != new_kd_value) { std::cout << new_kd_value << std::endl; usleep(500000); }
  }
}


int main()
{
  sleep(5);

  // Setting up initial values:
  std::cout << kp_value << std::endl;
  std::cout << ki_value << std::endl;
  std::cout << kd_value << std::endl;

  // Creating two threads. One for reading and one for writing:
  std::thread reader(ws_read);
  std::thread writer(ws_write);

  reader.join();
  writer.join();
  
  return 0;
}