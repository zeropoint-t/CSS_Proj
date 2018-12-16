#include <vector>
#include <iostream>

using namespace std;

#define HEIGHT 5
#define WIDTH 5

void print(vector<vector<int>>& screen){
    for(auto col = screen.begin(); col != screen.end(); col++){
        for(auto cell = col->begin(); cell != col->end(); cell++){
            cout << *cell << " ";
        }
        cout << endl;
    }
}


void Fill(int r, int c, int origColor, int fillColor, vector<vector<int>>& screen){
    if(r < 0 || r >= HEIGHT || c < 0 || c >= WIDTH)
        return;

    if(screen[r][c] == origColor)
        screen[r][c] = fillColor;
    else
        return;
    
    Fill(r-1, c, origColor, fillColor, screen);
    Fill(r, c+1, origColor, fillColor, screen);
    Fill(r+1, c, origColor, fillColor, screen);
    Fill(r, c-1, origColor, fillColor, screen);
}

void Fillbucket(int r, int c, int fillColor, vector<vector<int>>& screen){
    if(r < 0 || r > 5 || c < 0 || c > 5)
        return;  
    
    int origColor = screen[r][c];
    if(screen[r][c] != fillColor)
        Fill(r,c,origColor,fillColor, screen);

}

int main(){

    vector<vector<int>> screen;
    vector<int> row1 = {0,0,3,3,3};
    vector<int> row2 = {0,1,3,1,1};
    vector<int> row3 = {1,1,1,1,1};
    vector<int> row4 = {1,1,1,1,0};
    vector<int> row5 = {1,2,2,0,0};
    screen.push_back(row1);
    screen.push_back(row2);
    screen.push_back(row3);
    screen.push_back(row4);
    screen.push_back(row5);

    print(screen);

    cout << endl;

    Fillbucket(3,3, 5, screen);

    print(screen);
}