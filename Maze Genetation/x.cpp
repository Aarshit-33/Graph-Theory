#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "mazeGen.h"

const int rows = 25;
const int cols = 25;

using namespace std;

// function to find the path
bool findPath(vector<vector<char>>& maze, int x, int y, int endX, int endY) {
    // If the current cell is out of bounds, return false
    if (!isValid(x, y, rows, cols)) {
        return false;
    }

    // If the current cell is the end cell, return true
    if (x == endX && y == endY) {
        return true;
    }

    // If the current cell is a wall or has been visited, return false
    if (maze[x][y] == '#' || maze[x][y] == '.') {
        return false;
    }

    // Mark the current cell as part of the path

    maze[x][y] = '.';

    // Recursively explore each direction
    if (findPath(maze, x - 1, y, endX, endY)) {
        return true;
    }
    if (findPath(maze, x + 1, y, endX, endY)) {
        return true;
    }
    if (findPath(maze, x, y - 1, endX, endY)) {
        return true;
    }
    if (findPath(maze, x, y + 1, endX, endY)) {
        return true;
    }

    // If no direction leads to the end cell, unmark this cell and return false
    maze[x][y] = ' ';
    return false;
}

int main() {
    // Seed the random number generator
    srand(time(0));

    // Create the maze
    vector<vector<char>> maze(rows, vector<char>(cols, '#'));

    // Generate the maze
    generateMaze(maze, 0, 0);

    // Print the maze
    printMazeWithBorders(maze);

    int startX, startY, endX, endY;
    // generate random start and end points
    do {
        startX = rand() % rows;
        startY = rand() % cols;
        endX = rand() % rows;
        endY = rand() % cols;
    } while (maze[startX][startY] == '#' || maze[endX][endY] == '#');

    // Print the maze with start and end points
    printMazeWithBorders(maze);

    findPath(maze, startX, startY, endX, endY);
    
    maze[startX][startY] = 'S';
    maze[endX][endY] = 'E';

    // Print the maze with the path
    printMazeWithBorders(maze);
    return 0;
}