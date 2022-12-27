#include "Thuephong.h"
#include <bits/stdc++.h>
using namespace std;


class List 
{
protected:
    Thuephong *p;
    int length;
public:
    List();
    List(Thuephong*, int);
    List(const List&);
    ~List();
    List operator = (const List&);
    int getLength();
    void ShowRoom(); //Danh sach phong trong he thong
    void UpdateRental(); //Thue Phong
    void EnterRoom(); //Nhap  phong bang file
    void EnterUser(); //Nhap khach hang thue bang file;
    void ShowRoomUser(); //danh sach phong chua thue
    void ShowCustomer(); //danh sach phong da duoc thue
    long long SumMoney(); //tong doanh thu
    int indexOf(int = 0);
    void FindUser(int, int&); //tim kiem theo ma phong
    void BillUser(int, int&);
    void DeleteRoom(int); //xoa phong ra khoi he thong
    void UpdateAfter(int); //tra phong theo so luong
    void UpdateAfter1(int); 
    void Clear(Thuephong&); //tra phong
    void UpdateDateAfter(int); //cap nhat ngay thue cua khach
    void UpdatePrice(int); //cap nhat gia phong
    bool CheckCmnd(Person&);
    void ShowRented();

};