//Moises PC

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

// Function 1: Decimal to Binary
string decimalToBinary(int decimal){
    if(decimal == 0) return "0";
    int binary = 0;
    int remainder;
    int position = 1;
    
    while(decimal!= 0){
        remainder = decimal % 2;
        binary = binary + remainder * position;
        position = position * 10;
        decimal = decimal / 2;
    }
    return to_string(binary);
}

// Function 2: Binary to Decimal
int binaryToDecimal(string binary_value){
    int binary = stoi(binary_value);
    int decimal = 0;
    int remainder;
    int position = 1;
    
    while(binary!= 0){
        remainder = binary % 10;
        decimal = decimal + remainder * position;
        position = position * 2;
        binary = binary / 10;
    }
    return decimal;
}

// Function 3: Decimal to Hexadecimal 
string decimalToHexadecimal(int decimal){
    if(decimal == 0) return "0";
    string hex_chars = "0123456789ABCDEF";
    string hexadecimal = "";
    int remainder;
    
    while(decimal!= 0){
        remainder = decimal % 16;
        hexadecimal = hex_chars[remainder] + hexadecimal;
        decimal = decimal / 16;
    }
    return hexadecimal;
}

// Function 4: Hexadecimal to Decimal 
int hexadecimalToDecimal(string hex_value){
    int decimal = 0;
    int position = 1;
    for(int i=0; i<hex_value.length(); i++){
        if(hex_value[i] >= 'a' && hex_value[i] <= 'f') hex_value[i] = hex_value[i] - 32;
    }
    for(int i = hex_value.length()-1; i >=0; i--){
        int digit;
        if(hex_value[i] >= '0' && hex_value[i] <= '9') digit = hex_value[i] - '0';
        else digit = hex_value[i] - 'A' + 10;
        decimal = decimal + digit * position;
        position = position * 16;
    }
    return decimal;
}

int main(){
	
    srand(time(0));
    int choice = 0;
    int decimal_num;
    string input_value;

    while(choice!= 6){
        cout << "\n Conversion Menu:" << endl;
        cout << "1. Convert Decimal to Binary" << endl;
        cout << "2. Convert Binary to Decimal" << endl;
        cout << "3. Convert Hexadecimal to Decimal" << endl;
        cout << "4. Convert Decimal to Hexadecimal" << endl;
        cout << "5. Demo (Generate and convert random integers to binary)" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        if(choice == 1){
            cout << "Enter a decimal number: ";
            cin >> decimal_num;
            cout << "Binary representation: " << decimalToBinary(decimal_num) << endl;
        }
        if(choice == 2){
            cout << "Enter a binary number: ";
            cin >> input_value;
            cout << "Decimal representation: " << binaryToDecimal(input_value) << endl;
        }
        if(choice == 3){
            cout << "Enter a hexadecimal number: ";
            cin >> input_value;
            cout << "Decimal representation: " << hexadecimalToDecimal(input_value) << endl;
        }
        if(choice == 4){
            cout << "Enter a decimal number: ";
            cin >> decimal_num;
            cout << "Hexadecimal representation: " << decimalToHexadecimal(decimal_num) << endl;
        }
        if(choice == 5){
            int rand_num = rand() % 100;
            cout << "Generated random integer: " << rand_num << endl;
            cout << "Binary representation: " << decimalToBinary(rand_num) << endl;
        }
        if(choice == 6){
            cout << "Exiting the program." << endl;
        }
    }
    return 0;
}
