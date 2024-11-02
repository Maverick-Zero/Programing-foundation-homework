#include <iostream>
#include <vector>
#include <list>

std::vector<std::vector<int>> spiralMatrix(int m, int n, const std::list<int>& linkedList) {
    // Initialize m x n matrix filled with -1
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n, -1));
    
    // Iterator for the linked list
    auto it = linkedList.begin();

    // Define boundaries for spiral traversal
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    
    // Traverse in spiral order
    while (top <= bottom && left <= right && it != linkedList.end()) {
        // Traverse from left to right
        for (int j = left; j <= right && it != linkedList.end(); ++j) {
            matrix[top][j] = *it;
            ++it;
        }
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom && it != linkedList.end(); ++i) {
            matrix[i][right] = *it;
            ++it;
        }
        right--;

        // Traverse from right to left
        for (int j = right; j >= left && it != linkedList.end(); --j) {
            matrix[bottom][j] = *it;
            ++it;
        }
        bottom--;

        // Traverse from bottom to top
        for (int i = bottom; i >= top && it != linkedList.end(); --i) {
            matrix[i][left] = *it;
            ++it;
        }
        left++;
    }
    
    return matrix;
}

int main() {
    // Example 1
    int m1 = 3, n1 = 5;
    std::list<int> linkedList1 = {3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0};
    std::vector<std::vector<int>> result1 = spiralMatrix(m1, n1, linkedList1);

    std::cout << "Example 1 Output:\n";
    for (const auto& row : result1) {
        for (int num : row) std::cout << num << " ";
        std::cout << "\n";
    }

    // Example 2
    int m2 = 1, n2 = 4;
    std::list<int> linkedList2 = {0, 1, 2};
    std::vector<std::vector<int>> result2 = spiralMatrix(m2, n2, linkedList2);

    std::cout << "Example 2 Output:\n";
    for (const auto& row : result2) {
        for (int num : row) std::cout << num << " ";
        std::cout << "\n";
    }

    return 0;
}
