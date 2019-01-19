// unit: 1 byte=8 bits, 1 word=4 or 8 bytes=32 or 64 bits;
// signed type, char:8 bits, short/int:16 bits, long:32 bits, long long:64 bits
// float: 1 word (32 bits), double:2 words(64 bits)
// &: reference(definition), address(expression)
// *: pointer(definition), dereference(expression)
//----------------------------------------------------
# include<iostream>
// declaration: claim type and name of variable, definition: initialize value
    extern int u;// extern: declared outside function, no intializer(else definition)
// main, u:global/outer scope, fixed address
    int u=6;
// constexpr: const at compile time (explicit), const pointer (top-level)
    constexpr int *p=&u;
//------------------------------------------
// define data structure: struct class{member1, member2,...};
    struct student_ID{
        int studentNo=0; std::string Name; int DoB;// in-class initialize, no ()
    };// ; is needed at the end
    student_ID s1, s2, s3;// define variables
//-------------------------------------------
int main(){
// negative unsigned: value wrap around
    unsigned v1=10,v2=20;
    std::cout<<v1-v2<<std::endl;
// char: 'a', string: "a"(two characters: a + null'\0'), variable length
    std::cout<<"2\t\115\12";// Escap sequence, print: 2+tap+M+newline
//------------------------------------------------
    int u=3;// u: inner/block scope
// empty operator ::, globe scope
    std::cout<<u<<'\0'<<::u<<std::endl;// '\0': blank space
//------------------------------------------------
// reference: another name(alias) for object(not literal), type　match(unless const)
// not object, forever bound, must be initialized
    int &ru=u;// &: declarator
    ru=5;// u=5
    std::cout<<u<<" "<<ru<<std::endl;
//------------------------------------------------
// pointer:an object pointed to another one(no reference), take address, type match for nonconst
    int *pu=&u;
    std::cout<<*pu<<" "<<pu<<std::endl;// *pu:dereference, pu:address
// nullpointer: 0, nullptr, NULL（preprocessor）, void*: any type
// no assigned with int variable(zero or nonzero), or nonzero literal
    pu=0; //ERROR: pu=1, int *pu=u
//------------------------------------------------
// const: unchanged value, must be initialized
    const int c1=5;// initialize： nonconst to const, both ways
    int j=c1;
// reference to const, OK: initial const& with other expression
    const int &r1=j;
    const int &r2=10*2;
// ERROR: int &r3=c1, nonconst& to const
// top-level: const object itself, can be copied
    int *const p1=&j;// read from inside to ouside
    *p1=c1;// p1: const address, can change pointed object, ERROR: p1=&ci
// low-level: pointer/reference to const type, from nonconst to const ONLY, not the other way
    const int *p2=&j;
    p2=p1;// p2: can change address, p1 can be copied, ERROR: *p2=*p1
    int *pf=&u;
    p2=pf;// ERROR: pf(nonconst)=p2(const)
    const int *const p3=p2;// p3: both level, match low-level
//------------------------------------------------
//  type synonym: typedef/using
    typedef char *cr;// cr==char *
    using cr=char *;
//  cg is a constant pointer to char, not pointer to const char
    const cr cg=0;
//-----------------------------------------------
// auto: deduct type, must have intializer, multiple: same type, Error: si=2
    auto se=3.5,si=2.5;
    int &r3=u;
    auto d=r3;// ignore &: d is int, not int &
// igonre top-level const, keep low-level, e is int, f is const int*
    const int ci=10;
    auto e=ci;
    auto f=&ci;
// explicit declare &(keep top-level) or const, g: const&, h: const int
    auto &g=ci;
    const auto h=ci;
//------------------------------------------------
// decltype: deduce expression, without initialize
    decltype (ci) de=6;// keep top-level consts and reference, de: const &
// ignore reference in arithmetic, r0:int
    decltype(r3+0) r0;
// yield &: object on the left side of assignment=
    int *pd=&u;
    decltype(*pd) m=u;// m: int &
    decltype ((u)) n=u;// n:int &, expression(u)
    return 0;
}
