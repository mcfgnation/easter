#include <iostream>

int calculateEaster(int year)
{
    int goldenNumber = (year % 19) + 1;
    int century = year / 100 + 1;
    int skippedLeapYears = (3 * century) / 4 - 12;
    int moonCorrection = ((8 * century + 5) / 25) - 5;
    int sunday = (5 * year / 4) - skippedLeapYears - 10;
    int epact = (11 * goldenNumber + 20 + moonCorrection - skippedLeapYears) % 30;
    if ((epact == 25 && goldenNumber > 11) || epact == 24)
        epact++;
    int day = 44 - epact;
    if (day < 21)
        day += 30;

    int month = 3;
    if (day > 31)
    {
        month++;
        day -= 31;
    }

    return (month * 100) + day;
}

int main()
{
    int year;
    std::cout << "Enter a year to calculate Easter: ";
    std::cin >> year;

    int easterDate = calculateEaster(year);

    int month = easterDate / 100;
    int day = easterDate % 100;

    std::cout << "Easter in " << year << " is on " << month << "/" << day << std::endl;

    return 0;
}
