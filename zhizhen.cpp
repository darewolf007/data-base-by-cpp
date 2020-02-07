#include <iostream>
#include <string>

using namespace std;
//using namespace string;
int changef(int *p)
{
    int i = 100;
    *p = i;
    return *p;
}
int main()
{
    int i = 42;
    i = changef(&i);
    cout << i << endl;
    string s("hello");
    for (auto &c : s)
        c = toupper(c);
    cout << s << endl;
    int c = 2;
    getchar();
    return 0;
}
