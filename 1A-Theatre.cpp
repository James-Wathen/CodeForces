#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    // n m size paved with sizes a a
    // look at x and y seperately, product of how much a fits into each m and n
    string input;
    cout << "enter values for 'n', 'm' and 'a' seperated by spaces: ";
    getline(cin, input);// input of form n,m,a
    int L = input.length();
    int n, m, a;
    int variable = 0;
    string numberBuild = "";
    for (int i = 0; i <= L; i++)
    {
        if (input[i]!=' ' && input[i] != '\0')
        {
            numberBuild = numberBuild + input[i];
        }
        else if (input[i] == ' ' || input[i] == '\0')// char==',' so x = full number
        {
            variable++;// we can put x into the next variable now
            cout << "Var: " << variable << " is " << numberBuild << endl;
            if (variable==1)
                n = stoi(numberBuild);//to int
            else if (variable == 2)
                m = stoi(numberBuild);
            else if (variable == 3)
                a = stoi(numberBuild);
            numberBuild = "";
        }
        else
            cout << "non integer or space character detected" << endl;
    }
    cout << "n,m,a: " << n << ", " << m << ", " << a << endl;
    float x = ceil((float)n/a);// ceil is the rounded up (2.4->3) of the fraction, because we cannot divide up the rectangle by a (splitting up squares of a*a)
    float y = ceil((float)m/a);// This is because, we want upper bound of x and y before multiplying them, we cannot get the same result by upper bound of (n*m)/a
    float no = y*x;
    cout << "the rectangle can be covered by " << no << " squares of length a: " << a << endl;
}