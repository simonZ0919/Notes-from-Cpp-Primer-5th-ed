#include<iostream>
#include<vector>
#include<string>
using namespace::std;
//  blocks {}, name scope with a sequence of statement
// EX 5.5-5.6, create letter from grad
void convert_grade(){
    const vector<string> gradeList{"F","D","C","B","A","A++"};
    string gradeChar; int gradeNum;
    cout<<"Enter grade number: ";
    cin>>gradeNum;
// map grade with range 0-59, 60-69,..., 100
// cout<<(gradeNum<60 ? gradeList[0]: gradeList[(gradeNum-50)/10])<<endl;
    if (gradeNum<60)
        gradeChar=gradeList[0];
    else
        gradeChar=gradeList[(gradeNum-50)/10];
    cout<<gradeChar<<endl;
}
//--------------------------------------------------------
// EX 5.12, count chars: ff,fl,fi
void count_letter(){
    int ffCnt=0, flCnt=0,fiCnt=0;
    char currCh, lastCh;
    while(cin>>currCh){
        if (lastCh=='f'){
// case label: const, ERROR: bypass initialize
// break: jump out of control flow, default: if no cases matched
            switch (currCh) {
            case 'f': ++ffCnt; break;
            case 'l': ++flCnt; break;
            case 'i': ++fiCnt; break;
            default:break;
            }
        }
        lastCh=currCh;
    }
    cout<<ffCnt<<" "<<flCnt<<" "<<fiCnt<<" "<<endl;
}
//--------------------------------------------
// EX 5.17, compare two vectors for the prefix
bool compare_vector(){
    vector<int> v1{0,1,1,2};
    vector<int> v2{0,1,1,2,3,5,8};
    auto iter1=v1.cbegin(),iter2=v2.cbegin();
// any part of for loop can be omitted
    for (; iter1!=v1.cend()&& iter2!=v2.cend(); ++iter1, ++iter2)
        if(*iter1!=*iter2)
// break: exit the nearest(inner) loop(while, for, switch)
// continue: stop current(closest) loop, begin a new one
// goto label: jump to a label place
           break;
    return iter1==v1.cend() || iter2==v2.cend();
}
//--------------------------------------------
// Ex 5.23-5.25, handle zero divisor
void divide_error(){
   int d1,d2;
   cin>>d1;
   while(cin>>d2){
// try:detect error, throw exception
        try {
            if(d2){
                cout<<d1/d2<<endl;
                break;
            }
            else
// run_time error： type of object, initialized with string
                throw runtime_error("divide by zero");
            } catch (runtime_error err) {// catch(declartion) {}, object: err
// err.what(): return the string of err
            cout<<err.what()<<"\nType a new number: ";
        }
   }
}
//-------------------------------------------------
int main(){
// if(bool) {body}...else {body}: match the nearest pair
    convert_grade();
// switch(val): multiple conditions, execute following cases in order, use break
    //count_letter();
// for(initializer; condition; expression) {body}, expression: iterate after body
// range for: for(declaration: sequence){body}, declare: auto type, & to write content
// do {body} while(condition); : run body first, no define variable in condition
   cout<<(compare_vector()?"true":"false")<<endl;
//-------------------------------------------------------
// exception handle: deal with error, try{...throw..} catch(error){...}
   divide_error();
  return 0;
}
