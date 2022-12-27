#include "List.h"
#include "Date.h"
#include <iostream>
using namespace std;
List::List()
{
    this->p = nullptr;
    this->length = 0;
}
List::List(Thuephong *t, int len)
{
    this->length = len;
    this->p = new Thuephong[this->length];
    for (int i = 0; i < this->length; i++)
    {
        *(this->p + i) = *(t + i);
    }
}
List::List(const List &t)
{
    this->length = t.length;
    this->p = new Thuephong[this->length];
    for (int i = 0; i < this->length; i++)
    {
        *(this->p + i) = *(t.p + i);
    }
}
List::~List()
{
    delete[] this->p;
}
List List::operator=(const List &t)
{
    this->length = t.length;
    this->p = new Thuephong[this->length];
    for (int i = 0; i < this->length; i++)
    {
        *(this->p + i) = *(t.p + i);
    }
    return *this;
}
int List::getLength()
{
    return this->length;
}
void List::ShowRoom()
{
    system("cls");
    if (this->length == 0)
        cout << "\tKhong Co Phong Trong He Thong\n";
    else
    {
        cout << "\tDanh sach xe trong he thong\n";
        cout << char(213);
        for (int i = 0; i <= 79; i++)
        {
            if (i == 20 || i == 40 || i == 60 || i == 80)
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

            if (i == 20 || i == 40 || i == 60 || i == 80)
            {
                cout << char(216);
            }
            cout << char(205);
        }
        cout << char(181) << endl;
        for (int i = 0; i < this->length; i++)
        {
            // cout << "Motobike " << i + 1 << ":\n";
            (*(p + i)).room.showTable();
        }
        cout << char(212);

        for (int i = 0; i <= 79; i++)
        {

            if (i == 20 || i == 40 || i == 60 || i == 80)
            {
                cout << char(207);
            }
            cout << char(205);
        }
        cout << char(190) << endl;
    }
}
bool List::CheckCmnd(Person &per)
{
    int count = 0;
    for (int i = 0; i < this->length; i++)
    {
        if ((per.getCmnd()).compare((this->p + i)->Per.getCmnd()) == 0)
        {
            count++;
        }
    }
    if (count == 1)
        return true;
    return false;
}
void List::UpdateRental()
{
    system("cls");
    int cmp = 0;
    Date d;
    cout << "\t\t-----------Chao Mung Ban Den Voi Dich Vu Thue Xe-----------\n\n";
    this->ShowRoomUser();
    if (this->length > 0)
    {
        int mp;
        while (1)
        {
            try
            {
                cout << "Nhap Ma Phong Ban Muon Thue: ";
                cin >> mp;
                if (!cin)
                    throw string("");
                else
                    break;
            }
            catch (...)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n\t\t\tNhap Sai! Vui Long Nhap Lai!\n";

                continue;
            }
        }

        int k = indexOf(mp);
        if ((this->p + k)->room.getIsRend() != 1 && k >= 0 && k < this->length)
        {
            cin.ignore();
            cin >> ((this->p + k)->Per);
            if (CheckCmnd((this->p + k)->Per))
            {

                cin >> d;

                (*(this->p + k)).DateRented = d;
                cout << "Nhap So Ngay Muon Thue: ";
                cin >> (this->p + k)->NumberOfDaysRented;
                (*(this->p + k)).room.setIsRend(1);
                system("cls");

                (this->p + k)->ShowTT();
            }
            else
            {
                Person p;
                (this->p + k)->Per = p;
                cout << "\t Ban Dang Thue Phong Khac Trong He Thong\n";
            }
        }
        else
        {
            do
            {
                cout << "\tPhong Da Duoc Nguoi Khac Thue Hoac Khong Co Trong He Thong\n";
                cmp = 1;
                cout << "Ban Co MUon Thue Xe Khac Khong? y/n\n";
                char ch;
                cout << "Nhap Lua Chon: ";
                cin >> ch;
                if (ch == 'n')
                {
                    cout << "CAM ON QUY KHACH\n";
                    cmp = 0;
                }
                else
                {
                    int mp;
                    while (1)
                    {
                        try
                        {
                            cout << "Nhap Ma Phong Ban Muon Thue: ";
                            cin >> mp;
                            if (!cin)
                                throw string("");
                            else
                                break;
                        }
                        catch (...)
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\n\t\t\tNhap Sai! Vui Long Nhap Lai!\n";

                            continue;
                        }
                    }

                    int k = indexOf(mp);
                    if ((this->p + k)->room.getIsRend() != 1 && k >= 0 && k < this->length)
                    {
                        cin.ignore();
                        cin >> ((this->p + k)->Per);
                        if (CheckCmnd((this->p + k)->Per))
                        {
                            cin >> d;
                            (*(this->p + k)).DateRented = d;
                            cout << "Nhap So Ngay Muon Thue: ";
                            cin >> (this->p + k)->NumberOfDaysRented;
                            (*(this->p + k)).room.setIsRend(1);
                            system("cls");

                            (this->p + k)->ShowTT();
                        }
                        else
                        {
                            Person p;
                            (this->p + k)->Per = p;
                            cout << "\t Ban Dang Thue Phong Khac Trong He Thong\n";
                        }
                    }
                }
            } while (cmp);
        }
    }
}
void List::ShowRoomUser()
{
    if (this->length == 0)
    {
        cout << "\tKhong Co Phong Trong He Thong\n";
    }
    else
    {
        int j = 1;
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
        for (int i = 0; i < this->length; i++)
        {
            if (!(*(this->p + i)).room.getIsRend())
            {
                // cout << "roombike " << j << ":" << endl;
                // (*(this->p + i)).room.Show();
                (*(this->p + i)).room.ShowTB();
                j++;
            }
        }
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
}

long long List::SumMoney()
{
    long long sum = Thuephong::tong;
    for (int i = 0; i < this->length; i++)
    {
        if ((this->p + i)->NumberOfDaysRented > 0)
            sum += (*(this->p + i)).getMonney();
    }
    return sum;
}
int List::indexOf(int maphong)
{
    for (int i = 0; i < this->length; i++)
    {
        if (maphong == (this->p + i)->room.getMaphong())
            return i;
    }
    return -1;
}
void List::FindUser(int maphong, int &q)
{
    q = 0;
    int k = 0;
    for (int i = 0; i < this->length; i++)
    {
        if (maphong == (*(this->p + i)).room.getMaphong())
        {
            q = 1;
            (*(this->p + i)).room.ShowRoomOf1();
        }
    }
    if (q == 0)
        cout << "Khong Tim Thay Phong Trong He Thong! Vui Long Kiem Tra Lai!\n";
}
void List::BillUser(int maphong, int &q)
{
    int k = indexOf(maphong);
    q = 0;
    if (k != -1)
    {
        if ((*(this->p + k)).room.getIsRend() != 0)
        {
            (*(this->p + k)).ShowBill();
            q = 1;
        }
        if (q == 0)
            cout << "Phong Chua Duoc Thue!\n";
    }
    else
        cout << "Khong Tim Thay Phong Trong He Thong! Vui Long Kiem Tra Lai!\n";
}
void List::DeleteRoom(int maphong)
{
    int k = indexOf(maphong);
    if (k != -1)
    {
        if (!(*(this->p + k)).room.getIsRend())
        {
            Thuephong *tmp = new Thuephong[this->length];
            for (int i = 0; i < this->length; i++)
            {
                *(tmp + i) = *(this->p + i);
            }
            delete[] p;
            this->p = new Thuephong[this->length];
            for (int i = 0; i < k; i++)
            {
                *(this->p + i) = *(tmp + i);
            }
            for (int i = k; i < this->length - 1; i++)
            {
                *(this->p + i) = *(tmp + i + 1);
            }
            this->length--;
            system("cls");
            cout << "Xoa Phong Thanh Cong!\n";
        }
        else
            cout << "Phong Dang Duoc Thue!\n";
    }
    else
        cout << "Khong Co Phong Trong He Thong! Vui Long Kiem Tra Lai!\n";
}
Date getTimeNow()
{
    time_t now = time(0);
    tm *dt = localtime(&now);
    Date d(dt->tm_mday, dt->tm_mon + 1, dt->tm_year + 1900);
    return d;
}
void List::UpdateAfter(int n)
{
    if (n < 0 || n > this->length)
        cout << "So Luong Phong Nhap Vao Khong Hop Le!\n";
    else
    {
        for (int i = 0; i < n; i++)
        {
            int maphong;
            while (1)
            {
                try
                {
                    cout << "Nhap Ma Phong Muon Tra: ";
                    cin >> maphong;
                    if (!cin)
                        throw string("");
                    else
                        break;
                }
                catch (...)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\t\t\tNhap Sai! Vui Long Nhap Lai!\n";

                    continue;
                }
            }

            int k = indexOf(maphong);
            if (k == -1)
                cout << "Phong Khong Co Trong He Thong! Vui Long Kiem Tra Lai!\n";
            else
            {
                if ((*(this->p + k)).room.getIsRend() != 0)
                {
                    Date d = getTimeNow();
                    (*(this->p + k)).DatePaid = d;
                    Clear(*(this->p + k));
                    (*(this->p + k)).room.setIsRend(0);
                }
                else
                    cout << "Phong Co Trong He Thong Va Chua Duoc Thue!\n";
            }
        }
    }
}
void List::UpdateAfter1(int mp)
{

    int k = indexOf(mp);
    if (k == -1)
        cout << "Phong Khong Co Trong He Thong! Vui Long Kiem Tra Lai!\n";
    else
    {
        if ((*(this->p + k)).room.getIsRend() != 0)
        {
            Date d = getTimeNow();
            (*(this->p + k)).DatePaid = d;
            Clear(*(this->p + k));
            (*(this->p + k)).room.setIsRend(0);
        }
        else
            cout << "Phong Co Trong He Thong Va Chua Duoc Thue!\n";
    }
}

void List::Clear(Thuephong &tra)
{
    Person a;
    tra.Per = a;
    tra.NumberOfDaysRented = 0;
    Date d;
    tra.DateRented = tra.DatePaid = d;
}
void List::UpdateDateAfter(int maphong)
{
    Date n;
    int k = indexOf(maphong);
    if ((this->p + k)->room.getIsRend() == 0)
    {
        cout << "Phong Chua Duoc Thue!\n";
        return;
    }
    if (k == -1)
    {
        cout << "Ma Phong Khong Dung\n";
        return;
    }
    cout << "Nhap Ngay Thue Muon Cap Nhat \n";
    cin >> n;
    (this->p + k)->DateRented = n;
    cout << "\nCap Nhat Thanh Cong\n";
}
void List::UpdatePrice(int maphong)
{
    int n;
    int k = indexOf(maphong);
    if (k != -1)
    {
        if ((this->p + k)->room.getIsRend())
            cout << "\n----Phong Dang Duoc Thue! Khong Thue Cap Nhat Gia!----\n";
        else
        {
            cout << "Nhap Gia Xe Muon Cap Nhat: ";
            cin >> n;
            (this->p + k)->room.setPrice(n);
            cout << "\n------Cap Nhat Thanh Cong------\n";
        }
    }
    else
        cout << "\n------Phong Khong Co Trong He Thong! Vui Long Kiem Tra Lai!------\n";
}
void List::EnterRoom()
{
    ifstream in;
    string filename;
    do
    {
        cout << "Nhap Ten File: ";
        cin >> filename;
        filename += ".txt";
        in.open(filename);
        if (in.fail())
        {
            cout << "File Not Found: " << filename << endl;
            continue;
        }
        else
        {
            int n;
            in >> n;
            this->length = n;
            this->p = new Thuephong[this->length];
            in.ignore();
            for (int i = 0; i <= length; i++)
            {
                Room r;
                in >> r;
                (*(this->p + i)).room = r;
                (*(this->p + i)).NumberOfDaysRented = 0;
            }
            system("cls");
            cout << "\t---Upload from file Room---\n";
            break;
        }
    } while (1);
    in.close();
}
void List::EnterUser()
{
    ifstream in;
    string filename;
    do
    {
        cout << "Nhap Ten File: ";
        cin >> filename;
        filename += ".txt";
        in.open(filename);
        if (in.fail())
        {
            cout << "File Not Found: " << filename << endl;
            continue;
        }
        else
        {
            int n;
            in >> n;
            in.ignore();
            for (int i = 0; i < n; i++)
            {
                Person per;
                int day;
                in >> per;
                in >> day;
                in.ignore();
                Date d2 = getTimeNow();
                (*(this->p + i)).Per = per;
                (*(this->p + i)).DateRented = d2;
                (*(this->p + i)).NumberOfDaysRented = day;
                (*(this->p + i)).room.setIsRend(1);
            }
            system("cls");
            cout << "\t---Uploat from file Person---\n";
            break;
        }
    } while (1);
    in.close();
}

void List::ShowRented()
{
    if (this->length == 0)
    {
        cout << "\tKhong Co Phong Trong He Thong\n";
    }
    else
    {
        int j = 1;
        cout << char(213);
        for (int i = 0; i <= 164; i++)
        {
            if (i == 25 || i == 45 || i == 65 || i == 85 || i == 105 || i == 125 || i == 145 || i == 165)
            {
                cout << char(209);
            }
            cout << char(205);
        }
        cout << char(184) << endl;
        char _char = char(179);
        cout << _char << setw(25) << "TEN KHACH HANG  ";
        cout << _char << setw(20) << "SO CMND/HO CHIEU  ";
        cout << _char << setw(20) << "SO DIEN THOAI   ";
        cout << _char << setw(20) << "MA PHONG        ";
        cout << _char << setw(20) << "LOAI PHONG     ";
        cout << _char << setw(20) << "GIA(VND)    ";
        cout << _char << setw(20) << "NGAY THUE    ";
        cout << _char << setw(20) << "SO NGAY THUE   ";

        cout << _char << endl;
        cout << char(198);
        for (int i = 0; i <= 164; i++)
        {
            if (i == 25 || i == 45 || i == 65 || i == 85 || i == 105 || i == 125 || i == 145 || i == 165)
            {
                cout << char(216);
            }
            cout << char(205);
        }
        cout << char(181) << endl;
        for (int i = 0; i < this->length; i++)
        {
            if ((*(this->p + i)).room.getIsRend())
            {
                // cout << "Customer " << j << endl;

                // (*(this->p + i)).Show();
                (*(this->p + i)).ShowTB();

                j++;
            }
        }
        cout << char(212);
        for (int i = 0; i <= 164; i++)
        {
            if (i == 25 || i == 45 || i == 65 || i == 85 || i == 105 || i == 125 || i == 145 || i == 165)
            {
                cout << char(207);
            }
            cout << char(205);
        }
        cout << char(190) << endl;
        if (j == 1)
        {
            cout << "\tChua Co Khach Thue\n";
        }
    }
}