#include <iostream>

using namespace std;

class MySingelton
{
    static MySingelton* obj;

    int mvalue ;

    // constructor, copy constructor and assignmenet is made private
    // this gets called only once
    MySingelton()
    {
        cout<<"******** MySingelton Constructor called *********** \n";
    }

public:

    MySingelton(const MySingelton&) = delete;
    MySingelton& operator=(const MySingelton&) = delete;

    static MySingelton* createInstance()
    {

#if 0
// This is using pointers , there is memory leak
// Don't use this method , Thumb rule
        if(obj == nullptr)
            obj = new MySingelton();


#endif

#if 0
// This is for normal case
        return new MySingelton();
#endif

         static MySingelton myinstance;
         return &myinstance;

    }

    void setValue(int val)
    {
        mvalue = val;
    }

    void display()
    {
        cout<<"MySingelton display mvalue = "<<mvalue<<endl;
    }

     ~ MySingelton()
    {
        cout<<"destructor called \n";
    }

};

MySingelton* MySingelton::obj = nullptr;

int main()
{
    MySingelton* ptrA = MySingelton::createInstance();
    ptrA->setValue(20);
    ptrA->display();
    cout<<"address of ptr = "<<&ptrA<<endl;

    MySingelton* ptrB = MySingelton::createInstance();
    ptrB->display();

    cout<<"address of ptr2 = "<<&ptrB<<endl;

#if 0
// Not required , since we are not using raw pointers
    delete ptrA;
    delete ptrB;
#endif

    return 0;
}
