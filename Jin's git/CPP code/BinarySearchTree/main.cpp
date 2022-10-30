#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    BinarySearchTree *BST = new BinarySearchTree();  //새로운 객체를 생성한다.
    int num;
    cout<<"1.입력 2.탐색 3.삭제 4.보기 5.종료"<<endl;
    
    while(1)
    {
        cin>>num;
        if(num == 5)
        {
            break;
        }
        else
        {
            switch(num)  //switch-case를 사용하여 원하는 기능을 할 수 있도록 한다.
            {
                case 1:
                    int a;
                    cin>>a;
                    BST -> addNode(a);
                    break;
                    
                case 2:
                    int b;
                    cin>>b;
                    BST -> searchValue(b);
                    break;
                    
                case 3:
                    int c;
                    cin>>c;
                    BST -> removeNode(c);
                    cout<<c<<"을/를 트리에서 제거한다."<<endl;;
                    break;
                    
                case 4:
                    BST -> show();
                    cout<<endl;
                    break;
            }
            cout<<endl;
        }
    }
    return 0;
}

