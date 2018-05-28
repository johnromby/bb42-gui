#include <stdio.h>
#include <unistd.h>   // Used for the sleep() and usleep() functions
#include <iostream>
#include <string>
#include <thread>
// #include <mutex>

using namespace std;

// Using global variables so far...
// mutex mut;
// string * msg;
// string msg;

string kp_value = "10";
string ki_value = "0.033";
string kd_value = "2";
string new_kp_value = kp_value;
string new_ki_value = ki_value;
string new_kd_value = kd_value;

bool change = false;


void ws_in()
{
  while(true)
  {
    // mut.lock();

    string msg = "";
    int id = 0;

    cin >> msg;

    id = stoi(msg.substr(0,1));    

    switch (id) {
      
      case 1 :
        new_kp_value = msg;
        break;
      
      case 2 :
        new_ki_value = msg;
        break;
      
      case 3 :
        new_kd_value = msg;
        break;
      
      default:
        break;
    }
    
    change = true;

    // mut.unlock();
  }
}

void ws_out()
{
  while(true)
  {
    // mut.lock();

    if(change)
    {
      if (kp_value.compare(new_kp_value) != 0) { cout << new_kp_value << endl; usleep(500000); }
      if (ki_value.compare(new_ki_value) != 0) { cout << new_ki_value << endl; usleep(500000); }
      if (kd_value.compare(new_kd_value) != 0) { cout << new_kd_value << endl; usleep(500000); }
      change = false;
    }

    // mut.unlock();
    usleep(500000);
  }
}


int main()
{
  sleep(2);

  // Disable input/output buffering.
  setbuf(stdout, NULL);
  setbuf(stdin, NULL);

  // Setting up initial values:
  cout << '1' << kp_value << endl;
  cout << '2' << ki_value << endl;
  cout << '3' << kd_value << endl;

  // Creating two threads. One for reading and one for writing:
  thread reader(ws_in);
  thread writer(ws_out);

  reader.join();
  writer.join();
  
  return 0;
}