//
//  courses.h
//  Good_enough_Enroll_Helper
//
//  Provide a template class for courses(node) in a linked list.
//  Private valuables are information in each courses. 
//

#ifndef courses_h
#define courses_h

#include <cstdlib>   // Provides NULL and size_t
#include <iterator>  // Provides iterator and forward_iterator_tag
#include <string>
#include "course_info.h"
#include <iostream>
using namespace std;

template <class Item>
class courses
{
public:
    // TYPEDEF
    typedef Item value_type;
    // CONSTRUCTOR
    courses()
    {   course_detatil={}; course = 0; link_field = NULL; }
    courses(const course_info& source, const Item& init_data=Item(), courses* init_link=NULL)
    {   course_detatil = source; course = init_data; link_field = init_link; }
    // MODIFICATION MEMBER FUNCTIONS
    Item& course_() { return course; }
    course_info course_detail_() { return course_detatil; }
    courses* link( ) { return link_field; }
    void set_course (const Item& new_data) { course = new_data; }
    void set_link(courses* new_link) { link_field = new_link; }
    void set_course_detatil ( course_info detail) { course_detatil = detail; }
    // CONST MEMBER FUNCTIONS
    void display ()
    {
        cout << "   ***************************************************** " << endl;
        cout << "       class : " << course_detatil.class_title() << endl;
        cout << "       section number : " << course_detatil.class_course_num() << endl;
        cout << "       description : " << course_detatil.class_description() << endl;
        cout << "       credits : " << course_detatil.class_units() << endl;
        cout << "       class meeting : " << course_detatil.class_meeting_time().first;
        cout << " - " << course_detatil.class_meeting_time().second << endl << endl;
    }
    const Item& course_() const { return course; }
    const courses* link( ) const { return link_field; }
    const course_info course_detail_() const { return course_detatil; }
private:
    course_info course_detatil; // every detail about this class
    Item course;    // course section number
    courses *link_field;
};

// FUNCTIONS to manipulate a linked list:
template <class Item>
void list_clear(courses<Item>*& head_ptr);

/*
template <class Item>
void list_copy
(const courses<Item>* source_ptr, courses<Item>*& head_ptr, courses<Item>*& tail_ptr);
 */   
template <class Item>
void list_head_insert(courses<Item>*& head_ptr, const Item& entry, const course_info& entry1);
    
template <class Item>
void list_head_remove(courses<Item>*& head_ptr);
    
template <class Item>
void list_insert(courses<Item>* previous_ptr, const Item& entry, const course_info& entry1);
    
template <class Item>
std::size_t list_length(const courses<Item>* head_ptr);
    
template <class coursesPtr, class SizeType>
coursesPtr list_locate(coursesPtr head_ptr, SizeType position);
    
template <class Item>
void list_remove(courses<Item>* previous_ptr);
    
template <class coursesPtr, class Item>
coursesPtr list_search(coursesPtr head_ptr, const Item& target);
    
// FORWARD ITERATORS to step through the coursess of a linked list
// A courses_iterator of can change the underlying linked list through the
// * operator, so it may not be used with a const courses. The
// courses_const_iterator cannot change the underlying linked list
// through the * operator, so it may be used with a const courses.
// WARNING:
// This classes use std::iterator as its base class;
// Older compilers that do not support the std::iterator class can
// delete everything after the word iterator in the second line:
    
template <class Item>
class courses_iterator
: public std::iterator<std::forward_iterator_tag, Item>
{
public:
    courses_iterator(courses<Item>* initial = NULL)
    { current = initial; }
    Item& operator *( ) const
    { return current->course_(); }
    courses_iterator& operator ++( ) // Prefix ++
    {
        current = current->link( );
        return *this;
    }
    courses_iterator operator ++(int) // Postfix ++
    {
        courses_iterator original(current);
        current = current->link( );
        return original;
    }
    bool operator ==(const courses_iterator other) const
    { return current == other.current; }
    bool operator !=(const courses_iterator other) const
    { return current != other.current; }
private:
    courses<Item>* current;
};
    
template <class Item>
class const_courses_iterator
: public std::iterator<std::forward_iterator_tag, const Item>
{
public:
    const_courses_iterator(const courses<Item>* initial = NULL)
    { current = initial; }
    const Item& operator *( ) const
    { return current->course_(); }
    const_courses_iterator& operator ++( ) // Prefix ++
    {
        current = current->link( );
        return *this;
    }
    const_courses_iterator operator ++(int) // Postfix ++
    {
        const_courses_iterator original(current);
        current = current->link( );
        return original;
    }
    bool operator ==(const const_courses_iterator other) const
    { return current == other.current; }
    bool operator !=(const const_courses_iterator other) const
    { return current != other.current; }
private:
    const courses<Item>* current;
};

#include "courses.template"
#endif /* courses_h */
