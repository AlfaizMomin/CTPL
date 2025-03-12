#include <iostream>
#include <cstdlib>
using namespace std; // MISRA-CPP2008-2-13-3: Using 'using namespace std;' is not allowed.

#define MAGIC_NUMBER 42 // MISRA-CPP2008-4-10-2: Use of a magic number as a macro.

void process(int x);

void process(int x) {
    if (x = MAGIC_NUMBER) { // MISRA-CPP2008-6-4-1: Use of assignment in condition.
        cout << "Matched!" << endl;
    }
    int arr[10];
    int y = arr[x]; // MISRA-CPP2008-6-4-2: Using an out-of-bounds index (x can be any value).
}

int some_function() {
    return rand(); // MISRA-CPP2008-6-4-4: Using a non-constant value in return.
}

class Base {
public:
    virtual void show() = 0; // MISRA-CPP2008-9-5-1: Pure virtual function without an implementation.
};

class Derived : public Base {
public:
    void show() { cout << "Derived" << endl; } // MISRA-CPP2008-11-0-1: Missing 'override' keyword.
};

void risky_pointer_usage() {
    int* ptr = (int*)malloc(sizeof(int)); // MISRA-CPP2008-18-0-3: Using malloc instead of new.
    *ptr = 10;
    free(ptr); // MISRA-CPP2008-18-0-5: Mixing C-style memory management in C++.
}

void pointer_arithmetic() {
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    ptr += 3; // MISRA-CPP2008-18-7-1: Pointer arithmetic is not allowed.
}

void macro_function(int a) {
#define MULTIPLY(x) ((x) * 2) // MISRA-CPP2008-19-3-1: Function-like macros should be avoided.
    int result = MULTIPLY(a);
    cout << "Result: " << result << endl;
}

void risky_cast() {
    int x = 10;
    double* ptr = reinterpret_cast<double*>(&x); // MISRA-CPP2008-27-0-1: Dangerous use of reinterpret_cast.
    cout << *ptr << endl;
}

int main() {
    process(5);
    Derived d;
    d.show();
    risky_pointer_usage();
    pointer_arithmetic();
    macro_function(10);
    risky_cast();
    return 0;
}
