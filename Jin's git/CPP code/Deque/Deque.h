#ifndef Deque_h
#define Deque_h

#include<iostream>
#include <random>
using namespace std;

class Deque  //덱 class를 만든다.
{
private:
    int queue[100] = {0,};
    int front;  //맨 앞
    int rear;  //맨 뒤
    int capacity;  //크기

public:
    Deque( int ); //생성자
    void Push( string mark, int num );  //큐에 카드 넣기
    void showDeque();  //현재 상태
};

class Card  //카드 class를 만든다.
{
private:
    int card = 0; //난수를 받을 변수
public:
    int show_card( int num );  //난수를 이용하여 카드의 특정 번호를 받는다.
};

#endif /* Deque_h */
