#include <bits/stdc++.h>
using namespace std;

string direction = "DLRU";
int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, -1, 1, 0};

bool isValid(int r, int c, int n, vector<vector<bool>>& maze) {
	return r >= 0 && c >= 0 && r < n && c < n && maze[r][c];
}

void printMaze(vector<vector<bool>>& maze) {
	for (int i = 0; i < maze.size(); i++) {
		for (int j = 0; j < maze[i].size(); j++)
			cout << maze[i][j] << " ";
		cout << endl;
	}
}

void findPath(pair<int, int> s, pair<int, int> end, vector<vector<bool>>& maze, int n, vector<string>& ans, string& currentPath) {
	if (s.first == end.first && s.second == end.second) {
		ans.push_back(currentPath);
		return;
	}

	int r = s.first;
	int c = s.second;

	maze[r][c] = 0;

	for (int i = 0; i < 4; i++) {
		int nextr = r + dr[i];
		int nextc = c + dc[i]; 
		if (isValid(nextr, nextc, n, maze)) {
			currentPath += direction[i];
			findPath({nextr, nextc}, end, maze, n, ans, currentPath);
			currentPath.pop_back();
		}
	}
	maze[r][c] = 1;
}

int main() {
	vector<vector<bool>> maze = {
		{1, 0, 0, 1, 1},
		{1, 1, 1, 0, 0},
		{1, 0, 1, 1, 1},
		{1, 0, 1, 0, 1},
		{1, 1, 1, 1, 1}
	};

	int n = maze.size();
	cout << "Maze:: " << endl;
	printMaze(maze);

	int sX, sY, eX, eY;
	cout << "Enter start point: ";
	cin >> sX >> sY;
	cout << "Enter end point: ";
	cin >> eX >> eY;

	vector<string> result;
	string currentPath = "";

	findPath({sX, sY}, {eX, eY}, maze, n, result, currentPath);

	if (result.size() == 0)
		cout << "No path found" << endl;
	else{
		cout << "Path found: " << endl;
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << " ";
	}

	return 0;
}