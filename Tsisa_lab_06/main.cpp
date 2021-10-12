#include <iostream>
#include <vector>
#include "Print.cpp"

int Graph_before_the_start_of_the_algorithm(vector<vector<int>>& Network_graph)
{
    for (int k = 0; k < Network_graph.size(); k++)
    {
        for (int i = 0; i < Network_graph.size(); i++)
        {
            for (int j = 0; j < Network_graph.size(); j++)
            {
                if (i != j && Network_graph[i][k] != -999 && Network_graph[k][j] != -999)
                {
                    if (Network_graph[i][j] == -999)
                    {
                        Network_graph[i][j] = Network_graph[i][k] + Network_graph[k][j];
                    } else {
                        Network_graph[i][j] = max(Network_graph[i][j], Network_graph[i][k] + Network_graph[k][j]);
                    }
                }
            }
        }
    }
    Print1(Network_graph);
}

int main()
{

    int INF = -999;
    vector<vector<int>> Network_graph =
            {
                    {0,3,3,3,INF,INF,INF,INF},
                    {INF,0,INF,INF,INF,5,INF,INF},
                    {INF,INF,0,INF,4,1,INF,INF},
                    {INF,INF,INF,0,5,INF,INF,INF},
                    {INF,INF,INF,INF,0,INF,3,2},
                    {INF,INF,INF,INF,INF,0,2,INF},
                    {INF,INF,INF,INF,INF,INF,0,4},
                    {INF,INF,INF,INF,INF,INF,INF,0}
            };


    cout << "Variant 9" << endl;
    cout << "Graph before the start of the algorithm" << endl;
    Print1(Network_graph);
    cout << "Graph after work algorithm" << endl;
    int Graph_after_work_algorithm = Graph_before_the_start_of_the_algorithm(Network_graph);
    cout << "Shortest path length: " << Network_graph[0][7] << endl;
}

