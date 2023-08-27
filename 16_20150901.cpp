#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int count;
    int num;
    
    int ans = 1;
    vector<int> nums;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> num;
        nums.push_back(num);
    }
    int last_num = nums[0];
    for (auto i : nums)
    {
        if (i != last_num)
        {
            ans++;
        }
        last_num = i;
    }
    cout << ans;

    return 0;
}