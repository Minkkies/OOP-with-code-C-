#include <iostream>
using namespace std;

class Fabric
{
    int color; // 1.white 2.green 3.brown 4.gray
public:
    Fabric(int c)
    {
        if (c >= 1 && c <= 4)
        {
            color = c;
        }
        else
        {
            color = 1;
        }
    }

    int getColor()
    {
        return color;
    }

    virtual string getDetail()
    {
        switch (color)
        {
        case 1:
            return "white";
        case 2:
            return "green";
        case 3:
            return "brown";
        case 4:
            return "gray";
        default:
            return "white";
        }
    }
    virtual void show() = 0;
};

class Cotton : public Fabric
{
    int type; // 1.หนามาก 2.หนาปานกลาง 3.บาง
public:
    Cotton(int t, int c) : Fabric(c)
    {
        if (t >= 1 && t <= 3)
        {
            type = t;
        }
        else
        {
            type = 1;
        }
    }

    int getType()
    {
        return type;
    }

    string getDetail()
    {
        switch (type)
        {
        case 1:
            return "หนามาก";
        case 2:
            return "หนาปานกลาง";
        case 3:
            return "บาง";
        default:
            return "หนามาก";
        }
    }

    void show()
    {
        cout << "Fabric Color: " << Fabric::getDetail() << endl;
        cout << "Cotton Thickness: " << getDetail() << endl;
    }
};

class Linen : public Fabric
{
    int grade; // 1.very good 2.good 3.not bad
public:
    Linen(int g, int c) : Fabric(c)
    {
        if (g >= 1 && g <= 3)
        {
            grade = g;
        }
        else
        {
            grade = 1;
        }
    }

    int getGrade()
    {
        return grade;
    }

    string getDetail()
    {
        switch (grade)
        {
        case 1:
            return "very good";
        case 2:
            return "good";
        case 3:
            return "not bad";
        default:
            return "very good";
        }
    }

    void show()
    {
        cout << "Fabric Color: " << Fabric::getDetail() << endl;
        cout << "Linen Quality: " << getDetail() << endl;
    }
};

class Polyester : public Fabric
{
    int type; // 1.micro fabric 2.not micro fabric
public:
    Polyester(int t, int c) : Fabric(c)
    {
        if (t == 1 || t == 2)
        {
            type = t;
        }
        else
        {
            type = 1;
        }
    }

    int getType()
    {
        return type;
    }

    string getDetail()
    {
        switch (type)
        {
        case 1:
            return "micro fabric";
        case 2:
            return "not micro fabric";
        default:
            return "micro fabric";
        }
    }

    void show()
    {
        cout << "Fabric Color: " << Fabric::getDetail() << endl;
        cout << "Polyester Fabric: " << getDetail() << endl;
    }
};

ostream &operator<<(ostream &os, Fabric &fb)
{
    fb.show();
    return os;
}

class ClothItem
{
    double price;
    Fabric **fabric;
    int num;

public:
    ClothItem()
    {
        price = 100;
        num = 0;
        fabric = new Fabric *[num];
    }

    ClothItem(double p, int n)
    {
        setPrice(p);
        setNum(n);
        fabric = new Fabric *[n];
    }

    virtual ~ClothItem()
    {
        delete[] fabric;
        cout << "~ClothItem price: " << price << " Number of fabric: " << num << endl;
    }

    // set
    void setPrice(double p)
    {
        if (p >= 0)
        {
            price = p;
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
        delete[] fabric;
        fabric = new Fabric *[num];
    }

    void setFabric(int i, Fabric *f)
    {
        fabric[i] = f;
    }

    // get
    double getPrice()
    {
        return price;
    }
    int getNum()
    {
        return num;
    }
    Fabric *getFabric(int i)
    {
        return fabric[i];
    }

    Fabric *operator[](int i)
    {
        return fabric[i];
    }

    virtual void show() = 0;
    void showClothItem()
    {
        cout << "ClothItem price: " << price << endl;
        cout << " Number of fabric: " << num << endl;
        for (int i = 0; i < num; i++)
        {
            cout << "Fabric [" << i + 1 << "]: " << endl;
            fabric[i]->show();
        }
    }
};

class Hat : public ClothItem
{
    int uv;   // 1.กันUV 2.ไม่กันUV
    int type; // 1.หมวกเบสบอล 2.หมวกบักเก็ต 3.หมวกปีกกว้าง
public:
    Hat() : ClothItem()
    {
        uv = 2;
        type = 2;
        setPrice(80);
    }

    Hat(int u, int t, int p, int n) : ClothItem(p, n)
    {
        setUV(u);
        setType(t);
        setPrice(p);
        setNum(n);
    }
    ~Hat()
    {
        cout << "~Hat Type: " << type << " UV protect: " << uv << endl;
    }

    // set
    void setUV(int u)
    {
        if (uv == 1 || uv == 2)
        {
            uv = u;
        }
    }

    void setType(int t)
    {
        if (t >= 1 && t <= 3)
        {
            type = t;
        }
    }

    // get
    int getUV()
    {
        return uv;
    }
    int getType()
    {
        return type;
    }

    void show()
    {
        showClothItem();
        cout << "Hat Type: " << type << " UV protect: " << uv << endl;
    }
};

class Bag : public ClothItem
{
    int type; // 1.woman 2.men 3.both
    static int count;

public:
    Bag() : ClothItem()
    {
        type = 3;
        setPrice(99);
        count++;
    }
    Bag(int t, int p, int n) : ClothItem(p, n)
    {
        setType(t);
        setPrice(p);
        setNum(n);
        count++;
    }
    ~Bag()
    {
        count--;
        cout << "~Bag For: " << type << endl;
    }
    // set
    void setType(int t)
    {
        if (t >= 1 && t <= 3)
        {
            type = t;
        }
    }
    // get
    int getType()
    {
        return type;
    }

    virtual void show() = 0;

    static int getCount()
    {
        return count;
    }
};

int Bag::count;

class HandBag : public Bag
{
    int strap; // 1.มีสายสะพาย 2.ไม่มีสาย
public:
    HandBag() : Bag()
    {
        setType(1);
        setStrap(1);
        setPrice(199);
    }
    HandBag(int s, int t, int p, int n) : Bag(t, p, n)
    {
        setStrap(s);
        setType(t);
        setPrice(p);
        setNum(n);
    }
    ~HandBag()
    {
        cout << "~HandBag with: " << strap << endl;
    }
    // set
    void setStrap(int s)
    {
        if (s == 1 || s == 2)
        {
            strap = s;
        }
    }
    // get
    int getStrap()
    {
        return strap;
    }

    void show()
    {
        cout << "Bag For: " << Bag::getType() << endl;
        showClothItem();
        cout << "HandBag with: " << strap << endl;
    }
};

class Backpack : public Bag
{
    int frame; // 1.มีแผ่นรองหลัง 2.ไม่มี
    ClothItem **keep;
    int num;

public:
    Backpack() : Bag()
    {
        setType(2);
        frame = 2;
        setPrice(299);
        num = 0;
        keep = new ClothItem *[num];
    }
    Backpack(int f, int n, int t, int p, int n1) : Bag(t, p, n1)
    {
        setFrame(f);
        setNum(n);
        setType(t);
        setPrice(p);
        setNum(n1);
    }
    ~Backpack()
    {
        cout << "~Backpack with: " << frame << " Number of ClothItem: " << num << endl;
    }
    // copy con
    Backpack(Backpack & bp) : Bag(bp)
    {
        frame = bp.frame;
        num = bp.num;
        keep = new ClothItem *[num];
        for (int i = 0; i < num; i++)
        {
            keep[i] = bp.keep[i];
        }
    }

    // set
    void setFrame(int f)
    {
        if (f == 1 || f == 2)
        {
            frame = f;
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
        delete[] keep;
        keep = new ClothItem *[num];
    }

    void setKeep(int i, ClothItem *c)
    {
        keep[i] = c;
    }
    // get
    int getFrame()
    {
        return frame;
    }
    int getNum()
    {
        return num;
    }
    ClothItem *getKeep(int i)
    {
        return keep[i];
    }

    ClothItem *operator[](int i)
    {
        return keep[i];
    }

    bool operator==(Backpack &bp)
    {
        for (int i = 0; i < getNum(); i++)
        {
            for (int j = 0; j < bp.getNum(); j++)
            {
                // ตรวจสอบสีผ้าของ ClothItem แต่ละชิ้นใน Backpack ทั้งสอง
                if (getKeep(i)->getFabric(0)->getColor() == bp.getKeep(j)->getFabric(0)->getColor())
                {
                    return true; // พบสีที่ตรงกัน
                }
            }
        }
        return false; // ไม่พบสีที่ตรงกัน
    }

    void show()
    {
        cout << "Bag For: " << Bag::getType() << endl;
        cout << "BackPack with: " << frame << endl;
        cout << "Number of ClothItem: " << num << endl;
        for (int i = 0; i < num; i++)
        {
            cout << "ClothItem [" << i + 1 << "]: " << endl;
            keep[i]->showClothItem();
            cout << endl;
        }
    }

    void showBackPack()
    {
        cout << "BackPack with: " << frame << endl;
        cout << "Number of ClothItem: " << num << endl;
        for (int i = 0; i < num; i++)
        {
            cout << "ClothItem [" << i + 1 << "]: " << endl;
            keep[i]->showClothItem();
            cout << endl;
        }
    }
};

ostream &operator<<(ostream &os, ClothItem &ci)
{
    ci.show();
    return os;
}

int main()
{
    Fabric **fabric;
    fabric = new Fabric *[9];

    fabric[0] = new Cotton(1, 1);
    fabric[1] = new Cotton(2, 2);
    fabric[2] = new Cotton(3, 3);
    fabric[3] = new Linen(1, 1);
    fabric[4] = new Linen(2, 2);
    fabric[5] = new Linen(3, 3);
    fabric[6] = new Polyester(1, 2);
    fabric[7] = new Polyester(2, 4);
    fabric[8] = new Polyester(1, 3);

    for (int i = 0; i < 9; i++)
    {
        fabric[i]->show();
        cout << endl;
    }

    cout << "-------------------" << endl;
    HandBag *handbag1;
    handbag1 = new HandBag();
    handbag1->setStrap(2);
    handbag1->setType(3);
    handbag1->setNum(2);
    handbag1->setFabric(0, fabric[2]);
    handbag1->setFabric(1, fabric[6]);
    handbag1->setPrice(400);

    Hat *hat1;
    hat1 = new Hat();
    hat1->setType(1);
    hat1->setUV(1);
    hat1->setNum(1);
    hat1->setFabric(0, fabric[3]);
    hat1->setPrice(750);

    Hat *hat2;
    hat2 = new Hat();
    hat2->setType(3);
    hat2->setUV(2);
    hat2->setNum(1);
    hat2->setFabric(0, fabric[7]);
    hat2->setPrice(300);

    Backpack *backpack1;
    backpack1 = new Backpack();
    backpack1->setFrame(1);
    backpack1->setType(2);
    backpack1->setFabric(0, fabric[0]);
    backpack1->setPrice(1500);
    backpack1->setNum(2);
    backpack1->setKeep(0, handbag1);
    backpack1->setKeep(0, hat1);

    ClothItem *items[4] = {handbag1, hat1, hat2,backpack1};

    for (int i = 0; i < 4; i++)
    {
        cout << "Items [" << i + 1 << "]: " << endl;
        cout << *items[i] << endl;
    }

    cout<<"--------------------------"<<endl;
    Fabric* p1 = new Polyester(1, 1); // เนื้อไมโคร, สีขาว
    hat1->setFabric(0, p1);
    cout << *hat1;
    
    Backpack* backpack2 = new Backpack(*backpack1); 
    backpack2->show();

    return 0;
}
