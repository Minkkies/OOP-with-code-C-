#include <iostream>
using namespace std;

template <class T> //ใช้ <typename T> ก็ได้
T findMax(T a, T b, T c) {
    if (a >= b && a >= c){
        return a;
    } 
    else if (b >= a && b >= c){
        return b;
    }
    else{
        return c;
    }    
}

main() {
    cout << "Max of 9, 1, 5: " << findMax(9, 1, 5) << endl;
    cout << "Max of 2.5, 7.1, 4.3: " << findMax(2.5, 7.1, 4.3) << endl;
}