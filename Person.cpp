#include "Person.h"
Person::Person(const Person &p)
{
    Person(p.name, p.cmnd, p.age, p.sdt);
}

Person::Person(string name, string cmnd, int age, string sdt)
    : name(name), cmnd(cmnd), age(age), sdt(sdt)
{
}

Person::~Person()
{
}

void Person::Show()
{
    if(this->getAge() != 0)
    {
        cout  << "\t\tTen khach hang thue: " << this->name << endl;
        cout  << "\t\tTuoi: " << this->age << endl;
        cout  << "\t\tCMND: " << this->cmnd << endl;
        cout  << "\t\tSDT: " << this->sdt << endl; 
    }
}

// void Person::Show(ofstream& o)
// {
//     if(this->getAge() != 0)
//     {
//         o << setw(20) << " Ten khach hang thue: " << this->name << endl;
//         o << setw(20) << " CMND: " << this->cmnd << endl;
//         o << setw(20) << " Tuoi: " << this->age << endl;
//         o << setw(20) << " SDT: " << this->sdt << endl; 
//     }
// }

void Person::setName(string name)
{
    this->name = name;
}

string Person::getName()
{
    return this->name;
}

void Person::setCmnd(string cmnd)
{
    this->cmnd = cmnd;
}

string Person::getCmnd()
{
    return this->cmnd;
}

void Person::setAge(int age)
{
    this->age = age;
}

int Person::getAge()
{
    return this->age;
}

void Person::setSdt(string sdt)
{
    this->sdt = sdt;
}

string Person::getSdt()
{
    return this->sdt;
}

ostream &operator<<(ostream &dip, const Person &tag)
{
    dip << "----------------------------------------------THONG TIN----------------------------------------------" << endl;
    dip << "\t\t" << " Ten khach hang: " << tag.name << endl;
    dip << "\t\t" << " CMND: " << tag.cmnd << endl;
    dip << "\t\t" << " Tuoi: " << tag.age << endl;
    dip << "\t\t" << " SDT: " << tag.sdt << endl ;
    return dip;
}

istream &operator>>(istream &dip, Person &tag)
{
    cout << "\t\t Nhap ten khach hang: ";
    getline(dip, tag.name);
    cout << "\t\t Nhap CMND: ";
    getline(dip, tag.cmnd);
    cout << "\t\t Nhap Tuoi: ";
    dip >> tag.age;
    cout << "\t\t Nhap SDT: ";
    dip.ignore();
    getline(dip, tag.sdt);
    return dip;
}