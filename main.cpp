#include <iostream>
#include "lib.h"


int main() {
    int capacity = 100; 
    int size = 0; 
    Figure** figures = new Figure*[capacity];
    
    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Trapezoid\n";
        std::cout << "2. Add Rhomb\n";
        std::cout << "3. Add Pentagon\n";
        std::cout << "4. Print all figures\n";
        std::cout << "5. Print total area of all figures\n";
        std::cout << "6. Delete a figure by index\n";
        std::cout << "7. Exit\n";
        std::cout << "Choose an option: ";
        int option;
        std::cin >> option;

        if (option == 1) {
            if (size < capacity) {
                figures[size] = new Trapezoid(); 
                std::cout << "Enter trapezoid vertices:\n";
                std::cin >> *figures[size];
                ++size;
            } else {
                std::cout << "Array is full.\n";
            }
        } else if (option == 2) {
            if (size < capacity) {
                figures[size] = new Rhomb(); 
                std::cout << "Enter rhomb vertices:\n";
                std::cin >> *figures[size];
                ++size;
            } else {
                std::cout << "Array is full.\n";
            }
        } else if (option == 3) {
            if (size < capacity) {
                figures[size] = new Pentagon(); 
                std::cout << "Enter pentagon vertices:\n";
                std::cin >> *figures[size];
                ++size;
            } else {
                std::cout << "Array is full.\n";
            }
        } else if (option == 4) {
            for (int i = 0; i < size; ++i) {
                std::cout << "Figure " << i + 1 << ":\n" << *figures[i] << "\n";
                std::cout << "Center: (" << figures[i]->getCenter().x << ", " << figures[i]->getCenter().y << ")\n";
                std::cout << "Area: " << static_cast<double>(*figures[i]) << "\n";
            }
        } else if (option == 5) {
            double totalArea = 0;
            for (int i = 0; i < size; ++i) {
                totalArea += static_cast<double>(*figures[i]);
            }
            std::cout << "Total area of all figures: " << totalArea << "\n";
        } else if (option == 6) {
            std::cout << "Enter index to delete (1-based): ";
            int index;
            std::cin >> index;
            if (index > 0 && index <= size) {
                delete figures[index - 1];
                for (int i = index - 1; i < size - 1; ++i) {
                    figures[i] = figures[i + 1];
                }
                --size;
                std::cout << "Figure deleted.\n";
            } else {
                std::cout << "Invalid index.\n";
            }
        } else if (option == 7) {
            break;
        } else {
            std::cout << "Invalid option.\n";
        }
    }

    
    for (int i = 0; i < size; ++i) {
        delete figures[i];
    }
    delete[] figures;

    return 0;
}