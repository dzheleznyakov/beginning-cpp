/*
    Average speed in kilometers:
    Assume that a runner runs 24 miles in 1 hour, 40 minutes and 35 seconds.
    Write a program that displays the average speed in kilometers per hour.
    (Note 1 mile is equal to 1.6 kilometers)
*/
#include <iostream>

int main()
{
    const double KMS_PER_MILE{1.6};
    double time_hrs{1.0 + 40.0 / 60 + 35.0 / 3600};
    int distance_in_miles{24};
    double distance_in_kms{distance_in_miles * KMS_PER_MILE};
    double avg_speed{distance_in_kms / time_hrs};
    std::cout << "The average speed of the runner is " << avg_speed << " kph." << std::endl;
}
