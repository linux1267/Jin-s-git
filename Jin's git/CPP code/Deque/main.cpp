#include "Deque.h"
#include<iostream>
#include <random>

using namespace std;

int main()
{
    int start = 0;
    int num1, num2, num3, num4, num5;  //카드를 구현하기 위한 숫자
    int card_num1, card_num2, card_num3, card_num4, card_num5;   //카트의 숫자
    string card_mark1, card_mark2, card_mark3, card_mark4, card_mark5;;  //카드의 모양
    
    Card c1; //카드 객체
    num1 = c1.show_card(start);
    if ( num1 <= 13 )
    {
        card_num1 = num1;
        card_mark1 = "S";
    }
    else if ( num1 >13 and num1 <= 26 )
    {
        card_num1 = num1 - 13;
        card_mark1 = "D";
    }
    else if ( num1 >26 and num1 <= 39 )
    {
        card_num1 = num1 - 26;
        card_mark1 = "H";
    }
    else
    {
        card_num1 = num1 - 39;
        card_mark1 = "C";
    }                            //카드를 구현하는 과정
    
    Card c2;
    num2 = c2.show_card(num1);  //이전에 나온 카드와 비교하여 새로운 카드를 구한다.
    if ( num2 <= 13 )
    {
        card_num2 = num2;
        card_mark2 = "S";
    }
    else if ( num2 >13 and num2 <= 26 )
    {
        card_num2 = num2 - 13;
        card_mark2 = "D";    }
    else if ( num2 >26 and num2 <= 39 )
    {
        card_num2 = num2 - 26;
        card_mark2 = "H";
    }
    else
    {
        card_num2 = num2 - 39;
        card_mark2 = "C";
    }
    
    Card c3;
    num3 = c3.show_card(num1);
    num3 = c3.show_card(num2);
    if ( num3 <= 13 )
    {
        card_num3 = num3;
        card_mark3 = "S";
    }
    else if ( num3 >13 and num3 <= 26 )
    {
        card_num3 = num3 - 13;
        card_mark3 = "D";    }
    else if ( num3 >26 and num3 <= 39 )
    {
        card_num3 = num3 - 26;
        card_mark3 = "H";
    }
    else
    {
        card_num3 = num3 - 39;
        card_mark3 = "C";
    }
    
    Card c4;
    num4 = c4.show_card(num1);
    num4 = c4.show_card(num2);
    num4 = c4.show_card(num3);
    if ( num4 <= 13 )
    {
        card_num4 = num4;
        card_mark4 = "S";
    }
    else if ( num4 >13 and num4 <= 26 )
    {
        card_num4 = num4 - 13;
        card_mark4 = "D";    }
    else if ( num4 >26 and num4 <= 39 )
    {
        card_num4 = num4 - 26;
        card_mark4 = "H";
    }
    else
    {
        card_num4 = num4 - 39;
        card_mark4 = "C";
    }
    
    Card c5;
    num5 = c5.show_card(num1);
    num5 = c5.show_card(num2);
    num5 = c5.show_card(num3);
    num5 = c5.show_card(num4);
    if ( num5 <= 13 )
    {
        card_num5 = num5;
        card_mark5 = "S";
    }
    else if ( num5 >13 and num5 <= 26 )
    {
        card_num5 = num5 - 13;
        card_mark5 = "D";    }
    else if ( num5 >26 and num5 <= 39 )
    {
        card_num5 = num5 - 26;
        card_mark5 = "H";
    }
    else
    {
        card_num5 = num5 - 39;
        card_mark5 = "C";
    }
    
    int capacity = 53;

    Deque dq( capacity );  //큐 객체
  
    cout << "선택 된 카드1 : "<<card_mark1<<card_num1<<endl;
    dq.Push(card_mark1,card_num1);  //큐에 카드를 넣는다.
    dq.showDeque();  //현재 상태 출력
    
    cout << "선택 된 카드2 : "<<card_mark2<<card_num2<<endl;
    dq.showDeque();
    dq.Push(card_mark2,card_num2);
    dq.showDeque();
    
    cout << "선택 된 카드3 : "<<card_mark3<<card_num3<<endl;
    dq.showDeque();
    dq.Push(card_mark3,card_num3);
    dq.showDeque();
    
    cout << "선택 된 카드4 : "<<card_mark4<<card_num4<<endl;
    dq.showDeque();
    dq.Push(card_mark4,card_num4);
    dq.showDeque();
    
    cout << "선택 된 카드5 : "<<card_mark5<<card_num5<<endl;
    dq.showDeque();
    dq.Push(card_mark5,card_num5);
    dq.showDeque();
}
