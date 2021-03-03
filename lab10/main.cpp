#include <QCoreApplication>
#include <vector>
#include <QStack>
#include <iostream>
#include <QTextCodec>
#include <QTextStream>
using namespace std;

template<typename T>
class stek
{
public:
    QStack<T> s;
    void add(T a)
    {
        s.push(a);
    }
    void delet(T a)
    {
        auto z = s.data();

        for (int i = a; i <= 3; i++)
        {
            if ( i < 3)
            {
               z[i] = z[i+1];
            }
            else if (i == 3)
            {

            }
        }
    }
    void vivod1()
    {
        int i = 0;
        while (i != 3)
        {
            cout << s.top() << " ";
            s.pop();
            i++;
        }
    }
    void vivod2()
    {
        int i = 0;
        while (i != 2)
        {
            cout << s.top() << " ";
            s.pop();
            i++;
        }
    }
};

template<typename T>
class sor : public stek<T>
{
public:
    void cort()
    {
        float temp;
        auto z = this->s.data();
        for (int i = 0; i < 2; i++)
        {
                for (int j = 0; j < 3 - i - 1; j++)
                {
                    if (z[j] > z[j + 1])
                    {
                        temp = z[j];
                        z[j] = z[j + 1];
                        z[j + 1] = temp;
                    }
                }
        }
        for (int i = 0; i != 2; i++)
        {
            cout << z[i] << " ";

            //cout << this->s.top() << " ";
            //this->s.pop();
        }
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream outStream(stdout);
    outStream.setCodec(QTextCodec::codecForName("cp866"));

    stek<int> st1;
    stek<float> st2;
    sor<float> st22;

    outStream << QString("Add num to set") << flush;
    cout << endl;

    //добавление целых
    int a1;
    cin >> a1;
    st1.add(a1);
    cin >> a1;
    st1.add(a1);
    cin >> a1;
    st1.add(a1);

    //добавление вещественных
    float a2;
    cin >> a2;
    st2.add(a2);
    st22.add(a2);
    cin >> a2;
    st2.add(a2);
    st22.add(a2);
    cin >> a2;
    st2.add(a2);
    st22.add(a2);

    outStream << QString("Stack created") << flush << endl;
    cout << endl;

    int a3;
    outStream << QString("remove count with num ") << flush;
    cin >> a3;
    if (a3 <= 3)
    {
        st1.delet(a3);
    }
    else
    {
        st2.delet(a3);
    }
    cout << endl;

    outStream << QString("new stack: ") << flush << endl;
    if (a3 <= 3)
    {
        st1.vivod2();
        st2.vivod1();
    }
    else
    {
        st1.vivod1();
        st2.vivod2();
    }

    cout << endl << endl;
    outStream << QString("Sorted single counts ") << flush << endl;
    st22.cort();

    return a.exec();
}
