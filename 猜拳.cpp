#include <bits/stdc++.h>
#include <conio.h> 
using namespace std;
int main(){
	srand(time(0));
	int pc = rand() % 3; //电脑 
	char ch1; //赛制键盘事件 
	char ch2; //出拳键盘事件 
	char ch3; //重开键盘事件 
	int n; //局数
	int p; //玩家 
	int pwin; //玩家胜局 
	int pcwin; //电脑胜局 
	string p_choice; //玩家出拳 
	string pc_choice; //电脑出拳 
	
	flag1:
	system("cls");
	cout << "-------------------- 猜拳 --------------------" << endl;
	cout << "按下 1 赛制为三局制" << endl;
	cout << "按下 2 赛制为五局制" << endl;
	cout << "按下 3 赛制为七局制" << endl;
	
	while(1){
		if (_kbhit()){
			ch1 = _getch();
			if (ch1 == (int)'1'){
				n = 3; break;
			} else if (ch1 == (int)'2'){
				n = 5; break;
			} else if (ch1 == (int)'3'){
				n = 7; break;
			}
		}
	}
	
	flag2:
	//重新开始的初始化 
	if (ch1 == (int)'1') n = 3;
	if (ch1 == (int)'2') n = 5;
	if (ch1 == (int)'3') n = 7; 
	
	system("cls");
	cout << "按下S表示出石头" << endl;
	cout << "按下D表示出剪刀" << endl;
	cout << "按下F表示出布" << endl; 
	
	pwin = 0; pcwin = 0;
	while(n != 0){
		pc = rand() % 3;
		/////玩家出拳///// 
		while(1){
			if (_kbhit()){
				ch2 = _getch();
				if (ch2 == (int)'s'){
					p = 0; break;
				} else if (ch2 == (int)'d'){
					p = 1; break;
				} else if (ch2 == (int)'f'){
					p = 2; break;
				} else if (ch2 == 27){
					goto flag1; break;
				}
			}
		}
		if (p == 0) p_choice = "石头";
		if (p == 1) p_choice = "剪刀";
		if (p == 2) p_choice = "布";
		
		if (pc == 0) pc_choice = "石头";
		if (pc == 1) pc_choice = "剪刀";
		if (pc == 2) pc_choice = "布";
		
		cout << endl << "电脑: " << pc_choice << "  " << "你: " << p_choice << endl << endl; 
		
		if ((p == pc - 1 && p <= 2) || (p == 2 && pc == 0)) pwin++;
		if ((pc == p - 1 && pc <= 2) || (pc == 2 && p == 0)) pcwin++;
		n--;
	}
	
	if (pwin > pcwin) cout << "你赢了" << endl << endl;
	if (pcwin > pwin) cout << "你输了" << endl << endl;
	if (pwin == pcwin) cout << "平手" << endl << endl; 
	
	cout << "按下ESC重新选择赛制" << endl;
	cout << "按下ENTER按同样赛制重新开始" << endl;
	
	while(1){
		if (_kbhit()){
			ch3 = _getch();
			if (ch3 == 27){
				goto flag1; break;
			} else if (ch3 == 13){
				goto flag2; break;
			}
		}
	} 
}
