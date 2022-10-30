#include<iostream>
#include <random>
#include "LinkedList.h"

using namespace std;

typedef class LinkedList List;

int main()
{
    int start = 0;
    int num1, num2, num3, num4, num5;  //카드를 구현하기 위한 숫자
    
    Card c1; //카드 객체
    num1 = c1.show_card(start);
    
    Card c2;
    num2 = c2.show_card(num1);  //이전에 나온 카드와 비교하여 새로운 카드를 구한다.
    
    Card c3;
    num3 = c3.show_card(num1);
    num3 = c3.show_card(num2);
    
    Card c4;
    num4 = c4.show_card(num1);
    num4 = c4.show_card(num2);
    num4 = c4.show_card(num3);
    
    Card c5;
    num5 = c5.show_card(num1);
    num5 = c5.show_card(num2);
    num5 = c5.show_card(num3);
    num5 = c5.show_card(num4);
    
    List sl; //연결 리스트 객체를 생성
    
    sl.Push(num1); //연결 리스트에 차례로 카드를 입력한다.
    sl.ViewOne(1); //몇 번째에 무슨 카드가 들어갔는지 보여준다.

    sl.Push(num2);
    sl.ViewOne(2);
    
    sl.Push(num3);
    sl.ViewOne(3);
    
    sl.Push(num4);
    sl.ViewOne(4);
    
    sl.Push(num5);
    sl.ViewOne(5);
    
    cout<<endl;
    
    List::Iterator seek = sl.Begin();  //반복자를 생성한다.
    
    sl.ViewAll();  //현재 카드의 순서를 보여준다.
    
    seek.ChangeNode();  //카드의 크기에 따라 순서를 변경해준다.
    seek = sl.Begin();  //변경 대상을 다시 맨앞르로 옯긴다.
    
    seek.ChangeNode();  //위 과정을 반복한다.
    seek = sl.Begin();
    
    seek.ChangeNode();
    seek = sl.Begin();
    
    seek.ChangeNode();
    seek = sl.Begin();
    
    seek.ChangeNode();
    
    sl.ViewAll();  //순서 변경 후 결과를 보여준다.
    
    return 0;
    
}
