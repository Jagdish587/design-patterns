#include <iostream>
#include <memory>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////
/// \brief The ILegacyCode class
/// This is Legacy Code which was working previously
///

class ILegacyCode
{
public:
    virtual void request() = 0;

    virtual ~ILegacyCode()
    {

    }
};

class LegacyCode: public ILegacyCode
{
    void request()
    {
        cout<<"I am inside LegacyCode \n";
    }

};

//////////////////////// END ///////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
/// \brief The IVendor class
/// This is Vendor Class supplied from vendor team
/// This is called Adaptee in OO Terminology
///

class IVendor
{
public:
    virtual void simplerequest() = 0;
    virtual ~IVendor() { }
};

class Vendor: public IVendor
{
public:
    void simplerequest() {
        cout<<"i am damn simple request \n";
    }
};

/////////////////////////// END ////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// \brief The VendorAdapter class
/// This is Adapter class
/// Notice that we are subclassing Legacy Code and using
/// Vendor code
///
class VendorAdapter : public ILegacyCode
{
public:
    IVendor* vendobj = nullptr;

    explicit VendorAdapter(IVendor* obj)
    {
        this->vendobj = obj;
    }

    void request()
    {
        vendobj->simplerequest();
    }

};

/////////////////////////////////////// END ///////////////////////////////////


int main(int argc, char* argv[])
{
    // Step1 : Let's test nornal case scenario
    ILegacyCode* myobj1 = new LegacyCode();
    myobj1->request();

    // Step2: Lets test our vendor provided api's
    ILegacyCode* obj = new VendorAdapter(new Vendor());
    obj->request();

    delete myobj1;
    delete obj;

    return 0;
}
