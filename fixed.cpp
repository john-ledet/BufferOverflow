#include <iostream>
#include <stdio.h>
#include <cstring>


using namespace std;

void secretfunc() {
    cout << "Congratulations you caused a buffer overflow!" << endl;
}

//function that checks secret trigger that is besides buffer in memory; if an overflow occurs secret won't be 0 and will print out the secret message
void bof() {
    char buffer[5];
    int secret = 0;     
    
    cout << "Enter input: ";
    cin.get(buffer, sizeof(buffer)); //gets the input and saves it within the allowed buffer space, null terminating any characters that cause an overflow
    cout << endl;
    
    if (secret != 0) {
        secretfunc();
    }
    else {
        cout << "Input is safe, no buffer overflow." << endl;
    }
}

int main() {
    bof();
    return 0;
}