#include <iostream>
#include <vector>

std::vector<int> getRow(int rowIndex) {
    std::vector<int> row = {1}; // Start with the first row [1]

    for (int i = 1; i <= rowIndex; ++i) {
        // Generate the next row based on the current row
        std::vector<int> newRow(i + 1, 1); // Initialize with 1s
        for (int j = 1; j < i; ++j) {
            newRow[j] = row[j - 1] + row[j]; // Sum of two elements above
        }
        row = newRow; // Update row to the new row
    }

    return row;
}

int main() {
    int rowIndex;
    std::cout << "Enter row index: ";
    std::cin >> rowIndex;

    std::vector<int> result = getRow(rowIndex);
    std::cout << "Output: [ ";
    for (int num : result) std::cout << num << " ";
    std::cout << "]" << std::endl;

    return 0;
}
