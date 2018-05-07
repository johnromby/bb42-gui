#include <iostream>
#include <unistd.h>   // Used for the sleep() and usleep() functions
#include <mutex>
#include <string>
#include <thread>

std::mutex msg_mutex;
std::string msg;

std::string kp_value = "110,000";
std::string ki_value = "20,033";
std::string kd_value = "32,000";

void read()
{
  while (true) {
    std::string sin;
    std::cin >> sin;
    std::lock_guard<std::mutex> lock{msg_mutex};
    msg = sin;
  }
}

void write()
{
  while (true) {
    std::lock_guard<std::mutex> lock{msg_mutex};
    if (msg.length() > 0) {
      std::cout << msg << std::endl;
      msg.clear();
    }
  }
}

int main()
{
  std::cout << kp_value << std::endl;
  usleep(500 * 1000);
  std::cout << ki_value << std::endl;
  usleep(500 * 1000);
  std::cout << kd_value << std::endl;
  usleep(500 * 1000);

  std::thread reader(read);
  std::thread writer(write);

  reader.join();
  writer.join();
  return 0;
}