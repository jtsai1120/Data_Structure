
#include<iostream>
using namespace std;

int maze[10][12] = {
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,1,1,1,1,1,1,1},
    {1,1,1,0,1,1,0,0,0,0,1,1},
    {1,1,1,0,1,1,0,1,1,0,1,1},
    {1,1,1,0,0,0,0,1,1,0,1,1},
    {1,1,1,0,1,1,0,1,1,0,1,1},
    {1,1,1,0,1,1,0,1,1,0,1,1},
    {1,1,1,1,1,1,0,1,1,0,1,1},
    {1,1,0,0,0,0,0,0,1,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1}

};

void print(int r, int c) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 12; j++) {
            if (i == r and j == c) cout << "*" << " ";
            else if (maze[i][j] == 1) cout << "|" << " ";
            else if (maze[i][j] == 2) cout << "-" << " ";
            else cout << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

bool arrived;

void run(int r, int c) {
    // arrive at exit
    if (arrived) return;
    if (r == 8 and c == 2) {
        arrived = 1;
        return;
    }

    print(r, c);
    
    // right 
    if (c+1 < 12 and maze[r][c+1] == 0) {
        maze[r][c] = 2;
        run(r, c+1);
        maze[r][c] = 0;
    }
    // left
    if (c-1 > 0 and maze[r][c-1] == 0) {
        maze[r][c] = 2;
        run(r, c-1);
        maze[r][c] = 0;
    }
    // up
    if (r-1 > 0 and maze[r-1][c] == 0) {
        maze[r][c] = 2;
        run(r-1, c);
        maze[r][c] = 0;
    }
    // down
    if (r+1 < 12 and maze[r+1][c] == 0) {
        maze[r][c] = 2;
        run(r+1, c);
        maze[r][c] = 0;
    }

    maze[r][c] = 2;
}


int main() {
    arrived = 0;
    run(1, 1);
}

