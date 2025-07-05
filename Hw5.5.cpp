#include<iostream>
#include<string.h>
#include <cmath> 
using namespace std;

class Circle;
class Point {
private:
    static int num;
    double x,y;
    string name1;
    char name2[20];
public:
    //destructor
    Point(){
        num++;
        set(0.0, 0.0,"noname");
    }

    Point(double x1 , double y1){
        num++;
        set(x1, y1,"noname");
    }

    Point(char * m){
        num++;
        set(0.0, 0.0, m);
    }

    Point(double x1, double y1, char *m){
        num++;
        set(x1, y1, m);
    }

    ~Point(){
        num--;
        cout<<"\ncount Obj = "<<Point::count()<<endl;
    }

    //set all object to use in contructor and destructor
    void set(double x1, double y1, char *m){
        x = x1;
        y = y1;
        strcpy(name2, m);
    }

    //set
    void setX(double x1){
        x=x1;
    }
    void setY(double y1){
        y=y1;
    }
    void setName1(string n){
        name1=n;
    }
    void setName2(char * m){
        strcpy(name2,m);
    }

    //get
    double getX(){
        return x;
    }  
    double getY(){
        return y;
    }
    string getName1(){
        return name1;
    }
    char * getName2(){
        return name2;
    }

    //show
    void show();

    //4.1 dot & midpoint func
    double dot(Point&a){
        //(x1 * x2) + (y1 * y2)
        double scalar = (x * a.x) + (y * a.y);     
        return scalar;
    }

    Point midPoint(Point&a,Point&b){//a & b เป็นตัวแปรในพาราที่เราจะส่งค่ามาจากmain
        //x = ((x1 + x2)/2)   y = ((y1 + y2)/2)
        x = ((a.x + b.x)/2); 
        y = ((a.y + b.y)/2); //x , y  ของ mid 
        Point mid(x,y,"MidPoint");
        return mid;
    }

    //friend fuction
    friend bool checkCircle(Circle&, Point&);

    //static นับเลข
    static int count(){
        return num;
    }
    
};

int Point::num;//ต้องมีเวลาใช้static variable

void Point::show(){
    cout<<"\n======== show ========"<<endl;
    cout<<"Point name : "<<name2<<endl;
    cout<<"X  = "<<x<<endl;
    cout<<"Y  = "<<y<<endl; 
}

class Circle
{
private:
    double radius;
    Point center;
    char name[20];
public:
    
    /*ตัวสร้างเรียก setCircle ด้วยอาร์กิวเมนต์ 0 สำหรับ center ซึ่งอาจไม่ถูกต้องหาก Point 
    ไม่รองรับการกำหนดค่าแบบนี้ (ควรเป็นการกำหนดค่าเป็นออบเจ็กต์ Point มากกว่าค่าตัวเลข)
    Circle(){
        setCircle(0,0,"noname");
    }
    */

    //ที่ถูกต้อง ต้องแบบนี้
    /*
    Circle(){
        Point c(0, 0);
        setCircle(0, c, "noname");
    }
    */  

    /*ตัวสร้างกำหนดค่า center โดยการเรียก center.setX(0); และ center.setY(0); 
    ซึ่งสมมติว่า Point มีเมธอดเหล่านี้เพื่อกำหนดค่าพิกัด x และ y*/
    Circle():name("noname"){
        radius = 0;
        center.setX(0);
        center.setY(0);
    }

    Circle(double r , Point & c){
        setCircle(r, c,"noname");
    }

    Circle(double r,Point & c, char * n){
        setCircle(r, c, n);
    }

    ~Circle(){
        cout << "delete circle : "<< name<<endl;
    }

    //set
    void setCircle(double r,Point & c,char * n){
        radius=r;
        center=c;
        strcpy(name, n);
    }

    void setRadius(double r){
        radius=r;
    }

    void setCenter(Point & c){
        center=c;
    }

    void setName(char *n){
        strcpy(name , n);
    }

    //get
    double getRadius(){
        return radius;
    }

    Point getCenter(){
        return center;
    }

    char* getName(){
        return name;
    }

    //show
    void showCircle(){
        cout<<"\n==== Show Circle ===="<<endl;
        cout<<"Circle Name : " << name << endl;
        cout <<"X = " << center.getX()<<endl;
        cout<<"Y = " << center.getY() << endl;
        cout <<"radius = " << radius << endl;
    }

    friend bool checkCircle(Circle&, Point&);
};

//friend function
bool checkCircle(Circle & c,Point & p ){//c/x1,y1 รับวงกลม p/x2,y2 รับจุดที่จะเช็คว่าอยู่ในหรือนอกวงกลม
    //distance = sqrt(((x2 - x1)^2) + ((y2 - y1)^2));
    double distance;
    distance =sqrt(pow(p.x - c.center.x,2) + (pow(p.y - c.center.y , 2)));
    //distance =sqrt(pow(p.x - c.getCenter().x, 2) + pow(p.y - c.getCenter().x, 2)); กรณีไม่ใช้friend function in circle class
    if(distance <= c.radius){//c.getRadius กรณี ->
        return true;
        
    } else{
        return false;
    }
}

main(){
    //show x,y แล้วก็ชื่อของจุด
    cout<<"count Obj = "<<Point::count()<<endl;
    Point mid(0,0,"noname");
    mid.show();

    //show x,y,radius แล้วก็ชื่อของจุดในวงกลม
    cout<<"----------------------"<<endl;
    double r;
    cout<<"Input radius : ",cin>>r;
    Circle a(r,mid,"Point A");
    a.showCircle();

    //check point that we wanna know its in circle or not
    Point b(2,5,"Point B"); 
    b.show();
    
    bool resultN;
    resultN = checkCircle(a, b);
    if(resultN == 1){
        cout<<"Point "<<b.getName2()<<" is in the circle "<<endl;
    } else {
        cout<<"Point "<<b.getName2()<<" is out side the circle "<<endl;
    }

    //สร้างจุดศูนย์กลางของวงกลมและจุดที่จะคำนวณ เพื่อคำนวณระยะทาง
    cout<<"\n======== Create center point ========"<<endl;
    float x , y;
    char n[20];
    cout<<"Input Point Name : ",cin>>n;
    cout<<"Input x1 : ",cin>>x;
    cout<<"Input y1 : ",cin>>y;
    cout<<"Input radius : ",cin>>r;
    Point mid1(x,y);
    Circle c(r,mid1,n);
    c.showCircle();
    cout<<"Obj = "<<Point::count()<<endl;

    //อีกจุดเพื่อคำนวณ
    cout<<"----------------------"<<endl;
    cout<<"Input Point Name : ",cin>>n;
    cout<<"Input x1 : ",cin>>x;
    cout<<"Input y1 : ",cin>>y;
    Point d(x,y,n);
    d.show();
    cout<<"Obj = "<<Point::count()<<endl;

    cout<<"======Get======"<<endl;
    bool result;
    result = checkCircle(c,d);
    if(result == 1){
        cout<<"Point "<<d.getName2()<<" is in the circle "<<endl;

    } else {
        cout<<"Point "<<d.getName2()<<" is out side the circle "<<endl;
    }

    cout<<"===== destructor ====="<<endl;
    return 0;
}