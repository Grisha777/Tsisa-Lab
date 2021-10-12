#include "Function.cpp"

double Metod_Dichotomy(double a, double b, double c)
{
    const double Epsilon = 0.1;
    const double Delta = 0.01;
    double X_LEFT_LIMIT, X_RIGHT_LIMIT, Y_LEFT_LIMIT, Y_RIGHT_LIMIT;
    do
    {
        X_LEFT_LIMIT = 0.5 * (b + a) - Delta;
        X_RIGHT_LIMIT = 0.5 * (b + a) + Delta;
        Y_LEFT_LIMIT = Function(c, X_LEFT_LIMIT);
        Y_RIGHT_LIMIT = Function(c, X_RIGHT_LIMIT);
        if (Y_LEFT_LIMIT > Y_RIGHT_LIMIT)
        {
            a = X_LEFT_LIMIT;
        }
        else{
            b = X_RIGHT_LIMIT;
        }

    } while ((b - a) > Epsilon);

    return (a + b) / 2;
}