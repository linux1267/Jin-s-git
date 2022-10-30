#include "Polynomial.h"

int main()
{
    Polynomial a, b, t; //Polynomial 객체 a,b,t 생성
    int x; //x 값에 대입할 변수
    
    cout << "다항 식 A 입력 : ";
    cin >> a;
    cout << "다항 식 B 입력 : ";
    cin >> b;
    cout << "입력한 식 A : " << a << endl;
    cout << endl;
    cout << "입력한 식 B : " << b << endl;
    cout << endl;
    
    t = a * b; //다항식 a와 다항식 b의 곱을 새로운 t로 만듬
    cout << "A X B : " << t << endl;
    cout << "대입할 값 x 입력 : ";
    cin >> x;
    cout << "결과 : A(" << x << ")= " << Eval(x, a) << ", B(" << x << ")= " << Eval(x, b) << ", C(" << x << ")= " << Eval(x, t) << endl;
}
