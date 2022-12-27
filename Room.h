
#pragma once
#include<bits/stdc++.h>
using namespace std;

class Room
{
private:
    int maphong;
    int tinhtrang;
    // string classify;
    int classify;

    int price;
public:
    Room(int = 0, int = 0, int = 0, int = 0);
    Room(const Room&);
    ~Room();
    void Show();
    void Show(ofstream&);
    friend ostream& operator<<(ostream&,const Room&);
    friend istream& operator>>(istream&, Room&);
    int getPrice();
    int getIsRend();
    void setIsRend(int);
    void ShowTB();
    int getMaphong();
    int getClassify();
    void setPrice(int);
    void ShowTB1();
    void showTable();
    void ShowRoomOf1();
};