#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "ss.cpp"

double Utopia(const vector<vector<double>>& Matrix, const int& vector_criteria)
{
    vector<double> matrix(4);
    for (int i = 0; i < 4; i++)
        matrix[i] = Matrix[i][vector_criteria];
    sort(begin(matrix), end(matrix));
    return matrix[3];
}

double Metod_Pareto(const vector<vector<double>>& Matrix, const double& a, const double& b, const int& criteria_a, const int& criteria_b, const int& criteria_c)
{
    double z;
    z = sqrt(pow(a - Matrix[criteria_c][criteria_a], 2) + pow(b - Matrix[criteria_c][criteria_b], 2));
    return z;
}