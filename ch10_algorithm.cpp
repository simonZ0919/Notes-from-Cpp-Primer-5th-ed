#include <iostream>
#include <vector>
// general alogrithm apply to any type, operate on iterators
#include <algorithm>
#include <numeric>
#include <list>
// iterator type: insert, stream, reverse, move
#include <iterator>
#include <functional>
using namespace std;
// placeholder: argument bound to new function
using namespace std::placeholders;
//------------------------------------------
// Ex10.9, sort and remove duplicate words
void eliDup(vector<string> &words){
// sort in alphabtical order
    sort(words.begin(),words.end());
// move unqiue elems at front, return one past last unique
    auto iterUniq=unique(words.begin(),words.end());
// erase duplicate elems
    words.erase(iterUniq, words.end());
}
// -------------------------------------------
bool isShorter(const string &s1, const string &s2){
    return s1.size()<s2.size() ;
}
bool check_size(const string &s, size_t sl){
    return s.size()>=sl;
}
// EX 10.16, 10.18, 10.22, operations on words
void bigges(vector<string> words, vector<string>::size_type sz){
    eliDup(words);
// lambda expression: [capture list](parameter)->return type{body}
    auto sumInt=[](const int i1, const int i2){return i1+i2;};//ignore paramete and return type
    cout<<sumInt(3,9)<<endl;
// isShorter: predicate called by sort, stable_: remain alphabetic order
    stable_sort(words.begin(),words.end(),isShorter);
// use lambda expression
    auto sp=stable_partition(words.begin(),words.end(), //partition: separate with size, return one past last
                     [sz](const string &a) // sz: capture list, local nonstatic variable
                    {return a.size()>=sz;});
// bind function, local/reorder parameter
    cout<<count_if(words.begin(),words.end(),
                      bind(check_size,_1,sz))<<" ";// pass 1st argument, assign 2nd to sz
// for_each: print words with length>=sz
    for_each(words.begin(),sp,
             [](const string &s){cout<<s<<" ";});
}
// ------------------------------------------------------
int main(){ 
    vector<int> vec{3,6,8,6,9};
    int val =6;
// return iter to first found in iterator range, not found: return vec.cend()
    auto findval=find(vec.cbegin(),vec.cend(),val);
    auto cval=count(vec.cbegin(),vec.cend(),val);
// sum of element, start from 0
    int sum=accumulate(vec.cbegin(), vec.cend(),0);
    cout<<(findval!=vec.cend()?"found":"not found")
        << " "<<cval<<" "<<sum<<endl;
    vector<int> vec1;
// fill vec1 with 5 ints of 1, back_inserter: use push_forward, change size
    fill_n(back_inserter(vec1),5,1);
//-----------------------------------------------
// sort and remove duplicate words
// algorithm conditions: predicate, lambda expression, bind function
    vector<string> sw{"the", "red", "fox", "climbs", "the", "red", "trees"};
    bigges(sw, 5);
    cout<<endl;
//-----------------------------------------------
// read from cin, eof: default, end of file
    istream_iterator<int>in_itr(cin),eof;
    vector<int> vOld(in_itr,eof);// construct from input range
    list<int> vnew1, vnew2;
// insert iterator, call push_front(return v.begin()), push_back or insert(val, pos)
    copy(vOld.begin(),vOld.end(),front_inserter(vnew1));// reverse order
    copy(vOld.begin(),vOld.end(),inserter(vnew2, vnew2.begin()));// normal order
// copy vnew1 to cout, and print following " "
    ostream_iterator<int> out_itr(cout, " ");
    copy(vnew1.begin(),vnew1.end(),out_itr);
    cout<<endl;
// reverse_iterator: rbegin, crbegin(), count from end, rit.base(): normal
    for(auto rit=vnew1.rbegin(); rit!=vnew1.rend();rit++)
        cout<<*rit<<" ";   
}
