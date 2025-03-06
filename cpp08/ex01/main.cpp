#include <iostream>
#include "Span.hpp"

void testAddNumber()
{
    Span sp(5);
    try
    {
        std::cout << "Adding numbers individually:" << std::endl;

        sp.addNumber(10);
        std::cout << "Added 10" << std::endl;
        sp.addNumber(20);
        std::cout << "Added 20" << std::endl;
        sp.addNumber(30);
        std::cout << "Added 30" << std::endl;
        sp.addNumber(40);
        std::cout << "Added 40" << std::endl;
        sp.addNumber(50);
        std::cout << "Added 50" << std::endl;

        std::cout << "Trying to add another number." << std::endl;
        sp.addNumber(60);
    }
    catch (const Span::SpanOverflowException &e)
    {
        std::cout << "Test Failed: " << e.what() << std::endl;
    }
}

void testAddNumbers()
{
    Span sp(20000);
    try
    {
        std::cout << "Adding 20000 numbers:" << std::endl;

        sp.addNumbers(20000);
        std::cout << "Successfully added 20000 numbers" << std::endl;

        std::cout << "Trying to add 20001" << std::endl;
        sp.addNumber(20001);
    }
    catch (const Span::SpanOverflowException &e)
    {
        std::cout << "Test Failed: " << e.what() << std::endl;
    }
}

void testShortestSpan()
{
    Span sp(5);
    try
    {
        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);
        sp.addNumber(40);
        sp.addNumber(50);

        int result = sp.shortestSpan();
        std::cout << "Test Passed: Shortest Span is " << result << std::endl;
    }
    catch (const Span::SpanOverflowException &e)
    {
        std::cout << "Test Failed: " << e.what() << std::endl;
    }
}

void testLongestSpan()
{
    Span sp(5);
    try
    {
        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);
        sp.addNumber(40);
        sp.addNumber(50);

        int result = sp.longestSpan();
        std::cout << "Test Passed: Longest Span is " << result << std::endl;
    }
    catch (const Span::SpanOverflowException &e)
    {
        std::cout << "Test Failed: " << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "Testing Span Class" << std::endl;

    testAddNumber();
    testAddNumbers();
    testShortestSpan();
    testLongestSpan();

    return 0;
}