#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

void Print(const vector<double>& Matrix)
{
    for (auto i : Matrix) cout << i << " ";
    cout << endl;
}

void Print1()
{
    cout << '+' << string(32, '-') << '+' << string(10, '-')
         << '+' << string(20, '-') << '+' << string(19, '-')<< '+' << endl;
}

void Print2()
{
    Print1();
    cout << '|' << " Cost of the package Economy+TV " << '|' << "  Speed   "
         << '|' << "  Support service   " << '|' << "  Service quality  "<<'|' << endl;
    Print1();
    cout <<'|'<<string(14,' ')<<"  6  "<<string(13,' ');
    cout <<'|'<<string(3,' ')<<"  8  "<<string(2,' ');
    cout <<'|'<<string(8,' ')<<"  4  "<<string(7,' ');
    cout <<'|'<<string(8,' ')<<"  2  "<<string(6,' ')<<'|'<<endl;
    Print1();
}

void Print3()
{
    cout << '+' << string(10, '-') << '+' << string(10, '-')
         << '+' << string(10, '-') << '+' << string(10, '-')
         << '+' << string(10, '-') << '+'<< endl;
}

void Print4(const vector<vector<double>>& Matrix)
{
    Print3();
    cout <<'|'<<string(10,' ')<<'|'<<string(3,' ')<<"  1  "<<string(2,' ');
    cout <<'|'<<string(3,' ')<<"  2  "<<string(2,' ');
    cout <<'|'<<string(3,' ')<<"  3  "<<string(2,' ');
    cout <<'|'<<string(3,' ')<<"  4  " <<string(2,' ')<<'|'<< endl;
    Print3();
    cout <<'|'<<string(3,' ') <<"  A  "<<string(2,' ')<<'|';
    for (int i = 0; i < 4; i++)
    {
        cout <<string(4,' ')<<fixed << setprecision(2) << Matrix[0][i] <<string(2,' ')<<'|';
    }
    cout<<endl;
    Print3();
    cout <<'|'<<string(3,' ') <<"  B  "<<string(2,' ')<<'|';
    for (int i = 0; i < 4; i++)
    {
        cout <<string(4,' ')<< Matrix[1][i] <<string(2,' ')<<'|';
    }
    cout<<endl;
    Print3();
    cout <<'|'<<string(3,' ') <<"  C  "<<string(2,' ')<<'|';
    for (int i = 0; i < 4; i++)
    {
        cout <<string(4,' ')<< Matrix[2][i] <<string(2,' ')<<'|';
    }
    cout<<endl;
    Print3();
    cout <<'|'<<string(3,' ') <<"  D  "<<string(2,' ')<<'|';
    for (int i = 0; i < 4; i++)
    {
        cout <<string(4,' ')<< Matrix[3][i] <<string(2,' ')<<'|';
    }
    cout<<endl;
    Print3();
    cout << endl;
}

void Print5()
{
    cout << '+' << string(10, '-') << '+' << string(10, '-')
         << '+' << string(10, '-') << '+' << string(10, '-')
         << '+' << string(10, '-') << '+' << string(10, '-')
         << '+' << string(10, '-') << '+'<< endl;
}

void Print6(const vector<vector<double>>& Matrix, const vector<double>& sum, const vector<double>& standardized_amount)
{
    Print5();
    cout <<'|'<<string(10,' ')<<'|'<<string(3,' ')<<"  A  "<<string(2,' ' );
    cout <<'|'<<string(3,' ')<<"  B  "<<string(2,' ');
    cout <<'|'<<string(3,' ')<<"  C  "<<string(2,' ');
    cout <<'|'<<string(3,' ')<<"  D  "<<string(2,' ');
    cout <<'|'<<string(3,' ')<<" Sum  "<<string(1,' ');
    cout <<'|'<<string(2,' ')<<"NormSum"<<string(1,' ')<<'|'<<endl;
    Print5();

    cout <<'|'<<string(3,' ') <<"  A  "<<string(2,' ')<<'|';
    for (int i = 0; i <= 3; i++)
        cout << string(3,' ')<<fixed << setprecision(2) << setw(5) << Matrix[0][i] <<string(2,' ')<<'|';
    cout << string(3,' ')<<setw(5) << sum[0] <<string(2,' ')<<'|'<<string(4,' ')<< standardized_amount[0]<<string(2,' ')<<'|'<<endl;
    Print5();

    cout <<'|'<<string(3,' ') <<"  B  "<<string(2,' ')<<'|';
    for (auto i = 0; i <= 3; i++)
        cout << string(3,' ')<< setw(5) << Matrix[1][i] <<string(2,' ')<<'|';
    cout << string(3,' ')<<setw(5) << sum[1] <<string(2,' ')<<'|'<<string(4,' ')<< standardized_amount[1]<<string(2,' ')<<'|'<<endl;
    Print5();

    cout <<'|'<<string(3,' ') <<"  C  "<<string(2,' ')<<'|';
    for (auto i = 0; i <= 3; i++)
        cout << string(3,' ')<< setw(5) << Matrix[2][i] <<string(2,' ')<<'|';
    cout << string(3,' ')<<setw(5) << sum[2] <<string(2,' ')<<'|'<<string(4,' ')<< standardized_amount[2]<<string(2,' ')<<'|'<<endl;
    Print5();

    cout <<'|'<<string(3,' ') <<"  D  "<<string(2,' ')<<'|';
    for (auto i = 0; i <= 3; i++)
        cout << string(3,' ')<< setw(5) << Matrix[3][i] <<string(2,' ')<<'|';
    cout << string(3,' ')<<setw(5) << sum[3] <<string(2,' ')<<'|'<<string(4,' ')<< standardized_amount[3]<<string(2,' ')<<'|'<<endl;
    Print5();
}
