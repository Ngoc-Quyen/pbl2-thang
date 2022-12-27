#include "Date.h"

Date::Date(int day, int month, int year)
    :day(day), month(month), year(year)
{
}

Date::Date(const Date& d)
{
    this->day = d.day;
    this->month = d.month;
    this->year = d.year;
}

Date::~Date()
{
}

void Date::ShowRented()
{
    cout  << "\t\tNgay thue: " << this->day << "/" 
        << this->month << "/" << this->year << endl;
}

// void Date::Showrented(ofstream& o)
// {
//     o << "\t\t\t\t\t Ngay thue: " << this->day << "/" 
//         << this->month << "/" << this->year << endl;
// }

void Date::ShowPaid(int number)
{
    for(int i = 0; i < number; i++)
        this->NextDay();
    if(this->year != 0)
        cout << "\t\tNgay tra: " << this->day << "/" 
        << this->month << "/" << this->year << endl;
}

// void Date::ShowPaid(ofstream& o)
// {
//     o << "\t\t\t\t\t Ngay tra: " << this->day << "/" 
//         << this->month << "/" << this->year << endl;
// }

ostream& operator<<(ostream& dip, const Date& tag)
{
    dip << "\t\t Ngay: " << tag.day << "/"
        << tag.month << "/" << tag.year << endl;
        return dip;
}

istream& operator>>(istream& dip, Date& tag)
{
    cout << setw(20) << "Nhap lan luot ngay, thang, nam: ";
    dip >> tag.day >> tag.month >> tag.year;
    while (tag.month < 1 || tag.month > 12)
    {
        cout << setw(20) << "Nhap thang sai roi kia thang ngu\n";
        cout << setw(20) << "Nhap lai thang: ";
        dip >> tag.month;
    }
    while (tag.day > tag.DayMonth())
    {
        cout << setw(20) << "Nhap ngay sai roi kia thang ngu\n";
        cout << setw(20) << "Nhap lai ngay: ";
        dip >> tag.day;
    }
    return dip;
}
Date Date::getTimeNow()
{
    time_t now = time(0);
    tm *dt = localtime(&now);
    Date d(dt->tm_mday, dt->tm_mon + 1, dt->tm_year + 1900);
    return d;
}
bool Date::IsYear(int y)
{
    if (y % 400 == 0)
        return true;
    else if (y % 100 != 0 && y % 4 == 0)
        return true;
    else
        return false;
}
int Date::DayMonth()
{
    if (this->IsYear(this->year) && this->month == 2)
        return 29;
    else
        switch (this->month)
        {
        case 2:
            return 28;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        case 0:
            return 0;
            break;
        }
    return 0;
}
void Date::NextDay()
{
    int y = this->year;
    int m = this->month;
    int d = this->day;
    if (this->day <= this->DayMonth())
    {
        d = this->day + 1;
        if (this->month != 12 && this->day == this->DayMonth())
        {
            d = 1;
            m = this->month + 1;
        }
        else if (this->month == 12 && this->day == this->DayMonth())
        {
            d = 1;
            y = this->year + 1;
            m = 1;
        }
        else if (this->month == 2)
        {
            if (this->IsYear(this->year))
            {
                if (this->day == 29)
                {
                    d = 1;
                    m = this->month + 1;
                }
            }
            else if (this->day == 28)
                d = 1;
            m = this->month + 1;
        }
    }
    this->setDay(d);
    this->setMonth(m);
    this->setYear(y);
}
void Date::setDay(int d)
{
    this->day = d;
}
int Date::getDay()
{
    return this->day;
}
void Date::setMonth(int m)
{
    this->month = m;
}
int Date::getMonth()
{
    return this->month;
}
void Date::setYear(int y)
{
    this->year = y;
}
int Date::getYear()
{
    return this->year;
}