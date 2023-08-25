#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int visitor_count, visitor_no;
    unordered_map<int, int> visitor;
    cin >> visitor_count;
    while (visitor_count--)
    {
        cin >> visitor_no;
        visitor[visitor_no]++;
        cout << visitor[visitor_no]<< " ";
    }

    return 0;
}