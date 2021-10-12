#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void Print()
{
    cout << '+' << string(6, '-') << '+' << string(6, '-')
         << '+' << string(6, '-') << '+' << string(6, '-')
         << '+' << string(6, '-') << '+' << string(6, '-')
         << '+' << string(6, '-') << '+' << string(6, '-')
         << '+' <<endl;
}

void Print1(const vector<vector<int>>& Network_graph)
{
    for (int i = 0; i < Network_graph.size(); i++)
    {
        Print();
        for (int j = 0; j < Network_graph.size(); j++)
        {
            cout << '|' << setw(4) << Network_graph[i][j] << "  ";
        }
        cout << '|' << endl;
    }
    Print();
    cout<<endl;
}
