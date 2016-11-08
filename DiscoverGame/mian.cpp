#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <malloc.h>

typedef struct list
{
	int select[3] = {0,0,0};
	struct list* next;
	struct list* before;

}Discover;
Discover *i_head;
Discover *i_tail;
Discover *e_head;
Discover *e_tail;
Discover *i_NowIs;
Discover *e_NowIs;
Discover *i_temp;
Discover *e_temp;

int i_armor=30;
int e_armor=30;



void initLinkedList()
{
	i_head = (Discover*)malloc(sizeof(Discover));
	i_tail = (Discover*)malloc(sizeof(Discover));
	i_head->next = i_tail;
	i_head->before = NULL;
	i_tail->next = NULL;
	i_tail->before = i_head;
	e_head = (Discover*)malloc(sizeof(Discover));
	e_tail = (Discover*)malloc(sizeof(Discover));
	e_head->next = e_tail;
	e_head->before = NULL;
	e_tail->next = NULL;
	e_tail->before = e_head;
}

void i_InsertDiscover()
{
	Discover *p = (Discover*)malloc(sizeof(Discover));
	Discover *s = i_head;
	for (int i = 0; i < 3; i++)
	{
		p->select[i] = rand() % 6;
	}
	while (s->next != i_tail)
	{
		s = s->next;
	}

	p->next = i_tail;
	p->before = s;
	s->next = p;


	
}
void e_InsertDiscover() 
{
	Discover *k = (Discover*)malloc(sizeof(Discover));
	Discover *t = e_head;
	for (int asd = 0; asd < 3; asd++)
	{
		k->select[asd] = rand() % 6;
	}
	while (t->next != e_tail)
	{
		t = t->next;
	}
	k->next = e_tail;
	k->before = t;
	t->next = k;
}
Discover * i_TurnSelect(Discover *now) 
{
	int chosu;
	Discover* p=now->next;
	printf("\np1의 턴");
	printf("선택:");
	scanf("%d", &chosu);
	if (p->select[chosu] == 0)
	{
		printf("\n!! 방어도 4 감소 !!\n");
		i_armor = i_armor - 4;
		getch();
	}
	else if (p->select[chosu] == 1)
	{
		printf("\n!! 방어도 6 감소 !!\n");
		i_armor = i_armor - 6;
		getch();
	}
	else if (p->select[chosu] == 2)
	{
		printf("\n!! 방어도 9 감소 !!\n");
		i_armor = i_armor - 9;
		getch();
	}
	else if (p->select[chosu] == 3)
	{
		printf("\n!! 방어도 3 증가 !!\n");
		i_armor = i_armor + 3;
		getch();
	}
	else if (p->select[chosu] == 4)
	{
		printf("\n!! 방어도 5 증가 !!\n");
		i_armor = i_armor + 5;
		getch();
	}
	else if (p->select[chosu] == 5)
	{
		printf("\n!! 아무런 효과 없음! !!\n");
		getch();
	}
	
	
	system("cls");
	return p;
}		//
//아군 선택
Discover * e_TurnSelect(Discover *now)
{
	int chosu;
	printf("\np2의 턴 ");
	Discover* p = now->next;
	printf("선택(0~2):");
	scanf("%d", &chosu);
	if (p->select[chosu] == 0)
	{
		printf("\n!! 방어도 4 감소 !!\n");
		e_armor = e_armor - 4;
		getch();
	}
	else if (p->select[chosu] == 1)
	{
		printf("\n!! 방어도 6 감소 !!\n");
		e_armor = e_armor - 6;
		getch();
	}
	else if (p->select[chosu] == 2)
	{
		printf("\n!! 방어도 9 감소 !!\n");
		e_armor = e_armor - 9;
		getch();
	}
	else if (p->select[chosu] == 3)
	{
		printf("\n!! 방어도 3 증가 !!\n");
		e_armor = e_armor + 3;
		getch();
	}
	else if (p->select[chosu] == 4)
	{
		printf("\n!! 방어도 5 증가 !!\n");
		e_armor = e_armor + 5;
		getch();
	}
	else if (p->select[chosu] == 5)
	{
		printf("\n!! 아무런 효과 없음! !!\n");
		getch();
	}


	system("cls");
	return p;
}
//상대 선택

int main()
{
	initLinkedList();
	char checkStart;
	i_NowIs = i_head;
	e_NowIs = e_head;
	for (int i = 0; i < 300; i++)
	{


		i_InsertDiscover();
		e_InsertDiscover();
	}
	srand((unsigned int)time(NULL));

	printf("게임 시작(Y:실행 N:종료):");
	scanf("%c", &checkStart);
	system("cls");
	if (checkStart == 'Y' || checkStart == 'y');
	else if (checkStart == 'N'|| checkStart=='n')
	{
		exit(0);
	}
	else
	{
		exit(0);
	}
	for (int turn = 0;1; turn++)
	{
		printf("│1p의 방어도 %d│\n",i_armor);
		printf("│2p의 방어도 %d│\n",e_armor);
		if (turn % 2 == 0) 
		{
			i_temp = i_NowIs;
			i_NowIs=i_TurnSelect(i_temp);
		}
		else 
		{
			e_temp = e_NowIs;
			e_NowIs = e_TurnSelect(e_temp);
		}
		if (i_armor <= 0) {
			printf("2p의 승리!");
			break;
		}
		if (e_armor <= 0) {
			printf("1p의 승리!");
			break;
		}

	}



	return 0;
}