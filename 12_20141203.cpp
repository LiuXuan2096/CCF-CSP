#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Record
{
    int type;  // buy->0  sell->1  cancel->2
    double price;
    int stocks;
    bool cancel;  // true->取消  false->未取消

    Record(int t, int s, double p = 0, bool cancel = false)
        : type(t)
        , stocks(s)
        , price(p)
        , cancel(cancel)
        {}
};

vector<Record> record_list = {Record(-1, 0)};

bool cmp (int a, int b)
{
    return record_list[a].price > record_list[b].price;
}

int main()
{
    vector<int> buys, sells;
    string type;
    double price;
    int cancelled_line;
    int stocks;
   
    
    while (cin >> type)
    {
        if (type == "cancel")
        {
            cin >> cancelled_line;
            record_list.push_back(Record(2, 0));
            record_list[cancelled_line].cancel = true;
        }
        else
        {
            cin >> price >> stocks;
            record_list.push_back(Record(type == "buy" ? 0 : 1, stocks, price, false));
        }
    }

    long long sellS = 0; // 卖单的总股数
    long long buyS = 0;
    double ans_price = 0;
    long long ans_stocks = 0;
    // 把买单和卖单的下标分别放到对应的数组中
    for (int i = 0; i < record_list.size(); i++)
    {
        if (!record_list[i].cancel and record_list[i].type == 0)
        {
            buys.push_back(i);
        }
        else if (!record_list[i].cancel and record_list[i].type == 1)
        {
            sells.push_back(i);
            sellS += record_list[i].stocks;
        }
    }

    // 把卖单和买单的价格  按照出价从高到低排序
    sort(buys.begin(), buys.end(), cmp);
    sort(sells.begin(), sells.end(), cmp);

    for (int i = 0, j = 0; i < buys.size(); i++)
    {
        buyS += record_list[buys[i]].stocks;
        // cout << "xuan: " <<  "price: " <<record_list[buys[i]].price << " stocks: " <<  record_list[buys[i]].stocks << endl;
        for (; j < sells.size() and record_list[sells[j]].price > record_list[buys[i]].price; j++)
        {

         // cout << "xuan: "  << "price: " << record_list[sells[j]].price << " stocks: " << record_list[sells[j]].stocks << endl;
        sellS -= record_list[sells[j]].stocks;
        // cout << "85: xuan: " << " sellS: " << sellS << endl;

        }
        if (ans_stocks < min(buyS, sellS))
        {
            // cout << "xuan: " << " buyS: " << buyS << " sellS: " << sellS << endl;
            ans_stocks = min(buyS,sellS);
            ans_price = record_list[buys[i]].price;
            // cout << "xuan: " << " price: " << record_list[buys[i]].price << endl;
        }
    }

    cout << fixed << setprecision(2) << ans_price << " " << ans_stocks;

    return 0;
}