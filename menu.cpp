#include <iostream>
#include <Windows.h>
#include "menu.h"
#include <time.h>
#include <fstream>
#include "head.h"
#include <string>
using namespace std;

void menu()
{
	cout << "\t\t\tMENU" << endl;
	cout << "Chon 1 de sap xep tinh trang RANDOM" << endl;
	cout << "Chon 2 de sap xep voi tinh trang SORTED " << endl;
	cout << "Chon 3 de sap xep voi tinh trang NEARLY SORTED" << endl;
	cout << "Chon 4 de sap xep voi tinh trang REVERSED" << endl;
	cout << "Chon 5 de ket thuc chuong trinh" << endl;
}

void chonMenu(int &phimTat)
{
	cout << endl;
	cout << "Moi ban nhap: ";
	cin >> phimTat;
}


void xuLyMenu(int &phimTat)
{
	ofstream result;
	result.open("Result.csv", ios::out|ios::app);
	while(1)
	{
		if (phimTat == 0)
		{
			system("cls");
			menu();
			chonMenu(phimTat);
		}
		else if (phimTat == 1)
		{
			system("cls");
			string state = "Random";
			sapXep(state, result);
			cout << endl;
			cout << "NHAP 0 DE QUAY TRO LAI MENU";
			chonMenu(phimTat);
		}
		else if (phimTat == 2)
		{
			system("cls");
			string state = "Sorted";
			sapXep(state, result);
			cout << endl;
			cout << "NHAP 0 DE QUAY TRO LAI MENU";
			chonMenu(phimTat);
		}
		else if (phimTat == 3)
		{
			system("cls");
			string state = "NearlySorted";
			sapXep(state, result);
			cout << endl;
			cout << "NHAP 0 DE QUAY TRO LAI MENU";
			chonMenu(phimTat);
		}
		else if (phimTat == 4)
		{
			system("cls");
			string state = "Reversed";
			sapXep(state, result);
			cout << endl;
			cout << "NHAP 0 DE QUAY TRO LAI MENU";
			chonMenu(phimTat);
		}
		
		else if (phimTat == 5)
		{
			break;
		}
		else
		{
			cout << "Phim tat khong hop le, moi ban nhap lai yeu cau./ ";
			chonMenu(phimTat);
		}
	}
	result.close();
}