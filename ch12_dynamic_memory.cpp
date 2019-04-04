// static memory: store static object/global variable
// stack: nonstatic local variable
// heap(free store): dynamic allocate, static/stack:conntrolled by compiler
#include<memory>
#include<iostream>
#include<string>
#include<vector>
using namespace ::std;
// -----------------------------------------------------------
int main(){
// smart pointer: mangage dynamic memory, shared_ptr, unique_ptr, operations in Table 12.1-12.2
// make_shared: construct object of int(value 6), return shared_ptr
    shared_ptr<int> sPtr= make_shared<int> (6);
    auto sPtr1=make_shared<int> (2);
    sPtr1=sPtr;// --sPtr.use_count(), ++sPtr1.use_count(); if counter=0, destroy the object(in memory)
// dp: build-in ptr to unnamed int of 0
    int *dp=new int();
    int *dpNT=new(nothrow) int(5);//(nothrow): donnot throw exception
// memory leak: old memory pointed by dpNT(new int 5) is not freed
    dpNT=dp;
    delete dp;// must destory object after used
// bind build-in ptr to smart ptr
    shared_ptr<int> ptr1(new int());
// -----------------------------------------------------
// unique_ptr: own the object, initialize with new, no assign/copy
    unique_ptr<string> pd1(new string("hello"));
    unique_ptr<string> pd2(pd1.release());// transfer ownership from pd1 to pd2
// pd2.reset(pd1.release());
// -------------------------------------------------------
// weak_ptr: bind with shared_ptr, no change for counter
// EX 10.24, read string from cin into dynamic array
    size_t length;
    cin>>length;cin.ignore();
// dynamic array(no begin(), end(), range for), return *first_elem
    char *pa=new char[length+1];
    cin.get(pa, length+1);
    cout<<"input string: "<<pa<<endl;
    delete [] pa;// must have []
// -------------------------------------------------------
// EX 12.26, initialize string with allocator
//  alloc: define an allocator object
    allocator<string> alloc;
    string *p=alloc.allocate(10);// assigned unconstructed memory for 10 strings
    string *q=p;string s;
    while (cin>>s &&q!=p+10) {
        alloc.construct(q++,s);// construct memory
    }
    uninitialized_fill(q,p+10,"abc");// initialize the remaining strings with abc
    while(q!=p)
        alloc.destroy(--q);// destroy the elements
    alloc.deallocate(p,10);// free the memory
    return 0;
}


