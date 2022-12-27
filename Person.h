
#pragma once
#include <bits/stdc++.h>
using namespace std;
class Person
{
private:
    string name;
    string cmnd;
    int age;
    string sdt;
public:
    Person(string = "", string = "", int = 0, string = "");
    Person(const Person&);
    ~Person();
    void Show();
    void Show(ofstream&);
    void setName(string);
    string getName();
    void setCmnd(string);
    string getCmnd();
    void setAge(int);
    int getAge();
    void setSdt(string);
    string getSdt();
    friend ostream& operator<<(ostream&, const Person&);
    friend istream& operator>>(istream&, Person&);
};