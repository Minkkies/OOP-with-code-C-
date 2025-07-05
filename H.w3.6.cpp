#include<iostream>
using namespace std;

class Rectangle {
private:
    static int num;
    int width;
    int length;
public:
      //destructor
    Rectangle(){
        num++;
        set(0, 0);
    }

    Rectangle(int a , int b ){
        num++;
        set( a , b );
    }

    ~Rectangle(){
        num--;
        cout<<"\n----------------------"<<endl;
        cout<<"\ncount Obj = "<<num<<endl;
    }

    void set(int a , int b){
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

    int area(){
        return width*length;
    }

    int perimeter(){
        return 2*(width+length);
    }

    void show();

    //static นับเลข
    static int count(){
        return num;
    }
};

void Rectangle::show(){
    cout<<"\nWidth = "<<width<<endl;
    cout<<"Length = "<<length<<endl;
    cout<<"Area of Rectangle = "<<Rectangle::area()<<endl;
    cout<<"Perimater = "<<Rectangle::perimeter()<<endl;
}

int Rectangle::num;

//3.6 class myRect ทำหน้าที่เก็บข้อมูล Rectangle class
class MyRect
{
private:
    int row,col;
    Rectangle ** a;//a เป็นตัวแปรที่จะเก็บที่อยู่ของตัวชี้ที่ชี้ไปยังออบเจ็กต์ของคลาส Rectangle

    void set(int r , int c){ 
            row = r;
            col = c;

            a = new Rectangle *[row];  //จองที่ row
            for (int i = 0; i < row; i++)
            {
                a[i] = new Rectangle [col]; //จองที่ col สังเกตว่าไม่มี * หน้า[] กรณีเป็นมิติสุดท้าย
            }

        }
    
     void deleteArray(){
        if (a != nullptr)
        {
            for (int i = 0; i < row; i++)
                {
                    delete[] a[i];//delete col
                }
                delete[] a;//delete row
                a=nullptr;
            }
        }
public:
    MyRect(){
        set(0,0);
    }
    //contructor จองพื้นที่
    MyRect (int r, int c){
        set(r,c);
    }

    //destructor ลบพื้นที่
    ~MyRect (){
        deleteArray();
    }

    //setข้อมูล
    void setInput(int r , int c){
        row=r;
        col=c;
        int w,l;
        cout<<"========Input Array========="<<endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout<<"Enter width a["<<i<<"]["<<j<<"] :";cin>>w;
                cout<<"Enter length a["<<i<<"]["<<j<<"] :";cin>>l;
                a[i][j].set(w,l);  //set width length ให้ obj
            } 
        }
    }

    //ลบarrayเก่าเพื่อเปลี่ยนขนาดใหม่
    void reset(int r, int c){
        deleteArray();
        row=r;
        col=c;
        set(row,col);
        setInput(row,col);//set arrayใหม่
    }

    Rectangle get(int i, int j){
        return a[i][j];
    }

    //เป็นsetใส่ข้อมูลแค่ช่องเดียวที่ในarray มีobjเป็น w,l
    void setOneNoObj(int r,int c, int w,int l){
        a[r][c].set(w,l);
    }

    //setช่องเดียวแต่รับ objที่ข้างในเป็น w,l มาเลย
        void setOneObj(int i , int j, Rectangle p){
            a[i][j] = p; //p เป็นสมาชิก class Rectangle ที่มีข้อมูล w,l มาอยู่แล้ว
        }
  
    void show(){
    cout<<"==========show==========="<<endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<"\na["<<i<<"]["<<j<<"] width  = "<< a[i][j].getWidth()<<endl;
            cout<<"a["<<i<<"]["<<j<<"] lenght = "<< a[i][j].getLength()<<endl;
        }
    }
    }

    // ฟังก์ชั่นใหม่เพื่อแสดงผลลัพธ์ของ get function ของ Rectangle
    void showGetFunction(int i, int j){
        cout << "Width of a[" << i << "][" << j << "] = " << a[i][j].getWidth() << endl;
        cout << "Length of a[" << i << "][" << j << "] = " << a[i][j].getLength() << endl;
    }

};

int main(){
    int row,col;
    cout<<"=======Array Size========"<<endl;
    cout<<"Input Row :";cin>>row;
    cout<<"Input Column :";cin>>col;

    MyRect m(row,col);//จองพท.
    m.setInput(row,col);
    m.show();

    //แสดงobjในarray1ช่อง
    int r , c;//ตัวแปรตน.ของอาเรย์
    cout<<"===Select your location==="<<endl;
    cout<<"Input Location to see Result"<<endl;
    cout<<"Input row : ";cin>>r;
    cout<<"Input col : ";cin>>c;
    m.get(r,c); 
    cout<<"\n======== show ========"<<endl;
    m.showGetFunction(r,c);

    //reset
    int r1,c1;
    cout<<"==== Reset Array size===="<<endl;
    cout<<"Input row : ";cin>>r1;
    cout<<"Input col : ";cin>>c1;
    m.reset(r1,c1); //เรียกใช้ตอนแรกไม่ได้เลยเอา deleteArray&set ออกไปไว้ข้างนอก

    //set one no obj
    cout<<"====Set One No Obj  ===="<<endl;
    int r2 , c2; 
    cout<<"Input row : ",cin>>r2;
    cout<<"Input col : ",cin>>c2;

    int w , l;
    cout<<"Input width : ",cin>>w;
    cout<<"Input length : ",cin>>l;
    m.setOneNoObj(r2,c2,w,l);
    cout<<"\n======== show ========"<<endl;
    m.showGetFunction(r2,c2);

    //set one obj
    cout<<"====Set One Obj  ===="<<endl;
    int r3, c3; 
    cout<<"Input row : ",cin>>r3;
    cout<<"Input col : ",cin>>c3;

    cout<<"Input width : ",cin>>w;
    cout<<"Input length : ",cin>>l;
    Rectangle p(w,l); //ส่ง p ที่เป็น obj ไปเลย
    m.setOneObj(r3,c3,p);
    cout<<"\n======== show ========"<<endl;
    m.showGetFunction(r3,c3);

    cout<<"\n===== destructor ====="<<endl;

    return 0;
}