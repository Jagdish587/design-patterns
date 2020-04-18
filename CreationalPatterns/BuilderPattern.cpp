#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////

// This is Interface Class

class MobileParts
{

public:
    void setProcessor(string)  { }
    void setCamera(string) {}

};

class Mobile : public MobileParts
{
    public:
       string mProcessorName;
       string mCameraName;

       Mobile()
       {

       }

       void setProcessor(string& type)
       {
           mProcessorName = type;
       }

       void setCamera(string& type)
       {
           mCameraName = type;
       }

       string getProcessor() const {
           return mProcessorName;
       }

       string getCamera() const {
           return mCameraName;
       }

};

//////////////////////////// END ///////////////////////////////////////////

//////////////////////////// BUILDER CLASS /////////////////////////////////

class PartsBuilder
{
public:
     virtual void buildProcessor(string) = 0;
    virtual void buildCamera(string) = 0;
    virtual string getProcessorName () = 0;
     virtual string getCameraName() = 0;

    virtual ~PartsBuilder() {

    }

};

class SamsungBuilder: public PartsBuilder
{
    Mobile* mobj = nullptr;
public:

    SamsungBuilder()
    {
        mobj = new Mobile();
    }

    void buildProcessor(string type)
    {
        mobj->setProcessor(type);
    }

    void buildCamera(string type)
    {
        mobj->setCamera(type);
    }

    string getProcessorName ()  {
        return mobj->getProcessor();
    }

    string getCameraName ()  {
        return mobj->getCamera();
    }

    ~SamsungBuilder() {
        delete mobj;
    }

};


class RealmeBuilder: public PartsBuilder
{
    Mobile* mobj = nullptr;
public:

    RealmeBuilder()
    {
        mobj = new Mobile();
    }

    void buildProcessor(string type)
    {
        mobj->setProcessor(type);
    }

    void buildCamera(string type)
    {
        mobj->setCamera(type);
    }

    string getProcessorName ()  {
        return mobj->getProcessor();
    }

    string getCameraName ()  {
        return mobj->getCamera();
    }

    ~RealmeBuilder() {
        delete mobj;
    }

};


class IphoneBuilder: public PartsBuilder
{
    Mobile* mobj = nullptr;
public:

    IphoneBuilder()
    {
        mobj = new Mobile();
    }

    void buildProcessor(string type)
    {
        mobj->setProcessor(type);
    }

    void buildCamera(string type)
    {
        mobj->setCamera(type);
    }

    string getProcessorName ()  {
        return mobj->getProcessor();
    }

    string getCameraName ()  {
        return mobj->getCamera();
    }

    ~IphoneBuilder() {
        delete mobj;
    }

};


////////////////////////////// END OF BUILDER /////////////////////////////////

// Lets Create Factory Class

class FoxConn
{
    PartsBuilder* obj;
public:
    explicit FoxConn(PartsBuilder* builderobj)
    {
        this->obj = builderobj;
    }

    void createMobile()
    {
        this->obj->buildProcessor("quallcomm");
        this->obj->buildCamera("sony");
    }

};

int main()
{
    // Basically builder pattern is that is creates complex build into seperate class
    PartsBuilder *pBuild = new SamsungBuilder();

    FoxConn *pfactory = new FoxConn(pBuild);
    pfactory->createMobile();

    cout<<"Processor Name = "<<pBuild->getProcessorName()<<endl;
    cout<<"Camera Name = "<<pBuild->getCameraName()<<endl;

    delete pBuild;
    delete  pfactory;
    return 0;
}
