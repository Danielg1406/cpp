#include <iostream>
#include <list>
#include <stack>

#include "MutantStack.hpp"

static int g_failedTests = 0;

static void report(bool condition, const std::string &label)
{
    std::cout << (condition ? "[PASS] " : "[FAIL] ") << label << std::endl;
    if (!condition)
        ++g_failedTests;
}

template <typename StackType>
static void testIterationOrder(StackType &stack, int startValue, const std::string &label)
{
    try
    {
        typename StackType::iterator it = stack.begin();
        typename StackType::iterator end = stack.end();
        int expected = startValue;

        while (it != end)
        {
            if (*it != expected)
            {
                report(false, label);
                return;
            }
            ++expected;
            ++it;
        }
        report(true, label);
    }
    catch (const std::exception &e)
    {
        report(false, label + std::string(" (unexpected exception: ") + e.what() + ")");
    }
}

int main()
{
    std::cout << "Exercise 02 - MutantStack" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    report(mstack.top() == 17, "top returns the last pushed value");
    mstack.pop();
    report(mstack.size() == 1, "pop reduces the size");
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    report(it == mstack.begin(), "iterators support bidirectional movement");

    int expectedValues[] = {5, 3, 5, 737, 0};
    int index = 0;
    bool orderMatches = true;
    while (it != ite)
    {
        if (*it != expectedValues[index])
        {
            orderMatches = false;
            break;
        }
        ++it;
        ++index;
    }
    report(orderMatches && index == 5, "iteration follows stack storage order");

    MutantStack<int> copied(mstack);
    report(copied.size() == mstack.size(), "copy constructor copies the stack");
    MutantStack<int> assigned;
    assigned = mstack;
    report(assigned.top() == mstack.top(), "assignment copies the top element");

    std::stack<int> standardStack(mstack);
    report(standardStack.size() == mstack.size(), "can be copied into std::stack");

    const MutantStack<int> constStack(mstack);
    MutantStack<int>::const_iterator constIt = constStack.begin();
    MutantStack<int>::const_iterator constEnd = constStack.end();
    index = 0;
    orderMatches = true;
    while (constIt != constEnd)
    {
        if (*constIt != expectedValues[index])
        {
            orderMatches = false;
            break;
        }
        ++constIt;
        ++index;
    }
    report(orderMatches && index == 5, "const iterators work");

    MutantStack<int, std::list<int> > listStack;
    listStack.push(1);
    listStack.push(2);
    listStack.push(3);
    listStack.push(4);
    listStack.push(5);
    testIterationOrder(listStack, 1, "custom underlying container iterates correctly");

    std::cout << "Reverse iteration:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << std::endl;

    std::cout << "Failed tests: " << g_failedTests << std::endl;
    return g_failedTests == 0 ? 0 : 1;
}