// 참고 자료: 책 <알고리즘 트레이닝: 프로그래밍 대회 입문 가이드> 2판 13장 기하

#include <iostream>
#include <complex>

using namespace std;

// 정수 좌표를 써도 되는 경우
// typedef long logn C;
// 실수 좌표를 쓰는 경우
typedef long double C;
typedef complex<C> P;

#define X real()
#define Y imag()

void comp()
{
    P p = {4, 2};
    cout << p.X << " " << p.Y << "\n"; // 4 2

    P a = {4, 2};
    P b = {3, -1};
    cout << abs(b-a) << "\n"; // 3.16228

    P v = {4, 2}; // x축 사이의 각도 (라디안=180r/pi도)
    cout << arg(v) << "\n"; // 0.463648
    v *= polar(1.0, 0.5); // 길이가 1.0이고 각도가 0.5라디안인 벡터 생성하는 함수
    cout << arg(v) << "\n"; // 0.963648
}

void point_and_line()
{
    // 외적 a X b
    // x_1 * y_2 - x_2 * y_1
    // >0 이면 왼쪽으로 회전, =0이면 0 또는 180도 회전, <0 이면 오른쪽으로 회전
    P a = {4, 2};
    P b = {1, 2};
    C p = (conj(a)*b).Y; // 외적 구하기
    
    // 점의 위치 판별하기
    // (p - s_1) x (p - s_2)
    // 양수라면 직선의 왼쪽, 음수라면 오른쪽, 0이라면 일직선상

    // 삼각형 넓이
    // |(s_1 - p) x (s_2 - p)| / 2
    
    // 점과 직선 사이 거리
    // d = (s_1 - p) x (s_2 - p) / |s_2 - s_1|

    // 선분 교차
    // 1. 겹치는 경우
    //      외적으로 일직선 상 확인 -> 정렬하여 겹치는지 확인
    // 2. 한 꼭짓점에서 만나는 경우
    //      네 가지 경우 확인 -> 1이 아닌 경우 점이 겹치는지만 확인
    // 3. 교차점 하나
    //      상대 선분에 대하여 왼쪽, 오른쪽에 각각 하나씩
    // 4. T자 형태
    //      한 점이 선분 위에
}

int main()
{
    comp();
    point_and_line();
}

