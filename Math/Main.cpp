#include<iostream>
#include "SVector2.cpp"
#include "SVector4.cpp"

int main()
{
    SVector2  mv1(1.0f,1.0f);
    SVector2  mv2(3.0f,1.0f);
    std::cout<<SVector2::Dot(mv1,mv2)<<std::endl;
    return 0;
}
