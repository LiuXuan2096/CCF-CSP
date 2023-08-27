#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dayOfMonth(int year, int month)
{

        if (month == 2 and ((year % 400 == 0) or (year % 4 == 0 and year % 100 != 0)))
        {
            // 润年
            return 29;
        }
    
    return days[month];
}

int determineWeek(int y, int m, int d, int week = 2)
{
    for (int i = 1850; i < y; i++)
    {
        int day_of_year = ((i % 400 == 0) or (i % 4 == 0 and i % 100 != 0)) ? 366 : 365;
        week = (week + day_of_year) % 7;
    }
    for (int i = 1; i < m; i++)
    {
        
        week = (week + dayOfMonth(y, i)) % 7;
    }
    return (week + d - 1) % 7;
//     for (int i = 1850; i < y; ++i)
//     {                                                                        // 检查1850年到y年经历的年份
//         int temp = (i % 400 == 0 || i % 4 == 0 && i % 100 != 0) ? 366 : 365; // 平年有365天，闰年有366天
//         week = (week + temp) % 7;                                            // 更新week
//     }
//     for (int i = 1; i < m; ++i)  {              // 检查1月到m月的月份
//         week = (week + dayOfMonth(y, i)) % 7; // 求出该月有几天，并更新week
//     }
//     return (week + d - 1) % 7;                 // 返回周几
}

int main()
{
    int a, b, c, y1, y2;
    cin >> a >> b >> c >> y1 >> y2;
   
    if (c == 7)
    {
        c = 0;
    }
    // for (int i = y1; i <= y2; ++i)
    // {
    //     int week = determineWeek(i, a, 1);              // 确定i年a月1日是周几
    //     int day = 1 + (c + 7 - week) % 7 + 7 * (b - 1); // 确定i年a月第b个周c是几号
    //     if (day <= dayOfMonth(i, a))                   // 日期小于等于a月最大天数
    //         printf("%04d/%02d/%02d\n", i, a, day);
    //     else
    //         puts("none");
    // }
    //*************************************************************************************
    //cout << determineWeek(2023,8, 27) << endl;
    for (int i = y1; i <= y2; i++)
    {
        int first_day = 1;
        int week = determineWeek(i,a, 1 );
        //cout <<"58 xuan: week:" <<  week << endl;
        int distance = week - c;
        //cout << "59 xuan: distance " << distance << endl; 
        if (distance  < 0)
        {
            first_day -= distance;
        }
        else if (distance == 0)
        {
            first_day = 1;
        }
        else
        {
            //cout << "71 xuan: first_day " << first_day << " c: " << c << "  week:" << week << endl; 
             first_day = first_day + (7 + c - week);
             //cout << "72 xuan: first_day " << first_day << endl;
        }
        //cout << "72 xuan: first_day: " << first_day << endl;
        int week_distance = b - 1;
        //cout << "74 xuan: ans_day: " << first_day + week_distance * 7 << endl;
         if (first_day + week_distance * 7 > dayOfMonth(i, a))
        {
            cout << "none" << endl;
        }
        else 
        {
            int ans_day = first_day + week_distance * 7;
            cout << i << "/" << setw(2) << setfill('0') << a << "/" << setw(2) << setfill('0') << ans_day << endl;
        }


    }

    return 0;
}