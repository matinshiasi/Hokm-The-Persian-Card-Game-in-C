void shuffle_card(int *card)
{
    int i, r, temp;
    for (temp = 0, i = 0; temp < 44; i++, temp++)
        card[temp] = i;
    srand(time(NULL));
    for (i = 43; i > 0; i--)
    {
        r = rand() % i;
        temp = card[i];
        card[i] = card[r];
        card[r] = temp;
    }
}

void convert(int arr1[4][11], char card_type[11], int card_num[11])
{
    // this function convert 0 & 1 to card types and card numbers
    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (arr1[i][j] == 1)
            {
                if (i == 0)
                {
                    card_type[k] = 'A';
                    card_num[k] = j + 1;
                    k++;
                }
                if (i == 1)
                {
                    card_type[k] = 'B';
                    card_num[k] = j + 1;
                    k++;
                }
                if (i == 2)
                {
                    card_type[k] = 'C';
                    card_num[k] = j + 1;
                    k++;
                }
                if (i == 3)
                {
                    card_type[k] = 'D';
                    card_num[k] = j + 1;
                    k++;
                }
            }
        }
    }
}

int player_move(char bakhshnameh, char zamineh, int card_num[11], char card_type[11], int state)
{
    // this function defines what type of card to play and play the biggest number
    char played_type = '\0';
    int played_num = 0;
    int true = 0, flag = 0;
    for (int i = 0; i < 11; i++)
    {
        if (card_type[i] == zamineh)
        {
            if (card_num[i] > played_num)
            {
                played_type = card_type[i];
                played_num = card_num[i];
                flag = i;
                true = 1;
            }
        }
    }

    if (true == 0)
    {
        for (int i = 0; i < 11; i++)
        {
            if (card_type[i] == bakhshnameh)
            {
                if (card_type[i] != zamineh)
                {
                    if (card_num[i] > played_num)
                    {
                        played_type = card_type[i];
                        played_num = card_num[i];
                        flag = i;
                        true = 1;
                    }
                }
            }
        }
    }

    if (true == 0)
    {
        for (int i = 0; i < 11; i++)
        {
            if (card_type[i] != zamineh && card_type[i] != bakhshnameh)
            {
                played_num = 12;
                if (card_num[i] < played_num)
                {
                    played_type = card_type[i];
                    played_num = card_num[i];
                    flag = i;
                }
            }
        }
    }

    if (true == 1)
    {
        card_type[flag] = '\0';
        card_num[flag] = 0;
    }
    
    // we use state further away to help what kind of return we need
    if (state == 1)
        printf("%c%d", played_type, played_num);
    if (state == 2)
        return played_num;
}

char player_move_char(char bakhshnameh, char zamineh, int card_num[11], char card_type[11])
{
    char played_type = '\0';
    int played_num = 0;
    int true = 0;
    for (int i = 0; i < 11; i++)
    {
        if (card_type[i] == zamineh)
        {
            if (card_num[i] > played_num)
            {
                played_type = card_type[i];
                played_num = card_num[i];
                card_type[i] = '\0';
                card_num[i] = 0;
                true = 1;
            }
        }
    }

    if (true == 0)
    {
        for (int i = 0; i < 11; i++)
        {
            if (card_type[i] == bakhshnameh)
            {
                if (card_type[i] != zamineh)
                {
                    if (card_num[i] > played_num)
                    {
                        played_type = card_type[i];
                        played_num = card_num[i];
                        card_type[i] = '\0';
                        card_num[i] = 0;
                        true = 1;
                    }
                }
            }
        }
    }
    if (true == 0)
    {
        for (int i = 0; i < 11; i++)
        {
            if (card_type[i] != zamineh && card_type[i] != bakhshnameh)
            {
                played_num = 12;
                if (card_num[i] < played_num)
                {
                    played_type = card_type[i];
                    played_num = card_num[i];
                    card_type[i] = '\0';
                    card_num[i] = 0;
                }
            }
        }
    }
    return played_type;
}

void table(char bakhshnameh, int index, int turn, int card_num1[11], char card_type1[11], int card_num2[11], char card_type2[11],
           int card_num3[11], char card_type3[11], int card_num4[11], char card_type4[11], int round_counter1, int round_counter2)
{
    // table function prints game table
    int i, j;
    char zamineh;
    if (turn == 1)
        zamineh = card_type1[index];
    if (turn == 2)
        zamineh = comp_start(card_type2[11], card_num2[11], 1);
    if (turn == 3)
        zamineh = comp_start(card_type3[11], card_num3[11], 1);
    if (turn == 4)
        zamineh = comp_start(card_type4[11], card_num4[11], 1);
    
    
    
    system("cls"); // this helps to clear screen each time
    printf("\t\t\t\tP3\n\t");

    for (i = 0; i < 49; i++)
    {
        printf("-");
    }
    printf("\tteam 1: %d", round_counter1); // round counter update each round
    for (j = 0; j < 16; j++)
    {
        if (j == 0)
        {
            printf("\n\t|\t\t\t");
            if (turn == 3) // if player 3 have to start the game
                comp_start(card_type3, card_num3, 0);
            // esle if other players start and it playes base on their card
            if (turn == 1)
                player_move(bakhshnameh, zamineh, card_num3, card_type3, 1);
            if (turn == 2)
                player_move(bakhshnameh, zamineh, card_num3, card_type3, 1);
            if (turn == 4)
                player_move(bakhshnameh, zamineh, card_num3, card_type3, 1);
            printf("\t\t\t|");
        }
        if (j == 8)
        {
            printf("\n      P2|");
            if (turn == 2) // if player 2 have to start the game
                comp_start(card_type2[11], card_num2[11], 0);
            // esle if other players start and it playes base on their card
            if (turn == 1)
                player_move(bakhshnameh, zamineh, card_num2, card_type2, 1);
            if (turn == 3)
                player_move(bakhshnameh, zamineh, card_num2, card_type2, 1);
            if (turn == 4)
                player_move(bakhshnameh, zamineh, card_num2, card_type2, 1);
            printf("\t\t\t\t\t\t ");

            printf("\b\b\b");
            if (turn == 4) // if player 4 have to start the game
                comp_start(card_type4[11], card_num4[11], 0);
            // esle if other players start and it playes base on their card
            if (turn == 1)
                player_move(bakhshnameh, zamineh, card_num4, card_type4, 1);
            if (turn == 2)
                player_move(bakhshnameh, zamineh, card_num4, card_type4, 1);
            if (turn == 3)
                player_move(bakhshnameh, zamineh, card_num4, card_type4, 1);

            printf("|P4");
        }
        else if (j == 15)
            if (index > 11)
                printf(" ");
            else
                printf("\n        |\t\t\t%c%d\t\t\t|", card_type1[index], card_num1[index]); // it prints my card
        else
            printf("\n\t|\t\t\t\t\t\t|");
    }
    printf("\n\t");
    for (i = 0; i < 49; i++)
    {
        printf("-");
    }
    printf("\tteam 2: %d", round_counter2); // round counter update each round
    printf("\n\t\t\t\tP1");
    printf("\n\t-------------------------------------------------\n");
    printf("Symbol\t");
    for (i = 0; i < 11; i++)
    {
        if (i == index)
            printf("| - |"); // show a dash for each card played
        else
            printf("| %c |", card_type1[i]);
    }

    printf("\n\t-------------------------------------------------\n");
    printf("Number\t");
    for (i = 0; i < 11; i++)
    {
        if (i == index)
            printf("| - |"); // show a dash for each card played
        else
            printf("|%2d |", card_num1[i]);
    }

    printf("\n\t-------------------------------------------------");
    printf("\nindex\t  0    1    2    3    4    5    6    7    8    9   10\n"); // cards index
}

int winner(char bakhshnameh, int index, char zamineh, int card_num1[11], char card_type1[11], int card_num2[11],
           char card_type2[11], int card_num3[11], char card_type3[11], int card_num4[11], char card_type4[11])
{
    // winner function shows each round who wins and played greatest valued card

    int turn = 0, temp = 0;

    // here we have initial values
    char t2 = player_move_char(bakhshnameh, zamineh, card_num2, card_type2);
    int n2 = player_move(bakhshnameh, zamineh, card_num2, card_type2, 2);
    char t3 = player_move_char(bakhshnameh, zamineh, card_num3, card_type3);
    int n3 = player_move(bakhshnameh, zamineh, card_num3, card_type3, 2);
    char t4 = player_move_char(bakhshnameh, zamineh, card_num4, card_type4);
    int n4 = player_move(bakhshnameh, zamineh, card_num4, card_type4, 2);

    // check if there is a bakhshnameh between cards
    if (card_type1[index] == bakhshnameh || t2 == bakhshnameh || t3 == bakhshnameh || t4 == bakhshnameh)
    {
        if (card_type1[index] == bakhshnameh)
        {
            if (card_num1[index] > temp)
            {
                temp = card_num1[index];
                turn = 1;
            }
        }
        if (t2 == bakhshnameh)
        {
            if (n2 > temp)
            {
                temp = n2;
                turn = 2;
            }
        }
        if (t3 == bakhshnameh)
        {
            if (n3 > temp)
            {
                temp = n3;
                turn = 3;
            }
        }
        if (t4 == bakhshnameh)
        {
            if (n4 > temp)
            {
                temp = n4;
                turn = 4;
            }
        }
    }
    else
    { // otherwise check if there is zamineh between cards
        if (card_type1[index] == zamineh)
        {
            if (card_num1[index] > temp)
            {
                temp = card_num1[index];
                turn = 1;
            }
        }
        if (t2 == zamineh)
        {
            if (n2 > temp)
            {
                temp = n2;
                turn = 2;
            }
        }
        if (t3 == zamineh)
        {
            if (n3 > temp)
            {
                temp = n3;
                turn = 3;
            }
        }
        if (t4 == zamineh)
        {
            if (n4 > temp)
            {
                temp = n4;
                turn = 4;
            }
        }
    }
    return turn;
}

int comp_start(char card_type[11], int card_num[11], int condition)
{
    // we use this function when a computer player wants to start the game
    int temp = 0;
    for (int i = 1; i < 12; i++)
    {
        if (card_num[temp] < card_num[i])
            temp = i;
    }
    if (condition == 0)
        printf("%c%d", card_type[temp], card_num[temp]);
    if (condition == 1)
        return card_type[temp];
}