#include<iostream>
#include<string.h>
using namespace std;

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

    //static นับเลข
    static int count(){
        return num;
    }
    
};

int Point::num;//ต้องมีเวลาใช้static variable

void Point::show(){
    cout<<"\n======== show ========"<<endl;
    cout<<"name : "<<name2<<endl;
    cout<<"X  = "<<x<<endl;
    cout<<"Y  = "<<y<<endl; 
}

main(){
    cout<<"\n----------------------"<<endl;
    cout<<"count Obj = "<<Point::count()<<endl;

    double a,b;
    char name2[20];
    cout<<"\n======== Input ========"<<endl;
    cout<<"Point name : ";cin>>name2;
    cout<<"X1  = ";cin>>a;
    cout<<"Y1  = ";cin>>b;
    Point myPoint;
    myPoint.set(a,b,name2);
    cout<<"\ncount Obj = "<<Point::count()<<endl;
    myPoint.show();

    cout<<"\n======== Input ========"<<endl;
    cout<<"Point name2 : ";cin>>name2;
    cout<<"X2  = ";cin>>a;
    cout<<"Y2  = ";cin>>b;
    Point urPoint;
    urPoint.set(a,b,name2);
    cout<<"\ncount Obj = "<<Point::count()<<endl;
    urPoint.show();
    
    double result;
    result = myPoint.dot(urPoint);
    cout<<"\n==== Result Scalar ===="<<endl;
    cout<<"Scarlar = "<<result<<endl;

    Point midresult,mid1;
    midresult = mid1.midPoint(myPoint,urPoint);
    mid1.show();
    midresult.show();
    return 0;
}