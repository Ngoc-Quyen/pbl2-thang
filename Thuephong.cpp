#include "Thuephong.h"

Thuephong::Thuephong()
{
}

Thuephong::Thuephong(const Person &p, const Room &r, const Date &d1, const Date &d2, int day)
{
    this->Per = p;
    this->room = r;
    this->DateRented = d1;
    this->DatePaid = d2;
    this->NumberOfDaysRented = day;
}

Thuephong::~Thuephong()
{
}
int Thuephong::tong = 0;
void Thuephong::Show()
{
    this->Per.Show();
    this->room.Show();
    this->DateRented.ShowRented();
    this->DatePaid.ShowPaid(this->NumberOfDaysRented);
    if(this->getMonney() > 0)
    {
        cout << "\t\tSo ngay thue: " << this->NumberOfDaysRented << endl;
        // cout << "\t\t\t\t\tSo tien thanh toan: " << this->getMonney() << endl;
    }
}

// void Thuephong::Show(ofstream &o)
// {
//     this->Per.Show(o);
//     this->Room.Show(o);
//     this->DateRented.ShowRented(o);
//     this->DatePaid.ShowPaid(o);
//     if(this->getMonney() > 0)
//     {
//         cout << "\t\t\t\t\tSo ngay thue: " << this->NumberOfDaysRented << endl;
//         cout << "\t\t\t\t\tSo tien thanh toan: " << this->getMonney() << endl;
//     }
// }

long long Thuephong::getMonney()
{
    return this->room.getPrice() * this->NumberOfDaysRented;
}
void Thuephong::ShowTT()
{
    cout << "Thong Tin Thue Phong Cua Quy Khach\n";
    this->Per.Show();
    this->room.Show();
    this->DateRented.ShowRented();
    cout << "\t\tSo ngay thue: " << this->NumberOfDaysRented << endl;
    cout << "\t\tTong tien thanh toan: " << this->getMonney() << endl;
    cout << "Cam on quy khach da su dung dich vu cua chung toi\n";
}
void Thuephong::ShowTB()
{
    char _char = char(179);
    cout << _char << setw(25) << this->Per.getName() + " ";
    cout << _char << setw(20) << this->Per.getCmnd() + " ";
    cout << _char << setw(20) << this->Per.getSdt() + " ";
    cout << _char << setw(20) << this->room.getMaphong();
    if (this->room.getClassify() == 0)
        cout << _char << setw(20) << "NORMAL";
    else
        cout << _char << setw(20) << "VIP";
    cout << _char << setw(19) << this->room.getPrice() << " ";
    cout << _char << setw(11) << this->DateRented.getDay() << "/" << this->DateRented.getMonth() << "/" << this->DateRented.getYear() << " ";

    cout << _char << setw(19) << this->NumberOfDaysRented << " ";
    
    cout << _char << endl
         << char(195);
    for (int i = 0; i <= 164; i++)
    {
        if (i == 25 || i == 45 || i == 65 || i == 85 || i == 105 || i == 125 || i == 145 || i == 165)
        {
            cout << char(197);
        }
        cout << char(196);
    }
    cout << char(180) << endl;
}
void Thuephong::ShowBill()
{
    cout << "-------------Hoa Don Cua Ban-------------\n";
    this->Per.Show();
    this->room.Show();
    this->DateRented.ShowRented();
    this->DateRented.ShowPaid(this->NumberOfDaysRented);
    cout << "\t\tSo ngay thue: " << this->NumberOfDaysRented << endl;
    cout << "\t\tTong tien thanh toan: " << this->getMonney() << endl;
    Thuephong::tong += this->getMonney();

    cout << "-------------Hen Gap Lai----------------" << endl;
}