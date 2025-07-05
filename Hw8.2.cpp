#include<iostream>
using namespace std;

class Rectangle {
private:
    static int num;
    double width;
    double length;
public:
    Rectangle(){
        num++;
        setAll(0, 0);
    }   

    Rectangle(int a , int b ){
        num++;
        setAll( a , b );
    }
    //---------------------cast fuc------------------------------
    //double to Rectangle
    Rectangle(double d){
        width  = d;
        length = d;
    }

    //Rectangle to double
    operator double() {
        return width * length;
    }

    //-------------------Explain prefix,postfix---------------------------
    /*Prefix Operators (++, --): ฟังก์ชันเหล่านี้ทำงานภายในคลาสและสามารถเข้าถึงสมาชิก 
    private โดยตรง ดังนั้นไม่จำเป็นต้องเป็น friend
    Postfix Operators (++, --): โดยปกติแล้วต้องเป็น friend เนื่องจากมันต้องการเข้าถึงสมาชิก 
    private ของออบเจกต์เพื่อสร้างสำเนาที่เก็บค่าก่อนการอัปเดต*/
    //---------------------------------------------------------------------

    //--------------------------Operator++()-------------------------------
    // เพิ่มค่าค.ยาว prefix op++
    //เวลาmainเรียกใช้มันจะเรียกคนละตัวกัน เช่น ++a 
    //this จะชี้ไปที่objที่กำลังทำงานอยู่ ในนี้จะมีแค่ค.ยาวที่อัปเดตส่วนค.กว้างเท่าเดิม
    Rectangle & operator++(){
        ++length;// เพิ่มค.ยาว
        return *this;// ส่งคืนแบบ pass by ref ไปยังออบเจกต์ปัจจุบัน (หลังจากการอัปเดต)
    }

    //  เพิ่มค่าค.กว้าง postfix op++
    //เวลาmainเรียกใช้มันจะเรียกคนละตัวกัน เช่น a++
    Rectangle operator++(int){
        Rectangle oldObj = *this;//temp จะเก็บทั้งค.กว้างและค.ยาวของอันเก่า
        ++width;//เพิ่มค.กว้าง
        return oldObj;// ส่งคืนสำเนาที่เก็บค่าก่อนการอัปเดต
    }
    /*friend Rectangle operator++(Rectangle & rect,int){
        Rectangle oldObj = *this;//temp จะเก็บทั้งค.กว้างและค.ยาวของอันเก่า
        ++width;//เพิ่มค.กว้าง
        return oldObj;// ส่งคืนสำเนาที่เก็บค่าก่อนการอัปเดต
    }*/
    //---------------------------------------------------------------------

    //--------------------------Operator--()-------------------------------
    // ลดค.ยาว prefix op--
    friend Rectangle& operator--(Rectangle& rect) {
        if (rect.length >1) {  
            --rect.length;  // ลดความยาว
        }
        return rect;  // ส่งคืนการอ้างอิงไปยังออบเจกต์ที่ได้รับการอัปเดตแล้ว
    }
    /*Prefix ++ และ --: นิยามภายในคลาส โดยไม่ต้องใช้ friend แต่อันนี้โจทย์กำหนดให้เป็น
    Rectangle operator--(){
        if (length>0)//ตามโจทย์ค.ยาว>0เสมอ
        {
            --length;
        }else{
            cout<<"Length cannot be 0"<<endl;
        }
        return *this;// ส่งคืนออบเจกต์ที่ได้รับการอัปเดตแล้ว
    }*/

    //ลดค.กว้าง postfix op--
    //Postfix -- นิยามภายนอกคลาส และต้องใช้ friend เพื่อเข้าถึงสมาชิก private ของคลาส
    friend Rectangle operator--(Rectangle& rect,int){
        Rectangle oldObj = rect; // เก็บค่าเดิมก่อนการอัปเดต
        if (rect.width > 1) {  
            --rect.width;  
        }
        return oldObj;  // ส่งคืนออบเจกต์ที่เก็บค่าก่อนการอัปเดต
    }
    /* หากต้องการที่จะไม่ทำแบบfriendจะมีรูปแบบนี้ 
    Rectangle operator--(int) {
        Rectangle oldObj = *this;  
        if (width > 1) {  
            --width;  
        }
        return oldObj;  
    }*/
    //---------------------------------------------------------------------
    
    //----------------------Comparision Operator---------------------------
    //เปรียบเทียบพื้นที่สี่เหลี่ยม
    bool operator < (Rectangle & other){
        return area() < other.area()? true:false;
    }

    bool operator <= (Rectangle & other){
        return area() <= other.area()? true:false;
    }

    bool operator > (Rectangle & other){
        return area() > other.area()? true:false;
    }

    bool operator >= (Rectangle & other){
        return area() >= other.area()? true:false;
    }

    bool operator != (Rectangle & other){
        return area() != other.area()? true:false;
    }

    //----------------------Subscript Operator---------------------------
    //ใช้เข้าถึงและปรับค่าความกว้างและความยาว
    double& operator[](int index) {
        switch(index) {
            case 1: return width;  // ดัชนี 0 ใช้เพื่อเข้าถึงความกว้าง
            case 2: return length;// ดัชนี 1 ใช้เพื่อเข้าถึงความยาว
            default: 
                cout << "Index out of range" << endl;
        }
    }

    //------------------------Call Operator------------------------------
    //คืนค่า area หรือ perimeter ตาม boolean flag
    // คืนค่า width หรือ length ตาม index
    double& operator()(int index) {
        switch(index) {
            case 1: return width;
            case 2: return length;
            default: 
                cout << "Index out of range" << endl;
        }
    }

    int operator()(bool returnAP) {
        return returnAP ? area() : perimeter();
    }
    //-----------------------------------------------------------------

    ~Rectangle(){
        num--;
        cout<<"\ncount Obj = "<<Rectangle::count()<<endl;
    }

    void setAll(int a , int b){
        width=a;
        length=b;
    }

    void setWidth(int a){
        width=a;
    }

    void setLength(int b){
        length=b;
    }

    int getWidth(){
        return width;
    }

    int getLength(){
        return length;
    }

    //calculate
    double area(){
        return width*length;
    }

    double perimeter(){//เส้นรอบรูป
        return 2*(width+length);
    }

    void show(){
        cout<<"\nWidth = "<<width<<endl;
        cout<<"Length = "<<length<<endl;
        cout<<"Area of Rectangle = "<<area()<<endl;
        cout<<"Perimater = "<<perimeter()<<endl; 
    }

    //static นับเลข
    static int count(){
        return num;
    }
};
int Rectangle::num = 0;

int main(){
    Rectangle r1(3, 5);
    Rectangle r2(11, 9);
    cout << "\n======== Initial Rectangles ========" << endl;
    cout<<"\nR1: ";
    r1.show();//แสดงค่าเริ่มต้นของ r1 
    cout<<"\nR2 :";
    r2.show();//แสดงค่าเริ่มต้นของ r2 
    //-------------------- Op++ --------------------------
    cout << "\n========Show========" << endl;
    cout<<"\nR1: ";
    r1.show();
    ++r1; // Increase length by 1
    cout<<"\n===Testing Prefix ++ R1==="<<endl;
    r1.show();
    
    Rectangle oldR1=r1++; // Increase width by 1
    cout<<"\n========Before Testing Postfix r1==========="<<endl;
    oldR1.show();
    
    cout<<"\n========After Testing Postfix r1========"<<endl;
    r1.show();

    //-------------------- Op-- -------------------------
    cout << "\n========Show========" << endl;
    cout<<"\nR2: ";
    r2.show();
    --r2; // Decrease length by 1
    cout<<"\n===Testing Prefix -- R2==="<<endl;
    r2.show();
    
    Rectangle oldR2=r2--; // Decrease width by 1
    cout<<"\n========Before Testing Postfix r2==========="<<endl;
    oldR2.show();
    
    cout<<"\n========After Testing Postfix r2========"<<endl;
    r2.show();

    //-------------Comparision Op ------------------
    // Test comparison operators
    cout << "\n======== Testing Comparison Operators of Area ========" << endl;
    
    cout<<"\nCompare between 2 Area of Rectangle "<<endl;
    if (r1 < r2)
    {
        cout << "r1 < r2: " <<"True"<< endl;
    }else{
        cout << "r1 < r2: " <<"False"<< endl;
    }
    if (r1 <= r2)
    {
        cout << "r1 <= r2: " <<"True"<< endl;
    }else{
        cout << "r1 <= r2: " <<"False"<< endl;
    }
    
    if (r1 > r2)
    {
        cout << "r1 > r2: " <<"True"<< endl;
    }else{
        cout << "r1 > r2: " <<"False"<< endl;
    }

    if (r1 >= r2)
    {
        cout << "r1 >= r2: " <<"True"<< endl;
    }else{
        cout << "r1 >= r2: " <<"False"<< endl;
    }

    if (r1 != r2)
    {
        cout << "r1 != r2: " <<"True"<< endl;
    }else{
        cout << "r1 != r2: " <<"False"<< endl;
    }

    //ใช้เข้าถึงและปรับค่าความกว้างและความยาว []
    cout<<"\n===== Test operator [],() =====" <<endl;
    cout << "R1: " <<endl;
    cout << "width  = "<< r1[1] <<endl;
    cout << "lehgth = "<< r1[2] <<endl;
    //คืนค่า area หรือ perimeter 
    cout << "Area: " << r1(true) << endl;
    //ส่งค่า true ให้กับ r1(true) ฟังก์ชันจะเรียกใช้ area() และคืนค่าพื้นที่
    cout << "Perimeter: " << r1(false) << endl;
    //ส่งค่า false ให้กับ r1(false) ฟังก์ชันจะเรียกใช้ perimeter() และคืนค่าเส้นรอบรูป

    cout<<"\n===== Test operator [],() =====" <<endl;
    cout << "R2: " <<endl;
    cout << "width  = "<< r2[1] <<endl;
    cout << "lehgth = "<< r2[2] <<endl;
    cout << "Area: " << r2(true) << endl;
    cout << "Perimeter: " << r2(false) << endl;

    // แก้ไขค่าผ่าน operator[]
    r1[1]=10;
    r1[2]=20;
    cout<<"\n=====New operator [],()=====" <<endl;
    cout << "R1: " <<endl;
    cout << "width  = "<< r1[1] <<endl;
    cout << "lehgth = "<< r1[2] <<endl;
    cout << "Area: " << r1(true) << endl;
    cout << "Perimeter: " << r1(false) << endl;

    cout<<"\n===== Test operator () =====" <<endl;
    cout << "R2: " <<endl;
    cout << "width  = "<< r2(1) <<endl;
    cout << "lehgth = "<< r2(2) <<endl;
    cout << "\nArea: " << r2(true) << endl;
    cout << "Perimeter: " << r2(false) << endl;

    // แก้ไขค่าผ่าน operator()
    r2(1)=15;
    r2(2)=5;
    cout<<"\n=====New operator ()=====" <<endl;
    cout << "R2: " <<endl;
    cout << "width  = "<< r2(1) <<endl;
    cout << "lehgth = "<< r2(2) <<endl;
    cout << "Area: " << r2(true) << endl;
    cout << "Perimeter: " << r2(false) << endl;

    //ทดสอบการ cast
    cout<<"\n===== Test cast =====" <<endl;
    cout<<"double to Rectangle :" <<endl;
    double d1 = 5.2 , d2 = 4.3, d3 ,d4;

    cout << "----Before cast:  ----" <<endl;
    cout << "\nR1: ";
    r1.show();
    cout << "\nR2: ";
    r2.show();

    r1 = d1;
    r2 = Rectangle(d2);

    cout << "\n----After cast:  ----"<<endl;
    cout << "\nR1: " <<endl;
    r1.show();
    cout << "\nR2: " <<endl;
    r2.show();

    //ทดสอบ cast จาก Rectangle เป็น double
    cout<<"\nRectangle to double :" <<endl;
    double areaR1 = r1;
    double areaR2 = r2;

    cout << "Area of R1 (as double): " << areaR1 << endl;
    cout << "Area of R2 (as double): " << areaR2 << endl;

    cout<<"\n===== destructor ====="<<endl;
    cout<<"\ncount Obj = "<<Rectangle::count()<<endl;

    return 0;
}