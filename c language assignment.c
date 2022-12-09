#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int MAX = 5;

typedef struct
{
    int roomID;
    int status;
    char custName[20];
} Room;

void printmenu();
void listOccupiedRooms();
void assignRoom();
void removeRoom();
void findCustomer(Room* ntu);

int main()
{

    Room ntu[5];
    int choice;
    int loop = 1;
    int i;

    for (i = 0; i < MAX; i++)
    {
        ntu[i].roomID = i + 1;
        ntu[i].status = 0;
        strcpy(ntu[i].custName, "NIL");
    }

    printmenu();
    while (loop == 1)
    {
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            listOccupiedRooms(ntu);
            break;
        }
        case 2:
        {
            assignRoom(&ntu);
            break;
        }
        case 3:
        {
            removeRoom(&ntu);
            break;
        }
        case 4:
        {
            findCustomer(&ntu);
            break;
        }
        case 5:
        {
            loop = 0;

            break;
        }
        default:
        {
            printf("That is not an option!\n\n");
            break;
        }
        }
    }

    return 0;
}

void printmenu()
{
    printf("NTU HOTEL ROOM RESERVATION PROGRAM:\n");
    printf("1: listOccupiedRooms()\n");
    printf("2: assignRoom()\n");
    printf("3: removeRoom()\n");
    printf("4: findCustomer()\n");
    printf("5: quit\n");

}

void listOccupiedRooms(Room ntu[])
{
    int i;
    int empty = 1;

    printf("listOccupiedRooms():\n");
    for (i = 0; i < MAX; i++)
    {
        if (ntu[i].status == 0)
            continue;

        else
        {
            empty = 0;
            break;
        }
    }

    if (empty == 0)
    {
        for (i = 0; i < MAX; i++)
        {
            if (ntu[i].status == 1)
            {
                printf("roomID: %d\n", ntu[i].roomID);
                printf("customer name: %s\n", ntu[i].custName);
            }

        }
    }
    else
        printf("The hotel is empty\n");
}

void assignRoom(Room* ntu)
{
    //SAMPLE CODE ON HOW TO USE POINTERS TO POINT AN ARRAY OF STRUCTURES
    //strcpy(ntu[0].custName , "yomama");
    //ntu[0].status = 1;
    //printf("room id:%d status: %d customer: %s\n\n", ntu[0].roomID , ntu[0].status , ntu[0].custName);

    int choice;
    int i;
    printf("assignRoom():\n");

    for (i = 0; i < MAX; i++) //check if hotel is full or not
    {
        if (ntu[i].status == 1)
            continue;

        else
            break;
    }

    if (i == MAX)
    {
        printf("The hotel is full\n");
        return;
    }
    while (1)
    {

        printf("Enter a roomID between 1 and 5:\n");
        scanf("%d", &choice);
        choice = choice - 1;

        if (choice == MAX)
            return;

        else if (choice > MAX || choice < 0)
            continue;

        else if (ntu[choice].status == 1)
            printf("Occupied! Enter another roomID\n");

        else
        {
            char* p;
            ntu[choice].status = 1;
            printf("Enter customer name:\n");
            //scanf("%s", &ntu[choice].custName);
            getchar();
            fgets(ntu[choice].custName, 20, stdin);
            if (p = strchr(ntu[choice].custName, '\n')) *p = '\0';
            //gets(ntu[choice].custName);
            //printf("room id:%d status: %d customer: %s\n\n", ntu[choice].roomID , ntu[choice].status , ntu[choice].custName);
            printf("The room has been assigned successfully\n");
            return;
        }
    }
}

void removeRoom(Room* ntu)
{
    int choice;
    int i;

    printf("removeRoom():\n");

    for (i = 0; i < MAX; i++)
    {
        if (ntu[i].status == 0)
            continue;

        else
            break;
    }

    if (i == 5)
    {
        printf("All the rooms are empty\n");
        return;
    }

    while (1)
    {
        printf("Enter a roomID between 1 and 5:\n");
        scanf("%d", &choice);
        getchar();
        choice = choice - 1;

        if (choice == MAX)
            return;

        else if (choice > MAX || choice < 0)
            continue;

        else if (ntu[choice].status == 0)
            printf("Empty! Enter another roomID for removal\n");

        else
        {
            ntu[choice].status = 0;
            strcpy(ntu[choice].custName, "NIL");
            //printf("room id:%d status: %d customer: %s\n", ntu[choice].roomID , ntu[choice].status , ntu[choice].custName);
            printf("Removal is successful\n");
            return;
        }
    }
}

void findCustomer(Room* ntu)
{
    char name[20];
    char checkname[20];
    int i = 0;
    int j = 0;
    int k = 0;
    char* p;

    printf("findCustomer():\n");
    printf("Enter customer name:\n");
    getchar();
    fgets(name, 20, stdin);
    if (p = strchr(name, '\n')) *p = '\0';

    while (name[i] != '\0')//change input to upper case
    {
        name[i] = toupper(name[i]);
        i++;
    }

    for (i = 0; i < MAX; i++)
    {
        strcpy(checkname, ntu[i].custName);

        j = 0;
        while (checkname[j] != '\0')//change checkname to upper case
        {
            checkname[j] = toupper(checkname[j]);
            j++;
        }
        //printf("%s\n",checkname);
        for (j = 0; j < 20; j++)
        {
            //printf("i: %d , j:%d , custname:%c , name:%c\n" , i , j , ntu[i].custName[j] , name[j]);
            if (checkname[j] != '\0' && name[j] != '\0' && checkname[j] == name[j])
                continue;

            else if (checkname[j] == '\0' && name[j] == '\0')//found
                break;

            else
                break;
        }

        if (checkname[j] == '\0' && name[j] == '\0')
            break;
    }

    if (i != 5 && j != 0)//target is found
    {
        printf("The target customer name is found\n");
        printf("roomID: %d\n", ntu[i].roomID);
        printf("customer name: %s\n", ntu[i].custName);
        return;
    }

    else
        printf("The target customer name is not found\n");

    return;
}
