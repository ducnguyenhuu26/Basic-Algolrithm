#include<bits/stdc++.h>

using namespace std;

// BFS
void BFS(vector<vector<bool>> matrix, int n, int StartVertex) {
    int visit[n] = { 0 };
    queue <int> Q;

    visit[StartVertex] = 1, Q.push(StartVertex);
    // bo dinh xuat phat vao, coi nhu tang 0
    while (Q.size()) {
        int u = Q.front(); Q.pop();
        for (int v = 0; v < n; ++v)
            if (matrix[u][v] && visit[v] == 0) // co canh (u, v), v chua tham
                visit[v] = 1, Q.push(v);       // danh dau v da tham, bo v vao queue
    }
}

//DFS
void dfs(const vector<vector<bool>>& matrix, int vertex, vector<bool>& visited, int& count) {
    visited[vertex] = true;
    count++; // tăng số đỉnh trong thành phần liên thông

    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[vertex][i] && !visited[i]) {
            dfs(matrix, i, visited, count);
        }
    }
}

int componentSize(const vector<vector<bool>>& matrix, int start) {
    vector<bool> visited(matrix.size(), false);
    int count = 0;
    dfs(matrix, start, visited, count);
    return count;
}