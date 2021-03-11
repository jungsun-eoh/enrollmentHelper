//
//  student.h
//  Good_enough_Enroll_Helper
//
//
// FILE: student.h 
// TEMPLATE CLASS PROVIDED:
//   student<Item> (a collection of items; each item may appear multiple times)
//

#ifndef student_h
#define student_h

#include <cstdlib>   // Provides NULL and size_t and NULL
#include "courses.h"   // Provides courses class

template <class Item>
class student
{
public:
    // TYPEDEFS
    typedef std::size_t size_type;
    typedef Item value_type;
    typedef courses_iterator<Item> iterator;
    typedef const_courses_iterator<Item> const_iterator;
    // CONSTRUCTORS and DESTRUCTOR
    student( );
    ~student( );
    // MODIFICATION MEMBER FUNCTIONS
    bool erase_one(const Item& target); //  delete the selected course from the list
    void insert(const Item& entry, const course_info& entry1);  // add the course<Item> into the student<Item> list
    void operator +=(const student& addend);
    void operator =(const student& source);
    // CONST MEMBER FUNCTIONS
    bool select(Item& target, student<Item>& user_info, student<Item>& selected);
    //  check what subject that user already taken, and if user didn't take this class, it will register the course into the student list
    bool find_course(const Item& target);
    void print();
    void print(courses<Item> *index);
    bool isMaxUnits();
    size_type count(const Item& target) const;
    Item grab_course( ) const;
    size_type size( ) const { return many_courses; }
	// FUNCTIONS TO PROVIDE ITERATORS
	iterator begin( )
	    { return iterator(head_ptr); }
	const_iterator begin( ) const
	    { return const_iterator(head_ptr); }
	iterator end( )
	    { return iterator( ); } // Uses default constructor 
	const_iterator end( ) const
	    { return const_iterator( ); } // Uses default constructor 
private:
    courses<Item> *head_ptr;        // Head pointer for the list of items
    size_type many_courses;        // sum of units inside this list 
};

// NONMEMBER functions for the student
template <class Item>
student<Item> operator +(const student<Item>& b1, const student<Item>& b2);

#include "student.template"
#endif /* courses_h */

