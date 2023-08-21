#include <iostream>
#include <string>

class Product
{
public:
    void PartA(const std::string &part)
    {
        part_a = part;
    }
    void PartB(const std::string &part)
    {
        part_b = part;
    }
    void PartC(const std::string & part)
    {
        part_c = part;
    }

    void checkProduct()
    {
        std::cout << part_a + " " + part_b + " " + part_c + " has been created\n";
    }
private:
    std::string part_a;
    std::string part_b;
    std::string part_c;
};

class Builder
{
public:
    Builder() { std::cout << "Builder\n"; }
    virtual ~Builder() {}
    Product getProduct() { return product; }

    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;

protected:
    Product product;
};

class ConcreateBuilder1 : public Builder
{
public:
    ConcreateBuilder1() { std::cout << "ConcreateBuilder1\n"; }
    ~ConcreateBuilder1() override {}

    void buildPartA() override 
    {
        product.PartA("1-A");
    }
    void buildPartB() override 
    {
        product.PartB("1-B");
    }
    void buildPartC() override 
    {
        product.PartC("1-C");
    }
};

class ConcreateBuilder2 : public Builder
{
public:
    ConcreateBuilder2() { std::cout << "ConcreateBuilder2\n"; }
    ~ConcreateBuilder2() override {}

    void buildPartA() override 
    {
        product.PartA("2-A");
    }
    void buildPartB() override 
    {
        product.PartB("2-B");
    }
    void buildPartC() override 
    {
        product.PartC("2-C");
    }
};

class Director
{
public:
    Director() { std::cout << "Director\n"; }
    ~Director()
    {
        if(builder) { delete builder; }
    }

    void setBuilder(Builder* b)
    {
        if(builder) { delete builder; }
        builder = b;
    }

    Product getProduct() { return builder->getProduct(); }

    void construct()
    {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
    }

private:
    Builder* builder = nullptr;
};

int main(int argc, char** argv)
{
    Director director;
    director.setBuilder(new ConcreateBuilder1);
    director.construct();

    Product product1 = director.getProduct();
    product1.checkProduct();

    director.setBuilder(new ConcreateBuilder2);
    director.construct();

    Product product2 = director.getProduct();
    product2.checkProduct();
    
    return 0;
}