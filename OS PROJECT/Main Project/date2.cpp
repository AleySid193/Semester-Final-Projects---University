#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <cstring>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;
int getch() {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}
int main(int argc, char* argv[]) {
    int opt;

    do {
        // Get the current system time
        auto now = std::chrono::system_clock::now();

        // Convert the system time to a time_t object
        time_t current_time = std::chrono::system_clock::to_time_t(now);

        // Convert the time_t object to a string representation
        char time_str[100];
        string date_var, time_var;
        struct tm timeinfo;
        localtime_r(&current_time, &timeinfo);
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", &timeinfo);

        // Display the current system time
        for (int i = 0; i < 10; i++) {
            date_var += time_str[i];
        }
        for (int i = 11; i < 19; i++) {
            time_var += time_str[i];
        }

        system("clear");
        cout << "1) Display Current Time" << endl;
        cout << "2) Display Current Date" << endl;
        cout << "3) Exit" << endl;
        cout << "Enter Here : ";
        cin >> opt;
        system("clear");
        switch (opt) {
        case 1: {
            cout << "The Current System Time Is : " << time_var << endl;
            cout << "Press Enter To Continue!" << endl;
			char ok;
			cin >> ok;
            break;
        }
        case 2: {
            cout << "The Current System Date Is : " << date_var << endl;
            cout << "Press Enter To Continue!" << endl;
			char ok;
			cin >> ok;
            break;
        }
        case 3: {
            cout << "Exiting..." << endl;
            cout << "Press Enter To Continue!" << endl;
			char ok;
			cin >> ok;
            break;
        }
        default: {
            cout << "Invalid Input!" << endl;
            cout << "Press Any Key To Continue!" << endl;
            cout << "Press Enter To Continue!" << endl;
			string ok;
			cin >> ok;
            break;
        }
        }
    } while (opt != 3);
    int x = atoi(argv[1]);
    mkfifo("mypipe", 0666);

     int fd = open("mypipe", O_WRONLY);
    write(fd, &x, sizeof(x));
	close(fd);
    return 0;
}