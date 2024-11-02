#include <iostream>
#include <vector>

bool isRectangleOverlap(const std::vector<int>& rec1, const std::vector<int>& rec2) {
    // Check if one rectangle is to the left, right, above, or below the other
    return !(rec1[2] <= rec2[0] || // rec1 is to the left of rec2
             rec1[0] >= rec2[2] || // rec1 is to the right of rec2
             rec1[3] <= rec2[1] || // rec1 is below rec2
             rec1[1] >= rec2[3]);  // rec1 is above rec2
}

int main() {
    // Example 1
    std::vector<int> rec1 = {0, 0, 2, 2};
    std::vector<int> rec2 = {1, 1, 3, 3};
    std::cout << "Example 1 Output: " << (isRectangleOverlap(rec1, rec2) ? "true" : "false") << std::endl;

    // Example 2
    rec1 = {0, 0, 1, 1};
    rec2 = {1, 0, 2, 1};
    std::cout << "Example 2 Output: " << (isRectangleOverlap(rec1, rec2) ? "true" : "false") << std::endl;

    // Example 3
    rec1 = {0, 0, 1, 1};
    rec2 = {2, 2, 3, 3};
    std::cout << "Example 3 Output: " << (isRectangleOverlap(rec1, rec2) ? "true" : "false") << std::endl;

    return 0;
}
