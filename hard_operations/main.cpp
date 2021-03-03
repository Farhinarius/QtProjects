#include <iostream>

using namespace std;

int main()
{
    double i=3;
    double j=3;
    int n=3;
    int m=3;
    if (++i*5 > j/3 && n % 3 < ++m % 3)
    {
        cout << "\n All right" << endl;
        cout << i << endl;
        cout << j << endl;
        cout << n % 3 << endl;
        cout << m % 3 << endl;
    }

}
