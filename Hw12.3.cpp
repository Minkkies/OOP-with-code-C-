#include <iostream>   //12.1 - 12.3
using namespace std;
class A
{
    int a;

public:
    A()
    {
        setA(0);
    }
    A(int x)
    {
        setA(x);
    }
    ~A()
    {
        cout << "~A" << endl;
    }
    // set
    void setA(int x)
    {
        a = x;
    }
    // get
    int getA()
    {
        return a;
    }
    // show
    void showA()
    {
        cout << "\na = " << a << endl;
    }
};

class B : public A
{
    int b;

public:
    B()
    {
        setB(0);
    }
    B(int y)
    {
        setB(y);
    }
    B(int x, int y) : A(x)
    {
        setB(y);
    }
    ~B()
    {
        cout << "~B" << endl;
    }
    // set
    void setB(int y)
    {
        b = y;
    }
    // get
    int getB()
    {
        return b;
    }
    // show
    void showB()
    {
        showA();
        cout << "b = " << b << endl;
    }
};

// เช็ค a - b = จะโยน B
void equalZero(A &n, B &m) noexcept(false)
{
    if ((n.getA() - m.getB()) == 0)
    {
        throw B(m);
    }
    else
    {
        cout << "a - b  is not zero." << endl;
    }
}

main()
{
    //12.1 - 12.3
    A a1; a1.showA();
    a1.setA(15);
    cout << "--- get A ---" <<endl;
    cout << "a = " << a1.getA() <<endl;

    A a2(5);
    a2.showA();
    
    B b1; b1.showB();
    b1.setA(2); b1.setB(10);
    cout << "--- get B ---" <<endl;
    cout << "a = " << b1.getA() <<endl;
    cout << "b = " << b1.getB() <<endl;

    B b2(10, 5); // โดนโยน
    b2.showB();


    try
    {
        equalZero(a1, b1); 
        equalZero(a2, b2); // โดนโยน 
        cout << "in try block" << endl;
    }
    catch (B)
    {
        cout << "catch B" << endl;
    }
    catch (A)
    {
        cout << "cath A" << endl;
    }
    /*catch (B)
    {
        cout << "catch B" << endl;
    }*/
    cout << "continue to next step" << endl;

    //12.1 - 12.2 ถูกจับโดย catch(...) 
    try{
        char* s1 = "aespa"; cout << "s1 = " << s1 <<endl;
        char* s2 = "Aeri";  cout << "s2 = " << s2 <<endl;

        if (s1 == " Aeri")
        {
            throw s1;
        } else {
            throw s2; 
        }
        
    }
    catch(double d){
        cout << "Exception: " << d << endl;
    }
    catch (int i)
    {
        cout << "Exception: " << i << endl;
    }
    catch (char c)
    {
        cout << "Exception: " << c << endl;
    }
    catch (...)
    {
        cout << "Other Exception "<< endl;
    }

    cout << "\n----- destruct ----- " <<endl;
}