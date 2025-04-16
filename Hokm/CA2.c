#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "functions.h"

int main()
{
    // each player has a 2d array which by defult is 0
    int i, arr[44], player1[4][11] = {0}, player2[4][11] = {0}, player3[4][11] = {0}, player4[4][11] = {0};
    int card_num1[11] = {0}, card_num2[11], card_num3[11], card_num4[11];
    char card_type1[11], card_type2[11], card_type3[11], card_type4[11];

    shuffle_card(arr);

    // we mark each card we have with 1

    // deal 5 cards to each player
    for (i = 0; i < 5; i++)
        player1[arr[i] / 11][arr[i] % 11] = 1;
    for (i = 5; i < 10; i++)
        player2[arr[i] / 11][arr[i] % 11] = 1;
    for (i = 10; i < 15; i++)
        player3[arr[i] / 11][arr[i] % 11] = 1;
    for (i = 15; i < 20; i++)
        player4[arr[i] / 11][arr[i] % 11] = 1;

    // deal 4 cards to each player
    for (i = 20; i < 24; i++)
        player1[arr[i] / 11][arr[i] % 11] = 1;
    for (i = 24; i < 28; i++)
        player2[arr[i] / 11][arr[i] % 11] = 1;
    for (i = 28; i < 32; i++)
        player3[arr[i] / 11][arr[i] % 11] = 1;
    for (i = 32; i < 36; i++)
        player4[arr[i] / 11][arr[i] % 11] = 1;

    // deal 2 cards to each player
    for (i = 36; i < 38; i++)
        player1[arr[i] / 11][arr[i] % 11] = 1;
    for (i = 38; i < 40; i++)
        player2[arr[i] / 11][arr[i] % 11] = 1;
    for (i = 40; i < 42; i++)
        player3[arr[i] / 11][arr[i] % 11] = 1;
    for (i = 42; i < 44; i++)
        player4[arr[i] / 11][arr[i] % 11] = 1;

    // now we convert 0 & 1 to card types and card numbers
    convert(player1, card_type1, card_num1);
    convert(player2, card_type2, card_num2);
    convert(player3, card_type3, card_num3);
    convert(player4, card_type4, card_num4);

    // player choose bakhshnameh between these cards
    for (int i = 0; i < 11; i += 2)
        printf("| %c%d ", card_type1[i], card_num1[i]);

    printf("|\n");

    int quit = 1;
    char bakhshnameh;

    while (quit)
    {
        printf("Enter Bakhshnameh: ");
        scanf(" %c", &bakhshnameh); // input a char to choose bakhshnameh
        switch (bakhshnameh)
        {
        case 'A':
            quit = 0;
            break;
        case 'B':
            quit = 0;
            break;
        case 'C':
            quit = 0;
            break;
        case 'D':
            quit = 0;
            break;
        default:
            printf("not valid, try again!\n");
            break;
        }
    }

    int team1 = 0, team2 = 0, index, turn = 1, exit;
    char zamineh;
    // first time print the table without any cards
    table(bakhshnameh, index, 0, card_num1, card_type1, card_num2, card_type2, card_num3, card_type3, card_num4, card_type4, team1, team2);

    while (team1 < 6 && team2 < 6)
    {
        switch (turn)
        {
        case 1: //player one's turn
            exit = 1;
            while (exit)
            {
                printf("\n\nBakhshnameh: %c\nEnter your card: ", bakhshnameh);
                scanf("%d", &index);
                if (index < 11)
                {
                    table(bakhshnameh, index, turn, card_num1, card_type1, card_num2, card_type2, card_num3, card_type3, card_num4, card_type4, team1, team2);
                    zamineh = card_type1[index];
                    turn = winner(bakhshnameh, index, zamineh, card_num1, card_type1, card_num2, card_type2, card_num3, card_type3, card_num4, card_type4);
                    exit = 0;
                }
                else
                    printf("not valid, try again!");
            }
            if (turn == 1 || turn == 3)
                team1++;
            if (turn == 2 || turn == 4)
                team2++;
            break;
        case 2: //player two's turn
            table(bakhshnameh, index, turn, card_num1, card_type1, card_num2, card_type2, card_num3, card_type3, card_num4, card_type4, team1, team2);
            exit = 1;
            while (exit)
            {
                printf("\n\nBakhshnameh: %c\nEnter your card: ", bakhshnameh);
                scanf("%d", &index);
                if (index < 11)
                {
                    zamineh = comp_start(card_type2, card_num2, 1);
                    turn = winner(bakhshnameh, index, zamineh, card_num1, card_type1, card_num2, card_type2, card_num3, card_type3, card_num4, card_type4);
                    exit = 0;
                }
                else
                    printf("not valid, try again!");
            }
            if (turn == 1 || turn == 3)
                team1++;
            if (turn == 2 || turn == 4)
                team2++;
            break;
        case 3: //player three's turn
            table(bakhshnameh, index, turn, card_num1, card_type1, card_num2, card_type2, card_num3, card_type3, card_num4, card_type4, team1, team2);
            exit = 1;
            while (exit)
            {
                printf("\n\nBakhshnameh: %c\nEnter your card: ", bakhshnameh);
                scanf("%d", &index);
                if (index < 11)
                {
                    zamineh = comp_start(card_type3, card_num3, 1);
                    turn = winner(bakhshnameh, index, zamineh, card_num1, card_type1, card_num2, card_type2, card_num3, card_type3, card_num4, card_type4);
                    exit = 0;
                }
                else
                    printf("not valid, try again!");
            }
            if (turn == 1 || turn == 3)
                team1++;
            if (turn == 2 || turn == 4)
                team2++;
            break;
        case 4: //player four's turn
            table(bakhshnameh, index, turn, card_num1, card_type1, card_num2, card_type2, card_num3, card_type3, card_num4, card_type4, team1, team2);
            exit = 1;
            while (exit)
            {
                printf("\n\nBakhshnameh: %c\nEnter your card: ", bakhshnameh);
                scanf("%d", &index);
                if (index < 11)
                {
                    zamineh = comp_start(card_type4, card_num4, 1);
                    turn = winner(bakhshnameh, index, zamineh, card_num1, card_type1, card_num2, card_type2, card_num3, card_type3, card_num4, card_type4);
                    exit = 0;
                }
                else
                    printf("not valid, try again!");
            }
            if (turn == 1 || turn == 3)
                team1++;
            if (turn == 2 || turn == 4)
                team2++;
            break;
        }
    }

    if (team1 == 6)
        printf("\nteam 1 has won!");
    if (team2 == 6)
        printf("\nteam 1 has won!");
}