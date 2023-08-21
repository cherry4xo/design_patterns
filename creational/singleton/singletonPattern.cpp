#include <iostream>
#include <string>

class Singleton
{
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* instance()
    {
        if(!instance_) 
        {
            instance_ = new Singleton();
        }
        return instance_;
    }

    void checkSingleton() { std::cout << "Singleton has been created; instance = " << instance << "\n"; }

private:
    Singleton() { std::cout << "Singleton\n"; }
    static Singleton* instance_;
};

Singleton* Singleton::instance_ = nullptr;

int main(int argc, char** argv)
{
    Singleton* singleton = Singleton::instance();
    singleton->checkSingleton();
    Singleton* singleton2 = Singleton::instance();
    singleton2->checkSingleton();

    return 0;
}