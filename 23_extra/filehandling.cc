// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <fstream>

using namespace std;
int main(){
    
    fstream  fin("in.txt", ios::in);
    fstream  fout("out.txt", ios::out);

    int x;
    fin >> x;
    cout << x;

    fout << "apple";   
}