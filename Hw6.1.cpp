#include <iostream>
#include <cstring>
using namespace std;

class Date
{
private:
    int day, month, year;

public:
    Date()
    {
        set(0, 0, 0);
    }

    Date(int d, int m)
    {
        set(d, m, 0);
    }

    Date(int d, int m, int y)
    {
        set(d, m, y);
    }

    ~Date()
    {
        cout << "dalete " << day << "/" << month << "/" << year << endl;
    }

    // set
    void set(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    void setDay(int d)
    {
        day = d;
    }

    void setMonth(int m)
    {
        month = m;
    }

    void setYear(int y)
    {
        year = y;
    }

    // get
    int getDay()
    {
        return day;
    }

    int getMonth()
    {
        return month;
    }

    int getYear()
    {
        return year;
    }

    // show
    void showDate()
    {
        cout << "\n===== show Date =====" << endl;
        cout << day << "/" << month << "/" << year << endl;
    }
};

class Address
{
private:
    static int num;
    char Hnum[30];        // บ้านเลขที่
    char subDistrict[40]; // แขวง,ตำบล
    char district[40];    // อำเภอ,เขต
    char province[40];
    int postcode;

public:
    Address()
    {
        setAddress("none", "none", "none", "none", 0);
    }
    Address(char *n, char *s, char *d, char *p, int c)
    {
        setAddress(n, s, d, p, c);
    }
    ~Address()
    {
        cout << "delete Address " << endl;
    }
    void setAddress(char *n, char *s, char *d, char *p, int c)
    {
        strcpy(Hnum, n);
        strcpy(subDistrict, s);
        strcpy(district, d);
        strcpy(province, p);
        postcode = c;
    }
    void setHouseNum(char *n)
    {
        strcpy(Hnum, n);
    }
    void setSubDistrict(char *s)
    {
        strcpy(subDistrict, s);
    }
    void setDistrict(char *d)
    {
        strcpy(district, d);
    }
    void setProvince(char *p)
    {
        strcpy(province, p);
    }
    void setPostCode(int c)
    {
        postcode = c;
    }

    // get
    char *getHouseNum()
    {
        return Hnum;
    }
    char *getSubDistrict()
    {
        return subDistrict;
    }
    char *getDistrict()
    {
        return district;
    }
    char *getProvince()
    {
        return province;
    }
    int getPostCode()
    {
        return postcode;
    }

    void showAddress()
    {
        cout << "\n======== show Address ========" << endl;
        cout << "\nHouse Number: " << Hnum << endl;
        cout << "SubDistrict: " << subDistrict << endl;
        cout << "District: " << district << endl;
        cout << "Province: " << province << endl;
        cout << "Post code: " << postcode << endl;
    }
};

class Person
{
private:
    static int num;
    char fname[30];
    char lname[30];
    Date bday;   // Composition
    Address add; // Composition
public:
    Person()
    {
        setName("Firstname", "Lastname");
        bday.set(0, 0, 0); // เป็นobjของDateที่เรียกใช้set()
        add.setAddress("none", "none", "none", "none", 0);
        num++;
    }

    Person(char *f, char *l, Date &bd, Address &a) /*:bday(bd), add(a) ส่วนนี้เป็นComposition*/
    {
        setPerson(f, l, bd, a);
        num++;
    }

    ~Person()
    {
        cout << "delete " << fname << " " << lname << endl;
    }

    // set
    void setPerson(char *f, char *l, Date &bd, Address &a)
    {
        strcpy(fname, f);
        strcpy(lname, l);
        bday = bd;
        add = a;
    }

    void setName(char *f, char *l)
    {
        strcpy(fname, f);
        strcpy(lname, l);
    }

    void setBday(Date &d)
    {
        bday = d;
    }

    void setAdd(Address &a)
    {
        add = a;
    }

    // get
    char *getFname()
    {
        return fname;
    }

    char *getLname()
    {
        return lname;
    }

    Date getBday()
    {
        return bday;
    }

    Address getAdd()
    {
        return add;
    }

    void showPerson()
    {
        cout << "\n===== show Person =====" << endl;
        cout<<"\nPerson no. "<<Person::count() <<endl;
        cout << "Name: " << fname << " " << lname << endl;
        cout << "Birth Day: " << bday.getDay() << "/" << bday.getMonth() << "/" << bday.getYear() << endl;
        cout << "House Number: " <<add.getHouseNum() << endl;
        cout << "SubDistrict: " <<add.getSubDistrict() << endl;
        cout << "District: " << add.getDistrict() << endl;
        cout << "Province: " << add.getProvince() << endl;
        cout << "Post code: " << add.getPostCode() << endl;
    }

    static int count()
    {
        return num;
    }
};

int Person ::num; // นับคน

class Student : public Person
{
private:
    char stdNum[10];
    char fac[20];
    char university[20];
    // Person* person;  Aggregation

public:
    /*Student(Person* p, const char* id, const char* f, const char* u) :person(p){} Aggregation */
    Student()
    {
        setStudent("none", "none", "none");
    }

    Student(char *id, char *f1, char *u)
    {
        setStudent(id, f1, u);
    }

    // base ต้องใส่เสมอเพราะต้องไปเรียกconstructor ของคลาสแม่ก่อนทุกครั้ง
    Student(char *f, char *l, Date &d, Address &a, char *f1, char *id, char *u)
    {
        setPerson(f, l, d, a);
        setStudent(id, f1, u);
    }

    // base Person(f, l, d, a)->>เรียกใช้งาน constructor ของคลาส Person เขียนได้2แบบ
    /*Student(char *f, char *l,Date& d, Address& a, char *id, char *fac ,char *u ):Person(f, l, d, a){
        setStudent(id,f,u);
    }*/

    ~Student()
    {
        cout << "bye Student" << endl;
    }

    // set
    void setStudent(char *id, char *f1, char *u)
    {
        strcpy(stdNum, id);
        strcpy(fac, f1);
        strcpy(university, u);
    }

    void setStdNum(char *id)
    {
        strcpy(stdNum, id);
    }

    void setFaculty(char *f1)
    {
        strcpy(fac, f1);
    }

    void setUniversity(char *u)
    {
        strcpy(university, u);
    }

    // get
    char *getStdNum()
    {
        return stdNum;
    }
    char *getFaculty()
    {
        return fac;
    }

    char *getUniversity()
    {
        return university;
    }

    void showStudent()
    {
        cout << "\n==== Student ====" << endl;
        cout << "\nStudent: " << getFname() << " " << getLname() << endl;
        cout << "university: " << university << endl;
        cout << "faculty: " << fac << endl;
        cout << "Student ID : " << stdNum << endl;
    }
};

class Teacher : public Person
{
private:
    char fac[20];
    char university[20];
    char course[10];
    // Person* person;  Aggregation
public:
    /*Teacher(Person* p, const char* f, const char* u, const char* c, double s) :person(p)*/
    Teacher()
    {
        setTeacher("none", "none", "none");
    }

    Teacher(char *f2, char *u1, char *c)
    {
        setTeacher(f2, u1, c);
    }

    Teacher(char *f, char *l, Date &d, Address &a, char *f2, char *u1, char *c)
    {
        setPerson(f,l,d,a);
        setTeacher(f2, u1, c);
    }

    ~Teacher()
    {
        cout << "bye Teacher" << endl;
    }

    // set
    void setTeacher(char *f2, char *u1, char *c1)
    {
        strcpy(fac, f2);
        strcpy(university, u1);
        strcpy(course, c1);
    }

    void setFaculty(char *f2)
    {
        strcpy(fac, f2);
    }

    void setUniversity(char *u1)
    {
        strcpy(university, u1);
    }

    void setCourse(char *c)
    {
        strcpy(course, c);
    }

    // get
    char *getCourse()
    {
        return course;
    }
    char *getFaculty()
    {
        return fac;
    }

    char *getUniversity()
    {
        return university;
    }

    void showTeacher()
    {
        cout << "\n==== Teacher =====" << endl;
        cout << "\nTeacher: " << getFname() << " " << getLname() << endl;
        cout << "university: " << university << endl;
        cout << "faculty: " << fac << endl;
        cout << "Course ID : " << course << endl;
    }
};

int main()
{
    //--------person1---------
    Person p1;
    Date d1;
    d1.set(12, 05, 2009);
    Address a1;
    a1.setAddress("30 Ramkhamhaeng ", "Hua Mak", "Bang Kapi", "Bangkok", 10240);

    p1.setPerson("My", "Habibi",d1,a1);

    //p2.showPerson();
    Date per1Bd = p1.getBday(); 
    Address per1Add = p1.getAdd();

    cout << "\n===== show Person =====" << endl;
    cout<<"\nPerson no. "<<Person::count() <<endl;
    cout << "Name: " << p1.getFname() << " " << p1.getLname() << endl;
    cout << "Birth Day: " << per1Bd.getDay() << "/" <<per1Bd.getMonth() << "/" << per1Bd.getYear() << endl;
    cout << "House Number: " <<per1Add.getHouseNum() << endl;
    cout << "SubDistrict: " <<per1Add.getSubDistrict() << endl;
    cout << "District: " << per1Add.getDistrict() << endl;
    cout << "Province: " << per1Add.getProvince() << endl;
    cout << "Post code: " << per1Add.getPostCode() << endl;

    //------student2----------
    Student s2;
    Date d2;
    d2.set(31, 11, 1995);
    Address a2;
    a2.setAddress("22/15 ", "Nikhomphatana", "Nikhomphatana", "Rayong", 20180);

    s2.setName("King", "Kong");
    s2.setStudent("660500","sci","Ramkhamhaeng");
    s2.setBday(d2);
    s2.setAdd(a2);
    s2.showPerson();
    s2.showStudent();

    //-------Teacher3--------
    Teacher t3;
    Date d3;
    d3.set(01, 04, 1954);
    Address a3;
    a3.setAddress("282 Ramkhamhaeng ", "Hua Mak", "Bang Kapi", "Bangkok", 10240);

    t3.setTeacher("Suyoen", "Kim","COS2100");
    t3.setBday(d3);
    t3.setAdd(a3);
    t3.setFaculty("sci");
    t3.setUniversity("Ramkhamhaeng");
    t3.showPerson();
    cout << "\n==== Teacher =====" << endl;
    cout << "\nTeacher: " <<t3.getFname() << " " << t3.getLname() << endl;
    cout << "university: " <<t3.getUniversity() << endl;
    cout << "faculty: " <<t3.getFaculty() << endl;
    cout << "Course ID : " <<t3.getCourse()<< endl;
    

    //------student4----------
    Student s4;
    Date d4;
    d4.setDay(15);
    d4.setMonth(10);
    d4.setYear(2005);

    Address a4;
    a4.setHouseNum("70 Ramkhamhaeng ");
    a4.setSubDistrict("Hua Mak");
    a4.setDistrict("Bang Kapi");
    a4.setProvince("Bangkok");
    a4.setPostCode(10240);

    s4.setName("Apin","Wa");
    s4.setBday(d4);
    s4.setAdd(a4);
    s4.setStdNum("660500");
    s4.setFaculty("sci");
    s4.setUniversity("Ramkhamhaeng");
    s4.showPerson();
    cout << "\n==== Student ====" << endl;
    cout << "\nStudent: " << s4.getFname() << " " << s4.getLname() << endl;
    cout << "university: " << s4.getUniversity() << endl;
    cout << "faculty: " << s4.getFaculty() << endl;
    cout << "Student ID : " << s4.getStdNum() << endl;

    //-------Teacher5--------
    Teacher t5;
    Date d5;
    d5.setDay(11);
    d5.setMonth(06);
    d5.setYear(1976);
    
    Address a5;
    a5.setHouseNum("90 Ramkhamhaeng ");
    a5.setSubDistrict("Hua Mak");
    a5.setDistrict("Bang Kapi");
    a5.setProvince("Bangkok");
    a5.setPostCode(10240);

    t5.setName("Doctor.","Kim");
    t5.setBday(d5);
    t5.setAdd(a5);
    t5.setCourse("MED2100");
    t5.setFaculty("Medicine");
    t5.setUniversity("Ramkhamhaeng");
    t5.showPerson();
    t5.showTeacher();

    /*
    //composition,base of person
    Date d6(6,2,2005);
    Address a6("282 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
    Person p6("yeri","Kim",d6,a6);
    p6.showPerson();
    

    //base of teacher
    Date d7(2,2,2005);
    Address a7("32 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
    Teacher t7("Naomi","Sama",d7,a7,"ComSci","Ramkhamhaeng","RAM1201");
    t7.showPerson();
    t7.showTeacher();

    //base of student
    Date d8(9,9,2009);
    Address a8("35 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
    Student s8("miki","Urasawa",d8,a8,"660502","sci","Ramkhamhaeng");
    s8.showPerson();
    s8.showStudent();

    // show address
    Address a9("101/17 ","เนินพระ","เมือง","ระยอง",20100);
    a9.showAddress();

    //show date
    Date d10(24,02,2005);
    d10.showDate();
    */
   
    cout << "\n===== destructor =====" << endl;

    return 0;
}
