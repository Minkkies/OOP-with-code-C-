#include <iostream>
using namespace std;

// ฟังก์ชันชั้นล่างสุด (ฟังก์ชันที่ลึกที่สุด)
double divide2(double x, double y) noexcept(false) {
    if (y == 0) {
        throw 0;  // โยน exception ถ้า y เป็น 0
    }
}

double divide1(double x, double y) noexcept(false) {
    try{
        if (y == 0)
        {
            divide2(x, y);  //ถ้า y==0 จะเรียก divide2 และมันจะโยน 0 มาเข้า catch ข้างล่าง
        } else {
            return x / y; //ถ้าy!= 0 หารปกติแล้วออก
        }
    } catch (int y){
        cout << "y = " << y << endl; //ค่าที่โยนออกมาจาก divide2
        throw y; //โยนต่อไปให้ main
    }
    
}

main() {
    try {
        cout << "Result: " << divide1(10, 2) << endl;  // จะทำงานปกติ
        cout << "Result: " << divide1(10, 0) << endl;  // จะโยน
        cout << "Result: " << divide1(10, 5) << endl;  //โยนออกไปแล้วไม่ทำแล้ว
    } catch (int i) {
        cout << "\nexception: divide by zero" << endl; 
    }

    cout << "Hello World" << endl;
}
