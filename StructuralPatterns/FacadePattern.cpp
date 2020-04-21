#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////
/// \brief The ComplexStuffAB class
/// This is our Complex Stuff
///
class ComplexStuffAB
{
public:
    void complexRequestA() {
        cout<<"I am complexRequestA \n";
    }

    void complexRequestB() {
        cout<<"I am complexRequestB \n";
    }
};

class ComplexStuffCD
{
public:
    void complexRequestC() {
        cout<<"I am complexRequestC \n";
    }

    void complexRequestD() {
        cout<<"I am complexRequestD \n";
    }
};

///////////////// END ///////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
/// \brief The Facade class
/// This is my Facade Class , it hides
/// all the complixity from sub system and provide simple
/// interface to client , it doesn't add any new functionality
///
////////////////////////////////////////////////////////////////////////

class Facade {

    ComplexStuffAB* abptr = nullptr;
    ComplexStuffCD* cdptr = nullptr;
public:

    Facade(ComplexStuffAB* ab,ComplexStuffCD* cd)
    {
        this->abptr = ab;
        this->cdptr = cd;
    }

    void simpleSTuffAB () {
        abptr->complexRequestA();
        abptr->complexRequestB();
    }

    void simpleSTuffCD() {
        cdptr->complexRequestC();
        cdptr->complexRequestD();
    }

    ~ Facade() {
        delete abptr;
        delete cdptr;
    }

};

//////////////////// END ////////////////////////////////////////////

int main(int argc, char*argv[])
{
    Facade *ptr = new Facade(new ComplexStuffAB, new ComplexStuffCD);

    ptr->simpleSTuffAB();

    ptr->simpleSTuffCD();

    delete ptr;

    return 0;
}
