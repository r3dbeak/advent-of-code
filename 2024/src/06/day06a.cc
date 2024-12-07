#include <bits/stdc++.h>

using namespace std;

constexpr int WIDTH = 130;
constexpr int HEIGHT = 130;
using Grid = array<array<char, WIDTH>, HEIGHT>;

Grid readGridFromFile(const string &filename)
{
    Grid grid{};
    ifstream file(filename);
    string line;
    int i = 0;
    while (getline(file, line) && i < HEIGHT)
    {
        for (int j = 0; j < WIDTH && j < line.size(); ++j)
            grid[i][j] = line[j];
        i++;
    }
    return grid;
}

struct Vec2
{
    int x, y;
    bool operator<(const Vec2 &other) const
    {
        return tie(x, y) < tie(other.x, other.y);
    }
    Vec2 operator+(const Vec2 &other) const
    {
        return {x + other.x, y + other.y};
    }
    Vec2 operator-(const Vec2 &other) const
    {
        return {x - other.x, y - other.y};
    }
};

const array<Vec2, 4>
    directions = {{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}}; // Up, Right, Down, Left

Vec2 getNextDirection(const Vec2 &direction)
{
    if (direction.x == -1 && direction.y == 0)
        return {0, 1};
    if (direction.x == 0 && direction.y == 1)
        return {1, 0};
    if (direction.x == 1 && direction.y == 0)
        return {0, -1};
    if (direction.x == 0 && direction.y == -1)
        return {-1, 0};
    return {0, 0}; // Should not happen
}
class Guard
{
private:
    Vec2 position;
    Vec2 direction;

public:
    Guard(Vec2 pos, Vec2 dir) : position(pos), direction(dir) {}
    void rotate()
    {
        direction = getNextDirection(direction);
    }
    void move()
    {
        position = position + direction;
    }

    Vec2 getPosition() const
    {
        return position;
    }
    void setPosition(Vec2 pos)
    {
        position = pos;
    }
    Vec2 getDirection() const
    {
        return direction;
    }
};

bool cellOutOfBounds(const Vec2 &cell)
{
    return cell.x < 0 || cell.x >= HEIGHT || cell.y < 0 || cell.y >= WIDTH;
}

void updateCellBonkPosition(Grid &grid, Vec2 cell, map<pair<Vec2, Vec2>, Vec2> &bonkPos)
{
    for (const auto &dir : directions)
    {
        Vec2 currentCell = cell;
        Vec2 nextCell{currentCell};
        while (true)
        {
            nextCell = {nextCell.x + dir.x, nextCell.y + dir.y};
            if (cellOutOfBounds(nextCell)) // Out of bounds
            {
                bonkPos[{currentCell, dir}] = nextCell;
                break;
            }
            if (grid[nextCell.x][nextCell.y] == '#') // Bonked!
            {
                bonkPos[{currentCell, dir}] = nextCell;
                break;
            }
        }
    }
}

Vec2 findGuardPosition(const Grid &grid)
{
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            if (grid[i][j] == '^')
            {
                return {i, j};
            }
        }
    }
    return {-1, -1}; // Guard not found
}

void simulateGuardPath(Grid &grid, Guard guard, const map<pair<Vec2, Vec2>, Vec2> &bonkPosition)
{
    Vec2 obstacle{};
    int res = 0;
    while (true)
    {
        obstacle = bonkPosition.at({guard.getPosition(), guard.getDirection()});
        for (Vec2 c = guard.getPosition(); c.x != obstacle.x || c.y != obstacle.y; c = {c.x + guard.getDirection().x, c.y + guard.getDirection().y})
            if (grid[c.x][c.y] != 'X')
            {
                grid[c.x][c.y] = 'X';
                res++;
            }
        guard.setPosition({obstacle - guard.getDirection()});
        cout << "Guard at (" << guard.getPosition().x << ", " << guard.getPosition().y << ") bonked at obstacle at (" << obstacle.x << ", " << obstacle.y << ")" << endl;
        guard.rotate();
        if (cellOutOfBounds(obstacle)) // Out of bounds
            break;
    }
    cout << "Result: " << res << endl;
}

void printGrid(const Grid &grid)
{
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
            cout << grid[i][j];
        cout << endl;
    }
}

void updateObstacle(Grid &grid, Vec2 &obstacle, map<pair<Vec2, Vec2>, Vec2> &bonkPosition)
{
    Vec2 currentCell{};
    for (const auto &dir : directions)
    {
        currentCell = obstacle;
        while (true)
        {
            currentCell = currentCell + dir;
            if (cellOutOfBounds(currentCell) || grid[currentCell.x][currentCell.y] == '#')
                break;
            updateCellBonkPosition(grid, currentCell, bonkPosition);
        }
    }
}

int main()
{
    auto grid = readGridFromFile("../input/day06.in");

    // Compute the coordinates of the first obstacle in each direction (or out of bounds)
    map<pair<Vec2, Vec2>, Vec2> bonkPosition;
    Vec2 cell{};
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            if (grid[i][j] == '#')
            {
                // Mark the cells in each direction until an obstacle is found or out of bounds
                cell = {i, j};
                updateObstacle(grid, cell, bonkPosition);
            }
        }
    }

    Guard guard{findGuardPosition(grid), directions[0]};

    cout << "Simulating path of the guard:" << endl;
    cout << "--------------" << endl;
    cout << "Guard at (" << guard.getPosition().x << ", " << guard.getPosition().y << ")" << endl;
    simulateGuardPath(grid, guard, bonkPosition);

    cout << "--------------" << endl;
    cout << "Grid after simulation:" << endl;
    printGrid(grid);

    return 0;
}