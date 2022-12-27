#include "List.h"
#include <windows.h>
#include <iostream>
// #include"Thuephong.h"
#include <fstream>
#include <vector>
using namespace std;

bool ASC(int a, int b)
{
    return a < b;
}
bool DES(int a, int b)
{
    return a > b;
}
void Menu()
{
    cout << "\t------------------------------------------------------------------------"
            "----------------------------------------------------------------------------"
            "-----------------------------"
         << endl;
    cout << "\t\t1. Nhap danh sach phong vao he thong"
         << "\t\t\t\t\t\t|\t\t2. Nhap danh sach khach thue vao he thong" << endl;
    cout << endl;
    cout << "\t\t3. Thue phong"
         << "\t\t\t\t\t\t\t\t\t|\t\t4. Hien Thi " << endl;
    cout << endl;
    cout << "\t\t5. Tim kiem phong va xuat thong tin phong"
         << "\t\t\t\t\t|\t\t6. Tong doanh thu cua cua hang" << endl;
    cout << endl;
    cout << "\t\t7. Xoa 1 phong khoi he thong"
         << "\t\t\t\t\t\t\t|\t\t8. Cap nhat danh sach sau khi khach hang tra phong" << endl;
    cout << endl;
    cout << "\t\t9. Cap nhat gia thue phong"
         << "\t\t\t\t\t\t\t|\t\t10. Chinh sua ngay thue xe cua khach hang" << endl;
    cout << endl;
    cout << "\t\t11. Xuat hoa don cua khach theo ma phong"
         << "\t\t\t\t\t|\t\t0. Thoat" << endl;
    cout << endl;
    cout << endl;
    cout << "\t------------------------------------------------------------------------"
            "----------------------------------------------------------------------------"
            "-----------------------------";
    cout << endl;
}
void Page()
{
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t-------------- PBL2: DU AN CO SO LAP TRINH --------------";
    cout << "\n\n\n\n\t\t\t\t\t\t\t\tDE TAI : \tQUAN LI CHO THUE PHONG CUA KHACH SAN\n\n"
         << endl;
    cout << "\n\n\n\n\t\t\t\t\t|---------------------------------------------------------------------------------------------------------------------|";
    cout << "\n\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\tGiang Vien Huong Dan:\t\t\t\tThS.               \t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\tNhom SV Thuc Hien:\t\t\t\tNguyen Duc Thang\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\t\t\t\t\t\t\tDo Dinh Manh\t\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t      |";
    cout << "\n\t\t\t\t\t|---------------------------------------------------------------------------------------------------------------------|\n\n\n";
    cout << endl;
    system("pause");
    system("cls");
}
void Show(List &t)
{
    int cmt, q;
    List tmp;
    do
    {
        Menu();
        while (1)
        {
            try
            {
                cout << "\n\t\t\tNhap lua chon cua ban: ";
                cin >> cmt;
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
        switch (cmt)
        {
        case 1:
        {
            t.EnterRoom();
            system("pause");
        }
        break;
        case 2:
        {
            t.EnterUser();
            system("pause");
        }
        break;
        case 3:
        {
            system("cls");
            t.UpdateRental();
            system("pause");
        }
        break;
        case 4:
        {
            system("cls");
            int cmp;
            cout << "\t\t1. Hien Thi Danh Sach Tat Ca Phong Trong He Thong\n";
            cout << "\t\t2. Hien Thi Danh Sach Phong Chua Duoc Thue\n";
            cout << "\t\t3. Hien Thi Thong Tin Tat Ca Khach Dang Thue Xe\n";
            cout << "\t\t0. Thoat\n";
            while (1)
            {
                try
                {
                    cout << "\n\t\t\tNhap lua chon cua ban: ";
                    cin >> cmp;
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
            while (cmp < 0 || cmp > 3)
            {
                cout << "\t\tLua Chon Khong Phu Hop! Vui Long Nhap Lai!\n";
                while (1)
                {
                    try
                    {
                        cout << "\n\t\t\tNhap lua chon cua ban: ";
                        cin >> cmp;
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
            }
            switch (cmp)
            {
            case 1:
            {
                system("cls");
                t.ShowRoom();
                system("pause");
            }
            break;
            case 2:
            {
                system("cls");
                cout << "\t--------Danh Sach Phong Chua Duoc Thue Trong He Thong--------\n";
                t.ShowRoomUser();
                system("pause");
            }
            break;
            case 3:
            {
                system("cls");
                cout << "\t------Thong Tin Cac Khach Hang Dang Thue Xe------\n";
                t.ShowRented();
                system("pause");
            }
            case 0:
                break;
            default:
                break;
            }
        }
        break;
        case 5:
        {
            system("cls");
            int mp;
            while (1)
            {
                try
                {
                    cout << "Nhap Ma Phong Can Tim: ";
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
            t.FindUser(mp, q);
            system("pause");
        }
        break;
        case 6:
        {
            system("cls");
            cout << "\tTong Doanh Thu: " << t.SumMoney() << endl;
            system("pause");
        }
        break;
        case 7:
        {
            system("cls");
            int mp;
            while (1)
            {
                try
                {
                    cout << "Nhap Ma Phong Ban Muon Xoa: ";
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
            t.DeleteRoom(mp);
            system("pause");
        }
        break;
        case 8:
        {
            int n;
            cout << "\n\t\tNhap so phong can cap nhat la da tra trong he thong: ";
            cin >> n;
            t.UpdateAfter(n);
            system("pause");
        }
        break;
        case 9:
        {
            system("cls");
            t.ShowRoomUser();
            int str;
            while (1)
            {
                try
                {
                    cout << "Nhap Ma Phong : ";
                    cin >> str;
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
            t.UpdatePrice(str);
            system("pause");
        }
        break;
        case 10:
        {
            system("cls");
            t.ShowRented();

            int mp;
            while (1)
            {
                try
                {
                    cout << "Nhap Ma Phong: ";
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
            t.UpdateDateAfter(mp);
            system("pause");
        }
        break;
        case 11:
        {
            system("cls");
            int str;
            while (1)
            {
                try
                {
                    cout << "Nhap Ma Phong Khach Hang Muon Tra Xe Va In Hoa Don: \n";
                    cin >> str;
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

            t.BillUser(str, q);
            if (q != 0)
                t.UpdateAfter1(str);
            system("pause");
        }
        break;
        case 0:
            break;
        default:
            cout << "Lua Chon Khong Hop Le!\n";
            break;
        }
    } while (cmt != 0);
}
int main()
{
    Page();
    List t;
    int key;
    Show(t);
    return 0;
    return 0;
}