#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::abs;
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State
{
    kEmpty,
    kObstacle,
    kClosed
};

vector<State> ParseLine(string line)
{
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',')
    {
        if (n == 0)
        {
            row.push_back(State::kEmpty);
        }
        else
        {
            row.push_back(State::kObstacle);
        }
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string path)
{
    ifstream myfile(path);
    vector<vector<State>> board{};
    if (myfile)
    {
        string line;
        while (getline(myfile, line))
        {
            vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}

// Calculate the manhattan distance
int Heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x2 - x1) + abs(y2 - y1);
}

// TODO: Write the AddToOpen function here.
void AddToOpen(int x, int y, int g, int h, std::vector<std::vector<int>> &openNode, std::vector<std::vector<State>> &grid)
{
    std::vector<int> node{x, y, g, h};
    openNode.push_back(node);
    grid[x][y] = State::kClosed;
}

/** 
 * Implementation of A* search algorithm
 */
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2])
{

    cout << "No path found!"
         << "\n";
    return std::vector<vector<State>>{};
}

string CellString(State cell)
{
    switch (cell)
    {
    case State::kObstacle:
        return "⛰️   ";
    default:
        return "0   ";
    }
}

void PrintBoard(const vector<vector<State>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << CellString(board[i][j]);
        }
        cout << "\n";
    }
}

#include "test.cpp"

int main()
{
    int init[2]{0, 0};
    int goal[2]{4, 5};
    auto board = ReadBoardFile("../files/1.board");
    auto solution = Search(board, init, goal);
    PrintBoard(solution);
    // Tests
    TestHeuristic();
    TestAddToOpen();
}