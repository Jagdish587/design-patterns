#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
/// \brief The IiceCream class
///
class IiceCream
{
public:
    virtual void Make() = 0;
    virtual ~IiceCream() { }

};

class VanillaIceCream: public IiceCream
{
public:
     void Make()
    {
        std::cout<<"VanillaIceCream ";
    }


};

class ButterScotch: public IiceCream
{
public:

     void Make()
    {
        std::cout<<"ButterScotch ";
    }
};

class Strawberry : public IiceCream
{
    void Make()
    {
        std::cout<<"Strawberry ";
    }
};

////////////////////////// END //////////////////////////////////////////////////////////

// This is my decorator
class IceCreamDecorator: public IiceCream
{

public:
    explicit IceCreamDecorator(IiceCream& decorator):m_Decorator(decorator)
    {

    }

     void Make()
    {
        m_Decorator.Make();
    }
private:
    IiceCream& m_Decorator;
};

class WithFruits : public IceCreamDecorator
{

public:
    explicit WithFruits(IiceCream& decorator):IceCreamDecorator(decorator)
    {

    }

    void Make()
     {
        IceCreamDecorator::Make();
        std::cout<<" + Fruits \n";
    }

};

class WithNuts : public IceCreamDecorator
{

public:

    explicit WithNuts(IiceCream& decorator):IceCreamDecorator(decorator)
    {

    }

    void Make()
    {
        IceCreamDecorator::Make();
        std::cout<<" + Nuts \n";
    }

};

class WithWafers : public IceCreamDecorator
{

public:
    explicit WithWafers(IiceCream& decorator):IceCreamDecorator(decorator)
    {

    }

    void Make()
    {
        IceCreamDecorator::Make();
        std::cout<<" + Wafers \n";
    }

};

int main(int argc, char* argv[])
{

    IiceCream* pVanillaIcecream = new VanillaIceCream();
    IiceCream* pButerScoth = new ButterScotch();
    IiceCream* pStrawberry = new Strawberry();


    IiceCream* pIceCreamFruits = new WithFruits(*pVanillaIcecream);
    pIceCreamFruits->Make();


    IiceCream* pIceCreamNuts = new WithNuts(*pButerScoth);
    pIceCreamNuts->Make();

    IiceCream* pWafer = new WithWafers(*pStrawberry);
    pWafer->Make();

    delete pVanillaIcecream;
    delete pButerScoth;
    delete pStrawberry;
    delete pIceCreamFruits;
    delete pIceCreamNuts;
    delete pWafer;

    return 0;
}
