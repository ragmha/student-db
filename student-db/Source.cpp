#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<Windows.h>



using namespace std;

int main()
	{
	
	FILE *fp, *ft;
	char another, choice;

	struct student {
		char first_name[100], last_name[100];
		char course[200];
		char section[50];
	};

	struct student e;
	char xfirst_name[100], xlast_name[100];
	long int recsize;

	fp = fopen("user.txt", "rb+");

	if (fp == NULL) {
		fp = fopen("users.txt", "wb+");

		if (fp == NULL)
		{
			puts("Cannot open file");
			return 0;
		}
}
	recsize = sizeof(7);

	while (1)
	{
		system("cls");

		HANDLE hConsole;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hConsole, 27);
		cout << " *******************************************************************************";
		cout << " 				 STUDENT DATABASE SYSTEM                        ";
		cout << " *******************************************************************************";
		cout << "																				\n\n";														
		cout << "	\t\t\t 1)  ADD	RECORDS				 \n";
		cout <<	"	\t\t\t 2)  VIEW       RECORDS			         \n";
		cout << "	\t\t\t 3)  MODIFY	RECORDS		                 \n";
		cout << "	\t\t\t 4)  DELETE	RECORDS			         \n";
		cout << "	\t\t\t 5)  EXIT	RECORDS			         \n";
		cout << "													                                                         \n";
		cout << "		\t\t  SELECT YOUR OPTION :=>			\n";
		cout << "																	                        ";
		fflush(stdin);

	
	
		
		choice = _getche();
		switch (choice)
		{
		case '1':
			fseek(fp, 0, SEEK_END);
			another = 'Y';
			while (another == 'Y' || another == 'y')
			{
				system("cls");
				cout << "\n\n";
				cout << "\tEnter First Name : ";
				cin >> e.first_name;
				cout << "\n";
				cout << "\tEnter Last Name : ";
				cin >> e.last_name;
				cout << "\n";
				cout << "\tEnter Course   : ";
				cin >> e.course;
				cout << "\n";
				cout << "\tEnter Group   :	";
				cin >> e.section;
				fwrite(&e, recsize, 1, fp);
				cout << "\n";
				cout << "\t\tADD ANOTHER RECORD [Y/N]";
				fflush(stdin);
				another = getchar();

			}
			break; 
		
		case '2':
			system("cls");
			rewind(fp);
			cout << "\t\t\t RECORDS IN THE DATABASE \t\t";
			cout << "\n";
			while (fread(&e, recsize, 1, fp) == 1)
			{
				cout << "\n\n";
				cout << "\tNAME: " << e.first_name << setw(6) << e.last_name;
				cout << "\n\n";
				cout << "\tCOURSE: " << e.course;
				cout << "\n\n";
				cout << "\tGROUP: " << e.section;
			}
			cout << "\n\n";
			system("pause");
			break;

		case '3':
			system("cls");
			another = 'Y';
			while (another == 'Y' || another == 'y')
			{
				cout << "\n Enter the last name of the student :";
				cin >> xlast_name;

				rewind(fp);
				while (fread(&e, recsize, 1, fp) == 1)
				{
					if (strcmp(e.last_name, xlast_name) == 0)
					{
						cout << "Enter new First Name: ";
						cin >> e.first_name;
						cout << "Enter new Last Name: ";
						cin >> e.last_name;
						cout << "Enter new Course: ";
						cin >> e.course;
						cout << "Enter new Section: ";
						cin >> e.section;
						fseek(fp, -recsize, SEEK_CUR);
						fwrite(&e, recsize, 1, fp);
						break;
					}
					else
						cout << "ERORR RECORD NOT FOUND";

				}
				cout << "\n Modify Another RECORD [Y/N]";
				fflush(stdin);
				another = getchar();
				}
			break;


		case '4':
			system("cls");
			another = 'Y';
			while (another == 'Y' || another == 'y')
			{
				cout << "\n Enter Student Last Name to Delete: ";
				cin >> xlast_name;

				ft = fopen("temp.dat", "wb");

				rewind(fp);

				while (fread(&e,recsize,1,fp) == 1)

				if (strcmp(e.last_name,xlast_name) != 0) 
				{
					fwrite(&e, recsize, 1, ft);
				}
				fclose(fp);
				fclose(ft);
				remove("users.txt");
				rename("temp.dat", "users.txt");

				fp = fopen("users.txt", "rb+");

				cout << "\n Delete Another RECORD [Y/N]";
				fflush(stdin);
				another = getchar();
			}
			break;


		case '5' :
			fclose(fp);
			cout << "\n\n";
			cout << "\t\t	THANK YOU! :] ";
			exit(0);

		}
	}


	system("pause");
	return 0;

}
