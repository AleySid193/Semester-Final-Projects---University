#include <iostream>
#include <cmath>
#include <unistd.h>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

int countDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

bool isArmstrong(int number) {
    int originalNumber = number;
    int digitCount = countDigits(number);
    int sum = 0;

    while (number != 0) {
        int digit = number % 10;
        sum += pow(digit, digitCount);
        number /= 10;
    }

    return (sum == originalNumber);
}

int main(int argc, char* argv[]) {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isArmstrong(number)) {
        cout << number << " is an Armstrong number." << endl;
    } else {
        cout << number << " is not an Armstrong number." << endl;
    }
    sleep(5);
    int x = atoi(argv[1]);
    mkfifo("mypipe", 0666);

     int fd = open("mypipe", O_WRONLY);
    write(fd, &x, sizeof(x));
	close(fd);
    return 0;
}