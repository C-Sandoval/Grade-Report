#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

#include "Student.h"
#include "Class.h"

void Table(string userResponse, vector<Student> Class,ofstream& outFS){
    Student currUser;
    ClassRoom CITClass;
    
    
    CITClass.SetTest1Average(Class);
    CITClass.SetTest2Average(Class);
    CITClass.SetTest3Average(Class);
    CITClass.SetTest4Average(Class);
    CITClass.SetFinalTestAverage(Class);
    
    
    //class table 
    outFS << setfill(' ') << setw(40) << right << "CIT " << userResponse << " Class Report" << endl;
    outFS << endl;
    
    outFS << setfill(' ') << setw(16) << left << "Student Name" << "|";
    outFS << setw(7) << " Test 1 " << "|";
    outFS << setw(7) << " Test 2 " << "|";
    outFS << setw(7) << " Test 3 " << "|";
    outFS << setw(7) << " Test 4 " << "|";
    outFS << setw(10) << " Final Test " << "|";
    outFS << setw(12) << " Test Average " << "|";
    outFS << setw(9) << " Class Grade " << "|" << endl;
    outFS << setfill('-') << setw(95) << "" << endl;
    
    outFS << setfill(' ');
    
    //Outputs details of each student in the Class vector
    for(int i = 0; i < Class.size(); i++){
        currUser = Class.at(i);
        outFS << setw(16) << left << currUser.GetName() << setw(2) << "|";
        outFS << setw(7) << currUser.GetTestGrade1() << setw(2) << "|";
        outFS << setw(7) << currUser.GetTestGrade2() << setw(3) << "|";
        outFS << setw(6) << currUser.GetTestGrade3() << setw(3) << "|";
        outFS << setw(6) << currUser.GetTestGrade4() << setw(6) << "|";
        outFS << setw(7) << currUser.GetFinalTestGrade() << setw(7) << "|";
        outFS << setw(8) << currUser.TestAverage() << setw(7) << "|";
        outFS << setw(7) << currUser.FinalGrade() << "|" << endl;
    }
    outFS << setfill('-') << setw(95) << "" << endl;
    outFS << setfill(' ');
    outFS << endl;
    
    //Outputs another table regarding the grade details
    outFS << right << setfill(' ') << setw(35) << "CIT " << userResponse << " Class Report Details" << endl;
    outFS << endl;
    outFS << setw(12) << right << " Test #1 Average " << "|";
    outFS << setw(12) << " Test #2 Average " << "|";
    outFS << setw(12) << " Test #3 Average " << "|";
    outFS << setw(12) << " Test #4 Average " << "|";
    outFS << setw(12) << " Final Test Average " <<  "|" << endl;;
    outFS << setfill('-') << setw(93) << "" << endl;
    
    outFS << setfill(' ');
    outFS << setw(11) << CITClass.GetTest1Average() << setw(7) << "|";
    outFS << setw(11) << CITClass.GetTest2Average() << setw(7) << "|";
    outFS << setw(11) << CITClass.GetTest3Average() << setw(7) << "|";
    outFS << setw(11) << CITClass.GetTest4Average() << setw(7) << "|";
    outFS << setw(12) << CITClass.GetFinalTestAverage() << setw(9) << "|";
    
    outFS << endl;
    outFS << setfill('-') << setw(93) << "" << endl;
    outFS << setfill(' ');
    outFS << endl;
    
    //Outputs table with the highest test grade
    outFS << setfill(' ') << setw(8) << "CIT " << userResponse << " Highest Test Grades" << endl;
    outFS << endl;
    outFS << setw(6) << right << "Test # " << "|";
    outFS << setw(20) << "Student Name    " << "|";
    outFS << setw(12) << " Test Score " << "|" << endl;
    outFS << setfill('-') << setw(42) << "" << endl;
    outFS << setfill(' ');
    CITClass.OuptutHighestTestGrades(Class, outFS);
    outFS << setfill('-') << setw(42) << "" << endl;
    outFS << setfill(' ');
    outFS << endl;
    
    //Outputs table with the top 3 students in the class based on their test average
    outFS << setfill(' ') << setw(11) << "CIT " << userResponse << " Top #3 Students" << endl;
    outFS <<endl;
    outFS << setw(6) << left << "Rank" << setw(5) << "|";
    outFS << setw(16) << "Student Name    " << "|";
    outFS << setw(12) << " Class Grade " << "|" << endl;
    outFS << setfill('-') << setw(42) << "" << endl;
    outFS << setfill(' ');
    CITClass.OuptutTopStudents(Class, outFS);
    outFS << setfill('-') << setw(42) << "" << endl;
    outFS << setfill(' ');
    
    outFS << endl;
   
}


int main(){
    Student User;
    vector<Student> Class1325;
    vector<Student> Class1350;
    ifstream inFS;        //input file stream
    ofstream outFS;      //output file stream
    string userResponse;
    string userInput;
    bool isOpen = true;
    string studentFirstName;
    string studentLastName;
    double test1;
    double test2;
    double test3;
    double test4;
    double finalTest;
    
    cout << "Hello User" << endl;
    
    outFS.open("GradeReport.txt");
    if (!outFS.is_open()) {
      cout << "Could not open file GradeReport.txt." << endl;
    }
    
    
    //Reads user input based on the class report it wants to see
    while(isOpen == true){
        cout << "Please select what class you would like to see its class report" << endl;
        cout << "> CIT 1325" << endl;
        cout << "> CIT 1350" << endl;
        cout << endl;
        cout << "Please enter the course number: ";
        cin >> userResponse;
        
        //If user enters anything else besides the course numbers
        if((userResponse != "1325") && (userResponse != "1350")){
            cout << "Invalid response. Please try again" << endl;
            cout << endl;
        }
        
        //Opens CIT1325.txt if chosen
        if(userResponse == "1325"){
        
            inFS.open("CIT1325.txt");
    
            if(!inFS.is_open()){
                cout << "Could not open the file" << endl;
                break;
            }
            cout << "Looking into class CIT 1325" << endl;
            cout << endl;
            
            //Reading text lines using inFS
            for(int i = 0; i < 25; i++){
                inFS >> studentFirstName;
                inFS >> studentLastName;
                inFS >> test1;
                inFS >> test2;
                inFS >> test3;
                inFS >> test4;
                inFS >> finalTest;
                
                if(!inFS.fail()){
                    User.SetFirstName(studentFirstName);
                    User.SetLastName(studentLastName);
                    User.SetTestGrade1(test1);
                    User.SetTestGrade2(test2);
                    User.SetTestGrade3(test3);
                    User.SetTestGrade4(test4);
                    User.SetFinalTestGrade(finalTest);
                }
                
                Class1325.push_back(User);
                inFS.clear();
                }
                
            Table(userResponse, Class1325, outFS);
            inFS.close();
            cout << "The CIT 1325 class report is finished" << endl;
            break;
            }
        
        //Opens CIT1350.txt if chosen    
        if(userResponse == "1350"){
        
            inFS.open("CIT1350.txt");
    
            if(!inFS.is_open()){
                cout << "Could not open the file" << endl;
                break;
            }
            
            cout << "Looking into class CIT 1350" << endl;
            cout << endl;
            
            //Reading text lines using inFS
            for(int i = 0; i < 20; i++){
                inFS >> studentFirstName;
                inFS >> studentLastName;
                inFS >> test1;
                inFS >> test2;
                inFS >> test3;
                inFS >> test4;
                inFS >> finalTest;
                
                if(!inFS.fail()){
                    User.SetFirstName(studentFirstName);
                    User.SetLastName(studentLastName);
                    User.SetTestGrade1(test1);
                    User.SetTestGrade2(test2);
                    User.SetTestGrade3(test3);
                    User.SetTestGrade4(test4);
                    User.SetFinalTestGrade(finalTest);
                }
                
                Class1350.push_back(User);
                inFS.clear();
            }
            
            Table(userResponse, Class1350, outFS);
            cout << "The CIT 1350 class report is finished" << endl;
            inFS.close();
            break;
            }
    }
    
    cout << endl;
    
    //Reads user input if it wants to see the other class report
    while(isOpen == true){
        cout << "Would you also like to see the other class's grade report?" << endl;
        cout << "(Yes/No): ";
        cin >> userInput;
        
        //If user enters anything else besides YES or NO
        if((userInput != "Yes") && (userInput != "No")){
            cout << "Invalid response. Please try again" << endl;
            cout << endl;
        }
        
        if(userInput == "Yes"){
            
            //Opens CIT1325.txt if CIT1350 was chosen first 
            if(userResponse == "1350"){
                userResponse = "1325";
                inFS.open("CIT1325.txt");
        
                if(!inFS.is_open()){
                    cout << "Could not open the file" << endl;
                    break;
                }
                cout << "Looking into class CIT 1325" << endl;
                cout << endl;
                
                //Reading text lines using inFS
                for(int i = 0; i < 25; i++){
                    inFS >> studentFirstName;
                    inFS >> studentLastName;
                    inFS >> test1;
                    inFS >> test2;
                    inFS >> test3;
                    inFS >> test4;
                    inFS >> finalTest;
                    
                    if(!inFS.fail()){
                        User.SetFirstName(studentFirstName);
                        User.SetLastName(studentLastName);
                        User.SetTestGrade1(test1);
                        User.SetTestGrade2(test2);
                        User.SetTestGrade3(test3);
                        User.SetTestGrade4(test4);
                        User.SetFinalTestGrade(finalTest);
                    }
                    
                    Class1325.push_back(User);
                    inFS.clear();
                    }
                    
                Table(userResponse, Class1325, outFS);
                inFS.close();
                cout << "The CIT 1325 class report is finished" << endl;
                cout << endl;
                cout << "Please look at the Grade Report file to view report" << endl;
                cout << "YOur session has now ended" <<endl;
                break;
                }
            
            //Opens CIT1350.txt if CIT1325 was chosen first   
            if(userResponse == "1325"){
                userResponse = "1350";
                inFS.open("CIT1350.txt");
        
                if(!inFS.is_open()){
                    cout << "Could not open the file" << endl;
                    break;
                }
                
                cout << "Looking into class CIT 1350" << endl;
                cout << endl;
                
                //Reading text lines using inFS
                for(int i = 0; i < 20; i++){
                    inFS >> studentFirstName;
                    inFS >> studentLastName;
                    inFS >> test1;
                    inFS >> test2;
                    inFS >> test3;
                    inFS >> test4;
                    inFS >> finalTest;
                    
                    if(!inFS.fail()){
                        User.SetFirstName(studentFirstName);
                        User.SetLastName(studentLastName);
                        User.SetTestGrade1(test1);
                        User.SetTestGrade2(test2);
                        User.SetTestGrade3(test3);
                        User.SetTestGrade4(test4);
                        User.SetFinalTestGrade(finalTest);
                    }
                    
                    Class1350.push_back(User);
                    inFS.clear();
                }
                
                Table(userResponse, Class1350, outFS);
                cout << "The CIT 1350 class report is finished" << endl;
                cout << endl;
                cout << "Please look at the Grade Report file to view report" << endl;
                cout << "Your session has now ended" <<endl;
                inFS.close();
                break;
                }
        }
        
        else if(userInput == "No"){
            cout << endl;
            cout << "Your session has now ended" << endl;
            cout << "Please look at the Grade Report file to view report" << endl;
            break;
        }
        
    }
    
     outFS.close();
    
    return 0;
}