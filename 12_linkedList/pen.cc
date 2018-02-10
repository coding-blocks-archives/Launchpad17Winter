// Deepak Aggarwal, deepak@codingblocks.com
#include <iostream>
using namespace std;

class Pen{
public:
    int code;
    char color;
    char brand;

    void write(char word[]){
        cout << word << " is being written by a pen of color " << code << endl;
    }  

    // constructor
    Pen (char br, char col){
        brand = br;
        color = col;
    }

    // Pen(char br){
    //     brand = br;
    // }

};

void initialise(Pen& p, char b){
    p.brand = b;
}

int main(){
    Pen p1('R', 'y');
    Pen p2('F', 'r');   
    Pen p3('S');   

    // Pen is a datatype created by the programmer or the user of lang
    // p is a var of that user defined data type
    

    // initialise(p1, 'R');

    // p1.initialise('R', 'y');
    cout << p1.code << " " << p1.color << " " << p1.brand << endl;

    return 0;
}