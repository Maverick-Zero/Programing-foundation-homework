#include <iostream>
#include <string>
using namespace std;

// Function to add two binary numbers
string addBinary(string a, string b) {
    string result = "";  // Store the sum as a binary string
    int carry = 0;  // Carry for binary addition
    int i = a.size() - 1, j = b.size() - 1;  // Indices to traverse both strings

    // Loop through the binary strings from right to left
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        
        // Add bit from the first binary number
        if (i >= 0) {
            sum += a[i] - '0';  // Convert character to integer
            i--;
        }
        
        // Add bit from the second binary number
        if (j >= 0) {
            sum += b[j] - '0';  // Convert character to integer
            j--;
        }

        // Compute the result bit (sum % 2) and update the carry (sum / 2)
        result = char(sum % 2 + '0') + result;
        carry = sum / 2;
    }

    return result;
}

int main() {
    string bin1, bin2;

    // Inform the user what the program does
    cout << "This program adds two binary numbers.\n";

    // Ask the user to input the first binary number
    cout << "Please enter the first binary number: ";
    cin >> bin1;

    // Ask the user to input the second binary number
    cout << "Please enter the second binary number: ";
    cin >> bin2;

    // Call the function to add the binary numbers and store the result
    string sum = addBinary(bin1, bin2);

    // Output the result with a comment
    cout << "\nThe sum of the two binary numbers is: " << sum << endl;

    return 0;
}
