#include <stdio.h>
#include <windows.h>
#include <string.h>
#define MAX_USER 20

//���� ������  
int p1= 0;
int i1= 0;
int i2= 0;
int i3= 0;
int m1= 0; 

//����ü  
struct information {   
	char name[MAX_USER][20];
	int score[20];
};

//����ü ����  
struct information people_game; //�ι�����  
struct information idrama1;     //������  
struct information idrama2;     //������ ȭ��  
struct information idrama3;     //����ڵ� 
struct information movie1;      //�������� 
 
//�Լ��� 
void gameline();          //������  
void gamemaker();         //����������  
void gameanswer();        //��������  
void menu();              //�޴�  
void people_quiz();       //�ι����� 
int people_quiz_menu();   //�ι����� �޴�  
void usage();             //�ι����� ����  
void peopleline();        //�ι����� ����
void peoplegame();        //�ι����� ����  
int dramaselect();        //��� ����  
void dramamenu();         //��� �޴�
void drama1line();        //��� ���� 
void drama1();            //������  
void drama2line();        //������ ȭ�� ����  
void drama2();            //������ ȭ��
void drama3line();        //����ڵ� ����
void drama3();            //����ڵ�
int moviequiz_select();   //�������� ���� 
void moviequiz_menu();    //�������� �޴�  
void moviequiz();         //�������� 
void rank();              //��ŷ �޴�  
int rankselect();         //��ŷ ����  
void dramarankmenu();     //��󸶷�ŷ�޴�  
int dramarankselect();    //��󸶷�ŷ ����
void personrank();        //�ι����� ��ŷ    
void drama1rank();        //������ ��ŷ  
void drama2rank();        //������ȭ�� ��ŷ
void drama3rank();        //����ڵ� ��ŷ
void movierank();         //���� ��ŷ  
 
 
int main(void) {
	
	system("tiTle Quiz Game");
	system("mode con cols=120 lines=40"); //�ܼ�â ũ�� ���� 
	
	menu();
	
	return 0;
}

void textcolor(int color_number) { //�۾� ���� ����  
	
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);

}

void gotoxy(int x, int y) { //��ǥ ����  
	
	COORD pos={x,y};

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}

void gameline() {  
	
	gotoxy(20, 5);
	textcolor(14);
	int line;
	
	for ( line =0; line <40; line++ ) 
		printf("��");
		
	gotoxy(20, 35);
	for ( line =0; line <40; line++)
	    printf("��");
	    
	for ( line = 6; line < 35; line++) {
		gotoxy(20, line);
		printf("��");
		gotoxy(98, line);
		printf("��");
	}	
}

void gameanswer() { //���� ����  
	
	int line;
	textcolor(14);
	gotoxy(40, 25);
	for ( line =0; line < 40; line++)
	    printf("-");
	gotoxy(40, 27);
	for ( line =0; line < 40; line++)
	    printf("-");
	
	textcolor(7);
	gotoxy(42, 26);
	printf("��  ");
}

void gamemaker() {
	textcolor(14);
	gotoxy(55, 7);
	printf("QUIZ GAME");
	gotoxy(69, 9);
	printf("2�й� 3���� �� ������, Ȳ��ȫ");
	gotoxy(22, 10);
	printf("----------------------------------------------------------------------------");
}

void menu() { //�޴�  
	
	gameline();
	gameanswer();
	gamemaker();
	textcolor(11);
	gotoxy(50, 14);
	printf("1. �ι� ����");
	gotoxy(50, 16);
	printf("2. ��� ����");
	gotoxy(50, 18);
	printf("3. ���� ����");
	gotoxy(50, 20);
	printf("4. ��ŷ");
	
	textcolor(7);
	gotoxy(43, 23);
	printf("���� ���� ��ȣ�� �Է��� �ּ���."); 
	
	int num;
	gotoxy(45, 26);
	scanf("%d", &num);
	
	switch (num) {
		case 1:
			system("cls");
			people_quiz();
			break;
			
		case 2:
			system("cls");
			dramamenu();
			break;
		
		case 3:
			system("cls");
		    moviequiz_menu();
			break;
		
		case 4:
			system("cls");
			rank();
			break;
			
		default:
			system("cls");
			menu();
			break;
	}
	
}

void people_quiz() //�ι�����  
{
	while(1)
	{
		switch(people_quiz_menu())
		{
			case 1:
				system("cls");
				usage();
				break;
		
			case 2:
				system("cls");
				peoplegame();
				break;
			
			case 3:
				system("cls");
				menu();
				break;
			
			default:
				system("cls");
				Sleep(3000);
				break;
		}
	}
}

int people_quiz_menu() //�ι����� �޴�  
{	
	peopleline();

	gotoxy(50, 14);
	textcolor(11);
	printf("1. ���� �̿� ���");
	gotoxy(50, 16);
	printf("2. ���� ����");
	gotoxy(50, 18);
	printf("3. �޴��� ���ư���");
			
	gotoxy(43, 23);
	textcolor(7);
	printf("���� ���� ��ȣ�� �Է��� �ּ���.");
	int num;
	gotoxy(45, 26);
	scanf("%d", &num);
	
	return num;
}

void usage() //�ι����� ����  
{
	int num;
	peopleline();
	gotoxy(40, 14);
	textcolor(11);
	printf("�־����� ���� Ȥ�� ���� �̸��� ������");
	gotoxy(43, 16); 
	printf("�ι��� �̸��� ���ߴ� �����Դϴ�.");
	textcolor(7);
	gotoxy(38, 23);
	printf("�ڷΰ��⸦ ���Ͻø� [Enter]�� �Է��� �ּ���.\n");
	gotoxy(45, 26);
	fflush(stdin);
	getchar();
}

void peopleline() { //�ι����� ����  
	
	system("cls");
	gameline();
	gamemaker();
	gameanswer();
	
	gotoxy(55, 8);
	textcolor(11); 
	printf("�ι� ����");
}

void peoplegame() //�ι����� ����  
{
	char checkname[20], ans[10];
	int j = 0;
	
	peopleline();
	textcolor(7);
	gotoxy(45, 15);
	printf("�̸��� 'ȫ�浿'ó�� �����ּ���.");
	
	gotoxy(45, 26);
	scanf("%s", checkname);
	fflush(stdin); //�Է� ���� ����  
	
	while ( !(strcmp(checkname, people_game.name[j]) == 0) ) { //�����ϴ� �̸� Ȯ��  
		
		if (j == p1) {
			
			p1++;
			break;
    	}
		else j++;
    }
    
	strncpy(people_game.name[j], checkname, 20);
	
	int score=0;
	
	// 1
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("����ǥ\t��ź");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);
	
	if(strcmp(ans, "�̹�ȣ") == 0)
		score++;
	
	// 2
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);	
	printf("���꽽\t1����");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);
	
	if(strcmp(ans, "���缮") == 0)
		score++;
	
	// 3
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);	
	printf("������\t������");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);
	
	if(strcmp(ans, "������") == 0)
		score++;
		
	// 4
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("���̼�\t����");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);
	
	if(strcmp(ans, "��ٹ�") == 0)
		score++;
	
	// 5
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);	
	printf("�Ҵ�\t�ռ��̼ų�");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);
	
	if(strcmp(ans, "�����") == 0)
		score++;
		
	// 6
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("�Ź�Ŵ\t��ȣ��");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);
	
	if(strcmp(ans, "�赿��") == 0)
		score++;
		
	// 7
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("������\t���⽺");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);
	
	if(strcmp(ans, "�ڸ��") == 0)
		score++;
		
	// 8
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("���۳�\t���� ����");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);
	
	if(strcmp(ans, "�̺���") == 0)
		score++;
	
	// 9
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("��׷�\t�㹮��");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);
	
	if(strcmp(ans, "�ӽÿ�") == 0)
		score++;
	
	// 10
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("������\t������");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);

	if(strcmp(ans, "����") == 0)
		score++;
	
	//11	
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("����Ź\tȫ��");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);

	if(strcmp(ans, "�����") == 0)
		score++; 
	
	//12
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("Ȳ�ø�\t������");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);

	if(strcmp(ans, "���¿�") == 0)
		score++; 
	
	//13
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("����\t������ ������");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);

	if(strcmp(ans, "���") == 0)
		score++;
	
	//14
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("��õ��\t��������");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);

	if(strcmp(ans, "������") == 0)
		score++; 
	
	//15
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("�����ִϾ�\t�ż�����");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);

	if(strcmp(ans, "������") == 0)
		score++;
	
	//16
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("���̿���\t�ñ׳�");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);

	if(strcmp(ans, "������") == 0)
		score++;
	
	//17
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("3�ܰ���\t���Ѱ�����");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);

	if(strcmp(ans, "������") == 0)
		score++; 
	
	//18
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("�����\tû�����");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);

	if(strcmp(ans, "���ϴ�") == 0)
		score++; 
	
	//19
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("�ؿ���\t��â");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);

	if(strcmp(ans, "������") == 0)
		score++; 
	
	//20
	system("cls");
	peopleline();
	textcolor(7); 
	gotoxy(50, 15);
	printf("������Ȱ\t�ǻ��Ȱ");
	gotoxy(45, 26);
	scanf("%s", ans);
	fflush(stdin);

	if(strcmp(ans, "����ȣ") == 0)
		score++;
		
	system("cls");
	peopleline(); 
	textcolor(7); 
	gotoxy(45, 15);
	printf("%s ���� ����", people_game.name[j]);
	gotoxy(45, 17);
	
	printf("20���� �� �� %d ���� �������ϴ�.", score);
	
	gotoxy(45, 19);
	textcolor(11);
	if (score == 20) //������ ���� �۱Ͱ� �޶���  
	    printf("�ι����� ų��!");
	else if (score >15)
	    printf("�������� ���� �ƴ� ���");
	else if (score >10)
	    printf("�׷��� ������ ����� �ƴ� ���");
	else if (score >5)
	    printf("Ƽ�� ���� �� ����...?");
	else 
	    printf("�ƴ� ������ �ֱ� �־�?"); 
	    
	if (score > people_game.score[j])
	    people_game.score[j] = score;
	
	sleep(5);
	system("cls");
	menu();
}

int dramaselect() { //��� ����  
	
	gotoxy(38, 11);
	textcolor(7); 
	printf("��� ����� ������ ��󸶿� ���� ��� �����մϴ�.");
	gotoxy(50, 14);
	textcolor(11);
	printf("1. ������");
	gotoxy(50, 16);
	printf("2. ������ ȭ��");
	gotoxy(50, 18);
	printf("3. ����ڵ�");
	gotoxy(50, 20);
	printf("4. �޴��� ���ư���");
			
	gotoxy(43, 23);
	textcolor(7);
	printf("���� ���� ��ȣ�� �Է��� �ּ���.");
	int num;
	gotoxy(45, 26);
	scanf("%d", &num);
	
	return num; 
}

void dramamenu() { //��� �޴�  
	
	gameline();
	gamemaker();
	gameanswer();

	switch (dramaselect()) {
		case 1:
			system("cls");
			drama1();
			break;
			
		case 2:
			system("cls");
			drama2();
			break;
			
		case 3:
			system("cls");
			drama3();
			break;
			
		case 4:
			system("cls");
			menu();
			break; 
			
		default:
			system("cls");
			menu(); 
			break;
	}
}

void drama1line() { //��� ����  
	
	gameline();
	gamemaker();
	gameanswer();
	
	gotoxy(56, 8);
	textcolor(11); 
	printf("������");
}

void drama1() { //������  
	
	drama1line();
	
	char checkname[20];
	int j =0;
	
	textcolor(7);
	gotoxy(45, 15);
	printf("�̸��� 'ȫ�浿'ó�� �����ּ���.");
	
	gotoxy(45, 26);
	scanf("%s", checkname);
	fflush(stdin); //�Է� ���� ����  
	
	while ( !(strcmp(checkname, idrama1.name[j]) == 0) ) { //�����ϴ� �̸� Ȯ��  
		
		if ( j == i1) {
			
			i1++;
			break;
    	}
		else j++;
    }
    
	strncpy( idrama1.name[j], checkname, 20 );
	int score = 0;
	
	//1 
	system("cls");
	drama1line();
	char charanswer[15];
	int intanswer; 
	textcolor(7); 
	gotoxy(52, 15);
	printf("�������� �̸���?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "���") == 0)
	    score++;
	
	//2  
	system("cls");
	drama1line();
	textcolor(7); 
	gotoxy(50, 15);
	printf("�������� ���̴� �� ��?");
	gotoxy(45, 26);
	scanf("%d", &intanswer);
	fflush(stdin);
	
	if (intanswer == 939)
	    score++;
	
	//3
	system("cls");
	drama1line();
	textcolor(7); 
	gotoxy(48, 15);
	printf("������ �ź��� �̸���?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "����Ź") == 0)
	    score++;
	
	//4
	system("cls");
	drama1line();
	textcolor(7); 
	gotoxy(43, 15);
	printf("������ �������� ������ ���� ������?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "Į") == 0)
	    score++;
	
	//5 
	system("cls");
	drama1line();
	textcolor(7); 
	gotoxy(33, 15);
	printf("������� ���»��ڸ� ���� ������ ��ٰ� ��������? 'OOOO O'");
	gotoxy(45, 26);
	scanf("%[^\t\n]s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "�󽺷��� ��") == 0)
	    score++;
	
	//6
	system("cls");
	drama1line();
	textcolor(7); 
	gotoxy(39, 15);
	printf("���� ������ ��ô� ������ ��� 3�� �̸���?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "����ȭ") == 0)
	    score++;
	
	//7
    system("cls");
	drama1line();
	textcolor(7); 
	gotoxy(42, 15);
	printf("������ ��п� ���� ������ �ٲ������?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "����") == 0)
	    score++;
	
	//8   
	system("cls");
	drama1line();
	textcolor(7); 
	gotoxy(35, 15);
	printf("����Ź�� 9�� �� ���»��ڿ��Լ� ������ �����? 'OOOO'");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "����Ҹ�") == 0)
	    score++;
	
	//9    
	system("cls");
	drama1line();
	textcolor(7); 
	gotoxy(35, 15);
	printf("����Ź�� 9�� ���� �� �� �� ���»��ڸ� �ٽ� ��������?");
	gotoxy(45, 26);
	scanf("%d", &intanswer);
	fflush(stdin);
	
	if (intanswer == 19)
	    score++;
	
	//10
	system("cls");
	drama1line();
	textcolor(7); 
	gotoxy(45, 15);
	printf("���»���(����) ������ ������?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "�տ�") == 0)
	    score++;
	
	system("cls");
	drama1line();
	textcolor(7); 
	gotoxy(45, 15);
	printf("%s ���� ����", idrama1.name[j]);
	gotoxy(45, 17);
	printf("10���� �� �� %d ���� �������ϴ�.", score);
	
	gotoxy(45, 19);
	textcolor(11);
	if (score == 10) 
	    printf("������ �� �� ���� �ƴ� �� ������?");
	else if (score >5)
	    printf("������ ���� �ôµ� ����� ���� �ʴ°���?");
	else 
	    printf("������ ���� �þ�...?"); 
	    
	if (score > idrama1.score[j])
	    idrama1.score[j] = score;
	
	Sleep(5000);
	system("cls");
	menu();
}

void drama2line() { //������ ȭ�� ����  
	
	gameline();
	gamemaker();
	gameanswer();
	
	gotoxy(54, 8);
	textcolor(11); 
	printf("������ ȭ��");
}

void drama2() { //������ ȭ��
	
	drama2line();
	
	char checkname[20];
	int j =0;
	
	textcolor(7);
	gotoxy(45, 15);
	printf("�̸��� 'ȫ�浿'ó�� �����ּ���.");
	
	gotoxy(45, 26);
	scanf("%s", checkname);
	fflush(stdin); //�Է� ���� ����  
	
	while ( !(strcmp(checkname, idrama2.name[j]) == 0) ) { //�����ϴ� �̸� Ȯ��  
		
		if ( j == i2) {
			
			i2++;
			break;
    	}
		else j++;
    }
    
	strncpy( idrama2.name[j], checkname, 20 );
	int score = 0;
	
	//1
	system("cls");
	drama2line();
	char charanswer[15];
	int intanswer; 
	textcolor(7); 
	gotoxy(45, 15);
	printf("�������� ���� �����ΰ� �̸���?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "��ȭ��") == 0)
	    score++;
	
	//2    
	system("cls");
	drama2line();
	textcolor(7); 
	gotoxy(42, 15);
	printf("��ȭ���� ¦����ϴ� �����ΰ� �̸���?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "ǥ����") == 0)
	    score++;
	
	//3
	system("cls");
	drama2line();
	textcolor(7); 
	gotoxy(51, 15);
	printf("ǥ������ ������?");
	gotoxy(54, 17);
	printf("- OOOOO -");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "���ĳ����") == 0)
	    score++;
	
	//4    
	system("cls");
	drama2line();
	textcolor(7); 
	gotoxy(39, 15);
	printf("��ȭ�Ű� ǥ������ �ܱ� ��� �ٽ� ��������?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "�±�") == 0)
	    score++;
	
	//5
	system("cls");
	drama2line();
	textcolor(7); 
	gotoxy(47, 15);
	printf("��ȭ���� ���� ���� �ɷ�����?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "�����") == 0)
	    score++;
	    
	//6
	system("cls");
	drama2line();
	textcolor(7); 
	gotoxy(41, 15);
	printf("��ȭ�Ű� ǥ������ �ٴϴ� ��۱� �̸���?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "sbc") == 0)
	    score++;
	
	//7    
	system("cls");
	drama2line();
	textcolor(7); 
	gotoxy(47, 15);
	printf("�̻����� ������ �� ���ϱ�?");
	gotoxy(45, 26);
	scanf("%d", &intanswer);
	fflush(stdin);
	
	if (intanswer == 2)
	    score++;
	
	//8
	system("cls");
	drama2line();
	textcolor(7); 
	gotoxy(39, 15);
	printf("ǥ������ �ΰ� ��ȭ�Ű� �����ϴ� ��� �̸���?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "������") == 0)
	    score++;
	
	//9    
	system("cls");
	drama2line();
	textcolor(7); 
	gotoxy(46, 15);
	printf("ǥ������ �ǰ� �;��� ������?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "�Ƴ��") == 0)
	    score++;
	
	//10    
	system("cls");
	drama2line();
	textcolor(7); 
	gotoxy(39, 15);
	printf("��ȭ���� ǥ�������� ��� �� ���� ���ڰ� ������?");
	gotoxy(45, 26);
	scanf("%d", &intanswer);
	fflush(stdin);
	
	if (intanswer == 1000)
	    score++;
	    
	system("cls");
	drama2line();
	textcolor(7); 
	gotoxy(45, 15);
	printf("%s ���� ����", idrama2.name[j]);
	gotoxy(45, 17);
	printf("10���� �� �� %d ���� �������ϴ�.", score);
	
	gotoxy(45, 19);
	textcolor(11);
	if (score == 10) 
	    printf("������ ȭ�� �� �� ���� �ƴ� �� ������?");
	else if (score >5)
	    printf("������ ȭ�� ���� �ôµ� ����� ���� �ʴ°���?");
	else 
	    printf("������ ȭ�� ���� �þ�...?"); 
	    
	if (score > idrama2.score[j])
	    idrama2.score[j] = score;
	    
	Sleep(5000);
	system("cls");
	menu();
}

void drama3line() { //����ڵ� ����  
	
	gameline();
	gamemaker();
	gameanswer();
	
	gotoxy(56, 8);
	textcolor(11); 
	printf("����ڵ�");
}

void drama3() { //����ڵ�  
	
	drama3line();
	
	char checkname[20];
	int j =0;
	
	textcolor(7);
	gotoxy(45, 15);
	printf("�̸��� 'ȫ�浿'ó�� �����ּ���.");
	
	gotoxy(45, 26);
	scanf("%s", checkname);
	fflush(stdin); //�Է� ���� ����  
	
	while ( !(strcmp(checkname, idrama3.name[j]) == 0) ) { //�����ϴ� �̸� Ȯ��  
		
		if ( j == i3) {
			
			i3++;
			break;
    	}
		else j++;
    }
    
	strncpy( idrama3.name[j], checkname, 20 );
	int score = 0;
	
	//1
	system("cls");
	drama3line();
	char charanswer[15];
	int intanswer; 
	textcolor(7); 
	gotoxy(46, 15);
	printf("��ź�� �������� ���� �����?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "�̱�") == 0)
	    score++;
	
	//2    
	system("cls");
	drama3line();
	textcolor(7); 
	gotoxy(34, 15);
	printf("�������� ������ �ִ� ���� ������ �������� �ǽɹ޾�����?");
	gotoxy(55, 17);
	printf("- OOOO -");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "�̼�����") == 0)
	    score++;
	
	//3    
	system("cls");
	drama3line();
	textcolor(7); 
	gotoxy(47, 15);
	printf("��ź�� ���� ���� �׷��ϱ�?");
	gotoxy(55, 17);
	printf("- OOOO -");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "�����׷�") == 0)
	    score++;
	
	//4    
	system("cls");
	drama3line();
	textcolor(7); 
	gotoxy(49, 15);
	printf("�̺����� ����ģ �̸���?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "��ź") == 0)
	    score++;
	
	//5    
	system("cls");
	drama3line();
	textcolor(7); 
	gotoxy(39, 15);
	printf("�ֿ����� �������� �ҷ����� ������ �Ծ�����?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "¥���") == 0)
	    score++;
	
	//6    
	system("cls");
	drama3line();
	textcolor(7); 
	gotoxy(42, 15);
	printf("�ֿ����� �ƹ����� ���� ��� ������?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "����") == 0)
	    score++;
	
	//7
	system("cls");
	drama3line();
	textcolor(7); 
	gotoxy(42, 15);
	printf("��ź�� �߰���翡�� �� ���� �Ͽ�����?");
	gotoxy(45, 26);
	scanf("%d", &intanswer);
	fflush(stdin);
	
	if (intanswer == 100)
	    score++;
	
	//8
	system("cls");
	drama3line();
	textcolor(7); 
	gotoxy(40, 15);
	printf("��ȿ���� ���ɵ� �� ���� ���� Ƣ������?");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "����") == 0)
	    score++;
	
	//9    
	system("cls");
	drama3line();
	textcolor(7); 
	gotoxy(33, 15);
	printf("��ź�� ������ ���ױ淡 �ֿ����� ���̰� ����������? 'OO'");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "����") == 0)
	    score++;
	
	//10
	system("cls");
	drama3line();
	textcolor(7); 
	gotoxy(35, 15);
	printf("��ź�� ���ڿ��� �ݳ������� �������� ���������? 'OOO'");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "������") == 0)
	    score++;
	    
	system("cls");
	drama3line();
	textcolor(7); 
	gotoxy(45, 15);
	printf("%s ���� ����", idrama3.name[j]);
	gotoxy(45, 17);
	printf("10���� �� �� %d ���� �������ϴ�.", score);
	
	gotoxy(45, 19);
	textcolor(11);
	if (score == 10) 
	    printf("����ڵ� �� �� ���� �ƴ� �� ������?");
	else if (score >5)
	    printf("����ڵ� ���� �ôµ� ����� ���� �ʴ°���?");
	else 
	    printf("����ڵ� ���� �þ�...?"); 
	    
	if (score > idrama3.score[j])
	    idrama3.score[j] = score;
	    
	Sleep(5000);
	system("cls");
	menu();
}

int moviequiz_select() { //�������� ����  
	
	gameline();
	gamemaker();
	gameanswer();
	
	textcolor(7);
	gotoxy(28, 12);
	printf("���� ����� ��󸶳� ��ȭ ���縦 ���� ������ ���ߴ� �����Դϴ�");
	
	textcolor(11); 
	gotoxy(50, 15);
	printf("1. ���� ����");
	gotoxy(50, 17);
	printf("2. �޴��� ���ư���");
	
	gotoxy(43, 23);
	textcolor(7);
	printf("���� ���� ��ȣ�� �Է��� �ּ���.");
	int num;
	gotoxy(45, 26);
	scanf("%d", &num);
	
	return num; 
}

void moviequiz_menu() { //�������� �޴�  
	
	switch(moviequiz_select()) {
		
		case 1:
			system("cls");
			moviequiz();
			break;
		
		default:
			system("cls");
			menu();
			break;
	}
}

void moviequiz_line() {
	gameline();
	gamemaker();
	gameanswer();
	
	textcolor(11);
	gotoxy(54, 8);
	printf("���� ����");
}

void moviequiz() { //��������  
	
	moviequiz_line();
	
	char checkname[20];
	int j =0;
	
	textcolor(7);
	gotoxy(45, 15);
	printf("�̸��� 'ȫ�浿'ó�� �����ּ���.");
	
	gotoxy(45, 26);
	scanf("%s", checkname);
	fflush(stdin); //�Է� ���� ����  
	
	while ( !(strcmp(checkname, movie1.name[j]) == 0) ) { //�����ϴ� �̸� Ȯ��  
		
		if ( j == m1) {
			
			m1++;
			break;
    	}
		else j++;
    }
    
	strncpy( movie1.name[j], checkname, 20 );
	int score = 0;
	
	//1
	system("cls");
	moviequiz_line();
	char charanswer[15];
	int intanswer; 
	textcolor(7); 
	gotoxy(44, 15);
	printf("���� �� ����� �׷�. ���̰� ����?");
	gotoxy(56, 17);
	printf("- OOO -");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "���׶�") == 0)
	    score++;
	
	//2    
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(47, 15);
	printf("�̰��� �����ΰ�, ����ΰ�? ");
	gotoxy(55, 17);
	printf("- OOOO -");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "��������") == 0)
	    score++;
	
	//3
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(50, 15);
	printf("���� ���� �� ���ΰ�?");
	gotoxy(57, 17);
	printf("- OO -");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "����") == 0)
	    score++;
	
	//4
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(35, 15);
	printf("�ڱ� �λ��� ����ǥ ��������. �׳� ����ǥ�� ��! ����.");
	gotoxy(38, 17);
	printf("����ǥ�� ����ǥ �� �� ��� ������ �� ���ڰ�");
	gotoxy(40, 19);
	printf("�� �ɰŴ�, �� �ɰŴ�. �� �̹��� �� �ɰŴ�.");
	gotoxy(52, 21);
	printf("����ǥ. �˾Ҿ�?");
	gotoxy(54, 23);
	printf("- OOO OO -");
	
	gotoxy(45, 26);
	scanf("%[^\t\n]s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "������ ȭ��") == 0)
	    score++;
	
	//5    
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(40, 13);
	printf("�� ���� ����ؼ� ���ڰ� �Ǵ� ���� �ƴ϶�");
	gotoxy(43, 15);
	printf("������ ������ ��� ���ڰ� �Ǵ°ž�");
	gotoxy(45, 17);
	printf("���� �� ���� �������� �ϴ� ���ٽ�");
	gotoxy(44, 19);
	printf("���� ��������Ƿ� �ູ�ߴ�, ������");
	gotoxy(55, 21);
	printf("�װ� ������");
	gotoxy(54, 23);
	printf("- OOO OOOO -");
	
	gotoxy(45, 26);
	scanf("%[^\t\n]s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "������ ����̾�") == 0)
	    score++;
	    
	//6
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(50, 15);
	printf("���� �� �� ���Ҵ�...");
	gotoxy(56, 17);
	printf("- OOO -");
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "������") == 0)
	    score++;
	    
	//7
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(47, 13);
	printf("�ƹ��� ���� �� ������ �¾Ƶ�");
	gotoxy(45, 15);
	printf("������ �濡�� ������� �־���.");
	gotoxy(42, 17);
	printf("������ ���� �� ���� ���Ŷ� ����������");
	gotoxy(54, 19);
	printf("������ �׷���");
	gotoxy(51, 21);
	printf("������ ������ ������.");
	gotoxy(57, 23);
	printf("- OO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "�̻�") == 0)
	    score++;
	    
	//8
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(49, 15);
	printf("�дϴ�. ���� �� ������.");
	gotoxy(48, 17);
	printf("���ѹα� ��� �� 1�� 2��");
	gotoxy(30, 19);
	printf("���ѹα� �ֱ��� ���ο��� �ְ� ��� �Ƿ��� �������κ��� ���´�.");
	gotoxy(51, 21);
	printf("������ �����Դϴ�.");
	gotoxy(56, 23);
	printf("- OOO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "��ȣ��") == 0)
	    score++;
	
	//9    
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(51, 15);
	printf("���� ������ ��Ģ");
	gotoxy(30, 17);
	printf("��κ��� ����� �����ϴ� ���� �˸鼭�� �������� �ʴ´ٰ� �ϴ�.");
	gotoxy(33, 19);
	printf("�׷��鼭�� �������� �� ���������� �ϴ� �Ƹ��ٿ� ��ġ��.");
	gotoxy(53, 21);
	printf("- OOOO OOO -");
	
	gotoxy(45, 26);
	scanf("%[^\t\n]s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "�������� ����") == 0)
	    score++;
	    
	//10
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(36, 15);
	printf("�װ� ���� �Ϳ� �ٸ� ����� ���� ��ų �ʿ�� ����");
	gotoxy(54, 17);
	printf("- OOO OOO-");
	
	gotoxy(45, 26);
	scanf("%[^\t\n]s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "���¿� Ŭ��") == 0)
	    score++;
	    
	//11
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(29, 11);
	printf("�� � ���� ���ϴ��� ���� �ʴ� �濡 ���� �̷��� ���� �����̴�.");
	gotoxy(43, 13);
	printf("�׷��� ��ȸ���� �����̶� ���� ���̰�");
	gotoxy(46, 15);
	printf("�׷��� ���� �����̶� ���� ���̴�.");
	gotoxy(33, 17);
	printf("���� ������ ���� �����̶� �ϰ� �������� ������ �׸��̴�.");
	gotoxy(40, 19);
	printf("�� ���� ���õ��� ��ȸ���� �ϰ� ����ϴ� ��");
	gotoxy(51, 21);
	printf("�װ� ���� �����̴�.");
	gotoxy(54, 23);
	printf("- OOOO OOOO -");
	
	gotoxy(45, 26);
	scanf("%[^\t\n]s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "�����϶� 1994") == 0)
	    score++;
	    
	//12
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(41, 15);
	printf("Ű����°� ���̾�. (�߷�) ��. �� ��");
	gotoxy(55, 17);
	printf("- OOOOO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "�����а���") == 0)
	    score++;
	    
	//13
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(42, 15);
	printf("�ؾ�޶� �Ͽ�����. �ؾ��ֱ� �ٶ����.");
	gotoxy(37, 17);
	printf("�̾��ϱ���. ������ �Ͽ����� �ʸ� ���� ���Ͽ���.");
	gotoxy(54, 19);
	printf("- OO OO O -");
	
	gotoxy(45, 26);
	scanf("%[^\t\n]s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "�ظ� ǰ�� ��") == 0)
	    score++;
	    
	//14
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(46, 15);
	printf("���� ���Ƽ� ���� ���� �ʾƼ�");
	gotoxy(51, 17);
	printf("��� ���� �ູ�ߴ�.");
	gotoxy(57, 19);
	printf("- OOO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "������") == 0)
	    score++;
	    
	//15
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(50, 15);
	printf("�� ���� ������ �ƴ�?");
	gotoxy(56, 17);
	printf("- OOOO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "���˵���") == 0)
	    score++;
	    
	//16
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(43, 15);
	printf("ȣ�ǰ� ��ӵǸ� �װ� �Ǹ��� �� �˾ƿ�.");
	gotoxy(56, 17);
	printf("- OOOO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "�δ�ŷ�") == 0)
	    score++;
	    
	//17
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(40, 15);
	printf("�� �� ������ ��� �� �� ������ �����ݾ�?");
	gotoxy(49, 17);
	printf("�� �ױ� �� ���� ������");
	gotoxy(57, 19);
	printf("- OOO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);

	if (strcmp(charanswer, "�ż���") == 0)
	    score++;
	    
	//18
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(47, 15);
	printf("�Ƶ��, �ʴ� ��ȹ�� �� �ֱ���");
	gotoxy(57, 17);
	printf("- OOO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);

	if (strcmp(charanswer, "�����") == 0)
	    score++;
	    
	//19
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(52, 15);
	printf("���� ������ ������");
	gotoxy(58, 17);
	printf("- OO -");
	
	gotoxy(45, 26);
	scanf("%s", charanswer);
	fflush(stdin);

	if (strcmp(charanswer, "Ÿ¥") == 0)
	    score++;
	    
	//20
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(33, 13);
	printf("�ƹ��ϵ� ������ �ʰ�����, �����ϳ� ���� ���� �������");
	gotoxy(49, 15);
	printf("�װ� ��� ſ�� �ƴϿ�");
	gotoxy(34, 17);
	printf("�� �ƹ� ��ȸ�� ����, ����� �� �λ��� ����ó�� ���༭");
	gotoxy(53, 19);
	printf("������ ���̿�");
	gotoxy(54, 21);
	printf("- OOO OOO -");
	
	gotoxy(45, 26);
	scanf("%[^\t\n]s", charanswer);
	fflush(stdin);
	
	if (strcmp(charanswer, "����� �ҽ���") == 0)
	    score++;
	
	system("cls");
	moviequiz_line();
	textcolor(7); 
	gotoxy(45, 15);
	printf("%s ���� ����", movie1.name[j]);
	gotoxy(45, 17);
	printf("20���� �� �� %d ���� �������ϴ�.", score);
	
	gotoxy(45, 19);
	textcolor(11);
	if (score == 20) 
	    printf("�� �� ��󸶳� ��ȭ�� �ֱ� �Ѱ�?");
	else if (score >15)
	    printf("��󸶿� ��ȭ�� �ſ� ��ܺ��� ���");
	else if (score >10)
	    printf("������ ��󸶳� ��ȭ�� ���� �� ���");
	else if (score >5)
	    printf("������ ��󸶳� ��ȭ�� ���� �� ���");
	else if (score >0) 
	    printf("��󸶵� ��ȭ�� ���� �� ���� ���"); 
	else
	    printf("��󸶵� ��ȭ�� �� ���� �缼��...?");
	    
	if (score > movie1.score[j])
	    movie1.score[j] = score;
	
	sleep(5);
	system("cls");
	menu();
} 

void rank() { //��ŷ �޴�  
	
	gameline();
	gamemaker();
	gameanswer();
	
	switch (rankselect()) {
		case 1:
			system("cls");
			personrank(); 
			break;
			
		case 2:
			system("cls");
			dramarankmenu();
			break;
			
		case 3:
			system("cls");
			movierank();
			break;
			
		case 4:
			system("cls");
			menu();
			break; 
			
		default:
			system("cls");
			menu(); 
			break;
	}
}

int rankselect() { 
	
	textcolor(7);
	gotoxy(44, 11);
	printf("��ŷ�� ���� 3�������� �����ݴϴ�.");
	gotoxy(50, 14);
	textcolor(11);
	printf("1. �ι����� ��ŷ");
	gotoxy(50, 16);
	printf("2. ������� ��ŷ");
	gotoxy(50, 18);
	printf("3. �������� ��ŷ");
	gotoxy(50, 20);
	printf("4. �޴��� ���ư���");
			
	gotoxy(43, 23);
	textcolor(7);
	printf("���� ���� ��ȣ�� �Է��� �ּ���.");
	int num;
	gotoxy(45, 26);
	scanf("%d", &num);
	
	return num; 
}

void dramarankmenu() { //��󸶷�ŷ�޴�  
	
	gameline();
	gamemaker();
	gameanswer();
	
	switch (dramarankselect()) {
		case 1:
			system("cls");
			drama1rank();
			break;
			
		case 2:
			system("cls");
			drama2rank();
			break;
			
		case 3:
			system("cls");
			drama3rank();
			break;
			
		case 4:
			system("cls");
			menu();
			break; 
			
		default:
			system("cls");
			menu(); 
			break;
	}
} 

int dramarankselect() { //��󸶷�ŷ ����  
	
	textcolor(7);
	gotoxy(44, 11);
	printf("��ŷ�� ���� 3�������� �����ݴϴ�.");
	gotoxy(50, 14);
	textcolor(11);
	printf("1. ������ ��ŷ");
	gotoxy(50, 16);
	printf("2. ������ ȭ�� ��ŷ");
	gotoxy(50, 18);
	printf("3. ����ڵ� ��ŷ");
	gotoxy(50, 20);
	printf("4. �޴��� ���ư���");
			
	gotoxy(43, 23);
	textcolor(7);
	printf("���� ���� ��ȣ�� �Է��� �ּ���.");
	int num;
	gotoxy(45, 26);
	scanf("%d", &num);
	
	return num; 
} 

void personrank() { //�ι����� ��ŷ  
	
	gameline();
	gamemaker();
	gameanswer();
	
	int i, j, k;
	char rankname[20];
	struct information ranker={0,};	// rank ����ü  
	
	for(i = 0; i < p1; i++)	{
		
		ranker.score[i] = people_game.score[i];		// rank ������ ����� ����  
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
	
	textcolor(14);
	gotoxy(40, 12);
	printf("=============�ι�����[RANK]=============");
	gotoxy(40, 14);
	printf("[1st] Score : %2d\t| Name : %s", ranker.score[0], ranker.name[0]);	
	textcolor(7);
	gotoxy(40, 17);
	printf("[2nd] Score : %2d\t| Name : %s", ranker.score[1], ranker.name[1]); 
	gotoxy(40, 19);
	printf("[3rd] Score : %2d\t| Name : %s", ranker.score[2], ranker.name[2]);
	
	int num;
	textcolor(7);
	gotoxy(30, 23);
	printf("�޴��� ���ư��÷��� 1, ��ŷ�޴��� ���ư��÷��� 2�� �Է����ּ���.");
	gotoxy(45, 26);
	scanf("%d", &num);
	
	switch(num)
	{
		case 1:
			system("cls");
			menu();
			break;
		
		case 2:
			system("cls");
			rank();
			break;
		
		default:
			system("cls");
			menu();
			break;
	}
}

void drama1rank() { //������ ��ŷ  
	
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
	
	textcolor(14);
	gotoxy(40, 12);
	printf("==============������[RANK]==============");
	gotoxy(40, 14);
	printf("[1st] Score : %2d\t| Name : %s\n\n", ranker.score[0], ranker.name[0]);
	textcolor(7);
	gotoxy(40, 17);
	printf("[2nd] Score : %2d\t| Name : %s\n", ranker.score[1], ranker.name[1]); 
	gotoxy(40, 19);
	printf("[3rd] Score : %2d\t| Name : %s\n", ranker.score[2], ranker.name[2]);
	
	int num;
	textcolor(7);
	gotoxy(30, 23);
	printf("�޴��� ���ư��÷��� 1, ��ŷ�޴��� ���ư��÷��� 2�� �Է����ּ���.");
	gotoxy(45, 26);
	scanf("%d", &num);
	
	switch(num)
	{
		case 1:
			system("cls");
			menu();
			break;
		
		case 2:
			system("cls");
			rank();
			break;
		
		default:
			system("cls");
			menu();
			break;
	}
}

void drama2rank() { //������ȭ�� ��ŷ  
	
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
	
	textcolor(14);
	gotoxy(40, 12);
	printf("============������ ȭ��[RANK]============");
	gotoxy(40, 14);
	printf("[1st] Score : %2d\t| Name : %s\n\n", ranker.score[0], ranker.name[0]);	 
	textcolor(7);
	gotoxy(40, 17);
	printf("[2nd] Score : %2d\t| Name : %s\n", ranker.score[1], ranker.name[1]); 
	gotoxy(40, 19);
	printf("[3rd] Score : %2d\t| Name : %s\n", ranker.score[2], ranker.name[2]);
	
	int num;
	textcolor(7);
	gotoxy(30, 23);
	printf("�޴��� ���ư��÷��� 1, ��ŷ�޴��� ���ư��÷��� 2�� �Է����ּ���.");
	gotoxy(45, 26);
	scanf("%d", &num);
	
	switch(num)
	{
		case 1:
			system("cls");
			menu();
			break;
		
		case 2:
			system("cls");
			rank();
			break;
		
		default:
			system("cls");
			menu();
			break;
	}
} 

void drama3rank() { //����ڵ� ��ŷ  
	
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
	
	textcolor(14);
	gotoxy(40, 12);
	printf("=============����ڵ�[RANK]=============");
	gotoxy(40, 14);
	printf("[1st] Score : %2d\t| Name : %s\n\n", ranker.score[0], ranker.name[0]);
	textcolor(7);
	gotoxy(40, 17);
	printf("[2nd] Score : %2d\t| Name : %s\n", ranker.score[1], ranker.name[1]); 
	gotoxy(40, 19);
	printf("[3rd] Score : %2d\t| Name : %s\n", ranker.score[2], ranker.name[2]);
	
	int num;
	textcolor(7);
	gotoxy(30, 23);
	printf("�޴��� ���ư��÷��� 1, ��ŷ�޴��� ���ư��÷��� 2�� �Է����ּ���.");
	gotoxy(45, 26);
	scanf("%d", &num);
	
	switch(num)
	{
		case 1:
			system("cls");
			menu();
			break;
		
		case 2:
			system("cls");
			rank();
			break;
		
		default:
			system("cls");
			menu();
			break;
	}
} 

void movierank() { //���� ��ŷ  
	
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
	
	textcolor(14);
	gotoxy(40, 12);
	printf("============��������[RANK]============");
	gotoxy(40, 14);
	printf("[1st] Score : %2d\t| Name : %s\n\n", ranker.score[0], ranker.name[0]);
	textcolor(7);
	gotoxy(40, 17);
	printf("[2nd] Score : %2d\t| Name : %s\n", ranker.score[1], ranker.name[1]); 
	gotoxy(40, 19);
	printf("[3rd] Score : %2d\t| Name : %s\n", ranker.score[2], ranker.name[2]);
	
	int num;
	textcolor(7);
	gotoxy(30, 23);
	printf("�޴��� ���ư��÷��� 1, ��ŷ�޴��� ���ư��÷��� 2�� �Է����ּ���.");
	gotoxy(45, 26);
	scanf("%d", &num);
	
	switch(num)
	{
		case 1:
			system("cls");
			menu();
			break;
		
		case 2:
			system("cls");
			rank();
			break;
		
		default:
			system("cls");
			menu();
			break;
	}
}
