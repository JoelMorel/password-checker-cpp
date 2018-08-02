//  Created by Joel Morel on 4/23/18.
//  Copyright © 2018 Joel Morel. All rights reserved.
//

#include <iostream>
using namespace std;

class passwordChecker
{
public:
    string password = "";
    string secondPassword = "";
    int passwordLength = 0;
    bool validYesNo = false;
    bool matchYesNo = false;
    
    int charCount[5];   //    an 1D integer array to store the counts of each of the password ruls:
                        //    charCount[0] store the count of illegal special characters
                        //    charCount[1] store the count of numeric
                        //    charCount[2] store the count of lower case characters
                        //    charCount[3] store the count of upper case characters
                        //    charCount[4] store the count of legal special characters
                        //    intialize to zero
    
    
    passwordChecker()
    {
        do
        {
            for(int i = 0; i < 5; i++)
            {
                charCount[i] = 0;
            }
            
            displayRules();
            askUser4passwd();
            
            int index = 0;
            for(int i = 0; i < passwordLength; i++)
            {
                index = checkOneChar(password[i]);
                if(index >= 0 && index <= 4)
                {
                    charCount[index]++;
                }
            }
        
        // step 8: validYesNo <-- checkRules()
            validYesNo = checkRules();
            cout << "valid: " << validYesNo << endl;
            if(validYesNo)
            {
                msg("Please enter the password again: ");
                cin >> secondPassword;
                matchYesNo = matching(password, secondPassword);
                if(matchYesNo)
                {
                    displaySucess();
                }
                else
                {
                    displayMatchFail();
                    validYesNo = false; // set it back to false to repeat process again
                }
            }
            }
        while(!validYesNo);
        
    }
    
    void displayRules()
    {
        cout << "Hello you are to create a new password following these rules: " << endl;
        cout << "1) The password length: 8-32 characters" << endl;
        cout << "2) At least one numerical, i.e., 0, 1, 2,.." << endl;
        cout << "3) At least one upper case letter, i.e., A, B, C, ..." << endl;
        cout << "4) At least one lower case letter, i.e., a, b, c, ..." << endl;
        cout << "5) At least one of the special characters, but it must be within the set:{ # $ * ( ) % & ^} a total of eight (8) special characters. no other special characters are allowed." << endl;
    }
    
    void askUser4passwd ()
    {
        do
        {
            msg("Please enter your password :");
            cin >> password;
            passwordLength = password.length();
        }
        while(passwordLength < 8 || passwordLength > 32);
    }
    
    void displaySucess()
    {
        msg("your password will be updated in 2 minutes.");
    }
    
    void displayFail()
    {
        msg("your password failed one or more password rules");
    }
    
    
    void displayMatchFail()
    {
        msg("match failed...");
    }
    
    int checkOneChar (char chr)
    {
        int ascii = (int) chr;
        
        if(ascii >= 48 && ascii <= 57) // is the char a number
            return 1;
        else if(ascii >= 97  && ascii <= 122) // is the char a lowercaser letter
            return 2;
        else if(ascii >= 65  && ascii <= 90) // is the char a uppercase letter
            return 3;
        else if(isSpecialCharLegal(ascii))
            return 4;
        else
            return 0;
    }
    
    bool checkRules()
    {
        if(charCount[0] > 0)
        {
            return false;
        }
        else
        {
            for(int i = 1; i < 5; i++)
            {
                if(charCount[i] == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool matching(string s1, string s2)
    {
        if(s1.compare(s2) == 0)
        {
            return true;
        }
        else
        return false;
       
    }
    
    bool isSpecialCharLegal(int ascii)
    {
        if(ascii == 35 || ascii == 36 || ascii == 37 || ascii == 38 || ascii == 40 || ascii == 40 || ascii == 41 || ascii == 94)
        {
            return true;
        }
        else return false;
    }
    
    void msg(string msg)
    {
        cout << msg << endl;
    }

};

int main(int argc, const char * argv[])
{
    passwordChecker* newObj = new passwordChecker;

    return 0;
}
