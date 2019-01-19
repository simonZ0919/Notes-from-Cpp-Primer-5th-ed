// function: units of code with: return type, name, parameter list, function body
#include<iostream>
#include<vector>
#include<string>
using namespace::std;
// declare function in header, no body part{}
int abs_val();
//-------------------------------------------------------
// EX6.5 &6.7, return absolute number for first time, then numbers in sequence
int abs_val(int x){// x: parameter, automatic object, destroyed when function ends
// static: exist untill program ends, initialize ctr(first time), then define static
    static int ctr=(x>=0?x:-x);// ignore definition, the second function call
    return ctr++;// ctr not destroyed
}
//-----------------------------------------------------
// EX 6.17,check and convert upper letters
// &: return s and snew, const &: unchanged, take more types(literal, nonconst...)
bool c2lower(const string &s, string &snew){
    bool cap=false;
    for (auto p:s){
        cap|=isupper(p);// cap: true for at least a upper case
        snew+=tolower(p);// snew: convert p to lower case
    }
    return cap;
}
//----------------------------------------------
// EX 6.24 & 6.33 & 6.47, print array through recrusive function, with debugging
// void: no return, or return nothing
void print_arr(const int *beg, const int *end){
    if (beg==end)
        return;// return: break
    cout<<*beg<<'\0';
// run code if not define NDEBUG
    # ifndef NDEBUG// #define NDEBUG: no debug
    cout<<__func__<<" length: "<<end-beg<<endl;// __func_: print function name
    #endif
    print_arr(beg+1,end);// repeat function
}
//-----------------------------------------------
// EX 6.27, sum unknown numbers of int
void sum_int(initializer_list<int> lst){
    int sum=0;
// aceese list by range for, or lst.begin(), lst.end()
    for (auto &beg:lst)
        sum+=beg;
    cout<<sum<<endl;
}
//---------------------------------------------
// overload: functions have same name, different parameters, ignore top-level const, overload low-level
void print(string &){}// omit parameter name
void print(const string&){}
// EX6.42 & 6.45, plural form of words
// default parametes to the right, inline: avoid function call
inline string make_plural(size_t ctr, const string &word, const string &end="s"){
    return (ctr>1)? word+end :word;
}
//------------------------------------------------
// functions to add,subtract two ints
int add_int(int a, int b){return a+b;}
int sub_int(int a, int b){return a-b;}
//-------------------------------------------------
// input command line, argc: number of strings, argv:string content
int main(int argc, char *argv[]){
    int val; cin>>val;
    for (int i = 0; i < 5; ++i) {
//  val:argument, initialize parameter n, type & number match
        cout<<abs_val(val)<<'\0';// calll funtion with ()
    } 
//-----------------------------------------------
// pointer parameter: change object pointed, value: copy value
// &: change argument s1, match type, return additional parameters, nonconst to cont only
    string s1;
    cout<<boolalpha<<endl;//boolalpha: enable bool expression 
    cout<<c2lower("StudyPrimer",s1)<<'\0'<<s1<<endl;
// array parameter: pointer to first element, ignore size
// access array: mark end(null for char array), pointers(begin(arr), end(arr)), array size
    int arr[3]={1,6,9};
    int *abeg=begin(arr), *aend=end(arr);
     print_arr(abeg,aend);
// unknown number: initializer_list<type> lst, const, Table 6.1; ellipsis ...
    sum_int({1,6,9});// use {} to list value
//-------------------------------------------------
// return value: copy Rvalue, return &: Lvalue(can be assigned, except const&), no local object
// ar1, ar2, ar3: function return reference to array of 3 int, array type, need () for &
   int (&ar1(int u))[3];// parameter list precede over [size]
   auto ar2(int u)->int (&)[3]; //->: trailing returns
   decltype (arr) &ar3(int u);
// return vector: list initialize {}
//--------------------------------------------------
   string a;
   print(a);// exact match, calls print(string &)
// constexpr:return literal, can be nonconst, define inline/constexpr in headers
    cout<<make_plural(2,"word")<<endl;
//--------------------------------------------------
// fp: pointer to a function with parameter of two ints and return int
   using fp=int (*)(int, int);// () is needed, int *(int, int): function return *
// fc1,fc2,fc3: return pointer of function
   int (*fc1(char))(int, int);// Or: fp fc1(char)
   auto fc2(char)->int (*)(int,int);
   decltype (add_int) *fc3(char);
// Ex 6.54-6.56, store pointer function in vector and call
   vector<fp> vf;
   vf.push_back(add_int);// add_int convert to pointer
   vf.push_back(sub_int);
   for (fp u:vf)
       cout<<u(6,5)<<" ";// u(6,5): call add_int(6,5), sub_int(6,5)
    void calc(int x, bool fp(int, int ));// fp: same as *fp
// return preprocessor variable: EXIT_SUCCESS, EXIT_FAILURE
    return EXIT_SUCCESS;
}
