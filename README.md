# Vending Machine Simulation

## Overview
This project simulates a basic vending machine that manages inventory and sales transactions. It demonstrates object-oriented programming practices in C++, including the use of custom exceptions for error handling.

## Program Structure
- **VendingMachine.h/cpp**: Defines the `VendingMachine` class, encapsulating the logic for inventory management and sales transactions.
- **CustomException.h**: Contains the `CustomException` class for specific error handling scenarios within the vending machine operations.
- **main.cpp**: The entry point of the program, demonstrating various functionalities of the `VendingMachine` class and error handling.
- **Makefile**: Facilitates the building, cleaning, and rebuilding of the program from source files.

## Input/Output Files
- **Input**: The program takes no external input files. All test cases and demonstrations are coded within `main.cpp`.
- **Output**: Logs transaction details and error messages to the console and `test_results.txt` file, providing insights into the vending machine's operations and exception handling.

## Running the Program

1. **Building the Program**: Use the Makefile to compile and link the project. In the project directory, run:

    ```
    make
    ```
    or
    ```
    mingw32-make
    ```

This command compiles the source files into `.o` (object) files and then links these to create the executable `vending_machine`.

2. **Running the Executable**: Execute the program by running:
- On Linux/macOS:
  ```
  ./vending_machine
  ```
- On Windows:
  ```
  vending_machine.exe
  ```

3. **Cleaning Build Files**: To remove object files and the executable, ensuring a clean state for a rebuild, run:
    ```
    make clean
    ```
    or
    ```
    mingw32-make clean
    ```


4. **Rebuilding the Program**: To clean up and then build the project from scratch, use:
    ```
    make rebuild
    ```
    or
    ```
    mingw32-make rebuild
    ```
