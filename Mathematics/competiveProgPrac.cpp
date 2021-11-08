// C++ tricks for competitive programming 


#include<iostream>
#include<iomanip>
using namespace std;

typedef long long ll;
// ! These tricks are not supported for development purposes 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ? The above are for faster input and outputs 
    ll a = 23;
    bool b = true;
    // * boolean manipulation 
    cout << b << "\n"; // \n is faster than endl // 1
    cout << boolalpha; // prints true as true
    cout << b << "\n";
    cout << noboolalpha; 
    cout << b << "\n";

    // * Integer values

    // output as hexadecimal
    cout << hex;
    cout << a << "\n"; 
    // output as octadecimal
    cout << oct;
    cout << a << "\n"; 
    // output as decimal
    cout << dec;
    cout << a << "\n"; 

    cout << showbase; // show base of oct and hex numbers 
    cout << oct ;
    cout << a << "\n";
    cout << hex ;
    cout << a << "\n";
    cout << showpos; // shows + prefixed 
    cout << a << "\n";
    cout << uppercase; // bases in uppercase  
    cout << a << "\n";

    // *Output formatting 
    ll c = 12;
    cout << dec;
    cout << noshowpos;
    cout << noshowbase;
    cout << setw(5);// set width 
    cout << setfill('*');// fill the space with the character 
    cout << c << "\n";// ***12
    cout << setw(5);
    cout << "Hi"<<"\n";
    cout << left;
    cout << setw(5);
    cout << setfill('*');// fill the space with the character 
    cout << c << "\n" ;//12***


    cout << "\n Floating Point - Default behavior .\n";
    // ? Floating Point - Default behavior 
    double x = 1.2300;  // no trailing zeroes 
    cout << x << "\n";// 1.23

    double y = 1567.56732; // default precision is 6
    cout << y <<"\n"; // 1567.57


    double z = 1244567.45; // if digits before . are > 6 then scienticfic notation is taken 
    cout << z <<"\n";// 1.24457e+06

    double w = 124456.45; // if digits before . are = 6 then decimal rounding 
    cout << w <<"\n";

    double u = 123e+2;// digits < 6 with scientific notation then decimal with precision 6 and trailing zeroes
    cout << u <<"\n";// 12300

    return 0;
}