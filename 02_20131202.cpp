#include <iostream>
#include <cctype>

using namespace std;
using ll = long long;
int main()
{
    string isbn;
    ll count = 1, id = 0;
    int flag = 0;
    char  shi_bie_ma;
    cin >> isbn;
    for (int i = 0; i < 11; i++)
    {
        if (isdigit(isbn[i]))
        {
            int num = isbn[i] - '0';
            id = (num * count) + id;
            count++;
        }
    }
    flag = id % 11;
    if (flag == 10)
    {
        shi_bie_ma = 'X';
    }
    else
    {
        shi_bie_ma = '0' + flag;
    }

    if (isbn.back() == shi_bie_ma)
    {
        cout << "Right";
    }
    else
    {
        isbn.back() = shi_bie_ma;
        cout << isbn;
    }
}