#include<iostream>
#include<fstream>
#include<string>
#include "Studentc.h"

using namespace std;

int main()
{
    string teststr;
    
    cout<<"Please enter the name of the test Student: ";
    cin>>teststr;
    const char* str="testBoy";
    double db[]={90,50,80,80};
    StudentC test(str,db,4);
    cout<<test;
    ofstream ofile;
    ofile.open("StudentInf.txt");
    ofile<<test;

    return 0;
}