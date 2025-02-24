#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int b[3] = {3,7,8};
    int* p = &a;
    int* q = b;
    cout << "This is the value of variable a, (it was initialized to zero) " << a << "\n";
    cout << "This is the address of variable 'a' " << p << "\n";
    cout << "We stored this address in a pointer variable.. int* p, which we can access using 'p'\n";
    cout << "Using '*p' instead of 'p', we can change the value of 'a'\n";
    cout << "This is dereferencing!\n";
    cout << "What number should we change 'a' to??\n";
    cin >> *p;
    cout << "Now we print the value stored at 'a', which should be the number you provided!\n";
    cout << "Variable 'a' is now..." << a << "\n";
    cout << "We can take this a step further by using an array and pointer arithmetic!\n";
    cout << "If we have an array of 3 values 'b'\n";
    cout << "we can increment the address of the first letter to find the others!\n";
    cout << "Here's the address of the first letter in a pointer variable 'q'\n";
    cout << "\n";
    int increment = sizeof(b)/sizeof(b[0]);
    int i = 0;
    while (i < increment) {

        cout << "Address of array in pointer variable 'q'  " << q+i << "\n" ;
        cout << "Array slot " <<  i  << "  Value " << *(q+i) << "\n";
        i++;
    }
    return 0;
}