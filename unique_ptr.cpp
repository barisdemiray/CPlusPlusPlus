#include <memory>
#include <iostream>
#include <thread>
#include <sstream>
#include <cassert>

// Just a silly struct to demonstrate unique_ptr
struct Task {
    std::string name;
    int count;

    Task(const std::string& name, int count) : name(name), count(count) {}

    std::string toString() {
        std::stringstream ss;
        ss << "Name: " << name << " Count: " << count << std::endl;
        return ss.str();
    }
};

void thread_body(std::unique_ptr<Task> task)
{
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << task->toString();
        continue;
    }
}

int main()
{
    std::unique_ptr<Task> taskPtr(new Task("foo", 5));

    if (taskPtr) {
        std::cout << "task is valid" << std::endl;
    } else {
        std::cout << "task is NOT valid" << std::endl;
    }

    // We are obliged to use move semantics
    std::thread t(thread_body, std::move(taskPtr));

    // At this moment main() and thread are running simultaneously
    if (taskPtr) {
        std::cout << "task is valid" << std::endl;
    } else {
        std::cout << "task is NOT valid" << std::endl;
    }

    t.join();
    return 0;
}
