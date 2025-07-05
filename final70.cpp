#include <iostream>
using namespace std;

class Food
{
    int grade; // 1.standard 2.premium
public:
    Food() { grade = 1; }
    Food(int g)
    {
        if (g == 1 || g == 2)
        {
            grade = g;
        }
        else
        {
            cout << "Don't have this grade" << endl;
            grade = 1;
        }
    }
    virtual ~Food()
    {
        cout << "~Food ";
        show();
    }
    int getGrade() { return grade; }
    virtual string getType() = 0; // pure virtual
    virtual void show()
    {
        cout << "Food Grade = " << grade << endl;
    }
};

class Meat : public Food
{
    int type; // 1.beef 2.pork 3.lamb
public:
    Meat() { type = 1; }
    Meat(int t, int g) : Food(g)
    {
        if (t >= 1 && t <= 3)
        {
            type = t;
        }
        else
        {
            cout << "Don't have this type" << endl;
            type = 1;
        }
    }
    ~Meat()
    {
        cout << "~ Meat ";
        show();
    }

    // get
    string getType()
    {
        switch (type)
        {
        case 1:
            return "beef";
        case 2:
            return "pork";
        case 3:
            return "lamb";
        default:
            return "beef";
        }
    }

    void show()
    {
        Food::show();
        cout << "Meat Type = " << getType() << endl;
    }
};

class Seafood : public Food
{
    int type; // 1.กุ้ง 2.ปลาหมึก 3.หอย 4.ปลา
public:
    Seafood() { type = 1; }
    Seafood(int t, int g) : Food(g)
    {
        if (t >= 1 && t <= 4)
        {
            type = t;
        }
        else
        {
            cout << "Don't have this type" << endl;
            type = 1;
        }
    }
    ~Seafood()
    {
        cout << "~Seafood ";
        show();
    }

    // get
    string getType()
    {
        switch (type)
        {
        case 1:
            return "shrimp";
        case 2:
            return "squit";
        case 3:
            return "shell";
        case 4:
            return "fish";
        default:
            return "shrimp";
        }
    }

    void show()
    {
        Food::show();
        cout << "Seafood Type = " << getType() << endl;
    }
};

class Poultry : public Food
{
    int type; // 1.ไก่ 2.เป็ด
public:
    Poultry() { type = 1; }
    Poultry(int t, int g) : Food(g)
    {
        if (t == 1 || t == 2)
        {
            type = t;
        }
        else
        {
            cout << "Don't have this type" << endl;
            type = 1;
        }
    }
    ~Poultry()
    {
        cout << "~Poultry";
        show();
    }

    // get
    string getType()
    {
        switch (type)
        {
        case 1:
            return "chicken";
        case 2:
            return "duck";
        default:
            return "chicken";
        }
    }

    void show()
    {
        Food::show();
        cout << "Poultry Type = " << getType() << endl;
    }
};

ostream &operator<<(ostream &os, Food &a)
{
    a.show();
    return os;
}

class Dish
{
    double price;
    Food **food;
    int num;
    static int count;

public:
    Dish()
    {
        setPrice(60);
        num = 0;
        food = new Food *[num];
        count++;
    }
    /*Dish(double p, int n) ไม่ได้สั่งแต่ทำไปแล้ว
    {
        setPrice(p);
        num = n;
        food = new Food *[num];
        count++;
    }*/
    virtual ~Dish()
    {
        count--;
        cout << "~Dish ";
        showDish();
        delete[] food;
    }

    // copy con
    Dish(Dish &d)
    {
        count++;
        setPrice(d.price);
        num = d.num;
        food = new Food *[num];
        for (int i = 0; i < num; i++)
        {
            food[i] = d.food[i];
        }
    }

    // set
    void setPrice(double p)
    {
        if (p >= 0)
        {
            price = p;
        }
        else
        {
            price = 0;
        }
    }
    void setFood(int i, Food *f)
    {
        if (i >= 0 && i < num)
        {
            food[i] = f;
        }
    }
    void setNum(int n)
    {
        if (n < 0)
        {
            n = 1;
        }
        if (n == num)
        {
            return;
        }

        num = n;
        delete[] food;
        food = new Food *[num];
    }

    // get
    Food *getFood(int i)
    {
        if (i >= 0 && i < num)
        {
            return food[i];
        }
        return nullptr;
    }
    double getPrice()
    {
        return price;
    }
    int getNum()
    {
        return num;
    }

    virtual void show() = 0; // pure virtual
    // show
    void showDish()
    {
        cout << "price = " << price << endl;
        cout << "num = " << num << endl;
        for (int i = 0; i < num; i++)
        {
            food[i]->show();
        }
    }

    static int getCount()
    {
        return count;
    }
};

int Dish::count;

class Khaopad : virtual public Dish
{
    int size; // 1.จานกลาง 2.จานใหญ่
public:
    Khaopad()
    {
        size = 1;
        setPrice(55);
    }
    ~Khaopad()
    {
        cout << "~Khaopad ";
        cout << "size = " << size << endl;
    }
    // ลูกเกิดแม่ก็เกิด
    Khaopad(Khaopad &k) : Dish(k)
    {
        setSize(k.size);
    }

    // set
    void setSize(int s)
    {
        if (s == 1 || s == 2)
        {
            size = s;
        }
        else
        {
            cout << "Don't have this size" << endl;
            size = 1;
        }
    }
    // get
    int getSize()
    {
        return size;
    }
    void show()
    {
        Dish::showDish();
        cout << "size = " << size << endl;
    }
};

class Potaek : virtual public Dish
{
    int spicy; // 1.เผ็ดกลาง 2.เผ้ดมาก
public:
    Potaek()
    {
        spicy = 2;
        setPrice(350);
    }
    ~Potaek()
    {
        cout << "~Potaek ";
        cout << "spicy = " << spicy << endl;
    }
    Potaek(Potaek &p) : Dish(p)
    {
        spicy = p.spicy;
    }
    // set
    void setSpicy(int sp)
    {
        if (sp == 1 || sp == 2)
        {
            spicy = sp;
        }
        else
        {
            cout << "Don't have this spicy" << endl;
            spicy = 1;
        }
    }
    // get
    int getSpicy()
    {
        return spicy;
    }
    // show
    void show()
    {
        Dish::showDish();
        cout << "spicy = " << spicy << endl;
    }
};

class KhaopadPotaek : public Khaopad, public Potaek
{
    bool special; // 1(T).เพิ่มเครื่อง 0(F).ธรรมดา
public:
    KhaopadPotaek()
    {
        special = false;
        setSize(1);
        setSpicy(1);
        setPrice(150);
    }
    ~KhaopadPotaek()
    {
        cout << "~KhaopadPotaek";
        cout << "special = " << (special ? "special" : "normal") << endl;
    }
    KhaopadPotaek(KhaopadPotaek &kp) : Dish(kp), Khaopad(kp), Potaek(kp)
    {
        setPrice(kp.getPrice());
        special = kp.special;
        setSize(kp.getSize());
        setSpicy(kp.getSpicy());
    }

    // overlode set
    void setKhaopadPotaek(bool s)
    {
        special = s;
    }
    void setKhaopadPotaek(bool s, int a)
    {
        special = s;
        Khaopad::setSize(a);
    }
    void setKhaopadPotaek(bool s, int a, int b)
    {
        special = s;
        Khaopad::setSize(a);
        Potaek::setSpicy(b);
    }

    // get
    bool getSpecial()
    {
        return special;
    }

    // show
    void show()
    {
        Khaopad::show();
        cout << "spicy = " << getSpicy() << endl;
        cout << "special = " << (special ? "special" : "normal") << endl;
    }
};

ostream &operator<<(ostream &os, Dish &d)
{
    d.show();
    return os;
}

class Pinto
{
    Dish **dish;
    int num;

public:
    Pinto()
    {
        num = 0;
        dish = new Dish *[num];
    }
    ~Pinto()
    {
        cout << "~Pinto ";
        cout << "num = " << num << endl;
        for (int i = 0; i < num; i++)
        {
            dish[i]->showDish();
        }
    }
    //  set
    void setNum(int n)
    {
        if (n < 0)
        {
            n = 1;
        }
        if (n == num)
        {
            return;
        }

        num = n;
        delete[] dish;
        dish = new Dish *[num];
    }
    void setDish(int i, Dish *d)
    {
        dish[i] = d;
    }
    // get
    Dish *getDish(int i)
    {
        return dish[i];
    }
    int getNum()
    {
        return num;
    }

    double getPrice()
    {
        double total = 0;
        for (int i = 0; i < num; i++)
        {
            total += dish[i]->getPrice();
        }
        return total;
    }
    bool operator>(Pinto &p)
    {
        if (getPrice() > p.getPrice())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Box
{
private:
    Pinto **pinto;
    int num;

public:
    Box()
    {
        num = 0;
        pinto = new Pinto *[num];
    }
    ~Box() {}

    // set
    void setNum(int n)
    {
        if (n < 0)
        {
            n = 1;
        }
        if (n == num)
        {
            return;
        }

        num = n;
        delete[] pinto;
        pinto = new Pinto *[num];
    }
    void setPinto(int i, Pinto *p)
    {
        pinto[i] = p;
    }
    // get
    Pinto *getPinto(int i)
    {
        return pinto[i];
    }
    int getNum()
    {
        return num;
    }

    double getPrice()
    {
        double total = 0;
        for (int i = 0; i < 2; i++)
        {
            total += pinto[i]->getPrice();
        }
        return total;
    }
    void show()
    {
        cout << "Box: " << endl;
        cout << "count of pinto " << num << endl;

        for (int i = 0; i < num; i++)
        {
            cout << "pinto[" << i << "] : count of dish " << getPinto(i)->getNum() << endl;
            for (int j = 0; j < getPinto(i)->getNum(); j++)
            {
                cout << "dish[" << j << "]: " << endl;
                getPinto(i)->getDish(j)->showDish();
                cout << endl;
            }
        }
    }
};

int main()
{
    //-----------------------------
    Meat beef(1, 2);
    Meat pork(2, 2);
    Seafood shrimp(1, 1);
    Seafood squit(2, 1);
    Seafood shell(3, 2);
    Seafood fish(4, 1);
    Poultry chicken(1, 1);
    Poultry duck(2, 1);

    Food *food[8] = {&beef, &pork, &shrimp, &squit,
                     &shell, &fish, &chicken, &duck};

    for (int i = 0; i < 8; i++)
    {
        food[i]->show();
        cout << endl;
    }
    //-----------------------------
    Khaopad *khaopadMuKai = new Khaopad();
    khaopadMuKai->setSize(1);
    khaopadMuKai->setPrice(80);
    khaopadMuKai->setNum(2);
    khaopadMuKai->setFood(0, food[1]);
    khaopadMuKai->setFood(1, food[6]);
    cout << "KhaopadMuKai:" << endl;
    cout << *khaopadMuKai << endl;

    Potaek *potaek = new Potaek();
    potaek->setSpicy(2);
    potaek->setPrice(220);
    potaek->setNum(1);
    potaek->setFood(0, food[5]);
    cout << "Potaek:" << endl;
    cout << *potaek << endl;

    Khaopad *khaopadBeef = new Khaopad();
    khaopadBeef->setSize(2);
    khaopadBeef->setPrice(150);
    khaopadBeef->setNum(1);
    khaopadBeef->setFood(0, food[0]);
    cout << "khaopadBeef: " << endl;
    cout << *khaopadBeef << endl;

    KhaopadPotaek *khaopadPotaek = new KhaopadPotaek();
    khaopadPotaek->setKhaopadPotaek(false);
    khaopadPotaek->setSpicy(1);
    khaopadPotaek->setSize(1);
    khaopadPotaek->setPrice(160);
    khaopadPotaek->setNum(3);
    khaopadPotaek->setFood(0, food[2]);
    khaopadPotaek->setFood(1, food[3]);
    khaopadPotaek->setFood(2, food[4]);
    cout << "khaopadPotaek" << endl;
    cout << *khaopadPotaek << endl;
    //--------------------------
    Pinto *pinto[2];
    pinto[0] = new Pinto();
    pinto[0]->setNum(2);
    pinto[0]->setDish(0, khaopadMuKai);
    pinto[0]->setDish(1, potaek);

    pinto[1] = new Pinto();
    pinto[1]->setNum(2);
    pinto[1]->setDish(0, khaopadBeef);
    pinto[1]->setDish(1, khaopadPotaek);

    for (int i = 0; i < 2; i++)
    {
        cout << "\npinto [" << i << "]: count of dish " << pinto[i]->getNum() << endl;
        for (int j = 0; j < pinto[i]->getNum(); j++)
        {
            cout << "dish[" << j << "]:" << endl;
            pinto[i]->getDish(j)->showDish();
            cout << endl;
        }
    }
    //--------------------------
    Box *box = new Box();
    // box = new Box();
    box->setNum(2);
    box->setPinto(0, pinto[0]);
    box->setPinto(1, pinto[1]);
    box->show();

    cout << "total price = " << box->getPrice() << endl;

    double total = 0;
    for (int i = 0; i < box->getNum(); i++) // 2
    {
        for (int j = 0; j < box->getPinto(i)->getNum(); j++)
        {
            total += box->getPinto(i)->getDish(j)->getPrice();
        }
    }
    cout << "total price = " << total << endl;
    //--------------------------
    cout << "\n------before set------" << endl;
    cout << "khaopadPotaek:" << endl;
    cout << *khaopadPotaek << endl;

    cout << "\n------after set------" << endl;
    khaopadPotaek->setKhaopadPotaek(true);
    cout << "khaopadPotaek:" << endl;
    cout << *khaopadPotaek << endl;

    khaopadPotaek->setKhaopadPotaek(true, 2); // size
    cout << "khaopadPotaek:" << endl;
    cout << *khaopadPotaek << endl;

    khaopadPotaek->setKhaopadPotaek(true, 2, 2); // spicy
    cout << "khaopadPotaek:" << endl;
    cout << *khaopadPotaek << endl;
    //--------------------------

    // copy
    Khaopad *khaopadPedYang = new Khaopad();
    khaopadPedYang->setSize(2);
    khaopadPedYang->setPrice(190);
    khaopadPedYang->setNum(1);
    khaopadPedYang->setFood(0, food[7]);
    cout << "khaopadPedYang:" << endl;
    cout << *khaopadPedYang << endl;

    Khaopad *MyKhaopad = new Khaopad(*khaopadPedYang);
    cout <<"MyKhaopad:" <<endl;
    cout <<*MyKhaopad <<endl;

    delete khaopadPedYang;
    delete MyKhaopad;
    //--------------------------
    cout <<"\n----- get Type ----- ";
    for (int i = 0; i < 2; i++)
        {
            cout<<"Box: "<<endl;
            cout << "\npinto ["<< i << "]:"<<endl;
            for (int j = 0; j < pinto[i]->getNum(); j++)
            {
                cout << "dish["<< j <<"]: ";
                for (int k = 0; k < pinto[i]->getDish(j)->getNum(); k++)
                {
                    cout << pinto[i]->getDish(j)->getFood(k)->getType() << " ";
                }
                cout<<endl;
                
            }
        }
    //--------------------------
    cout <<"\n----- standard ----- ";
    int standard = 0;
    for (int i = 0; i < 2; i++)
        {
            cout << "\npinto ["<< i << "]:"<<endl;
            for (int j = 0; j < pinto[i]->getNum(); j++)
            {
                cout << "dish["<< j <<"]: ";
                for (int k = 0; k < pinto[i]->getDish(j)->getNum(); k++)
                {
                    cout << pinto[i]->getDish(j)->getFood(k)->getGrade() << " ";
                    int g = pinto[i]->getDish(j)->getFood(k)->getGrade();
                    if (g == 1 )
                    {
                        standard++;
                    }
    
                }
                cout<<endl;
                
            }
        }
    cout << "\nstandard = " << standard <<endl;

    cout << "\n------destructor-------" << endl;
    return 0;
}