#!/bin/bash

# Compiler flags for optimizations and modern C++
CXX="g++"
CXXFLAGS="-O2 -std=c++17 -Wall -Wextra"

# Set color codes
RED='\033[1;31m'    # Bright Red for errors
GREEN='\033[1;32m'  # Bright Green for success
YELLOW='\033[1;33m' # Bright Yellow for process messages
BLUE='\033[1;34m'   # Bright Blue for headings
CYAN='\033[1;36m'   # Bright Cyan for details
BOLD='\033[1m'      # Bold text
NC='\033[0m'        # No color

# Compile the C++ source files
echo -e "${BLUE}${BOLD}🚀 Compiling source files...${NC}"
$CXX $CXXFLAGS generator.cpp -o generator || { echo -e "${RED}❌ Compilation error in generator.cpp${NC}"; exit 1; }
$CXX $CXXFLAGS brute.cpp -o brute || { echo -e "${RED}❌ Compilation error in brute.cpp${NC}"; exit 1; }
$CXX $CXXFLAGS best.cpp -o best || { echo -e "${RED}❌ Compilation error in best.cpp${NC}"; exit 1; }

# Optional iteration limit (default: unlimited)
max_iterations=${1:-1000}
iteration=1

while [ "$iteration" -le "$max_iterations" ] || [ "$max_iterations" -eq 0 ]; do
    echo -e "${YELLOW}${BOLD}➡️ Running test iteration: $iteration${NC}"

    # Generate test input
    ./generator > input.txt

    # Run both executables in parallel
    ./brute < input.txt > brute_output.txt &
    ./best < input.txt > best_output.txt
    wait  # Ensure both processes complete

    # Compare outputs
    if diff -q brute_output.txt best_output.txt > /dev/null; then
        echo -e "${GREEN}✅ Test $iteration passed.${NC}"
    else
        echo -e "${RED}❌ Mismatch found on iteration $iteration!${NC}"
        echo -e "${CYAN}------------------${NC}"
        echo -e "${BLUE}${BOLD}📥 Input:${NC}"
        cat input.txt
        echo -e "${CYAN}------------------${NC}"
        echo -e "${BLUE}${BOLD}🐢 Brute Output:${NC}"
        cat brute_output.txt
        echo -e "${CYAN}------------------${NC}"
        echo -e "${BLUE}${BOLD}⚡ Best Output:${NC}"
        cat best_output.txt
        echo -e "${CYAN}------------------${NC}"

        # Save the failing test case
        cp input.txt failed_input.txt
        # cp brute_output.txt failed_brute_output.txt
        # cp best_output.txt failed_best_output.txt
        echo -e "${RED}📂 Failed test case saved as failed_input.txt${NC}"
        exit 1
    fi

    iteration=$((iteration + 1))
done

echo -e "${GREEN}${BOLD}🎉 All tests passed successfully!${NC}"
