// data abstraction: design(outside) level, hide irrelevant details, focus on interface
// encapsulation: implementation(inner) level, hide code of class type, private
#include<iostream>
#include<string>
#include<vector>
using namespace ::std;
//----------------------------------------------------
// Ex 7.5, 7.9, 7.15, 7.19, operations on class: Person
// declare class: default private, construct: default public
class Person;
class Person{// must define class before use it
// interface accessed by all programs
public:
// member function: declared inside class, defined inside(inline) or outside class
// this: implicit function parameter, *const to class object
    string getName() const{// cosnt: const *this, object unchanged
        return this->name;// (*this).name, this can be omitted
   }
    string getAddress() const;
// constructor: member function of class name, initialize object, no return, nonconst
// default cosntructor, call with no argument, otherwise compiler synthesize default
    Person()=default;
// class name(parameters): class members(val) {}, omit member: default
    Person(const string ns): name(ns) {}
// explicit: no type conversion for single argument, inside class use, no copy=
    explicit Person(istream &);
// acessible ONLY to class member(function), encapsulate implementation
private:
    string name, address;
// friend: allow acess to nonpublic members
    friend istream &read(istream &is, Person &pd);
};
// define outside class, match declaration and const, inside class scope::
string Person::getAddress() const{
    return address;
}
// non-member function, define & declare outside class in header
// &is: pass &, no copy of IO types, &read: change I/Ostream
istream &read(istream &is, Person &pd){
    is>>pd.name>>pd.address;
    return is;
}
// constructor outside class
Person::Person(istream &is) {//ignore initialize list
    read(is, *this);// *this: whole object
}
//----------------------------------------------
class Screen{// must define class before use it
public:
// type members defined at begining, no redefined
    typedef size_t st;// using st=size_t
    Screen(st h, st w, char c): height(h), width(w), contents(h*w, c){}
// delagte the previous constructor, default constructor
    Screen(char cd):Screen(0,0,cd) {}
// return Screen&: Lvalue, change object itself(not a copy)
    Screen &move(st, st) {return *this;}
    Screen &set(char);
//  grant friendship to another class
    friend class Debug;
private:
    st height=0, width=0, cursor=0;
    mutable string contents;// mutuable: nonconst
    Screen *link_screen;// pointer to class
    st size() const;
};
// explicit inline: avoid overhead(unused memory)
inline Screen &Screen::set(char c){
    contents[cursor]=c;
    return *this;
}
// return type st before function name, also need class scope::
Screen::st Screen::size() const{
    return height*width;
}
class Debug{
public:
//  constexpr constructor: no body and return, initalize every member
    constexpr Debug(bool b): hw(b){}
//  static member: exist outside object, no *this or const
    static void test(bool);
private:
    bool hw;
    static Debug db;//declare static inside class, define outisde
};
//---------------------------------------------------
int main(){
    Person ps;// class Person ps
    read(cin,ps);
    char s;
 // implicit convert to class, myscreen(): function
    Screen myscreen(s);
// in-class initialize with {}, match argument
    vector<Screen> vscr{Screen(3,5,' ')};
    myscreen.move(2,1).set('%');// myscreen.move(2,1); myscreen.set('%')
    return 0;
}
