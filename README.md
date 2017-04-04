# multithreaded_deadlock
Project 2 - CMPSC 473

Adam Geiger

## This Project

My project is based out of an Xcode project in C++. If you want to use this in Visual Studio just put all .cpp and .h file in a Visual Studio project.


### DeadLock Example

**Console input**: `1`

In this program, 5 threads are trying to print to the console. The deadlock happens when one thread grabs the first lock `myMutex1` and another thread grabs the other `myMutex2`. Now when either thread tries to acquire the other lock it can't since the other thread has it. Therefor the threads are in deadlock and cannot move forward.

### Mutual Exclusion

**Console input**: `2`

To combat the deadlocking program we can use the deadlocking prevention technique Mutual Exclusion. In way program this is accomplished by adding only one lock to the resource intensive part of printing to the console. This creates mutual exclusion to the active thread.


### Hold and Wait

**Console input**: `3`

Another method of deadlock prevention is Hold and Wait. To show this in my code I used two locks inside of the resource intense section `shared_cout_thread_even()`. Since the lock `myMutex1` is accessed first every time, there is no way for another thread to come and take the second lock `myMutex2`. So the active thread is *holding* the lock while other threads are *waiting*.

### No Preempt and Circular Wait

**Console input**: `4` and `5`

No Preempt and Circular Wait methods of deadlock prevention work in a simular way in my code. To have no preemptions in the resource section of the code means that the threads finishes all it needs to before another thread enters the section. So I have the threads being created and destroyed one after another so that they finish everything they need to before another thread starts. In the same way, *circular wait* waits for each thread to finish until the next thread goes. This orders the threads so that the resource section can process them one at a time.
