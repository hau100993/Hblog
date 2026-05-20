#include <bits/stdc++.h>
// #include <thread>
// #include <iostream.h>
// #include <string.h>
#include <unistd.h>

static bool blockingState= false; 
std::mutex signalMutex; 

bool function1(int inputValue)
{
    /* do some thing */
    while (inputValue--> 0)
    {
        /* do work */
        std::cout << "\nThread " << __FUNCTION__ << " is working: " << inputValue << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    return true;
}

bool function2(int inputValue)
{
    std::unique_lock<std::mutex> mlock(signalMutex);
    /* do some thing */
    while (inputValue--> 0)
    {
        /* do work */
        std::cout << "\nThread " << __FUNCTION__ << " is working: " << inputValue << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));

        if (blockingState)
        {
            std::cout << "\nThread " << __FUNCTION__ << " is got set lock(): " << "\n";
            mlock.lock();
        }
        // else
        // {
        //     std::cout << "\nThread " << std::this_thread::get_id() << " is got set unlock(): " << "\n";
        //     mlock.unlock();
        // }
    }
    mlock.unlock();
    return true;
}


/*  Create signal handler */

void signalHandler(int signal)
{
    if (signal == SIGUSR1)
    {
        std::cout << "User request SIGUSR1 signal. set blockingState to true" << "\0";
        blockingState = true;
    }
    else if (signal == SIGUSR2)
    {
        std::cout << "User request SIGUSR2 signal. set blockingState to false" << "\0";
        blockingState = false;
    }

    return; 

}

int main()
{

    std::cout << "Starting: Process id: " << getpid() << "\n";

    std::signal(SIGUSR1, signalHandler);
    std::signal(SIGUSR2, signalHandler);

    
    std::thread thread1(function1, 100);
    std::thread thread2(function2, 100);


    // /*  Main thread: Loop to  get signal */
    // {

    //     while (true) // not rx signal
    //     {
    //         std::this_thread::sleep_for(std::chrono::seconds(1));
    //     }

    // }

    thread1.join();
    thread2.join();
    return 0;
}