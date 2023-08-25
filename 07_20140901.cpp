#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int count;
    vector<int> nums;
    int ans = 0;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (abs(nums[i] - nums[j]) == 1)
            {
                ans++;
            }
        }
    }
    cout << ans;

    return 0;

}