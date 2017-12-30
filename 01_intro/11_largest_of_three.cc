// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
    #include <iostream>
    using namespace std;
    int main(){
        int x;
        int y;
        int z;

        cin >> x >> y >> z;

        if (x > y and y > z){   //and --> &&
            cout << x;
        }
        else if (y > x && y > z){ // or --> || 
        cout << y;
    }
    else {
        cout << z;
    }
}