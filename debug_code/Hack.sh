#!/bin/bash

# Compiler flags for optimizations
CXX="g++"
CXXFLAGS="-O2 -std=c++17 -Wall -Wextra"

# Set color codes
RED='\033[1;31m'    # Bright Red for hacks found
GREEN='\033[1;32m'  # Bright Green for no issues
YELLOW='\033[1;33m' # Bright Yellow for process messages
BLUE='\033[1;34m'   # Bright Blue for headings
CYAN='\033[1;36m'   # Bright Cyan for details
BOLD='\033[1m'      # Bold text
NC='\033[0m'        # No color

# Compile the C++ source files
echo -e "${BLUE}${BOLD}🚀 Compiling source files...${NC}"
$CXX $CXXFLAGS generator.cpp -o generator || { echo -e "${RED}❌ Compilation error in generator.cpp${NC}"; exit 1; }
$CXX $CXXFLAGS good.cpp -o good || { echo -e "${RED}❌ Compilation error in good.cpp${NC}"; exit 1; }
$CXX $CXXFLAGS stupid.cpp -o stupid || { echo -e "${RED}❌ Compilation error in stupid.cpp${NC}"; exit 1; }

# Optional iteration limit (default: unlimited)
max_iterations=${1:-1000}
iteration=1

while [ "$iteration" -le "$max_iterations" ] || [ "$max_iterations" -eq 0 ]; do
    echo -e "${YELLOW}${BOLD}➡️ Running hack attempt: $iteration${NC}"

    # Generate test input
    ./generator > input.txt

    # Run both executables
    ./good < input.txt > good_output.txt &
    ./stupid < input.txt > stupid_output.txt
    wait  # Ensure both processes complete

    # Compare outputs
    if diff -q good_output.txt stupid_output.txt > /dev/null; then
        echo -e "${GREEN}✅ No hack found in attempt $iteration.${NC}"
    else
        echo -e "${RED}❌ Hack successful! Found counterexample on attempt $iteration.${NC}"
        echo -e "${CYAN}------------------${NC}"
        echo -e "${BLUE}${BOLD}📥 Input:${NC}"
        cat input.txt
        echo -e "${CYAN}------------------${NC}"
        echo -e "${BLUE}${BOLD}✅ Good Output:${NC}"
        cat good_output.txt
        echo -e "${CYAN}------------------${NC}"
        echo -e "${BLUE}${BOLD}❌ Stupid Output:${NC}"
        cat stupid_output.txt
        echo -e "${CYAN}------------------${NC}"

        # Save the failing test case
        cp input.txt hacked_input.txt
        # cp good_output.txt hacked_good_output.txt
        # cp stupid_output.txt hacked_stupid_output.txt
        echo -e "${RED}📂 Hacked test case saved as hacked_input.txt${NC}"
        exit 1
    fi

    iteration=$((iteration + 1))
done

echo -e "${GREEN}${BOLD}🎉 No hack found in $max_iterations attempts.${NC}"
