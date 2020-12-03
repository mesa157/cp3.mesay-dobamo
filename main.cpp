#include <iostream>
#include <iomanip> 

#include "RentalSystem.h"
#include "Customer.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <file_with_cars.csv>" << std::endl;
        return 0;
    }
    try
    {
        RentalSystem rentalSystem;
        std::cout << "Loading rental cars..." << std::endl;
        rentalSystem.loadCars(argv[1]);

        std::cout << "Welcome to the Rental Car System!" << std::endl;
        int cmd;
        bool finished = false;
        std::string name;
        std::cout << "Enter your name: ";
        std::cin >> name;
        Customer customer(name);

        std::cout << "Enter money amount: $";
        double money;
        std::cin >> money;
        customer.setTotal(money);

        while (!finished) {
            rentalSystem.printMenu();
            std::cout << "Your choice: ";
            std::cin >> cmd;
            switch (cmd) {
                case 1: // Rent a car
                {
                    std::size_t num;
                    rentalSystem.printCars();
                    std::cout << "Car #: ";
                    std::cin >> num;
                    if (rentalSystem.rentCar(customer, num)) {
                        std::cout << "You're successfully rented the car!" << std::endl;
                    } else {
                        std::cout << "You're not rent the car!" << std::endl;
                    }
                    break;
                } 
                case 2: // Rest of money
                {
                    std::cout << "Rest of money: $" << std::fixed << std::setprecision(2) <<
                        customer.total() << std::endl;
                    break;
                }
                case 3: // List of cars
                {
                    rentalSystem.printCars();
                    break;
                }
                case 4: // Exit
                {
                    finished = true;
                    break;
                }
            }
        }
        std::cout << "Bue" << std::endl;


    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}