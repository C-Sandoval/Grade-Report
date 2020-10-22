#include <iostream>
#include <string>

#include "Student.h"

Student::Student(){
    firstName = "none";
    lastName = "none";
    Test1 = 0;
    Test2 = 0;
    Test3 = 0;
    Test4 = 0;
    finalTestGrade = 0;
    testAverage = 0;
    finalGrade = ' ';
}

void Student::SetFirstName(string inputFirstName){
    firstName = inputFirstName;
}

void Student::SetLastName(string inputLastName){
    lastName = inputLastName;
}

string Student::GetName(){
    return firstName + " " + lastName;
}

void Student::SetTestGrade1(double testGrade1){
    Test1 = testGrade1;
}

void Student::SetTestGrade2(double testGrade2){
    Test2 = testGrade2;
}

void Student::SetTestGrade3(double testGrade3){
    Test3 = testGrade3;
}

void Student::SetTestGrade4(double testGrade4){
    Test4 = testGrade4;
}

double Student::GetTestGrade1(){
    return Test1;
}

double Student::GetTestGrade2(){
    return Test2;
}

double Student::GetTestGrade3(){
    return Test3;
}

double Student::GetTestGrade4(){
    return Test4;
}

void Student::SetFinalTestGrade(int finalTest){
    finalTestGrade = finalTest;
}

double Student::GetFinalTestGrade(){
    return finalTestGrade;
}

double Student::TestAverage(){
    int sumOfTests = 0;

    sumOfTests += (Test1 + Test2 + Test3 + Test4) + (2 * finalTestGrade);

    testAverage = sumOfTests / 6;

    return testAverage;
}

char Student::FinalGrade(){
    if(testAverage >= 90){
        finalGrade = 'A';
    }
    else if((testAverage <= 89) && (testAverage >= 80)){
        finalGrade = 'B';
    }
    else if((testAverage <= 79) && (testAverage >= 70)){
        finalGrade = 'C';
    }
    else if((testAverage <= 69) && (testAverage >= 60)){
        finalGrade = 'D';
    }
    else if(testAverage <= 59){
        finalGrade = 'F';
    }

    return finalGrade;
}