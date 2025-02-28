#include <iostream>
using namespace std;


class Person{
    protected:
        string name;
        int age;


    public:
        Person(string n, int a) : name(n), age(a){}


        void display(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
};

class Teacher : public Person{
    protected:
        string subject;

    public:
        Teacher(string n, int a, string s) : Person(n, a),
            subject(s){}

        void display(){
            Person::display();
            cout << "Subject: " << subject << endl;
        }
};

class Researcher : public Person{
    public:
        string researchArea;

    public:
        Researcher(string n, int a, string ra) : Person(n, a),
            researchArea(ra){}

        void display(){
            Person::display();
            cout << "Research Area: " << researchArea << endl;
        }
};

class Professor : public Teacher, public Researcher{
    protected:
        int publications;


    public:
        Professor(string n, int a, string s, string ra, int p) : Teacher(n, a, s),
        Researcher(n,a,ra), publications(p){}


        void display(){
            Teacher::display();
            cout << "Research Area: " << researchArea << endl;
            cout << "Publications: " << publications << endl;
        }
};

int main(){
    Professor p1("Talha Shahid", 25, "OOP", "Gaming", 12);
    p1.display();

    return 0;
}

