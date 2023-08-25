#include <iostream>
#include <string>
#include <unordered_map>

class Flyweight
{
public:
    virtual ~Flyweight() {}

    virtual void operation(const std::string& extrinsicState) = 0;
};

class ConcreteFlyweight : public Flyweight
{
public:
    ConcreteFlyweight(const std::string& intrinsicState)
        : intrinsicState_(intrinsicState)
    {
        std::cout << "ConcreteFlyweight + intrinsicState: " << intrinsicState_ << std::endl;
    }
    ~ConcreteFlyweight() {}

    void operation(const std::string& extrinsicState) override
    {
        std::cout << "ConcreteFlyweight operation extrinsicState: " << extrinsicState << std::endl;
    }

private:
    std::string intrinsicState_;
};

class UnsharedConcreteFlyweight : public Flyweight
{
public:
    UnsharedConcreteFlyweight(const std::string& allState)
        : allState_(allState)
    {
        std::cout << "UnsharedConcreteFlyweight allState: " << allState_ << std::endl;
    }

    void operation(const std::string& extrinsicState)
    {
        std::cout << "UnsharedConcreteFlyweight operation extrinsicState: " << extrinsicState << std::endl;
    }

private:
    std::string allState_;
};

class FlyweightFactory
{
public:
    ~FlyweightFactory() 
    {
        for(auto it = flys.begin(); it != flys.end(); ++it)
            delete it->second;
        flys.clear();
    }

    Flyweight* getFlyweight(const std::string& key)
    {
        if(flys.find(key) != flys.end()){
            std::cout << "Existed flyweight\n";
            return flys[key];
        }

        Flyweight* fly = new ConcreteFlyweight(key);
        flys.insert(std::make_pair(key, fly));
        std::cout << "New flyweight\n";

        return fly;
    }

private:
    std::unordered_map<std::string, Flyweight*> flys;
};

int main(int argc, char** argv)
{
    FlyweightFactory* factory = new FlyweightFactory();
    factory->getFlyweight("Hello")->operation("World");
    factory->getFlyweight("Hello")->operation("World");
    factory->getFlyweight("Hello")->operation("World");

    Flyweight* unsharedfly = new UnsharedConcreteFlyweight("what's up");
    unsharedfly->operation("helloworld");

    return 0;
}