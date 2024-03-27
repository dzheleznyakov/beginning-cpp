/*
    Write a program that will read and store an arbitrary sequence of records
    relating to products. Each record includes three items of data -
    an integer product number, a quantity, and a unit price,
    such as a product number 1001, the quantity is 25,
    and the unit price is £9.95. The program should output each product
    on a separate line and include the total cost. The last line should
    output the total cost for all products. Columns should align.
*/
#include <iomanip>
#include <iostream>
#include <vector>

int main()
{
    std::vector<unsigned int> products{};
    std::vector<unsigned int> quantities{};
    std::vector<double> prices{};

    unsigned int next_product{};
    unsigned int next_quantity{};
    double next_price{};

    do
    {
        std::cout << "Enter the next product number, its quantity and price (or 0 to end): ";
        std::cin >> next_product;
        if (next_product == 0)
            break;
        std::cin >> next_quantity;
        std::cin >> next_price;
        products.push_back(next_product);
        quantities.push_back(next_quantity);
        prices.push_back(next_price);
    } while (true);

    std::cout << "\n-------------------------------------------";
    std::cout << "\nProduct   Quantity   Unit Price   Cost     ";
    std::cout << "\n-------------------------------------------";

    double total_price{};
    for (std::vector<unsigned int>::size_type i{}; i < products.size(); ++i)
    {
        double cost{prices.at(i) * quantities.at(i)};
        total_price += cost;
        std::cout << '\n'
                  << std::left << std::setw(10) << products.at(i)
                  << std::setw(11) << quantities.at(i)
                  << std::setprecision(2) << std::fixed
                  << "£" << std::setw(12) << prices.at(i)
                  << "£" << cost;
    }

    std::cout << '\n'
              << std::right
              << std::setw(36) << "£" << total_price;
    std::cout << std::endl;
}