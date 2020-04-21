#include <iostream>
#include <memory>
using namespace std;



// This is Adapter Design Pattern using Class Adapter


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

class VendorAdapter : public ILegacyCode , Vendor
{
public:
    IVendor* vendobj = nullptr;

    VendorAdapter()
    {
        vendobj = new Vendor();
    }

    void request()
    {
        vendobj->simplerequest();
    }

    ~ VendorAdapter()
    {
        delete vendobj;
    }

};

/////////////////////////////////////// END ///////////////////////////////////


int main(int argc, char* argv[])
{

    // Adapter Design using multiple inheritence
    VendorAdapter* ptr = new VendorAdapter();
    ptr->request();

    delete ptr;


    return 0;
}

