#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int row, column;
    cin >> row >> column;
    vector<vector<int>> matrix(row, vector<int>(column));
    for (auto& i : matrix)
    {
        for(auto&j : i)
        {
            cin >> j;
        }
    }

    for (int i = column - 1; i >= 0; i--)
    {
        for (int j = 0; j < row; j++)
        {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}