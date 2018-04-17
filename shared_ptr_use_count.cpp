#include <memory>
#include <iostream>

void func2(std::shared_ptr<char> c)
{
    std::cout << "Use count = " << c.use_count() << std::endl;
}

void func(std::shared_ptr<char> c)
{
    std::cout << "Use count = " << c.use_count() << std::endl;
    func2(c);
}

void deleter(char* c)
{
    delete [] c;
    c = NULL;
    std::cout << "Deleted." << std::endl;
}

int main()
{
    std::shared_ptr<char> c(new char[5], deleter);

    c = std::shared_ptr<char>(new char[7], deleter);

    func(c);

    std::cout << "Use count = " << c.use_count() << std::endl;

    return 0;
}
