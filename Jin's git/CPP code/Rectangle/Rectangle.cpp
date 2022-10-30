#include "Rectangle.h"
#include <iostream>
using namespace std;

int Rectangle::id = 0;  //static 변수 id를 0으로 초기화

/*Rectangle::Rectangle(int x, int y, int w, int h) { //클래스 Rectangle의 생성자 정의
    xLow = x;                   //x좌표 값
    yLow = y;                   //y좌표 값
    width = w;                  //넓이 값
    height = h;                 //높이 값

    std::cout << ++id << "번째 Rectangle 객체 생성\n\n";  //만들어 지는 객체들의 순서를 알기 위해 static변수 id를 1씩 올려가며 순서를 알 수 있는 값을 출력한다.
}

Rectangle::~Rectangle() {  //클래스 Rectangle의 소멸자 정의
    std::cout << "좌표 (" << xLow << ',' << yLow << ')'
        << " Rectangle 객체 소멸\n\n";
}

std::ostream& operator <<(std::ostream& os, Rectangle& r) { //출력 연산자 오버로딩, 여기서 os는 ostream의 객체를 참조하고 ,r은 Rectangle 객체를 참조로 받는다.
    os << "height : " << r.height << std::endl
        << "width : " << r.width << std::endl
        << "x : " << r.xLow << std::endl
        << "y : " << r.yLow << std::endl << std::endl;

    return os;
}

Rectangle Rectangle::operator +(Rectangle& r) { //연산자 오버로딩 , 전달받은 Rectangel 객체와 참조자 r을 더하여 임시 객체를 만들고 이가 반환된다. 

    int sum_x, sum_y, sum_w, sum_h;

    sum_x = xLow + r.xLow;
    sum_y = yLow + r.yLow;
    sum_w = this->width + r.width;
    sum_h = this->height + r.height;

    return Rectangle(sum_x, sum_y, sum_w, sum_h);
}*/

Rectangle::~Rectangle() {
   cout<<"좌표 ("<< xLow << ',' << yLow << ')' << " Rectangle 객체 소멸\n\n";
}   //파괴자 정의

istream& operator >>(istream& in, Rectangle& r){
    in >> r.xLow >> r.yLow >> r.width >> r.height;
    return in;
}   //입력 연산자 오버로딩 정의
ostream& operator <<(ostream& os, Rectangle& r) {
    os << "x : " << r.xLow << endl
        << "y : " << r.yLow << endl
        << "width : " << r.width << endl
    << "height : " << r.height << endl;

    return os;
}   //출력 연산자 오버로딩 정의

void Rectangle::Rectangle_area(Rectangle& r)
{
    int multiply_value = r.width * r.height;
    
    cout<<++id<<"번쨰 Rectangle의 넓이 : "<<multiply_value<<endl;
}   //객체의 넓이를 구하는 함수의 정의

void Rectangle::Rectangle_overlab(Rectangle r1, Rectangle r2)
{
    int xx1, yy1, xx2, yy2;
    int i, j, x_comparison, y_comparison = 0;
    int r3_x, r3_y, r3_width, r3_height = 0;
    int comparison_space[21][21] = {0,};
    
    xx1 = r1.xLow + r1.width;
    yy1 = r1.yLow + r1.height;
    
    xx2 = r2.xLow + r2.width;
    yy2 = r2.yLow + r2.height;
    
    for ( i = r1.yLow; i <= yy1; i++ )
    {
        for ( j = r1.xLow; j <= xx1; j++ )
        {
            comparison_space[j][i]++;
        }
    }
    for ( i = r2.yLow; i <= yy2; i++ )
    {
        for( j = r2.xLow; j <= xx2; j++ )
        {
            comparison_space[j][i]++;
        }
    }
    
    for ( i = 0; i <= 20; i++ )
    {
        for( j = 0; j <= 20; j++ )
        {
            if( comparison_space[j][i] == 2)
            {
                r3_x = j;
                r3_y = i;
            }
        }
    } //이차원 배열을 통해 겹치는 부분을 구한다.
    if (r1.xLow <= r2.xLow and r1.yLow <= r2.yLow )
    {
        r3_width = r3_x - r2.xLow;
        r3_height = r3_y - r2.yLow;
        r3_x = r3_x - r3_width;
        r3_y = r3_y - r3_height;
    } //r1이 r2보다 왼쪽에 있을 때
    else if (r1.xLow >= r2.xLow and r1.yLow >= r2.yLow)
    {
        r3_width = r3_x - r1.xLow;
        r3_height = r3_y - r1.yLow;
        r3_x = r3_x - r3_width;
        r3_y = r3_y - r3_height;
    } //r2가 r1보다 왼쪽에 있을 때
    
    Rectangle r3( r3_x, r3_y, r3_width, r3_height );
    cout<<r3<<endl;
    r3.Rectangle_area(r3);
} //두 객체의 겹치는 부분을 이차원 배열을 통해 구하고 겹치는 부분을 이용하여 좌표와 가로, 세로 길이를 구하여 객체를 생성하고 그것의 넓이는 구하는 함수이다.
