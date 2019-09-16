#include<iostream>
// vector,string: contiguous memory, random access, insert at end
#include<vector>
#include<string>
#include<deque>//  random access, insert at front and back
#include<array>//  fixed size, random access, no add/remove
// list/forward_list: insert in the middle, sequential access only，no iterator arithmetic
#include<list> // double-linked list
#include<forward_list>// single-linked list, no size(), no iterator--
//-------------------------------------------------
#include<stack>//stack(last-in, first-out): vector, deque, list
#include<queue>//queue(first-in, first-out): list, deque; priority_queue: vector,deque
using namespace ::std;
//---------------------------------------------------
// Ex 9.4 and 9,5, find the matched value
vector<int>::iterator &find (const int n, vector<int>::iterator &vbeg,
          vector<int>::iterator &vend){
    for (; vbeg!=vend; ++vbeg) {
        if (n==*vbeg)
            return vbeg;
    }
    return vend;
}
//---------------------------------------------------
// Ex 9.43-9.45, replace new string, add postffix
void update_string(string &s, const string &oldVal,
                    const string &newVal, const string &pfx){
    size_t n=oldVal.size();
    for(int i=0; i!=s.size()-n;i++){
// substr: n chars from s[i]
        if (s.substr(i,n)==oldVal)
// replace n chars from s[i] with newVal
//          s.erase(i,n); s.insert(i,newVal);
            s.replace(i,n,newVal);
// look for newVal at positon i, find operations, Table 9.14
//        auto pos=s.find(newVal);
//        s.replace(pos,n,newVal);
    }
    s.append(" "+pfx);//  append sf to s
}
int main (){
// a list of deque that hold int
    list<deque<int>> qd;
    vector<int> v1{1,3,6,9,10};
// iterator range: [first, end), begin<=end
    auto vb=v1.begin(), ve=v1.end();
    auto imatch=find(6,vb,ve);
//  array: size is part of type
    array<int, 10> arry1{2,3,6};
//  assignment, Table 9.4
//  swap/copy container=: type match, iterator range/assign: type conversion
    vector<int> va(arry1.begin(),arry1.end());
    list<double> lst;
    lst.assign(va.begin(), va.end());// assign va to li
    swap(va,v1);// exchange value of va with v1, valid iterator/reference
//----------------------------------------------------
//  add elements, Table 9.5
    list<string> sl;
    string word;
    auto iter=sl.begin();
    while(cin>>word)
//  insert at front, return the iterator of first inserted element
        iter=sl.insert(iter, word);// sl.push_front(word)
//----------------------------------------------------
//  first element of v1, Table 9.6
    auto val=v1.front(), val2=v1.at(0), val3=v1[0], val4=*v1.begin();
//---------------------------------------------------
// Ex 9.26, remove even number in a list, Table 9.7
    int ia[]={0,1,1,2,3,5,8,13,21,55,89};
    list<int> lst1(begin(ia), end(ia));
    auto ita=lst1.begin();
    while(ita != lst1.end())
        if(!(*ita %2) )
// erase: return iterator after the removed element
            ita=lst1.erase(ita);
        else
            ++ita;
    for(const auto n: lst1)
        cout<<n<<'\0';
    cout<<endl;
//----------------------------------------------------
// Ex 9.27, remove odd number in forward_list, Table 9.8
    forward_list<int> flst(begin(ia),end(ia));
// prev: one before curr, predecessor
    auto prev=flst.before_begin();
    auto curr=flst.begin();
    while(curr!=flst.end()){
        if(*curr % 2)
            curr=flst.erase_after(prev);
        else {
            prev=curr;
            ++curr;
        }
    }
//----------------------------------------------------
// change the number of element, not memory(capacity)
    flst.resize(5);
    for (auto fn:flst)
        cout<<fn<<" ";
    cout<<endl;
// size: number of elements already holds, capacity: vector can hold
// operations of memory, Table 9.10
    vector<int> vec{1,5,8};
    vec.reserve(100);// preallocate 100 int for vec
    cout<<vec.size()<<" "<<vec.capacity()<<endl;
//---------------------------------------------------
// construct string, Table 9.11
// operations on string, Table 9.12, take index or iterator
    string sv("thx for help");
    update_string(sv,"thx","thanks","Sir");
    cout<<sv<<endl;
//--------------------------------------------------
// Ex 9.50, string convert to number, Table 9.16
    vector<string> sn{"3.6", "6.6","5.8"};
    double sum;
    for(const auto &ms: sn)
        sum+=stod(ms);
    cout<<sum<<endl;
//--------------------------------------------------
// adaptor: make one act like another, build stack on top of vector, copy sve2
// Ex9.52, find(), operations of stack and queue, Table 9.18 & 9.19
    vector<string> sv2{"g","(","w",")"};bool para;string sp;
    stack<string,vector<string>> stk(sv2);
    while(!stk.empty()){
// stk.top(): top element(right most)
        if(stk.top()==")" || para){
            sp+=stk.top();
            para=true;
        }
        if(stk.top()=="(" && para)
            break;
        stk.pop();// remove top element
    }
    cout<<sp<<endl;
    return 0;
}
