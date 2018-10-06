#include <iostream>
using namespace std;

class RGB{
public:
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

void display(RGB rgbs[][5], int rows, int columns){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << rgbs[i][j].getColor() << "  ";
        }
        cout << endl;
    }
}

void fillWithBucket(RGB rgbs[][5], int rows, int columns, int y, int x, RGB& color, int depth){
    if((y >= 0 && y < columns) && (x >= 0 && x < rows) && rgbs[y][x] != color){
        cout << "y: " << y << "  x: " << x << " at depth: " << depth << endl;
        RGB current = rgbs[y][x];
        rgbs[y][x].setColor(color);
        
        if(y-1 >= 0 && current == rgbs[y-1][x]){
            fillWithBucket(rgbs, rows, columns, y-1, x, color, ++depth);
        }
        if(x+1 <= columns && y-1 >= 0 && current == rgbs[y-1][x+1]){
            fillWithBucket(rgbs, rows, columns, y-1, x+1, color, ++depth);
        }
        if(x+1 <= columns && current == rgbs[y][x+1]){
            fillWithBucket(rgbs, rows, columns, y, x+1, color, ++depth);
        }
        if(x+1 <= columns && y+1 <= rows && current == rgbs[y+1][x+1]){
            fillWithBucket(rgbs, rows, columns, y+1, x+1, color, ++depth);
        }
        if(y+1 <= rows && current == rgbs[y+1][x]){
            fillWithBucket(rgbs, rows, columns, y+1, x, color, ++depth);
        }
        if(x-1 >= 0 && y+1 <= rows && current == rgbs[y+1][x-1]){
            fillWithBucket(rgbs, rows, columns, y+1, x-1, color, ++depth);
        }
        if(x-1 >= 0 && current == rgbs[y][x-1]){
            fillWithBucket(rgbs, rows, columns, y, x-1, color, ++depth);
        }
        if(x-1 >= 0 && y-1 >= 0 && current == rgbs[y-1][x-1]){
            fillWithBucket(rgbs, rows, columns, y-1, x-1, color, ++depth);
        }
    }else{
        return;
    }
}

int main(int argc, const char * argv[]){
    RGB rgb11(1),rgb12(1),rgb13(0),rgb14(0),rgb15(0);

    RGB rgb21(1),rgb22(0),rgb23(0),rgb24(0),rgb25(0);

    RGB rgb31(0),rgb32(0),rgb33(0),rgb34(0),rgb35(2);

    RGB rgb41(0),rgb42(0),rgb43(0),rgb44(2),rgb45(2);

    RGB rgb51(0),rgb52(0),rgb53(2),rgb54(2),rgb55(3);

    RGB rgbs[5][5] = {  
        {rgb11, rgb12, rgb13, rgb14, rgb15},
        {rgb21, rgb22, rgb23, rgb24, rgb25},
        {rgb31, rgb32, rgb33, rgb34, rgb35},
        {rgb41, rgb42, rgb43, rgb44, rgb45},
        {rgb51, rgb52, rgb53, rgb54, rgb55}
    };

    display(rgbs,5,5);

    cout << endl;

    int y = 0, x = 0;
    RGB color(5);
    fillWithBucket(rgbs, 5, 5, y , x, color, 0);

    cout << endl;

    display(rgbs,5,5);

    return 0;

}