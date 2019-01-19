# include <iostream>
# include <string> // string: variable-length of characters
# include <vector>// vector: container to hold same objects(no reference)
// declare names, using namespace::name, ::scope operator
using namespace::std; using std::cin;
//----------------------------------
// concatenate strings, change upper/lower case
void operate_string(){
    string s, cs;
// read unlimited string, cin>>s: read first word without space
    while (cin>>s)
// getline(source, target): read a line from istream
// s.empty(): TRUE for empty string
        if (!s.empty())
// concatenate string: at least one string for each +
        cs+=s+" ";
//---------------------------------------
// access and change element in a string
// for (element: object){body}, traverse the object, change cs, use &
    for (char &c:cs)
// detect non-blank character and convert to uppercase character
        if (!isspace(c))
           c=toupper(c);
    cout<<cs<<endl;
//------------------------------------------
// for-loop with subscript range: 0<=index<=cs.size()-1
// s.size(): length of string, unsigned size_type, use auto or decltype
    for (decltype (cs.size()) index=0; index!=cs.size(); ++index)
        if (!isspace(cs[index]))
            cs[index]=tolower(cs[index]);
    cout<<cs<<endl;
}
//-------------------------------------------
//EX 3.20, calculate sum of elements in vector
void operate_vector(){
    int ival;
    vector<int> v;
    while(cin>>ival)
// add element to vector, cannot use subscript for empty vector
        v.push_back(ival);
// print all elements use range for, ERROR: cout<<v, vector is not object
    for(auto cv:v)
        cout<<cv<<" ";
    cout<<endl;
// v.size(), v.empty(): same as string
    if (!v.empty())
        for(decltype (v.size()) ix=0; ix+1!=v.size();++ix)
            cout<<v[ix]+v[ix+1]<<'\0';
    cout<<endl;
//---------------------------------------
//use iterator, EX 3.24, symmetric sum, ib count from first, ie from last
    for (auto ib=v.begin(), ie=v.end()-1;ib<=ie;++ib,--ie)
        if(*ib==*ie)// check the median
            cout<<*ib;
        else
            cout<<*ib+*ie<<" ";
    cout<<endl;
}
//------------------------------------------
// EX3.22, convert text to uppercase
void operate_iterator(vector<string> v){
// define iter, begin(): first elem, end(): one past the end
    for(auto iter=v.begin();iter!=v.end();++iter){
// iter->empty(): (*iter).empty(), () is needed
        if(!iter->empty())
// check every char in string, character->string->vector
            for (auto &c:*iter)
                c=toupper(c);
        cout<<*iter<<endl;
    }
}
//------------------------------------
int main(){
// string initialize, Table 3.1
    string s1="hello world";// copy using =
    string s2("hiyou");// direct form
    string s3(5,'A');// s3: AAAAA
// compare strings: first different characters, s1<s2
// string operations, Table 3.2, SINGLE character: cctype, Table 3.3
// access character of strings: range for (traverse), subscript(index), iterator
    //operate_string();
//---------------------------------------------
// vector<template name>, instantate class type, initialize vector, Table 3.4
// (): construct vector(size, content), {}: list initialze, if not possible, construct object
    vector<int> v1(3); //3 elements of 0
    vector<int> v2{3,6,9}; // element: 3, 6, 9
    vector<string> v3{3,"yes"};// v3: 3 word "yes", since 3 is not string type
// operations on vector, Table 3.5
// access vector: range for, subscript(avoid), iterator, Table 3.6
    operate_vector();
//------------------------------------------------
// use iterator for container/strings, const_iterator: read-only, cbegin(), cend()
// opeations on iterator, Table 3.6 & 3.7, two iterators can be subtract, not add
    operate_iterator(v3);
//------------------------------------------------
// array: container of objects, fixed size(const size_t) and data type
// use list intialize, no copy() or assign, ERROR: int a1(ary)
    int ary[]={1,3,5,7,9};// omit size
    int *arrptr[5];//  arrptr: array of 5 pointers to int
    int (*ptrary)[5];// ptrary: pointer to arrary of 5 ints, raed from inside
// traverse array:range for, subscript, pointer(iterator, arthmetic operations, Table 3.6 & 3.7)
// pointer to first element:begin(ary), ary, &ary[0]
// off-the-end:end(ary), &ary[5], ary+5
    for (int *pa=ary+1;pa!=end(ary);++pa)
        cout<<pa[-1]<<" ";// pa[-1]: *(pa-1)
    cout<<endl;
// *(ary+5): ary[5], *ary+5: ary[0]+5
//-------------------------------------------------
// character arrays, terminate in null, operations in Table 3.8, ERROR use: +,-,<,>
   char ca[]="hello";//size: 6 (including null)
// use array to intialzie string or vector, no reverse, except c_str: return &s1[0]
   const char *str=s1.c_str();
   vector<int> vec1(ary, ary+3);//range from ary[0] to ary[2](one past last: ary[3])
// EX 3.42, initialize array from vector
   int av[3];
   int *ba=av;// int *ba=&av[0]
   for(auto iv:vec1)
       *ba++=iv;// first *ba=iv, then ba+1
//--------------------------------------------------
// multidimensional array: arrays of arrays, ia[row][column]
   int ia[2][3]={{3,5,6},{9}};// nest initialze with {}, 2nd rows: the ramining are 0
// access array: range for, pointer, subscript(size_t)
   for (auto &row:ia){// & is needed, else ia converted to a pointer
       for (auto col:row)
           cout<<col<<" ";
       cout<<endl;
   }
// type alias, [array] after name
typedef int int_array[3];//using int_array=int[3]
// p: pointer to array of 3 int
   for (int_array *p=ia; p!=ia+2;p++){// int (*p)[3]=ia, OR: auto p=ia
       for(int *q=*p;q!=end(*p);q++)//*p: pointer to first element of array
           cout<<*q*2<<" ";
       cout<<endl;
    }
    return 0;
}
