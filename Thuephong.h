#include"Date.h"
#pragma once
#include"Person.h"
#include"Room.h"
#include<bits/stdc++.h>
using namespace std;

class Thuephong
{
private:
    Person Per;
    Room room;
    Date DateRented; //ngay thue
    Date DatePaid; //ngay thanh toan
    int NumberOfDaysRented; //so ngay da thue
    static int tong;
public:
    Thuephong();
    Thuephong(const Person&, const Room&, const Date&, const Date&, int = 0);
    ~Thuephong();
    void Show();
    // void Show(ofstream&);
    long long getMonney();
    void ShowBill();
    void ShowTT();
    // Thuephong& operator = (const Thuephong&);
    friend class List;
    void ShowTB();

};