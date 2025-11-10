#include "Span.hpp"
#include <iostream>
#include <cstdlib>  // para rand()
#include <ctime>    // para time()
#include <iomanip>  // para fixed & setprecision()
int main()
{
        // Inicializar el generador de números aleatorios
        std::srand(std::time(0));
        // Crear un vector con 10000 números
        std::vector<int> nums;
        for (int i = 0; i < 10000; i++)
        {
            nums.push_back(std::rand() % 100000);  // números aleatorios entre 0-99999
        }
    try { //regular exercice raising exception
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        int nums[]={10,20,30};
        std::vector<int> v(nums, nums+3);
        sp.addNumber(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try { //regular exercise without raising exception
        Span sp = Span(8);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        int nums[]={10,20,30};
        std::vector<int> v(nums, nums+3);
        sp.addNumber(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try { // timing 10 000 integers wiht my longestspan
        // Inicializar el generador de números aleatorios
        
        Span sp = Span(10000);
        
		clock_t start_insert = clock();
        sp.addNumber(nums.begin(), nums.end());
		clock_t end_insert = clock();
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        
		clock_t start = clock();
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        clock_t end = clock();
        
		// Set the output format for floating-point numbers
		std::cout << std::fixed;        // Use fixed-point notation (e.g., 0.000003)
		std::cout << std::setprecision(6);
        std::cout << "Custom insert Time : " 
              << (double)(end_insert - start_insert) / CLOCKS_PER_SEC << "s" << std::endl;
        std::cout << "Custom Span   Time : " 
              << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    try { // timing 10 000 integers wiht my longestspan
        // Inicializar el generador de números aleatorios
        
        Span sp = Span(10000);
        
		clock_t start_insert = clock();
        sp.addNumberSTL(nums.begin(), nums.end());
		clock_t end_insert = clock();
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        
		clock_t startSTL = clock();
        std::cout << "Longest span: " << sp.longestSpanSTL() << std::endl;
        clock_t endSTL = clock();
		// Set the output format for floating-point numbers
		std::cout << std::fixed;        // Use fixed-point notation (e.g., 0.000003)
		std::cout << std::setprecision(6);
        std::cout << "STL    insert Time : " 
              << (double)(end_insert - start_insert) / CLOCKS_PER_SEC << "s" << std::endl;
        std::cout << "STL    Span   Time : " 
              << (double)(endSTL - startSTL) / CLOCKS_PER_SEC << "s" << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    
return 0;
}

