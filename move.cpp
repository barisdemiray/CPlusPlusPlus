#include <utility>
#include <iostream>
#include <sstream>
#include <chrono>

// A very useless method, point is how incoming parameter is copied
void length(std::string str)
{
    std::cout << "Length: " << str.length() << std::endl;
}

int main()
{
    std::stringstream ss;

    for (int i = 0; i < 100000000; ++i) {
        ss << "Hope this will not overflow" << std::endl;
    }

    std::string str = ss.str();

    unsigned long time1, time2, time3;

    // Do the same operation twice, with and without std::move()
    time1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    length(str);
    time2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::cout << "First operation took " << time2 - time1 << " milliseconds" << std::endl;
    std::cout << "Length of the string after the call is " << str.length() << std::endl;

    time2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    length(std::move(str));
    time3 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::cout << "Second operation took " << time3 - time2 << " milliseconds" << std::endl;
    std::cout << "Length of the string after the call is " << str.length() << std::endl;

    return 0;
}
