#include "Date.h"
#include "Person.h"
#include "Customer.h"
#include "RealEstateAgent.h"
#include "Property.h"
#include "LandSale.h"
#include "HouseSale.h"
#include "ApartmentSale.h"
#include "RealEstateManager.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Manager object
    RealEstateManager manager;

    // Create customers
    Customer customer1("John A.", Date(1, 8, 1993), "123456789");
    Customer customer2("Jane B.", Date(5, 5, 1990), "246813579");
    Customer customer3("Josh C.", Date(8, 4, 1985), "135792468");
    Customer customer4("Judy D.", Date(2, 9, 1995), "987654321");

    // Create agents
    RealEstateAgent* agent1 = new RealEstateAgent("Adam E.", Date(7, 2, 1991), 901, Date(1, 7, 2019));
    RealEstateAgent* agent2 = new RealEstateAgent("Anna F.", Date(3, 3, 1988), 902, Date(5, 5, 2020));
    RealEstateAgent* agent3 = new RealEstateAgent("Alex G.", Date(2, 1, 1992), 903, Date(2, 8, 2021));

    // Create some properties
    LandSale* land = new LandSale("123 Pine Street", customer1, agent1->getID(), Date(5, 5, 2025), 15000.0, 1300000);
    HouseSale* house = new HouseSale("456 Cedar Street", customer2, agent2->getID(), Date(10, 5, 2025), "Town house", 2012, 5, 1100000);
    ApartmentSale* apartment1 = new ApartmentSale("789 Oak Street", customer3, agent3->getID(), Date(15, 5, 2025), 300.0, 2015, 3, 900000);
    ApartmentSale* apartment2 = new ApartmentSale("101 Spruce Street", customer4, agent1->getID(), Date(20, 5, 2025), 250.0, 2021, 2, 700000);

    // Add agents to manager
    manager.addAgent(agent1).addAgent(agent2).addAgent(agent3);

    // Add properties for sale
    manager.addPropertyForSale(land).addPropertyForSale(house).addPropertyForSale(apartment1).addPropertyForSale(apartment2);

    // Print manager info
    manager.printAll();
    cout << endl;

    // Testing find functions
    cout << "Searching for property with ID 1002:" << endl << endl;
    manager.findProperty(1002);
    cout << endl;

    cout << "Searching for agent with ID 902:" << endl << endl;
    manager.findAgent(902);
    cout << endl;

    // Sell a property
    cout << "Attempting sale of house:" << endl;
    manager.completeSale(house, 1250000, Date(11, 6, 2025));
    cout << endl;

    // Print manager info again
    manager.printAll();
    cout << endl;

    // Search for sold property
    cout << "Searching for sold property with ID 1002:" << endl;
    manager.findProperty(1002);
    cout << endl;

    // Check if property removed from agent's properties
    cout << "Searching for agent with ID 902:" << endl;
    manager.findAgent(902);
    cout << endl;


    // Delete dynamic objects
    delete agent1;
    delete agent2;
    delete agent3;
    delete land;
    delete house;
    delete apartment1;
    delete apartment2;

    return 0;
}