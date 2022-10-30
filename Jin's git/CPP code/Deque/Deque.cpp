#include "Deque.h"
#include<iostream>
#include <random>

Deque::Deque( int capacity )  //덱의 생성자
    :capacity( capacity )
{
    front = 0;  //초기값을 지정한다.
    rear = 0;
}

void Deque::Push( string mark, int num )  //큐에 카드를 넣는다.
{
    if ( front == (rear+1) % capacity )
    {
        cout << "큐가 가득 찼습니다.\n";
    }
    else   //특정 숫자에 따라 카드의 모양을 지정해준다.
    {
        if ( mark == "S" )
        {
            queue[num] = num;
        }
        else if ( mark == "D" )
        {
            queue[num + 13] = num;
        }
        else if ( mark == "H" )
        {
            queue[num + 26] = num;
        }
        else if ( mark == "C" )
        {
            queue[num + 39] = num;
        }
        rear = ++rear % capacity;
    }
}

void Deque::showDeque()   //큐의 현재 상태를 보여준다.
{
    if ( front == rear )
    {
        cout << "큐가 가득 찼습니다.\n";
    }
    else
    {
        for (int i = 0; i < capacity; i++)
        {
            if ( queue[i] != 0 )
            {
                if ( i <= 13 )
                {
                    cout<<"S"<<queue[i]<< " ";
                }
                else if ( i > 13 and i <= 26 )
                {
                    cout<<"D"<<queue[i]<< " ";
                }
                else if( i > 26 and i <= 39 )
                {
                    cout<<"H"<<queue[i]<< " ";
                }
                else if ( i > 39 and i <= 52 )
                {
                    cout<<"C"<<queue[i]<< " ";
                }
            }
            else
            {
                continue;
            }
        }
        cout << "\n";
    }
}

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
