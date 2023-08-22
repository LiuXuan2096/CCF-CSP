#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int matrix_count = 0;
    vector<int> matrix_height;
    int ans = 0;  // 存放最终答案的变量
    cin >> matrix_count;
    for (int i = 0; i < matrix_count; i++)
    {
        int temp;
        cin >> temp;
        matrix_height.push_back(temp);
    }
    for (int i = 0; i < matrix_count; i++)
    {
        int left = i, right = i;
        // 找左边第一个高度小于自己的矩形
        while (left >= 0 && matrix_height[left] >= matrix_height[i])
        {
            left--;
        }
        // 找右边第一个高度小于自己的矩形
        while (right <= matrix_count && matrix_height[right] >= matrix_height[i])
        {
            right++;
        }
        int current_area = (right - left - 1) * matrix_height[i];  // 当前矩形所能形成的最大矩形的面积
        ans = ans >= current_area ? ans : current_area;  // 更新ans
    }
    cout << ans;
}