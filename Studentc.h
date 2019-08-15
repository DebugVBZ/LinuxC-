#ifndef STUDENTC_H
#define STUDENTC_H

#include<valarray>
#include<string>
#include<iostream>
using namespace std;

class StudentC
{
private:
    
    typedef valarray<double> DbArray;
    //初始化列表应按照类名声明顺序进行初始化
    string name;
    DbArray scores;
    ostream& arr_out(ostream& os) const;
public:
    StudentC():name("Null"),scores(){};
    StudentC(const string& s):name(s),scores(){};
    StudentC(const string& s,int n):name(s),scores(n){};
    explicit StudentC(int n):name("Null"),scores(n){};
    StudentC(const string& s,const DbArray& db):name("Null"),scores(db){};
    StudentC(const char* str,const double *db,int n):name(str),scores(db,n){};
    ~StudentC(){};

    double Average() const;
    const string Name() const;
    //重载操作符时 返回引用的可以用作左值
    double& operator[](int n);
    //重载操作符时 用作右值
    double operator[](int n) const;
    //friends
    friend istream& operator>>(istream& is,StudentC& stu);
    friend istream& getline(istream& is,StudentC& stu);
    friend ostream& operator<<(ostream& os,StudentC& stu);



};
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


#endif