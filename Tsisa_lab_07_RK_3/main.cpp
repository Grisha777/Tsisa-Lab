#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
//#include "ss.cpp"
//#include "Method_Replacement_criteria.cpp"
//#include "Metod_Pareto.cpp"
//#include "Metod_Weighing_and_combining_criteria.cpp"
//#include "Metod_Hierarchy_analysis_matrix.cpp"
//#include "Print.cpp"

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

vector<double> Metod_Weighing_and_combining_criteria(const vector<vector<double>>& Matrix, const vector<double> vector_criteria)
{
    vector<double> matrix(4);
    for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
    matrix[i] += Matrix[i][j] * vector_criteria[j];
    return matrix;
}

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
int main()
{
    std::vector<std::vector<double>> Matrix = { {3,3,5,6},{4,2,3,5},{2,7,4,1},{5,7,2,1} };
    std::vector<double> vector_criteria = { 6,8,4,2 };
    std::vector<double> normalise_criteria = norma(vector_criteria);
    cout <<"Variant 9" << endl;
    cout<<"Choosing an internet provider: A. MGTS; B. Rostelecom; C. Acado; D. Qwerty"<<endl;
    cout<<"Criteria: 1) Cost of the package Economy+TV; 2) Speed; 3) Support service; 4) Service quality"<<endl<<endl;
    cout<<"Vector of criteria weights"<<endl;
    Print2();
    cout<<endl;
    cout<<"Normalized vector"<<endl;
    Print(normalise_criteria);
    cout<<endl;
    cout<<"Matrix"<<endl;
    Print4(Matrix);
    cout<<endl;


    cout << "Method Replacement criteria: " << endl;
    std::vector<std::vector<double>> MaTrix = Method_Replacement_criteria(Matrix, 3);
    Print4(MaTrix);
    cout<<endl;

    cout << "Metod Pareto: " << endl;
    double a = Utopia(Matrix, 1);
    double b = Utopia(Matrix, 2);
    cout << "Utopia:" <<' '<< a << " " << b << endl;
    cout << "A: " << Metod_Pareto(Matrix, a, b, 1, 2, 0) << endl;
    cout << "B: " << Metod_Pareto(Matrix, a, b, 1, 2, 1) << endl;
    cout << "C: " << Metod_Pareto(Matrix, a, b, 1, 2, 2) << endl;
    cout << "D: " << Metod_Pareto(Matrix, a, b, 1, 2, 3) << endl;
    cout<<endl;

    cout << "Metod Weighing and combining_criteria: " << endl;
    std::vector<std::vector<double>> MaTriX = norma(Matrix);
    Print4(MaTriX);
    std::vector<double> Vector_criteria;
    std::vector<double> Normalise_vector_criteria;
    Vector_criteria = normalized_vector(vector_criteria);
    Normalise_vector_criteria = norma(Vector_criteria);
    cout<<"Normalized vector"<<endl;
    Print(Normalise_vector_criteria);
    Vector_criteria = Metod_Weighing_and_combining_criteria(MaTriX, Normalise_vector_criteria);
    cout<<endl;
    cout << "Criterion for all alternatives: ";
    Print(Vector_criteria);
    cout << endl << endl;


    cout << "Metod Hierarchy analysis: " << endl;
    std::vector<double> m_m(4), m_m_1(4), m_m_2(4), m_m_3(4), m_m_m(4);
    std::vector <double> m_sum(4), m_sum_1(4), m_sum_2(4), m_sum3(4), m_m_sum(4);

    MaTriX = Metod_Hierarchy_analysis_matrix(Matrix, 0);
    m_sum = sum(MaTriX);
    m_m = norma(m_sum);
    cout << endl << "Cost of the package Economy+TV: " << endl;
    Print6(MaTriX, m_sum, m_m);

    MaTriX = Metod_Hierarchy_analysis_matrix(Matrix, 1);
    m_sum_1 = sum(MaTriX);
    m_m_1 = norma(m_sum_1);
    cout << endl << "Speed: " << endl;
    Print6(MaTriX, m_sum_1, m_m_1);

    MaTriX = Metod_Hierarchy_analysis_matrix(Matrix, 2);
    m_sum_2 = sum(MaTriX);
    m_m_2 = norma(m_sum_2);
    cout << endl << "Support service: " << endl;
    Print6(MaTriX, m_sum_2, m_m_2);

    MaTriX = Metod_Hierarchy_analysis_matrix(Matrix, 3);
    m_sum3 = sum(MaTriX);
    m_m_3 = norma(m_sum3);
    cout << endl << "Service quality: " << endl;
    Print6(MaTriX, m_sum3, m_m_3);

    MaTriX = Metod_Hierarchy_analysis(vector_criteria);
    m_m_sum = sum(MaTriX);
    m_m_m = norma(m_m_sum);
    cout << endl << "Assessment of criteria priorities: " << endl;
    Print6(MaTriX, m_m_sum, m_m_m);
    cout << endl;

    for (int i = 0; i < 4; i++)
    {
        MaTriX[i][0] = m_m[i];
        MaTriX[i][1] = m_m_1[i];
        MaTriX[i][2] = m_m_2[i];
        MaTriX[i][3] = m_m_3[i];
    }
    for (auto i : MaTriX)
    {
        for (auto j : i)
        cout << j << " ";
        cout << endl;
    }
    cout << endl;
    Vector_criteria = Metod_Weighing_and_combining_criteria(MaTriX, m_m_m);
    Print(Vector_criteria);
}
