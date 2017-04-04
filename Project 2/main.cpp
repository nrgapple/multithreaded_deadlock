//  Adam Geiger
//  main.cpp
//  Project 2


// Project2.cpp : A simple program showing how the prevent a deadlock using 4 ways the restrain requests by threads.
//

#include <iostream>
#include <thread>
#include "Account.hpp"

using namespace std;
const int SIZE = 10;

mutex myMutex, myMutex1, myMutex2;
enum Fix{Deadlock, Mutual, HoldAndWait, NoPreempt, CircularWait};

Fix policy;


void shared_cout_thread_even(int i, int thread_num)
{
  lock_guard<mutex> g1(myMutex1);
  lock_guard<mutex> g2(myMutex2);
  cout << " " << "[" << i << "|" << thread_num << "]" << " ";
}

void shared_cout_thread_odd(int i, int thread_num)
{
  lock_guard<mutex> g2(myMutex2);
  lock_guard<mutex> g1(myMutex1);
  cout << " " << "[" << i << "|" << thread_num << "]" << " ";
}

void shared_cout_main(int i, int thread_num)
{
  lock_guard<mutex> g(myMutex);
  cout << " " << "[" << i << "|" << thread_num << "]" << " ";
}

void f(int n)
{
  for (int i = SIZE*(n - 1); i < SIZE*n; i++) {
    if (policy == Mutual)
      shared_cout_main(i, n);
    else if (policy == HoldAndWait)
      shared_cout_thread_even(i, n);
    else if (policy == NoPreempt)
      shared_cout_main(i, n);
    else if (n % 2 == 0)
      shared_cout_thread_even(i, n);
    else
      shared_cout_thread_odd(i, n);
  }
}

int main()
{
  

  
  
  int newFix;
  cout << "Enter Policy to test: \n1: Cause Deadlock\n2: Mutual Exclusion\n3: Hold and Wait\n4: No Preemption\n5: Circular Wait\nPolicy: ";
  cin >> newFix;
  newFix--;
  policy = (Fix)newFix;
  thread t1, t2, t3, t4, t5;
  
  switch (policy){
    case (Deadlock) :
      
      t1 = thread(f, 1);  // 0-9
      t2 = thread(f, 2);  // 10-19
      t3 = thread(f, 3);  // 20-29
      t4 = thread(f, 4);  // 30-39
      t5 = thread(f, 5);  // 40-49
      
      for (int i = 0; i > -SIZE; i--)
        shared_cout_main(i, 0);  // (0, -49)
      
      t1.join();
      t2.join();
      t3.join();
      t4.join();
      t5.join();
      break;
    case (Mutual) :
      t1 = thread(f, 1);  // 0-9
      t2 = thread(f, 2);  // 10-19
      t3 = thread(f, 3);  // 20-29
      t4 = thread(f, 4);  // 30-39
      t5 = thread(f, 5);  // 40-49
      
      for (int i = 0; i > -SIZE; i--)
        shared_cout_main(i, 0);  // (0, -49)
      
      t1.join();
      t2.join();
      t3.join();
      t4.join();
      t5.join();
      
      break;
    case (HoldAndWait) :
      t1 = thread(f, 1);  // 0-9
      t2 = thread(f, 2);  // 10-19
      t3 = thread(f, 3);  // 20-29
      t4 = thread(f, 4);  // 30-39
      t5 = thread(f, 5);  // 40-49
      
      for (int i = 0; i > -SIZE; i--)
        shared_cout_main(i, 0);  // (0, -49)
      
      t1.join();
      t2.join();
      t3.join();
      t4.join();
      t5.join();
      
      break;
      
    case(NoPreempt) :
      t1 = thread(f, 1);  // 0-9
      t1.join();
      t2 = thread(f, 2);  // 10-19
      t2.join();
      t3 = thread(f, 3);  // 20-29
      t3.join();
      t4 = thread(f, 4);  // 30-39
      t4.join();
      t5 = thread(f, 5);  // 40-49
      t5.join();
      break;
    case(CircularWait) :
      t1 = thread(f, 1);  // 0-9
      t1.join();
      t2 = thread(f, 2);  // 10-19
      t2.join();
      t3 = thread(f, 3);  // 20-29
      t3.join();
      t4 = thread(f, 4);  // 30-39
      t4.join();
      t5 = thread(f, 5);  // 40-49
      t5.join();
      
      for (int i = 0; i > -SIZE; i--)
        shared_cout_main(i, 0);  // (0, -49)
      break;
    default:
      cout << "error" << endl;
      break;
  }
  
  return 0;
}

