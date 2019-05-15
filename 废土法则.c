#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define STAR "* * * * * * * * * * * 游 戏 说 明 * * * * * * * * * * * * * *"
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

void pos(int x, int y)//设置光标位置
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}
 
typedef struct {//人物属性
	int hp;
	int st;
	int level;
}HSL;
HSL first = { 150 , 150 , 10 };

typedef struct{//装备数量
	int dirty;
	float clear;
	float food;
}T_number;
T_number t_number = {1 , 1 , 0};

typedef struct {//武器
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
	pos(35,2);printf("废土法则"); 
	pos(15,3);puts(UP); 
	pos(15,5);
	printf("输入姓名:\n");
	pos(15,6);
	gets(name);
	system("cls");
	pos(15,1); puts(UP);
	pos(35,2);printf("废土法则"); 
	pos(15,3);puts(UP); 
	pos(10,5);
	Sleep(2000); 
	char b1[100]={"3088年，各国为了各自的利益,冲突不断，最终核战争爆发......"};
	background_pause(b1);
	pos(10,7);
	Sleep(2000); 
	char b2[50]={"3091年......"};
	background_pause(b2);        
	pos(10,9);
	Sleep(3000); 
	char b3[100]={"因为核战争带来的影响，地球上几乎所有动物都发生了严重的变异"}; 
	background_pause(b3);
	char b4[100]={"主角"};
	strcat(b4,name);
	pos(10,11);
	Sleep(2000);
	background_pause(b4);
	char b5[100]={"作为地球上为数不多的幸存者,自己的储备物资即将耗尽"};
	strcat(name,b5);
	background_pause(b5);
	pos(10,13);
	Sleep(2000); 
	char b6[100]={"但是TA从广播里面听说H市有大型避难所后,决定向着所谓的避难所进发......"};
	background_pause(b6);
	pos(10,15);
	Sleep(2000); 
	system("cls"); 
	pos(30,11);
	char b7[50]={"游戏加载中....."};
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
	pos(1,7);printf("1.总述:真TM刺激!"); 
	pos(1,8);printf("2.战斗部分:一共有五个等级的怪物，每个等级有五种怪物，怪物的等级与怪物的攻击值、"); 
	pos(1,9);printf("玩家生命和体力消耗成正比，玩家可以选择是否与怪物进行战斗，打不过就跑嘛~"); 
	pos(1,10);printf("3.装备部分:玩家身上有脏水、纯水和食物三种装备,它们都可以提升你的生命值，纯水每"); 
	pos(1,11);printf("一瓶能补充30的生命值，食物每份能补充35~40的生命值。另外脏水比较特殊，它可以让"); 
	pos(1,12);printf("你的生命值和体力减少5~20。"); 
	pos(1,13);printf("4.武器部分:当玩家等级升高到一定时便会解锁新的武器，其攻击值也会升高。"); 
	pos(1,14);printf("5.玩家属性:玩家分别有等级、生命值和力气值。"); 
	pos(1,15);printf("注:当游戏某段时间没反应，请不要慌张，可以采取以下措施:"); 
	pos(3,16);printf("1.继续等待（网络原因）");
	pos(3,17);printf("2.重启游戏");
	pos(3,18);printf("3.重启电脑");
	pos(3,20);system("pause");
}
void menu(char name[]){
	int select ;
	while (1) {
		system("cls");	
		pos(30,5);printf("1.战斗");
		pos(30,7);printf("2.检查装备")	;   
		pos(30,9);printf("3.查看自身状态");	   
		pos(30,11);printf("4.游戏说明(必读)");	    
		pos(30,13);printf("5.退出游戏");
		pos(30,15);scanf("%d",&select);
		system("cls");
		switch(select){
			case 1:{
				fight();//上路 
				break;
			}
			case 2:{
				thing();//装备 
				break;
			}
			case 3:{
				state();//人物属性 
				break;
			}
			case 4:{
				rule();
				break;
			}	
			case 5:{	
				exit(0);//退出游戏 
			}
			defalt:{
				printf("fuck");
			} 
		}
	} 
	return;
}  

void state(){
	pos(30,7);printf("生命值: %d\n",first.hp);	
	pos(30,9);printf("体力值: %d\n",first.st);
	pos(30,11);printf("等级: %d\n",first.level);
	pos(30,13);system("pause");
	return ;
}

int weapon(){
	system("cls"); 
	if(first.level<=20)
	{
		pos(30,11);printf("武器: 匕首\n");
	}	
	if(first.level>20 && first.level<=60)
	{
		pos(30,11);printf("武器: 武士刀\n");
	}
	if(first.level>60 && first.level<=85)
	{
		pos(30,11);printf("武器: 左轮手枪\n");
	}
	if(first.level>85 && first.level<=90)
	{
		pos(30,11);printf("武器: 突击步枪\n");
	}
	if(first.level>90 && first.level<=100)
	{
		pos(30,11);printf("武器: 榴弹炮\n");
	}
	pos(30,13);system("pause");
	return -2;
}

void weapon_b()
{
	system("cls");	
	if(first.level>20 && first.level<=60){
		pos(30,11);printf("解锁了新武器: 武士刀\n");
	}
	if(first.level>60 && first.level<=85){
		pos(30,11);printf("解锁了新武器: 左轮手枪\n");
	}
	if(first.level>85 && first.level<=90){
		pos(30,11);printf("解锁了新武器: 突击步枪\n");
	}
	if(first.level>90 && first.level<=100){
		pos(30,11);printf("解锁了新武器: 榴弹炮\n");
	}
	pos(30,13);system("pause");	
}

void thing(){
	int select; 
	do {
		system("cls");	
		pos(30,9);printf("1.武器类\n");
		pos(30,11);printf("2.食物类\n");
		pos(30,13);printf("3.水\n");
		pos(30,15);printf("4.返回主菜单\n");
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
		pos(10,9);printf("食物 : 每一份可以加35~40的生命值和体力，最好在与高级怪物战斗后使用");
		pos(10,10);printf("现有食物份数: %d",t_number.food);
		pos(10,11);printf("请选择是否来一份食物？"); 
		pos(10,12);printf("1.来一份！  2.来半份就好   3.我还不需要");
		pos(10,13);scanf("%d",&w);
		switch(w){
			case 1:
			{
				if(t_number.food<=0){
					pos(15,14);printf("不好意思，你现在一份食物都没有");
					pos(15,16);system("pause");
				} 
				else if (t_number.food>=1) {
					t = rand () % 10 + 35;
					s = rand () % 10 + 35;
					if(first.hp >= 150)
					{
						first.hp = 150 ;
						pos(15,16);printf("满血状态！");
						pos(15,18);system("pause");
					}
					else if(first.st>=150){
						first.st = 150;
						pos(15,16);printf("体力充沛！");
						pos(15,18);system("pause");
					}
					else if(first.hp < 150 && first.hp >0 && first.st < 150&& first.st >0 ) 
					{
						first.st += s;
						first.hp += t;
						pos(15,16);printf("啊~，恢复一下啦~(～￣▽￣)～");
						pos(15,18);system("pause");	
						t_number.food -= 1;
					}
				}
				pos(15,15);printf("加载中......");
				Sleep(1500);
				system("cls");
				state();
				return -2;
				break;
			}
			case 2: 
			{
				if(t_number.food<0.5){
					pos(15,14);printf("不好意思，你现在连半份食物都没有");
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
						pos(15,14);printf("满血状态！");
						system("pause");
					}
					else if(first.st>=150){
						first.st = 150; 
						pos(15,14);printf("体力充沛！");
						system("pause");
					}
					else if(first.hp < 300 && first.hp >0 && first.st < 350 && first.st >0 ) 
					{
						first.st += s;
						first.hp += t;
						pos(15,14);printf("啊~，恢复一下啦~(～￣▽￣)～");
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
		pos(5,9);printf("脏水:出现的频率比较高，但是存在风险，如果里面毒素细菌过多或许会使你的生命值下降");
		pos(5,10);printf("但是毒素细菌少的的话你可以选择喝掉，还是能一点回血的，毕竟快穷途末路了嘛。");
		pos(5,12);printf ("你现在有 %d 瓶脏水。",t_number.dirty);
		pos(5,12);printf("请选择是否来一瓶脏水?");
		pos(5,13);printf("1.赌一把，来一瓶！     2.再说再说......"); 
		pos(5,14);scanf("%d",& w);
		if( w == 1 ){
			if (t_number.dirty <= 0){
				pos(5,15);printf("哎呀,你一瓶脏水也没有。");
				Sleep(2000);
				state();
				return -2;
			}
			else{
				srand((unsigned)time(NULL));
				t = rand () % 20 + 5; 
				m = rand() % 10;//取1-10随机数
				if(m == 1||m == 2||m == 3||m == 4||m == 5||m == 6){//执行减血的概率就是0.7,需较高 
					first.hp -= t;
					first.st -= t;
					t_number.dirty -= 1;
					pos(5,16);printf("真倒霉，这水有毒(ノ｀Д)ノ");//减血 
				} 
				else{
					first.hp += t;
					t_number.dirty -= 1;
					pos(5,16);printf("啊~，恢复一下啦~\(≧▽≦)/~");//加血 
				}
				if(first.hp >= 150){
					first.hp = 150;
					pos(5,16);printf("满血状态！") ;
				}
				else if(first.hp <= 0 ){
					first.hp = 0 ;
					pos(5,16);printf("下辈子再也不作死！"); 
					over();
				}
				pos(5,17);	printf("加载中......");
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
		pos(30,9);printf("纯水:因为环境的污染，纯水出现的概率相对比较低，但是一些怪物具有独特消化系统，能净化脏水,\n");
		pos(30,10);printf("所以你需要消灭完怪物后提取怪物体内的水囊。纯水的恢复效果异常显著，一瓶能补充30的生命值\n");
		pos(30,11);printf("你现在有 %d 瓶纯水\n",t_number.clear); 
		pos(30,12);printf("请选择是否来一瓶纯水\n");
		pos(30,14);printf("1.来一瓶！   2.只用半瓶就好    3.先留着吧");
		pos(30,15);scanf("%d",&w);
		if(w==1){
			if(t_number.clear <= 0)
			{
				pos(30,16);printf("真糟糕！你没有纯水。\n");
				Sleep(2000);
				state();
				return -2;
			}
			else 
			{
				if (t_number.clear > 1){
					if(first.hp >= 150){
						first.hp = 150 ;
						pos(30,16);printf("满血状态！");
					}
					else if (first.hp > 0 && first.hp < 150){
						pos(30,16);printf("啊，回复一下啦\(^o^)/~");//加血 
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
				pos(30,16);printf("满血状态！");
			}
			else if (first.hp > 0 && first.hp < 150){
				pos(30,16);printf("啊，回复一下啦\(^o^)/~");//加血 
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
		pos(30,9);printf("1.脏水");
		pos(30,11);printf("2.纯水");  
		pos(30,13);printf("3.返回"); 
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
	if(first.level<=20)//玩家伤害monster量 
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
	int  s , t  , k , j , c , l;//s等级判断 t等级范围 k怪物编号 j计数  l打败怪物后所加的等级 
	int f , i , u , w1 ,w2;//f玩家伤害 i怪物伤害 u怪物hp w1是直接打死耗费 w交战耗费 
	int m ;//奖励编号  , 取随机数 ； 
	//int t_1,t_2,t_3;//存东西 
	char monster_1[100][100]={"巨型蟑螂","黑足虫","变异乌鸦","瘟鸡","食睾鼠"}; 
	char monster_2[100][100]={"寄生犬","尸鬼","泥沼蟹","瘟形虫","晦暗妖怪"};
	char monster_3[100][100]={"芬里尔狼","追踪者","猎杀者","无皮者","消除者"}; 
	char monster_4[100][100]={"舔食者","食惧者","食脑者","掘墓者","暴君"}; 
	char monster_5[100][100]={"滴漏者","谵死怪","蹑海者","攫速者","死亡爪"};   
	srand((unsigned)time(NULL));
	t = rand () % 100;//怪物等级范围为120级
	k = rand () % 5;//怪物编号 0~5
	if(t <= 40){
		u = 15;
		pos(20,10);printf("你遇见了%s,是否要怼他？\n",monster_1[k]); 	
		pos(20,11);printf("1.怼他！   2.怼不过(逃)\n");
		pos(20,12);scanf("%d",&s);
		system("cls"); 
		if(s == 1){	
			while(1){
				f = me_hurt(f);
				pos(20,13);printf("战斗中......");
				Sleep(2000);
				pos(20,14);printf("你对%s造成了%d的伤害\n",monster_1[k],f);
				u -= f;
				Sleep(1000);
				if(u<=0){
					system("cls");
					pos(20,15);printf("哈哈哈~~~他被你怼死了！\n");
					Sleep(2500); 
					w1 = rand () % 5 + 15 ; 
					first.st -= w1;
					l = rand () % 2 + 2; 
					first.level += l;
					pos(20,16);printf("你升了%d级\n",l); 
					Sleep(1200);
					weapon_b();
					m = rand () % 5;
					pos(20,17);printf("搜刮中......");
					system("cls");
					Sleep(1000);
					t_number.dirty += 3; 
					pos(20,18);printf("你从怪物水囊里收集到三瓶脏水\n"); 
					Sleep(2000);
					return;
				}	 
				Sleep(1000);
				pos(20,15);printf("靠！它没被有死,它要反击了！\n");
				Sleep(2000);
				pos(20,16);printf("战斗中......");
				i = rand () % 15 + 10; 
				first.hp -= i;//玩家生命值
				first.st -= i;//玩家力气值 
				Sleep(2000); 
				pos(20,17);printf("%s对你造成了%d的伤害,你还有%d的生命值和%d的体力值.\n",monster_1[k],i,first.hp,first.st);
				Sleep(1000);
				if(first.hp<=0){
					pos(20,18);printf("唉,你居然被一只%s杀到没血......",monster_1[k]);
					over();
				}
				if(first.st<=0){
					pos(20,18);printf("唉,你居然被一只%s干到没有力气......",monster_1[k]);
					over();
				}
				pos(20,19);printf("1.灭了他！    2.逃跑\n");
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
		pos(20,10);printf("你遇见了%s,是否要怼他？\n",monster_2[k]); 	
		pos(20,11);printf("1.怼他！   2.怼不过(逃)\n");
		pos(20,12);scanf("%d",&s);
		system("cls"); 
		if(s == 1){	
			while(1){
				f = me_hurt(f);
				pos(20,13);printf("战斗中......");
				Sleep(2000);
				pos(20,14);printf("你对%s造成了%d的伤害\n",monster_2[k],f);
				u -= f;
				Sleep(1000);
				if(u<=0){
					system("cls");
					pos(20,15);printf("哈哈哈~~~他被你怼死了！\n"); 
					Sleep(2500);
					w1 = rand () % 10 + 20 ; 
					first.st -= w1;
					l = rand () % 2 + 4; 
					first.level += l;
					pos(20,16);printf("你升了%d级\n",l);
					Sleep(1300);
					weapon_b(); 
					m = rand () % 6 ;
					pos(20,17);printf("搜刮中......");
					Sleep(1000);
					system("cls");
					if (m == 0 || m == 1 || m== 2 ){
						t_number.dirty += 2; 
						pos(20,15);printf("你从怪物水囊里收集到两瓶脏水\n"); 
					}
					m = rand () % 6; 
					if (m==3||m==4){
						t_number.food += 0.5;
						pos(20,16);printf("喔，你收集到了半份食物\n"); 
					}
					m = rand () % 6;
					if(m==5){
						t_number.clear += 0.5;
						pos(20,18);printf("哇！你从怪物水囊里收集到半瓶纯水\n"); 
					}
					return;
				}	 
				Sleep(1000);
				pos(20,15);printf("靠！它没被有死,它要反击了！\n");
				Sleep(2000);
				pos(20,16);printf("战斗中......");
				i = rand () % 20 + 25 ; 
				first.hp -= i;//玩家生命值
				first.st -= i;//玩家力气值 
				Sleep(2000); 
				pos(20,17);printf("%s对你造成了%d的伤害,你还有%d的生命值和%d的体力值.\n",monster_2[k],i,first.hp,first.st);
				Sleep(1000);
				if(first.hp<=0){
					pos(20,18);printf("唉,你居然被一只%s杀到没血......",monster_2[k]);
					over();
				}
				if(first.st<=0){
					pos(20,18);printf("唉,你居然被一只%s干到没有力气......",monster_2[k]);
					over();
				}
				pos(20,19);printf("1.灭了他！    2.逃跑\n");
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
		pos(20,10);printf("你遇见了%s,是否要怼他？\n",monster_3[k]); 	
		pos(20,11);printf("1.怼他！   2.怼不过(逃)\n");
		pos(20,12);scanf("%d",&s);
		system("cls"); 
		if(s == 1){	
			while(1){
				f = me_hurt(f);
				pos(20,13);printf("战斗中......");
				Sleep(2000);
				pos(20,14);printf("你对%s造成了%d的伤害\n",monster_3[k],f);
				u -= f;
				Sleep(1000);
				if(u<=0){
					system("cls");
					pos(20,15);printf("哈哈哈~~~他被你怼死了！\n"); 
					Sleep(2500);
					w1 = rand () % 15 + 30 ; 
					first.st -= w1;
					l = rand () % 4 + 6; 
					first.level += l;
					pos(20,16);printf("你升了%d级\n",l); 
					Sleep(1200);
					weapon_b();
					m = rand () % 10;
					pos(20,17);printf("搜刮中......");
					Sleep(1000);
					system("cls");
					if (m == 0 || m == 1 || m== 2 || m== 3 || m == 4){
						t_number.dirty += 2; 
						pos(20,15);printf("你从怪物水囊里收集到两瓶脏水\n"); 
					}
					m = rand () % 10; 
					if (m==5||m==6||m==7){
						t_number.food += 1;
						pos(20,16);printf("喔，你收集到了一份食物\n"); 
					}
					m = rand () % 10;
					if(m==8||m==9){
						t_number.clear += 1;
						pos(20,17);printf("哇！你从怪物水囊里收集到一瓶纯水\n"); 
					}
					return;
				}	 
				Sleep(3000);
				pos(20,15);printf("靠！它没被有死,它要反击了！\n");
				Sleep(1000);
				pos(20,16);printf("战斗中......");
				i = rand () % 20 + 35 ; 
				first.hp -= i;//玩家生命值
				first.st -= i;//玩家力气值 
				Sleep(2000); 
				pos(20,17);printf("%s对你造成了%d的伤害,你还有%d的生命值和%d的体力值.\n",monster_3[k],i,first.hp,first.st);
				Sleep(1000);
				if(first.hp<=0){
					pos(20,18);printf("唉,你居然被一只%s杀到没血......",monster_3[k]);
					over();
				}
				if(first.st<=0){
					pos(20,18);printf("唉,你居然被一只%s干到没有力气......",monster_3[k]);
					over();
				}
				pos(20,19);printf("1.灭了他！    2.逃跑\n");
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
		pos(20,10);printf("你遇见了%s,是否要怼他？\n",monster_4[k]); 	
		pos(20,11);printf("1.怼他！   2.怼不过(逃)\n");
		pos(20,12);scanf("%d",&s);
		system("cls"); 
		if(s == 1){	
			while(1){
				f = me_hurt(f);
				pos(20,13);printf("战斗中......");
				Sleep(2000);
				pos(20,14);printf("你对%s造成了%d的伤害\n",monster_4[k],f);
				u -= f;
				Sleep(1000);
				if(u<=0){
					system("cls");
					pos(20,15);printf("哈哈哈~~~他被你怼死了！\n");
					Sleep(2500); 
					w1 = rand () % 5 + 45 ; 
					first.st -= w1;
					l = rand () % 18 + 10; 
					first.level += l;
					pos(20,16);printf("你升了%d级\n",l);
					Sleep(1200);
					weapon_b(); 
					m = rand () % 15;
					pos(20,17);printf("搜刮中......");
					Sleep(1000);
					system("cls");
					if (m == 0 || m == 1 || m== 2 || m== 3 || m == 4||m == 5||m == 6|| m == 7 ||m == 8){
						t_number.dirty += 3; 
						pos(20,15);printf("你从怪物水囊里收集到三瓶脏水\n"); 
					} 
					m = rand () % 15;
					if (m==9||m==10||m==11||m==12){
						t_number.food += 2;
						pos(20,16);printf("喔，你收集到了两份食物\n"); 
					}
					m = rand () % 15;
					if (m==13||m==14){
						t_number.clear += 2;
						pos(20,17);printf("哇！你从怪物水囊里收集到两瓶纯水\n"); 
					}
					return;
				}	 
				Sleep(1000);
				pos(20,15);printf("靠！它没被有死,它要反击了！\n");
				Sleep(1000);
				pos(20,16);printf("战斗中......");
				i = rand () % 25 + 40 ; 
				first.hp -= i;//玩家生命值
				first.st -= i;//玩家力气值 
				Sleep(2000); 
				pos(20,17);printf("%s对你造成了%d的伤害,你还有%d的生命值和%d的体力值.\n",monster_4[k],i,first.hp,first.st);
				Sleep(1000);
				if(first.hp<=0){
					pos(20,10);printf("唉,你居然被一只%s杀到没血......",monster_4[k]);
					over();
				}
				if(first.st<=0){
					pos(20,10);printf("唉,你居然被一只%s干到没有力气......",monster_4[k]);
					over();
				}
				pos(20,18);printf("1.灭了他！    2.逃跑\n");
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
		pos(20,10);printf("你遇见了%s,是否要怼他？\n",monster_5[k]); 	
		pos(20,11);printf("1.怼他！   2.怼不过(逃)\n");
		pos(20,12);scanf("%d",&s);
		system("cls"); 
		if(s == 1){	
			while(1){
				f = me_hurt(f);
				pos(20,13);printf("战斗中......");
				Sleep(2500);
				pos(20,14);printf("你对%s造成了%d的伤害\n",monster_5[k],f);
				u -= f;
				Sleep(1000);
				if(u<=0){
					system("cls");
					pos(20,15);printf("哈哈哈~~~他被你怼死了！\n");
					Sleep(2000); 
					w1 = rand () % 35 + 50 ; 
					first.st -= w1;
					l = rand () % 12 + 18; 
					first.level += l;
					pos(20,16);printf("你升了%d级",l); 
					Sleep(1200);
					weapon_b();
					m = rand () % 20;
					pos(20,17);printf("搜刮中......");
					system("cls");
					Sleep(1000);
					if (m == 0 || m == 1 || m== 2 || m== 3 || m == 4||m == 5||m == 6|| m == 7 ||m == 8 ||m == 9||m == 10 ){
						t_number.dirty += 5; 
						pos(20,18);printf("你从怪物水囊里收集到五瓶脏水"); 
					} 
					else if (m==11||m==12||m==13||m==14){
						t_number.food += 0.5;
						pos(20,19);printf("喔，你收集到了半份食物"); 
					}
					else if (m==15||m==16||m==17){
						t_number.food += 1;
						pos(20,20);printf("喔，你收集到了一份食物"); 
					}
					else {
						t_number.clear += 3;
						pos(20,21);printf("哇！你从怪物水囊里收集到三瓶纯水"); 
					}
					return;
				}	 
				Sleep(2000);
				pos(20,15);printf("靠！它没被有死,它要反击了！\n");
				Sleep(3500);
				pos(20,16);printf("战斗中......");
				i = rand () % 40 + 45 ; 
				first.hp -= i;//玩家生命值
				first.st -= i;//玩家力气值 
				Sleep(2000);
				pos(20,17);printf("%s对你造成了%d的伤害,你还有%d的生命值和%d的体力值.\n",monster_5[k],i,first.hp,first.st);
				Sleep(1000);
				if(first.hp<=0){
					pos(20,18);printf("唉,你居然被一只%s杀到没血......",monster_5[k]);
					over();
				}
				if(first.st<=0){
					pos(20,18);printf("唉,你居然被一只%s干到没有力气......",monster_5[k]);
					over();
				}
				pos(20,19);printf("1.灭了他！    2.逃跑\n");
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
			printf("★");
			pos(i + j, 10);
			printf("★");
		}
		for (i = 5; i < 10; i++)
		{
			pos(5 + j, i);
			printf("★");
			pos(25 + j, i);
			printf("★");
		}
		pos(8 + j, 7);
		printf("逃过'避难所'计划");
		for (i = 5; i < 25; i += 2)
		{
			pos(i + 50 - j, 12);
			printf("★");
			pos(i + 50 - j, 17);
			printf("★");
		}
		for (i = 12; i < 17; i++)
		{
			pos(5 + 50 - j, i);
			printf("★");
			pos(25 + 50 - j, i);
			printf("★");
		}
		pos(11 + 50 - j, 14);
		printf("恭喜你！");
		while (j == 50)
			j = 0;
		pos(28, 20);
		printf("出品人:信安四班_肖展鹏");
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


