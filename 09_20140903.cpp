#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main()
{
    string pattern;
    int flag, str_count;
    string match_str;

    cin >> pattern;
    cin >> flag >> str_count;

    regex r(pattern, flag == 0 ? regex::icase : regex::ECMAScript );

    while (cin >> match_str)
    {
        if (regex_search(match_str, r))
        {
            cout << match_str << endl;
        }
    }

    return 0;
}