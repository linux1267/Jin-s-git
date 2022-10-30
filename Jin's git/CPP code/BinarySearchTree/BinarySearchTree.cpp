#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

void BinarySearchTree::addNode(int value)  //노드를 입력하는 함수를 정의한다.
{
    Node *node = new Node();
    Node * tmpRoot = nullptr;
    
    node -> value = value;
    if(root == nullptr)
    {
        root = node;
    }
    else
    {
        Node *ptr = root;
        while(ptr != nullptr)
        {
            tmpRoot = ptr;
            if(node -> value < ptr -> value)
            {
                ptr = ptr -> left;
            }
            else
            {
                ptr = ptr -> right;
            }
        }
        if(node -> value < tmpRoot -> value)
        {
            tmpRoot -> left = node;
        }
        else
        {
            tmpRoot -> right = node;
        }
    }
}


Node *BinarySearchTree::removeSequence(Node *node, int _value)  //노드를 제거하기 위한 요소
{
    if(node == nullptr)
    {
        return node;
    }
    else if(node -> value > _value)
    {
        node -> left = removeSequence(node -> left, _value);
    }
    else if(node -> value < _value)
    {
        node -> right = removeSequence(node -> right, _value);
    }
    else
    {
        Node *ptr = node;
        if(node -> right == nullptr && node -> left == nullptr)
        {
            delete node;
            node = nullptr;
        }
        else if (node -> right == nullptr)
        {
            node = node -> left;
            delete ptr;
        }
        else if(node -> left == nullptr)
        {
            node = node -> right;
            delete ptr;
        }
        else
        {
            ptr = searchMaxNode(node -> left);
            node -> value = ptr -> value;
            node -> left = removeSequence(node -> left, ptr -> value);
        }
    }
    return node;
}

void BinarySearchTree::removeNode(int value)  //노드를 제거하기 위한 함수를 정의한다.
{
    Node *ptr = root;
    removeSequence(ptr, value);
}

bool BinarySearchTree::searchValue(int value)  //탐색을 위한 함수를 정의한다.
{
    Node *ptr = root;
    Node *tmpRoot = nullptr;
    while(ptr != nullptr)
    {
        if(ptr -> value == value)
        {
            cout<<value<<"은/는 트리에 존재한다."<<endl;
            return true;
        }
        else if(ptr -> value > value)
        {
            ptr = ptr -> left;
        }
        else
        {
            ptr = ptr -> right;
        }
    }
    return false;
}

void BinarySearchTree::show()  //트리를 출력하기 위한 함수를 정의한다.
{
    inOrder(root);
}
