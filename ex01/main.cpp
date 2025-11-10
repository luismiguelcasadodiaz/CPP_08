#include "Span.hpp"
#include <iostream>
#include <cstdlib>  // para rand()
#include <ctime>    // para time()
int main()
{
    try {
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

    try {
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

    try {
        // Inicializar el generador de números aleatorios
        std::srand(std::time(0));
        
        Span sp = Span(10000);
        
        // Crear un vector con 10000 números
        std::vector<int> nums;
        for (int i = 0; i < 10000; i++)
        {
            nums.push_back(std::rand() % 100000);  // números aleatorios entre 0-99999
        }
        clock_t start = clock();
        // Añadir todos de una vez
        sp.addNumber(nums.begin(), nums.end());
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        clock_t end = clock();
        std::cout << "Time with Span: " 
              << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        // Inicializar el generador de números aleatorios
        std::srand(std::time(0));
        
        Span sp = Span(10000);
        
        // Crear un vector con 10000 números
        std::vector<int> nums;
        for (int i = 0; i < 10000; i++)
        {
            nums.push_back(std::rand() % 100000);  // números aleatorios entre 0-99999
        }
        clock_t start = clock();
        // Añadir todos de una vez
        sp.addNumber(nums.begin(), nums.end());
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpanSTL() << std::endl;
        clock_t end = clock();
        std::cout << "Time with Span: " 
              << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
    }catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    
return 0;
}

