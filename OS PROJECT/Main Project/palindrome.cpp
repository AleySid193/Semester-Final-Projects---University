#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main(int argc, char* argv[]) {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    sleep(5);
    int x = atoi(argv[1]);
    mkfifo("mypipe", 0666);

     int fd = open("mypipe", O_WRONLY);
    write(fd, &x, sizeof(x));
	close(fd);
    return 0;
}
