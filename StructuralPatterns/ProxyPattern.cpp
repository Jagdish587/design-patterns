#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////
/// \brief The ISubject class
/// This is the Interface Class for Subject
///

class ISubject
{
public:
    virtual void request() = 0;
    virtual ~ISubject() {}
};

class RealRequest : public ISubject
{
public:

    void request() {
        cout<<"I am RealRequest \n";
    }

};

/////////////////// END //////////////////////////////////////////


////////////////////////////////////////////////////////////////////
/// \brief The ProxyRequest class
/// This is Proxy Class
///
class ProxyRequest : public ISubject
{
    RealRequest* ptr;
public:
    explicit ProxyRequest(RealRequest* realobj)
    {
        this->ptr = realobj;
    }

    void request() {
        cout<<"I am Proxy Request \n";
        ptr->request();
    }

    ~ ProxyRequest()
    {
        delete ptr;
    }

};

////////////////////////// END ///////////////////////////////////

int main(int argc, char* argv[])
{
    ISubject* ptr = new ProxyRequest(new RealRequest());
    ptr->request();

    delete ptr;
    return 0;
}

