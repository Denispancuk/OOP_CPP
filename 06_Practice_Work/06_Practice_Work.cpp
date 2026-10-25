#include <iostream>
using namespace std;
class Time {
    int years;
    int months;
    long long days;
    long long hours;
    long long minutes;
    long long seconds;
public:
    Time()
    {
        years = 0;
        months = 0;
        days = 0;
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    explicit Time(long long seconds)
    {
        SecondsToTime(seconds);
    }
    Time(int years, int months , long long days, long long hours, long long minutes, long long seconds)
    {
        if (years < 0)
            this->years = 0;
        else
            this->years = years;
        if (months < 0 || months > 12)
            this->months = 0;
        else
            this->months = months;
        if (days < 0 || days > 32)
            this->days = 0;
        else
            this->days = days;
        if (hours < 0 || hours > 23)
            this->hours = 0;
        else
            this->hours = hours;
        if (minutes < 0 || minutes > 59)
            this->minutes = 0;
        else
            this->minutes = minutes;
        if (seconds < 0 || seconds > 59)
            this->seconds = 0;
        else
            this->seconds = seconds;
    }
    void SecondsToTime(long long total) {
        this->years = total / 31536000;
        total %= 31536000;
        this->months = total / 2592000;
        total %= 2592000;
        this->days = total / 86400;
        total %= 86400;
        this->hours = total / 3600;
        total %= 3600;
        this->minutes = total/60 ;
        this->seconds = total % 60;
    }
    int TimeToSeconds()const {
        return ((years * 31536000)+(months * 2592000) + (days * 86400) + (hours * 3600) + (minutes * 60) + (seconds));
    }
    void Print()const {
        cout << endl;
        cout << "Date: ";
        if (days > 9)
        {
            cout << days << '/';
            if (months > 9)
            {
                cout << months << '/';
            }
            else {
                cout << '0' << months << '/';
            }
            cout << years << "   ";
        }
        else {
            cout << '0' << days << '/';
            if (months > 9)
            {
                cout << months << '/';
            }
            else {
                cout << '0' << months << '/';
            }
            cout << years << "   ";
        }



        if (hours > 9)
        {
            cout << "Time: " << hours << ':';
            if (minutes > 9)
            {
                cout << minutes << ':';
                if (seconds > 9)
                {
                    cout << seconds << endl;
                }
                else {
                    cout << '0' << seconds << endl;
                }
            }
            else
            {
                cout << '0' << minutes << ':';
                if (seconds > 9)
                {
                    cout << seconds << endl;
                }
                else {
                    cout << '0' << seconds << endl;
                }
            }
        }
        else {
            cout << "Time: 0" << hours << ':';
            if (minutes > 9)
            {
                cout << minutes << ':';
                if (seconds > 9)
                {
                    cout << seconds << endl;
                }
                else {
                    cout << '0' << seconds << endl;
                }
            }
            else
            {
                cout << '0' << minutes << ':';
                if (seconds > 9)
                {
                    cout << seconds << endl;
                }
                else {
                    cout << '0' << seconds << endl;
                }
            }
        }
    }
#pragma region Binary Operators
    Time operator +(const Time& other) {
        int res = TimeToSeconds() + other.TimeToSeconds();
        Time res2;
        res2.SecondsToTime(res);
        return res2;
    }
    Time operator -(const Time& other) {
        int res = TimeToSeconds() - other.TimeToSeconds();
        Time res2;
        res2.SecondsToTime(res);
        return res2;
    }
    Time operator *(const Time& other) {
        int res = TimeToSeconds() * other.TimeToSeconds();
        Time res2;
        res2.SecondsToTime(res);
        return res2;
    }
    Time operator /(const Time& other) {
        int check = other.TimeToSeconds();
        int res;
        if (check == 0)
            res = TimeToSeconds() / 1;
        else 
            res = TimeToSeconds() / check;
        Time res2;
        res2.SecondsToTime(res);
        return res2;
    }
    Time operator +=(const Time& other) {
        long long res = TimeToSeconds() + other.TimeToSeconds();
        SecondsToTime(res);
        return *this;
    }

    Time operator -=(const Time& other) {
        long long res = TimeToSeconds() - other.TimeToSeconds();
        SecondsToTime(res);
        return *this;
    }
    Time operator =(const Time& other) {
        this->years = other.years;
        this->months = other.months;
        this->days = other.days;
        this->hours = other.hours;
        this->minutes = other.minutes;
        this->seconds = other.seconds;
        return *this;
    }
    Time operator *=(const Time& other) {
        this->years *= other.years;
        this->months *= other.months;
        this->days *= other.days;
        this->hours *= other.hours;
        this->minutes *= other.minutes;
        this->seconds *= other.seconds;
        return *this;
    }
    Time operator %=(const Time& other) {
        this->years %= other.years;
        this->months %= other.months;
        this->days %= other.days;
        this->hours %= other.hours;
        this->minutes %= other.minutes;
        this->seconds %= other.seconds;
        return *this;
    }
#pragma endregion
#pragma region Bool Operators
    bool operator > (const Time& other) {
        return (TimeToSeconds() > other.TimeToSeconds());
    }
    bool operator < (const Time& other) {
        return !(*this > other);
    }
    bool operator >= (const Time& other) {
        return (TimeToSeconds() >= other.TimeToSeconds());
    }
    bool operator <= (const Time& other) {
        return (TimeToSeconds() <= other.TimeToSeconds());
    }
    bool operator == (const Time& other) {
        return (this->hours == other.hours && this->minutes == other.minutes && this->seconds == other.seconds);
    }
    bool operator != (const Time& other) {
        return !(*this == other);
    }


#pragma endregion
#pragma region Uno operators
    Time operator -- (int) { //Не працювала програма, ШІ сказав потрібно вказати тип для постфіксу(t--)
        long long res = TimeToSeconds();
        res--;
        SecondsToTime(res);
        return *this;
    }
    Time operator -- () {
        long long res = TimeToSeconds();
        res--;
        SecondsToTime(res);
        return *this;
    }
    Time operator ++ (int) {
        long long res = TimeToSeconds();
        res++;
        SecondsToTime(res);
        return *this;
    }
    Time operator ++ () {
        long long res = TimeToSeconds();
        res++;
        SecondsToTime(res);
        return *this;
    }
#pragma endregion

    

};
int main()
{
        Time t1;
        t1.Print();
        
        Time t2(50000000);
        t2.Print();

        Time t3(0, 5, 15, 12, 30, 45);
        t3.Print();


        Time t5 = t2 - t3;
        t5.Print();

        Time t6 = t2 * Time(2);
        t6.Print();

        Time t7 = t2 / Time(10);
        t7.Print();

        Time t8 = t2;
        t8.Print();


        t8 -= t3;
        t8.Print();
        cout << endl;
        cout << (t2 > t3) << endl;
        cout << (t2 < t3) << endl;
        cout << (t2 >= t3) << endl;
        cout << (t2 <= t3) << endl;
        cout << (t2 == t3) << endl;
        cout << (t2 != t3) << endl;

        t3++;
        t3.Print();

        t3--;
        t3.Print();

}
