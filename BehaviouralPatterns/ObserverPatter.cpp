#include <iostream>
#include <set>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
class IObsserver
{
public:
    virtual void onDataChanged(string&) = 0;
    virtual ~IObsserver() { }

};

class MyAppA : public IObsserver
{
public:
    void onDataChanged(string& data) {
        cout<<"MyAppA = "<<data<<endl;
    }

};

class MyAppB : public IObsserver
{
public:
    void onDataChanged(string& data) {
        cout<<"MyAppB = "<<data<<endl;
    }
};

////////////////////////////////////////////////////////////

class Observable
{
public:
    void addsubsriber(IObsserver *ptrObser)
    {
        listner.insert(ptrObser);
    }

    void removesubscriber(IObsserver *ptrObser)
    {
        listner.erase(ptrObser);
    }

    void datachanged(string data)
    {
        for (auto &iter : listner) {
            iter->onDataChanged(data);
        }
    }

private:
    std::set<IObsserver*> listner;
};

int main()
{
    MyAppA *ptrA = new MyAppA();
    MyAppB *ptrb = new MyAppB();

    Observable observableobj ;
    observableobj.addsubsriber(ptrA);
    observableobj.addsubsriber(ptrb);

    // It will notify to both Apps
    observableobj.datachanged("Hello Jagdish ");

    observableobj.removesubscriber(ptrA);

    // It will notify to  App B
    observableobj.datachanged("Hello Jagdish ");


    delete ptrA;
    delete ptrb;

    return 0;
}
