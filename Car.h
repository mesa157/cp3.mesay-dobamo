#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
public:
   Car(std::string model, std::string number, double cost, std::string description)
      : m_model(std::move(model))
      , m_number(std::move(number))
      , m_cost(cost)
      , m_description(std::move(description))
      { }
   
   virtual ~Car() {}
   virtual std::string type() const = 0;

   double cost() const {
      return m_cost;
   }

   std::string model() const {
      return m_model;
   }
   std::string number() const {
      return m_number;
   }
   std::string description() const {
      return m_description;
   }

private:
   std::string m_model;
   std::string m_number;
   double m_cost;
   std::string m_description;
};

#endif