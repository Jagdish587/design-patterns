#include <iostream>
using namespace std;

//////////////// First Lets design RX /////////////////////////
/// \brief main
/// \return

class Light
{
public:
    void on() {
        cout<<"Light is ON \n ";
    }

    void off() {
        cout<<"Light if OFF \n";
    }
};

class Fan
{
public:

    void on() {
        cout<<"Fan is ON \n";
    }

    void Off() {
        cout<<"Fan is OFF \n";
    }
};

////////////////////////////////////////// End of RX /////////////////////////////////////

class ICommand
{
public:
    virtual void execute() = 0;
    virtual ~ ICommand() {}
};

class LightOncCommand: public ICommand
{
public:

    LightOncCommand()
    {
        mptr = new Light();
    }

    void execute() {
        mptr->on();
    }

    ~ LightOncCommand() {
        delete mptr;
    }

private:
    Light* mptr;
};

class LightOFFComand: public ICommand
{
public:

    LightOFFComand()
    {
        mptr = new Light();
    }

    void execute() {
        mptr->off();
    }

    ~ LightOFFComand()
    {
        delete mptr;
    }

private:
    Light* mptr;

};

class FanOnCommand : public ICommand
{
public:
    FanOnCommand()
    {
        mptr = new Fan();
    }

    void execute()
    {
        mptr->on();
    }

    ~ FanOnCommand()
    {
        delete mptr;
    }

public:
    Fan* mptr;
};

class FanOffCommand : public ICommand
{
public:

    FanOffCommand()
    {
        mptr = new Fan();
    }

    void execute()
    {
        mptr->Off();
    }

    ~ FanOffCommand()
    {
        delete mptr;
    }

private:
    Fan* mptr ;
};

//////////////// END //////////////////////////////////////////////////////

class RemoteControl
{
public:

    RemoteControl()
    {

    }

    void setCommandType(ICommand* ptrcom)
    {
        this->Iptr = ptrcom;
    }

    void execueCommand()
    {
        Iptr->execute();
    }

private:
    ICommand*  Iptr ;
};

int main()
{
    // Type of Command
    ICommand* PtrLightONCommand = new LightOncCommand();

    // This is Invoker
    RemoteControl* rmcPtr = new RemoteControl();
    rmcPtr->setCommandType(PtrLightONCommand);
    rmcPtr->execueCommand();

    ICommand* PtrFanOffCommand =  new FanOffCommand();

    RemoteControl* remcPtr = new RemoteControl();
    remcPtr->setCommandType(PtrFanOffCommand);
    remcPtr->execueCommand();

    delete PtrLightONCommand;
    delete rmcPtr;
    delete remcPtr;
    delete PtrFanOffCommand;


    return 0;
}
