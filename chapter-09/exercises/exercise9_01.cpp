/*
    Define a lambda expression to find the largest even number
    in a vector of non-zero elements of type int. Demonstrate its use
    in a suitable test program.
*/
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

template <typename G, typename R>
void reportNumbersStats(
    G numGetter,
    const string message,
    R reducer)
{
    vector<int> nums{};
    numGetter(nums);
    int num{reducer(nums)};
    std::cout << message << ": " << num << std::endl;
}

void readNumbers(vector<int> &nums);

int main()
{
    auto getter = [](vector<int> &nums)
    {
        readNumbers(nums);
    };
    auto reducer = [](const vector<int> &nums) -> int
    {
        if (!nums.size())
            return 0;
        int max{nums[0]};
        for (size_t i{1}; i < nums.size(); ++i)
        {
            if (nums[i] > max)
                max = nums[i];
        }
        return max;
    };

    reportNumbersStats(getter, "The largest number is", reducer);
}

void readNumbers(vector<int> &nums)
{
    std::cout << "Enter non-zero integers, or 0 to finish: ";
    int num{};
    while (true)
    {
        std::cin >> num;
        if (!num)
            break;
        nums.push_back(num);
    }
}
