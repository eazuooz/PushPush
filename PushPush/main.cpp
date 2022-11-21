#include <iostream>
#include "Application.h"

int main()
{
	setlocale(LC_ALL, "");

	Application::GetInstance()->Initiailize();

	while (Application::GetInstance()->GetIsRunning())
	{
	    Application::GetInstance()->Update();
	    Application::GetInstance()->Rendering();
	}
	Application::GetInstance()->Destroy();

	return 0;
}

// 집이랑 플레이어 겹칠떄
// 1돌 2집 3플레이어


// 클리어
// 최종스테이지 저장해뒀다가 다시키면 그 스테이지에서 시작
// 돌맹이 넣엇을때 비프음



//이력서 연락 1주일
// 
// 면접 2주일뒤에
// 
// 코테 3주일

// 이진 균형 트리

// 스택 / 큐

// 정렬 알고리즘

// 깊이 / 넓이 우선탐색 dfs /BFS

// 그리디 알고리즘

// 그래프 / 트리 

// 동적계획 프로그래밍 

// 알고리즘 코딩테스트

// 컨텐츠 제작해와라 채팅 서버 프로그램 제작해와 

// 오브젝트풀 메모리풀 제작해와라

// std::vector 직접 제작해라

// 데브시스터즈 4문제 2문제 맞는다는 생각 하시면


// 대기업 나이도 서류
// 학력 인서울 사이버대 국립대 ( 고등학교 졸업 ) 학력

// 포트폴리오 개수마다 내부점수

// 자소서 이력서

// 코딩 테스트 점수

// 내부 채용

// 남 30
// 32
// 여 27~28 

// 슬슬 불안감도 

// 최종학력증명서
// 경력자 건강보험 기록 
// 경진대회 은상
// 성적표 x

// 정보처리기사


// 가산점 정보처리기사

