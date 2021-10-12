#include <iostream>
#include <random>


#include <utility>

using namespace std;

int N = 12;
vector<pair<double, double>> couple(12);
vector<pair<double, double>> couple1(12);

double Function(double c, double d)
{
    double Z = 0;
    for (auto i = 0; i < N; i++)
    {
        auto x = couple[i].first;
        auto t = couple[i].second;
        double y = c * x + d;
        Z = Z + (y - t) * (y - t);
    }
    return Z;

}
double Function_1(double c, double d)
{
    double h = 0;
    for (auto i = 0; i < N; i++)
    {
        auto x = couple1[i].first;
        auto t0 = couple1[i].second;
        double y = c * x + d;
        h = h + (y - t0) * (y - t0);
    }
    return h;
}