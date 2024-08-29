// DataStructureC.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#pragma once;
#include <iostream>
#include "vector.hpp"


int main()
{
    std::cout << "Hello World!\n";
    vector<int> v(10);
    v.push(4);
    v.print();


    
}