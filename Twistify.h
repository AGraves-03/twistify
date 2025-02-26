#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>

namespace Twistify {

    // Reverses a string, but in the most convoluted way.
    std::string reverseString(const std::string& str);

    // A function that swaps two integers in a loop, just to confuse things.
    void swapception(int& a, int& b);

    // A function that echoes a message in a recursive way.
    void echoMadness(const std::string& message, int count);

    // A completely unnecessary way to sort numbers.
    void tangleSort(std::vector<int>& nums);

    int tangleMultiply(int a, int b);
    
    template <typename T>
    void cursedCast(T value);

    void chaoticLoop(int n);

    void pseudoError();

    void aiCodeReview();
    void unpredictableDefineBomb();
    void randomCodeInjection();
    void timeTravelerBug();
    void stealthyCorruptor();


    class NameTwister {
    private:
        std::unordered_map<std::string, int> variables;

    public:
        NameTwister(); // Constructor

        void set(std::string name, int value);
        int get(std::string name);
        void rename(std::string oldName, std::string newName);
    };
}
