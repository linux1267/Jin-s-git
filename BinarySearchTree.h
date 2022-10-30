#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <iostream>

using namespace std;

struct Node   //트리에서 각각의 노드를 표현한다.
{
    Node *left, *right;
    int value;
};

class BinarySearchTree  //이진탐색트리를 구현하는 클래스를 생성한다.
{
public:
    BinarySearchTree():root(nullptr){};
    ~BinarySearchTree(){};
    
    void addNode(int value);  //트리에 노드를 입력하는 함수를 선언한다.
    bool searchValue(int value);  //트리에 존재하는 노드를 탐색하는 함수를 선언한다.
    void removeNode(int value);  //트리에 존재하는 노드를 제거하는 함수를 선언한다.
    void show();  //트리를 구성하는 노드들을 출력하는 함수를 선언한다.
    
private:
    Node *root;  //트리의 root값
    Node *tail;  //트리의 tail값
    
    void inOrder(Node *current) //중위 순회를 하는 함수를 정의한다.
    {
        if(current != nullptr)
        {
            inOrder(current -> left);
            cout<<current -> value<<" ";
            inOrder(current -> right);
        }
    }
    
    Node *searchMaxNode(Node *node)  //가장 큰 값을 가지는 노드를 찾는다.
    {
        if(node == NULL)
        {
            return NULL;
        }
        while(node -> right != NULL)
        {
            node = node -> right;
        }
        return node;
    }
    
    Node *removeSequence(Node *node, int _value);  //노드를 제거하기 위한 요소
};

#endif /* BinarySearchTree_h */
