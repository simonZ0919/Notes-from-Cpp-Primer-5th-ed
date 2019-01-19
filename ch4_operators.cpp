// rvalue: content, ivalue: identity(location in memory), ivalue converted to rvalue, not other way
// precedence: priority(Table 4.12), associativity: group/read from right/left
// evaulation order: &&, ||, condition(? :), comma(,), others not specfied, BUG: use object twice or more
// oveerflow: value out of the range of data type
// overload: class redefine built-in operators(like >>, <<), same precedence/associativity
#include<iostream>
#include<vector>
using namespace::std;
int main(){
//modulus(remainder): -m%n=-(m%n), m%(-n)=m%n, sign depend on m
    cout<<5%2 <<" "<<5%-2<<endl;//negative- precedes over %
//----------------------------------------------------
// short-circuit(left first), A&&B: read B when A==TRUE, A||B: read B when A==FALSE
// if (a<b<c): if (1<c), when a<b(True), CORRECT: if(a<b && b<c)
    int a=2,b;
    if (!a)// True if a is nonzero, if (a==true): if (a==1)
//-----------------------------------------------------
// a=b: a is ivalue, return a
    a=b=3;//right associative=: b=3, then a=b, same type
    a%=b;// a= a % b=0
//-----------------------------------------------------
    b=++a;//b=1, a=1: prefix return increased ivalue, preferred
    b=a++;//b=1, a=2: postfix returns a copy of original, rvalue
// *iter++: *(iter++), iter+1, return original,  (*iter).empty():need (), precedence: .>++>*
//-----------------------------------------------------
// EX4.22, cluster grade with 60, 75, use conditional operator(? : )
    vector<int> grade{65,70,55,80,60,90};
    for (auto &pg:grade)
// if(pg<60) cout<<"fail"; else if(pg<75) cout<<"pass";else cout<<"high_pass";
        cout<<((pg<60)?"fail":(pg<75)?"pass":"high_pass")<<'\0';// () is needed(low precedency)
//-----------------------------------------------------
// built-in <<, >>: left/right shift bit, &|^: bitwise AND, OR, XOR
    unsigned long bits=0;// long: 32 bits
    bits |=1UL<<25; // bits=bits|(1UL<<25), 1UL:000...1, set 1 to No.25 bit
    bits &=~(1UL<<25);// reset No.25
//-----------------------------------------------------
// sizeof: return size in byte(8 bits),size_t, no evaluate, return const
    int arr1[sizeof (bits)];
//---------------------------------------------------------
// implicit conversion: small(bool,char, short...) promote to large bits(at least int), signed to unsigned
// explicit conversion: cast-name<type>(object), static_cast: direct type convert, not const
    void *pv=&a;
    int *pi=static_cast<int*>(pv);//void* to int*
// const_cast: const to nonconst, no other type
    const double *pc;
    double *pd=const_cast<double*>(pc);// pd is nonconst double*
// other: reinterpret_cast, dynamic_cast, cast is not preferred
  return 0;
}
