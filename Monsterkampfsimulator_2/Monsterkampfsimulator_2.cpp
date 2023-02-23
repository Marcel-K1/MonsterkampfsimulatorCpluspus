// Monsterkampfsimulator_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// TO DO: const aus Strings und literalen machen und pointer aus den objecten machen und pointer lebenszyklus meaning delete etc einbauen

#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>
#include <WinUser.h>
#include <conio.h>
#include <stdio.h>
#include "Monster.h"
#include "Hilfsfunktionen.h"

//Forward Declarations
ERace GetUserInputRace(std::string);
ERace GetUserInputRace(std::string, Monster*);
float GetUserInputFloat(std::string);
void ClearWindow();


int main()
{
    bool endGame = true;

    do
    {
        ClearWindow();

        std::locale::global(std::locale("German_germany"));

        std::cout << "\t\t\tWILLKOMMEN ZU DEINEM MONSTERKAMPF!\n\n";

        Stats* pTempStats = new Stats();
        pTempStats->race = GetUserInputRace("Bitte gib eine Klasse für das 1.Monster ein! 1 = Ork, 2 = Troll, 3 = Goblin\n");
        pTempStats->healthPoints = GetUserInputFloat("Bitte gib ein, wie hoch die Lebenspunkte(HP) sein sollen! Erlaubt ist alles zwischen 1 und 100.\n");
        pTempStats->attackPoints = GetUserInputFloat("Bitte gib ein, wie hoch die Angriffspunkte(AP) sein sollen! Erlaubt ist alles zwischen 1 und 100.\n");
        pTempStats->defensePoints = GetUserInputFloat("Bitte gib ein, wie hoch die Abwehrpunkte(DP) sein sollen! Erlaubt ist alles zwischen 1 und 100.\n");
        pTempStats->speed = GetUserInputFloat("Bitte gib ein, wie hoch die Geschwindigkeit(S) sein soll! Erlaubt ist alles zwischen 1 und 100.\n");

        Monster* pMonsterA = new Monster(*pTempStats);
        //pTempStats = NULL;
        //delete pTempStats;

        ClearWindow();

        std::cout << "\t\t\tWILLKOMMEN ZU DEINEM MONSTERKAMPF!\n\n";

        std::cout << "\n1.Monster: " << pMonsterA->enum_to_string(pMonsterA->GetRace()) 
            << "\nLebenspunkte: " << pMonsterA->GetHealthPoints()
            << "\nAngriffspunkte: " << pMonsterA->GetAttackPoints() 
            << "\nAbwehrpunkte: " << pMonsterA->GetDefensePoints() 
            << "\nGeschwindigkeit: " << pMonsterA->GetSpeedPoints() << std::endl;

        
        std::stringstream sStream;
        sStream << "\nBitte gib eine Klasse für das 2.Monster ein! 1 = Ork, 2 = Troll, 3 = Goblin. Es darf kein " << pMonsterA->enum_to_string(pMonsterA->GetRace()) << " sein!\n";
        std::string sText = sStream.str(); 
        //pTempStats = new Stats();
        pTempStats->race = GetUserInputRace(sText, pMonsterA);
        sText.clear();
        sStream.str(std::string());
        pTempStats->healthPoints = GetUserInputFloat("Bitte gib ein, wie hoch die Lebenspunkte(HP) sein sollen! Erlaubt ist alles zwischen 1 und 100.\n");
        pTempStats->attackPoints = GetUserInputFloat("Bitte gib ein, wie hoch die Angriffspunkte(AP) sein sollen! Erlaubt ist alles zwischen 1 und 100.\n");
        pTempStats->defensePoints = GetUserInputFloat("Bitte gib ein, wie hoch die Abwehrpunkte(DP) sein sollen! Erlaubt ist alles zwischen 1 und 100.\n");
        pTempStats->speed = GetUserInputFloat("Bitte gib ein, wie hoch die Geschwindigkeit(S) sein soll! Erlaubt ist alles zwischen 1 und 100.\n");

        Monster* pMonsterB = new Monster(*pTempStats);
        pTempStats = NULL;
        delete pTempStats;

        std::cout << "\n2.Monster: " << pMonsterB->enum_to_string(pMonsterB->GetRace())
            << "\nLebenspunkte: " << pMonsterB->GetHealthPoints()
            << "\nAngriffspunkte: " << pMonsterB->GetAttackPoints()
            << "\nAbwehrpunkte: " << pMonsterB->GetDefensePoints()
            << "\nGeschwindigkeit: " << pMonsterB->GetSpeedPoints() << std::endl;

        Sleep(5000);

        ClearWindow();

        std::cout << "\t\t\tWILLKOMMEN ZU DEINEM MONSTERKAMPF!\n\n";

        pMonsterA->WhoAttacksFirst(*pMonsterA, *pMonsterB);


        //Key Input abfragen
        do
        {
            bool endWhile = true;
            
            std::string input;
            std::cout << "Noch eine Runde? Drücke 'j'. Zum Verlassen drücke 'n'.\n";
            getline(std::cin, input);
            if (input == "j")
            {
                ("Eine neue Runde!");
                Sleep(2000);
                pMonsterA->~Monster();
                pMonsterB->~Monster();
                input.clear();
                endGame = true;
                break;
            }
            else if (input == "n")
            {
                printf("Du verlässt den Monsterkampfsimulator.");
                Sleep(2000);
                pMonsterA->~Monster();
                pMonsterB->~Monster();
                input.clear();
                endGame = false;
                break;
            }
            else
            {
                printf("Du hast etwas falsches eingegeben. Bitte entweder 'j' oder 'n' und enter drücken.\n");
                Sleep(2000);
            }

        } while (true);


        //if (input == "j")
        //{
        //    ("Eine neue Runde!");
        //    Sleep(2000);
        //    monsterA->~Monster();
        //    monsterB->~Monster();
        //}
        //else if (input == "n")
        //{
        //    printf("Du verlässt den Monsterkampfsimulator.");
        //    Sleep(2000);
        //    monsterA->~Monster();
        //    monsterB->~Monster();
        //    break;
        //}
        //else
        //{
        //    continue;
        //}
         
         
        //if (_getch() == 0x4E)
        //{
        //    printf("Du verlässt den Monsterkampfsimulator.");
        //    Sleep(2000);
        //    monsterA->~Monster();
        //    monsterB->~Monster();
        //    break;
        //}
        //if (_getch() == 0x4A)
        //{
        //    printf("Eine neue Runde!");
        //    Sleep(2000);
        //    monsterA->~Monster();
        //    monsterB->~Monster();
        //}


        //if (GetAsyncKeyState('n') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        //{
        //    printf("Du verlässt den Monsterkampfsimulator.");
        //    Sleep(2000);
        //    monsterA->~Monster();
        //    monsterB->~Monster();
        //    break;
        //}
        //else if (GetAsyncKeyState('j') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        //{
        //    printf("Eine neue Runde!");
        //    Sleep(2000);
        //    monsterA->~Monster();
        //    monsterB->~Monster();
        //}


       /* if (WM_KEYUP)
        {
            switch (WPARAM wParam{})
            {
            case 0x4A:

                printf("Eine neue Runde!");
                Sleep(2000);
                monsterA->~Monster();
                monsterB->~Monster();
                continue;

            case 0x4E:

                printf("Du verlässt den Monsterkampfsimulator.");
                Sleep(2000);
                monsterA->~Monster();
                monsterB->~Monster();
                break;

            default:
                printf("Du verlässt den Monsterkampfsimulator.");
                Sleep(2000);
                monsterA->~Monster();
                monsterB->~Monster();
                break;
            }
        }*/


        //if (GetAsyncKeyState(VK_CLEAR))
        //{
        //    printf("Du verlässt den Monsterkampfsimulator.");
        //    Sleep(2000);
        //    monsterA->~Monster();
        //    monsterB->~Monster();
        //    break;
        //}
        //else if (GetAsyncKeyState(0x4A))
        //{
        //    printf("Eine neue Runde!");
        //    Sleep(2000);
        //    monsterA->~Monster();
        //    monsterB->~Monster();
        //}


        //std::string pressedKey{};
        //std::string endKey = "n";
        //std::string continueKey = "j";

        //if (input == endKey)
        //{
        //    break;
        //}

    } while (endGame);

    

    return 0;
}

float GetUserInputFloat(std::string _description)
{
    //do
    //{
    //    Console.WriteLine(_description);
    //    if (float.TryParse(Console.ReadLine(), out float input))
    //    {
    //        if (input > 0 && input <= 100)
    //        {
    //            return input;
    //        }
    //        else
    //        {
    //            Console.Clear();
    //            Console.WriteLine("!Bitte nur Zahlen von 1 - 100 eingeben!");
    //        }
    //    }
    //    else
    //    {
    //        Console.Clear();
    //        Console.WriteLine("!Bitte nur ganze Zahlen von 1 - 100 eingeben!");
    //    }
    //} while (true);

    while (std::cin) // CTRL-Z (or CTRL-D) and enter to quit
    {
        std::string input;
        float f;

        std::cout << _description; std::getline(std::cin, input);

        if (TryParse(input, f))
            {
                return f;
            }
        else std::cout << "!Bitte nur Zahlen von 1 - 100 eingeben!" << std::endl;
    }

}

ERace GetUserInputRace(std::string _description)
{
    //do
    //{
    //    Console.WriteLine(_description);
    //    if (int.TryParse(Console.ReadLine(), out int input))
    //    {
    //        if (input > 0 && input < 4)
    //        {
    //            return (ERace)input;
    //        }
    //        else
    //        {
    //            Console.Clear();
    //            Console.WriteLine("!Bitte nur Zahlen von 1 - 100 eingeben!");
    //        }
    //    }
    //    else
    //    {
    //        Console.Clear();
    //        Console.WriteLine("!Bitte nur ganze Zahlen von 1 - 100 eingeben!");
    //    }
    //} while (true);

    while (std::cin) // CTRL-Z (or CTRL-D) and enter to quit
    {
        std::string input;
        int i;

        std::cout << _description; std::getline(std::cin, input);

        if (TryParse(input, i))
        {
            if (i > 0 && i < 4)
                {
                    return (ERace)i;
                }
            else std::cout << "!Bitte nur Zahlen von 1 - 100 eingeben!" << std::endl;

        }
        else std::cout << "!Bitte nur Zahlen von 1 - 100 eingeben!" << std::endl;
    }
}

ERace GetUserInputRace(std::string _description, Monster* _other)
{
    while (std::cin) // CTRL-Z (or CTRL-D) and enter to quit
    {
        std::string input;
        int i;

        std::cout << _description; std::getline(std::cin, input);

        if (TryParse(input, i))
        {
            if (i > 0 && i < 4)
            {
                if (!((ERace)i == _other->GetRace()))
                    return (ERace)i;
            }
            else std::cout << "!Bitte nur ganze Zahlen von 1 - 3 eingeben!" << std::endl;

        }
        else std::cout << "!Bitte nur ganze Zahlen von 1 - 3 eingeben!" << std::endl;
    }
}

void ClearWindow()
{
    /*std::cout << "\x1B[2J\x1B[H";*/

    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}






