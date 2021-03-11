//
//  course_info.h
//  Good_enough_Enroll_Helper
//

#ifndef course_info_h
#define course_info_h

#include <iostream>
#include <string>
#include <utility>
using namespace std;

class course_info
{
public:
    // CONSTRUCTOR
    course_info(const string& subject=(""), const int courseNum=(0), const size_t& unit=(0), const string& describe=(""), const pair<int, int> meet_time=make_pair(0,0), const int& requierment=(0))
    { title = subject; course_num = courseNum; units = unit; description = describe; meeting_time = meet_time; prerequisites = requierment; }
    course_info (const course_info &source)
    {
        this->set_title(source.class_title());
        this->set_course_num(source.class_course_num());
        this->set_unit(source.class_units());
        this->set_description(source.class_description());
        this->set_prerequisites(source.class_prerequisites());
        this->set_meet_time(source.class_meeting_time());
    }
    // MODIFICATION MEMBER FUNCTIONS
    string class_title() { return title; }
    int class_course_num() { return course_num; }
    size_t class_units() { return units; }
    string class_description() { return description; }
    pair<int, int> class_meeting_time() { return meeting_time; }
    int class_prerequisites() { return prerequisites; }
    void set_title (const string& new_data) { title = new_data; }
    void set_course_num(const int& new_data) { course_num = new_data; }
    void set_unit(const size_t& new_data) { units = new_data; }
    void set_description(const string& new_data) { description = new_data; }
    void set_meet_time(const pair<int, int>& new_data) { meeting_time = new_data; }
    void set_prerequisites(const int& new_data) { prerequisites = new_data; }
    const string class_title() const { return title; }
    const int class_course_num() const{ return course_num; }
    const size_t class_units() const { return units; }
    const string class_description() const { return description; }
    const pair<int, int> class_meeting_time() const { return meeting_time; }
    const int class_prerequisites() const { return prerequisites; }
    
protected:
    string title;   // class name
    int course_num; // class section number
    size_t units;   // class unit
    string description; // class description
    pair<int, int> meeting_time;    // meeting hour
    int prerequisites;  // requirement
};


#endif /* course_info_h */
