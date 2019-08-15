#include"Studentc.h"

#include<iostream>
#include<valarray>
#include<string>

using namespace std;
ostream& StudentC::arr_out(ostream& os)const
{
    int lim=scores.size();
    if(lim>0)
    {
        for(int i=0;i<lim;i++)
        {
            os<<scores[i]<<" ";
            //一行五个
            if(i%5==0)
            cout<<"\n";
        }
    }
    else cout<<"No scores stored.";
    return os;
}
double StudentC::Average() const
{
    return scores.sum()/scores.size();
}
const string StudentC::Name() const{
    return this->name;
}
double& StudentC::operator[](int n)
{
    return scores[n];
}
double StudentC::operator[](int n) const
{
    return scores[n];
}
//friends
istream& operator>>(istream& is,StudentC& stu)
{
    is>>stu.name;
    return is;
}
istream& getline(istream& is,StudentC& stu)
{
    //is.getline(stu.name);
    getline(is,stu.name);
    return is;
}
ostream& operator<<(ostream& os,StudentC& stu)
{
    cout<<"Scores for Student "<<stu.Name()<<" :\n";
    stu.arr_out(os);
    return os;
}