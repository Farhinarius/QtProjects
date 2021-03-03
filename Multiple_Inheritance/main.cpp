// Multiple_Inheritance;
// Polimorfo_parametra;

/////////////////////////////////

#include <iostream>
using namespace std;

/////////////////////////////////
class Car
{
protected:
    float body;
public:
    Car(float a):body(a)
    {}
};
////////////////////////////////
class Ferrari : public Car
{
protected:
    float power;
public:
    Ferrari(float a,float b): Car(a),power(b)
    {}
    void show_car()
    {
        cout << "Body: " << body << endl;
        cout << "Power: " << power << endl;
    }
};
////////////////////////////////
class Ferrari_F430 : public Ferrari
{
private:
    float style;
public:
    Ferrari_F430(float a,float b, float c): Ferrari(a,b), style(c)
    {}
    void show_car()
    {
        cout << "Body: " << body << endl;
        cout << "Power: " << power << endl;
        cout << "Style: " << style << endl;
    }
};

////////////////////////////////
int main()
{
    // cout << " The Fastest " << endl;

    /// Ferrari 1
    Ferrari Object_F1(1,400);
    Object_F1.show_car();
    cout << endl;

    /// Ferrari 2
    Ferrari_F430 Object_F2(1,430,25);
    Object_F2.show_car();
    cout << endl;

    return 0;
}







