#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

std::string kthDistinct(const std::vector<std::string>& arr, int k) {
    std::unordered_map<std::string, int> countMap;
    
    // Count occurrences of each string
    for (const auto& str : arr) {
        countMap[str]++;
    }
    
    // Find the k-th distinct string
    for (const auto& str : arr) {
        if (countMap[str] == 1) {
            k--;
            if (k == 0) {
                return str;
            }
        }
    }
    
    // If there are fewer than k distinct strings
    return "";
}

int main() {
    std::vector<std::string> arr1 = {"d", "b", "c", "b", "c", "a"};
    int k1 = 2;
    std::cout << "Example 1 Output: " << kthDistinct(arr1, k1) << std::endl; // Output: "a"

    std::vector<std::string> arr2 = {"aaa", "aa", "a"};
    int k2 = 1;
    std::cout << "Example 2 Output: " << kthDistinct(arr2, k2) << std::endl; // Output: "aaa"

    std::vector<std::string> arr3 = {"a", "b", "a"};
    int k3 = 3;
    std::cout << "Example 3 Output: " << kthDistinct(arr3, k3) << std::endl; // Output: ""

    return 0;
}
