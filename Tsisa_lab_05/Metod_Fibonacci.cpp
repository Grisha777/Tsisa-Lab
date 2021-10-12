
#include <random>
#include <algorithm>


using namespace std;

int64_t Fibonacci(const size_t &n)
{
    if (n < 1)
    {
        return 0;
    }
    int64_t f1 = 0 , f2 = 1, fn = 0;
    for ( size_t  i = 1; i < n; ++i )
    {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return fn;
}

double Metod_Fibonacci(double a, double b, double d)
{
    auto x1 = a + Fibonacci(N - 2) * (b - a) / Fibonacci(N);
    auto x2 = a + Fibonacci(N - 1) * (b - a) / Fibonacci(N);
    for (int i = 1; i < N; i++)
    {
        if (Function(d, x1) > Function(d, x2))
        {
            a = x1;
            x1 = x2;
            x2 = b - (x1 - a);
        }
        else
        {
            b = x2;
            x2 = x1;
            x1 = a + (b - x2);
        }
    }
    return (a + b) / 2;
}