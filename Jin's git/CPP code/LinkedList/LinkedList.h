#ifndef LinkedList_h
#define LinkedList_h

#include<iostream>
#include <random>

using namespace std;

class Card  //카드 class를 만든다.
{
private:
    int card = 0; //난수를 받을 변수
public:
    int show_card( int num );  //난수를 이용하여 카드의 특정 번호를 받는다.
};

class LinkedList  //연결 리스트 클래스를 생성한다.
{
    struct Node //연결 리스트의 노드
    {
        int data;
        Node *next;
        
        Node(int data=0)
        {
            this->data = data;
            next = 0;
        }
    };
    
    Node *head;  //연결 리스트 맨 앞 노드의 위치 정보
    Node *tail;  //연결 리스트 맨 뒤 노드의 위치 정보
    
public:
    
    class Iterator  //연결 리스트에 보관한 데이터를 탐색하기 위한 반복자 클래스 생성
    {
        Node *node;  //현재 노드의 위치 정보
        
    public:
        friend class LinkedList;  //연결리스트에서는 모든 멤버에 접근 가능
        
        Iterator(Node *node=0)
        {
            this->node = node;
        }
        
        bool ChangeNode()  //크기를 비교하여 노드의 순서를 변경한다.
        {
            while(1)
            {
                if(node->next)  //다음 노드가 있을 때
                {
                    int box = 0;
                    if(node->data > node->next->data)
                    {
                        box = node->data;
                        node->data = node->next->data;
                        node->next->data = box;
                        
                        node = node->next;
                    }
                    else
                    {
                        node = node->next;
                    }
                }
                else
                {
                    break;
                }
            }
            return true;
        }
    };
    
    LinkedList();  //연결 리스트의 생성자
    ~LinkedList();  //파괴자
    
    void Push(int data);  //입력을 받아 연결 리스트에 넣는 함수
    
    Iterator Begin()  //탐색에 사용할 시작 반복자
    {
        LinkedList::Iterator iter(head);
        
        return iter;
    }
    
    void ViewOne(int num)const;  //카드 하나를 보여주는 함수
    void ViewAll()const;  //모든 카드의 순서를 보여주는 함수
};

#endif /* LinkedList_h */
