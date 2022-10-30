#include<iostream>
#include <random>
#include "LinkedList.h"

int Card::show_card( int num )  //난수를 이용하여 카드를 결정하는 숫자를 받는다.
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1,52);
    
    while(1)  //이전에 나왔던 카드와 중복이 되는지 판단한다.
    {
        card = dist(gen);
        if ( card == num )
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return card;
}

LinkedList::LinkedList()  //생성자
{
    head = 0;
    tail = 0;
}

LinkedList::~LinkedList()  //파괴자
{
    Node *prev=0;
    
    while(head !=0)
    {
        prev = head;
        head = head->next;
        
        delete prev;
    }
}

void LinkedList::Push(int data)
{
    Node *node = new Node(data);  //새로운 노드
    
    if(head==0)  //비어있을 때
    {
        head = tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}

void LinkedList::ViewOne(int num)const
{
    Node *seek;
    string card_mark;
    int card_num = 0;
    
    if ( seek->data <= 13 )
   {
       card_num = seek->data;
       card_mark = "S";
   }
   else if ( seek->data >13 and seek->data <= 26 )
   {
       card_num = seek->data - 13;
       card_mark = "D";    }
   else if ( seek->data >26 and seek->data <= 39 )
   {
       card_num = seek->data - 26;
       card_mark = "H";
   }
   else
   {
       card_num = seek->data - 39;
       card_mark = "C";
   }                                  //카드의 모양과 숫자를 확정
    cout<<"선택 된 카드"<<num<<" : "<<card_mark<<card_num<<endl;
}

void LinkedList::ViewAll()const
{
    Node *seek=0;
    string card_mark;
    int card_num = 0;
    
    for(seek = head; seek!=0 ; seek = seek->next)
    {
        if ( seek->data <= 13 )
       {
           card_num = seek->data;
           card_mark = "S";
       }
       else if ( seek->data >13 and seek->data <= 26 )
       {
           card_num = seek->data - 13;
           card_mark = "D";    }
       else if ( seek->data >26 and seek->data <= 39 )
       {
           card_num = seek->data - 26;
           card_mark = "H";
       }
       else
       {
           card_num = seek->data - 39;
           card_mark = "C";
       }
        cout<<card_mark<<card_num<<" ";
    }
    
    cout<<endl;
    cout<<endl;
}
