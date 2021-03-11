//
//  main.cpp
//  Good_enough_Enroll_Helper
//
//

#include <iostream>
#include <fstream>
#include <string>
#include "courses.h"
#include "student.h"
#include "course_info.h"
using namespace std;

void register_class(student<int>&, student<int>&, student<int>&);
//  check that user already took prerequites, and if user quilify, allow to register.
//  or cout warning.
void getClassInformation(string ,student<int>&);
//  read information from the file.

int main()
{
    student<int> course_book_2016SP;    //  All the course you could register this semester
    student<int> jungsun;   //  course information that user already took
    student<int> course_selected_2016SP;    //  course that user selects for this semester
    string file, file1;
    file = "good_course_2016FA.txt";    // All the course opened right now
    file1 = "took2016SP.txt";   // course user taken
    int answer(0);
    
    //  Get the course list and information for this semester from the file
    getClassInformation(file, course_book_2016SP);
    //  Get the course list and information that student already took from the file
    getClassInformation(file1, jungsun);
    
    cout << "       *** welcome to the register program ***" << endl;
    while (answer != -1)
    {
        cout << " [1] 2016FA  List of Courses" << endl;
        cout << " [2] 2016FA  Ready for selecting Course? " << endl;
        cout << " [3] 2016FA  Let's look what you select so far! " << endl;
        cout << " [4] List of Classes You already Complete! " << endl;
        cout << " [-1] Menu out" << endl;
        cin >> answer;
        switch (answer) {
            case 1:
                course_book_2016SP.print();
                break;
            case 2:
                register_class(course_selected_2016SP, jungsun, course_book_2016SP);
                break;
            case 3:
                course_selected_2016SP.print();
                break;
            case 4:
                jungsun.print();
                break;
            case -1:
                cout << "Good bye, See you next semester! " << endl;
                break;
            default:
                cout << "---Wrong Input---" << endl;
                break;
        }
    }
    return 0;
}

void register_class(student<int> &selected_course, student<int> &user, student<int> &book)
{
    int select(0);
    size_t maxUnits(19);
    bool isRegistered;
    course_info temp1;
    
    if(selected_course.size() <= maxUnits)
    {
        cout << "What class do you want to select? \n Input the course section num" << endl;
        cin >> select;
        isRegistered = book.select(select, user, selected_course);
        if (isRegistered) {
            cout << "class " << select << " is registered successly." << endl;
        }
        else
        {
            cout << "You already took this class..." << endl;
        }
    }
    else
        cout << "You already readched the maximum credit for this semester!\n" << endl;
    cout << endl;
}

void getClassInformation(string fileName ,student<int> &veco)
{
    string subject("");
    int section_num(0);
    size_t unit(0);
    string describe("");
    int meet_TimeS(0);
    int meet_TimeF(0);
    int requirement(0);
    pair<int, int> meet_Time;
    ifstream inStream;
    course_info temp;

    inStream.open(fileName);
    if (inStream.fail())
    {
        cout << "Input file opening error.\n";
        exit(1);
    }
    
    int i(0);
    do
    {
        inStream >> section_num >> subject >> unit >> describe >> requirement >> meet_TimeS >> meet_TimeF;
        meet_Time = make_pair(meet_TimeS,meet_TimeF);
        temp = {subject, section_num, unit, describe, meet_Time, requirement};
        veco.insert(section_num, temp);
        i++;
    }while(!inStream.eof());
    
    inStream.close();
}
