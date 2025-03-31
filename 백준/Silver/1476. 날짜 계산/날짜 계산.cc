#include <iostream>

int main(){
    int earth, sun, moon;
    std::cin >> earth >> sun >> moon;

    int earthYear = 1, sunYear = 1, moonYear = 1, realYear = 1;
    while (earthYear != earth || sunYear != sun || moonYear != moon) {
        earthYear = (earthYear == 15) ? 1 : earthYear + 1;
        sunYear = (sunYear == 28) ? 1 : sunYear + 1;
        moonYear = (moonYear == 19) ? 1 : moonYear + 1;
        realYear++;
    }

    std::cout << realYear;
}