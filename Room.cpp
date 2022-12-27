#include "Room.h"

Room::Room(int maphong, int tinhtrang, int classify, int price)
    : maphong(maphong), tinhtrang(tinhtrang), classify(classify), price(price)
{
}

Room::Room(const Room &r)
{
    this->maphong = r.maphong;
    this->tinhtrang = r.tinhtrang;
    this->classify = r.classify;
    this->price = r.price;
}

Room::~Room()
{
}

void Room::Show()
{
    cout << "\t\tMa phong: " << this->maphong << endl;
    cout << "\t\tLoai phong (VIP | NORMAL): ";
    if (this->classify == 0)
        cout << "NORMAL\n";
    else
        cout << "VIP\n";
    cout << "\t\tGia thue: " << this->price << "dong/Ngay" << endl;
    if (this->tinhtrang == 0)
        cout << "\t\tTinh trang: TRONG" << endl;
    else
        cout << "\t\tTinh trang: DA THUE" << endl;
}

// void Room::Show(ofstream& o)
// {
//     o << "\t\t\t\t\t Ma phong: " << this->maphong << endl;
//     o << "\t\t\t\t\t Loai phong (VIP & NORMAL): " << this->classify << endl;
//     o << "\t\t\t\t\t Gia thue: " << this->price << "dong/Ngay" << endl;
//     if(this->tinhtrang == 0)
//         o << "\t\t\t\t\t Tinh trang: TRONG" << endl;
//     else

//         o << "\t\t\t\t\t Tinh trang: DA THUE" << endl;
// }

ostream &operator<<(ostream &dip, const Room &tag)
{
    dip << "\t\t Ma phong: " << tag.maphong << endl;
    dip << "\t\t Loai phong (VIP | NORMAL): ";
    if (tag.classify == 0)
        dip << "NORMAL\n";
    else
        dip << "VIP\n";
    //<< tag.classify << endl;
    dip << "\t\t Gia thue: " << tag.price << " dong/Ngay" << endl;
    return dip;
}

istream &operator>>(istream &dip, Room &tag)
{
    cout << "\t\t Nhap ma phong: ";
    dip >> tag.maphong;
    cout << "\t\t Nhap loai phong (1.VIP | 2.NORMAL): ";
    dip.ignore();
    // getline(dip, tag.classify);
    dip >> tag.classify;
    cout << "\t\t Nhap gia thue (dong/ngay): ";
    dip >> tag.price;
    dip.ignore();
    tag.tinhtrang = 0;
    return dip;
}

int Room::getPrice()
{
    return this->price;
}
int Room::getIsRend()
{
    return this->tinhtrang;
}
void Room::setIsRend(int tinhtrang)
{
    this->tinhtrang = tinhtrang;
}
int Room::getMaphong()
{
    return this->maphong;
}
void Room::ShowTB()
{
    char _char = char(179);
    cout << _char << setw(20) << this->maphong;
    if (this->getClassify() == 0)
        cout << _char << setw(20) << "NORMAL";
    else
        cout << _char << setw(20) << "VIP";
    cout << _char << setw(19) << this->price << " ";

    cout << _char << endl
         << char(195);
    for (int i = 0; i <= 59; i++)
    {
        if (i == 20 || i == 40 || i == 60)
        {
            cout << char(197);
        }
        cout << char(196);
    }
    cout << char(180) << endl;
}
void Room::ShowTB1()
{
    cout << char(213);
    for (int i = 0; i <= 59; i++)
    {
        if (i == 20 || i == 40 || i == 60)
        {
            cout << char(209);
        }
        cout << char(205);
    }
    cout << char(184) << endl;
    char _char = char(179);
    cout << _char << setw(20) << "MA PHONG       ";
    cout << _char << setw(20) << "LOAI PHONG     ";
    cout << _char << setw(20) << "GIA(VND)     ";
    cout << _char << endl;
    cout << char(198);

    for (int i = 0; i <= 59; i++)
    {
        if (i == 20 || i == 40 || i == 60)
        {
            cout << char(216);
        }
        cout << char(205);
    }
    cout << char(181) << endl;
    this->ShowTB();
    cout << char(212);

    for (int i = 0; i <= 59; i++)
    {
        if (i == 20 || i == 40 || i == 60)
        {
            cout << char(207);
        }
        cout << char(205);
    }
    cout << char(190) << endl;
}
void Room::setPrice(int price)
{
    this->price = price;
}
int Room::getClassify()
{
    return this->classify;
}
void Room::showTable()
{
    char _char = char(179);
    cout << _char << setw(20) << this->maphong;
    if (this->getClassify() == 0)
        cout << _char << setw(20) << "NORMAL";
    else
        cout << _char << setw(20) << "VIP";
    cout << _char << setw(19) << this->price << " ";
    if (this->getIsRend() != 0) 
        cout << _char << setw(20) << "DA THUE ";
    else cout << _char << setw(20) << "TRONG ";
    cout << _char << endl
         << char(195);
    for (int i = 0; i <= 79; i++)
    {
        if (i == 20 || i == 40 || i == 60 || i == 80)
        {
            cout << char(197);
        }
        cout << char(196);
    }
    cout << char(180) << endl;
}
void Room::ShowRoomOf1()
{
    system("cls");
        cout << "\tDanh sach xe trong he thong\n";
        cout << char(213);
        for (int i = 0; i <= 79; i++)
        {
            if (i == 20 || i == 40 || i == 60 || i == 80 )
            {
                cout << char(209);
            }
            cout << char(205);
        }
        cout << char(184) << endl;
        char _char = char(179);
        cout << _char << setw(20) << "MA PHONG        ";
        cout << _char << setw(20) << "LOAI PHONG     ";
        cout << _char << setw(20) << "GIA(VND)      ";
        cout << _char << setw(20) << "TINH TRANG PHONG    ";
        cout << _char << endl;
        cout << char(198);

        for (int i = 0; i <= 79; i++)
        {

            if (i == 20 || i == 40 || i == 60 || i == 80 )
            {
                cout << char(216);
            }
            cout << char(205);
        }
        cout << char(181) << endl;
        this->showTable();
        cout << char(212);

        for (int i = 0; i <= 79; i++)
        {

            if (i == 20 || i == 40 || i == 60 || i == 80 )
            {
                cout << char(207);
            }
            cout << char(205);
        }
        cout << char(190) << endl;
}