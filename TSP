#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tsp(vector<vector<int>> &graph, vector<bool> &visited, int pos, int n, int count, int cost, int start, vector<int> &path, vector<int> &bestPath) {
    if (count == n && graph[pos][start]) {
        path.push_back(start);
        int totalCost = cost + graph[pos][start];
        if (totalCost < INT_MAX) {
            bestPath = path;
        }
        path.pop_back(); // backtrack
        return totalCost;
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = true;
            path.push_back(i);

            int temp = tsp(graph, visited, i, n, count + 1, cost + graph[pos][i], start, path, bestPath);
            ans = min(ans, temp);

            visited[i] = false;
            path.pop_back();
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the cost adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    vector<bool> visited(n, false);
    vector<int> path, bestPath;
    visited[0] = true;
    path.push_back(0);

    int result = tsp(graph, visited, 0, n, 1, 0, 0, path, bestPath);

    cout << "\nMinimum cost of TSP: " << result << endl;
    cout << "Optimal Path: ";
    for (int city : bestPath) {
        cout << city << " -> ";
    }
    cout << bestPath[0] << endl; // return to start

    return 0;
}
