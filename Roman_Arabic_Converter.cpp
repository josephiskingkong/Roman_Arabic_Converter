/***********************************
*                                  *
*          Perelygin Egor          *
*              PI-221              *
*    Roman and Arabic converter    *
*                                  *
************************************/


#include <iostream>
#include <string>

using namespace std;

void fromArabicToRoman(int inputArabicNumber) {
    
    const string unitsRoman[10] = {
        "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"
    },
    tensRoman[10] = {
        "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"
    },
    hundredsRoman[10] = {
        "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
    };
    
    int units = inputArabicNumber % 10;
    int tens = inputArabicNumber % 100 / 10;
    int hundreds = inputArabicNumber % 1000 / 100;
    int thousands = inputArabicNumber / 1000;
    
    string thousandsRoman = "";
	
	for (int thousandsCounter = thousands; thousandsCounter > 0; --thousandsCounter) {
		thousandsRoman += "M";
	} 
    cout << "Arabic " << inputArabicNumber << " is Roman " << thousandsRoman << hundredsRoman[hundreds] << tensRoman[tens] << unitsRoman[units] << endl << '\n';        
}

void fromRomanToArabic(string inputRomanNumber) {
    
    int n = int(inputRomanNumber.length());

    int result = 0;
    for (int i = 0; i < n; i++) {
        switch (inputRomanNumber[i]) {
            case 'I':
                result += 1;
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                result += 10;
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                result += 100;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
        }
    }

    for (int i = 1; i < n; i++) {
        
        
        if ((inputRomanNumber[i] == 'V' || inputRomanNumber[i] == 'X' || inputRomanNumber[i] == 'L' || 
        inputRomanNumber[i] == 'C' || inputRomanNumber[i] == 'D' || inputRomanNumber[i] == 'M') && inputRomanNumber[i - 1] == 'I') {
            result -= 1 + 1;
        }
        
        if ((inputRomanNumber[i] == 'X' || inputRomanNumber[i] == 'L' || inputRomanNumber[i] == 'C' || 
        inputRomanNumber[i] == 'D' || inputRomanNumber[i] == 'M') && inputRomanNumber[i - 1] == 'V') {
            result -= 5 + 5;
        }
        
        if ((inputRomanNumber[i] == 'L' || inputRomanNumber[i] == 'C' || inputRomanNumber[i] == 'D' || 
        inputRomanNumber[i] == 'M') && inputRomanNumber[i - 1] == 'X') {
            result -= 10 + 10;
        }
        
        if ((inputRomanNumber[i] == 'C' || inputRomanNumber[i] == 'D' || inputRomanNumber[i] == 'M') && inputRomanNumber[i - 1] == 'L') {
            result -= 50 + 50;
        }

        if ((inputRomanNumber[i] == 'D' || inputRomanNumber[i] == 'M') && inputRomanNumber[i - 1] == 'C') {
            result -= 100 + 100;
        }
        
        if ((inputRomanNumber[i] == 'M') && inputRomanNumber[i - 1] == 'D') {
            result -= 500 + 500;
        }
    }
    cout << "Roman " << inputRomanNumber << " is Arabic " << result << endl;
}

int main() {
    int inputArabicNumber;
    string inputRomanNumber;
    int choice;
    
    cout << "Enter 1 if you want to convert Arabic numeral in Roman. Else enter 0 : ";
    cin >> choice;
    
    if (choice == 1 || choice == 0) {
        
		if (choice == 1) {
        	cout << "Enter Arabic number which you want to convert : ";
    	    cin >> inputArabicNumber;
    	    fromArabicToRoman(inputArabicNumber);
	    }
	    if (choice == 0) {
	    	cout << "Enter Roman number which you want to convert : ";
        	cin >> inputRomanNumber;
        	fromRomanToArabic(inputRomanNumber);
	    }
    } else {
		cout << "Incorrect input.";
		return 0;
	}
	system("pause");
}

