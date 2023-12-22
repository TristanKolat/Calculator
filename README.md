# Calculator

Utilizes various patterns to implement basic calculations for "+, -, *, /, %" operations.

## Overview

This repository contains the implementation of a custom calculator leveraging unique array and stack structures. It incorporates command and abstract command factory patterns, enabling a robust and extendable calculator application.

## Features

- **Custom Array and Stack**: Implemented from scratch to optimize calculator operations.
- **Design Patterns**: Utilizes wrapper facade, templates, command, and abstract factory patterns for a modular and scalable codebase.
- **Simple Command-Line Interface**: For easy operation.

### Wrapper Facade
The Stack class acts as a facade, providing a simplified interface (push, pop, top, is_empty, etc.) to the underlying Array class, which manages the actual storage of elements. This encapsulation allows the Stack to expose only relevant stack operations and hide the complexity of array management.

### Templates
In the InfixtoPostfix, Stack and Array classes, C++ templates are used to enable handling of various data types, ensuring both versatility and type safety.

### Command
The Command Pattern is implemented to encapsulate mathematical operations as objects, enhancing the calculator's versatility and extensibility. The current implementation supports addition, subtraction, division, multiplication, and modulus operations, along with open and closed parenthesis commands for managing operator precedence. This design allows for the easy integration of new operations, ensuring that extending functionality is straightforward and does not impact existing code. The pattern also ensures a consistent interface across different commands and handles the complexities of operation precedence, making the system robust and maintainable. This approach exemplifies a forward-thinking design that facilitates future growth and modifications of the software's capabilities.

### Abstract Factory
The project utilizes the Abstract Factory Pattern to facilitate the conversion of infix mathematical expressions into postfix format. This is achieved through `Expr_Command_Factory`, an abstract base class that outlines the interface for creating command objects for various operations like addition, subtraction, and handling parentheses. The `Stack_Expr_Command_Factory`, a concrete implementation of this abstract factory, specifically creates command objects designed to work with a stack, enabling the correct handling and precedence of operations. This design not only ensures accurate conversion and evaluation of expressions but also provides flexibility and extensibility, allowing for easy integration of new operations or functionalities in the future. The use of this pattern exemplifies a structured approach to managing complex expression evaluations in a maintainable and scalable manner.

## Getting Started

### Installation

1. Clone the repository to your local machine.
2. Navigate to the repository directory.

### Compilation

1. Make sure `Makefile` and `Makefile.calculator` are present in the root of the repository.
2. Compile the calculator using:
3. make

### Running the Calculator

1. To start the calculator, use:
2. ./calculator

When inputting commands, add spaces between tokens. Example:
5+4

Note: For negative numbers, spaces are not required (e.g., -9).
