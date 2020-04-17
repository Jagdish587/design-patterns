#include <iostream>
using namespace std;


//////////////// This is Processor type ///////////////////

// This is Processor Class
class Processor{
 public :
  string processorType;

   void displayProcessor() {
    cout<<"ProcessorType = "<<processorType<<endl;
  }

};


class QuallcommProcessor : public Processor
{
 public :

  QuallcommProcessor()
  {
    processorType = "Quallcomm";
  }


};

class MediaTekProcessor : public Processor
{
 public:

  MediaTekProcessor()
  {
    processorType = "MediaTek";
  }

};

// This is Factory for ProcessorType , It should use Processor class

class ProcessorFactory
{
 public:

  Processor* prssrobj = nullptr;

  Processor* createProcessors(string value)
  {
    if(!value.compare("quallcomm")) {
      prssrobj = new QuallcommProcessor();
    } else {
      prssrobj = new MediaTekProcessor();
    }

    return prssrobj;
  }

  virtual ~ProcessorFactory()
  {
    delete prssrobj;
  }


};

//////////////// End of Processors ////////////////////////////////////////


////////////// lets go for Camera Types ////////////////////////////////////

// Step1 : Create a Camera  Class
class Camera
{
 public:

  string cameraType;

  void displayCamera() {
    cout<<"Camera Type = "<<cameraType<<endl;
  }

  virtual ~Camera()
  {

  }

};


// Step2: Create differnet Camera Types

class Sony : public Camera
{
 public:
  Sony()
  {
    cameraType = "Sony";
  }

};

class Nikon : public Camera
{
 public:
  Nikon()
  {
    cameraType = "Nikon";
  }

};

class CameraFactory
{
 public:

  Camera* camtype = nullptr;

  Camera* createCameras(string value)
  {
    if(!value.compare("sony")) {
      camtype =  new Sony();
    } else {
      camtype =  new Nikon();
    }

    return camtype;
  }

  virtual ~CameraFactory()
  {
    delete camtype;
  }

};


/////////////////// End of Camera Stuff //////////////////


/////////////////////////////////////////////////////////////////////////////

// This is my Interface Class
class Mobile {

 public:

  string mobileName;
  virtual Processor* createProcessor(string) = 0;
  virtual Camera* createCamera(string) = 0;

  void displaymobileName() {
    cout<<"Mobile Name = "<<mobileName<<endl;
  }

  virtual ~Mobile() {}

};

class Samsung: public Mobile
{
 public:

  ProcessorFactory processorfactobj;
  CameraFactory camfactobj;

  Samsung()
  {
    mobileName = "Samsung";
  }

  Processor* createProcessor(string type)
  {
    return processorfactobj.createProcessors(type);
  }

  Camera* createCamera(string type)
  {
    return camfactobj.createCameras(type);
  }

  virtual ~Samsung()
  {
  }

};

class Realme: public Mobile {
 public:

  ProcessorFactory processorfactobj;
  CameraFactory camfactobj;

  Realme()
  {
    mobileName = "Realme";
  }

  Processor* createProcessor(string type)
  {
    return processorfactobj.createProcessors(type);
  }

  Camera* createCamera(string type)
  {
    return camfactobj.createCameras(type);
  }

};

class Iphone : public Mobile {
 public:

  ProcessorFactory processorfactobj;
  CameraFactory camfactobj;

  Iphone()
  {
    mobileName = "Realme";
  }

  Processor* createProcessor(string type)
  {
    return processorfactobj.createProcessors(type);
  }

  Camera* createCamera(string type)
  {
    return camfactobj.createCameras(type);
  }

};

// Lets have a factory class which uses mobile class
class MobileFactory {

 public:

  static Mobile* createMobileFactory(int type)
  {
    if(type == 1) {
      return new Samsung();
    } else if (type == 2){
        return new Realme();
    } else {
        return new Iphone();
    }
  }

};

//////////////////////////////////////////////////////////////////////////////////////

// This is my driver code
int main()
{

  Mobile *mobileobj = MobileFactory::createMobileFactory(1);
  Processor *processtype = mobileobj->createProcessor("quallcomm");
  Camera *camtype = mobileobj->createCamera("sony");

  mobileobj->displaymobileName();
  processtype->displayProcessor();
  camtype->displayCamera();

  delete mobileobj ;

  return 0;
}

