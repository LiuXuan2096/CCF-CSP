#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long num;
    int ans = 0;
    cin >> num;
    string num_str = to_string(num);
    for (char ch : num_str)
    {
        int temp = ch - '0';
        ans += temp;
    }
    cout << ans;
}