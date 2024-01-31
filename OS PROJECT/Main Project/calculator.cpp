#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

void calculator()
{
	int option;
	do {
		system("clear");
		cout << "Welcome To Calculator!" << endl << endl;
		cout << "1) Addition" << endl;
		cout << "2) Subtraction" << endl;
		cout << "3) Multiplication" << endl;
		cout << "4) Division" << endl;
		cout << "5) Modulus" << endl;
		cout << "6) Quit" << endl;
		cout << "Enter Here : ";
		cin >> option;

		system("clear");
		switch (option) {
		case 1: {
			int a, b;
			cout << "Enter First Number : " << endl;
			cin >> a;
			cout << "Enter Second Number : " << endl;
			cin >> b;
			cout << "Sum : " << a + b << endl;
			break;
		}
		case 2: {
			int a, b;
			cout << "Enter First Number : " << endl;
			cin >> a;
			cout << "Enter Second Number : " << endl;
			cin >> b;
			cout << "Difference : " << a - b << endl;
			break;
		}
		case 3: {
			int a, b;
			cout << "Enter First Number : " << endl;
			cin >> a;
			cout << "Enter Second Number : " << endl;
			cin >> b;
			cout << "Product : " << a * b << endl;
			break;
		}
		case 4: {
			int a, b;
			cout << "Enter First Number : " << endl;
			cin >> a;
			cout << "Enter Second Number : " << endl;
			cin >> b;
			cout << "Division : " << a / b << endl;
			break;
		}
		case 5: {
			int a, b;
			cout << "Enter First Number : " << endl;
			cin >> a;
			cout << "Enter Second Number : " << endl;
			cin >> b;
			cout << "Modulus : " << a % b << endl;
			break;
		}
		case 6: {
			system("clear");
			cout << "Thanks For Using Calcuator..." << endl;
			sleep(5);
			system("clear");
			option = 5;
			break;
		}
		default: {
			cout << "Invalid Input!" << endl;
			break;
		}
		}
	} while (option != 5);
}

int main(int argc, char* argv[])
{
	calculator();
	int x = atoi(argv[1]);
    mkfifo("mypipe", 0666);

     int fd = open("mypipe", O_WRONLY);
    write(fd, &x, sizeof(x));
	close(fd);
	return 0;
}
