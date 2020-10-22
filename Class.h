#ifndef CLASS_H
#define CLASS_H

#include <vector>

#include "Student.h"

class ClassRoom{
    public:
        ClassRoom();    //Constructor
        void SetTest1Average(vector<Student> Class);
        void SetTest2Average(vector<Student> Class);
        void SetTest3Average(vector<Student> Class);
        void SetTest4Average(vector<Student> Class);
        void SetFinalTestAverage(vector<Student> Class);
        double GetTest1Average();
        double GetTest2Average();
        double GetTest3Average();
        double GetTest4Average();
        double GetFinalTestAverage();
        void OuptutHighestTestGrades(vector<Student> Class, ofstream& outFS);
        void OuptutTopStudents(vector<Student> Class, ofstream& outFS);
    private:
        double test1Average;
        double test2Average;
        double test3Average;
        double test4Average;
        double finalTestAverage;
};


#endif