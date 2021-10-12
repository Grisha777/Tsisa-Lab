#include <iostream>
#include <random>
#include "Metod_Dichotomy.cpp"
#include "Metod_Fibonacci.cpp"
#include "Print.cpp"

using namespace std;


int main()
{
    //int N=12;
    const double c = -4, d = 2, A = 6, a = -3, b = 3;
    auto Step = (b - a)/N;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> random(-0.5, 0.5);
    int count = 0;
    for (double x = a; x < b; x += Step)
    {
        auto t = c * x + d + A * random(gen);
        auto t0 = c * x + d;
        couple[count] = {x, t};
        couple1[count] = {x, t0};
        count++;
    }
    cout<<"Variant 9"<<endl<<"Function: y=c*x+d, interval: ["<< a <<","<< b <<"], c=-4, d=2"<< endl<<endl;
    cout<<"Results without noise"<<endl;
    Print2();
    cout << "Results with noise A = " << A<<endl;
    Print3();
    double w1 = Metod_Dichotomy(a, b, c);
    double w0 = Metod_Fibonacci(a, b, d);
    cout <<"w0 = " << w0 << ", " <<"w1 = "<< w1 << endl;
}


