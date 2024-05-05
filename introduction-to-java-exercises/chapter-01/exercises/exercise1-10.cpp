/*
    Average speed in miles:
    Assume that a runner runs 15 kilometers in 50 minutes
    and 30 seconds. Write a program that displays the average speed
    in miles per hour.
*/
#include <iostream>

int main()
{
    double distance_in_km{15};
    double minutes{50};
    double seconds{30};
    double total_minutes{minutes + seconds / 60};
    double total_hours{total_minutes / 60};

    const double km_per_mile{1.6};
    double distance_in_m{distance_in_km / km_per_mile};

    std::cout << "The average speed is " << (distance_in_m / total_hours)
              << " miles per hour." << std::endl;
}
