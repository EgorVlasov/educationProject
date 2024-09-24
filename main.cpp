#include <iostream>
int main (){
    std::string stopName1 = "developers_street";
    std::string stopName2 = "Algorithms_Prospectus";
    std::string stopName3 = "Errors_road";
    std::string stopName4 = "Release_alley";
    int numberOfStopsOnRoute = 4;
    int ticketPrice = 20;
    int expensesSalary = ticketPrice / 4;
    int expensesFuel = ticketPrice / 5;
    int expensesTaxes = ticketPrice / 5;
    int expensesCarRepair = ticketPrice / 5;
    int incomeForOneTicket = ticketPrice - (expensesSalary+expensesFuel+expensesTaxes+expensesCarRepair);
    int incomeForOneStop;
    int totalIncome;
    int passengersCameOut;
    int passengersEntered;
    int currentNumberOfPassengers;
    std::string currentStopName;

    currentStopName = stopName1;
    currentNumberOfPassengers = 0;

    std::cout << "We arrive at the stop '" << currentStopName <<"'. Passengers In the cabin" << currentNumberOfPassengers << " \n";
    std::cout << "How many passengers got off at the bus stop? \n";
    std::cin >> passengersCameOut;
    std::cout << "How many passengers have entered at the bus? \n";
    std::cin >> passengersEntered;
    std::cout << "We leave from the stop '" << currentStopName << "' \n";
    currentNumberOfPassengers += (passengersEntered - passengersCameOut);
    std::cout << "Passengers in the bus cabin: " << currentNumberOfPassengers << "\n";
    incomeForOneStop = incomeForOneTicket*currentNumberOfPassengers;
    std::cout << "we earned: " << incomeForOneStop << " rubles \n";
    totalIncome = incomeForOneStop;
    std::cout << "we earned TOTAL: " << totalIncome << " rubles \n";

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
    incomeForOneStop = incomeForOneTicket*currentNumberOfPassengers;
    std::cout << "we earned: " << incomeForOneStop << " rubles \n";
    totalIncome +=incomeForOneStop;
    std::cout << "we earned TOTAL: " << totalIncome << " rubles \n";

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
    incomeForOneStop = incomeForOneTicket*currentNumberOfPassengers;
    std::cout << "we earned: " << incomeForOneStop << " rubles \n";
    totalIncome +=incomeForOneStop;
    std::cout << "we earned TOTAL: " << totalIncome << " rubles \n";
    
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
    incomeForOneStop = incomeForOneTicket*currentNumberOfPassengers;
    std::cout << "we earned: " << incomeForOneStop << " rubles \n";
    totalIncome +=incomeForOneStop;
    std::cout << "we earned TOTAL: " << totalIncome << " rubles \n";  
};