#include <stdio.h>
int collatz_Length(long long int number) {
    int length=1;
    while ( number != 1) {
        if (number % 2 == 0) {
            number/= 2;
        } else {
            number = number * 3 + 1;
        }
        length++;
    }
    return length;
}

void longest_Sequence(long long int limit) {
    long long int max_Number = 1;
    int max_Length = 1;
    for (long long int a = 2; a< limit; a++) {
        int length = collatz_Length(a);
        if (length > max_Length) {
            max_Length = length;
            max_Number = a;
        }
    }
    printf("Starting number: %lld \n", max_Number);
    printf("Length of the longest Collatz sequence: %d\n", max_Length);
}

int main() {
    long long int n;
    printf("Enter the upper limit N: ");
    scanf("%lld", &n);
    longest_Sequence(n);
    return 0;
}
