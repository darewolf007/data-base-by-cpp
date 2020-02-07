#include <iostream>
#include <string>

using namespace std;
//using namespace string;
int main()
{
    int i = 42;
    cout << i << endl;
    string s("hello");
    for (auto &c : s)
        c = toupper(c);
    cout << s << endl;
    int c = 2;
    getchar();
    return 0;
}
