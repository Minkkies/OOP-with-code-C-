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
        cout << "delete " << day << "/" << month << "/" << year << endl;
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
        cout << "\ndelete Address " << endl;
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
        cout << "\ndelete " << fname << " " << lname << endl;
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

class Student :virtual public Person
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
        cout << "\nbye Student" << endl;
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
        cout << "\nStudent: " << getFname() << " " << getLname() << endl;
        cout << "university: " << university << endl;
        cout << "faculty: " << fac << endl;
        cout << "Student ID : " << stdNum << endl;
    }
};

class Teacher :virtual public Person
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
        cout << "\nbye Teacher" << endl;
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
        cout << "\nTeacher: " << getFname() << " " << getLname() << endl;
        cout << "university: " << university << endl;
        cout << "faculty: " << fac << endl;
        cout << "Course ID : " << course << endl;
    }
};

//ข้อ7.2
class TAssistant : public Student, public Teacher{
private:
    char email[100];// อีเมล
    char courseAssign[20];// วิชาที่รับผิดชอบ
    char professor[100]; // อาจารย์ที่ดูแล
    int yearOfStudy;//ชั้นปี
public:
    TAssistant()
    {
        setTAssistant("none", "none", "none",0);
    }

    TAssistant(char *e, char *ca, char *pf, int yos)
    {
        setTAssistant(e, ca, pf ,yos);
    }

    /*--------single inherit-------------
        เป็นการกำหนดค่าเริ่มต้นให้คลาสแม่ 2 คลาสทำให้โค้ดมีค.ยืดหยุ่นมากขึ้นแต่ก็ควรระวังอาจทำให้โค้ดซับซ้อนและเข้าใจยากขึ้น 
        โดยเฉพาะถ้ามีการสืบทอดจากหลายๆ คลาสที่มีโครงสร้างซับซ้อน
    TAssistant(char *id, char *f1, char *u,char *f2, char *u1, char *c,char *e, char *ca,
                char * pf, int yos): Student(id, f1, u),Teacher(f2, u1, c) 
    {
        setTAssistant(e,ca,pf,yos);
    }*/

    /*---------multiple inheri-------------
        กรณีต้องการ set ค่าเริ่มต้นให้ Person ด้วย
        กรณี multiple inheritance ต้องสั่งแบบนี้มันถึงจะขึ้นไปทำตามที่สั่ง ไม่งั้นมันจะไปเรียก default constructor เสมอ*/
        //setค่าเริ่มต้นให้นักเรียนกับครูโดนการไปเรียกcontructorที่ตรงกับพารามิเตอร์
        //เป็นการsetค่าเริ่มต้นให้personไปในตัวเพราะนักเรียนและครูต้องการค่าเริ่มต้นของperson
        //กำหนดค่าเริ่มต้นให้กับตัวแปรและช่วยให้ TAssistant สามารถใช้งาน attributes ของคลาสพื้นฐานได้
    TAssistant(char *f, char *l, Date & d, Address &a,char * id, char *f1,char*u, char * f2,char*u1,
            char* c, char *e,char *ca, char *pf,int yos) :Person(f,l,d,a),Student(id, f1, u),Teacher(f2, u1, c)
    {
        setTAssistant(e, ca, pf,yos);
    }

    ~TAssistant()
    {
        cout << "\nbye Teaching Assistant" << endl;
    }

    // set
    void setTAssistant(char *e, char *ca, char *pf,int yos)
    {
        strcpy(email, e);
        strcpy(courseAssign, ca);
        strcpy(professor, pf);
        yearOfStudy=yos;
    }

    void setEmail(char *e)
    {
        strcpy(email, e);
    }

    void setCourseAssign(char *ca)
    {
        strcpy(courseAssign, ca);
    }

    void setProfessor(char *pf)
    {
        strcpy(professor, pf);
    }

    void setYearOfStudy(int yos)
    {
        yearOfStudy=yos;
    }

    // get
    char* getEmail()
    { 
        return email; 
    }

    char* getCourseAssign()
    { 
        return courseAssign; 
    }

    char* getProfessor()
    { 
        return professor;
    }

    int getyearOfStudy()
    {
        return yearOfStudy;
    }

    void showTAssistant()
    {
        cout << "\nTeaching Assistant: " << getFname() << " " << getLname() << endl;
        cout << "Year of Study: " << yearOfStudy << endl;
        cout << "Email: " << email << endl;
        cout << "Assigned Course: " << courseAssign << endl;
        cout << "Professor: " << professor << endl;

    }
};



int main()
{
    //-------Teacher3--------
    Teacher t3;
    Date d3;
    d3.set(01, 04, 1954);
    Address a3;
    a3.setAddress("282 Ramkhamhaeng ", "Hua Mak", "Bang Kapi", "Bangkok", 10240);

    t3.setName("Kim","Hyunbin");
    t3.setTeacher("Science","Ramkhamhaeng","COS1101");
    t3.setBday(d3);
    t3.setAdd(a3);
    t3.showPerson();
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

    //----Teaching Assistant6----
    Date d6(14,02,2003);
    Address a6("15/2","Nikhomphatana","Nikhomphana","Rayong",21180);
    TAssistant ta6("Kimi","Noto",d6,a6,"660502","Science","Ramkhamhaeng","Science","Ramkhamhaeng",
                    "COS1101","xadcawda123@gmail.com","COS1101","Kim Hyunbin",3);
    
    ta6.showPerson();
    ta6.showStudent();
    cout << "\nTeaching Assistant: " <<ta6.getFname() << " " <<ta6.getLname() << endl;
    cout << "Year of Study: " <<ta6.getyearOfStudy() << endl;
    cout << "Email: " <<ta6.getEmail() << endl;
    cout << "Assigned Course: " <<ta6.getCourseAssign()<< endl;
    cout << "Professor: " <<ta6.getProfessor() << endl;

    //----Teaching Assistant7----
    TAssistant ta7;
    Date d7(13,06,2004);
    Address a7("111/12","Bankot","Bang-pa-in","Ayutthaya",13160);

    ta7.setName("Kun","Mhiw");
    ta7.setBday(d7);
    ta7.setAdd(a7);
    ta7.setStudent("660549","Medicine","Ramkhamhaeng");
    ta7.setTeacher("Medicine","Ramkhamhaeng","MED2100");
    ta7.setTAssistant("dcjajdkoda456@gmail.com","MED2100","Doctor.Kim",2);
    ta7.showPerson();
    ta7.showStudent();
    ta7.showTAssistant();
   
    cout << "\n===== destructor =====" << endl;

    return 0;
}