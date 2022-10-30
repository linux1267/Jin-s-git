#pragma once

#include <iostream>
using namespace std;


class Rectangle              //Rectangle 클래스 생성

{
private:
    static int id;           //static 맴버 변수 생성 -> 모든 객체가 공유하는 변수
    
public:
    int width;               //넓이
    int height;              //높이
    int xLow, yLow;          //x와 y의 좌표값
    //Rectangle(int, int, int, int);      //생성자 선언
    Rectangle(int x=0, int y=0, int w=0, int h=0)
    : xLow(x), yLow(y), width(w), height(h)
    {}          //생성자 선언과 정의
    ~Rectangle();                       //소멸자 선언

    /*friend std::ostream& operator <<(std::ostream&, Rectangle&); //출력 연산자 오버로딩

    Rectangle operator +(Rectangle&); //연산자 오버로딩*/
    
    friend istream& operator >>(istream&, Rectangle&); //입력 연산자 오버로딩 선언
    friend ostream& operator <<(ostream&, Rectangle&); //출력 연산자 오버로딩 선언
    
    void Rectangle_area(Rectangle& r); //객체들의 넓이를 구하는 함수 선언
    
    void Rectangle_overlab(Rectangle r1, Rectangle r2); //객체들의 겹치는 부분을 구하는 함수 선언
};
