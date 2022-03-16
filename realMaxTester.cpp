#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "realMaxTester.hpp"
#include "HashTable.h"
#include <iostream>

using namespace std;

bool fullPass = true;
bool individualPass = true;

// This is where you can edit the tasks that the tester will perform
void tasks()
{
    steveJobsTest0();
    steveJobsTest1();
    steveJobsTest2();
}

void steveJobsTest0()
{
    cout << endl
         << "Steve Jobs' Test 0: Checks if HashTables are created of appropriate sizes (slightly modified to be harder)" << endl;

    typedef HashTable<string, int> HTSI;
    typedef HashNode<string, int> HNSI;
    HTSI hashtable1, hashtable2(113);
    HNSI N;

    if (hashtable1.size() != 11)
    {
        failIndividual();
    }
    displayTest("Checks default HashTable size is 11");
    cout << endl
         << "\tSize: " + to_string(hashtable1.size()) << endl;

    if (hashtable2.size() != 113)
    {
        failIndividual();
    }
    displayTest("Creates HashTable of size 113");
    cout << endl
         << "\tSize: " + to_string(hashtable2.size()) << endl;

    if (HTSI(12000).size() != 12000)
    {
        failIndividual();
    }
    displayTest("Creates HashTable of size 12000");
    cout << endl
         << "\tSize: " + to_string(HTSI(12000).size()) << endl;
    cout << endl;
}

void steveJobsTest1()
{
    cout << endl
         << "Steve Jobs' Test 1: Checks if HashTables can store values correctly" << endl;

    typedef HashTable<string, int> HTSI;
    typedef HashNode<string, int> HNSI;
    typedef HashTable<string, string> HTSS;
    typedef HashNode<string, string> HNSS;
    HTSI T1(117), T2;
    HNSI N;

    N.assign("AC21008", 21008);
    if (N.getKey() != "AC21008" || N.getValue() != 21008)
    {
        failIndividual();
    }
    displayTest("Creates HashNode with Key of \"AC21008\" and integer value of 21008 and gets the value back");
    cout << endl
         << "\tKey: " << N.getKey() << "\tValue: " << N.getValue() << endl;

    T1.insert("Hello", 17);
    T1.insert("World", 19);
    T1.insert("abc", 12);
    if (T1.getValue("Hello") != 17 || T1.getValue("abc") != 12 || T1.getValue("World") != 19)
    {
        failIndividual();
    }
    displayTest("Inserts integers onto HashTable of size 117 with keys as strings and gets the values back");
    cout << endl
         << "\tValue 1: " << T1.getValue("Hello") << "\tValue 2: " << T1.getValue("abc") << "\tValue 3: " << T1.getValue("World") << endl;

    T2.insert("AAAA", 39);
    T2.insert("AAA", 42);
    T2.insert("A", 76);
    if (T2.getValue("AAAA") != 39 || T2.getValue("A") != 76 || T2.getValue("AAA") != 42)
    {
        failIndividual();
    }
    displayTest("Inserts integers onto HashTable of default size with keys as strings and gets the values back");
    cout << endl
         << "\tValue 1: " << T2.getValue("AAAA") << "\tValue 2: " << T2.getValue("AAA") << "\tValue 3: " << T2.getValue("A") << endl;

    HNSS N2;

    N2.assign("AC21008", "21008");
    if (N2.getKey() != "AC21008" || N2.getValue() != "21008")
    {
        failIndividual();
    }
    displayTest("Creates HashNode with Key of \"AC21008\" and value of \"21008\" and gets the value back");
    cout << endl
         << "\tKey: " << N2.getKey() << "\tValue: " << N2.getValue() << endl;

    HTSS T3(97), T4;
    T3.insert("Hello", "17");
    T3.insert("World", "19");
    T3.insert("abc", "12");
    if (T3.getValue("Hello") != "17" || T3.getValue("abc") != "12" || T3.getValue("World") != "19")
    {
        failIndividual();
    }
    displayTest("Inserts strings onto HashTable of size 97 with keys as strings and gets the values back");
    cout << endl
         << "\tValue 1: " << T3.getValue("Hello") << "\tValue 2: " << T3.getValue("abc") << "\tValue 3: " << T3.getValue("World") << endl;

    T4.insert("AAAA", "39");
    T4.insert("AAA", "42");
    T4.insert("A", "76");
    if (T4.getValue("AAAA") != "39" || T4.getValue("A") != "76" || T4.getValue("AAA") != "42")
    {
        failIndividual();
    }
    displayTest("Inserts strings onto HashTable of default size with keys as strings and gets the values back");
    cout << endl
         << "\tValue 1: " << T4.getValue("AAAA") << "\tValue 2: " << T4.getValue("AAA") << "\tValue 3: " << T4.getValue("A") << endl;

    cout << endl;
}

void steveJobsTest2()
{
    cout << endl
         << "Steve Jobs' Test 2: " << endl;

    typedef HashTable<string, int> HTSI;
    typedef HashTable<int, int> HTII;

    HTSI T1(117);
    int s;

    T1.insert("Hello", 17);
    T1.insert("World", 19);
    T1.insert("abc", 12);
    s = T1.size();
    T1.rehash(2 * s);
    if (T1.size() < 2 * s)
    {
        failIndividual();
    }
    displayTest("Rehashes HashTable from size 117 to 234");
    cout << endl;

    if (T1.getValue("Hello") != 17 || T1.getValue("abc") != 12 || T1.getValue("World") != 19)
    {
        failIndividual();
    }
    displayTest("Checks that HashNodes present before rehashing can still be accessed");
    cout << endl;

    T1.insert("AAAA", 39);
    T1.insert("AAA", 42);
    T1.insert("A", 76);
    if (T1.getValue("AAAA") != 39 || T1.getValue("A") != 76 || T1.getValue("AAA") != 42)
    {
        // cout << "Values are not stored correctly." << endl;
        failIndividual();
    }
    displayTest("Inserts strings onto HashTable with keys as strings and gets the values back");
    cout << endl;

    T1.erase("AAA");
    T1.erase("World");

    if (T1.getValue("Hello") != 17 || T1.getValue("abc") != 12 || T1.getValue("AAAA") != 39 || T1.getValue("A") != 76)
    {
        // cout << "Values are not stored correctly." << endl;
        failIndividual();
    }
    displayTest("Erases some nodes and checks that other nodes are still accessible");
    cout << endl;

    HTII T3(173);
    int num = static_cast<int>(T3.size());
    for (int i = 0; i < num; i++)
    {
    T1.insert("AAAA", 39);
    T1.insert("AAA", 42);
    T1.insert("A", 76);
    }
    for (int i = 0; i < num; i++)
    {
        if (T3.getValue(9 * i * i + 11 * i + 13) != 2 * i - 1)
        {
            // cout << "Integer values are not stored correctly." << endl;
            failIndividual();
            // cout << endl;
        }
    }
    for (int i = 0; i < num; i = i + 2)
    {
        T3.erase(9 * i * i + 11 * i + 13);
    }
    for (int i = 1; i < num; i = i + 2)
    {
        if (T3.getValue(9 * i * i + 11 * i + 13) != 2 * i - 1)
        {
            // cout << "Integer values are not stored correctly after erasing." << endl;
            failIndividual();
            // cout << endl;
        }
    }
    for (int i = 0; i < num; i = i + 2)
    {
        T3.insert(9 * i * i + 11 * i + 13, 3 * i - 1);
    }
    for (int i = 0; i < num; i++)
    {
        if (i % 2)
        {
            if (T3.getValue(9 * i * i + 11 * i + 13) != 2 * i - 1)
            {
                // cout << "Integer values are not stored correctly after erasing and reinserting." << endl;
                failIndividual();
                // cout << endl;
            }
        }
        else
        {
            if (T3.getValue(9 * i * i + 11 * i + 13) != 3 * i - 1)
            {
                // cout << "Integer values are not stored correctly after erasing and reinserting." << endl;
                failIndividual();
                // cout << endl;
            }
        }
    }

    cout << endl;
}

void displayIntro()
{
    system("clear");
    cout << "Real Max Tester for Assignment 3 in Computer Systems 2A" << endl;
    cout << "Use wisely" << endl;
}

void displayTest(string str)
{
    cout << endl;
    if (individualPass)
    {
        cout << "\033[32m"
             << "[PASS]";
        cout << "\033[0m"
             << "\t" << str;
    }
    else
    {
        cout << "\033[31m"
             << "[FAIL]";
        cout << "\033[39;49m"
             << "\t" << str;
        individualPass = true;
    }
}

void roast()
{
    int randVal = rand() % 2;
    switch (randVal)
    {
    case 0:
        cout << "You code is worse than Uncle Ian's memes" << endl;
        break;
    case 1:
        cout << "If this program marked you like Mike Crabbs, you'd just fail the module" << endl;
        break;
    default:
        cout << "Whatever you think is causing this, it's not the problem" << endl;
    }
}

void concern()
{
    int randVal = rand() % 2;
    switch (randVal)
    {
    case 0:
        cout << "Your limitation — it’s only your imagination";
        break;
    default:
        cout << "Push yourself, because no one else is going to do it for you.";
        break;
    }
}

void displayFail()
{
    cout << R"(
        ______      _  _ 
        |  ___|    (_)| |
        | |_  __ _  _ | |
        |  _|/ _` || || |
        | | | (_| || || |
        \_|  \__,_||_||_|            
    )";
    cout << endl;
}

void displayPass()
{
    cout << R"(
         _____            
        /  ___|                                 
        \ `--.  _   _   ___  ___  ___  ___  ___ 
         `--. \| | | | / __|/ __|/ _ \/ __|/ __|
        /\__/ /| |_| || (__| (__|  __/\__ \\__ \
        \____/  \__,_| \___|\___|\___||___/|___/
    )";
    cout << endl;
}

void failIndividual()
{
    fullPass = false;
    individualPass = false;
}

void oops(int sig)
{
    failIndividual();
    cout << "Oops there's a fault here: " << sig << endl;
    displayFail();
    int randVal = rand() % 100;

    if (randVal < 15)
    {
        roast();
    }
    else if (randVal < 30)
    {
        concern();
    }
}

int catchSegFault()
{
    struct sigaction act;
    act.sa_handler = oops;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGINT, &act, 0);
    return 0;
}

void checkSuccess()
{
    if (fullPass)
    {
        displayPass();
    }
    else
    {
        displayFail();
    }
}

int main()
{
    catchSegFault();
    displayIntro();
    tasks();
    checkSuccess();
    return 0;
}