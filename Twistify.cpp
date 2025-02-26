#include "Twistify.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <thread>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

namespace Twistify {

    // Reverse function that uses recursion to reverse a string
    std::string reverseString(const std::string& str) {
        if (str.empty()) return str;
        return reverseString(str.substr(1)) + str[0];
    }

    // Swapception: Randomly swaps variables in a silly, tangled loop.
    void swapception(int& a, int& b) {
        for (int i = 0; i < 5; i++) { // 5 iterations of unnecessary swapping
            if (i % 2 == 0) {
                a = a + b;
                b = a - b;
                a = a - b;
            } else {
                a = a - b;
                b = a + b;
                a = b - a;
            }
            std::cout << "Swapped " << a << " and " << b << " at iteration " << i << std::endl;
        }
    }

    // Echo madness: This function prints the message recursively in a twisted way
    void echoMadness(const std::string& message, int count) {
        if (count <= 0) return;
        std::cout << message << std::endl;
        echoMadness(message, count - 1);
    }

    // Tangle Sort: Sorts a list but randomly shuffles items then sorts them anyway
    void tangleSort(std::vector<int>& nums) {
        std::cout << "Starting TangleSort...\n";

        // Initialize a random number generator
        std::random_device rd;
        std::mt19937 g(rd());

        // Shuffle numbers using std::shuffle
        std::shuffle(nums.begin(), nums.end(), g);

        std::cout << "Shuffling numbers...\n";
        std::sort(nums.begin(), nums.end());
        std::cout << "Tangled and Sorted: ";
        for (const int& num : nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    NameTwister::NameTwister() {
        // Constructor - Nothing needed here yet
    }

    void NameTwister::set(std::string name, int ivalue) {
        variables[name] = ivalue;
    }

    int NameTwister::get(std::string name) {
        if (variables.find(name) != variables.end()) {
            return variables[name];
        }
        return 0; // Default if the variable doesn’t exist
    }

    void NameTwister::rename(std::string oldName, std::string newName) {
        if (variables.find(oldName) != variables.end()) {
            variables[newName] = variables[oldName];
            variables.erase(oldName);
        }
    }

    
    
    int tangleMultiply(int a, int b) {
        int steps = rand() % 5 + 1; // Perform between 1 and 5 steps of 'multiplication madness'

        for (int i = 0; i < steps; i++) {
            int r = rand() % 10; // Random number for the operation
            if (r < 5) {
                a *= b;
                std::cout << "Step " << i + 1 << ": a *= b => a = " << a << std::endl;
            } else {
                b *= a;
                std::cout << "Step " << i + 1 << ": b *= a => b = " << b << std::endl;
            }
        }

        return a * b; // Return final multiplication result
    }
    void chaoticLoop(int n) {
        for (int i = 0; i < n; ) { // No i++ here...
            if (rand() % 2) {
                std::cout << "Iteration: " << i << "\n";
                i += (rand() % 3); // Sometimes skips, sometimes jumps ahead
            }
        }
    }
    template <typename T>
    void cursedCast(T value) {
        if (rand() % 2) {
            std::cout << "Casting to int: " << (int)value << "\n";
        } else {
            std::cout << "Casting to double: " << (double)value << "\n";
        }
    }

    void pseudoError() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<int> errorDist(0, 4);
        static std::uniform_int_distribution<int> scrambleDist(0, 1);
        static std::uniform_int_distribution<int> delayDist(1, 5);
        static std::uniform_int_distribution<int> crashDist(0, 4);
        static std::uniform_int_distribution<int> warningDist(0, 3);
        static std::uniform_int_distribution<int> typeForceDist(0, 2);

        std::vector<std::string> errors = {
            "Segmentation fault (core dumped)",
            "Bus error: Process terminated",
            "Fatal runtime error: Integer division by zero",
            "Compiler error: Expected '}' but found 'despair'",
            "Memory access violation at address 0xDEADBEEF"
        };

        std::vector<std::string> fakeWarnings = {
            "Warning: Possible undefined behavior detected in random places",
            "Warning: Expected ';' but found '?'",
            "Warning: Your code is 99% error-free. This is unacceptable.",
            "Warning: std::cout used too many times. Please stop."
        };

        std::vector<std::string> fakeFixes = {
            "Fix applied: All variables renamed to 'yolo'",
            "Fix applied: Deleted your main function. Hope it helps!",
            "Fix applied: Replaced all loops with `goto chaos;`",
            "Fix applied: AI-generated fix. Probably incorrect."
        };

        std::vector<std::string> fakeStackTrace = {
            "0xBADF00D - internal_compiler_error() at /dev/null:0",
            "0xDEADBEEF - crashNow() at broken_code.cpp:666",
            "0xC001C0DE - randomFunction() at ???:??",
            "0xF00DBABE - main() at unknown.cpp:42"
        };

        // 33% chance to freeze program (fake crash)
        if (scrambleDist(gen) == 0) {
            int freezeTime = delayDist(gen);
            std::cerr << "[ERROR] System unresponsive... (freezing for " << freezeTime << " seconds)\n";
            std::this_thread::sleep_for(std::chrono::seconds(freezeTime));
        }

        // Pick and print a random error
        std::string chosenError = errors[errorDist(gen)];
        std::cerr << chosenError << std::endl;

        // Scramble the error message (for extra confusion)
        if (scrambleDist(gen)) {
            for (char &c : chosenError) {
                if (std::isalpha(c)) c = c + ((errorDist(gen) % 3) - 1); 
            }
            std::cerr << "(Debug info: " << chosenError << ")" << std::endl;
        }

        // Print a fake stack trace
        std::cerr << "Stack trace (most recent call last):" << std::endl;
        for (const auto &trace : fakeStackTrace) {
            std::cerr << trace << std::endl;
        }

        // Print a fake warning
        if (warningDist(gen) == 0) {
            std::cerr << fakeWarnings[warningDist(gen)] << std::endl;
        }

        // Randomly pretend to "fix" the error
        if (crashDist(gen) == 1) {
            std::cerr << "Auto-fix applied: " << fakeFixes[warningDist(gen)] << std::endl;
        }

        // **NEW: Force user to type a phrase before continuing**
        if (typeForceDist(gen) == 0) {
            std::cerr << "\nTo resolve this error, type: 'I accept Twistify’s chaos' and press Enter: ";
            std::string input;
            std::getline(std::cin, input);
            while (input != "I accept Twistify’s chaos") {
                std::cerr << "Incorrect! The compiler demands respect. Try again: ";
                std::getline(std::cin, input);
            }
            std::cerr << "Fine, you may proceed...\n";
        }

        // **NEW: Write fake logs to file**
        std::ofstream logFile("twistify_log.txt", std::ios::app);
        if (logFile.is_open()) {
            logFile << "[ERROR] " << chosenError << "\n";
            logFile << "[INFO] Fake stack trace:\n";
            for (const auto &trace : fakeStackTrace) {
                logFile << trace << "\n";
            }
            logFile << "[FIX] Attempted fix: " << fakeFixes[warningDist(gen)] << "\n\n";
            logFile.close();
        }

        // **NEW: 20% chance to "crash" the program**
        if (crashDist(gen) == 0) {
            std::cerr << "Aborted (core dumped)\n";
            std::exit(1);
        }
    }
    void aiCodeReview() {
        static std::random_device rd;
        static std::mt19937 gen(rd());

        std::vector<std::string> insults = {
            "This code is a disgrace to bits and bytes.",
            "I've seen monkeys type better C++ than this.",
            "Did you mean to write C++ or was this accidental?",
            "Your logic is as stable as Windows ME.",
            "Congratulations! You've written an NP-Hard 'Hello World'."
        };

        std::vector<std::string> nonsenseTips = {
            "Remove all whitespace for better performance.",
            "C++ compiles faster if you type `using namespace God;`.",
            "Try replacing all `return` statements with `exit(0)`.",
            "Your `for` loops are too circular. Consider using squares."
        };

        std::vector<std::string> fakeWarnings = {
            "Warning: Detected excessive use of logic.",
            "Warning: Compiler running at 12% efficiency due to poor syntax.",
            "Warning: AI detected sadness in your code. Recommended fix: switch to Java.",
            "Warning: Your `main()` function has commitment issues."
        };

        std::cerr << "[AI CODE REVIEW] Running deep analysis...\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cerr << "[AI REVIEW] " << insults[gen() % insults.size()] << "\n";
        std::cerr << "[AI SUGGESTION] " << nonsenseTips[gen() % nonsenseTips.size()] << "\n";
        std::cerr << "[AI WARNING] " << fakeWarnings[gen() % fakeWarnings.size()] << "\n";

        std::cerr << "[AI OPTIMIZATION] Successfully increased runtime efficiency by -10%.\n";
        std::cerr << "[AI ANALYSIS] Sending performance report to NSA servers...\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void unpredictableDefineBomb() {
        std::cerr << "[WARNING] Enabling Unpredictable Defines...\n";

        std::ofstream header("twistify_chaos.h");
        if (header) {
            header << "#pragma once\n";
            header << "#define if while\n";
            header << "#define return break\n";
            header << "#define int double\n";
            header << "#define main int fakeMain()\n";
            header.close();
        }
    }

    void randomCodeInjection() {
        std::cerr << "[WARNING] Injecting Useless Code...\n";

        std::ofstream file("main.cpp", std::ios::app);
        if (file) {
            file << "\n// Quantum computing initialization\n";
            file << "std::cout << \"Initializing quantum matrix calculations...\\n\";\n";
            file.close();
        }
    }

    void timeTravelerBug() {
        std::cerr << "[WARNING] Activating Time Traveler Mode...\n";
        int result = std::system("date 01-01-1970");
        if (result != 0) {
            std::cerr << "[ERROR] Time Traveler Mode failed to activate.\n";
        }
    }

    void stealthyCorruptor() {
        std::cerr << "[WARNING] Corrupting a single character in your source...\n";

        std::string filename = "main.cpp"; 
        std::ifstream file(filename);
        if (file) {
            std::string code((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            file.close();

            if (code.size() > 1) {
                static std::random_device rd;
                static std::mt19937 gen(rd());
                int pos = std::uniform_int_distribution<int>(0, code.size() - 1)(gen);

                code[pos] = code[pos] == 'a' ? 'b' : 'a'; 

                std::ofstream outFile(filename);
                outFile << code;
                outFile.close();

                std::cerr << "[SUCCESS] Corruption complete. Good luck debugging.\n";
            }
        }
    }

}
