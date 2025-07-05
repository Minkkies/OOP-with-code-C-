#include <iostream>
#include <cstring>
using namespace std;

class Date
{
private:
    int day, month;
    int *year;

public:
    Date()
    {
        day = 0;
        month = 0;
        year = new int(0); // pointer=0 mean same with nullptr
    }

    Date(int day, int month)
    {
        this->day = day;
        this->month = month;
        this->year = new int(0);
    }

    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = new int(year);
    }

    ~Date()
    {
        cout << "delete " << " " << day << "/" << month << "/" << *year << endl;
        delete year;
    }

    // lab 9
    //-------copy con-------
    Date(const Date &d)
    {
        cout << "Copy constructor" << endl;
        this->day = d.day;
        this->month = d.month;
        this->year = new int(*d.year);
        /* if (d.year != 0)
        {
             this->year=new int (d.year);
        }
        else
        {
            this->year= 0;
        }*/
    }

    //------assign operator------
    Date &operator=(const Date &d)
    {
        if (this == &d)
        {
            cout << "same object" << endl;
            return *this;
        }
        this->day = d.day;
        this->month = d.month;
        *year = *d.year; // element = element already convert
        return *this;
    }

    // set
    void set(int d, int m, int y)
    {
        this->day = d;
        this->month = m;
        *this->year = y;
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
        *year = y;
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
        return *year; // convert เอาเลขปีออกไม่ได้เอาตน.ออก
    }

    // show
    void showDate()
    {
        cout << "\n===== show Date =====" << endl;
        cout << " " << day << "/" << month << "/" << *year << endl;
    }

    // ostream , istream
    friend ostream &operator<<(ostream &os, const Date &d);
    friend istream &operator>>(istream &is, Date &r);
};

// ostream , istream
ostream &operator<<(ostream &os, Date &d)
{
    d.showDate();
    return os;
}

istream &operator>>(istream &is, Date &d)
{
    int year;
    cout << "Enter day: ", is >> d.day;
    cout << "Enter mont: ", is >> d.month;
    cout << "Enter year: ", is >> year; // convert ไม่งั้นจะเป็นการใส่ค่าให้pointer
    d.setYear(year);
    return is;
}

class Address
{
private:
    string Hnum;        // บ้านเลขที่
    string subDistrict; // แขวง,ตำบล
    string district;    // อำเภอ,เขต
    string *province;
    int postcode;

public:
    Address()
    {
        Hnum = "N/A";
        subDistrict = "N/A";
        district = "N/A";
        province = new string("N/A");
        postcode = 0;
    }
    Address(string n, string s, string d, string p, int c)
    {
        Hnum = n;
        subDistrict = s;
        district = d;
        province = new string(p);
        postcode = c;
    }
    ~Address()
    {
        cout << "\ndelete Address " << endl;
        delete province;
    }
    //-------copy con-------
    Address(const Address &ad)
    {
        cout << "Copy constructor" << endl;
        Hnum = ad.Hnum;
        subDistrict = ad.subDistrict;
        district = ad.district;
        postcode = ad.postcode;

        if (ad.province != 0)
        {
            province = new string(*ad.province);
        }
        else
        {
            cout << "province = 0 " << endl;
            province = 0;
        }
    }

    //------assign operator------
    Address &operator=(const Address &ad)
    {
        if (this == &ad)
        {
            cout << "same object" << endl;
            return *this;
        }
        Hnum = ad.Hnum;
        subDistrict = ad.subDistrict;
        district = ad.district;
        postcode = ad.postcode;
        *province = (*ad.province);

        return *this;
    }

    void setAddress(string n, string s, string d, string p, int c)
    {
        Hnum = n;
        subDistrict = s;
        district = d;
        *province = p;
        postcode = c;
    }
    void setHouseNum(string n)
    {
        Hnum = n;
    }
    void setSubDistrict(string s)
    {
        subDistrict = s;
    }
    void setDistrict(string d)
    {
        district = d;
    }
    void setProvince(string p)
    {
        *province = p;
    }
    void setPostCode(int c)
    {
        postcode = c;
    }

    // get
    string getHouseNum()
    {
        return Hnum;
    }
    string getSubDistrict()
    {
        return subDistrict;
    }
    string getDistrict()
    {
        return district;
    }
    string getProvince()
    {
        return *province;
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
        cout << "Province: " << *province << endl;
        cout << "Post code: " << postcode << endl;
    }

    // ostream , istream
    friend ostream &operator<<(ostream &os, const Address &ad);
    friend istream &operator>>(istream &is, Address &ad);
};

ostream &operator<<(ostream &os, const Address &ad)
{
    cout << "\n======== show Address ========" << endl;
    cout << "\nHouse Number: " << ad.Hnum << endl;
    cout << "SubDistrict: " << ad.subDistrict << endl;
    cout << "District: " << ad.district << endl;
    cout << "Province: " << *ad.province << endl;
    cout << "Post code: " << ad.postcode << endl;
    return os;
}

// istream
istream &operator>>(istream &is, Address &ad)
{
    string n, s, d, p;
    int c;
    cout << "House Number: ";
    is >> n;
    cout << "SubDistrict: ";
    is >> s;
    cout << "District: ";
    is >> d;
    cout << "Province: ";
    is >> p;
    cout << "Post code: ";
    is >> c;
    ad.setAddress(n, s, d, p, c);
    return is;
}

class Person
{
private:
    static int num;
    string *name;
    Date bday;   // Composition
    Address add; // Composition
public:
    Person() //: Date(0,0,0) ถ้าชื่อเกิดวันที่กับที่อยู่ก็เกิดมันไปเรียกdefault
    {
        name = new string("N/A");
        num++;
    }

    Person(string n, Date &bd, Address &a)
    {
        add = a;
        bday = bd;
        name = new string(n);
        num++;
    }

    virtual ~Person()
    {
        cout << "\ndelete " << *name << endl;
        delete name;
        num--;
    }

    //-------copy con-------
    Person(const Person &p)
    {
        num++;
        cout << "Copy constructor" << endl;
        bday = p.bday;
        add = p.add;
        if (p.name != 0)
        {
            name = new string(*p.name);
        }
        else
        {
            cout << "name = 0 " << endl;
            name = 0;
        }
    }

    //------assign operator------
    Person &operator=(const Person &p)
    {
        if (this == &p)
        {
            cout << "same object" << endl;
            return *this;
        }
        bday = p.bday;
        add = p.add;
        *name = *p.name;
        return *this;
    }

    // set
    void setPerson(string n, Date &bd, Address &a)
    {
        *name = n;
        bday = bd;
        add = a;
    }

    void setName(string n)
    {
        *name = n;
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

    string getname()
    {
        return *name;
    }

    Date getBday()
    {
        return bday;
    }

    Address getAdd()
    {
        return add;
    }

    static int count()
    {
        return num;
    }

    // ostream
    virtual void print(ostream &os)
    {
        os << "\n===== print Person =====" << endl;
        os << "Person no. " << count() << endl;
        os << "  Name: " << *name << endl;
        bday.showDate();
        add.showAddress();
    }

    // istream
    virtual void input(istream &is)
    {
        string n;
        Date d;
        Address ad;
        cout << "\n======= input ======= " << endl;
        cout << "Enter Name: ";
        is >> n;
        setName(n);
        cout << endl;
        is >> d;
        setBday(d);
        cout << endl;
        is >> ad;
    }
    void showPerson(ostream &os)
    {
        // cout << "\n===== show Person =====" << endl;
        print(os);
    }
};

int Person ::num; // นับคน

class Student : virtual public Person
{
private:
    string stdNum;
    string fac;
    string *university;
    // Person* person;  Aggregation

public:
    /*Student(Person* p, const char* id, const char* f, const char* u) :person(p){} Aggregation */
    Student()
    {
        stdNum = "N/A";
        fac = "N/A";
        university = new string("N/A");
    }

    Student(string id, string f1, string u)
    {
        stdNum = id;
        fac = f1;
        university = new string(u);
    }

    // base ต้องใส่เสมอเพราะต้องไปเรียกconstructor ของคลาสแม่ก่อนทุกครั้ง
    Student(string n, Date &d, Address &a, string f1, string id, string u) : Person(n, d, a)
    {
        stdNum = id;
        fac = f1;
        university = new string(u);
    }

    // base Person(f, l, d, a)->>เรียกใช้งาน constructor ของคลาส Person เขียนได้2แบบ
    /*Student(char *f, char *l,Date& d, Address& a, char *id, char *fac ,char *u ):Person(f, l, d, a){
        setStudent(id,f,u);
    }*/

    ~Student()
    {
        cout << "\nbye Student" << endl;
        delete university;
    }

    // copy con------------
    Student(const Student &s) : Person(s)
    {
        // Person::operator=(s);
        cout << "\nStudent:: Copy constructer";
        stdNum = s.stdNum;
        fac = s.fac;

        if (s.university != 0)
        {
            university = new string(*s.university);
        }
        else
        {
            cout << "university = 0 " << endl;
            university = 0;
        }
    }
    //---------------------

    // operator =
    Student &operator=(const Student &s)
    {
        cout << "op= in Student" << endl;
        if (this == &s)
        {
            cout << "same Student" << endl;
            return *this;
        }
        Person::operator=(s);
        stdNum = s.stdNum;
        fac = s.fac;
        *university = *s.university;

        return *this;
    }

    // set
    void setStudent(string id, string f1, string u)
    {
        stdNum = id;
        fac = f1;
        *university = u;
    }

    void setStdNum(string id)
    {
        stdNum = id;
    }

    void setFaculty(string f1)
    {
        fac = f1;
    }

    void setUniversity(string u)
    {
        *university = u;
    }

    // get
    string getStdNum()
    {
        return stdNum;
    }
    string getFaculty()
    {
        return fac;
    }

    string getUniversity()
    {
        return *university;
    }

    // ostream
    void print(ostream &os)
    {
        Person::print(os);

        os << "Student: " << getname() << endl;
        os << "university: " << *university << endl;
        os << "faculty: " << fac << endl;
        os << "Student ID : " << stdNum << endl;
    }

    // istream
    void input(istream &is)
    {
        Person::input(is);

        string uni, fac, id;
        cout << "university: ";
        is >> uni;
        setUniversity(uni);
        cout << "faculty: ";
        is >> fac;
        setFaculty(fac);
        cout << "Student ID : ";
        is >> id;
        setStdNum(id);
    }

    // show
    void showStudent(ostream &os)
    {
        // cout <<"===== show Student =====" <<endl;
        print(os);
    }
};

class Teacher : virtual public Person
{
private:
    string fac1;
    string university1;
    string *course;
    // Person* person;  Aggregation
public:
    /*Teacher(Person* p, const char* f, const char* u, const char* c, double s) :person(p)*/
    Teacher()
    {
        fac1 = "N/A";
        university1 = "N/A";
        course = new string("N/A");
    }

    Teacher(string f2, string u1, string c)
    {
        fac1 = f2;
        university1 = u1;
        course = new string(c);
    }

    Teacher(string n, Date &d, Address &a, string f2, string u1, string c) : Person(n, d, a)
    {
        fac1 = f2;
        university1 = u1;
        course = new string(c);
    }

    ~Teacher()
    {
        cout << "\nbye Teacher" << endl;
        delete course;
    }

    // copy con------------
    Teacher(const Teacher &t) : Person(t)
    {
        // Person::operator=(t);
        cout << "\nTeacher:: Copy constructer";
        fac1 = t.fac1;
        university1 = t.university1;

        if (t.course != 0)
        {
            course = new string(*t.course);
        }
        else
        {
            cout << "course = 0 " << endl;
            course = 0;
        }
    }
    //---------------------

    // operator =
    Teacher &operator=(const Teacher &t)
    {
        cout << "op= in Teacher" << endl;
        if (this == &t)
        {
            cout << "same Teacher" << endl;
            return *this;
        }
        Person::operator=(t);
        fac1 = t.fac1;
        university1 = t.university1;
        *course = *t.course;

        return *this;
    }

    // set
    void setTeacher(string f2, string u1, string c1)
    {
        fac1 = f2;
        university1 = u1;
        *course = c1;
    }

    void setFaculty1(string f2)
    {
        fac1 = f2;
    }

    void setUniversity1(string u1)
    {
        university1 = u1;
    }

    void setCourse(string c1)
    {
        *course = c1;
    }

    // get
    string getCourse()
    {
        return *course;
    }
    string getFaculty1()
    {
        return fac1;
    }

    string getUniversity1()
    {
        return university1;
    }

    void showTeacher(ostream &o)
    {
        print(o);
    }

    // ostream
    void print(ostream &os)
    {
        Person::print(os);
        os << "\nTeacher: " << getname() << endl;
        os << "university: " << university1 << endl;
        os << "faculty: " << fac1 << endl;
        os << "Course ID : " << *course << endl;
    }

    // istream
    void input(istream &is)
    {
        Person::input(is);
        //------------------------
        string uni, fac, course;
        cout << "\nuniversity: ";
        is >> uni;
        setUniversity1(uni);
        cout << "faculty: ";
        is >> fac;
        setFaculty1(fac);
        cout << "Course: ";
        is >> course;
        setCourse(course);
    }
};


// ข้อ7.2
class TAssistant : public Student, public Teacher
{
private:
    string email;        // อีเมล
    string courseAssign; // วิชาที่รับผิดชอบ
    string *professor;   // อาจารย์ที่ดูแล
    int yearOfStudy;     // ชั้นปี
public:
    TAssistant()
    {
        email = "N/A";
        courseAssign = "N/A";
        professor = new string("N/A");
        yearOfStudy = 0;
    }

    TAssistant(string e, string ca, string pf, int yos)
    {
        email = e;
        courseAssign = ca;
        professor = new string(pf);
        yearOfStudy = yos;
    }

    TAssistant(string n, Date &d, Address &a, string id, string f1, string u, string f2, string u1,
               string c, string e, string ca, string pf, int yos) : Person(n, d, a), Student(id, f1, u), Teacher(f2, u1, c)
    {
        email = e;
        courseAssign = ca;
        professor = new string(pf);
        yearOfStudy = yos;
    }

    ~TAssistant()
    {
        cout << "\nbye Teaching Assistant" << endl;
        delete professor;
    }

    // copy con---------
    TAssistant(TAssistant &ta) : Student(ta), Teacher(ta), Person(ta)
    {
        // TAssistant::operator=(ta);
        cout << "\nTA:: coppy constructer";
        email = ta.email;
        courseAssign = ta.courseAssign;
        yearOfStudy = ta.yearOfStudy;

        if (ta.professor != 0)
        {
            professor = new string(*ta.professor);
        }
        else
        {
            cout << "professor = 0 " << endl;
            professor = 0;
        }
    }

    // operator =
    TAssistant &operator=(TAssistant &ta)
    {
        cout << "\nop= in TA" << endl;
        if (this == &ta)
        {
            cout << "same TA" << endl;
            return *this;
        }
        // Student::operator=(ta);
        // Teacher::operator=(ta);

        Student::setStdNum(ta.getStdNum());
        Student::setFaculty(ta.getFaculty());
        Student::setUniversity(ta.getUniversity());

        Teacher::setFaculty1(ta.getFaculty1());
        Teacher::setUniversity1(ta.getUniversity1());
        Teacher::setCourse(ta.getCourse());

        email = ta.email;
        courseAssign = ta.courseAssign;
        yearOfStudy = ta.yearOfStudy;
        *professor = *ta.professor;

        return *this;
    }
    // set
    void setTAssistant(string e, string ca, string pf, int yos)
    {
        email = e;
        courseAssign = ca;
        professor = new string(pf);
        yearOfStudy = yos;
    }

    void setEmail(string e)
    {
        email = e;
    }

    void setCourseAssign(string ca)
    {
        courseAssign = ca;
    }

    void setProfessor(string pf)
    {
        professor = new string(pf);
    }

    void setYearOfStudy(int yos)
    {
        yearOfStudy = yos;
    }

    // get
    string getEmail()
    {
        return email;
    }

    string getCourseAssign()
    {
        return courseAssign;
    }

    string getProfessor()
    {
        return *professor;
    }

    int getyearOfStudy()
    {
        return yearOfStudy;
    }

    // ostream
    void print(ostream &os)
    {
        Teacher::print(os);
        // Student::printStudent(os);
        os << "\nStudent: " << getname() << endl;
        os << "university: " << getUniversity1() << endl;
        os << "faculty: " << getUniversity() << endl;
        os << "Student ID : " << getStdNum() << endl;

        os << "\nTeaching Assistant: " << getname() << endl;
        os << "Year of Study: " << yearOfStudy << endl;
        os << "Email: " << email << endl;
        os << "Assigned Course: " << courseAssign << endl;
        os << "Professor: " << *professor << endl;
    }
    // istream
    void input(istream &is)
    {
        Teacher::input(is);
        // inputStudent(is);
        string uni, fac, id;
        cout << "\nuniversity: ";
        is >> uni;
        setUniversity(uni);
        cout << "faculty: ";
        is >> fac;
        setFaculty(fac);
        cout << "Student ID : ";
        is >> id;
        setStdNum(id);

        string e;
        string ca;
        string pf;
        int yos;
        cout << "\nTeaching Assistant" << endl;
        cout << "Email: " << endl;
        is >> e;
        setEmail(e);
        cout << "Assigned Course: " << endl;
        is >> ca;
        setCourseAssign(ca);
        cout << "Professor: " << endl;
        is >> pf;
        setProfessor(pf);
        cout << "Year of Study: " << endl;
        is >> yos;
        setYearOfStudy(yos);
    }

    // show
    void showTA(ostream &a)
    {
        print(a);
    }
};

//เกิดdynamic binding ที่a
ostream &operator<<(ostream &os, Person &a)
{
    a.print(os);
    return os;
}
istream &operator>>(istream &is, Person &a)
{
    a.input(is);
    return is;
}

int main()
{
    // assignment
    //   สร้างวัตถุ Date
    //----------------copy date----------------
    Date date1;
    date1.setDay(10);
    date1.setMonth(02);
    date1.setYear(2005);
    cout << "Date1: " << endl;
    cout << "===== get Date =====" << endl;
    cout << " " << date1.getDay() << "/" << date1.getMonth() << "/" << date1.getYear() << endl;
    // คัดลอกวัตถุ Date
    Date date2 = date1;
    cout << "\nDate2: " << endl;
    date2.showDate();
    //-----------------assign date---------------------
    Date date6(24,02,2005);
    cout << "Date6:" << endl;
    date6.showDate();
    cout << "---- Test Assignment  ----" << endl;
    date6=date2;
    cout << "Date 6 assign Date 2: "<<endl;
    date6.showDate();
    
    //-------------------copy Address-----------------
    Address addr1("123", "xyz", "uu", "nuio", 12345);
    cout << "Address1:" << endl;
    addr1.showAddress();
    Address addr2 = addr1;
    cout << "Address2:" << endl;
    cout << "House Number: " << addr2.getHouseNum() << endl;
    cout << "SubDistrict: " << addr2.getSubDistrict() << endl;
    cout << "District: " << addr2.getDistrict() << endl;
    cout << "Province: " << addr2.getProvince() << endl;
    cout << "Post code: " << addr2.getPostCode() << endl;

    //---------------------assign address-------------
    Address addr7("122/7","bangkapi","huamak","Bangkok",10254);
    cout << "Address7:" << endl;
    addr7.showAddress();
    cout << "---- Test Assignment  ----" << endl;
    addr7 = addr1;
    cout << "Address 7 assign Address 1: "<<endl;
    addr7.showAddress();

    //-----------------copy Person------------------
    Person person1("John Doe", date1, addr1);
    cout << "\n===== get Person =====" << endl;
    cout << "Person1:" << endl;
    person1.showPerson(cout);
    cout << "---- Test Copy ----" << endl;
    Person person2 = person1;
    cout << "Person2:" << endl;
    cout << " " << person2.getname();
    cout << person2.getBday().getDay() << "/" << person2.getBday().getMonth() << "/" << person2.getBday().getYear() << endl;
    cout << "House Number: " << person2.getAdd().getHouseNum() << endl;
    cout << "SubDistrict: " << person2.getAdd().getSubDistrict() << endl;
    cout << "District: " << person2.getAdd().getDistrict() << endl;
    cout << "Province: " << person2.getAdd().getProvince() << endl;
    cout << "Post code: " << person2.getAdd().getPostCode() << endl;
    //-----------------assign Person------------------
    Address addr5("636","Uni","Mueng","Mimiki",20159);
    Person person3("Adum Walker", date2, addr5);
    cout << "Person3:" << endl;
    person3.showPerson(cout);
    cout << "---- Test Assignment  ----" << endl;
    person3=person1;
    cout << "Person 3 assign Person1: "<<endl;
    person3.showPerson(cout);

    //-----------------copy Student------------------------
    Student student1("123456", "Engineering", "ABC University");
    student1.setPerson("Alice Smith", date1, addr1);
    cout << "===== get Student =====" << endl;
    cout << "Student1:" << endl;
    student1.showPerson(cout);
    cout << "Student" << endl;
    cout << "university: " << student1.Student:: getUniversity() << endl;
    cout << "faculty: " << student1.Student::getFaculty() << endl;
    cout << "Student ID : " << student1.Student::getStdNum() << endl;
    cout << "---- Test Copy ----" << endl;
    Student student2 = student1;
    cout << "Student2:" << endl;
    student2.showStudent(cout);
    //-----------------assign Student----------------------
    Date date5(11,01,2498);
    Student student3("74884","adada445","ahdua");
    student3.setPerson("ami usa",date5,addr1);
    cout << "Student3:" << endl;
    student3.showStudent(cout);
    cout << "---- Test Assignment  ----" << endl;
    student3=student1;
    cout << "\nStudent3 assign student1: "<<endl;
    student3.showStudent(cout);


    //----------------copy Teacher----------------------
    Date date4(18,07,2548);
    Address addr4("37 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",21025);
    Teacher teacher1("Science", "XYZ University", "SCI101");
    teacher1.setPerson("Dr. Brown", date4, addr4);
     cout << "\n===== get Teacher =====" << endl;
    teacher1.showPerson(cout);
    cout << "Teacher1:" << endl;
    cout << "university: " << teacher1.getUniversity1() <<endl;
    cout << "faculty: " << teacher1.getFaculty1() <<endl;
    cout << "Course: "<< teacher1.getCourse() <<endl;
    cout << "\n---- Test Copy ----" << endl;
    Teacher teacher2 = teacher1;
    cout << "Teacher2:" << endl;
    teacher2.showTeacher(cout);

    //--------------assign Teacher-------------------
    Teacher teacher3("sci","Ramkhamhaeng","COS2102");
    teacher3.setPerson("naoki ursawa", date4, addr1);
    cout << "Teacher 3:" << teacher3 << endl;
    cout << "\n---- Test Assignment  ----" << endl;
    teacher3=teacher2;
    cout << "\nteacher3 assign teacher2: "<<endl;
    teacher3.showTeacher(cout);


    //--------------copy TAssistant-------------------
    TAssistant ta1;
    ta1.setPerson("Bob Johnson", date1, addr1);
    ta1.setStudent("654321", "Science", "XYZ University");
    ta1.setTeacher("Science", "XYZ University", "SCI101");
    cout << "\n===== get TeachingAssistant =====" << endl;
    ta1.showPerson(cout);
    ta1.showStudent(cout);
    ta1.showTeacher(cout);
    cout << "\nTeaching Assistant: " << ta1.getname() << endl;
    cout << "Year of Study: " << ta1.getyearOfStudy() << endl;
    cout << "Email: " << ta1.getEmail() << endl;
    cout << "Assigned Course: " << ta1.getCourseAssign() << endl;
    cout << "Professor: " << ta1.getProfessor() << endl;

    cout << "Teaching Assistant 1:" << endl<< ta1 << endl;
    cout << "\n---- Test Copy ----" << endl;
    TAssistant ta2 = ta1;
    cout << "\nta2 copy ta1: "<<endl;
    ta2.showTA(cout);
    

    //------------ assign TAssistant----------------------
    Date date3(25, 02, 2021);
    Address addr3("68 Ramkhamhaeng ", "Hua Mak", "Bang Kapi", "Bangkok", 10240);
    TAssistant ta3;
    ta3.setPerson("Stubaki Fuyumi", date3, addr3);
    ta3.setStudent("660505", "Sci", "RU");
    ta3.setTeacher("Science", "Ramkhamhaeng", "2102");
    ta3.setTAssistant("ta@example.com", "SCI101", "Dr.Brown", 2);
    cout << "Teaching Assistant 3:" << endl
         << ta3 << endl;
    cout << "\n---- Test Assignment  ----" << endl;
    ta2 = ta3;
    cout << "\nta2 assign ta3: "<<endl;
    ta2.showTA(cout);

    // test os--------------------
    cout << "\n---- Test ostream ----" << endl;
    cout << "ta1: " << ta1;
    cout << "person2: " << person2;
    cout << "student1: " << student1;
    cout <<" Date6: "<<date6;
    cout <<" Address3: " <<addr3;

    // test is--------------------
    cout << "---- Test istream ----" << endl;
    cin >> date1;
    cout << "Date1: " << date1;
    cin >> person1;
    cout << "Person1: " << person1;
    cin >> student1;
    cout << "student1: " << student1;
    cin >> teacher1;
    cout << "teacher1: "<< teacher1;
    cin >> ta1;
    cout << "Teaching Assistant1: " << ta1;

    cout << "\n------ destructor ------"<<endl;

    return 0;
}