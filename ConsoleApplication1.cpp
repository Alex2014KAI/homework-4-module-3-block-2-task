#include <iostream>

class Counter {
    int counter;

public:
    Counter() :counter(1) {};
    Counter(int ctr) :counter(ctr) {};

    void increase();
    void decrease();
    int getCounter();
};

void work(Counter& counter);

int main()
{
    Counter counter;

    std::cout << "Do you want to specify the initial value of the counter? Enter yes or no: ";
    std::string inputInitialValue;
    std::cin >> inputInitialValue;

    if (inputInitialValue == "yes") {
        std::cout << "Enter the initial value of the counter: ";
        int initialValueCounter{ 1 };
        std::cin >> initialValueCounter;

        counter = Counter (initialValueCounter);
    }
    else if (inputInitialValue == "no") {
        counter = Counter(1);
    }
    else {
        std::cout << "You entered an incorrect value." << std::endl;
        std::cout << "A counter with an initial value of 1 was automatically created." << std::endl;

        counter = Counter(1);
    }

    work(counter);
}

void Counter::increase() {
    counter++;
}

void Counter::decrease() {
    counter--;
}

int Counter::getCounter() {
    return counter;
}

void work(Counter& counter) {

    while (true) {
        std::cout << "Enter the command ('+', '-', '=' or 'x'): ";
        char order;
        std::cin >> order;

        switch (static_cast<int>(order))  // ASCII "+": 43, "-": 45, "=": 61, "x": 120
        {
        case 43: {
            counter.increase();
            break;
        };
        case 45: {
            counter.decrease();
            break;
        };
        case 61: {
            std::cout << counter.getCounter() << std::endl;
            break;
        };
        case 120: {
            std::cout << "Goodbye!" << std::endl;
            return;
            break;
        };

        default:
            std::cout << "You entered an invalid command." << std::endl;
            break;
        }
    }
}
