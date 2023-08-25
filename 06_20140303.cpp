#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
    string s;
    string t;  // 存放参数
    string command;  // 存放命令
    int rows;  // 表示行数
    vector<int> type(128);   // 值为命令类型 所以为字母对应的编码值 0表示非法选项 1表示无参选项 2表示带参选项
    
   
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        type[s[i]] = 1;
        if (i + 1 < s.size() and s[i+1] == ':')
        {
            type[s[i]] = 2;
        }
    }
    cin >> rows;
    cin.get();  // 吸收换行符
    for (int i = 1; i <= rows; i++)
    {
        map<char, string> ans; // 存放命令选项和参数
        getline(cin, s);
        stringstream sstream(s);
        sstream >> s;  // 消耗掉命令行工具对应的字符串
        while (sstream >> command)
        {
            if (command.size() == 2 and command[0] == '-' and type[command[1]] == 1)
            {
                ans[command[1]] = "";  // 说明该字符串为无参命令
            }
            else if (command.size() == 2 and command[0] == '-' and type[command[1]] == 2 and sstream >> t)
            {
                ans[command[1]] = t;  // 说明该字符串为带参命令
            }
            else
            {
                // 非法字符 停止处理
                break;
            }
        }
        cout << "Case " << i << ":";
        for (auto &i : ans)
        {
            cout << " -" << i.first;
            if (!i.second.empty())
            {
                cout << " " << i.second;
            }
        }
        cout << endl;
    }

    return 0;
}