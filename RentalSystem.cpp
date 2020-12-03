#include "RentalSystem.h"
#include "Coupe.h"
#include "Hatchback.h"
#include "Minivan.h"
#include "Sedan.h"

#include <fstream>
#include <exception>
#include <sstream>
#include <vector>
#include <iostream>
#include <iomanip>

double fromString(const std::string& value) {
   std::stringstream ss(value);
   double result;
   ss >> result;
   return result;
}

Car* makeCar(const std::vector<std::string>& tokens) {
   if (tokens.size() != 5) {
      throw std::logic_error("Wrong file format: expected Type,Name,Number,Cost,Description");
   }

   double cost = fromString(tokens[3]);
   if (tokens[0] == "Coupe") {
      return new Coupe(tokens[1], tokens[2], cost, tokens[4]);
   }
   if (tokens[0] == "Hatchback") {
      return new Hatchback(tokens[1], tokens[2], cost, tokens[4]);
   }
   if (tokens[0] == "Minivan") {
      return new Minivan(tokens[1], tokens[2], cost, tokens[4]);
   }
   if (tokens[0] == "Sedan") {
      return new Sedan(tokens[1], tokens[2], cost, tokens[4]);
   }

   throw std::logic_error("Wrong type of car: " + tokens[0]);
}

// Type,Name,Number,Cost,Description
void RentalSystem::loadCars(const std::string& filename)
{
   std::ifstream in(filename);
   if (!in.good()) {
      throw std::logic_error("File not found: " + filename);
   }

   while (1) {
      std::string line;
      std::getline(in, line);
      if (!in) {
         break;
      }
      if (line.empty()) {
         continue;
      }
      std::stringstream ss(line);
      std::string token;
      std::vector<std::string> tokens;
      while(std::getline(ss, token, ',')) {
         tokens.push_back(std::move(token));
      }
      m_cars.push_back(makeCar(tokens));
   }
   std::cout << m_cars.size() << " cars was successfully loaded" << std::endl;
}

void RentalSystem::printMenu() const
{
   std::cout << "Menu:" << std::endl;
   std::cout << "1. Rent a car" << std::endl;
   std::cout << "2. Rest of money" << std::endl;
   std::cout << "3. List of cars" << std::endl;
   std::cout << "4. Exit" << std::endl;
}

void RentalSystem::printCars() const
{
   std::cout << "Rental cars: " << std::endl;
   for (std::size_t i = 0; i < m_cars.size(); ++i) {
      std::cout << std::left << std::setw(5) << i + 1 << std::setw(15) << m_cars[i]->type();
      std::cout << std::left << std::setw(15) << m_cars[i]->model();
      std::cout << std::left << std::setw(10) << m_cars[i]->number();
      std::cout << std::left << "$" <<std::fixed << std::setprecision(2) << m_cars[i]->cost();
      std::cout << "\t" << m_cars[i]->description() << std::endl;
   }
}

bool RentalSystem::rentCar(Customer& customer,std::size_t i) {
   if (i > m_cars.size() || i == 0) {
      std::cout << "Invalid index: " << i << std::endl;
      return false;
   }
   int days;
   std::cout << "Days of rent: ";
   std::cin >> days;
   return customer.rentCar(m_cars[i - 1], days);
}