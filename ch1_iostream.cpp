// use library <header>, #include: outside any function
#include <iostream>
// class defined in the header file named Sales_item.hpp
#include <Sales_item.hpp>
//--------------------------------------------
// every program has a function
// function body: {block: sequence of statements}
int main(){
//--------------------------------------------
// iostream object<<value to print, return left operhand
// endl; manipulator, flush the buffer, std: namespace
    std::cout<<"enter two numbers:"<<std::endl;// (std::cout<<"enter numbers")<<std::endl;
    int c1,c2;
// reads input, >>: from left to right
    (std::cin>>c1)>>c2;
    std::cout<<"the product is ";
    std::cout<<c1*c2<<std::endl;
// print /*, match /* */
    std::cout<</*"*/"/*"/*"*/<<std::endl;
//----------------------------------------
//Ex 1.9/1.13 Sum numbers from 50 to 100
    int sum=0;
// for-loop:abreviaton of loop
// initial: int val=50, condition: val<100, body: sum+=val, after body executed, val=va+1
    for(int val=50; val<=100; val++)
       sum+=val;//sum=sum+val
    std::cout<<"sum from 50 to 100: "<<sum<<std::endl;
//----------------------------------------------
    int sval=0, val=0;
// while(true), read inputs of unknown numbers, cin>>values returns cin,
    while(std::cin>>val) //end-of-file: ctrlz+z
        sval+=val;
    std::cout<<"sum of input:"<<sval<<std::endl;
// return: terminate the function(send back value)
    return 0;
}
