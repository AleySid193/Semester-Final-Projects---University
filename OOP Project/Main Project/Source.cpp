
#include<iomanip>
#include<fstream>
#include<windows.h>
#include<ctime>
#include <stdlib.h>
#include <cstdlib>
#include<time.h>
#include <string>
#include <cstring>
#include <sstream>
#include "covid.h"
#include <iostream>

using namespace std;

void gov_off_access_to_files();


/*class superadmin
{
public:

	void add_doctor()
	{

	}
	void delete_doctor()
	{

	}
	void add_fdo()
	{

	}
	void delete_fdo()
	{

	}
	void  add_govt_official()
	{

	}
	void delete_govt_official()
	{

	}
	void add_admin()
	{

	}
	void delete_admin()
	{

	}
protected:*/

void superadmin:: superadmin_login_check()
{
	struct Data
	{
		string name, email, password;
	};

	string line, word;
	int i = 0;
	bool flag = false;
	string name, email, password;
	Data v1, v2;
	cout << "Enter email : ";  cin >> v1.email;
	cout << "Enter password : "; cin >> v1.password;

	ifstream read;


	read.open("superadmin_credentials.csv");
	if (!read.is_open())
	{
		cout << "Sorry! : " << endl;
		exit(0);
	}

	else
	{
		while (getline(read, line))
		{
			stringstream str(line);

			getline(str, email, ',');
			getline(str, password, '\n');


			v2.email = email;
			v2.password = password;
		}
		if (v2.email == v1.email && v2.password == v1.password)
		{
			flag = true;
		}
		if (flag == true)
		{
			system("cls");
			cout << "Congratulations! Access Granted : " << endl;
		}
		else
		{
			system("cls");
			cout << "Access Denied : Enter the credentials again. " << endl;
		}

	}


	read.close();
}


void admin::admin_login_check()

{
	struct Data
	{
		string name, email, password;
	};

	string line, word;
	int i = 0;
	bool flag = false;
	string name, email, password;
	Data v1, v2;
	cout << "Enter email : ";
	cin >> v1.email;
	cout << "Enter password : ";
	cin >> v1.password;

	ifstream read;


	read.open("admin_credentials.csv");
	if (!read.is_open())
	{
		cout << "Sorry! : " << endl;
		exit(0);
	}

	else
	{
		while (getline(read, line))
		{
			stringstream str(line);

			getline(str, email, ',');
			getline(str, password, '\n');


			v2.email = email;
			v2.password = password;
		}
		if (v2.email == v1.email && v2.password == v1.password)
		{
			flag = true;
		}
		if (flag == true)
		{
			system("cls");
			cout << "Congratulations! Access Granted : " << endl;
		}
		else
		{
			system("cls");
			cout << "Access Denied : Enter the credentials again. " << endl;
		}

	}


	read.close();
}


void doctor::citizen_vaccine_status()
{
	bool flag = false;
	static int totalVaccineCount = 0;
	int citizenVaccineCount = 0;
	cout << "Enter the doses you already got : ";
	cin >> citizenVaccineCount;
	if (citizenVaccineCount == 0)
	{
		flag = true;
	}
	
	if (flag==true)
	{
		cout << "Person does not get any of his vaccine shot : " << endl;
		cout << "Here is your first shot of vaccine : " << endl;
		citizenVaccineCount++;
		totalVaccineCount++;
		cout << "Your total dose : " << citizenVaccineCount << endl;
		cout << "Total vaccine count : " << totalVaccineCount << endl;
	}
	else if (citizenVaccineCount==1)
	{
		cout << "You only left with one shot of vaccine : " << endl;
		citizenVaccineCount++;
		totalVaccineCount += 2;
		cout << "Your total dose : " << citizenVaccineCount << endl;
	}
	else if (citizenVaccineCount<=3)
	{
		cout << "Your vaccination process is being completed : " << endl;
		cout << "No need of vaccine anymore : " << endl;
		citizenVaccineCount = 2;
		cout << "Your total dose : " << citizenVaccineCount << endl;
		totalVaccineCount += 2;
		cout << "Total vaccine count : " << totalVaccineCount << endl;

	}

}


void doctor:: doctor_login_check()
{
	struct Data
	{
		string name, email, password;
	};

	string line, word;
	int i = 0;
	bool flag = false;
	string name, email, password;
	Data v1, v2;
	cout << "Enter email : ";
	cin >> v1.email;
	cout << "Enter password : ";
	cin >> v1.password;

	ifstream read;


	read.open("doctor_credentials.csv");
	if (!read.is_open())
	{
		cout << "Sorry! : " << endl;
		exit(0);
	}

	else
	{
		while (getline(read, line))
		{
			stringstream str(line);

			getline(str, email, ',');
			getline(str, password, '\n');


			v2.email = email;
			v2.password = password;
		}
		if (v2.email == v1.email && v2.password == v1.password)
		{
			flag = true;
		}
		if (flag == true)
		{
			system("cls");
			cout << "Congratulations! Access Granted : " << endl;
		}
		else
		{
			system("cls");
			cout << "Access Denied : Enter the credentials again. " << endl;
		}

	}


	read.close();
}


void fdo:: fdo_login_check()
{
	struct Data
	{
		string name, email, password;
	};

	string line, word;
	int i = 0;
	bool flag = false;
	string name, email, password;
	Data v1, v2;
	cout << "Enter email : ";
	cin >> v1.email;
	cout << "Enter password : ";
	cin >> v1.password;

	ifstream read;


	read.open("fdo_credentials.csv");
	if (!read.is_open())
	{
		cout << "Sorry! : " << endl;
		exit(0);
	}

	else
	{
		while (getline(read, line))
		{
			stringstream str(line);

			getline(str, email, ',');
			getline(str, password, '\n');


			v2.email = email;
			v2.password = password;
		}
		if (v2.email == v1.email && v2.password == v1.password)
		{
			flag = true;
		}
		if (flag == true)
		{
			system("cls");
			cout << "Congratulations! Access Granted : " << endl;
		}
		else
		{
			system("cls");
			cout << "Access Denied : Enter the credentials again. " << endl;
		}

	}


	read.close();
}


void government_official::government_officer_check()
{
	struct Data
	{
		string name, email, password;
	};

	string line, word;
	int i = 0;
	bool flag = false;
	string name, email, password;
	Data v1, v2;
	cout << "Enter email : ";
	cin >> v1.email;
	cout << "Enter password : ";
	cin >> v1.password;

	ifstream read;


	read.open("government_officer_credentials.csv");
	if (!read.is_open())
	{
		cout << "Sorry! : " << endl;
		exit(0);
	}

	else
	{
		while (getline(read, line))
		{
			stringstream str(line);

			getline(str, email, ',');
			getline(str, password, '\n');


			v2.email = email;
			v2.password = password;
		}
		if (v2.email == v1.email && v2.password == v1.password)
		{
			flag = true;
		}
		if (flag == true)
		{
			system("cls");
			cout << "Congratulations! Access Granted : " << endl<<endl;
			Sleep(500);
			gov_off_access_to_files();  
		}
		else
		{
			system("cls");
			cout << "Access Denied : Enter the credentials again. " << endl;
		}

	}
	read.close();
}


bool citizen :: citizen_account_signUp_or_logIn()
{
	ifstream readFile;
	int pass, i=1;
	string email, email2, Line,
		First_Name, Last_Name, Email, city, blood_type,
		address, state, Password, Password2, CNIC, line, word, Dob = " ";
	long long int Phone_number = 0;
	bool flag = false;
	cout << "Enter your E-mail address: ";
	cin >> email;
	cout << endl;
	cout << "Enter your E-mail password: ";
	cin >> Password;
	cout << endl << endl;
	readFile.open("citizen_credentials.csv", ios::app);
	if (!readFile.is_open())
	{
		cout << "File is not being opened : " << endl;
		exit(0);
	}
	else
	{
		while (getline(readFile, Line))
		{
			stringstream str(Line);

			getline(str, Email, ',');
			getline(str, Password2, '\n');
		}
		if (email == Email)
		{
			flag = true;
		}

		if (flag == true)
		{
			cout << "Access granted !!" << endl;
		}

		else
		{
			cout << "This Email does not exit !!";
			cout << endl;
			ofstream writeFile1;
			writeFile1.open("citizen_credentials.csv", ios::app);
			cout << "\n\n\t\t\t SIGN UP PAGE\t\t\t\n\n";
			cout << "\nEnter a new Email : ";
			cin >> Email;
			cout << endl;
			cout << "Enter a new password : ";
			cin >> Password;
			cout << endl;
			cout << "Enter First Name : ";
			cin >> First_Name;
			cout << endl;
			cout << "Enter Last Name : ";
			cin >> Last_Name;
			cout << endl;
			cout << "Enter CNIC : ";
			cin >> CNIC;
			cout << endl;
			cin.ignore();
			cout << "Enter City : ";
			cin >> city;
			cout << endl;
			cout << "Enter ADDRESS : ";
			cin.ignore();
			getline(cin, address);
			cout << endl;
			cout << "Enter Blood Type : ";
			cin >> blood_type;
			cout << endl;
			cout << "Enter Date Of Birth   : ";
			cin >> Dob;
			cout << endl;
			writeFile1 << Email << "," << Password << "," << First_Name << ","
				<< Last_Name << "," << CNIC << ","
				<< city << "," << blood_type << "," << Dob << "," << address
				<< "\n";
			system("cls");
			cout << "\t\t\tSign up Details\t\t\t";
			cout << endl;
			cout << "First Name : " << First_Name << "\n\n";
			cout << "Last Name : " << Last_Name << "\n\n";
			cout << "Email : " << Email << "\n\n";
			cout << "CNIC : " << CNIC << "\n\n";
			cout << "City : " << city << "\n\n";
			cout << "Blood Type : " << blood_type << "\n\n";
			cout << "Date of Birth : " << Dob << "\n\n";
			cout << "Address : " << address;
			cout << endl;
		}

		readFile.close();
	}
}


void citizen:: citizen_account_check()
{
	
	citizen_account_signUp_or_logIn();
	
};


	void main_menu::welcome_note()
	{
		cout << "\t\t\t\t enter any key to start program : "; cin >> a;
		system("cls");
		for (int i = 0; i < 2; i++)
		{
			system("Color 8E");
			cout << "\t   :)  \\\\\\        /// |||||||| ||||||| ||||||| ||| |||\\\\\\  ||| |||||||| ||||||||| ||| ||||||| |||\\\\\\  |||         \n";
			cout << "\t   :)   \\\\\\      ///  |||  ||| |||     |||     ||| ||| \\\\\\ ||| |||  |||    |||    ||| ||| ||| ||| \\\\\\ |||         \n";
			cout << "\t   :)    \\\\\\    ///   |||||||| |||     |||     ||| |||  \\\\\\||| ||||||||    |||    ||| ||| ||| |||  \\\\\\|||         \n";
			cout << "\t   :)     \\\\\\  ///    |||  ||| |||     |||     ||| |||     ||| |||  |||    |||    ||| ||| ||| |||     |||         \n";
			cout << "\t   :)      \\\\\\///     |||  ||| ||||||| ||||||| ||| |||     ||| |||  |||    |||    ||| ||||||| |||     |||         \n";
			Sleep(200);
			system("cls");
			system("Color F0");
			cout << "\t   :)  \\\\\\        /// |||||||| ||||||| ||||||| ||| |||\\\\\\  ||| |||||||| ||||||||| ||| ||||||| |||\\\\\\  |||         \n";
			cout << "\t   :)   \\\\\\      ///  |||  ||| |||     |||     ||| ||| \\\\\\ ||| |||  |||    |||    ||| ||| ||| ||| \\\\\\ |||         \n";
			cout << "\t   :)    \\\\\\    ///   |||||||| |||     |||     ||| |||  \\\\\\||| ||||||||    |||    ||| ||| ||| |||  \\\\\\|||         \n";
			cout << "\t   :)     \\\\\\  ///    |||  ||| |||     |||     ||| |||     ||| |||  |||    |||    ||| ||| ||| |||     |||         \n";
			cout << "\t   :)      \\\\\\///     |||  ||| ||||||| ||||||| ||| |||     ||| |||  |||    |||    ||| ||||||| |||     |||         \n";
			Sleep(200);
			system("cls");
		}
		system("Color 8E");
		system("cls");
	}


	void main_menu::account_type()
	{
		while (account_type_choice == 'a' || account_type_choice == 'b' || account_type_choice == 'c' ||
			account_type_choice == 'd' || account_type_choice == 'e' || account_type_choice == 'f')
		{
			cout << "\t\t\t\t enter your account type\n";
			cout << "\t\t\t\t ----------------------------\n\n";
			cout << "a.government officer login        b.super admin login \n\n"
				<< "c.admin login                     d.doctor login \n\n"
				<< "e.fdo login                       f.citizen login\n\n";

			cout << "\n\nAccount type: ";
			bool wrong = true;
			cin >> account_type_choice; cout << "\n\n";
			/*do {
				if (account_type_choice <= 'f') {*/
					switch (account_type_choice)
					{
					case 'a':
						system("cls");
						government_officer_check();
						break;
					case 'b':
						system("cls");
						superadmin_login_check();
						break;
					case 'c':
						system("cls");
						admin_login_check();
						break;
					case 'd':
						system("cls");
						doctor_login_check();
						break;
					case 'e':
						system("cls");
						fdo_login_check();
						break;
					case'f':
						system("cls");
						citizen_account_check();
						break;
					default:
						system("cls");
						cout << "\n\n\t\t\t[!]You have selected wrong choice. \n\t\t\t[!]Please select a valid choice\n\n";
						Sleep(300);
						continue;
					}
				/*}
				else
				{
					cout << "TRY AGAIN<<endl";
					wrong = true;
					cin >> account_type_choice; cout << "\n\n";
				}
			} while (wrong == true);*/
		}

	}

	void gov_off_access_to_files()
	{
		int i = 1;
		string email, email2, password, Line,
			First_Name, Last_Name, Email, city, blood_type,
			address, state, CNIC, line, word, Dob = " ";
		long long int phone_number = 0;

		ifstream read;
		char choice_of_gov_off;
		system("cls");
		cout << "\t\t\t\t ----------------------------\n\n";
		cout << "a.government officer data       b.super admin data \n\n"
			<< "c.admin data                    d.doctor data \n\n"
			<< "e.fdo data                      f.citizen data\n\n";

		cout << "What data you want to access?";
		cin >> choice_of_gov_off;
		system("cls");
		switch (choice_of_gov_off)
		{
		case 'a':
			read.open("government_officer_credentials.csv");
			if (!read.is_open())
			{
				cout << "Sorry! File named''government_officer_credentials.cvs'' cannot be opened" << endl;
				exit(1);
			}

			while (getline(read, line))
			{

				stringstream str(line);

				getline(str, email, ',');
				getline(str, password, '\n');

				cout << "Govt. Officer " << i << " : ";
				cout << email << endl;
				i++;
			}


			read.close();
			break;
		case 'b':
			read.open("super_admin_credentials.csv");
			if (!read.is_open())
			{
				cout << "Sorry! File named''super_admin.csv'' cannot be opened" << endl;
				exit(1);
			}

			while (getline(read, line))
			{

				stringstream str(line);

				getline(str, email, ',');
				getline(str, password, '\n');

				cout << "Super Admin " << i << " : ";
				cout << email << endl;
				i++;
			}


			read.close();
			break;
		case 'c':
			read.open("admin_credentials.csv");
			if (!read.is_open())
			{
				cout << "Sorry! File named''admin_credentials.csv'' cannot be opened" << endl;
				exit(1);
			}

			while (getline(read, line))
			{

				stringstream str(line);

				getline(str, email, ',');
				getline(str, password, '\n');

				cout << "Admin " << i << " : ";
				cout << email << endl;
				i++;
			}


			read.close();
			break;
		case 'd':
			read.open("doctor_credentials.csv");
			if (!read.is_open())
			{
				cout << "Sorry! File named''doctor_credentials.csv'' cannot be opened" << endl;
				exit(1);
			}

			while (getline(read, line))
			{

				stringstream str(line);

				getline(str, email, ',');
				getline(str, password, '\n');

				cout << "Doctor " << i << " : ";
				cout << email << endl;
				i++;
			}


			read.close();
			break;
		
		case 'e':
			read.open("fdo_credentials.csv");
			if (!read.is_open())
			{
				cout << "Sorry! File named''fdo.csv'' cannot be opened" << endl;
				exit(1);
			}

			while (getline(read, line))
			{

				stringstream str(line);

				getline(str, email, ',');
				getline(str, password, '\n');

				cout << "FDO " << i << " : ";
				cout << email << endl;
				i++;
			}


			read.close();
			break;
		case 'f':
			read.open("citizen_credentials.csv");
			if (!read.is_open())
			{
				cout << "Sorry! File named''citizen.csv'' cannot be opened" << endl;
				exit(1);
			}

			while (getline(read, line))
			{

				stringstream str(line);

				getline(str, email, ',');
				getline(str, password, ',');
				getline(str, First_Name, ',');
				getline(str, Last_Name, ',');
				getline(str, CNIC, ',');
				getline(str, city, ',');
				getline(str, blood_type, ',');
				getline(str, Dob, ',');
				getline(str, address, '\n');

				cout << endl;
				
				cout << "Email : " << email << "\n\n";
				cout << "First Name : " << First_Name << "\n\n";
				cout << "Last Name : " << Last_Name << "\n\n";
				cout << "CNIC : " << CNIC << "\n\n";
				cout << "City : " << city << "\n\n";
				cout << "Date of Birth : " << Dob << "\n\n";
				cout << "Address : " << address << "\n\n";
				cout << "Blood Type : " << blood_type << "\n\n";
				
				cout << "\n"
					<< "======================================="
					<< "======================================="
					<< "\n";

				i++;
			}


			read.close();
			break;
		default:
			cout << "Kuch nahi vro : " << endl;
			break;
		}
	}