// 矩形的Z字形扫描
#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()
{
    int matrix_rows;
    cin >> matrix_rows;
    vector<vector<int>> matrix(matrix_rows, vector<int>(matrix_rows));

    
    for (auto& i : matrix)
    {
        for (auto& j : i)
        {
            cin >> j;
        }
    }

    // n行的正方形 有2n - 1条扫描线 或者说对角线
    for (int i = 0; i < 2 * matrix_rows - 1; i++)
    {
        // 确定每条扫描线的起点
        array<int, 2> start_point = i < matrix_rows ?array<int,2>{i, 0} : array<int,2>{matrix_rows - 1, i - matrix_rows + 1};
        // 从起点开始扫描，偶数行从左下角到右上角输出 奇数行从右上角往左下角输出
        // 1.首先定义存放扫描线上的点的数据结构
        vector<int> points;
        while (start_point[0] >= 0 and start_point[0] < matrix_rows  and start_point[1] >= 0 and start_point[1] < matrix_rows )
        {
            points.push_back(matrix[start_point[0]][start_point[1]]);
            start_point[0]--;
            start_point[1]++;
        }
        // 2.确定扫描顺序
        if (i & 1)
        {
            // 奇数行
            for (auto i = points.rbegin(); i != points.rend(); i++)
            {
                cout << *i << " ";
            }
        }
        else
        {
            // 偶数行
            for (int i : points)
            {
                cout << i << " ";
            }
        }
    }

    return 0;
}