#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using namespace std;

class Student
{
public:
    Student();
    void SetFirstName(string inputFirstName);
    void SetLastName(string inputLastName);
    string GetName();
    void SetTestGrade1(double testGrade1);
    void SetTestGrade2(double testGrade2);
    void SetTestGrade3(double testGrade3);
    void SetTestGrade4(double testGrade4);
    double GetTestGrade1();
    double GetTestGrade2();
    double GetTestGrade3();
    double GetTestGrade4();
    void SetFinalTestGrade(int finalTest);
    double GetFinalTestGrade();
    double TestAverage();
    char FinalGrade();

private:
    string firstName;
    string lastName;
    double Test1;
    double Test2;
    double Test3;
    double Test4;
    double finalTestGrade;
    double testAverage;
    char finalGrade;
};

#endif