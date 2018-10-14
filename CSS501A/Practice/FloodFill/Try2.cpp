#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

//Keeps track of next cell location
class NeighborPointer{
    public:
        NeighborPointer(){
            offsets.push({-1,0});
            offsets.push({-1,1});
            offsets.push({0,1});
            offsets.push({1,1});
            offsets.push({1,0});
            offsets.push({1,-1});
            offsets.push({0,-1});
            offsets.push({-1,-1});
        }

        bool hasNextOffset(){
            if(!this->offsets.empty()){
                return true;
            }else{
                return false;
            }
        }

        tuple<int,int> getNextOffset(){
            if(!this->offsets.empty()){
                tuple<int,int> top = offsets.top();
                offsets.pop();
                return top;
            }else{
                return {};
            }
        }
    private:
        stack<tuple<int,int>> offsets;
};

class RGB{
public:
    RGB(){}
    RGB(int color):color(color){}
    
    bool operator==(const RGB& rgb){
        if(this->color == rgb.color)
            return true;
        else
            return false;
    }
    bool operator!=(const RGB& rgb){
        if(this->color != rgb.color)
            return true;
        else
            return false;
    }
    int getColor() const{
        return this->color;
    }
    void setColor(const RGB& newColor){
        this->color = newColor.getColor();
    }
private:
    int color;
};


//represents a cell that contains RGB
class Cell{
    public:
        Cell(){}
        Cell(int y, int x, int clr):y(y),x(x){
            color = RGB(clr);
        }
        tuple<int,int> getNextOffset(){
            return this->nbrs.getNextOffset();
        };
        bool hasNextCell(){
            return this->nbrs.hasNextOffset();
        }
        int getX(){
            return this->x;
        }
        int getY(){
            return this->y;
        }
        RGB getColor(){
            return this->color;
        }
        void setColor(RGB color){
            this->color = color;
        }
    private:
        NeighborPointer nbrs;
        RGB color;
        int x;
        int y;
};

#define WIDTH 3
#define HEIGHT 3
class Screen{
    public:
        Screen(){}
        Screen (Cell cells[HEIGHT][WIDTH]){
            for(int h = 0; h < HEIGHT; h++){
                for(int w = 0; w < WIDTH; w++){
                    this->cells[h][w] = cells[h][w];
                }
            }
        }
        ~Screen(){
            // for(int i = 0; i < HEIGHT; ++i) {
            //     delete [] cells[i];
            // }
            // delete [] cells;
        }

        Cell* getCell(int y, int x){
            if(y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH){
                return &cells[y][x];
            }else{
                return nullptr;
            }
        }
        void fillWithBucket(const RGB& rgb, const int y, const int x){
            //find the landing cell
            Cell* startCell = this->getCell(y,x);
            //find target color which needs to match adjacent color to change to rgb param
            RGB targetColor = startCell->getColor();
            //set landing cell color to rgb param
            startCell->setColor(rgb);
            //make sure the landing cell exists
            if(startCell != nullptr){
                //create a stack
                stack<Cell*> s;
                //push start cell to a stack
                s.push(startCell);
                //loop until a stack is empty
                while(!s.empty()){
                    //peek the top cell in a stack
                    Cell* curCell = s.top();
                    //visit all curCell's neighbor cells
                    while(curCell->hasNextCell()){
                        //get next neighbor offset
                        tuple<int,int> offset = curCell->getNextOffset();
                        //get next neighbor cell
                        Cell* neighborCell = this->getCell(curCell->getY() + get<0>(offset), curCell->getX() + get<1>(offset));
                        //proceed if next exists
                        if(neighborCell != nullptr){
                            //check if neighbor cell has the same color as target color
                            if(neighborCell->getColor() == targetColor){
                                //push next to stack
                                s.push(neighborCell);
                                //set the neighbor color to rgb param
                                neighborCell->setColor(rgb);
                                cout << endl;
                                display();
                                break;
                            }
                        }
                    }
                    // s.pop();
                    if(!curCell->hasNextCell())
                        break;
                }
            }
        }

        void display(){
            for (int h = 0; h < HEIGHT; h++) {
                for (int w = 0; w < WIDTH; w++) {
                    std::cout << cells[h][w].getColor().getColor() << "  ";
                }
                cout << endl;
            }
        }
    private:
        Cell cells[HEIGHT][WIDTH];
};

void display(RGB rgbs[][5], int rows, int columns){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << rgbs[i][j].getColor() << "  ";
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]){

    Cell c11(0,0,1),c12(0,1,1),c13(0,2,0);
    Cell c21(1,0,1),c22(1,1,0),c23(1,2,0);
    Cell c31(2,0,0),c32(2,1,0),c33(2,2,1);

    Cell cells[3][3] = {  
        {c11, c12, c13},
        {c21, c22, c23},
        {c31, c32, c33}
    };

    Screen scr(cells);
    scr.display();

    RGB rgb(2);
    scr.fillWithBucket(rgb,2,0);

    scr.display();

    return 0;
}