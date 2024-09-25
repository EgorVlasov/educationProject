#include <iostream>
int main (){
    std::string stopName1 = "developers_street";
    std::string stopName2 = "Algorithms_Prospectus";
    std::string stopName3 = "Errors_road";
    std::string stopName4 = "Release_alley";
    std::string currentStopName;
    int numberOfStopsOnRoute = 4;
    int ticketPrice = 20;
    int salary = ticketPrice / 4;
    int fuelCost = ticketPrice / 5;
    int taxes = ticketPrice / 5;
    int carRepairCost = ticketPrice / 5;
    int totalSalary;
    int totalFuelCoste;
    int totalTaxes;
    int totalcarRepairCost;
    int totalIncome;
    int totalPassangers;
    int passengersCameOut;
    int passengersEntered;
    int currentNumberOfPassengers;

    currentStopName = stopName1;
    currentNumberOfPassengers = 0;
    std::cout << "We arrive at the stop '" << currentStopName <<"'. Passengers In the cabin: " << currentNumberOfPassengers << " \n";
    std::cout << "How many passengers got off at the bus stop? \n";
    std::cin >> passengersCameOut;
    std::cout << "How many passengers have entered at the bus? \n";
    std::cin >> passengersEntered;
    std::cout << "We leave from the stop '" << currentStopName << "' \n";
    currentNumberOfPassengers += (passengersEntered - passengersCameOut);
    std::cout << "Passengers in the bus cabin: " << currentNumberOfPassengers << "\n";

    totalSalary = salary*passengersEntered;
    totalFuelCoste = fuelCost*passengersEntered;
    totalTaxes = taxes*passengersEntered;
    totalcarRepairCost = carRepairCost*passengersEntered;
    totalPassangers = passengersEntered;

    std::cout << "-----------in route--------- \n";

    currentStopName = stopName2;
    std::cout << "We arrive at the stop '" << currentStopName << "'. Passengers In the cabin: " << currentNumberOfPassengers << " \n";
    std::cout << "How many passengers got off at the bus stop? \n";
    std::cin >> passengersCameOut;
    std::cout << "How many passengers have entered at the bus? \n";
    std::cin >> passengersEntered;
    std::cout << "We leave from the stop '" << currentStopName << "' \n";
    currentNumberOfPassengers += (passengersEntered - passengersCameOut);
    std::cout << "Passengers in the bus cabin: " << currentNumberOfPassengers << "\n";

    totalSalary += (salary*passengersEntered);
    totalFuelCoste += (fuelCost*passengersEntered);
    totalTaxes += (taxes*passengersEntered);
    totalcarRepairCost += (carRepairCost*passengersEntered);
    totalPassangers +=passengersEntered;


    std::cout << "-----------in route--------- \n";

    currentStopName = stopName3;
    std::cout << "We arrive at the stop '" << currentStopName << "'. Passengers In the cabin: " << currentNumberOfPassengers << " \n";
    std::cout << "How many passengers got off at the bus stop? \n";
    std::cin >> passengersCameOut;
    std::cout << "How many passengers have entered at the bus? \n";
    std::cin >> passengersEntered;
    std::cout << "We leave from the stop '" << currentStopName << "' \n";
    currentNumberOfPassengers += (passengersEntered - passengersCameOut);
    std::cout << "Passengers in the bus cabin: " << currentNumberOfPassengers << "\n";

    totalSalary += (salary*passengersEntered);
    totalFuelCoste += (fuelCost*passengersEntered);
    totalTaxes += (taxes*passengersEntered);
    totalcarRepairCost += (carRepairCost*passengersEntered);
    totalPassangers +=passengersEntered;
    
    std::cout << "-----------in route--------- \n";

    currentStopName = stopName4;
    std::cout << "We arrive at the stop '" << currentStopName << "'. Passengers In the cabin: " << currentNumberOfPassengers << " \n";
    std::cout << "How many passengers got off at the bus stop? \n";
    std::cin >> passengersCameOut;
    std::cout << "How many passengers have entered at the bus? \n";
    std::cin >> passengersEntered;
    std::cout << "We leave from the stop '" << currentStopName << "' \n";
    currentNumberOfPassengers += (passengersEntered - passengersCameOut);
    std::cout << "Passengers in the bus cabin: " << currentNumberOfPassengers << "\n";

    totalSalary += (salary*passengersEntered);
    totalFuelCoste += (fuelCost*passengersEntered);
    totalTaxes += (taxes*passengersEntered);
    totalcarRepairCost += (carRepairCost*passengersEntered);
    totalPassangers +=passengersEntered;
    totalIncome = (totalPassangers*ticketPrice)-(totalSalary+totalFuelCoste+totalTaxes+totalcarRepairCost);
    
    std::cout << "\n";
    std::cout << "Total tickets were sold: " << totalPassangers << "\n";
    std::cout << "Total amount of tickets sold: " << totalPassangers*ticketPrice << "\n";
    std::cout << "Total Income: " << totalIncome << "\n";
    std::cout << "Driver salary: " << totalSalary << "\n";
    std::cout << "Total fuel coste: " << totalFuelCoste << "\n";
    std::cout << "Total fuel coste: " << totalTaxes << "\n";
    std::cout << "Total car repair cost: " << totalcarRepairCost << "\n";
};