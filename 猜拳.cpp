#include <bits/stdc++.h>
#include <conio.h> 
using namespace std;
int main(){
	srand(time(0));
	int pc = rand() % 3; //���� 
	char ch1; //���Ƽ����¼� 
	char ch2; //��ȭ�����¼� 
	char ch3; //�ؿ������¼� 
	int n; //����
	int p; //��� 
	int pwin; //���ʤ�� 
	int pcwin; //����ʤ�� 
	string p_choice; //��ҳ�ȭ 
	string pc_choice; //���Գ�ȭ 
	
	flag1:
	system("cls");
	cout << "-------------------- ��ȭ --------------------" << endl;
	cout << "���� 1 ����Ϊ������" << endl;
	cout << "���� 2 ����Ϊ�����" << endl;
	cout << "���� 3 ����Ϊ�߾���" << endl;
	
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
	//���¿�ʼ�ĳ�ʼ�� 
	if (ch1 == (int)'1') n = 3;
	if (ch1 == (int)'2') n = 5;
	if (ch1 == (int)'3') n = 7; 
	
	system("cls");
	cout << "����S��ʾ��ʯͷ" << endl;
	cout << "����D��ʾ������" << endl;
	cout << "����F��ʾ����" << endl; 
	
	pwin = 0; pcwin = 0;
	while(n != 0){
		pc = rand() % 3;
		/////��ҳ�ȭ///// 
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
		if (p == 0) p_choice = "ʯͷ";
		if (p == 1) p_choice = "����";
		if (p == 2) p_choice = "��";
		
		if (pc == 0) pc_choice = "ʯͷ";
		if (pc == 1) pc_choice = "����";
		if (pc == 2) pc_choice = "��";
		
		cout << endl << "����: " << pc_choice << "  " << "��: " << p_choice << endl << endl; 
		
		if ((p == pc - 1 && p <= 2) || (p == 2 && pc == 0)) pwin++;
		if ((pc == p - 1 && pc <= 2) || (pc == 2 && p == 0)) pcwin++;
		n--;
	}
	
	if (pwin > pcwin) cout << "��Ӯ��" << endl << endl;
	if (pcwin > pwin) cout << "������" << endl << endl;
	if (pwin == pcwin) cout << "ƽ��" << endl << endl; 
	
	cout << "����ESC����ѡ������" << endl;
	cout << "����ENTER��ͬ���������¿�ʼ" << endl;
	
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
