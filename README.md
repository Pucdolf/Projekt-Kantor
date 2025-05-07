# Projekt Kantor

**Opis:** Aplikacja w C++ realizująca funkcjonalność prostego kantoru walutowego. Umożliwia użytkownikowi wymianę walut, wyświetlanie dostępnych kursów oraz historii transakcji.

## Spis treści

* [Opis](#opis)
* [Funkcje](#funkcje)
* [Technologie](#technologie)
* [Instalacja i uruchomienie](#instalacja-i-uruchomienie)
* [Użytkowanie](#użytkowanie)
* [Struktura projektu](#struktura-projektu)
* [Kontakt](#kontakt)

## Opis

Projekt Kantor to aplikacja konsolowa, która pozwala użytkownikowi wymieniać waluty według ustalonych kursów. Program przechowuje historię wymian i umożliwia wyświetlenie kursów oraz bilansu użytkownika.

## Funkcje

* Wymiana walut (np. PLN na EUR, USD na GBP itd.)
* Wyświetlanie dostępnych kursów
* Historia wykonanych transakcji
* Obsługa błędów (np. niewystarczające środki, niepoprawne dane)

## Technologie

* C++
* Standardowa biblioteka C++ (STL)
* Kompilator zgodny z C++20 lub nowszym

## Instalacja i uruchomienie

1. Sklonuj repozytorium lub wypakuj archiwum:

   ```bash
   git clone https://github.com/twoj-uzytkownik/ProjektKantor.git
   cd ProjektKantor
   ```
2. Zbuduj projekt:

   * Visual Studio: otwórz `ProjektKantor.sln`
   * G++ (przykład):

     ```bash
     g++ main.cpp Kantor.cpp -o KantorApp
     ```
3. Uruchom program:

   ```bash
   ./KantorApp
   ```

## Użytkowanie

Po uruchomieniu programu użytkownik trafia do głównego menu, z którego może przejść do trybu klienta lub administratora.

### Menu główne:

```
+---------------------+
| --Main Menu--       |
| 1. Klient           |
| 2. Administrator    |
| 3. Wyjdz            |
+---------------------+
Wybierz opcję [1-3]:
```

### Tryb klienta:

```
+--------------------------------------------------+
| 1. Wyświetl aktualne kursy walut                |
| 2. Dokonaj transakcji kupna waluty              |
| 3. Dokonaj transakcji sprzedaży waluty          |
| 4. Menu główne                                  |
| 5. Wyjście                                      |
+--------------------------------------------------+
Wybierz opcję [1-5]:
```

### Tryb administratora:

```
+--------------------------------------------------------------+
| --Admin--                                                   |
| 1. Wyświetl aktualne kursy walut                            |
| 2. Aktualizuj kursy walut                                   |
| 3. Pokaż zasoby                                             |
| 4. Dodaj zasoby                                             |
| 5. Pokaż historię transakcji                                |
| 6. Wyczyść historię transakcji                              |
| 7. Zmień hasło                                              |
| 8. Menu główne                                              |
| 9. Wyjście                                                  |
+--------------------------------------------------------------+
Wybierz opcję [1-9]:
```

## Struktura projektu

```
ProjektKantor/
├── main.cpp
├── Kantor.cpp
├── Kantor.h
├── kursy.txt           # plik z kursami walut
├── historia.txt        # zapis historii wymian
├── ProjektKantor.sln   # projekt Visual Studio (jeśli dotyczy)
└── README.md
```

## Kontakt

* Autor: Pucdolf
