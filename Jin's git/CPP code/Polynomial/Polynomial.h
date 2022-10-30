#ifndef Polynomial_h
#define Polynomial_h

#include <iostream>
#include <string>
#include <math.h>

using namespace std;
const int MaxDegree = 100; //다항식이 가질 수 있는 최대 차수

class Polynomial
{
private:
    bool isFirstNum = true; //다항식에서 첫번째로 오는 항인지 구분
    bool chk = 0; // 0 - 계수 / 1 - 계수
    int temp = 0; // 임시 계수 저장
    int termArray[101] = {0, }; //입력받은 계수 값을 그에 맞는 차수 인덱스에 저장

public:
    // friend들은 Polynomial 클래스의 private변수에 접근할 수 있다.
    friend istream& operator>>(istream& is, Polynomial& p); //입력을 받기 위한 입력 오버로딩 선언
    friend ostream& operator<<(ostream& os, Polynomial& p); //출력을 하기 위한 출력 오버로딩 선언

    friend Polynomial operator * (Polynomial& p1, Polynomial& p2); //다항식과 다항식의 곱을 실행하는 곱셈 연산자 오버로딩 선언

    friend int Eval(int x, Polynomial& p); //다항식의 x에 값을 대입하기 위한 함수 선언
};

//입력 오버로딩
istream& operator>>(istream& is, Polynomial& p)
{
    string tmp_str;
    getline(is, tmp_str); //공백도 문자열에 포함하여 입력 받기 위해 getline함수를 사용
    
    int tmp = 0;
    
    for(int i = 0; i < tmp_str.size(); i++) {
        if((i - tmp) % 4 == 0) { //공백으로 인해 0부터 4씩 증가하여 계수가 나온다
            if(tmp_str[i] == '-') { //음수일 경우 -(부호)를 입력 받기 때문에 i값에 1을 추가한다
                tmp++;
                p.temp = (-1) * (tmp_str[i + 1] - '0'); //문자열로 받았으므로 정수형으로 바꾼후 -1을 곱해준다
                i++;
            }
            else { //양수인 경우
                p.temp = tmp_str[i] - '0';
            }
        }
        else if((i - tmp) % 4 == 2){ //공백으로 인해 2부터 4씩 증가하며 지수가 나온다
            p.termArray[tmp_str[i] - '0'] += p.temp;
        }
    }
    return is;
}

//출력 오버로딩
ostream& operator<<(ostream& os, Polynomial& p)
{
    for (int i = MaxDegree; i >= 0; i--) //최대 차수부터 1씩 줄어들면서 항을 뽑아낸다
    {
        if(p.termArray[i] != 0) { //termArray배열의 i 인덱스에 있는 계수 값이 0이 아닐 때
            if(!p.isFirstNum) { //첫째항이 아닐 때
                if(p.termArray[i] < 0) { //계수가 음수일 때
                    os << " " << "-" << " ";
                    if(i == 0) { //상수항일 때
                        os << (- 1) * p.termArray[i];
                    }
                    else if(i == 1) { //1차항일 때
                        if(p.termArray[i] == -1) { //계수가 -1일 때
                            os << "x";
                        }
                        else { //계수가 -1이 아닌 음수일 때
                            os << (-1) * p.termArray[i];
                            os << "x";
                        }
                    }
                    else { // 다차항
                        if(p.termArray[i] == -1) { //계수가 -1일 때
                            os << "x";
                            os << "^" << i;
                        }
                        else { //계수가 -1이 아닌 음수일 때
                            os << (-1) * p.termArray[i];
                            os << "x";
                            os << "^" << i;
                        }
                    }
                }
                else { //계수가 양수일 때
                    os << " " << "+" << " ";
                    if(i == 0) { //상수항
                        os << p.termArray[i];
                    }
                    else if(i == 1) { //1차항
                        if(p.termArray[i] == 1) { //계수가 1일 때
                            os << "x";
                        }
                        else { // 계수가 1이 아닌 양수일 때
                            os << p.termArray[i];
                            os << "x";
                        }
                    }
                    else { //다차항
                        if(p.termArray[i] == 1) { //계수가 1일 때
                            os << "x";
                            os << "^" << i;
                        }
                        else { //계수가 1이 아닌 양수일 때
                            os << p.termArray[i];
                            os << "x";
                            os << "^" << i;
                        }
                    }
                }
            }
            else { //첫번째 항일 때
                p.isFirstNum = false;
                if(p.termArray[i] < 0) { //계수가 음수일 때
                    os << "-" << " ";
                    if(i == 0) { //상수일 때
                        os << (- 1) * p.termArray[i];
                    }
                    else if(i == 1) { //1차항
                        if(p.termArray[i] == -1) { //계수가 -1일 때
                            os << "x";
                        }
                        else { //계수가 -1이 아닌 음수일 떄
                            os << (-1) * p.termArray[i];
                            os << "x";
                        }
                    }
                    else { //다차항
                        if(p.termArray[i] == -1) { //계수가 -1일 때
                            os << "x";
                            os << "^" << i;
                        }
                        else { //계수가 -1이 아닌 음수일 때
                            os << (-1) * p.termArray[i];
                            os << "x";
                            os << "^" << i;
                        }
                    }
                }
                else { //계수가 양수일 때
                    if(i == 0) { //상수항
                        os << p.termArray[i];
                    }
                    else if(i == 1) { //계수가 1일 때
                        if(p.termArray[i] == 1) {
                            os << "x";
                        }
                        else { //계수가 1이 아닌 양수일 때
                            os << p.termArray[i];
                            os << "x";
                        }
                    }
                    else { //다차항
                        if(p.termArray[i] == 1) { //계수가 1일 때
                            os << "x";
                            os << "^" << i;
                        }
                        else { //계수가 1이 아닌 양수일 때
                            os << p.termArray[i];
                            os << "x";
                            os << "^" << i;
                        }
                    }
                }
            }
        }
    }
    return os;
}

//* 연산자 오버로딩
Polynomial operator * (Polynomial& p1, Polynomial& p2)
{
    Polynomial MUL; //다항식 곱셈이 된 새로운 객체 생성

    for (int i = 0; i < MaxDegree; i++) //0부터 최대 차수까지
    {
        if (p1.termArray[i] == 0) //p1의 계수가 0이면 continue
        {
            continue;
        }
        else //p1의 계수가 0이 아닐 때
        {
            for (int j = 0; j < MaxDegree; j++) //0부터 최대 차수까지
            {
                if (p2.termArray[j] == 0) //p2의 계수가 0이면 continue
                {
                    continue;
                }
                else //p2의 계수가 0이 아닐 때
                {
                    int exp = i + j; //p1의 지수와 p2의 지수 합 ( 곱셈을 하면 지수들은 더해진다. )

                    if (MUL.termArray[exp] != 0) //exp차 계수가 0이 아닐 때
                    {
                        MUL.termArray[exp] += p1.termArray[i] * p2.termArray[j];
                    }
                    else //계수가 0일 때
                    {
                        MUL.termArray[exp] = p1.termArray[i] * p2.termArray[j];
                    }
                }
            }
        }
    }
    return MUL;
}

//다항식에 값 대입하기
int Eval(int x, Polynomial& p)
{
    int sum = 0;
    for (int i = 0; i < MaxDegree; i++) //인덱스 0부터 MaxDegree -1까지
    {
        if(p.termArray[i] != 0) { //계수가 0이 아닐 때
            int tmp = 0;
            tmp += pow(x, i); //x의 i제곱
            tmp *= p.termArray[i]; //x의 i제곱된 값에 계수 곱하기
            sum += tmp; //항 하나씩 더해주기
        }
    }
    return sum;
}

#endif /* Polynomial_h */
