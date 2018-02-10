// Deepak Aggarwal, deepak@codingblocks.com
// https://github.com/aggarwaldeepak/
#include <iostream>
using namespace std;

class MobilePhone{
private:
    int price;
    int imei;
public:
    char* brand;
    // char brand[100];
    // member functions
    
    MobilePhone(){
        // brand = "Nokia";  // array
        int len = 6;
        brand = new char[len];

        strcpy(brand, "Nokia");
        price = 0;
        imei = 0;
    }

    MobilePhone(const char br[]){
        // br[0] = 'F';
        int len = strlen(br);
        brand = new char[len + 1];

        strcpy(brand, br);
        price = 0;
        imei = 0;
    }

    MobilePhone(char br[], int p){
        price = p;
        strcpy(brand, br);
        imei = 0;
    }

    void setImei(int code){
        if (code > 0) imei = code;
    }

    int getImei(){
        return imei;
    }

    const char* getBrand(){
        return brand;
    }

    void calling(char person[]){
        cout << "calling " << person << " from " << brand << endl;
    }

    MobilePhone(const MobilePhone& m){
        int len = strlen(m.brand);
        brand = new char[len + 1];
        
        strcpy(brand, m.brand);
        imei = m.imei;        
    }

    ~MobilePhone(){
        cout << "Dtor for " << brand << " being called" << endl;
        delete [] brand;
    }

};

void foo(){
    MobilePhone m1("nokia");
    MobilePhone m2("apple");
    MobilePhone m3("blackcherry");

    // delete [] m1.brand;
    // m1.deleteMem();
    // m2.deleteMem();

}

int main(){
    // m.setImei(1234);
    // m.setImei = -100;
    // cout << m.brand << endl;

    // MobilePhone m("Samsung");
    // MobilePhone m2(m);
    // // MobilePhone m2 = m;  // assignment operator
    // cout << m.getBrand() << endl;
    // m.brand[0] = 'T';
    // cout << m2.getBrand() << endl;
    // cout << m.getBrand() << endl;

    foo();
    return 0;
}