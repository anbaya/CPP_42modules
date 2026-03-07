#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    // // ── Test 1: Subject example ──────────────────────────────
    std::cout << "=== Test 1: Subject example ===" << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortest: " << sp.shortestSpan() << std::endl; // 2
        std::cout << "longest:  " << sp.longestSpan()  << std::endl; // 14
    }

    // ── Test 2: Overflow – adding to a full Span ─────────────
    std::cout << "\n=== Test 2: Overflow (full container) ===" << std::endl;
    {
        Span sp(3);
        try {
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3);
            sp.addNumber(4); // should throw
            std::cout << "ERROR: no exception thrown" << std::endl;
        } catch (const Span::itsFullEx &e) {
            std::cout << "Caught: " << e.what() << std::endl;
        }
    }

    // ── Test 3: Too few elements (0 and 1) ───────────────────
    std::cout << "\n=== Test 3: Too few elements ===" << std::endl;
    {
        Span empty(1);
        try {
            empty.shortestSpan();
            std::cout << "ERROR: no exception thrown" << std::endl;
        } catch (const std::exception &e) {
            std::cout << "Caught (0 elems): " << e.what() << std::endl;
        }
        empty.addNumber(42);
        try {
            empty.longestSpan();
            std::cout << "ERROR: no exception thrown" << std::endl;
        } catch (const std::exception &e) {
            std::cout << "Caught (1 elem):  " << e.what() << std::endl;
        }
    }

    // ── Test 4: Two elements only ────────────────────────────
    std::cout << "\n=== Test 4: Two elements ===" << std::endl;
    {
        Span sp(2);
        sp.addNumber(100);
        sp.addNumber(1);
        std::cout << "shortest: " << sp.shortestSpan() << std::endl; // 99
        std::cout << "longest:  " << sp.longestSpan()  << std::endl; // 99
    }

    // ── Test 5: Negative numbers ─────────────────────────────
    std::cout << "\n=== Test 5: Negative numbers ===" << std::endl;
    {
        Span sp(5);
        sp.addNumber(-10);
        sp.addNumber(-3);
        sp.addNumber(0);
        sp.addNumber(7);
        sp.addNumber(20);
        std::cout << "shortest: " << sp.shortestSpan() << std::endl; // 3
        std::cout << "longest:  " << sp.longestSpan()  << std::endl; // 30
    }

    // ── Test 6: Duplicate values ─────────────────────────────
    std::cout << "\n=== Test 6: Duplicate values ===" << std::endl;
    {
        Span sp(4);
        sp.addNumber(5);
        sp.addNumber(5);
        sp.addNumber(5);
        sp.addNumber(5);
        std::cout << "shortest: " << sp.shortestSpan() << std::endl; // 0
        std::cout << "longest:  " << sp.longestSpan()  << std::endl; // 0
    }

    // ── Test 7: 10 000 numbers ───────────────────────────────
    std::cout << "\n=== Test 7: 10,000 numbers ===" << std::endl;
    {
        Span sp(10000);
        for (int i = 0; i < 10000; i++)
            sp.addNumber(i);
        std::cout << "shortest: " << sp.shortestSpan() << std::endl; // 1
        std::cout << "longest:  " << sp.longestSpan()  << std::endl; // 9999
    }

    // ── Test 8: 100 000 random numbers ───────────────────────
    std::cout << "\n=== Test 8: 100,000 random numbers ===" << std::endl;
    {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        Span sp(100000);
        for (int i = 0; i < 100000; i++)
            sp.addNumber(std::rand());
        std::cout << "shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "longest:  " << sp.longestSpan()  << std::endl;
    }

    // ── Test 9: Copy constructor & assignment ────────────────
    std::cout << "\n=== Test 9: Copy / Assignment ===" << std::endl;
    {
        Span a(3);
        a.addNumber(10);
        a.addNumber(20);
        a.addNumber(30);

        Span b(a);                   // copy ctor
        std::cout << "copy ctor  longest: " << b.longestSpan() << std::endl; // 20

        Span c(1);
        c = a;                       // assignment
        std::cout << "assign op  longest: " << c.longestSpan() << std::endl; // 20
    }

    // ── Test 10: Large span with INT_MIN / INT_MAX ──────────
    std::cout << "\n=== Test 10: INT_MIN / INT_MAX ===" << std::endl;
    {
        Span sp(2);
        sp.addNumber(-2147483648); // INT_MIN
        sp.addNumber(2147483647);  // INT_MAX
        std::cout << "longest:  " << sp.longestSpan() << std::endl; // 4294967295
    }

    // ── Test 11: Range addNumber with iterators ──────────────
    std::cout << "\n=== Test 11: Range addNumber (iterators) ===" << std::endl;
    {
        std::vector<int> v;
        for (int i = 0; i < 10000; i++)
            v.push_back(i);
        Span sp(10000);
        sp.addNumber(v.begin(), v.end());
        std::cout << "shortest: " << sp.shortestSpan() << std::endl; // 1
        std::cout << "longest:  " << sp.longestSpan()  << std::endl; // 9999
    }

    // ── Test 12: Range addNumber overflow ─────────────────────
    std::cout << "\n=== Test 12: Range addNumber overflow ===" << std::endl;
    {
        std::vector<int> v;
        for (int i = 0; i < 10; i++)
            v.push_back(i);
        Span sp(5);
        try {
            sp.addNumber(v.begin(), v.end()); // should throw after 5
            std::cout << "ERROR: no exception thrown" << std::endl;
        } catch (const Span::itsFullEx &e) {
            std::cout << "Caught: " << e.what() << std::endl;
        }
    }

    return 0;
}