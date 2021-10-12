#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include "ss.cpp"


vector<double> Metod_Weighing_and_combining_criteria(const vector<vector<double>>& Matrix, const vector<double> vector_criteria)
{
    vector<double> matrix(4);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            matrix[i] += Matrix[i][j] * vector_criteria[j];
    return matrix;
}