#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

////////////////////////////// Report ////////////////////////////////////////////////

// This is Report Interface Class

class Report
{
public:
    virtual Report* clone() = 0;
    virtual void display() = 0;

    virtual ~Report() {}

};


class ExcelReport : public Report
{
public:

    Report* ptr;

    Report* clone() {
        ptr = new ExcelReport();
        return ptr;
    }

    void display() {
        cout<<"i am ExcelReport \n";
    }

    ~ ExcelReport() {
        delete ptr;
    }

};


class PPTReport : public Report
{
public:
    Report* ptr ;

    Report* clone() {
        ptr = new PPTReport();
        return ptr;
    }

    void display() {
        cout<<"i am PPTReport \n";
    }

    ~ PPTReport() {
        delete ptr;
    }

};

class WordReport : public Report
{
public:

     Report* ptr ;

    Report* clone() {
        ptr = new WordReport();
        return ptr;
    }

    void display() {
        cout<<"i am WordReport \n";
    }

    ~ WordReport() {
        delete ptr;
    }

};

///////////////////////////// End //////////////////////////////////////////////////////


class ReportMangaer
{
public:
    static Report* rptr1 ;
    static Report* rptr2 ;
    static Report* rptr3 ;

    static void initlize()
    {
        rptr1 = new ExcelReport();
        rptr2 = new PPTReport();
        rptr3 = new WordReport();
    }

    static Report* createReport(int choice) {

        if(choice == 1)
            rptr1->clone();
        else if(choice == 2)
            rptr2->clone();
        else if(choice == 3){
            rptr3->clone();
        }
    }

    ~ ReportMangaer()
    {
        delete rptr1;
        delete rptr2;
        delete rptr3;
    }

};

Report* ReportMangaer::rptr1 = nullptr;
Report* ReportMangaer::rptr2 = nullptr;
Report* ReportMangaer::rptr3 = nullptr;

struct Destruct
{
    void operator()(Report *a) const {
    delete a;
    }
};

int main()
{
    vector<Report*> myReportvector(4);
    int choice;
    int iter =0;

    ReportMangaer::initlize();

    while (true) {
        cout<<"enter your choice 1 or 2 or 3";
        cin>>choice;

        if(choice == 1 || choice == 2 || choice ==3) {
            cout<<"\nentered choice = "<<choice;
            myReportvector[1] = ReportMangaer::createReport(choice);
            myReportvector[1]->display();
        } else
            break;

        iter = iter + 1;
    }

    Destruct dobj;
    // this calls Destruct::operator()
    std::for_each(myReportvector.begin(), myReportvector.end(), dobj);


    return 0;
}
