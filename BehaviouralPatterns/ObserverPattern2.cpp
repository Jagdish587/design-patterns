#include <iostream>
#include <set>

using namespace std;

class IDataChnagedListner {
 public:
    IDataChnagedListner() = default;

    virtual void onStatusChnaged() = 0;
};



class MyFramework {
    MyFramework(const MyFramework&) = delete;
    MyFramework& operator=(const MyFramework&) = delete;

 public:
    MyFramework() = default;

    static MyFramework* createInstance() {
        static MyFramework myinstance;
        return &myinstance;
    }

    void addListner(IDataChnagedListner* listner) {
        mylistner.insert(listner);
    }

    void removeListner(IDataChnagedListner* listner) {
         mylistner.erase(listner);
    }

    void statusChanged() {
        for (auto &iter : mylistner) {
            iter->onStatusChnaged();
        }
    }

 private:
    std::set<IDataChnagedListner*> mylistner;
};
//////////////////////////// Apps ///////////////

class MyApplicationA : public IDataChnagedListner{
 public:
    MyApplicationA() {
        myframeworkobj = MyFramework::createInstance();
        myframeworkobj->addListner(this);
    }

    void onStatusChnaged() {
        cout <<"My MyApplicationA Status Changed  \n";
    }

    virtual  ~MyApplicationA() {
    }

 private:
    MyFramework* myframeworkobj;
};


class MyApplicationB : public IDataChnagedListner{
 public:
    MyApplicationB() {
        myframeworkobj = MyFramework::createInstance();
        myframeworkobj->addListner(this);
    }

    void onStatusChnaged() {
        cout <<"My MyApplicationB Status Changed  \n";
    }

    virtual  ~MyApplicationB() {
    }

 private:
    MyFramework* myframeworkobj;
};




int main() {
    MyApplicationA* myapp = new MyApplicationA();

    MyApplicationB* myappB = new MyApplicationB();

    MyFramework* myframeworkobj = MyFramework::createInstance();

    myframeworkobj->statusChanged();

    delete myapp;
    delete myappB;

    return 0;
}
