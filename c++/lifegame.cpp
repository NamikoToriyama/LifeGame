#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <unistd.h>
#include <cstdlib> 

using namespace std;

void printCells(vector<vector<bool>> cells)
{
    for (vector<bool> cellsRow : cells)
    {
        for (bool cell : cellsRow)
        {
            cell ? cout << "■" : cout << "□";
        }
        cout << endl;
    }
    cout << endl;
}

int countLivingCells(vector<vector<bool>> cells, int x, int y)
{
    int count = 0;
    int size_i = cells.size(), size_j = cells[0].size();
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (x + i < 0 || size_i <= x + i  || y + j < 0 || size_j <= y + j )
            {
                continue;
            }
            else
            {
                count += cells[x + i][y + j];
            }
        }
    }
    return count - cells[x][y];
}

vector<vector<bool>> nextGeneration(vector<vector<bool>> preGeneration,
                                    vector<vector<bool>> newGeneration,
                                    int size_i, int size_j)
{ // TODO 参照渡し
    for (int i = 0; i < size_i; i++)
    {
        // ここはNの大きさに依存する
        for (int j = 0; j < size_j; j++)
        {
            int cnt = countLivingCells(preGeneration, i, j);
            if (preGeneration[i][j])
            {
                if (cnt == 2 || cnt == 3)
                {
                    newGeneration[i][j] = true;
                }
                else
                {
                    newGeneration[i][j] = false;
                }
            }
            else
            {
                if (cnt == 3)
                {
                    newGeneration[i][j] = true;
                }
                else
                {
                    newGeneration[i][j] = false;
                }
            }
        }
    }
    return newGeneration;
}

void execute(vector<vector<bool>> cells)
{
    int size_i = cells.size(), size_j = cells[0].size();
    vector<vector<bool>> newGen(size_i, vector<bool>(size_j));
    printCells(cells);
    newGen = nextGeneration(cells, newGen, size_i, size_j);
    usleep(0.5 * 1000000);
    execute(newGen);
}

vector<vector<bool>> generateCell(vector<vector<bool>> cells)
{
    int size_i = cells.size(), size_j = cells[0].size();
    // 乱数%2でtrue or falseを決める
    for (int i = 0; i < size_i; i++)
    {
        // ここはNの大きさに依存する
        for (int j = 0; j < size_j; j++)
        {
            cells[i][j] = rand()%2;
        }
    }
    
    return cells;
}

void defineCell()
{
    int a, b;
    cin >> a >> b;
    // 生きてたらtrue、死んでたらfalseを入れる
    vector<vector<bool>> cells(a, vector<bool>(b));
    cells = generateCell(cells);
    execute(cells);
}

void gliderCell()
{
    bool f = false;
    bool o = true;
    // 縦 : 11以上 横 : 38以上
    vector<vector<bool>> cells = {
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, o, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, o, f, o, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, o, o, f, f, f, f, f, f, o, o, f, f, f, f, f, f, f, f, f, f, f, f, o, o, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, o, f, f, f, o, f, f, f, f, o, o, f, f, f, f, f, f, f, f, f, f, f, f, o, o, f, f, f, f, f, f, f, f},
        {f, o, o, f, f, f, f, f, f, f, f, o, f, f, f, f, f, o, f, f, f, o, o, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, o, o, f, f, f, f, f, f, f, f, o, f, f, f, o, f, o, o, f, f, f, f, o, f, o, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, o, f, f, f, f, f, o, f, f, f, f, f, f, f, o, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, o, f, f, f, o, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, o, o, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
        {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
    };
    execute(cells);
}

int main()
{
    // defineCell();
    gliderCell();
}
