#include "Set.h" 
#include "table.h"



int main() 
{
    std::cout << "\n1 Task: \n\n";//Sofiya
    Set<char> expression;
    char expr[] = {'(', '2', '*', '3', ')',  '+' , '2'};
    expression.add(expr, 7);
    expression.print();
    expression.calculateExp();


    std::cout << "\n2 Task: \n\n";//Sofiya

    std::cout << "Digits in 2024: " << digits(2024) << std::endl; 
    std::cout << "Digits in 5: " << digits(5) << std::endl; 
    std::cout << "Digits in 10110111: " << digits(10110111) << std::endl; 


    std::cout << "\n3.1 Task: \n\n";//Sofiya

    char chars[] = { 'a', 'b', 'r', 'a', 'c',  'a' , 'd', 'a', 'b', 'r', 'a'};

    task31(chars);

    std::cout << "\n3.2 Task: \n\n";//Sofiya

    task32(chars);

    std::cout << "\n3.3 Task: \n\n";//Sofiya

    task33(chars);

    std::cout << "\n4 Task: (Eratosthenes from 2 to 100)\n\n";//Oleh

    eratosthenes(100);

    
    

    const int n = 3;
    Set<Product> storeAssortment[n]; 

    storeAssortment[0].add(Product::Bread);
    storeAssortment[0].add(Product::Butter);
    storeAssortment[0].add(Product::Milk);
    storeAssortment[0].add(Product::Cheese);

    storeAssortment[1].add(Product::Milk);
    storeAssortment[1].add(Product::Meat);
    storeAssortment[1].add(Product::Fish);
    storeAssortment[1].add(Product::Salt);
    storeAssortment[1].add(Product::Bread);

    storeAssortment[2].add(Product::Sugar);
    storeAssortment[2].add(Product::Tea);
    storeAssortment[2].add(Product::Coffee);
    storeAssortment[2].add(Product::Bread);


    std::cout << "\n5.1 Task: \n\n";//Oleh
    
    Set<Product> commonProducts = storeAssortment[0];
    for (int i = 1; i < n; ++i) {
        commonProducts = commonProducts.intersect(storeAssortment[i]);
    }
    std::cout << "Products is in every store: ";
    commonProducts.print();

    std::cout << "\n5.2 Task: \n\n";//Oleh

    Set<Product> anyProducts;
    for (int i = 0; i < n; ++i) {
        anyProducts = anyProducts.unionSetIfNotContains(storeAssortment[i]);
    }
    std::cout << "Products is in at least one store: ";
    anyProducts.print();

    std::cout << "\n5.3 Task: \n\n";//Oleh

    Set<Product> allProducts;

    for (int i = 0; i < 11; ++i) {
        allProducts = allProducts.add(Product(i));
    }

    Set<Product> missingProducts = allProducts.difference(anyProducts);
    std::cout << "Products is missing in all stores: ";
    missingProducts.print();

    std::cout << "\n6.1 Task: \n\n";//Oleh

    Name guests_Ivan[] = { Name::Oleksa, Name::Yuliya , Name::Vitaliy, Name::Markiyan , Name::Olga };
    Name guests_Oleh[] = { Name::Kseniya , Name::Andriy , Name::Sofiya , Name::Olga , Name::Taras , Name::Iryna };
    Name guests_Artemiy[] = { Name::Yuriy , Name::Halyna , Name::Olga };
    Name guests_Vladyslav[] = { Name::Kateryna , Name::Olga };
    Name guests_Solomiya[] = { Name::Mykola , Name::Vasyl, Name::Olga };
    Name guests_Kseniya[] = { Name::Andriy , Name::Vasyl, Name::Olga };
    Name guests_Andriy[] = { Name::Mykola , Name::Taras, Name::Olga  };
    Name guests_Sofiya[] = { Name::Markiyan , Name::Oleh, Name::Olga , Name::Kostyantyn };

    Table<Name , Name> table;
    table.add(Name::Ivan, guests_Ivan, 5);
    table.add(Name::Oleh, guests_Oleh, 6);
    table.add(Name::Artemiy, guests_Artemiy, 3);
    table.add(Name::Vladyslav, guests_Vladyslav, 2);
    table.add(Name::Solomiya, guests_Solomiya, 3);
    table.add(Name::Kseniya, guests_Kseniya, 3);
    table.add(Name::Andriy, guests_Andriy, 3);
    table.add(Name::Sofiya, guests_Sofiya, 4);
    
   

    table.print();

    std::cout << "\n";


    Table<Name, int>* visits = table.calculateVisits();
    visits->printUnFriendlyName();
    std::cout << "\n6.2 Task: \n\n";//Oleh
    visits->printMostFriendlyName(table.getSize());
    std::cout << "\n6.3 Task: \n\n";//Oleh
    Name t1[] = { Name::Oleh, Name::Artemiy, Name::Halyna };
    Name t2[] = { Name::Ivan , Name::Artemiy };
    Name t3[] = { Name::Ivan , Name::Oleh  };
    Name t4[] = { Name::Markiyan, Name::Oleksa , Name::Halyna};
    Name t5[] = { Name::Sofiya, Name::Taras };
    Table<Name, Name> closeTable;

    closeTable.add(Name::Vladyslav, t4, 3);
    closeTable.add(Name::Oleh, t2, 2);
    closeTable.add(Name::Solomiya, t5, 2);
    closeTable.add(Name::Ivan, t1, 3);
    closeTable.add(Name::Artemiy, t3, 2);

    closeTable.print();
    std::cout << "\n";
    closeTable.checkCloseFriends(3);
    closeTable.checkCloseFriends(4);

    std::cout << "\n6.4 Task: \n\n";//Oleh

    Table<Name, Set<Name>>* guestsTable = closeTable.buildGuestsTable();
    guestsTable->print();
    delete guestsTable;
    delete visits;

    std::cout << "\n7 Task: \n\n";//Oleh


    City tripLviv[] = { City::Kyiv , City::Odesa , City::Ternopil , City::Chernivtsi };
    City tripKharkiv[] = { City::Donetsk , City::Luhansk , City::Simferopol };
    City tripChernivtsi[] = { City::Chernihiv , City::Poltava , City::Vinnytsia };
    City tripMykolaiv[] = { City::Kherson , City::Ivano_Frankivsk };

    Table<City, City> busTable;
    busTable.add(City::Lviv, tripLviv, 4);
    busTable.add(City::Kharkiv, tripKharkiv, 3);
    busTable.add(City::Chernivtsi, tripChernivtsi, 3);
    busTable.add(City::Mykolaiv, tripMykolaiv, 2);


     

    busTable.print();



    std::cout << "\nCan we have a trip from Lviv to Kyiv: " << busTable.canReachDestination(City::Lviv, City::Kyiv) << "\n";
    std::cout << "Can we have a trip from Kyiv to Lviv: " << busTable.canReachDestination(City::Kyiv, City::Lviv) << "\n";
    std::cout << "Can we have a trip from Lviv to Ivano_Frankivsk: " << busTable.canReachDestination(City::Lviv, City::Ivano_Frankivsk) << "\n";
    std::cout << "Can we have a trip from Lviv to Poltava: " << busTable.canReachDestination(City::Lviv, City::Poltava) << "\n";
    std::cout << "Can we have a trip from Kharkiv to Simferopol: " << busTable.canReachDestination(City::Kharkiv, City::Simferopol) << "\n";


    return 0;

}

