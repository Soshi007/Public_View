#include <iostream>
#include "Float_Number.h"
#include <stdexcept>

using namespace std;

int main(){
  
    FloatNumber num1(5, 123456);  // 5.123456
    FloatNumber num2(3, 654321);  // 3.654321
    FloatNumber num3;
    
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;


    FloatNumber sum = num1 + num2;
    cout << "Sum: " << sum << endl;


    FloatNumber diff = num1 - num2;
    cout << "Difference: " << diff << endl;

    FloatNumber product = num1 * num2;
    cout << "Product: " << product << endl;


    try {
        FloatNumber quotient = num1 / num2;
        cout << "Quotient: " << quotient << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

 
    cout << "Is num1 > num2? " << (num1 > num2 ? "Yes" : "No") << endl;
    cout << "Is num1 < num2? " << (num1 < num2 ? "Yes" : "No") << endl;
    cout << "Is num1 == num2? " << (num1 == num2 ? "Yes" : "No") << endl;


    num1 += num2;
    cout << "After num1 += num2: " << num1 << endl;

   
    num1 -= num2;
    cout << "After num1 -= num2: " << num1 << endl;

    ++num1;
    cout << "After ++num1: " << num1 << endl;

    num1++;
    cout << "After num1++: " << num1 << endl;

    --num1;
    cout << "After --num1: " << num1 << endl;

    num1--;
    cout << "After num1--: " << num1 << endl;

    cout << "Integer part of num1: " << num1[0] << endl;
    cout << "Decimal part of num1: " << num1[1] << endl;

    cout << "Enter a new FloatNumber:" << endl;
    cin >> num3;
    cout << "You entered: " << num3 << endl;

    return 0;
}
