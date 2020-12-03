#include "Customer.h"

#include <iostream>

Customer::Customer(std::string name) : m_name(std::move(name)){}

void Customer::setTotal(double total) {
   m_total = total;
}

double Customer::total() const {
   return m_total;
}

std::string Customer::name() const {
   return m_name;
}

Car* Customer::car() const {
   return m_car;
}

bool Customer::rentCar(Car* car, int days) {
   if (m_car != nullptr) {
      std::cout << "You have already rented car: " << m_car->model() << std::endl;
      return false;
   }

   double cost = car->cost() * days;
   if (m_total < cost) {
      std::cout << "You have not enough money to rent the car: " << car->model() << std::endl;
      return false;
   }
   m_total -= cost;
   m_car = car;
   return true;
}
