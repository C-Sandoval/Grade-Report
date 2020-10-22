#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include "Class.h"
#include "Student.h"


ClassRoom::ClassRoom(){
    test1Average = 0;
    test2Average = 0;
    test3Average = 0;
    test4Average = 0;
    finalTestAverage = 0;
}    

void ClassRoom::SetTest1Average(vector<Student> Class){
    double Test1Scores = 0;
    Student currStudent;
    
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        Test1Scores += currStudent.GetTestGrade1();
    }
    
    test1Average = Test1Scores / Class.size();
}

void ClassRoom::SetTest2Average(vector<Student> Class){
    double Test2Scores = 0;
    Student currStudent;
    
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        Test2Scores += currStudent.GetTestGrade2();
    }
    
    test2Average = Test2Scores / Class.size();
}
        
void ClassRoom::SetTest3Average(vector<Student> Class){
    double Test3Scores = 0;
    Student currStudent;
    
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        Test3Scores += currStudent.GetTestGrade3();
    }
    
    test3Average = Test3Scores / Class.size();
}

void ClassRoom::SetTest4Average(vector<Student> Class){
    double Test4Scores = 0;
    Student currStudent;
    
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        Test4Scores += currStudent.GetTestGrade4();
    }
    
    test4Average = Test4Scores / Class.size();
}

void ClassRoom::SetFinalTestAverage(vector<Student> Class){
    double FinalTestScores = 0;
    Student currStudent;
    
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        FinalTestScores += currStudent.GetFinalTestGrade();
    }
    
    finalTestAverage = FinalTestScores / Class.size();
}

double ClassRoom::GetTest1Average(){
    return test1Average;
}

double ClassRoom::GetTest2Average(){
    return test2Average;
}

double ClassRoom::GetTest3Average(){
    return test3Average;
}

double ClassRoom::GetTest4Average(){
    return test4Average;
}

double ClassRoom::GetFinalTestAverage(){
    return finalTestAverage;
}

void ClassRoom::OuptutHighestTestGrades(vector<Student> Class, ofstream& outFS){
    Student currStudent;
    double highestTest1Score = 0;
    double highestTest2Score = 0;
    double highestTest3Score = 0;
    double highestTest4Score = 0;
    double highestFinalTestScore = 0;

    
    
    //Finds the highest test scores
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        
        if(highestTest1Score < currStudent.GetTestGrade1()){
            highestTest1Score = currStudent.GetTestGrade1();
        }
        if(highestTest2Score < currStudent.GetTestGrade2()){
            highestTest2Score = currStudent.GetTestGrade2();
        }
        if(highestTest3Score < currStudent.GetTestGrade3()){
            highestTest3Score = currStudent.GetTestGrade3();
        }
        if(highestTest4Score < currStudent.GetTestGrade4()){
            highestTest4Score = currStudent.GetTestGrade4();
        }
        if(highestFinalTestScore < currStudent.GetFinalTestGrade()){
            highestFinalTestScore = currStudent.GetFinalTestGrade();
        }
        
    }
    
    //Searches Students with highest Test 1 Scores
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        
        if(currStudent.GetTestGrade1() == highestTest1Score){
            outFS << setw(4) << "#1" << setw(4) << "|";
            outFS << setw(16) << currStudent.GetName() << setw(5) << "|";
            outFS << setw(7) << currStudent.GetTestGrade1() << setw(6) << "|" << endl;
        }
    }
    
    //Searches Students with highest Test 2 Scores
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        
        if(currStudent.GetTestGrade2() == highestTest2Score){
            outFS << setw(4) << "#2" << setw(4) << "|";
            outFS << setw(16) << currStudent.GetName() << setw(5) << "|";
            outFS << setw(7) << currStudent.GetTestGrade2() << setw(6) << "|" << endl;
        }
    }
    
    
    //Searches Students with highest Test 3 Scores
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        
        if(currStudent.GetTestGrade3() == highestTest3Score){
            outFS << setw(4) << "#3" << setw(4) << "|";
            outFS << setw(16) << currStudent.GetName() << setw(5) << "|";
            outFS << setw(7) << currStudent.GetTestGrade3() << setw(6) << "|" << endl;
        }
    }
    
    
    //Searches Students with highest Test 4 Scores
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        
        if(currStudent.GetTestGrade4() == highestTest4Score){
            outFS << setw(4) << "#4" << setw(4) << "|";
            outFS << setw(16) << currStudent.GetName() << setw(5) << "|";
            outFS << setw(7) << currStudent.GetTestGrade4() << setw(6) << "|" << endl;
        }
    }
    
    //Searches Students with highest Final Test Scores
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        
        if(currStudent.GetFinalTestGrade() == highestFinalTestScore){
            outFS << setw(6) << "Final" << setw(2) << "|";
            outFS << setw(16) << currStudent.GetName() << setw(5) << "|";
            outFS << setw(7) << currStudent.GetTestGrade1() << setw(6) << "|" << endl;
        }
    }

}

void ClassRoom::OuptutTopStudents(vector<Student> Class, ofstream& outFS){
    Student currStudent;
    double Top1Grade = 0;
    double Top2Grade = 0;
    double Top3Grade = 0;
    
    //Looks for highest class grade
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        
        if(Top1Grade < currStudent.TestAverage()){
            Top1Grade = currStudent.TestAverage();
        }
    }
    
    //Looks for 2nd highest class grade
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        
        if((Top2Grade < currStudent.TestAverage()) && (currStudent.TestAverage() != Top1Grade)){
            Top2Grade = currStudent.TestAverage();
        }
    }
    
    //Looks for 3rd highest class grade
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        
        if((Top3Grade < currStudent.TestAverage()) && (currStudent.TestAverage() != Top1Grade) && (currStudent.TestAverage() != Top2Grade)){
            Top3Grade = currStudent.TestAverage();
        }
    }
    //Outputs #1 student
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        
        if(currStudent.TestAverage() == Top1Grade){
            outFS << setw(6) << "#1" << setw(5) << "|";
            outFS << setw(16) << currStudent.GetName() << setw(6) << "|";
            outFS << setw(8) << Top1Grade << setw(6) << "|" << endl;
            }
    }
    
    //Outputs #2 student
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        
        if(currStudent.TestAverage() == Top2Grade){
            outFS << setw(6) << "#2" << setw(5) << "|";
            outFS << setw(16) << currStudent.GetName() << setw(6) << "|";
            outFS << setw(8) << Top2Grade << setw(6) << "|" << endl;
            }
    }
    //Outputs #3 student
    for(int i = 0; i < Class.size(); i++){
        currStudent = Class.at(i);
        
        if(currStudent.TestAverage() == Top3Grade){
            outFS << setw(6) << "#3" << setw(5) << "|";
            outFS << setw(16) << currStudent.GetName() << setw(6) << "|";
            outFS << setw(8) << Top3Grade << setw(6) << "|" << endl;
            }
    }
    
}

