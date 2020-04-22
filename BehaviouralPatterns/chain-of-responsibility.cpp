#include <iostream>
#include <string>
using namespace std;

class Calculator {
public:
    Calculator() : nextPointer (0) {}

    void setNextPointer(Calculator* ptr)
    {
        this->nextPointer = ptr;
    }

    void processResult(int a, int b)
    {
        if(this != nullptr) {
            this->getResult(a,b);
            nextPointer->processResult(a,b);
        }
    }

private:
    Calculator* nextPointer ;
    virtual void getResult(int, int) = 0;

};

class Addition : public Calculator
{
public:
    void getResult(int a, int b)
    {
        cout<<"Addition value = "<<(a + b)<<endl;
    }

};

class Subtraction : public Calculator
{
public:
    void getResult(int a, int b)
    {
        cout<<"Subtraction value = "<<(a - b)<<endl;
    }

};

class Multiplication : public Calculator
{
public:

    void getResult(int a, int b)
    {
        cout<<"Multiplication value = "<<(a * b)<<endl;
    }

};


int main()
{

    Addition add;
    Subtraction sub;
    Multiplication mul;

    add.setNextPointer(&sub);
    sub.setNextPointer(&mul);

    add.processResult(5,4);

    return 0;
}
