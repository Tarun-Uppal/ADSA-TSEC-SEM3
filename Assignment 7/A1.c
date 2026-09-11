#include <stdio.h>

#define MAX 100

int hashTable[MAX];
int tableSize;

int hashFunction(int key)
{
    return key % tableSize;
}

int secondHashFunction(int key)
{
    return 1 + (key % (tableSize - 1));
}

void linearProbing(int key)
{
    int index;
    int h = hashFunction(key);
    int locations = 0;
    for (int i = 0; i < tableSize; i++)
    {
        locations++;
        index = (h + i) % tableSize;
        if (hashTable[index] == -1)
        {
            hashTable[index] = key;
            printf("Key %d inserted at index %d\n", key, index);
            printf("Locations calculated: %d\n", locations);
            return;
        }
    }
    printf("Hash table is full!\n");
}

void quadraticProbing(int key)
{
    int index;
    int h = hashFunction(key);
    int locations = 0;

    for (int i = 0; i < tableSize; i++)
    {
        locations++;
        index = (h + i * i) % tableSize;
        if (hashTable[index] == -1)
        {
            hashTable[index] = key;
            printf("Key %d inserted at index %d\n", key, index);
            printf("Locations calculated: %d\n", locations);
            return;
        }
    }
    printf("Hash table is full!\n");
}

void doubleHashing(int key)
{
    int index;
    int h1 = hashFunction(key);
    int h2 = secondHashFunction(key);
    int locations = 0;

    for (int i = 0; i < tableSize; i++)
    {
        locations++;
        index = (h1 + i * h2) % tableSize;
        if (hashTable[index] == -1)
        {
            hashTable[index] = key;
            printf("Key %d inserted at index %d\n", key, index);
            printf("Locations calculated: %d\n", locations);
            return;
        }
    }
    printf("Hash table is full!\n");
}

void insertKeys(int keys[], int n, int choice)
{
    int totalLocations = 0;
    int before, after;

    for (int i = 0; i < n; i++)
    {
        before = 0;
        if (choice == 1)
        {
            int key = keys[i];
            int h = hashFunction(key);
            for (int j = 0; j < tableSize; j++)
            {
                int index = (h + j) % tableSize;
                if (hashTable[index] == -1)
                {
                    before = j + 1;
                    break;
                }
            }
            linearProbing(key);
        }
        else if (choice == 2)
        {
            int key = keys[i];
            int h = hashFunction(key);
            for (int j = 0; j < tableSize; j++)
            {
                int index = (h + j * j) % tableSize;
                if (hashTable[index] == -1)
                {
                    before = j + 1;
                    break;
                }
            }
            quadraticProbing(key);
        }
        else if (choice == 3)
        {
            int key = keys[i];
            int h1 = hashFunction(key);
            int h2 = secondHashFunction(key);
            for (int j = 0; j < tableSize; j++)
            {
                int index = (h1 + j * h2) % tableSize;
                if (hashTable[index] == -1)
                {
                    before = j + 1;
                    break;
                }
            }
            doubleHashing(key);
        }
        totalLocations += before;
    }
    printf("\nHash Table:\n");
    for (int i = 0; i < tableSize; i++)
    {
        if (hashTable[i] == -1)
            printf("Index %d : EMPTY\n", i);
        else
            printf("Index %d : %d\n", i, hashTable[i]);
    }
    printf("\nTotal locations calculated = %d\n", totalLocations);
    printf("Number of keys inserted     = %d\n", n);
    printf("Average locations calculated = %.2f\n",
           (float)totalLocations / n);
}

void main()
{
    int keys[MAX];
    int n;
    int choice;
    printf("Enter hash table size: ");
    scanf("%d", &tableSize);
    if (tableSize <= 1 || tableSize > MAX)
    {
        printf("Invalid table size!\n");
        return;
    }
    printf("Enter number of keys: ");
    scanf("%d", &n);
    if (n > tableSize || n <= 0)
    {
        printf("Invalid number of keys!\n");
        return;
    }
    printf("\nEnter %d keys:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &keys[i]);
    }
    do
    {
        printf("1 - Linear Probing\n");
        printf("2 - Quadratic Probing\n");
        printf("3 - Double Hashing\n");
        printf("4 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 3)
        {
            for (int i = 0; i < tableSize; i++)
            {
                hashTable[i] = -1;
            }
            printf("\n");
            insertKeys(keys, n, choice);
        }
        else if (choice == 4){
            printf("\nProgram terminated.\n");
        }
        else
        {
            printf("\nInvalid choice!\n");
        }
    } while (choice != 4);
}