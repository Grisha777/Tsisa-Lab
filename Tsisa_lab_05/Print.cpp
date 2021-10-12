#include <iostream>
#include <random>
#include <algorithm>
#include <iomanip>
using namespace std;

void Print1()
{
    cout << '+' << string(15, '-') << '+' << string(18, '-')<< '+'  << endl;
}

void Print2()
{
    Print1();
    cout << '|' <<string(5,' ')<< "  X  " <<string(5,' ');
    cout << '|' <<string(5,' ')<< "  y(x)  "<<string(5,' ')<< '|' <<endl;
    Print1();
    for (auto i = 0; i < N; i++)
    {
        cout <<'|'<<string(5,' ')<<fixed << setprecision(2)<<couple1[i].first << string(5,' ');
        cout <<'|'<<string(7,' ')<<fixed << setprecision(2)<<couple1[i].second <<string(7,' ')<<'|';
        cout<<endl;
        Print1();
    }
    cout <<endl;
}

void Print3()
{
    Print1();
    cout << '|' <<string(5,' ')<< "  X  " <<string(5,' ');
    cout << '|' <<string(5,' ')<< "  y(x)  "<<string(5,' ')<< '|' <<endl;
    Print1();
    for (auto i = 0; i < N; i++)
    {
        cout <<'|'<<string(5,' ')<<fixed << setprecision(2)<<couple[i].first << string(5,' ');
        cout <<'|'<<string(7,' ')<<fixed << setprecision(2)<<couple[i].second <<string(7,' ')<<'|';
        cout<<endl;
        Print1();
    }
    cout <<endl;
}