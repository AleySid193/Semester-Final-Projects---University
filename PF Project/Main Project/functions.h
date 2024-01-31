#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<fstream>
using namespace std;

double price = 0;
string ans;
double bill = 0, cash = 0;

void customer();
void mainmenu();
void login();
void modify();
void del();
void create();
void display();





//Function for main menu
void mainmenu() {
	int user;
	cout << "Welcome To Main Menu!" << endl << endl;
	cout << "1. Admin" << endl;
	cout << "2. Customer" << endl;
	cout << "3. Exit" << endl;
	cout << "PRESS RELATIVE KEY = ";
	cin >> user;
	system("cls");
	switch (user) {
	case 1: {
		login();
		break;
	}
	case 2: {
		customer();
		break;
	}
	case 3: break;
	default: {
		cout << "Invalid Input!" << endl;
		cout << "Re Enter Valid Inputs" << endl;
		mainmenu();
	}
	}
}





//Admin functions started
//Function for login (admin main function)
void login() {
	cout << "Login To Get Access!" << endl << endl;
	int i = 2, j = 2, user, user1;
	ifstream passin;
	ofstream passout;
	string reserve, pass;
	do {
		cout << "1. Change Password" << endl;
		cout << "2. Enter Password" << endl;
		cout << "3. Go To Main Menu" << endl;
		cout << "4. Exit" << endl;
		cout << "PRESS RELATIVE KEY = ";
		cin >> user1;
		system("cls");
		passin.open("pass.txt");
		passin >> reserve;
		passin.close();
		switch (user1) {
		case 1: {
			do {
				cout << "Enter The Old Passcode ::" << endl;
				cin >> pass;
				if (pass == reserve) {
					cout << "Enter The New Passcode without spacing  ::" << endl;
					cin >> pass;
					reserve = pass;
					passout.open("pass.txt");
					passout << reserve;
					passout.close();
					cout << "Passcode Changed Successfuly!" << endl;
					system("pause"); system("cls");
					mainmenu();
				}
				else {
					cout << "Incorrect Passcode!" << endl;
					cout << "You have " << i << " More Attempts!" << endl;
					i--;
					system("pause"); system("cls");
				}
			} while (pass != reserve && i > 0);
			break;
		}
		case 2: {
			do {
				cout << "Enter Your Passcode To Get Access ::" << endl;
				cin >> pass;
				system("cls");
				if (pass == reserve) {
					cout << "Welcome To Admin Menu!" << endl << endl;
					cout << "1. Add New Item" << endl;
					cout << "2. Display Records" << endl;
					cout << "3. Modify Any Item" << endl;
					cout << "4. Delete Item" << endl;
					cout << "5. Go Back" << endl;
					cout << "6. Go To Main Menu" << endl;
					cout << "PRESS RELATIVE KEY = ";
					cin >> user;
					system("cls");
					switch (user) {
					case 1: {
						create();
						break;
					}
					case 2: {
						display();
						break;
					}
					case 3: {
						modify();
						break;
					}
					case 4: {
						del();
						break;
					}
					case 5: {
						login();
						break;
					}
					case 6: {
						mainmenu();
						break;
					}
					default: {
						cout << "Invalid Input!" << endl;
						break;
					}
					}
				}
				else {
					cout << "Incorrect Passcode!" << endl;
					cout << "You Have " << j << " More Attempts!" << endl;
					j--;
					system("pause"); system("cls");
				}
			} while (pass != reserve && j > 0);
			break;
		}
		case 3: {
			mainmenu();
			break;
		}
		case 4: {
			break;
		}
		default: {
			cout << "Invalid Input!" << endl;
		}
		}
	} while (user1 < 1 || user1 > 4);
}





//#1 Create function
void create() {
	int option, count = 0, quantity;
	string name;
	double price;
	ofstream write;
	ifstream read;
	string temp;
	do {
		cout << "Welcome To Create Menu!" << endl << endl;
		cout << "1. Burger" << endl;
		cout << "2. Pizza" << endl;
		cout << "3. Pasta" << endl;
		cout << "4. Brownie" << endl;
		cout << "5. Drinks" << endl;
		cout << "6. Go Back" << endl;
		cout << "7. Go To Main Menu" << endl;
		cout << "PRESS RELATIVE KEY = ";
		cin >> option;
		system("cls");
		switch (option) {
		case 1: {
			cin.ignore();
			cout << "Enter Name Of The Product" << endl;
			getline(cin, name);
			cout << "Enter Price Of Product = ";
			cin >> price;
			write.open("bprice.txt", ios::app);
			write << price << endl;
			write.close();
			cout << "Enter The Quantity = ";
			cin >> quantity;
			write.open("bstock.txt", ios::app);
			write << quantity << endl;
			write.close();
			read.open("burger.txt");
			while (!read.eof()) {
				getline(read, temp);
				count++;
			}
			read.close();
			write.open("burger.txt", ios::app);
			write << count << "." << setw(20) << name << setw(20) << price << setw(20) << endl;
			write.close();
			cout << "Item Created Successfuly!" << endl;
			break;
		}
		case 2: {
			cin.ignore();
			cout << "Enter Name Of The Product" << endl;
			getline(cin, name);
			cout << "Enter Price Of Product = ";
			cin >> price;
			write.open("pprice.txt", ios::app);
			write << price << endl;
			write.close();
			cout << "Enter The Quantity = ";
			cin >> quantity;
			write.open("pstock.txt", ios::app);
			write << quantity << endl;
			write.close();
			read.open("pizza.txt");
			while (!read.eof()) {
				getline(read, temp);
				count++;
			}
			read.close();
			write.open("pizza.txt", ios::app);
			write << count << "." << setw(20) << name << setw(20) << price << setw(20) << endl;
			write.close();
			cout << "Item Created Successfuly!" << endl;
			break;
		}
		case 3: {
			cin.ignore();
			cout << "Enter Name Of The Product" << endl;
			getline(cin, name);
			cout << "Enter Price Of Product = ";
			cin >> price;
			write.open("paprice.txt", ios::app);
			write << price << endl;
			write.close();
			cout << "Enter The Quantity = ";
			cin >> quantity;
			write.open("pastock.txt", ios::app);
			write << quantity << endl;
			write.close();
			read.open("pasta.txt");
			while (!read.eof()) {
				getline(read, temp);
				count++;
			}
			read.close();
			write.open("pasta.txt", ios::app);
			write << count << "." << setw(20) << name << setw(20) << price << setw(20) << endl;
			write.close();
			cout << "Item Created Successfuly!" << endl;
			break;
		}
		case 4: {
			cin.ignore();
			cout << "Enter Name Of The Product" << endl;
			getline(cin, name);
			cout << "Enter Price Of Product = ";
			cin >> price;
			write.open("brprice.txt", ios::app);
			write << price << endl;
			write.close();
			cout << "Enter The Quantity = ";
			cin >> quantity;
			write.open("brstock.txt", ios::app);
			write << quantity << endl;
			write.close();
			read.open("brownie.txt");
			while (!read.eof()) {
				getline(read, temp);
				count++;
			}
			read.close();
			write.open("brownie.txt", ios::app);
			write << count << "." << setw(20) << name << setw(20) << price << setw(20) << endl;
			write.close();
			cout << "Item Created Successfuly!" << endl;
			break;
		}
		case 5: {
			cin.ignore();
			cout << "Enter Name Of The Product" << endl;
			getline(cin, name);
			cout << "Enter Price Of Product = ";
			cin >> price;
			write.open("dprice.txt", ios::app);
			write << price << endl;
			write.close();
			cout << "Enter The Quantity = ";
			cin >> quantity;
			write.open("dstock.txt", ios::app);
			write << quantity << endl;
			write.close();
			read.open("drinks.txt");
			while (!read.eof()) {
				getline(read, temp);
				count++;
			}
			read.close();
			write.open("drinks.txt", ios::app);
			write << count << "." << setw(20) << name << setw(20) << price << setw(20) << endl;
			write.close();
			cout << "Item Created Successfuly!" << endl;
			break;
		}
		case 6: {
			login();
			break;
		}
		case 7: {
			mainmenu();
			break;
		}
		default: {
			cout << "Invalid Input" << endl;
			break;
		}
		}
	} while (option < 1 || option > 7);
	cout << "Do You Want To Continue?" << endl;
	cout << "Press 'Y' For Yes Or 'N' For No..." << endl;
	cout << "Enter Here = ";
	cin >> ans;
	if (ans == "Y" || ans == "y") {
		create();
	}
	else if (ans == "N" || ans == "n") {
		mainmenu();
	}
}





//#2 Display function
void display() {
	ifstream read, read1;
	string temp, temp1;
	cout << "Your File Has Following Data In It!" << endl << endl;
	cout << "Sr#" << setw(20) << "Name" << setw(20) << "Price" << setw(20) << "Quantity" << setw(20) << endl << endl;
	read.open("burger.txt");
	read1.open("bstock.txt");
	cout << "Your Burger's Are ::" << endl;
	while (!read.eof()) {
		getline(read, temp);
		getline(read1, temp1);
		cout << temp << setw(20) << temp1 << endl;
	}
	read.close();
	read1.close();
	read.open("pizza.txt");
	read1.open("pstock.txt");
	cout << "Your Pizza's Are ::" << endl;
	while (!read.eof()) {
		getline(read, temp);
		getline(read1, temp1);
		cout << temp << setw(20) << temp1 << endl;
	}
	read.close();
	read1.close();
	read.open("pasta.txt");
	read1.open("pastock.txt");
	cout << "Your Pasta's Are ::" << endl;
	while (!read.eof()) {
		getline(read, temp);
		getline(read1, temp1);
		cout << temp << setw(20) << temp1 << endl;
	}
	read.close();
	read1.close();
	read.open("brownie.txt");
	read1.open("brstock.txt");
	cout << "Your Brownie's Are ::" << endl;
	while (!read.eof()) {
		getline(read, temp);
		getline(read1, temp1);
		cout << temp << setw(20) << temp1 << endl;
	}
	read.close();
	read1.close();
	read.open("drinks.txt");
	read1.open("dstock.txt");
	cout << "Your Drink's Are ::" << endl;
	while (!read.eof()) {
		getline(read, temp);
		getline(read1, temp1);
		cout << temp << setw(20) << temp1 << endl;
	}
	read.close();
	read1.close();
	system("pause"); system("cls");
	mainmenu();
}





//3 Modification function
void modify() {
	int option, sr, count = 0;
	char ch;
	string str;
	double price, stock, data, data2[1000] = { 0 };
	ofstream write; 
	ifstream read;
	cout << "Welcome To Modification Menu!" << endl << endl;
	cout << "1. Burger" << endl;
	cout << "2. Pizza" << endl;
	cout << "3. Pasta" << endl;
	cout << "4. Brownie" << endl;
	cout << "5. Drinks" << endl;
	cout << "6. Go Back" << endl;
	cout << "7. Go To Main Menu" << endl;
	cout << "PRESS RELATIVE KEY = ";
	cin >> option;
	system("cls");
	switch (option) {
	case 1: {
		read.open("burger.txt");
		while (!read.eof()) {
			getline(read, str);
			cout << str << endl;
		}
		read.close();
		cout << "Enter Serial Number = ";
		cin >> sr;
		sr = sr - 1;
		cout << "1. To Change Price" << endl;
		cout << "2. To Change Stock" << endl;
		cin >> option;
		switch (option) {
		case 1: {
			cout << "Enter Price = " << endl;
			cin >> price;
			read.open("bprice.txt");
			while (!read.eof()) {
				read >> data;
				data2[count] = data;
				count++;
			}
			read.close();
			data2[sr] = price;
			write.open("bprice.txt");
			for (int i = 0; i < count - 1; i++) {
				data = data2[i];
				write << data << endl;
			}
			write.close();
			break;
		}
		case 2: {
			cout << "Enter Stock = " << endl;
			cin >> stock;
			read.open("bstock.txt");
			while (!read.eof()) {
				read >> data;
				data2[count] = data;
				count++;
			}
			read.close();
			data2[sr] = stock;
			write.open("bstock.txt");
			for (int i = 0; i < count - 1; i++) {
				data = data2[i];
				write << data << endl;
			}
			write.close();
			break;
		}
		default: {
			cout << "Invalid Input" << endl;
			break;
		}
		}
		break;
	}
	case 2: {

		read.open("pizza.txt");
		while (!read.eof()) {
			getline(read, str);
			cout << str << endl;

		}
		read.close();
		cout << "Enter Serial Number = ";
		cin >> sr;
		sr = sr - 1;
		cout << "1. To Change Price" << endl;
		cout << "2. To Change Stock" << endl;
		cin >> option;
		switch (option) {
		case 1: {
			cout << "Enter Price = " << endl;
			cin >> price;
			read.open("pprice.txt");
			while (!read.eof()) {
				read >> data;
				data2[count] = data;
				count++;
			}
			read.close();
			data2[sr] = price;
			write.open("pprice.txt");
			for (int i = 0; i < count - 1; i++) {
				data = data2[i];
				write << data << endl;
			}
			write.close();
			break;
		}
		case 2: {
			cout << "Enter Stock = " << endl;
			cin >> stock;
			read.open("pstock.txt");
			while (!read.eof()) {
				read >> data;
				data2[count] = data;
				count++;
			}
			read.close();
			data2[sr] = stock;
			write.open("pstock.txt");
			for (int i = 0; i < count - 1; i++) {
				data = data2[i];
				write << data << endl;
			}
			write.close();
			break;
		}
		default: {
			cout << "Invalid Input!" << endl;
			break;
		}
		}
		break;
	}
	case 3: {

		read.open("pasta.txt");
		while (!read.eof()) {
			getline(read, str);
			cout << str << endl;

		}
		read.close();
		cout << "Enter Serial Number = ";
		cin >> sr;
		sr = sr - 1;
		cout << "1. To Change Price" << endl;
		cout << "2. To Change Stock" << endl;
		cin >> option;
		switch (option) {
		case 1: {
			cout << "Enter Price = " << endl;
			cin >> price;
			read.open("paprice.txt");
			while (!read.eof()) {
				read >> data;
				data2[count] = data;
				count++;
			}
			read.close();
			data2[sr] = price;
			write.open("paprice.txt");
			for (int i = 0; i < count - 1; i++) {
				data = data2[i];
				write << data << endl;
			}
			write.close();
			break;
		}
		case 2: {
			cout << "Enter Stock = " << endl;
			cin >> stock;
			read.open("pastock.txt");
			while (!read.eof()) {
				read >> data;
				data2[count] = data;
				count++;
			}
			read.close();
			data2[sr] = stock;
			write.open("pastock.txt");
			for (int i = 0; i < count - 1; i++) {
				data = data2[i];
				write << data << endl;
			}
			write.close();
			break;
		}
		default: {
			cout << "Invalid Input" << endl;
			break;
		}
		}
		break;
	}
	case 4: {

		read.open("brownie.txt");
		while (!read.eof()) {
			getline(read, str);
			cout << str << endl;

		}
		read.close();
		cout << "Enter Serial Number = ";
		cin >> sr;
		sr = sr - 1;
		cout << "1. To Change Price" << endl;
		cout << "2. To Change Stock" << endl;
		cin >> option;
		switch (option) {
		case 1: {
			cout << "Enter Price = " << endl;
			cin >> price;
			read.open("brprice.txt");
			while (!read.eof()) {
				read >> data;
				data2[count] = data;
				count++;
			}
			read.close();
			data2[sr] = price;
			write.open("brprice.txt");
			for (int i = 0; i < count - 1; i++) {
				data = data2[i];
				write << data << endl;
			}
			write.close();
			break;
		}
		case 2: {
			cout << "Enter Stock = " << endl;
			cin >> stock;
			read.open("brstock.txt");
			while (!read.eof()) {
				read >> data;
				data2[count] = data;
				count++;
			}
			read.close();
			data2[sr] = stock;
			write.open("brstock.txt");
			for (int i = 0; i < count - 1; i++) {
				data = data2[i];
				write << data << endl;
			}
			write.close();
			break;
		}
		default: {
			cout << "Invalid Input" << endl;
			break;
		}
		}
		break;
	}
	case 5: {

		read.open("drinks.txt");
		while (!read.eof()) {
			getline(read, str);
			cout << str << endl;

		}
		read.close();
		cout << "Enter Serial Number = ";
		cin >> sr;
		sr = sr - 1;
		cout << "1. To Change Price" << endl;
		cout << "2. To Change Stock" << endl;
		cin >> option;
		switch (option) {
		case 1: {
			cout << "Enter Price = " << endl;
			cin >> price;
			read.open("dprice.txt");
			while (!read.eof()) {
				read >> data;
				data2[count] = data;
				count++;
			}
			read.close();
			data2[sr] = price;
			write.open("dprice.txt");
			for (int i = 0; i < count - 1; i++) {
				data = data2[i];
				write << data << endl;
			}
			write.close();
			break;
		}
		case 2: {
			cout << "Enter Stock = " << endl;
			cin >> stock;
			read.open("dstock.txt");
			while (!read.eof()) {
				read >> data;
				data2[count] = data;
				count++;
			}
			read.close();
			data2[sr] = stock;
			write.open("dstock.txt");
			for (int i = 0; i < count - 1; i++) {
				data = data2[i];
				write << data << endl;
			}
			write.close();
			break;
		}
		default: {
			cout << "Invalid Input" << endl;
			break;
		}
		}
		break;
	}
	case 6: {
		login();
		break;
	}
	case 7: {
		mainmenu();
		break;
	}
	default: {
		cout << "Invalid Input" << endl;
		cout << "Re Enter The Valid Inputs" << endl;
		modify();
	}
	}
	cout << "Do You Want To Continue? y/n" << endl;
	cout << "Enter Here = ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y') {
		modify();
	}
	else {
		cout << "Thanks For Using This Program!" << endl;
		system("pause");
	}
}





//#4 Delete function
void del() {
	int sr, count = 0, option;
	char ch;
	ofstream write;
	ifstream read;
	string data, data2[1000];
	cout << "Welcome To Delete Menu" << endl << endl;
	cout << "1. Burger" << endl;
	cout << "2. Pizza" << endl;
	cout << "3. Pasta" << endl;
	cout << "4. Brownie" << endl;
	cout << "5. Drinks" << endl;
	cout << "6. Go Back" << endl;
	cout << "7. Go To Main Menu" << endl;
	cout << "PRESS RELATIVE KEY = ";
	cin >> option;
	system("cls");
	switch (option) {
	case 1: {
		read.open("burger.txt");
		for (int i = 0; !read.eof(); i++) {
			getline(read, data);
			data2[i] = data;
			cout << data2[i] << endl;
			count++;
		}
		read.close();
		cout << "Enter Serial Number = ";
		cin >> sr;
		sr = sr - 1;
		data2[sr] = ' ';
		write.open("burger.txt");
		for (int i = 0; i < count; i++) {
			data = data2[i];
			write << data << endl;
		}
		write.close();
		read.open("bprice.txt");
		for (int i = 0; !read.eof(); i++) {
			getline(read, data);
			data2[i] = data;
			cout << data2[i] << endl;
			count++;
		}
		read.close();
		data2[sr] = ' ';
		write.open("bprice.txt");
		for (int i = 0; i < count; i++) {
			data = data2[i];
			write << data << endl;
		}
		write.close();
		write.open("bstock.txt");
		for (int i = 0; i < count; i++) {
			data = data2[i];
			write << data << endl;
		}
		write.close();
		cout << "Line Deleted Successfuly" << endl;
		system("pause");
		break;
	}
	case 2: {
		read.open("pizza.txt");
		for (int i = 0; !read.eof(); i++) {
			getline(read, data);
			data2[i] = data;
			cout << data2[i] << endl;
			count++;
		}
		read.close();
		cout << "Enter Serial Number = ";
		cin >> sr;
		sr = sr - 1;
		data2[sr] = ' ';
		write.open("pizza.txt");
		for (int i = 0; i < count; i++) {
			data = data2[i];
			write << data << endl;
		}
		write.close();
		read.open("pprice.txt");
		for (int i = 0; !read.eof(); i++) {
			getline(read, data);
			data2[i] = data;
			count++;
		}
		read.close();
		data2[sr] = ' ';
		write.open("pprice.txt");
		for (int i = 0; i < count; i++) {
			data = data2[i];
			write << data << endl;
		}
		write.close();
		write.open("pstock.txt");
		for (int i = 0; i < count; i++) {
			data = data2[i];
			write << data << endl;
		}
		write.close();
		cout << "Line Deleted Successfuly" << endl;
		system("pause");
		break;
	}
	case 3: {
		read.open("pasta.txt");
		for (int i = 0; !read.eof(); i++) {
			getline(read, data);
			data2[i] = data;
			cout << data2[i] << endl;
			count++;
		}
		read.close();
		cout << "Enter Serial Number = ";
		cin >> sr;
		sr = sr - 1;
		data2[sr] = ' ';
		write.open("pasta.txt");
		for (int i = 0; i < count; i++) {
			data = data2[i];
			write << data << endl;
		}
		write.close();
		read.open("paprice.txt");
		for (int i = 0; !read.eof(); i++) {
			getline(read, data);
			data2[i] = data;
			count++;
		}
		read.close();
		data2[sr] = ' ';
		write.open("paprice.txt");
		for (int i = 0; i < count; i++) {
			data = data2[i];
			write << data << endl;
		}
		write.close();
		write.open("pastock.txt");
		for (int i = 0; i < count; i++) {
			data = data2[i];
			write << data << endl;
		}
		write.close();
		cout << "Line Deleted Successfuly" << endl;
		system("pause");
		break;
	}
	case 4: {
		read.open("brownie.txt");
		for (int i = 0; !read.eof(); i++) {
			getline(read, data);
			data2[i] = data;
			cout << data2[i] << endl;
			count++;
		}
		read.close();
		cout << "Enter Serial Number = ";
		cin >> sr;
		sr = sr - 1;
		data2[sr] = ' ';
		write.open("brownie.txt");
		for (int i = 0; i < count; i++) {
			data = data2[i];
			write << data << endl;
		}
		write.close();
		read.open("brprice.txt");
		for (int i = 0; !read.eof(); i++) {
			getline(read, data);
			data2[i] = data;
			count++;
		}
		read.close();
		data2[sr] = ' ';
		write.open("brprice.txt");
		for (int i = 0; i < count; i++) {
			data = data2[i];
			write << data << endl;
		}
		write.close();
		write.open("brstock.txt");
		for (int i = 0; i < count; i++) {
			data = data2[i];
			write << data << endl;
		}
		write.close();
		cout << "Line Deleted Successfuly" << endl;
		system("pause");
		break;
	}
	case 5: {
		read.open("drinks.txt");
		for (int i = 0; !read.eof(); i++) {
			getline(read, data);
			data2[i] = data;
			cout << data2[i] << endl;
			count++;
		}
		read.close();
		cout << "Enter Serial Number = ";
		cin >> sr;
		sr = sr - 1;
		data2[sr] = ' ';
		write.open("drinks.txt");
		for (int i = 0; i < count; i++) {
			data = data2[i];
			write << data << endl;
		}
		write.close();
		read.open("dprice.txt");
		for (int i = 0; !read.eof(); i++) {
			getline(read, data);
			data2[i] = data;
			count++;
		}
		read.close();
		data2[sr] = ' ';
		write.open("dprice.txt");
		for (int i = 0; i < count; i++) {
			data = data2[i];
			write << data << endl;
		}
		write.close();
		write.open("dstock.txt");
		for (int i = 0; i < count; i++) {
			data = data2[i];
			write << data << endl;
		}
		write.close();
		cout << "Line Deleted Successfuly" << endl;
		system("pause");
		break;
	}
	case 6: {
		login();
		break;
	}
	case 7: {
		mainmenu();
		break;
	}
	default: {
		cout << "Invalid Input" << endl;
		cout << "Re Enter Valid Inputs" << endl;
		del();
	}
	}
	cout << "Do You Want To Continue? y/n" << endl;
	cout << "Enter Here = ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y') {
		del();
	}
	else {
		cout << "Thanks For Using This Program!" << endl;
		system("pause");
	}
}





//Customer function started
void customer() {
	cout << "Welcome Dear Customer!" << endl << endl;
	double pay = 0;
	int option, user, count = 0, count1 = 0;
	double price[1000] = { 0 }, quantity[1000] = { 0 }, quan;
	string temp, ans;
	ifstream recieve("text.txt");
	ofstream sender;
	while (!recieve.eof()) {
		getline(recieve, temp);
		cout << temp << endl;
	}
	recieve.close();
	cout << "PRESS RELATIVE KEY = ";
	cin >> option;
	system("cls");
	switch (option) {
	case 1: {
		recieve.open("burger.txt");
		while (!recieve.eof()) {
			getline(recieve, temp);
			cout << temp << endl;
			count1++;
		}
		recieve.close();
		cout << "PRESS RELATIVE KEY = ";
		cin >> user;
		do {
			if (user >= count1 || user<=0)
			{
				cout << "you entered wrong key" << endl << "Enter again: " << endl;
				cin >> user;
			}
		} while (user <= 0 || user>=count1);
		
		do {
			cout << "Enter The Quantity = ";
			cin >> quan;
			if (quan <=0)
			{
				cout << "you entered wrong quantity" <<endl<< "Enter again: " << endl;
			}
		} while (quan <=0);
		
		recieve.open("bprice.txt");
		while (!recieve.eof()) {
			recieve >> price[count];
			count++;
		}
		recieve.close();
		count = 0;
		recieve.open("bstock.txt");
		while (!recieve.eof()) {
			recieve >> quantity[count];
			count++;
		}
		recieve.close();
		if (quantity[user - 1] <= 0)
		{
			cout << "Out of stock" << endl;
		}
		else
		{
			quantity[user - 1] -= quan;
			sender.open("bstock.txt");
			for (int i = 0; i < count; i++) {
				sender << quantity[i] << endl;
			}
			sender.close();
			quan = quan * price[user - 1];
			bill = bill + quan;
		}
		break;
	}
	case 2: {
		recieve.open("pizza.txt");
		while (!recieve.eof()) {
			getline(recieve, temp);
			cout << temp << endl;;
		}
		recieve.close();
		cout << "PRESS RELATIVE KEY = ";
		cin >> user;
		do {
			if (user >= count1 || user <= 0)
			{
				cout << "you entered wrong key" << endl << "Enter again: " << endl;
				cin >> user;
			}
		} while (user <= 0 || user >= count1);
		do {
			cout << "Enter The Quantity = ";
			cin >> quan;
			if (quan <= 0)
			{
				cout << "you entered wrong quantity" << endl << "Enter again: " << endl;
			}
		} while (quan <= 0);
		recieve.open("pprice.txt");
		while (!recieve.eof()) {
			recieve >> price[count];
			count++;
		}
		recieve.close();
		count = 0;
		recieve.open("pstock.txt");
		while (!recieve.eof()) {
			recieve >> quantity[count];
			count++;
		}
		recieve.close();
		if (quantity[user - 1] <= 0)
		{
			cout << "Out of stock" << endl;
		}
		else
		{
			quantity[user - 1] -= quan;
			sender.open("bstock.txt");
			for (int i = 0; i < count; i++) {
				sender << quantity[i] << endl;
			}
			sender.close();
			quan = quan * price[user - 1];
			bill = bill + quan;
		}
		break;
	}
	case 3: {
		recieve.open("pasta.txt");
		while (!recieve.eof()) {
			getline(recieve, temp);
			cout << temp << endl;
			count1++;
		}
		recieve.close();
		cout << "PRESS RELATIVE KEY = ";
		cin >> user;
		do {
			if (user >= count1 || user <= 0)
			{
				cout << "you entered wrong key" << endl << "Enter again: " << endl;
				cin >> user;
			}
		} while (user <= 0 || user >= count1);
		do {
			cout << "Enter The Quantity = ";
			cin >> quan;
			if (quan <= 0)
			{
				cout << "you entered wrong quantity" << endl << "Enter again: " << endl;
			}
		} while (quan <= 0);
		recieve.open("paprice.txt");
		while (!recieve.eof()) {
			recieve >> price[count];
			count++;
		}
		recieve.close();
		count = 0;
		recieve.open("pastock.txt");
		while (!recieve.eof()) {
			recieve >> quantity[count];
			count++;
		}
		recieve.close();
		if (quantity[user - 1] <= 0)
		{
			cout << "Out of stock" << endl;
		}
		else
		{
			quantity[user - 1] -= quan;
			sender.open("bstock.txt");
			for (int i = 0; i < count; i++) {
				sender << quantity[i] << endl;
			}
			sender.close();
			quan = quan * price[user - 1];
			bill = bill + quan;
		}
		break;
	}
	case 4: {
		recieve.open("brownie.txt");
		while (!recieve.eof()) {
			getline(recieve, temp);
			cout << temp << endl;;
		}
		recieve.close();
		cout << "PRESS RELATIVE KEY = ";
		cin >> user;
		do {
			if (user >= count1 || user <= 0)
			{
				cout << "you entered wrong key" << endl << "Enter again: " << endl;
				cin >> user;
			}
		} while (user <= 0 || user >= count1);
		do {
			cout << "Enter The Quantity = ";
			cin >> quan;
			if (quan <= 0)
			{
				cout << "you entered wrong quantity" << endl << "Enter again: " << endl;
			}
		} while (quan <= 0);
		recieve.open("brprice.txt");
		while (!recieve.eof()) {
			recieve >> price[count];
			count++;
		}
		recieve.close();
		count = 0;
		recieve.open("brstock.txt");
		while (!recieve.eof()) {
			recieve >> quantity[count];
			count++;
		}
		recieve.close();
		if (quantity[user - 1] <= 0)
		{
			cout << "Out of stock" << endl;
		}
		else
		{
			quantity[user - 1] -= quan;
			sender.open("bstock.txt");
			for (int i = 0; i < count; i++) {
				sender << quantity[i] << endl;
			}
			sender.close();
			quan = quan * price[user - 1];
			bill = bill + quan;
		}
		break;
	}
	case 5: {
		recieve.open("drinks.txt");
		while (!recieve.eof()) {
			getline(recieve, temp);
			cout << temp << endl;
			count1++;
		}
		recieve.close();
		cout << "PRESS RELATIVE KEY = ";
		cin >> user;
		do {
			if (user >= count1 || user <= 0)
			{
				cout << "you entered wrong key" << endl << "Enter again: " << endl;
				cin >> user;
			}
		} while (user <= 0 || user >= count1);
		
			cout << "Enter The Quantity = ";
			cin >> quan;
			if (quan <= 0)
			{
				cout << "you entered wrong quantity" << endl << "Enter again: " << endl;
			}

		recieve.open("dprice.txt");
		while (!recieve.eof()) {
			recieve >> price[count];
			count++;
		}
		recieve.close();
		count = 0;
		recieve.open("dstock.txt");

		while (!recieve.eof()) {
			recieve >> quantity[count];
			count++;
		}
		recieve.close();
		if (quantity[user - 1] <= 0)
		{
			cout << "Out of stock" << endl;
		}
		else
		{
			quantity[user - 1] -= quan;
			sender.open("bstock.txt");
			for (int i = 0; i < count; i++) {
				sender << quantity[i] << endl;
			}
			sender.close();
			quan = quan * price[user - 1];
			bill = bill + quan;
		}
		break;
	}
	case 6: {
		mainmenu();
		break;
	}
	case 7: {
		break;
	}
	default: {
		cout << " INVALID " << endl;
	}
	}
	cout << "Do You Want To Continue  " << endl;
	cout << "If yes Press Y else press n for no" << endl;
	cin >> ans;
	if (ans == "y" || ans == "Y") {
		system("pause"); system("cls");
		customer();
	}
	else {
		cout << "Thank You This Is Your Bill " << bill << endl;
		do {
			cout << "Enter Payment = ";
			cin >> pay;
			pay = pay - bill;
			bill = 0;
			if (pay < 0) {
				cout << "Insufficient cash!" << endl;
				cout << "Enter Valid Payment!" << endl;
			}
			else {
				cout << "Your Change =  " << pay << endl;
				system("pause"); system("cls");
				mainmenu();
			}
		} while (pay < 0);
	}
}
