#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

vector<double> norma(const vector<double>& Matrix)
{
    vector<double> matrix(4);
    double s = 0;
    for (auto i : Matrix)
        s += i;
    for (int i = 0; i < 4; i++)
        matrix[i] = Matrix[i] / s;
    return matrix;
}

vector<vector<double>> norma(const vector<vector<double>>& Matrix)
{
    vector<double> sum(4);
    vector<vector<double>> matrix(4, vector<double>(4));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            sum[i] += Matrix[j][i];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            matrix[j][i] = Matrix[j][i] / sum[i];
    return matrix;
}

void sort(vector<vector<double>>& Matrix)
{
    double t;
    for (auto i = 0; i < 4; i++)
        for (auto j = 0; j <= 3; j++)
            for (auto c = j; c <= 3; c++)
                if (Matrix[j][i] > Matrix[c][i])
                {
                    t = Matrix[j][i];
                    Matrix[j][i] = Matrix[c][i];
                    Matrix[c][i] = t;
                }
}

vector<double> normalized_vector(const vector<double>& vector_criteria)
{
    vector<double> vec_crit(4);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (i != j)
            {
                if (vector_criteria[i] > vector_criteria[j])
                    vec_crit[i]++;
                if (vector_criteria[i] == vector_criteria[j])
                    vec_crit[i] += 0.5;
            }
    return vec_crit;
}
vector<double> sum(const vector<vector<double>>& Matrix)
{
    vector<double> sum(4);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            sum[i] += Matrix[i][j];
    return sum;
}

