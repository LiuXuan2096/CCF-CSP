#include <iostream>
#include <set>
#include <array>
using namespace std;

int main()
{
    int count;
    int x1, y1, x2, y2;
    set<array<int, 2>> matrixs;
    cin >> count;
    while (count > 0)
    {
        cin >>x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x2; i++)
        {
            for (int j = y1; j < y2; j++)
            {
                matrixs.insert({i, j});
            }
        }
        count--;
    }
    cout << matrixs.size();

    return 0;
}