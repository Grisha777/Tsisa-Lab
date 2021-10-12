#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include "ss.cpp"

vector<vector<double>> Metod_Hierarchy_analysis_matrix(const vector<vector<double>>& Matrix, const int& vector_criteria)
{
    vector<vector<double>> matrix(4, vector<double>(4));
    for (int i=0;i<4;i++)
        for (int j = 0; j < 4; j++)
        {
            if (Matrix[i][vector_criteria] == Matrix[j][vector_criteria])
                matrix[i][j] = 1;
            if (Matrix[i][vector_criteria] > Matrix[j][vector_criteria])
            {
                if (Matrix[i][vector_criteria] - Matrix[j][vector_criteria] == 1)
                    matrix[i][j] = 3;
                if (Matrix[i][vector_criteria] - Matrix[j][vector_criteria] == 2)
                    matrix[i][j] = 5;
                if (Matrix[i][vector_criteria] - Matrix[j][vector_criteria] == 3)
                    matrix[i][j] = 7;
                if (Matrix[i][vector_criteria] - Matrix[j][vector_criteria] == 4)
                    matrix[i][j] = 9;
            }
            if (Matrix[i][vector_criteria] < Matrix[j][vector_criteria])
            {
                if (Matrix[j][vector_criteria] - Matrix[i][vector_criteria] == 1)
                    matrix[i][j] = 1.0 / 3;
                if (Matrix[j][vector_criteria] - Matrix[i][vector_criteria] == 2)
                    matrix[i][j] = 1.0 / 5;
                if (Matrix[j][vector_criteria] - Matrix[i][vector_criteria] == 3)
                    matrix[i][j] = 1.0 / 7;
                if (Matrix[j][vector_criteria] - Matrix[i][vector_criteria] == 4)
                    matrix[i][j] = 1.0 / 9;
            }
        }
    return matrix;
}

vector<vector<double>> Metod_Hierarchy_analysis(const vector<double>& vector_criteria)
{
    vector<vector<double>> matrix(4, vector<double>(4));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            if (vector_criteria[i] == vector_criteria[j])
                matrix[j][i] = 1;
            if (vector_criteria[i] > vector_criteria[j]) {
                if (vector_criteria[i] - vector_criteria[j] == 1)
                    matrix[j][i] = 3;
                if (vector_criteria[i] - vector_criteria[j] == 2)
                    matrix[j][i] = 5;
                if (vector_criteria[i] - vector_criteria[j] == 3)
                    matrix[j][i] = 7;
                if (vector_criteria[i] - vector_criteria[j] == 4)
                    matrix[j][i] = 9;
            }
            if (vector_criteria[i] < vector_criteria[j]) {
                if (vector_criteria[j] - vector_criteria[i] == 1)
                    matrix[j][i] = 1.0 / 3;
                if (vector_criteria[j] - vector_criteria[i] == 2)
                    matrix[j][i] = 1.0 / 5;
                if (vector_criteria[j] - vector_criteria[i] == 3)
                    matrix[j][i] = 1.0 / 7;
                if (vector_criteria[j] - vector_criteria[i] == 4)
                    matrix[j][i] = 1.0 / 8;
            }
        }
    return matrix;
}