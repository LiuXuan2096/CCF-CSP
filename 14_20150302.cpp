#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int,int> a,  pair<int, int> b)
{
    return tie(a.second,b.first) > tie(b.second, a.first);
}

int main()
{
    int count;
    int num;
    unordered_map<int,int> num_map;
  
    cin  >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> num;
        num_map[num]++;
    }
    vector<pair<int, int>> num_vector(num_map.begin(), num_map.end());
    sort(num_vector.begin(), num_vector.end(), cmp);
    for (auto i : num_vector)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}