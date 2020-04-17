#include <iostream>

using namespace std;

// This is my Interface Class
class Mobile {

 public:
  int ramsize ;
  string mobileName ;

  virtual void display() {
    cout<<"Mobile Name = "<<mobileName<<" ramsize = "<<ramsize<<endl;
  }

  virtual ~Mobile() {}


};


////////////////////////////////////////////////////////////////////

class Samsung: public Mobile
{
 public:
  Samsung(int ramSize, string name) {
    ramsize = ramSize;
    mobileName = name;
  }

};

class Realme: public Mobile {
 public:

  Realme(int ramSize, string name)
  {
    ramsize = ramSize;
    mobileName = name;
  }

};

class Iphone : public Mobile {
 public:

  Iphone(int ramSize, string name)
  {
    ramsize = ramSize;
    mobileName = name;
  }

};

/////////////////////////////////////////////////////////////////////////

// Lets have a factory class which uses mobile class
class MobileFactory {

 public:

  static Mobile* createFactory(int value)
  {
    if(value == 1) {
      return new Samsung(4,"Samsung");
    } else if (value == 2){
        return new Realme(8,"RealMe");
    } else {
      	return new Iphone(16,"IPhone");
    }
  }

};


// This is my driver code
int main()
{
  Mobile *obj = MobileFactory::createFactory(2);
  obj->display();

  delete obj ;

  return 0;
}

