#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <string>
#include <algorithm>
#include <thread>

#include "./lib/Thread/ThreadEx.h"
#include "./lib/Utils/UtilityModules.h"
#include "./lib/stl_container.h"


using namespace std;

// void job(int& count)
// {
//     auto id = std::this_thread::get_id(); 
//     std::cout << "Start thread id::" << id << "\n"; 
//     while (count --> 0 )

//         // auto output = boost::format("Thread[%d]: Decrease counter: %d ")%id%count; 
//         // cout << output.str() << "\n";
//         cout <<"Thread: " << id << " Decrease counter " << count << "\n";
//         std::this_thread::sleep_for(1s);
// }

int main()
{
    ThreadEx newJob;

    // std::cout << "Input value: " << "\n";
    // unsigned int count = 10;
    //get input from cmd:
    // std::cin >> count;
    // std::cout << "Got: " << count << "\n";
    newJob.start();
    newJob.startByStdAsync();

    // std::cin.get(); // waiting to press ENTER

/* ================================= */
/*  Timer mTimer;
    mTimer.testPrint();
    return 0; 
    
*/


/* ================================= */
    test_priority_queue();

}
