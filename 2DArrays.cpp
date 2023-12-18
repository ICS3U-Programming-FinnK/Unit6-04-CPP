// Created by: Finn Kitor
// Created on: December 18th, 2023
// this program is a 2d array that makes the user input the rows and columns and
// is will generate 50 random numbers and will calculate the average
#include <iostream>
#include <random>
#include <vector>

const int MIN_NUM = 1;
const int MAX_NUM = 50;
// Create an empty 2D array
std::vector<std::vector<int>> create_2d_array(int rows, int columns) {
    try {  
        if (rows <= 0 || columns <= 0) {
            // Invalid input for negative numbers inputted
            throw std::invalid_argument("Number of rows and columns must be positive integers");
        }

        std::vector<std::vector<int>> array_2d;
        // Generate random numbers and place them in the 2D array
        for (int i = 0; i < rows; i++) {
            std::vector<int> row;
            for (int j = 0; j < columns; j++) {
                // Generate a random number between MIN_NUM and MAX_NUM
                int num = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
                row.push_back(num);
            }
            array_2d.push_back(row);
        }
        return array_2d;
    } catch (const std::invalid_argument& e) {
        std::cout << "Error creating 2D array: " << e.what() << std::endl;
        return std::vector<std::vector<int>>();
    }
}

float calc_average(const std::vector<std::vector<int>>& array_2d) {
    try {
        if (array_2d.empty()) {
            throw std::invalid_argument("Array is empty");
        }
        // Initialize variables for sum and count
        int total_sum = 0;
        int count = 0;
        // Calculate the sum of all the numbers in the 2D array
        for (const auto& row : array_2d) {
            for (int num : row) {
                total_sum += num;
                count++;
            }
        }
        // Calculate the average
        float average = static_cast<float>(total_sum) / count;
        return average;
    } catch (const std::invalid_argument& e) {
        std::cout << "Error calculating average: " << e.what() << std::endl;
        return 0.0;
    }
}

int main() {
    try {
        int rows, columns;
        // Ask the user for the number of rows and columns
        std::cout << "Enter the number of rows: ";
        std::cin >> rows;

        std::cout << "Enter the number of columns: ";
        std::cin >> columns;
        // Create the 2D array
        std::vector<std::vector<int>> array_2d = create_2d_array(rows, columns);
        if (array_2d.empty()) {
            return 0;
        }
        // Display the 2D array
        std::cout << "2D Array:" << std::endl;
        for (const auto& row : array_2d) {
            for (int num : row) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
        // Calculate and display the average
        float average = calc_average(array_2d);
        std::cout << "Average: " << average << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: Invalid input, you inputted a string, not a number: " << e.what() << std::endl;
    }
    // Call the main function
    return 0;
}
