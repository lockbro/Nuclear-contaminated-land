#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define STAR "* * * * * * * * * * * �� Ϸ ˵ �� * * * * * * * * * * * * * *"
#define UP "* * * * * * * * * * * * * * * * * * * * * * * * *" 
void background_pause(char* background);
void background_print();
int dirty_water_use(); 
void pos(int x, int y);
void menu(char name[]);
int me_hurt(int f);
int clear_water();
void thing();
void state();
void fight();
int weapon();
void over();
int water();
int food_s();
void weapon_b();
char name[10];

void pos(int x, int y)//���ù��λ��
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}
 
typedef struct {//��������
	int hp;
	int st;
	int level;
}HSL;
HSL first = { 150 , 150 , 10 };

typedef struct{//װ������
	int dirty;
	float clear;
	float food;
}T_number;
T_number t_number = {1 , 1 , 0};

typedef struct {//����
	char w1[20];
	char w2[20];
	char w3[20];
	char w4[20];
	char w5[20];
}Weapon;
Weapon weapon_u;

void background_print()
{
	pos(15,1); puts(UP);
	pos(35,2);printf("��������"); 
	pos(15,3);puts(UP); 
	pos(15,5);
	printf("��������:\n");
	pos(15,6);
	gets(name);
	system("cls");
	pos(15,1); puts(UP);
	pos(35,2);printf("��������"); 
	pos(15,3);puts(UP); 
	pos(10,5);
	Sleep(2000); 
	char b1[100]={"3088�꣬����Ϊ�˸��Ե�����,��ͻ���ϣ����պ�ս������......"};
	background_pause(b1);
	pos(10,7);
	Sleep(2000); 
	char b2[50]={"3091��......"};
	background_pause(b2);        
	pos(10,9);
	Sleep(3000); 
	char b3[100]={"��Ϊ��ս��������Ӱ�죬�����ϼ������ж��ﶼ���������صı���"}; 
	background_pause(b3);
	char b4[100]={"����"};
	strcat(b4,name);
	pos(10,11);
	Sleep(2000);
	background_pause(b4);
	char b5[100]={"��Ϊ������Ϊ��������Ҵ���,�Լ��Ĵ������ʼ����ľ�"};
	strcat(name,b5);
	background_pause(b5);
	pos(10,13);
	Sleep(2000); 
	char b6[100]={"����TA�ӹ㲥������˵H���д��ͱ�������,����������ν�ı���������......"};
	background_pause(b6);
	pos(10,15);
	Sleep(2000); 
	system("cls"); 
	pos(30,11);
	char b7[50]={"��Ϸ������....."};
	background_pause(b7);
	Sleep(5000);  
}

void background_pause(char* n){
	int i;
	for(i = 0 ; n[i] != '\0' ; i++)
	{
		Sleep(100);
		printf("%c",n[i]);
		while ( n[i] == '\0')
		{
			break;
		}                 
	}	
} 

void rule(){
	pos(10,5);puts(STAR);
	pos(1,7);printf("1.����:��TM�̼�!"); 
	pos(1,8);printf("2.ս������:һ��������ȼ��Ĺ��ÿ���ȼ������ֹ������ĵȼ������Ĺ���ֵ��"); 
	pos(1,9);printf("����������������ĳ����ȣ���ҿ���ѡ���Ƿ���������ս�����򲻹�������~"); 
	pos(1,10);printf("3.װ������:�����������ˮ����ˮ��ʳ������װ��,���Ƕ����������������ֵ����ˮÿ"); 
	pos(1,11);printf("һƿ�ܲ���30������ֵ��ʳ��ÿ���ܲ���35~40������ֵ��������ˮ�Ƚ����⣬��������"); 
	pos(1,12);printf("�������ֵ����������5~20��"); 
	pos(1,13);printf("4.��������:����ҵȼ����ߵ�һ��ʱ�������µ��������乥��ֵҲ�����ߡ�"); 
	pos(1,14);printf("5.�������:��ҷֱ��еȼ�������ֵ������ֵ��"); 
	pos(1,15);printf("ע:����Ϸĳ��ʱ��û��Ӧ���벻Ҫ���ţ����Բ�ȡ���´�ʩ:"); 
	pos(3,16);printf("1.�����ȴ�������ԭ��");
	pos(3,17);printf("2.������Ϸ");
	pos(3,18);printf("3.��������");
	pos(3,20);system("pause");
}
void menu(char name[]){
	int select ;
	while (1) {
		system("cls");	
		pos(30,5);printf("1.ս��");
		pos(30,7);printf("2.���װ��")	;   
		pos(30,9);printf("3.�鿴����״̬");	   
		pos(30,11);printf("4.��Ϸ˵��(�ض�)");	    
		pos(30,13);printf("5.�˳���Ϸ");
		pos(30,15);scanf("%d",&select);
		system("cls");
		switch(select){
			case 1:{
				fight();//��· 
				break;
			}
			case 2:{
				thing();//װ�� 
				break;
			}
			case 3:{
				state();//�������� 
				break;
			}
			case 4:{
				rule();
				break;
			}	
			case 5:{	
				exit(0);//�˳���Ϸ 
			}
			defalt:{
				printf("fuck");
			} 
		}
	} 
	return;
}  

void state(){
	pos(30,7);printf("����ֵ: %d\n",first.hp);	
	pos(30,9);printf("����ֵ: %d\n",first.st);
	pos(30,11);printf("�ȼ�: %d\n",first.level);
	pos(30,13);system("pause");
	return ;
}

int weapon(){
	system("cls"); 
	if(first.level<=20)
	{
		pos(30,11);printf("����: ذ��\n");
	}	
	if(first.level>20 && first.level<=60)
	{
		pos(30,11);printf("����: ��ʿ��\n");
	}
	if(first.level>60 && first.level<=85)
	{
		pos(30,11);printf("����: ������ǹ\n");
	}
	if(first.level>85 && first.level<=90)
	{
		pos(30,11);printf("����: ͻ����ǹ\n");
	}
	if(first.level>90 && first.level<=100)
	{
		pos(30,11);printf("����: ����\n");
	}
	pos(30,13);system("pause");
	return -2;
}

void weapon_b()
{
	system("cls");	
	if(first.level>20 && first.level<=60){
		pos(30,11);printf("������������: ��ʿ��\n");
	}
	if(first.level>60 && first.level<=85){
		pos(30,11);printf("������������: ������ǹ\n");
	}
	if(first.level>85 && first.level<=90){
		pos(30,11);printf("������������: ͻ����ǹ\n");
	}
	if(first.level>90 && first.level<=100){
		pos(30,11);printf("������������: ����\n");
	}
	pos(30,13);system("pause");	
}

void thing(){
	int select; 
	do {
		system("cls");	
		pos(30,9);printf("1.������\n");
		pos(30,11);printf("2.ʳ����\n");
		pos(30,13);printf("3.ˮ\n");
		pos(30,15);printf("4.�������˵�\n");
		pos(30,17);scanf("%d",&select);
		switch(select){
			case 1:{
			 	select = weapon();
				break;
			} 
			case 2:{
				select = food_s(); 
				break;
			} 
			case 3:{
				select = water();
				break;
			}
			case 4:{
				return;
				break;
			}
			default:{
				break;
			} 
		}
	} while (select < 0 || select > 4);
	return;
}

int food_s(){
	int  s , t , w , r = 0;
	do{
		system("cls");
		srand((unsigned)time(NULL));
		pos(10,9);printf("ʳ�� : ÿһ�ݿ��Լ�35~40������ֵ���������������߼�����ս����ʹ��");
		pos(10,10);printf("����ʳ�����: %d",t_number.food);
		pos(10,11);printf("��ѡ���Ƿ���һ��ʳ�"); 
		pos(10,12);printf("1.��һ�ݣ�  2.����ݾͺ�   3.�һ�����Ҫ");
		pos(10,13);scanf("%d",&w);
		switch(w){
			case 1:
			{
				if(t_number.food<=0){
					pos(15,14);printf("������˼��������һ��ʳ�ﶼû��");
					pos(15,16);system("pause");
				} 
				else if (t_number.food>=1) {
					t = rand () % 10 + 35;
					s = rand () % 10 + 35;
					if(first.hp >= 150)
					{
						first.hp = 150 ;
						pos(15,16);printf("��Ѫ״̬��");
						pos(15,18);system("pause");
					}
					else if(first.st>=150){
						first.st = 150;
						pos(15,16);printf("�������棡");
						pos(15,18);system("pause");
					}
					else if(first.hp < 150 && first.hp >0 && first.st < 150&& first.st >0 ) 
					{
						first.st += s;
						first.hp += t;
						pos(15,16);printf("��~���ָ�һ����~(��������)��");
						pos(15,18);system("pause");	
						t_number.food -= 1;
					}
				}
				pos(15,15);printf("������......");
				Sleep(1500);
				system("cls");
				state();
				return -2;
				break;
			}
			case 2: 
			{
				if(t_number.food<0.5){
					pos(15,14);printf("������˼�������������ʳ�ﶼû��");
					system("pause");
					return -2;
					break;
				} 
				else if (t_number.food>=0.5){	
					t = rand () % 16 + 17;
					s = rand () % 16 + 17;
					if(first.hp >= 150)
					{
						first.hp = 150 ;
						pos(15,14);printf("��Ѫ״̬��");
						system("pause");
					}
					else if(first.st>=150){
						first.st = 150; 
						pos(15,14);printf("�������棡");
						system("pause");
					}
					else if(first.hp < 300 && first.hp >0 && first.st < 350 && first.st >0 ) 
					{
						first.st += s;
						first.hp += t;
						pos(15,14);printf("��~���ָ�һ����~(��������)��");
						pos(15,16);system("pause");	
						t_number.food -= 0.5;
					}
					return -2;
					break;
				}
			} 
			case 3:{
				system("cls");
				state();
				return -2;	
				break;
			}
			default :{
				return -1; 
				break; 
			} 
		}
	}while (w < 0 || w > 3);
	return;
} 
 
int dirty_water(){
	int m , t , w , r = 0;
	do {
		system("cls");
		pos(5,9);printf("��ˮ:���ֵ�Ƶ�ʱȽϸߣ����Ǵ��ڷ��գ�������涾��ϸ����������ʹ�������ֵ�½�");
		pos(5,10);printf("���Ƕ���ϸ���ٵĵĻ������ѡ��ȵ���������һ���Ѫ�ģ��Ͼ�����;ĩ·���");
		pos(5,12);printf ("�������� %d ƿ��ˮ��",t_number.dirty);
		pos(5,12);printf("��ѡ���Ƿ���һƿ��ˮ?");
		pos(5,13);printf("1.��һ�ѣ���һƿ��     2.��˵��˵......"); 
		pos(5,14);scanf("%d",& w);
		if( w == 1 ){
			if (t_number.dirty <= 0){
				pos(5,15);printf("��ѽ,��һƿ��ˮҲû�С�");
				Sleep(2000);
				state();
				return -2;
			}
			else{
				srand((unsigned)time(NULL));
				t = rand () % 20 + 5; 
				m = rand() % 10;//ȡ1-10�����
				if(m == 1||m == 2||m == 3||m == 4||m == 5||m == 6){//ִ�м�Ѫ�ĸ��ʾ���0.7,��ϸ� 
					first.hp -= t;
					first.st -= t;
					t_number.dirty -= 1;
					pos(5,16);printf("�浹ù����ˮ�ж�(�Σ৥)��");//��Ѫ 
				} 
				else{
					first.hp += t;
					t_number.dirty -= 1;
					pos(5,16);printf("��~���ָ�һ����~\(�R���Q)/~");//��Ѫ 
				}
				if(first.hp >= 150){
					first.hp = 150;
					pos(5,16);printf("��Ѫ״̬��") ;
				}
				else if(first.hp <= 0 ){
					first.hp = 0 ;
					pos(5,16);printf("�±�����Ҳ��������"); 
					over();
				}
				pos(5,17);	printf("������......");
				Sleep(2000);
				system("cls");
				state();
				return -2;
			} 	
		}
		else if(w == 2){ 
			return -2;
		} 	
	}while( w < 0 || w > 2);
} 

int clear_water(){
	int up = 30;
	int w;
	do{
		system("cls");
		pos(30,9);printf("��ˮ:��Ϊ��������Ⱦ����ˮ���ֵĸ�����ԱȽϵͣ�����һЩ������ж�������ϵͳ���ܾ�����ˮ,\n");
		pos(30,10);printf("��������Ҫ������������ȡ�������ڵ�ˮ�ҡ���ˮ�Ļָ�Ч���쳣������һƿ�ܲ���30������ֵ\n");
		pos(30,11);printf("�������� %d ƿ��ˮ\n",t_number.clear); 
		pos(30,12);printf("��ѡ���Ƿ���һƿ��ˮ\n");
		pos(30,14);printf("1.��һƿ��   2.ֻ�ð�ƿ�ͺ�    3.�����Ű�");
		pos(30,15);scanf("%d",&w);
		if(w==1){
			if(t_number.clear <= 0)
			{
				pos(30,16);printf("����⣡��û�д�ˮ��\n");
				Sleep(2000);
				state();
				return -2;
			}
			else 
			{
				if (t_number.clear > 1){
					if(first.hp >= 150){
						first.hp = 150 ;
						pos(30,16);printf("��Ѫ״̬��");
					}
					else if (first.hp > 0 && first.hp < 150){
						pos(30,16);printf("�����ظ�һ����\(^o^)/~");//��Ѫ 
						t_number.clear -= 1;
					}
				}
				return -2; 
			} 
		}
		else if( w == 2){
			if (t_number.clear > 1){
				first.hp += 15;
			}
			if(first.hp >= 150){
				first.hp = 150 ;
				pos(30,16);printf("��Ѫ״̬��");
			}
			else if (first.hp > 0 && first.hp < 150){
				pos(30,16);printf("�����ظ�һ����\(^o^)/~");//��Ѫ 
			}
			t_number.clear -= 0.5; 
			return -2;
		}
		else if (w == 3){
			system("cls");
			state();
			return -2; 
		}
	}while(w < 0 || w > 3);
}

int water(){
	int w1=0;
	do {
		system("cls");
		pos(30,9);printf("1.��ˮ");
		pos(30,11);printf("2.��ˮ");  
		pos(30,13);printf("3.����"); 
		pos(30,15);scanf("%d",&w1);
		switch(w1)
		{
			case 1:{
				system("cls");
				w1 = dirty_water();
				break;
			}
			case 2:{
				system("cls");
				w1 = clear_water();
				break;
			} 
			case 3:{
				system("cls");
				return -2; 
				break;
			}
			default :{
				break;
			}
		}
	}while (w1 < 0 || w1 > 3);
} 

int me_hurt(int f){
	srand((unsigned)time(NULL));
	if(first.level<=20)//����˺�monster�� 
		f = rand () % 10 + 5 ;
	if(first.level>20 && first.level<=60)
		f = rand () % 20 + 15 ;
	if(first.level>60 && first.level<=85)
		f = rand () % 15 + 30 ;
	if(first.level>85 && first.level<=90)
		f = rand () % 30 + 45 ;
	if(first.level>90 && first.level<=100)
		f = rand () % 90 + 70 ;
	return f;
} 

void fight()
{
	int  s , t  , k , j , c , l;//s�ȼ��ж� t�ȼ���Χ k������ j����  l��ܹ�������ӵĵȼ� 
	int f , i , u , w1 ,w2;//f����˺� i�����˺� u����hp w1��ֱ�Ӵ����ķ� w��ս�ķ� 
	int m ;//�������  , ȡ����� �� 
	//int t_1,t_2,t_3;//�涫�� 
	char monster_1[100][100]={"�������","�����","������ѻ","����","ʳغ��"}; 
	char monster_2[100][100]={"����Ȯ","ʬ��","����з","���γ�","�ް�����"};
	char monster_3[100][100]={"�������","׷����","��ɱ��","��Ƥ��","������"}; 
	char monster_4[100][100]={"��ʳ��","ʳ����","ʳ����","��Ĺ��","����"}; 
	char monster_5[100][100]={"��©��","������","�溣��","������","����צ"};   
	srand((unsigned)time(NULL));
	t = rand () % 100;//����ȼ���ΧΪ120��
	k = rand () % 5;//������ 0~5
	if(t <= 40){
		u = 15;
		pos(20,10);printf("��������%s,�Ƿ�Ҫ�����\n",monster_1[k]); 	
		pos(20,11);printf("1.�����   2.����(��)\n");
		pos(20,12);scanf("%d",&s);
		system("cls"); 
		if(s == 1){	
			while(1){
				f = me_hurt(f);
				pos(20,13);printf("ս����......");
				Sleep(2000);
				pos(20,14);printf("���%s�����%d���˺�\n",monster_1[k],f);
				u -= f;
				Sleep(1000);
				if(u<=0){
					system("cls");
					pos(20,15);printf("������~~~����������ˣ�\n");
					Sleep(2500); 
					w1 = rand () % 5 + 15 ; 
					first.st -= w1;
					l = rand () % 2 + 2; 
					first.level += l;
					pos(20,16);printf("������%d��\n",l); 
					Sleep(1200);
					weapon_b();
					m = rand () % 5;
					pos(20,17);printf("�ѹ���......");
					system("cls");
					Sleep(1000);
					t_number.dirty += 3; 
					pos(20,18);printf("��ӹ���ˮ�����ռ�����ƿ��ˮ\n"); 
					Sleep(2000);
					return;
				}	 
				Sleep(1000);
				pos(20,15);printf("������û������,��Ҫ�����ˣ�\n");
				Sleep(2000);
				pos(20,16);printf("ս����......");
				i = rand () % 15 + 10; 
				first.hp -= i;//�������ֵ
				first.st -= i;//�������ֵ 
				Sleep(2000); 
				pos(20,17);printf("%s���������%d���˺�,�㻹��%d������ֵ��%d������ֵ.\n",monster_1[k],i,first.hp,first.st);
				Sleep(1000);
				if(first.hp<=0){
					pos(20,18);printf("��,���Ȼ��һֻ%sɱ��ûѪ......",monster_1[k]);
					over();
				}
				if(first.st<=0){
					pos(20,18);printf("��,���Ȼ��һֻ%s�ɵ�û������......",monster_1[k]);
					over();
				}
				pos(20,19);printf("1.��������    2.����\n");
				pos(20,20);scanf("%d",&s);
				system("cls");
				if(s == 2){
					return ;
				}
			}
		}
	}
	else if(t > 40 && t <= 60){
		u = 35;
		pos(20,10);printf("��������%s,�Ƿ�Ҫ�����\n",monster_2[k]); 	
		pos(20,11);printf("1.�����   2.����(��)\n");
		pos(20,12);scanf("%d",&s);
		system("cls"); 
		if(s == 1){	
			while(1){
				f = me_hurt(f);
				pos(20,13);printf("ս����......");
				Sleep(2000);
				pos(20,14);printf("���%s�����%d���˺�\n",monster_2[k],f);
				u -= f;
				Sleep(1000);
				if(u<=0){
					system("cls");
					pos(20,15);printf("������~~~����������ˣ�\n"); 
					Sleep(2500);
					w1 = rand () % 10 + 20 ; 
					first.st -= w1;
					l = rand () % 2 + 4; 
					first.level += l;
					pos(20,16);printf("������%d��\n",l);
					Sleep(1300);
					weapon_b(); 
					m = rand () % 6 ;
					pos(20,17);printf("�ѹ���......");
					Sleep(1000);
					system("cls");
					if (m == 0 || m == 1 || m== 2 ){
						t_number.dirty += 2; 
						pos(20,15);printf("��ӹ���ˮ�����ռ�����ƿ��ˮ\n"); 
					}
					m = rand () % 6; 
					if (m==3||m==4){
						t_number.food += 0.5;
						pos(20,16);printf("ร����ռ����˰��ʳ��\n"); 
					}
					m = rand () % 6;
					if(m==5){
						t_number.clear += 0.5;
						pos(20,18);printf("�ۣ���ӹ���ˮ�����ռ�����ƿ��ˮ\n"); 
					}
					return;
				}	 
				Sleep(1000);
				pos(20,15);printf("������û������,��Ҫ�����ˣ�\n");
				Sleep(2000);
				pos(20,16);printf("ս����......");
				i = rand () % 20 + 25 ; 
				first.hp -= i;//�������ֵ
				first.st -= i;//�������ֵ 
				Sleep(2000); 
				pos(20,17);printf("%s���������%d���˺�,�㻹��%d������ֵ��%d������ֵ.\n",monster_2[k],i,first.hp,first.st);
				Sleep(1000);
				if(first.hp<=0){
					pos(20,18);printf("��,���Ȼ��һֻ%sɱ��ûѪ......",monster_2[k]);
					over();
				}
				if(first.st<=0){
					pos(20,18);printf("��,���Ȼ��һֻ%s�ɵ�û������......",monster_2[k]);
					over();
				}
				pos(20,19);printf("1.��������    2.����\n");
				pos(20,20);scanf("%d",&s);
				system("cls");
				if(s == 2){
					return ;
				}
			}
		}	
	}
	else if(t > 60 && t <= 75){
		u = 50;
		pos(20,10);printf("��������%s,�Ƿ�Ҫ�����\n",monster_3[k]); 	
		pos(20,11);printf("1.�����   2.����(��)\n");
		pos(20,12);scanf("%d",&s);
		system("cls"); 
		if(s == 1){	
			while(1){
				f = me_hurt(f);
				pos(20,13);printf("ս����......");
				Sleep(2000);
				pos(20,14);printf("���%s�����%d���˺�\n",monster_3[k],f);
				u -= f;
				Sleep(1000);
				if(u<=0){
					system("cls");
					pos(20,15);printf("������~~~����������ˣ�\n"); 
					Sleep(2500);
					w1 = rand () % 15 + 30 ; 
					first.st -= w1;
					l = rand () % 4 + 6; 
					first.level += l;
					pos(20,16);printf("������%d��\n",l); 
					Sleep(1200);
					weapon_b();
					m = rand () % 10;
					pos(20,17);printf("�ѹ���......");
					Sleep(1000);
					system("cls");
					if (m == 0 || m == 1 || m== 2 || m== 3 || m == 4){
						t_number.dirty += 2; 
						pos(20,15);printf("��ӹ���ˮ�����ռ�����ƿ��ˮ\n"); 
					}
					m = rand () % 10; 
					if (m==5||m==6||m==7){
						t_number.food += 1;
						pos(20,16);printf("ร����ռ�����һ��ʳ��\n"); 
					}
					m = rand () % 10;
					if(m==8||m==9){
						t_number.clear += 1;
						pos(20,17);printf("�ۣ���ӹ���ˮ�����ռ���һƿ��ˮ\n"); 
					}
					return;
				}	 
				Sleep(3000);
				pos(20,15);printf("������û������,��Ҫ�����ˣ�\n");
				Sleep(1000);
				pos(20,16);printf("ս����......");
				i = rand () % 20 + 35 ; 
				first.hp -= i;//�������ֵ
				first.st -= i;//�������ֵ 
				Sleep(2000); 
				pos(20,17);printf("%s���������%d���˺�,�㻹��%d������ֵ��%d������ֵ.\n",monster_3[k],i,first.hp,first.st);
				Sleep(1000);
				if(first.hp<=0){
					pos(20,18);printf("��,���Ȼ��һֻ%sɱ��ûѪ......",monster_3[k]);
					over();
				}
				if(first.st<=0){
					pos(20,18);printf("��,���Ȼ��һֻ%s�ɵ�û������......",monster_3[k]);
					over();
				}
				pos(20,19);printf("1.��������    2.����\n");
				pos(20,20);scanf("%d",&s);
				system("cls");
				if(s == 2){
					return ;
				}
			}
		}
	}
	else if(t > 75 && t <= 90){
		u = 75;
		pos(20,10);printf("��������%s,�Ƿ�Ҫ�����\n",monster_4[k]); 	
		pos(20,11);printf("1.�����   2.����(��)\n");
		pos(20,12);scanf("%d",&s);
		system("cls"); 
		if(s == 1){	
			while(1){
				f = me_hurt(f);
				pos(20,13);printf("ս����......");
				Sleep(2000);
				pos(20,14);printf("���%s�����%d���˺�\n",monster_4[k],f);
				u -= f;
				Sleep(1000);
				if(u<=0){
					system("cls");
					pos(20,15);printf("������~~~����������ˣ�\n");
					Sleep(2500); 
					w1 = rand () % 5 + 45 ; 
					first.st -= w1;
					l = rand () % 18 + 10; 
					first.level += l;
					pos(20,16);printf("������%d��\n",l);
					Sleep(1200);
					weapon_b(); 
					m = rand () % 15;
					pos(20,17);printf("�ѹ���......");
					Sleep(1000);
					system("cls");
					if (m == 0 || m == 1 || m== 2 || m== 3 || m == 4||m == 5||m == 6|| m == 7 ||m == 8){
						t_number.dirty += 3; 
						pos(20,15);printf("��ӹ���ˮ�����ռ�����ƿ��ˮ\n"); 
					} 
					m = rand () % 15;
					if (m==9||m==10||m==11||m==12){
						t_number.food += 2;
						pos(20,16);printf("ร����ռ���������ʳ��\n"); 
					}
					m = rand () % 15;
					if (m==13||m==14){
						t_number.clear += 2;
						pos(20,17);printf("�ۣ���ӹ���ˮ�����ռ�����ƿ��ˮ\n"); 
					}
					return;
				}	 
				Sleep(1000);
				pos(20,15);printf("������û������,��Ҫ�����ˣ�\n");
				Sleep(1000);
				pos(20,16);printf("ս����......");
				i = rand () % 25 + 40 ; 
				first.hp -= i;//�������ֵ
				first.st -= i;//�������ֵ 
				Sleep(2000); 
				pos(20,17);printf("%s���������%d���˺�,�㻹��%d������ֵ��%d������ֵ.\n",monster_4[k],i,first.hp,first.st);
				Sleep(1000);
				if(first.hp<=0){
					pos(20,10);printf("��,���Ȼ��һֻ%sɱ��ûѪ......",monster_4[k]);
					over();
				}
				if(first.st<=0){
					pos(20,10);printf("��,���Ȼ��һֻ%s�ɵ�û������......",monster_4[k]);
					over();
				}
				pos(20,18);printf("1.��������    2.����\n");
				pos(20,19);scanf("%d",&s);
				system("cls");
				if(s == 2){
					return ;
				}
			} 
		}
		else{
			return; 
		}
	}
	else if(t > 90 && t <= 100){
		u = 90;
		pos(20,10);printf("��������%s,�Ƿ�Ҫ�����\n",monster_5[k]); 	
		pos(20,11);printf("1.�����   2.����(��)\n");
		pos(20,12);scanf("%d",&s);
		system("cls"); 
		if(s == 1){	
			while(1){
				f = me_hurt(f);
				pos(20,13);printf("ս����......");
				Sleep(2500);
				pos(20,14);printf("���%s�����%d���˺�\n",monster_5[k],f);
				u -= f;
				Sleep(1000);
				if(u<=0){
					system("cls");
					pos(20,15);printf("������~~~����������ˣ�\n");
					Sleep(2000); 
					w1 = rand () % 35 + 50 ; 
					first.st -= w1;
					l = rand () % 12 + 18; 
					first.level += l;
					pos(20,16);printf("������%d��",l); 
					Sleep(1200);
					weapon_b();
					m = rand () % 20;
					pos(20,17);printf("�ѹ���......");
					system("cls");
					Sleep(1000);
					if (m == 0 || m == 1 || m== 2 || m== 3 || m == 4||m == 5||m == 6|| m == 7 ||m == 8 ||m == 9||m == 10 ){
						t_number.dirty += 5; 
						pos(20,18);printf("��ӹ���ˮ�����ռ�����ƿ��ˮ"); 
					} 
					else if (m==11||m==12||m==13||m==14){
						t_number.food += 0.5;
						pos(20,19);printf("ร����ռ����˰��ʳ��"); 
					}
					else if (m==15||m==16||m==17){
						t_number.food += 1;
						pos(20,20);printf("ร����ռ�����һ��ʳ��"); 
					}
					else {
						t_number.clear += 3;
						pos(20,21);printf("�ۣ���ӹ���ˮ�����ռ�����ƿ��ˮ"); 
					}
					return;
				}	 
				Sleep(2000);
				pos(20,15);printf("������û������,��Ҫ�����ˣ�\n");
				Sleep(3500);
				pos(20,16);printf("ս����......");
				i = rand () % 40 + 45 ; 
				first.hp -= i;//�������ֵ
				first.st -= i;//�������ֵ 
				Sleep(2000);
				pos(20,17);printf("%s���������%d���˺�,�㻹��%d������ֵ��%d������ֵ.\n",monster_5[k],i,first.hp,first.st);
				Sleep(1000);
				if(first.hp<=0){
					pos(20,18);printf("��,���Ȼ��һֻ%sɱ��ûѪ......",monster_5[k]);
					over();
				}
				if(first.st<=0){
					pos(20,18);printf("��,���Ȼ��һֻ%s�ɵ�û������......",monster_5[k]);
					over();
				}
				pos(20,19);printf("1.��������    2.����\n");
				pos(20,20);scanf("%d",&s);
				system("cls");
				if(s == 2){
					return ;
				}
			} 
		}
		else{
			return; 
		}
	}
} 
	
void over()
{
	int i, j;
	for (j = 0; j < 60; j++)
	{
		for (i = 5; i < 25; i += 2)
		{
			pos(i + j, 5);
			printf("��");
			pos(i + j, 10);
			printf("��");
		}
		for (i = 5; i < 10; i++)
		{
			pos(5 + j, i);
			printf("��");
			pos(25 + j, i);
			printf("��");
		}
		pos(8 + j, 7);
		printf("�ӹ�'������'�ƻ�");
		for (i = 5; i < 25; i += 2)
		{
			pos(i + 50 - j, 12);
			printf("��");
			pos(i + 50 - j, 17);
			printf("��");
		}
		for (i = 12; i < 17; i++)
		{
			pos(5 + 50 - j, i);
			printf("��");
			pos(25 + 50 - j, i);
			printf("��");
		}
		pos(11 + 50 - j, 14);
		printf("��ϲ�㣡");
		while (j == 50)
			j = 0;
		pos(28, 20);
		printf("��Ʒ��:�Ű��İ�_Фչ��");
		Sleep(100);
		system("cls");
	}
}

int main(void)
{
	char name[20];		
	background_print();
	menu(name);
	fight();
	over();
	return 0;
}


