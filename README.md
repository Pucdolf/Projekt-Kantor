# Kantor Project

**Description:** A C++ application providing basic currency exchange functionality. It allows users to exchange currencies, view current exchange rates, and check transaction history.

## Table of Contents

* [Description](#description)
* [Features](#features)
* [Technologies](#technologies)
* [Installation and Running](#installation-and-running)
* [Usage](#usage)
* [Project Structure](#project-structure)
* [Contact](#contact)

## Description

Kantor Project is a console application that allows users to exchange currencies based on set rates. The program stores exchange history and enables viewing rates and user balance.

## Features

* Currency exchange (e.g., PLN to EUR, USD to GBP, etc.)
* Displaying available exchange rates
* Transaction history
* Error handling (e.g., insufficient funds, invalid data)

## Technologies

* C++
* C++ Standard Library (STL)
* Compiler compatible with C++20 or newer

## Installation and Running

### Requirements
* Compiler: MSVC (Visual Studio 2022 recommended)
* System: Windows (due to the use of `system("cls")`)
* C++ Standard: C++17 or newer

### Installation Steps:
1. Clone the repository or extract the archive:
   ```bash
   git clone https://github.com/Pucdolf/PK2-ProjektKantor.git
   cd "PK2 - ProjektKantor"
   ```

2. Build the project:
   * **Visual Studio:** Open the `ProjektKantor.sln` file and select `Build Solution` (shortcut `Ctrl+Shift+B`).
   * **MSBuild (PowerShell):**
     ```powershell
     msbuild ProjektKantor.sln /p:Configuration=Debug /p:Platform=x64
     ```

3. Run the program:
   ```powershell
   .\x64\Debug\ProjektKantor.exe
   ```

## Usage

After starting the program, the user enters the main menu, from which they can switch to client or administrator mode.

### Main Menu:

```
+---------------------+
| --Main Menu--       |
| 1. Client           |
| 2. Administrator    |
| 3. Exit             |
+---------------------+
Select option [1-3]:
```

### Client Mode:

```
+--------------------------------------------------+
| 1. View current exchange rates                  |
| 2. Perform a buy transaction                    |
| 3. Perform a sell transaction                   |
| 4. Main Menu                                    |
| 5. Exit                                         |
+--------------------------------------------------+
Select option [1-5]:
```

### Admin Mode:

```
+--------------------------------------------------------------+
| --Admin--                                                   |
| 1. View current exchange rates                              |
| 2. Update exchange rates                                    |
| 3. Show resources                                           |
| 4. Add resources                                            |
| 5. Show transaction history                                 |
| 6. Clear transaction history                                |
| 7. Change password                                          |
| 8. Main Menu                                                |
| 9. Exit                                                     |
+--------------------------------------------------------------+
Select option [1-9]:
```

## Project Structure

```
ProjektKantor/
├── main.cpp
├── Kantor.cpp
├── Kantor.h
├── kursy.txt           # file with exchange rates
├── historia.txt        # transaction history log
├── ProjektKantor.sln   # Visual Studio solution (if applicable)
└── README.md
```

## Contact

* Author: Pucdolf
* Repository: [https://github.com/Pucdolf/Knapsack-Problem](https://github.com/Pucdolf/Knapsack-Problem)
