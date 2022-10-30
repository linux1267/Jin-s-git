#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
    /*Rectangle r1(1, 1, 3, 4);   //Rectangle 객체 r1 생성
    std::cout << r1;            // r1 출력
    
    Rectangle* r2 = new Rectangle(2, 3, 5, 5);    //r1이 가리키는 메모리 공간에 Rectnagle(2,3,5,5)를 동적할당 한다.
    std::cout << *r2;          //r2에 할당된 값 출력

    r1 = r1 + *r2;             //r1과 r2의 할당된 값을 더하여 새로운 r1을 만든다.

    std::cout << r1;           // 새로워진 r1 출력

    delete r2;                 //r2에 할당된 값 제거*/
    
    Rectangle r1;           //Rectangle 객체 r1생성
    cin>>r1;            //r1 입력 받기
    cout<<r1<<endl;     //r1 출력
    r1.Rectangle_area(r1);  //r1의 넓이
    
    Rectangle r2;          //Rectangle 객체 r2생성
    cin>>r2;               //r2 입력 받기
    cout<<r2<<endl;        //r2 출력
    r2.Rectangle_area(r2);   //r2의 넓이
    
    r2.Rectangle_overlab(r1, r2); //r1과 r2의 겹치는 부분을 구하고 객체 3을 만든다
}

