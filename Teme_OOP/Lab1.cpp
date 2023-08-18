#include <iostream>

//this function checks if a number given as an argument is prime or not
bool isPrime(int a) {
    if (a == 0 || a == 1)
        return false;
    for (int d = 2; d * d <= a; d++)
        if (a % d == 0)
            return false;
    return true;

}

//the first n pairs of prime numbers which have the difference between them equal to 2
void punkt_a() {
    int n;
    int number1 = 1, number2 = 3, count = 0;
    std::cout << "8. a)" << std::endl;
    std::cout << "Gib die Anzahl der Zwillingspaaren ein:";
    std::cin >> n;
    while (count < n) {
        if (isPrime(number1) && isPrime(number2) && number2 - number1 == 2) {
            std::cout << "(" << number1 << "," << number2 << ")\n";
            count++;
        }
        number1++;
        number2++;
    }
    std::cout << std::endl;
}

//the longest sequence of deacreasing numbers
void punkt_b() {
    int n;
    std::cout << "8. b)" << std::endl;
    std::cout << "Gib die Lange des Zahlenvektors ein:";
    std::cin >> n;

    int l[n];

    for (int i = 0; i < n; i++) {
        std::cout << "l[" << i << "]:";
        std::cin >> l[i];
    }

    int current_longest = 1;
    int longest = 1;
    int end_index = 0;

    //in this for loop we determine the longest sequence of decreasing numbers, as well as the end index for this specific sequence
    for (int i = 0; i < n - 1; i++) {
        if (l[i] > l[i + 1]) {
            current_longest++;
        } else {
            if (current_longest > longest) {
                longest = current_longest;
                end_index = i;
            }
            current_longest = 1;
        }
    }

    //we verify here if the last sequence that has been determined is eligible to be the longest
    if (current_longest > longest) {
        longest = current_longest;
        end_index = n - 1;
    }

    std::cout << "Die erhaltene Sequenz ist: ";
    //instead of working with a start index, we use the differnece between end index and longest sequence to determine the start of the iteration
    for (int i = end_index - longest + 1; i <= end_index; i++) {
        std::cout << l[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    punkt_a();
    punkt_b();

    return 0;
}
