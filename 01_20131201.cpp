/*

*/
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

using ll = long long;
bool cmp(const pair<ll, ll> &p1, const pair<ll, ll> &p2);
 int main()
{


    ll count, temp;
    map<ll, ll> Map;
    // receiving input
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> temp;
        ++Map[temp];
    }



    long long result = max_element(Map.begin(), Map.end(), cmp)->first;
    cout << result;
}

bool cmp(const pair<ll, ll> &p1, const pair<ll, ll> &p2)
{
    return p1.second < p2.second;
}
