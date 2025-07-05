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

    //static นับเลข
    static int count(){
        return num;
    }
    
};

int Point::num;//ต้องมีเวลาใช้static variable

void Point::show(){
    cout<<"\n======== get ========"<<endl;
    cout<<"\nname : "<<name2<<endl;
    cout<<"X  = "<<x<<endl;
    cout<<"Y  = "<<y<<endl; 
}

main(){
    cout<<"\n----------------------"<<endl;
    cout<<"\ncount Obj = "<<Point::count()<<endl;
    Point a;

    cout<<"\n----------------------"<<endl;
    cout<<"\ncount Obj = "<<Point::count()<<endl;
    Point b;
    b.show();

    cout<<"\n----------------------"<<endl;
    cout<<"\ncount Obj = "<<Point::count()<<endl;
    Point c(2,3);
    c.show();
    
    cout<<"\n----------------------"<<endl;
    cout<<"\ncount Obj = "<<Point::count()<<endl;
    Point d("Kingkong");
    d.show();

    cout<<"\n----------------------"<<endl;
    cout<<"\ncount Obj = "<<Point::count()<<endl;
    Point e(5,7,"GUJABAH");
    e.show();

    a.setX(3.0);
    a.setY(1.5);
    a.setName1("Habibi");

    cout<<"\n----------------------"<<endl;
    cout<<"\ncount Obj = "<<Point::count()<<endl;
    cout<<"\n======== get ========"<<endl;
    cout<<"\nx = "<<a.getX()<<endl<<"y = "<<a.getY()<<endl<<"name = "<<a.getName1()<<endl;

    cout<<"\n===== destructor ====="<<endl;
    cout<<Point::count()<<endl;
}