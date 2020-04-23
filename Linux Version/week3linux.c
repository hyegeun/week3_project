#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//전역 변수들  

int p1= 0;
int i1= 0;
int i2= 0;
int i3= 0;
int m1= 0;

struct information { //구조체  
	char name[20][15];
	int score[20];
};

struct information people_game; //인물퀴즈 
struct information idrama1; //도깨비  
struct information idrama2; //질투의 화신  
struct information idrama3; //상속자들 
struct information movie1; //명대사퀴즈  

int main(void) {

	menu();
	
	return 0;
}

void gotoxy(int x, int y) { //좌표 설정 함수  

    printf("\033[%d;%df",y,x);

    fflush(stdout);

}

void gameline() {  
	
	gotoxy(20, 5);
	printf("%c[1;33m", 27);
	int line;
	
	for ( line =0; line <80; line+=2 ) {
		gotoxy(20+line, 5);
		printf("□");
	}
		
	gotoxy(20, 35);
	for ( line =0; line <80; line+=2 ) {
		gotoxy(20+line, 35);
		printf("□");
	}
	    
	for ( line = 6; line < 35; line++) {
		gotoxy(20, line);
		printf("□");
		gotoxy(98, line);
		printf("□");
	}	
}

void gameanswer() { //정답 라인  
	
	int line;
	printf("%c[1;33m", 27);
	gotoxy(40, 25);
	for ( line =0; line < 40; line++)
	    printf("-");
	gotoxy(40, 27);
	for ( line =0; line < 40; line++)
	    printf("-");
	
	printf("%c[1;37m", 27);
	gotoxy(42, 26);
	printf("☞  ");
}

void gamemaker() {
	printf("%c[1;33m", 27);
	gotoxy(55, 7);
	printf("QUIZ GAME");
	gotoxy(69, 9);
	printf("2분반 3주차 팀 김혜근, 황선홍");
	gotoxy(22, 10);
	printf("----------------------------------------------------------------------------");
}

void menu() { //메뉴  
	
	gameline();
	gameanswer();
	gamemaker();
	printf("%c[1;36m", 27);
	gotoxy(50, 14);
	printf("1. 인물 퀴즈");
	gotoxy(50, 16);
	printf("2. 드라마 퀴즈");
	gotoxy(50, 18);
	printf("3. 명대사 퀴즈");
	gotoxy(50, 20);
	printf("4. 랭킹");
	
	printf("%c[1;37m", 27);
	gotoxy(43, 23);
	printf("들어가고 싶은 번호를 입력해 주세요."); 
	
	int num;
	gotoxy(45, 26);
	scanf("%d", &num);
	
	switch (num) {
		case 1:
			system("clear");
			people_quiz();
			break;
			
		case 2:
			system("clear");
			dramamenu();
			break;
		
		case 3:
			system("clear");
		    moviequiz_menu();
			break;
		
		case 4:
			system("clear");
			rank();
			break;
			
		default:
			system("clear");
			menu();
			break;
	}
	
}

void people_quiz() //인물퀴즈  
{
	while(1)
	{
		switch(people_quiz_menu())
		{
			case 1:
				system("clear");
				usage();
				break;
		
			case 2:
				system("clear");
				peoplegame();
				break;
			
			case 3:
				system("clear");
				menu();
				break;
			
			default:
				system("clear");
				break;
		}
	}
}

int people_quiz_menu() //인물퀴즈 메뉴  
{	
	peopleline();

	gotoxy(50, 14);
	printf("%c[1;36m", 27);
	printf("1. 게임 이용 방법");
	gotoxy(50, 16);
	printf("2. 게임 시작");
	gotoxy(50, 18);
	printf("3. 메뉴로 돌아가기");
			
	gotoxy(43, 23);
	printf("%c[1;37m", 27);
	printf("들어가고 싶은 번호를 입력해 주세요.");
	int num;
	gotoxy(45, 26);
	scanf("%d", &num);
	
	return num;
}

void usage() //인물퀴즈 설명  
{
	int num;
	peopleline();
	gotoxy(40, 14);
	printf("%c[1;36m", 27);
	printf("주어지는 별명 혹은 극중 이름을 가지고");
	gotoxy(43, 16); 
	printf("인물의 이름을 맞추는 게임입니다.");
	printf("%c[1;37m", 27);
	gotoxy(38, 23);
	printf("뒤로가기를 원하시면 [Enter]를 입력해 주세요.\n");
	gotoxy(45, 26);
	__fpurge(stdin);
	getchar();
	getchar();
}

void peopleline() { //인물퀴즈 라인  
	
	system("clear");
	gameline();
	gamemaker();
	gameanswer();
	
	gotoxy(55, 8);
	printf("%c[1;36m", 27);
	printf("인물 퀴즈");
}

void peoplegame() //인물퀴즈 게임  
{
	char checkname[20], ans[10];
	int j = 0;
	
	peopleline();
	printf("%c[1;37m", 27);
	gotoxy(45, 15);
	printf("이름을 '홍길동'처럼 적어주세요.");
	
	gotoxy(45, 26);
	scanf("%s", checkname);
	__fpurge(stdin); //입력 버퍼 지움  
	
	while ( !(strcmp(checkname, people_game.name[j]) == 0) ) { //존재하는 이름 확인  
		
		if (j == p1) {
			
			p1++;
			break;
    	}
		else j++;
    }
    
	strncpy(people_game.name[j], checkname, 20);
	
	int score=0;
	
	// 1
	system("clear");
	peopleline();
	printf("%c[1;37m", 27); 
	gotoxy(50, 15);
	printf("구준표\t김탄");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);
	
	if(strcmp(ans, "이민호") == 0)
		score++;
	
	// 2
	system("clear");
	peopleline();
	printf("%c[1;37m", 27);
	gotoxy(50, 15);	
	printf("유산슬\t1인자");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);
	
	if(strcmp(ans, "유재석") == 0)
		score++;
	
	// 3
	system("clear");
	peopleline();
	printf("%c[1;37m", 27); 
	gotoxy(50, 15);	
	printf("이익준\t납뜩이");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);
	
	if(strcmp(ans, "조정석") == 0)
		score++;
		
	// 4
	system("clear");
	peopleline();
	printf("%c[1;37m", 27); 
	gotoxy(50, 15);
	printf("조이서\t마녀");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);
	
	if(strcmp(ans, "김다미") == 0)
		score++;
	
	// 5
	system("clear");
	peopleline();
	printf("%c[1;37m", 27);
	gotoxy(50, 15);	
	printf("소니\t손세이셔널");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);
	
	if(strcmp(ans, "손흥민") == 0)
		score++;
		
	// 6
	system("clear");
	peopleline();
	printf("%c[1;37m", 27);
	gotoxy(50, 15);
	printf("매미킴\t김호들");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);
	
	if(strcmp(ans, "김동현") == 0)
		score++;
		
	// 7
	system("clear");
	peopleline();
	printf("%c[1;37m", 27); 
	gotoxy(50, 15);
	printf("하찮은\t십잡스");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);
	
	if(strcmp(ans, "박명수") == 0)
		score++;
		
	// 8
	system("clear");
	peopleline();
	printf("%c[1;37m", 27); 
	gotoxy(50, 15);
	printf("나쁜놈\t유진 초이");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);
	
	if(strcmp(ans, "이병헌") == 0)
		score++;
	
	// 9
	system("clear");
	peopleline();
	printf("%c[1;37m", 27);
	gotoxy(50, 15);
	printf("장그래\t허문학");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);
	
	if(strcmp(ans, "임시완") == 0)
		score++;
	
	// 10
	system("clear");
	peopleline();
	printf("%c[1;37m", 27); 
	gotoxy(50, 15);
	printf("리정혁\t윤진우");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);

	if(strcmp(ans, "현빈") == 0)
		score++;
	
	//11	
	system("clear");
	peopleline();
	printf("%c[1;37m", 27);
	gotoxy(50, 15);
	printf("지은탁\t홍설");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);

	if(strcmp(ans, "김고은") == 0)
		score++; 
	
	//12
	system("clear");
	peopleline();
	printf("%c[1;37m", 27); 
	gotoxy(50, 15);
	printf("황시목\t뮤지컬");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);

	if(strcmp(ans, "조승우") == 0)
		score++; 
	
	//13
	system("clear");
	peopleline();
	printf("%c[1;37m", 27); 
	gotoxy(50, 15);
	printf("엑소\t백일의 낭군님(예명)");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);

	if(strcmp(ans, "디오") == 0)
		score++;
	
	//14
	system("clear");
	peopleline();
	printf("%c[1;37m", 27);
	gotoxy(50, 15);
	printf("얼굴천재\t강남미인");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);

	if(strcmp(ans, "차은우") == 0)
		score++; 
	
	//15
	system("clear");
	peopleline();
	printf("%c[1;37m", 27);
	gotoxy(50, 15);
	printf("슈퍼주니어\t신서유기");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);

	if(strcmp(ans, "조규현") == 0)
		score++;
	
	//16
	system("clear");
	peopleline();
	printf("%c[1;37m", 27); 
	gotoxy(50, 15);
	printf("하이에나\t시그널");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);

	if(strcmp(ans, "김혜수") == 0)
		score++;
	
	//17
	system("clear");
	peopleline();
	printf("%c[1;37m", 27); 
	gotoxy(50, 15);
	printf("3단고음\t무한가요제");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);

	if(strcmp(ans, "아이유") == 0)
		score++; 
	
	//18
	system("clear");
	peopleline();
	printf("%c[1;37m", 27); 
	gotoxy(50, 15);
	printf("동백꽃\t청년경찰");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);

	if(strcmp(ans, "강하늘") == 0)
		score++; 
	
	//19
	system("clear");
	peopleline();
	printf("%c[1;37m", 27); 
	gotoxy(50, 15);
	printf("해원맥\t이창");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);

	if(strcmp(ans, "주지훈") == 0)
		score++; 
	
	//20
	system("clear");
	peopleline();
	printf("%c[1;37m", 27); 
	gotoxy(50, 15);
	printf("감빵생활\t의사생활");
	gotoxy(45, 26);
	scanf("%s", ans);
	__fpurge(stdin);

	if(strcmp(ans, "정경호") == 0)
		score++;
		
	system("clear");
	peopleline(); 
	printf("%c[1;37m", 27);
	gotoxy(45, 15);
	printf("%s 님의 점수", people_game.name[j]);
	gotoxy(45, 17);
	printf("20문제 중 총 %d 문제 맞혔습니다.", score);
	
	printf("%c[1;36m", 27);
	if (score == 20) { //점수에 따라 글귀가 달라짐  
	    gotoxy(45, 19);
        printf("인물퀴즈 킬러!"); } 
	
	else if (score >15) {
        gotoxy(45, 19); 
	    printf("연예인을 많이 아는 사람"); }
	
	else if (score >10) {
        gotoxy(45, 19); 
	    printf("그래도 유명한 사람은 아는 사람"); } 
	
	else if (score >5) {
        gotoxy(45, 19); 
	    printf("티비 자주 안 보니...?"); } 
	
	else {
		gotoxy(45, 19);
	    printf("아는 연예인 있긴 있어?"); }
	
	gotoxy(45, 26); 
	if (score > people_game.score[j])
	    people_game.score[j] = score;
	
	sleep(5);
	system("clear");
	menu();
}

int dramaselect() { //드라마 선택  
	
	gotoxy(38, 11);
	printf("%c[1;37m", 27); 
	printf("드라마 퀴즈는 선택한 드라마에 대한 퀴즈를 출제합니다.");
	gotoxy(50, 14);
	printf("%c[1;36m", 27);
	printf("1. 도깨비");
	gotoxy(50, 16);
	printf("2. 질투의 화신");
	gotoxy(50, 18);
	printf("3. 상속자들");
	gotoxy(50, 20);
	printf("4. 메뉴로 돌아가기");
			
	gotoxy(43, 23);
	printf("%c[1;37m", 27);
	printf("들어가고 싶은 번호를 입력해 주세요.");
	int num;
	gotoxy(45, 26);
	scanf("%d", &num);
	
	return num; 
}

void dramamenu() { //드라마 메뉴  
	
	gameline();
	gamemaker();
	gameanswer();

	switch (dramaselect()) {
		case 1:
			system("clear");
			drama1();
			break;
			
		case 2:
			system("clear");
			drama2();
			break;
			
		case 3:
			system("clear");
			drama3();
			break;
			
		case 4:
			system("clear");
			menu();
			break; 
			
		default:
			system("clear");
			menu(); 
			break;
	}
}

void drama1line() { //드라마 라인  
	
	gameline();
	gamemaker();
	gameanswer();
	
	gotoxy(56, 8);
	printf("%c[1;36m", 27); 
	printf("도깨비");
}

void drama1() { //도깨비  
	
	drama1line();
	
	char checkname[20];
	int j =0;
	
	printf("%c[1;37m", 27);
	gotoxy(45, 15);
	printf("이름을 '홍길동'처럼 적어주세요.");
	
	gotoxy(45, 26);
	scanf("%s", checkname);
	__fpurge(stdin); //입력 버퍼 지움  
	
	while ( !(strcmp(checkname, idrama1.name[j]) == 0) ) { //존재하는 이름 확인  
		
		if ( j == i1) {
			
			i1++;
			break;
    	}
		else j++;
    }
    
	strncpy( idrama1.name[j], checkname, 20 );
	int score = 0;
	
	//1 
	system("clear");
	drama1line();
	char charanswer[15];
	int intanswer; 
	printf("%c[1;37m", 27);
	gotoxy(52, 15);
	printf("도깨비의 이름은?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "김신") == 0)
	    score++;
	
	//2  
	system("clear");
	drama1line();
	printf("%c[1;37m", 27);
	gotoxy(50, 15);
	printf("도깨비의 나이는 몇 살?");
	gotoxy(45, 26);
	scanf("%d", &intanswer);
	__fpurge(stdin);
	
	if (intanswer == 939)
	    score++;
	
	//3
	system("clear");
	drama1line();
	printf("%c[1;37m", 27);
	gotoxy(48, 15);
	printf("도깨비 신부의 이름은?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "지은탁") == 0)
	    score++;
	
	//4
	system("clear");
	drama1line();
	printf("%c[1;37m", 27); 
	gotoxy(43, 15);
	printf("도깨비 가슴에는 무엇이 박혀 있을까?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "칼") == 0)
	    score++;
	
	//5 
	system("clear");
	drama1line();
	printf("%c[1;37m", 27); 
	gotoxy(33, 15);
	printf("도깨비는 저승사자를 보고 무엇을 썼다고 말했을까? 'OOOO O'");
	gotoxy(45, 26);
	scanf("%[^\t\n]s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "상스러운 갓") == 0)
	    score++;
	
	//6
	system("clear");
	drama1line();
	printf("%c[1;37m", 27);
	gotoxy(39, 15);
	printf("대대로 도깨비를 모시던 집안의 재벌 3세 이름은?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "유덕화") == 0)
	    score++;
	
	//7
    system("clear");
	drama1line();
	printf("%c[1;37m", 27); 
	gotoxy(42, 15);
	printf("도깨비 기분에 따라 무엇이 바뀌었을까?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "날씨") == 0)
	    score++;
	
	//8   
	system("clear");
	drama1line();
	printf("%c[1;37m", 27);
	gotoxy(35, 15);
	printf("지은탁이 9살 때 저승사자에게서 구해준 사람은? 'OOOO'");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "삼신할매") == 0)
	    score++;
	
	//9    
	system("clear");
	drama1line();
	printf("%c[1;37m", 27);
	gotoxy(35, 15);
	printf("지은탁은 9살 이후 몇 살 때 저승사자를 다시 만났을까?");
	gotoxy(45, 26);
	scanf("%d", &intanswer);
	__fpurge(stdin);
	
	if (intanswer == 19)
	    score++;
	
	//10
	system("clear");
	drama1line();
	printf("%c[1;37m", 27);
	gotoxy(45, 15);
	printf("저승사자(김우빈) 전생의 본명은?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "왕여") == 0)
	    score++;
	
	system("clear");
	drama1line();
	
	printf("%c[1;37m", 27); 
	gotoxy(45, 15);
	printf("%s 님의 점수", idrama1.name[j]);
	gotoxy(45, 17);
	printf("10문제 중 총 %d 문제 맞혔습니다.", score);

	printf("%c[1;36m", 27);
	if (score == 10) {
		gotoxy(45, 19);
	    printf("도깨비 한 번 본게 아닌 것 같은데?"); }
	
	else if (score >5) {
		gotoxy(45, 19);
	    printf("도깨비 보긴 봤는데 기억이 나지 않는거지?"); }
	
	else {
		gotoxy(45, 19);
	    printf("도깨비 보긴 봤어...?"); }

	gotoxy(45, 26);
	if (score > idrama1.score[j])
	    idrama1.score[j] = score;
	
	sleep(5);
	system("clear");
	menu();
}

void drama2line() { //질투의 화신 라인  
	
	gameline();
	gamemaker();
	gameanswer();
	
	gotoxy(54, 8);
	printf("%c[1;36m", 27); 
	printf("질투의 화신");
}

void drama2() { //질투의 화신
	
	drama2line();
	
	char checkname[20];
	int j =0;
	
	printf("%c[1;37m", 27);
	gotoxy(45, 15);
	printf("이름을 '홍길동'처럼 적어주세요.");
	
	gotoxy(45, 26);
	scanf("%s", checkname);
	__fpurge(stdin);//입력 버퍼 지움  
	
	while ( !(strcmp(checkname, idrama2.name[j]) == 0) ) { //존재하는 이름 확인  
		
		if ( j == i2) {
			
			i2++;
			break;
    	}
		else j++;
    }
    
	strncpy( idrama2.name[j], checkname, 20 );
	int score = 0;
	
	//1
	system("clear");
	drama2line();
	char charanswer[15];
	int intanswer; 
	printf("%c[1;37m", 27);
	gotoxy(45, 15);
	printf("조정석이 맡은 남주인공 이름은?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "이화신") == 0)
	    score++;
	
	//2    
	system("clear");
	drama2line();
	printf("%c[1;37m", 27);
	gotoxy(42, 15);
	printf("이화신을 짝사랑하던 여주인공 이름은?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "표나리") == 0)
	    score++;
	
	//3
	system("clear");
	drama2line();
	printf("%c[1;37m", 27); 
	gotoxy(51, 15);
	printf("표나리의 직업은?");
	gotoxy(54, 17);
	printf("- OOOOO -");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "기상캐스터") == 0)
	    score++;
	
	//4    
	system("clear");
	drama2line();
	printf("%c[1;37m", 27); 
	gotoxy(39, 15);
	printf("이화신과 표나리는 외국 어디서 다시 만났을까?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "태국") == 0)
	    score++;
	
	//5
	system("clear");
	drama2line();
	printf("%c[1;37m", 27); 
	gotoxy(47, 15);
	printf("이화신은 무슨 병에 걸렸을까?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "유방암") == 0)
	    score++;
	    
	//6
	system("clear");
	drama2line();
	printf("%c[1;37m", 27); 
	gotoxy(41, 15);
	printf("이화신과 표나리가 다니는 방송국 이름은?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "sbc") == 0)
	    score++;
	
	//7    
	system("clear");
	drama2line();
	printf("%c[1;37m", 27); 
	gotoxy(47, 15);
	printf("이빨강의 엄마는 몇 명일까?");
	gotoxy(45, 26);
	scanf("%d", &intanswer);
	__fpurge(stdin);
	
	if (intanswer == 2)
	    score++;
	
	//8
	system("clear");
	drama2line();
	printf("%c[1;37m", 27); 
	gotoxy(39, 15);
	printf("표나리를 두고 이화신과 경쟁하던 사람 이름은?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "고정원") == 0)
	    score++;
	
	//9    
	system("clear");
	drama2line();
	printf("%c[1;37m", 27);
	gotoxy(46, 15);
	printf("표나리가 되고 싶었던 직업은?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "아나운서") == 0)
	    score++;
	
	//10    
	system("clear");
	drama2line();
	printf("%c[1;37m", 27); 
	gotoxy(39, 15);
	printf("이화신은 표나리에게 라면 몇 번을 먹자고 했을까?");
	gotoxy(45, 26);
	scanf("%d", &intanswer);
	__fpurge(stdin);
	
	if (intanswer == 1000)
	    score++;
	    
	system("clear");
	drama2line();
	printf("%c[1;37m", 27);
	gotoxy(45, 15);
	printf("%s 님의 점수", idrama2.name[j]);
	gotoxy(45, 17);
	printf("10문제 중 총 %d 문제 맞혔습니다.", score);
	
	printf("%c[1;36m", 27);
	if (score == 10) {
		gotoxy(45, 19);
	    printf("질투의 화신 한 번 본게 아닌 것 같은데?"); }
	
	else if (score >5) {
		gotoxy(45, 19);
	    printf("질투의 화신 보긴 봤는데 기억이 나지 않는거지?"); }
	
	else {
		gotoxy(45, 19);
	    printf("질투의 화신 보긴 봤어...?"); }

	gotoxy(45, 26);
	if (score > idrama2.score[j])
	    idrama2.score[j] = score;
	    
	sleep(5);
	system("clear");
	menu();
}

void drama3line() { //상속자들 라인  
	
	gameline();
	gamemaker();
	gameanswer();
	
	gotoxy(56, 8);
	printf("%c[1;36m", 27); 
	printf("상속자들");
}

void drama3() { //상속자들  
	
	drama3line();
	
	char checkname[20];
	int j =0;
	
	printf("%c[1;37m", 27);
	gotoxy(45, 15);
	printf("이름을 '홍길동'처럼 적어주세요.");
	
	gotoxy(45, 26);
	scanf("%s", checkname);
	__fpurge(stdin);//입력 버퍼 지움  
	
	while ( !(strcmp(checkname, idrama3.name[j]) == 0) ) { //존재하는 이름 확인  
		
		if ( j == i3) {
			
			i3++;
			break;
    	}
		else j++;
    }
    
	strncpy( idrama3.name[j], checkname, 20 );
	int score = 0;
	
	//1
	system("clear");
	drama3line();
	char charanswer[15];
	int intanswer; 
	printf("%c[1;37m", 27);
	gotoxy(46, 15);
	printf("김탄과 차은상이 만난 나라는?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "미국") == 0)
	    score++;
	
	//2    
	system("clear");
	drama3line();
	printf("%c[1;37m", 27); 
	gotoxy(34, 15);
	printf("차은상이 가지고 있던 무엇 때문에 마약으로 의심받았을까?");
	gotoxy(55, 17);
	printf("- OOOO -");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "미숫가루") == 0)
	    score++;
	
	//3    
	system("clear");
	drama3line();
	printf("%c[1;37m", 27); 
	gotoxy(47, 15);
	printf("김탄네 집은 무슨 그룹일까?");
	gotoxy(55, 17);
	printf("- OOOO -");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "제국그룹") == 0)
	    score++;
	
	//4    
	system("clear");
	drama3line();
	printf("%c[1;37m", 27);
	gotoxy(49, 15);
	printf("이보나의 전남친 이름은?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "김탄") == 0)
	    score++;
	
	//5    
	system("clear");
	drama3line();
	printf("%c[1;37m", 27); 
	gotoxy(39, 15);
	printf("최영도는 차은상을 불러내서 무엇을 먹었을까?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "짜장면") == 0)
	    score++;
	
	//6    
	system("clear");
	drama3line();
	printf("%c[1;37m", 27); 
	gotoxy(42, 15);
	printf("최영도는 아버지와 무슨 운동을 했을까?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "유도") == 0)
	    score++;
	
	//7
	system("clear");
	drama3line();
	printf("%c[1;37m", 27); 
	gotoxy(42, 15);
	printf("김탄은 중간고사에서 몇 등을 하였을까?");
	gotoxy(45, 26);
	scanf("%d", &intanswer);
	__fpurge(stdin);
	
	if (intanswer == 100)
	    score++;
	
	//8
	system("clear");
	drama3line();
	printf("%c[1;37m", 27);
	gotoxy(40, 15);
	printf("이효신은 수능도 안 보고 어디로 튀었을까?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "군대") == 0)
	    score++;
	
	//9    
	system("clear");
	drama3line();
	printf("%c[1;37m", 27); 
	gotoxy(33, 15);
	printf("김탄은 무엇을 들켰길래 최영도와 사이가 나빠졌을까? 'OO'");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "서자") == 0)
	    score++;
	
	//10
	system("clear");
	drama3line();
	printf("%c[1;37m", 27); 
	gotoxy(35, 15);
	printf("김탄은 서자에서 반나절만에 무엇으로 등극했을까? 'OOO'");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "대주주") == 0)
	    score++;
	    
	system("clear");
	drama3line();
	printf("%c[1;37m", 27);
	gotoxy(45, 15);
	printf("%s 님의 점수", idrama3.name[j]);
	gotoxy(45, 17);
	printf("10문제 중 총 %d 문제 맞혔습니다.", score);
	
	printf("%c[1;36m", 27);
	if (score == 10) {
		gotoxy(45, 19);
	    printf("상속자들 한 번 본게 아닌 것 같은데?"); }
	
	else if (score >5) {
		gotoxy(45, 19);
	    printf("상속자들 보긴 봤는데 기억이 나지 않는거지?"); }
	
	else {
		gotoxy(45, 19);
	    printf("상속자들 보긴 봤어...?"); }

	gotoxy(45, 26);
	if (score > idrama3.score[j])
	    idrama3.score[j] = score;
	    
	sleep(5);
	system("clear");
	menu();
}

int moviequiz_select() { //명대사퀴즈 선택  
	
	gameline();
	gamemaker();
	gameanswer();
	
	printf("%c[1;37m", 27);
	gotoxy(28, 12);
	printf("명대사 퀴즈는 드라마나 영화 명대사를 보고 제목을 맞추는 게임입니다");
	
	printf("%c[1;36m", 27);
	gotoxy(50, 15);
	printf("1. 게임 시작");
	gotoxy(50, 17);
	printf("2. 메뉴로 돌아가기");
	
	gotoxy(43, 23);
	printf("%c[1;37m", 27);
	printf("들어가고 싶은 번호를 입력해 주세요.");
	int num;
	gotoxy(45, 26);
	scanf("%d", &num);
	
	return num; 
}

void moviequiz_menu() { //명대사퀴즈 메뉴  
	
	switch(moviequiz_select()) {
		
		case 1:
			system("clear");
			moviequiz();
			break;
		
		default:
			system("clear");
			menu();
			break;
	}
}

void moviequiz_line() {
	gameline();
	gamemaker();
	gameanswer();
	
	printf("%c[1;36m", 27);
	gotoxy(54, 8);
	printf("명대사 퀴즈");
}

void moviequiz() { //명대사퀴즈  
	
	moviequiz_line();
	
	char checkname[20];
	int j =0;
	
	printf("%c[1;37m", 27);
	gotoxy(45, 15);
	printf("이름을 '홍길동'처럼 적어주세요.");
	
	gotoxy(45, 26);
	scanf("%s", checkname);
	__fpurge(stdin); //입력 버퍼 지움  
	
	while ( !(strcmp(checkname, movie1.name[j]) == 0) ) { //존재하는 이름 확인  
		
		if ( j == m1) {
			
			m1++;
			break;
    	}
		else j++;
    }
    
	strncpy( movie1.name[j], checkname, 20 );
	int score = 0;
	
	//1
	system("clear");
	moviequiz_line();
	char charanswer[15];
	int intanswer; 
	printf("%c[1;37m", 27); 
	gotoxy(44, 15);
	printf("지금 내 기분이 그래. 어이가 없네?");
	gotoxy(56, 17);
	printf("- OOO -");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "베테랑") == 0)
	    score++;
	
	//2    
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27);
	gotoxy(47, 15);
	printf("이것은 갈비인가, 통닭인가? ");
	gotoxy(55, 17);
	printf("- OOOO -");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "극한직업") == 0)
	    score++;
	
	//3
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27);
	gotoxy(50, 15);
	printf("내가 왕이 될 상인가?");
	gotoxy(57, 17);
	printf("- OO -");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "관상") == 0)
	    score++;
	
	//4
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27); 
	gotoxy(35, 15);
	printf("자기 인생에 물음표 던지지마. 그냥 느낌표만 딱! 던져.");
	gotoxy(38, 17);
	printf("물음표와 느낌표 둘 다 섞어서 던지면 더 나쁘고");
	gotoxy(40, 19);
	printf("난 될거다, 난 될거다. 난 이번에 꼭 될거다.");
	gotoxy(52, 21);
	printf("느낌표. 알았어?");
	gotoxy(54, 23);
	printf("- OOO OO -");
	
	gotoxy(45, 26);
	scanf("%[^\t\n]s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "질투의 화신") == 0)
	    score++;
	
	//5    
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27); 
	gotoxy(40, 13);
	printf("더 많이 사랑해서 약자가 되는 것이 아니라");
	gotoxy(43, 15);
	printf("마음에 여유가 없어서 약자가 되는거야");
	gotoxy(45, 17);
	printf("내가 준 것을 받으려고 하는 조바심");
	gotoxy(44, 19);
	printf("내가 사랑했으므로 행복했다, 괜찮다");
	gotoxy(55, 21);
	printf("그게 여유지");
	gotoxy(54, 23);
	printf("- OOO OOOO -");
	
	gotoxy(45, 26);
	scanf("%[^\t\n]s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "괜찮아 사랑이야") == 0)
	    score++;
	    
	//6
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27); 
	gotoxy(50, 15);
	printf("아직 한 발 남았다...");
	gotoxy(56, 17);
	printf("- OOO -");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "아저씨") == 0)
	    score++;
	    
	//7
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27);
	gotoxy(47, 13);
	printf("아무리 빨리 이 새벽을 맞아도");
	gotoxy(45, 15);
	printf("어김없이 길에는 사람들이 있었다.");
	gotoxy(42, 17);
	printf("남들이 아직 꿈 속을 헤멜거라 생각했지만");
	gotoxy(54, 19);
	printf("언제나 그렇듯");
	gotoxy(51, 21);
	printf("세상은 나보다 빠르다.");
	gotoxy(57, 23);
	printf("- OO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "미생") == 0)
	    score++;
	    
	//8
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27);
	gotoxy(49, 15);
	printf("압니다. 저도 잘 알지요.");
	gotoxy(48, 17);
	printf("대한민국 헌법 제 1조 2항");
	gotoxy(30, 19);
	printf("대한민국 주권은 국민에게 있고 모든 권력은 국민으로부터 나온다.");
	gotoxy(51, 21);
	printf("국가란 국민입니다.");
	gotoxy(56, 23);
	printf("- OOO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "변호인") == 0)
	    score++;
	
	//9    
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27); 
	gotoxy(51, 15);
	printf("낭만 보존의 법칙");
	gotoxy(30, 17);
	printf("대부분의 사람이 존재하는 것을 알면서도 존재하지 않는다고 믿는.");
	gotoxy(33, 19);
	printf("그러면서도 누군가는 꼭 지켜줬으면 하는 아름다운 가치들.");
	gotoxy(53, 21);
	printf("- OOOO OOO -");
	
	gotoxy(45, 26);
	scanf("%[^\t\n]s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "낭만닥터 김사부") == 0)
	    score++;
	    
	//10
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27); 
	gotoxy(36, 15);
	printf("네가 너인 것에 다른 사람을 납득 시킬 필요는 없어");
	gotoxy(54, 17);
	printf("- OOO OOO-");
	
	gotoxy(45, 26);
	scanf("%[^\t\n]s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "이태원 클라쓰") == 0)
	    score++;
	    
	//11
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27);
	gotoxy(29, 11);
	printf("그 어떤 길을 택하더라도 가지 않는 길에 대한 미련은 남기 마련이다.");
	gotoxy(43, 13);
	printf("그래서 후회없는 선택이란 없는 법이고");
	gotoxy(46, 15);
	printf("그래서 삶의 정답이란 없는 법이다.");
	gotoxy(33, 17);
	printf("그저 선택한 길을 정답이라 믿고 정답으로 만들어가면 그만이다.");
	gotoxy(40, 19);
	printf("내 지난 선택들을 후회없이 믿고 사랑하는 것");
	gotoxy(51, 21);
	printf("그게 삶의 정답이다.");
	gotoxy(54, 23);
	printf("- OOOO OOOO -");
	
	gotoxy(45, 26);
	scanf("%[^\t\n]s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "응답하라 1994") == 0)
	    score++;
	    
	//12
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27); 
	gotoxy(41, 15);
	printf("키스라는건 말이야. (중략) 비벼. 막 비벼");
	gotoxy(55, 17);
	printf("- OOOOO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "건축학개론") == 0)
	    score++;
	    
	//13
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27); 
	gotoxy(42, 15);
	printf("잊어달라 하였느냐. 잊어주길 바라느냐.");
	gotoxy(37, 17);
	printf("미안하구나. 잊으려 하였으나 너를 잊지 못하였다.");
	gotoxy(54, 19);
	printf("- OO OO O -");
	
	gotoxy(45, 26);
	scanf("%[^\t\n]s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "해를 품은 달") == 0)
	    score++;
	    
	//14
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27); 
	gotoxy(46, 15);
	printf("날이 좋아서 날이 좋지 않아서");
	gotoxy(51, 17);
	printf("모든 날이 행복했다.");
	gotoxy(57, 19);
	printf("- OOO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "도깨비") == 0)
	    score++;
	    
	//15
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27); 
	gotoxy(50, 15);
	printf("너 내가 누군지 아니?");
	gotoxy(56, 17);
	printf("- OOOO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "범죄도시") == 0)
	    score++;
	    
	//16
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27);
	gotoxy(43, 15);
	printf("호의가 계속되면 그게 권리인 줄 알아요.");
	gotoxy(56, 17);
	printf("- OOOO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "부당거래") == 0)
	    score++;
	    
	//17
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27); 
	gotoxy(40, 15);
	printf("갈 때 가더라도 담배 한 대 정도는 괜찮잖아?");
	gotoxy(49, 17);
	printf("거 죽기 딱 좋은 날씨네");
	gotoxy(57, 19);
	printf("- OOO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);

	if (strcmp(charanswer, "신세계") == 0)
	    score++;
	    
	//18
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27); 
	gotoxy(47, 15);
	printf("아들아, 너는 계획이 다 있구나");
	gotoxy(57, 17);
	printf("- OOO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);

	if (strcmp(charanswer, "기생충") == 0)
	    score++;
	    
	//19
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27);
	gotoxy(52, 15);
	printf("손은 눈보다 빠르다");
	gotoxy(58, 17);
	printf("- OO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	__fpurge(stdin);

	if (strcmp(charanswer, "타짜") == 0)
	    score++;
	    
	//20
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27); 
	gotoxy(33, 13);
	printf("아무일도 생기지 않겠지만, 만에하나 무슨 일이 생기더라도");
	gotoxy(49, 15);
	printf("그건 당신 탓이 아니오");
	gotoxy(34, 17);
	printf("난 아무 후회도 없고, 당신이 내 인생에 선물처럼 와줘서");
	gotoxy(53, 19);
	printf("감사할 뿐이오");
	gotoxy(54, 21);
	printf("- OOO OOO -");
	
	gotoxy(45, 26);
	scanf("%[^\t\n]s", charanswer);
	__fpurge(stdin);
	
	if (strcmp(charanswer, "사랑의 불시착") == 0)
	    score++;
	
	system("clear");
	moviequiz_line();
	printf("%c[1;37m", 27);
	gotoxy(45, 15);
	printf("%s 님의 점수", movie1.name[j]);
	gotoxy(45, 17);
	printf("20문제 중 총 %d 문제 맞혔습니다.", score);
	
	printf("%c[1;36m", 27);
	if (score == 20) {
		gotoxy(45, 19);
	    printf("안 본 드라마나 영화가 있긴 한가?"); }
	
	else if (score >15) {
		gotoxy(45, 19);
	    printf("드라마와 영화를 매우 즐겨보는 사람"); }
	
	else if (score >10) {
		gotoxy(45, 19);
	    printf("유명한 드라마나 영화는 많이 본 사람"); }
	
	else if (score >5) {
		gotoxy(45, 19);
	    printf("유명한 드라마나 영화를 들어보긴 한 사람"); }
	
	else if (score >0) {
		gotoxy(45, 19);
	    printf("드라마도 영화도 거의 안 보는 사람"); }
	
	else {
		gotoxy(45, 19);
	    printf("드라마도 영화도 안 보고 사세요...?"); }

	gotoxy(45, 26);
	if (score > movie1.score[j])
	    movie1.score[j] = score;
	
	sleep(5);
	system("clear");
	menu();
} 

void rank() { //랭킹 메뉴  
	
	gameline();
	gamemaker();
	gameanswer();
	
	switch (rankselect()) {
		case 1:
			system("clear");
			personrank(); 
			break;
			
		case 2:
			system("clear");
			dramarankmenu();
			break;
			
		case 3:
			system("clear");
			movierank();
			break;
			
		case 4:
			system("clear");
			menu();
			break; 
			
		default:
			system("clear");
			menu(); 
			break;
	}
}

int rankselect() { 
	
	printf("%c[1;37m", 27);
	gotoxy(44, 11);
	printf("랭킹은 상위 3위까지만 보여줍니다.");
	gotoxy(50, 14);
	printf("%c[1;36m", 27);
	printf("1. 인물퀴즈 랭킹");
	gotoxy(50, 16);
	printf("2. 드라마퀴즈 랭킹");
	gotoxy(50, 18);
	printf("3. 명대사퀴즈 랭킹");
	gotoxy(50, 20);
	printf("4. 메뉴로 돌아가기");
			
	gotoxy(43, 23);
	printf("%c[1;37m", 27);
	printf("들어가고 싶은 번호를 입력해 주세요.");
	int num;
	gotoxy(45, 26);
	scanf("%d", &num);
	
	return num; 
}

void dramarankmenu() { //드라마랭킹메뉴  
	
	gameline();
	gamemaker();
	gameanswer();
	
	switch (dramarankselect()) {
		case 1:
			system("clear");
			drama1rank();
			break;
			
		case 2:
			system("clear");
			drama2rank();
			break;
			
		case 3:
			system("clear");
			drama3rank();
			break;
			
		case 4:
			system("clear");
			menu();
			break; 
			
		default:
			system("clear");
			menu(); 
			break;
	}
} 

int dramarankselect() { //드라마랭킹 선택  
	
	printf("%c[1;37m", 27);
	gotoxy(44, 11);
	printf("랭킹은 상위 3위까지만 보여줍니다.");
	gotoxy(50, 14);
	printf("%c[1;36m", 27);
	printf("1. 도깨비 랭킹");
	gotoxy(50, 16);
	printf("2. 질투의 화신 랭킹");
	gotoxy(50, 18);
	printf("3. 상속자들 랭킹");
	gotoxy(50, 20);
	printf("4. 메뉴로 돌아가기");
			
	gotoxy(43, 23);
	printf("%c[1;37m", 27);
	printf("들어가고 싶은 번호를 입력해 주세요.");
	int num;
	gotoxy(45, 26);
	scanf("%d", &num);
	
	return num; 
} 

void personrank() { //인물퀴즈 랭킹  
	
	gameline();
	gamemaker();
	gameanswer();
	
	int i, j, k;
	char rankname[20];
	struct information ranker={0,};	// rank 구조체  
	
	for(i = 0; i < p1; i++)	{
		
		ranker.score[i] = people_game.score[i];		// rank 순위를 만들기 위해  
		strncpy(ranker.name[i], people_game.name[i], 20);
	}
	
	for(i = 0; i < p1-1; i++) 	{
		
		for(j = i+1; j < p1; j++) {
			
			if(ranker.score[i] < ranker.score[j]) {
				
				k = ranker.score[j];
				ranker.score[j] = ranker.score[i];
				ranker.score[i] = k;
				
				strncpy(rankname, ranker.name[j], 20);
				strncpy(ranker.name[j], ranker.name[i], 20);
				strncpy(ranker.name[i], rankname, 20);	
			}	
		}	
	}
	
	printf("%c[1;33m", 27);
	gotoxy(40, 12);
	printf("=============인물퀴즈[RANK]=============");
	gotoxy(40, 14);
	printf("[1st] Score : %2d\t| Name : %s", ranker.score[0], ranker.name[0]);	
	printf("%c[1;37m", 27);
	gotoxy(40, 17);
	printf("[2nd] Score : %2d\t| Name : %s", ranker.score[1], ranker.name[1]); 
	gotoxy(40, 19);
	printf("[3rd] Score : %2d\t| Name : %s", ranker.score[2], ranker.name[2]);
	
	int num;
	printf("%c[1;37m", 27);
	gotoxy(30, 23);
	printf("메뉴로 돌아가시려면 1, 랭킹메뉴로 돌아가시려면 2를 입력해주세요.");
	gotoxy(45, 26);
	scanf("%d", &num);
	
	switch(num)
	{
		case 1:
			system("clear");
			menu();
			break;
		
		case 2:
			system("clear");
			rank();
			break;
		
		default:
			system("clear");
			menu();
			break;
	}
}

void drama1rank() { //도깨비 랭킹  
	
	gameline();
	gamemaker();
	gameanswer();
	
	int i, j, k;
	char rankname[20];
	struct information ranker={0,};
	
	for(i = 0; i < i1; i++)	{
		
		ranker.score[i] = idrama1.score[i];	
		strncpy(ranker.name[i], idrama1.name[i], 20);
	}
	
	for(i = 0; i < i1-1; i++)
	{
		for(j = i+1; j < i1; j++)
		{
			if(ranker.score[i] < ranker.score[j])
			{
				k = ranker.score[j];
				ranker.score[j] = ranker.score[i];
				ranker.score[i] = k;
				
				strncpy(rankname, ranker.name[j], 20);
				strncpy(ranker.name[j], ranker.name[i], 20);
				strncpy(ranker.name[i], rankname, 20);	
			}	
		}	
	}
	
	printf("%c[1;33m", 27);
	gotoxy(40, 12);
	printf("==============도깨비[RANK]==============");
	gotoxy(40, 14);
	printf("[1st] Score : %2d\t| Name : %s\n\n", ranker.score[0], ranker.name[0]);
	printf("%c[1;37m", 27);
	gotoxy(40, 17);
	printf("[2nd] Score : %2d\t| Name : %s\n", ranker.score[1], ranker.name[1]); 
	gotoxy(40, 19);
	printf("[3rd] Score : %2d\t| Name : %s\n", ranker.score[2], ranker.name[2]);
	
	int num;
	printf("%c[1;37m", 27);
	gotoxy(30, 23);
	printf("메뉴로 돌아가시려면 1, 랭킹메뉴로 돌아가시려면 2를 입력해주세요.");
	gotoxy(45, 26);
	scanf("%d", &num);
	
	switch(num)
	{
		case 1:
			system("clear");
			menu();
			break;
		
		case 2:
			system("clear");
			rank();
			break;
		
		default:
			system("clear");
			menu();
			break;
	}
}

void drama2rank() { //질투의화신 랭킹  
	
	gameline();
	gamemaker();
	gameanswer();
	
	int i, j, k;
	char rankname[20];
	struct information ranker={0,}; 
	
	for(i = 0; i < i2; i++)	{
		
		ranker.score[i] = idrama2.score[i];	
		strncpy(ranker.name[i], idrama2.name[i], 20);
	}
	
	for(i = 0; i < i2-1; i++)
	{
		for(j = i+1; j < i2; j++)
		{
			if(ranker.score[i] < ranker.score[j])
			{
				k = ranker.score[j];
				ranker.score[j] = ranker.score[i];
				ranker.score[i] = k;
				
				strncpy(rankname, ranker.name[j], 20);
				strncpy(ranker.name[j], ranker.name[i], 20);
				strncpy(ranker.name[i], rankname, 20);	
			}	
		}	
	}
	
	printf("%c[1;33m", 27);
	gotoxy(40, 12);
	printf("============질투의 화신[RANK]============");
	gotoxy(40, 14);
	printf("[1st] Score : %2d\t| Name : %s\n\n", ranker.score[0], ranker.name[0]);	 
	printf("%c[1;37m", 27);
	gotoxy(40, 17);
	printf("[2nd] Score : %2d\t| Name : %s\n", ranker.score[1], ranker.name[1]); 
	gotoxy(40, 19);
	printf("[3rd] Score : %2d\t| Name : %s\n", ranker.score[2], ranker.name[2]);
	
	int num;
	printf("%c[1;37m", 27);
	gotoxy(30, 23);
	printf("메뉴로 돌아가시려면 1, 랭킹메뉴로 돌아가시려면 2를 입력해주세요.");
	gotoxy(45, 26);
	scanf("%d", &num);
	
	switch(num)
	{
		case 1:
			system("clear");
			menu();
			break;
		
		case 2:
			system("clear");
			rank();
			break;
		
		default:
			system("clear");
			menu();
			break;
	}
} 

void drama3rank() { //상속자들 랭킹  
	
	gameline();
	gamemaker();
	gameanswer();
	
	int i, j, k;
	char rankname[20];
	struct information ranker={0,};
	
	for(i = 0; i < i3; i++)	{
		
		ranker.score[i] = idrama3.score[i];	
		strncpy(ranker.name[i], idrama3.name[i], 20);
	}
	
	for(i = 0; i < i3-1; i++)
	{
		for(j = i+1; j < i3; j++)
		{
			if(ranker.score[i] < ranker.score[j])
			{
				k = ranker.score[j];
				ranker.score[j] = ranker.score[i];
				ranker.score[i] = k;
				
				strncpy(rankname, ranker.name[j], 20);
				strncpy(ranker.name[j], ranker.name[i], 20);
				strncpy(ranker.name[i], rankname, 20);	
			}	
		}	
	}
	
	printf("%c[1;33m", 27);
	gotoxy(40, 12);
	printf("=============상속자들[RANK]=============");
	gotoxy(40, 14);
	printf("[1st] Score : %2d\t| Name : %s\n\n", ranker.score[0], ranker.name[0]);
	printf("%c[1;37m", 27);
	gotoxy(40, 17);
	printf("[2nd] Score : %2d\t| Name : %s\n", ranker.score[1], ranker.name[1]); 
	gotoxy(40, 19);
	printf("[3rd] Score : %2d\t| Name : %s\n", ranker.score[2], ranker.name[2]);
	
	int num;
	printf("%c[1;37m", 27);
	gotoxy(30, 23);
	printf("메뉴로 돌아가시려면 1, 랭킹메뉴로 돌아가시려면 2를 입력해주세요.");
	gotoxy(45, 26);
	scanf("%d", &num);
	
	switch(num)
	{
		case 1:
			system("clear");
			menu();
			break;
		
		case 2:
			system("clear");
			rank();
			break;
		
		default:
			system("clear");
			menu();
			break;
	}
} 

void movierank() { //명대사 랭킹  
	
	gameline();
	gamemaker();
	gameanswer();
	
	int i, j, k;
	char rankname[20];
	struct information ranker={0,};
	
	for(i = 0; i < m1; i++)	{
		
		ranker.score[i] = movie1.score[i];
		strncpy(ranker.name[i], movie1.name[i], 20);
	}
	
	for(i = 0; i < m1-1; i++)
	{
		for(j = i+1; j < m1; j++)
		{
			if(ranker.score[i] < ranker.score[j])
			{
				k = ranker.score[j];
				ranker.score[j] = ranker.score[i];
				ranker.score[i] = k;
				
				strncpy(rankname, ranker.name[j], 20);
				strncpy(ranker.name[j], ranker.name[i], 20);
				strncpy(ranker.name[i], rankname, 20);	
			}	
		}	
	}
	
	printf("%c[1;33m", 27);
	gotoxy(40, 12);
	printf("============명대사퀴즈[RANK]============");
	gotoxy(40, 14);
	printf("[1st] Score : %2d\t| Name : %s\n\n", ranker.score[0], ranker.name[0]);
	printf("%c[1;37m", 27);
	gotoxy(40, 17);
	printf("[2nd] Score : %2d\t| Name : %s\n", ranker.score[1], ranker.name[1]); 
	gotoxy(40, 19);
	printf("[3rd] Score : %2d\t| Name : %s\n", ranker.score[2], ranker.name[2]);
	
	int num;
	printf("%c[1;37m", 27);
	gotoxy(30, 23);
	printf("메뉴로 돌아가시려면 1, 랭킹메뉴로 돌아가시려면 2를 입력해주세요.");
	gotoxy(45, 26);
	scanf("%d", &num);
	
	switch(num)
	{
		case 1:
			system("clear");
			menu();
			break;
		
		case 2:
			system("clear");
			rank();
			break;
		
		default:
			system("clear");
			menu();
			break;
	}
}
