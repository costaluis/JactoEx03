#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Solution {
    static inline int calculateNewMaxArea(const int height, const int length, const int oldMaxArea) {
        const int newAreaValue = height * length;
        return (newAreaValue > oldMaxArea) ? newAreaValue : oldMaxArea;
    }

public:
    static int maxArea(const std::vector<int>& height) {
        if (height.size() < 2) {
            return 0;
        }

        int p1 = 0;
        int p2 = static_cast<int>(height.size()) - 1;
        int maxAreaValue = -1;

        while (p1 != p2) {
            if (height[p1] < height[p2]) {
                maxAreaValue = calculateNewMaxArea(height[p1], (p2 - p1), maxAreaValue);
                p1++;
            } else {
                maxAreaValue = calculateNewMaxArea(height[p2], (p2 - p1), maxAreaValue);
                p2--;
            }
        }

        return maxAreaValue;
    }
};

int main() {
    std::string line;
    int number;
    std::vector<int> numbers;

    std::cout << "Insira as alturas: " << std::endl;
    std::getline(std::cin, line);
    std::istringstream iss(line);

    while (iss >> number) {
        numbers.push_back(number);
    }

    const auto result = Solution::maxArea(numbers);

    std::cout << result << std::endl;

    return 0;
}
