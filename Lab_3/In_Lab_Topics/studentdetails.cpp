#include <iostream>
using namespace std;

class Student{
    private:
        int rollno;
        string name;
        string courseName;
        float gpa;


    public:
        void setValues(int r, string Name, string CourseName, float Gpa){
            rollno = r;
            name = Name;
            courseName = CourseName;
            gpa = Gpa;
        }

        int getRollNo(){
            return rollno;
        }

        string getName(){
            return name;
        }

        string getCourseName(){
            return courseName;
        }

        float getGPA(){
            return gpa;
        }




};


int main(){
    Student s1;

    s1.setValues(855, "Omer", "OOP Lab", 4.0);

    cout << "Name: " << s1.getName() << endl;
    cout << "Roll Number: " << s1.getRollNo() << endl;
    cout << "Course Name: " << s1.getCourseName() << endl;
    cout << "GPA: " << s1.getGPA() << endl;

    return 0;
}