#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

struct Win
{
    int num = 0;
    int x1;
    int x2;
    int y1;
    int y2;
};

bool if_function(Win w1,  int x, int y)
{
    return (w1.x1 <= x && w1.y1 <= y && w1.x2 >= x && w1.y2 >= y);
}

int main()
{
    int count_win, count_click;
    cin >> count_win >> count_click;
    list<Win> win_list(count_win);
    int num = 1;
    int x,y;
    // 输入是按从最下层到最顶层的顺序输入的，要用反向迭代器读取
    for (auto i = win_list.rbegin(); i != win_list.rend(); ++i)
    {
        cin >> i->x1 >> i->y1 >> i->x2 >> i->y2;
        i->num = num;
        num++;
    }
    while (count_click--)
    {
        cin >> x >> y;
        auto i = find_if(win_list.begin(), win_list.end(), [x, y](const Win &w)
                         { return (w.x1 <= x && w.y1 <= y && w.x2 >= x && w.y2 >= y); });
        if (i == win_list.end())  // 未找到符合条件的矩形
        {
            cout << "IGNORED" << endl;
        }
        else 
        {
            win_list.push_front(*i);
            cout << i->num << endl;
            win_list.erase(i);
        }
    }
    return 0;
}