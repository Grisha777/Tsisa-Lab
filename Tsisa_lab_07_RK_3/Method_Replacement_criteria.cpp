#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include "ss.cpp"

vector<vector<double>> Method_Replacement_criteria(const vector<vector<double>>& Matrix, const int& vector_criteria)
{
    vector<vector<double>> MaTrix = Matrix;
    sort(MaTrix);
    vector<vector<double>> MaTriX(4, vector<double>(4));

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            if (i != vector_criteria)
                MaTriX[j][i] = (Matrix[j][i] - MaTrix[0][i]) / (MaTrix[3][i] - MaTrix[0][i]);
            else
                MaTriX[j][i] = Matrix[j][i];
        }
    return MaTriX;
}