#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <unistd.h>

using namespace std;
#define ll long long
#define pb push_back

void execute(vector<vector<int>> cells);
int countCell(vector<vector<int>> cells, int x, int y);
void printCell(vector<vector<int>> cells);

int main() {
  
  vector<vector<int>> cells = {
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,1,1,1,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
  };
  execute(cells);
}

void execute(vector<vector<int>> cells){
    printCell(cells);
    vector<vector<int>> nextCells(5,vector<int>(5,0));
    for(int i=1;i<4;i++){
        for(int j=1;j<4;j++){
            int cnt = countCell(cells, i, j);
            if(cells[i][j]==0){
                if(cnt==3){
                    nextCells[i][j] = 1;
                } else {
                    nextCells[i][j] = 0;
                }
            } else {
                if(cnt==2 || cnt==3){
                    nextCells[i][j] = 1;
                } else {
                    nextCells[i][j] = 0;
                }
            } 
        }
  }
  sleep(1);
  execute(nextCells);
}

int countCell(vector<vector<int>> cells, int x, int y){
    int count = 0;
    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            count += cells[x+i][y+j];
        }
    }
    return count - cells[x][y];
}

void printCell(vector<vector<int>> cells){
    for(int i=1;i<4;i++){
        for(int j=1;j<4;j++){
            cells[i][j] ? cout << "□ " : cout <<  "■ ";
        }
        cout << endl;
    }
    cout << endl;
}
