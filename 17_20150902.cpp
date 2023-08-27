#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int year;
    int day_no;
    bool is_run_year;
    int ans_month;
    int ans_day;
    int day_of_months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day_of_months_run[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> days_sum;
    vector<int> days_sum_run;
    int sum = 0;
    int sum_run = 0;
    for (int i = 0; i < 13; i++)
    {
        sum += day_of_months[i];
        days_sum.push_back(sum);

        sum_run += day_of_months_run[i];
        days_sum_run.push_back(sum_run);
    }
    cin >> year >> day_no;
    // cout << "21 xuan: " << " year:"<< year << "  day_no:" << day_no << endl;
    
    is_run_year = ((year % 400 == 0) or (year % 100 != 0 and year % 4 == 0));
    // cout << "24 xuan: is_run_year:" << is_run_year << endl;
    
    int day_no_copy = day_no;
    for (int i = 1; i < 13; i++)
    {
        if(is_run_year)
        {
            day_no -= day_of_months_run[i];

            if (day_no == 0)
            {
                ans_month = i;
                ans_day = day_of_months_run[i];
                break;
                //cout << "43 xuan: " << " i:" <<i <<" ans_day: " << day_of_months_run[i];
            }
            if (day_no < 0)
            {
                ans_month = i;
                ans_day = day_no_copy - days_sum_run[i - 1];
                //cout << "49 xuan: "<< " i:" << i << " ans_day: " << ans_day;
                break;
            }
        }
        else
        {
            day_no -= day_of_months[i];

            if (day_no == 0)
            {
                ans_month = i;
                ans_day = day_of_months[i];
                break;
            }
            if (day_no < 0)
            {
                ans_month = i;
                ans_day = day_no_copy - days_sum[i - 1];
                break;
            }
        }

        
    }
    cout << ans_month << endl;
    cout << ans_day;

    return 0;
}