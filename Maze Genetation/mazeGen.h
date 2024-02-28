#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// const int rows = 25;
// const int cols = 25;

enum Direction { UP, DOWN, LEFT, RIGHT };

// Function to print the maze
void printMaze(const vector<vector<char>>& maze) {
    for (const auto& row : maze) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

// function printMaze that also prints borders
void printMazeWithBorders(const vector<vector<char>>& maze) {
    for (int i = 0; i < maze.size() + 2; i++) {
        cout << "# ";
    }
    cout << endl;
    for (const auto& row : maze) {
        cout << "# ";
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << "#" << endl;
    }
    for (int i = 0; i < maze.size() + 2; i++) {
        cout << "# ";
    }
    cout << endl;
}

// Function to check if a cell is within bounds
bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// Function to generate the maze using Depth-First Search
void generateMaze(vector<vector<char>>& maze, int x, int y) {
    // Mark the current cell as visited
    maze[x][y] = ' ';

    // Define the possible directions
    vector<Direction> directions = {UP, DOWN, LEFT, RIGHT};

    // Randomly shuffle the directions
    random_shuffle(directions.begin(), directions.end());

    // Explore each direction
    for (Direction dir : directions) {
        int newX = x, newY = y;

        // Move in the chosen direction
        if (dir == UP) {
            newX -= 2;
        } else if (dir == DOWN) {
            newX += 2;
        } else if (dir == LEFT) {
            newY -= 2;
        } else if (dir == RIGHT) {
            newY += 2;
        }

        // Check if the new cell is valid and unvisited
        if (isValid(newX, newY, maze.size(), maze[0].size()) && maze[newX][newY] == '#') {
            // Mark the cell in between as visited
            maze[(x + newX) / 2][(y + newY) / 2] = ' ';
            // Recursively explore the new cell
            generateMaze(maze, newX, newY);
        }
    }
}

// int main() {
//     srand(static_cast<unsigned>(time(0)));

//     // Initialize the maze with walls
//     vector<vector<char>> maze(rows, vector<char>(cols, '#'));

//     // Generate the maze starting from the top-left corner
//     generateMaze(maze, 0, 0);
 
//     // Print the generated maze
//     printMazeWithBorders(maze);

//     return 0;
// }
