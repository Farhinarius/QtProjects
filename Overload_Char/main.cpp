// Overload_function.cpp
// options;

//////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

////////////////////////////////////////////

/***************************************/
void repchar()  /// - write on the console symbol "*" 45 times
{
    for (int i = 0;i < 45;i++)
    {
      cout << "*";
    }
}
/***************************************/
void repchar(int k)  /// - write on the console symbol "=" k times
{
    for (int i = 0;i < k;i++)
    {
     cout << "=";
    }
}
//======================================//
void repchar(int k, char ch)  /// - write on the console symbol "ch" k times
{
    for (int i = 0;i < k;i++)
    {
     cout << ch;
    }
}
//-------------------------------------//
////////////////////////////////////////


int main()
{
    cout << "\n I am beautiful" << endl;
    repchar(); cout << endl;
    cout << "You are beautiful" << endl;
    repchar(30); cout << endl;
    cout << "We are beautiful" << endl;
    repchar(40,'+'); cout << endl;
    cout << "This is overload,brother !!!" << endl;
    repchar(100,'$');
    return 0;
}
