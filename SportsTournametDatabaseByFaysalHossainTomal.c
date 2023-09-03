//Sports Tournament Database with various data structures by Faysal Hossain Tomal #221002220

#include<stdio.h>   //standard header
#include<string.h>  //header for using string
#include<stdlib.h>  //header for using linked list
#include<windows.h> //header for using sleep()

#define win 3       //points rewarded for a win
#define lose 0      //points rewarded for a draw
#define draw 1      //points rewarded for a draw

struct Team{                //structure of a linked list for teams
    char TeamName[100];     //string for storing team name
    int id;                 //integer variable for storing team id
    int points;             //integer variable for storing team points
    int nwin;               //integer variable for storing team number of wins
    int nlose;              //integer variable for storing team number of loses
    int ndraw;              //integer variable for storing team number of draws
    struct Team *next;      //pointer for indicating next team
} *head=NULL;               //declaring head as null

struct Player{              //structure of a linked list for players
    char PlayingTeam[100];  //string for storing player's team name
    char PlayerName[100];   //string for storing player's name
    int Goal;               //integer variable for storing goals scored by a player
    int Assist;             //integer variable for storing goals scored by a player
    struct Player *next;    //pointer for indicating next player
} *headPlayer=NULL;         //declaring headPlayer as null

char def_user[]="ADMIN";    //customizable user name
char def_pass[]="123";      //customizable user password

char def_team1[] = "ARG";   //default added team1
char def_team2[] = "BRA";   //default added team2
char def_team3[] = "BAN";   //default added team3

char en_team[100];          //string for user entered team
char en_user[100];          //string for user entered user name
char en_pass[1000];         //string for user entered password
char en_player[100];        //string for user entered player name
char en_playerTeam[100];    //string for user entered player's team

void AddPlayer(char en_player[], char en_playerTeam[]){     //function for adding a new player
    struct Player *newPlayer;
    newPlayer=(struct Player *)malloc(sizeof(struct Player));
    strcpy(newPlayer->PlayerName,en_player);
    strcpy(newPlayer->PlayingTeam,en_playerTeam);
    newPlayer->next=NULL;
    printf("\nNUMBER OF GOALS = ");
    scanf("%d", &newPlayer->Goal);
    printf("\nNUMBER OF ASSISTS = ");
    scanf("%d", &newPlayer->Assist);
    if (headPlayer==NULL)
    {
        headPlayer=newPlayer;
    }
    else
    {
        struct Player *temp = headPlayer;
        while (temp->next != NULL)
        {
            temp= temp->next;
        }
        temp->next=newPlayer;
    }
    printf("\nPLAYER ADDED");
}

void updatePlayer(char en_player[]){    //function for updating information of an existing player
    system("cls");
    int flag=0;
    struct Player *temp = headPlayer;
    if (headPlayer == NULL)
    {
        printf("\nNO PLAYERS\n");
    }
    else
    {
        while (temp->next!=NULL)
        {
            if (strcmp(temp->PlayerName,en_player)==0)
            {
                printf("\nNUMBER OF GOALS = ");
                scanf("%d", &temp->Goal);
                printf("\nNUMBER OF ASSISTS = ");
                scanf("%d", &temp->Assist);
                flag++;
            }
            temp=temp->next;
        }
        if (strcmp(temp->PlayerName,en_player)==0)
        {
            printf("\nNUMBER OF GOALS = ");
            scanf("%d", &temp->Goal);
            printf("\nNUMBER OF ASSISTS = ");
            scanf("%d", &temp->Assist);
            flag++;
        }
        else if (flag==0)
        {
            printf("\nWRONG INPUT OR THE PLAYER DOES NOT EXIST");
        }
    }
}

void ShowSquad(char en_playerTeam[]){       //function for displaying the squad members with information of an entered team
    int flag=0;
    system("cls");
    if (headPlayer == NULL)
    {
        printf("\nNO PLAYERS\n");
    }
    else
    {
        struct Player *temp = headPlayer;
        printf("\n\nTHE SQUAD IS - \n");
        while (temp->next != NULL)
        {
            if(strcmp(en_playerTeam,temp->PlayingTeam)==0)
            {
                printf("%s\t\tTEAM = %s\t\tGOALS = %d\t\tASSISTS = %d\n", temp->PlayerName, temp->PlayingTeam, temp->Goal, temp->Assist);
                flag++;
            }
            temp = temp->next;
        }
        if(strcmp(en_playerTeam,temp->PlayingTeam)==0)
        {
            printf("%s\t\tTEAM = %s\t\tGOALS = %d\t\tASSISTS = %d\n", temp->PlayerName, temp->PlayingTeam, temp->Goal, temp->Assist);
            flag++;
        }
        else if(flag==0)
        {
            printf("\nNO PLAYERS\n");
        }
    }
}

void ShowPlayers(){     //function for displaying all entered players information
    system("cls");
    if (headPlayer == NULL)
    {
        printf("\nNO PLAYERS\n");
    }
    else
    {
        struct Player *temp = headPlayer;
        printf("\n\nENTERED PLAYERS ARE - \n");
        while (temp->next != NULL)
        {
            printf("%s\t\tTEAM = %s\t\tGOALS = %d\t\tASSISTS = %d\n", temp->PlayerName, temp->PlayingTeam, temp->Goal, temp->Assist);
            temp = temp->next;
        }
        printf("%s\t\tTEAM = %s\t\tGOALS = %d\t\tASSISTS = %d\n", temp->PlayerName, temp->PlayingTeam, temp->Goal, temp->Assist);
    }
}

void AddNewTeam(char newName[]){        //function for adding a new team
    struct Team *newTeam;
    newTeam = (struct Team *)malloc(sizeof(struct Team));
    strcpy(newTeam->TeamName, newName);
    newTeam->next=NULL;
    if (head==NULL)
    {
        head=newTeam;
    }
    else
    {
        struct Team *temp = head;
        while (temp->next != NULL)
        {
            temp= temp->next;
        }
        temp->next=newTeam;
    }
    printf("\nTEAM ADDED");
    Sleep(1000);
}

void deleteAtBeginning(){       //function for deleting a team from the first position
    if (head == NULL)
    {
        printf("\nNO TEAM");
    }
    else
    {
        struct Team *temp = head;
        head = head ->next;
        temp->next = NULL;
    }
    system("cls");
    printf("\nTEAM DELETED");
    Sleep(1000);
}

void playerDeleteAtBeginning(){     //function for deleting a player from the first position
    if (headPlayer == NULL)
    {
        printf("\nNO PLAYER");
    }
    else
    {
        struct Player *temp = headPlayer;
        headPlayer = headPlayer ->next;
        temp->next = NULL;
    }
    system("cls");
    printf("\nPLAYER DELETED");
    Sleep(1000);
}

void playerDeleteAtEnd(){       //function for deleting a player from the last position
    if (headPlayer == NULL)
    {
        printf("\nNO PLAYER");
    }
    else
    {
        struct Player *temp = headPlayer;
        struct Player *prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
    }
    system("cls");
    printf("\nPLAYER DELETED");
    Sleep(1000);
}

void deleteAtEnd(){         //function for deleting a team from the last position
    if (head == NULL)
    {
        printf("\nNO TEAM");
    }
    else
    {
        struct Team *temp = head;
        struct Team *prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
    }
    system("cls");
    printf("\nTEAM DELETED");
    Sleep(1000);
}

void playerDeleteInterior(char name[]){
    if (headPlayer == NULL)
    {
        printf("\nNO PLAYER");
    }
    else if (strcmp(headPlayer->PlayerName,name)==0)
    {
        playerDeleteAtBeginning();
    }
    else
    {
        struct Player *temp = headPlayer;
        struct Player *prev = NULL;
        while (strcmp(temp->PlayerName,name)!=0)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        temp->next=NULL;
    }
    system("cls");
    printf("\nPLAYER DELETED");
    Sleep(1000);
}

void deleteInterior(char name[]){
    if (head == NULL)
    {
        printf("\nNO TEAM");
    }
    else if (strcmp(head->TeamName,name)==0)
    {
        deleteAtBeginning();
    }
    else
    {
        struct Team *temp = head;
        struct Team *prev = NULL;
        while (strcmp(temp->TeamName,name)!=0)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        temp->next=NULL;
    }
    system("cls");
    printf("\nTEAM DELETED");
    Sleep(1000);
}

void display(){     //function for displaying all entered teams
    int i = 1;
    system("cls");
    if (head == NULL)
    {
        printf("\nNO TEAMS\n");
    }
    else
    {
        struct Team *temp = head;
        temp->id = 1;
        printf("\n\nENTERED TEAMS ARE - \n");
        while (temp->next != NULL)
        {
            printf("%d. %s\n", temp->id, temp->TeamName);
            temp = temp->next;
            i++;
            temp->id=i;
        }
        printf("%d. %s\n", temp->id, temp->TeamName);
    }
}

void updateTeam(int user_in){       //function for adding / updating informations of a team
    system("cls");
    struct Team *temp = head;
    while (temp->id != user_in)
    {
        temp = temp->next;
    }
    printf("ENTER NUMBER OF WINS = ");
    scanf("%d", &temp->nwin);
    printf("ENTER NUMBER OF LOSSES = ");
    scanf("%d", &temp->nlose);
    printf("ENTER NUMBER OF DRAWS = ");
    scanf("%d", &temp->ndraw);
    printf("\nTEAM NAME = %s", temp->TeamName);
    temp->points=(temp->nwin*win)+(temp->nlose*lose)+(temp->ndraw*draw);
    printf("\nPOINTS = %d", temp->points);
}

void SearchPlayer(char en_player[]){        //function for searching a player
    int flag=0;
    struct Player *temp;
    temp=headPlayer;
    while (temp!=NULL)
    {
        if(strcmp(en_player,temp->PlayerName)==0)
        {
            printf("\nPLAYER NAME = %s", temp->PlayerName);
            printf("\nNUMBER OF GOALS = %d", temp->Goal);
            printf("\nNUMBER OF ASSISTS = %d", temp->Assist);
            flag++;
        }
        temp=temp->next;
    }
    if (flag==0)
    {
        printf("\nENTERED PLAYER DOES NOT EXIST");
    }
}

void SearchTeam(char en_team[]){        //function for searching a team
    int flag=0;
    struct Team *temp;
    temp=head;
    while (temp!=NULL)
    {
        if(strcmp(en_team,temp->TeamName)==0)
        {
            printf("\nTEAM NAME = %s", temp->TeamName);
            printf("\nNUMBER OF WINS = %d", temp->nwin);
            printf("\nNUMBER OF LOSES = %d", temp->nlose);
            printf("\nNUMBER OF DRAWS = %d", temp->ndraw);
            printf("\nTOTAL POINTS = %d", temp->points);
            flag++;
        }
        temp=temp->next;
    }
    if (flag==0)
    {
        printf("\nENTERED TEAM DOES NOT EXIST");
    }
    return;
}

void pointBoard(struct Team *temp){         //function for displaying the point leaderboard
    temp=head;
    printf("\nNAME\t\tWINS\t\tLOSES\t\tDRAWS\t\tPOINTS\n");
    while (temp != NULL)
    {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n",temp->TeamName, temp->nwin, temp->nlose, temp->ndraw, temp->points);
        temp = temp->next;
    }
}

void goalBoard(struct Player *temp){        //function for displaying the goal leaderboard
    temp=headPlayer;
    printf("\nNAME\t\tTEAM\t\tGOALS\n");
    while (temp != NULL)
    {
        printf("%s\t\t%s\t\t%d\n",temp->PlayerName, temp->PlayingTeam, temp->Goal);
        temp = temp->next;
    }
}

void assistBoard(struct Player *temp){      //function for displaying the assist leaderboard
    temp=headPlayer;
    printf("\nNAME\t\tTEAM\t\tASSISTS\n");
    while (temp != NULL)
    {
        printf("%s\t\t%s\t\t%d\n",temp->PlayerName, temp->PlayingTeam, temp->Assist);
        temp = temp->next;
    }
}

void SortingDes(struct Team *head){         //function for sorting the teams in descending order with respect to points
    struct Team *tempNode;
    int tempPoint, tempID, tempWin, tempLose, tempDraw;
    char tempName[100];
    tempNode = NULL;
    if (head==NULL)
    {
        printf("\nNO TEAMS");
    }
    else
    {
        while (head!=NULL)
        {
            tempNode=head->next;
            while (tempNode!=NULL)
            {
                if (head->points < tempNode->points)
                {
                    tempPoint = head->points;
                    tempID = head->id;
                    tempWin = head->nwin;
                    tempLose = head->nlose;
                    tempDraw = head->ndraw;
                    strcpy(tempName,head->TeamName);
                    head->points = tempNode->points;
                    head->id=tempNode->id;
                    head->nwin=tempNode->nwin;
                    head->nlose=tempNode->nlose;
                    head->ndraw=tempNode->ndraw;
                    strcpy(head->TeamName,tempNode->TeamName);
                    tempNode->points=tempPoint;
                    tempNode->id=tempID;
                    tempNode->nwin=tempWin;
                    tempNode->nlose=tempLose;
                    tempNode->ndraw=tempDraw;
                    strcpy(tempNode->TeamName,tempName);
                }
                tempNode=tempNode->next;
            }
            head=head->next;
        }
    }
    pointBoard(head);
}

void SortingGoal(struct Player *headPlayer){        //function for sorting the players in descending order with respect to goals
    struct Player *tempNode;
    int tempGoal, tempAssist;
    char tempName[100];
    char tempNameTeam[100];
    tempNode = NULL;
    if (headPlayer==NULL)
    {
        printf("\nNO PLAYERS");
    }
    else
    {
        while (headPlayer!=NULL)
        {
            tempNode=headPlayer->next;
            while (tempNode!=NULL)
            {
                if (headPlayer->Goal < tempNode->Goal)
                {
                    tempGoal = headPlayer->Goal;
                    tempAssist = headPlayer->Assist;
                    strcpy(tempName,headPlayer->PlayerName);
                    strcpy(tempNameTeam,headPlayer->PlayingTeam);
                    headPlayer->Goal = tempNode->Goal;
                    headPlayer->Assist=tempNode->Assist;
                    strcpy(headPlayer->PlayerName,tempNode->PlayerName);
                    strcpy(headPlayer->PlayingTeam,tempNode->PlayingTeam);
                    tempNode->Goal=tempGoal;
                    tempNode->Assist=tempAssist;
                    strcpy(tempNode->PlayerName,tempName);
                    strcpy(tempNode->PlayingTeam,tempNameTeam);
                }
                tempNode=tempNode->next;
            }
            headPlayer=headPlayer->next;
        }
    }
    goalBoard(headPlayer);
}

void SortingAssist(struct Player *headPlayer){      //function for sorting the players in descending order with respect to assists
    struct Player *tempNode;
    int tempGoal, tempAssist;
    char tempName[100];
    char tempNameTeam[100];
    tempNode = NULL;
    if (headPlayer==NULL)
    {
        printf("\nNO PLAYERS");
    }
    else
    {
        while (headPlayer!=NULL)
        {
            tempNode=headPlayer->next;
            while (tempNode!=NULL)
            {
                if (headPlayer->Assist < tempNode->Assist)
                {
                    tempGoal = headPlayer->Goal;
                    tempAssist = headPlayer->Assist;
                    strcpy(tempName,headPlayer->PlayerName);
                    strcpy(tempNameTeam,headPlayer->PlayingTeam);
                    headPlayer->Goal = tempNode->Goal;
                    headPlayer->Assist=tempNode->Assist;
                    strcpy(headPlayer->PlayerName,tempNode->PlayerName);
                    strcpy(headPlayer->PlayingTeam,tempNode->PlayingTeam);
                    tempNode->Goal=tempGoal;
                    tempNode->Assist=tempAssist;
                    strcpy(tempNode->PlayerName,tempName);
                    strcpy(tempNode->PlayingTeam,tempNameTeam);
                }
                tempNode=tempNode->next;
            }
            headPlayer=headPlayer->next;
        }
    }
    assistBoard(headPlayer);
}

int main(){     //the main function
    int user_in;
    AddNewTeam(def_team1);  //adding team 1 by default
    AddNewTeam(def_team2);  //adding team 2 by default
    AddNewTeam(def_team3);  //adding team 3 by default
    login_part:
    system("cls");
    int login=0;
    char ch;
    printf("---LOG IN TO ACCESS THE DATABASE---");  //simple login section
    printf("\n\nEnter user name     = ");
    gets(en_user);
    printf("\nEnter user password = ");
    while ((ch = _getch(en_pass))!=13)  //13 is the ascii value of return or enter
    {
        en_pass[login]=ch;
        login++;
        printf("*");
    }
    en_pass[login]='\0';

    if (strcmp(def_user,en_user)==0 && strcmp(def_pass,en_pass)==0)
    {
        system("cls");
        printf("\n---WELCOME---");
        Sleep(1000);
        goto main_menu;
    }
    else
    {
        system("cls");
        printf("\nWrong user name or password\nTry again");
        Sleep(1000);
        system("cls");
        goto login_part;
    }
    main_menu:
    system("cls");
    printf("\n---FNT SPORTS DATABASE---\n");
    printf("\nENTER CORRESPONDING NUMBER TO CONTINUE"); //all features are shown
    printf("\n 1. ENTERED TEAM LIST");
    printf("\n 2. REGISTER A NEW TEAM");
    printf("\n 3. DELETE A TEAM FROM DATABASE");
    printf("\n 4. ADD / UPDATE INFORMATIONS OF A TEAM");
    printf("\n 5. ENTERED PLAYER LIST");
    printf("\n 6. SQUAD OF AN ENTERED TEAM");
    printf("\n 7. ADD A PLAYER TO A TEAM");
    printf("\n 8. DELETE A PLAYER FROM A TEAM");
    printf("\n 9. UPDATE PLAYER INFORMATION");
    printf("\n10. SEARCH A TEAM");
    printf("\n11. SEARCH A PLAYER");
    printf("\n12. POINTS LEADERBOARD");
    printf("\n13. GOALS LEADERBOARD");
    printf("\n14. ASSISTS LEADERBOARD");
    printf("\n15. EXIT");
    printf("\n ENTER YOUR INPUT = ");
    scanf("%d", &user_in);
    switch (user_in)        //switch case for doing all operations
    {
    case 1:         //showing all entered team name
        display();
        decision1:
        printf("\nENTER '0' TO RETURN\nENTER '1' TO REGISTER A NEW TEAM\nENTER '2' TO ADD INFORMATION FOR THE TEAMS\nENTER YOUR INPUT = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 0:
            goto main_menu;
        case 1:
            goto menu2;
        case 2:
            goto menu4;
        default:
            printf("\nWRONG INPUT");
            Sleep(1000);
            goto decision1;
        }

    case 2:     //registering a new team
        menu2:
        system("cls");
        printf("\nENTER TEAM NAME = ");
        scanf("%s", en_team);
        AddNewTeam(en_team);
        decision2:
        printf("\nENTER '0' TO RETURN\nENTER '1' TO REGISTER ANOTHER TEAM\nENTER '2' TO ADD INFORMATION FOR THE TEAMS\nENTER YOUR INPUT = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 0:
            goto main_menu;
        case 1:
            goto menu2;
        case 2:
            goto menu4;
        default:
            printf("\nWRONG INPUT");
            Sleep(1000);
            goto decision2;
        }

    case 3:     //removing an added team
        menu3:
        system("cls");
        display();
        decision3:
        printf("\nENTER '0' TO RETURN\nENTER '1' TO DELETE FIRST TEAM\nENTER '2' TO DELETE LAST TEAM\nENTER '3' TO DELETE ANY TEAM\nENTER YOUR INPUT = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 0:
            goto main_menu;
        case 1:
            deleteAtBeginning();
            goto menu3;
        case 2:
            deleteAtEnd();
            goto menu3;
        case 3:
            printf("\nENTER THE NAME OF THE TEAM YOU WANT TO DELETE = ");
            scanf("%s", en_team);
            deleteInterior(en_team);
            goto menu3;
        default:
            printf("\nWRONG INPUT");
            Sleep(1000);
            goto decision3;
        }

    case 4:     //adding / updating information of a team
        menu4:
        system("cls");
        display();
        printf("\nENTER TEAM NUMBER TO ADD / UPDATE INFORMATION = ");
        scanf("%d", &user_in);
        updateTeam(user_in);
        decision4:
        printf("\nENTER '0' TO RETURN\nENTER '1' TO UPDATE AGAIN\nENTER YOUR INPUT = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 0:
            goto main_menu;
        case 1:
            goto menu4;
        default:
            printf("\nWRONG INPUT");
            Sleep(1000);
            goto decision4;
        }

    case 5:     //showing all entered players
        menu5:
        system("cls");
        printf("\nENTERED PLAYERS ARE = ");
        ShowPlayers();
        decision5:
        printf("\nENTER '0' TO RETURN\nENTER '1' TO ADD A NEW PLAYER TO A TEAM\nENTER YOUR INPUT = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 0:
            goto main_menu;
        case 1:
            goto menu7;
        default:
            printf("\nWRONG INPUT");
            Sleep(1000);
            goto decision5;
        }

    case 6:     //showing squad of a registered team
        menu6:
        system("cls");
        display();
        printf("\nENTER A TEAM NAME TO SEE SQUAD = ");
        scanf("%s", en_playerTeam);
        ShowSquad(en_playerTeam);
        decision6:
        printf("\nENTER '0' TO RETURN\nENTER YOUR INPUT = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 0:
            goto main_menu;
        default:
            printf("\nWRONG INPUT");
            Sleep(1000);
            goto decision6;
        }

    case 7:     //adding a new player to registered teams
        menu7:
        system("cls");
        printf("\nPLAYERS CAN BE ADDED TO THESE REGISTERED TEAMS = ");
        display();
        printf("\nENTER THE TEAM NAME WHERE YOU WOULD ADD A PLAYER = ");
        scanf("%s", en_playerTeam);
        printf("\nENTER THE PLAYER'S NAME = ");
        scanf("%s", en_player);
        AddPlayer(en_player, en_playerTeam);
        decision7:
        printf("\nENTER '0' TO RETURN\nENTER '1' TO ADD ANOTHER PLAYER\nENTER YOUR INPUT = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 0:
            goto main_menu;
        case 1:
            goto menu7;
        default:
            printf("\nWRONG INPUT");
            Sleep(1000);
            goto decision7;
        }

    case 8:     //deleting a player from the registered teams
        menu8:
        system("cls");
        ShowPlayers();
        decision8:
        printf("\nENTER '0' TO RETURN\nENTER '1' TO DELETE FIRST PLAYER\nENTER '2' TO DELETE LAST PLAYER\nENTER '3' TO DELETE ANY PLAYER\nENTER YOUR INPUT = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 0:
            goto main_menu;
        case 1:
            playerDeleteAtBeginning();
            goto menu8;
        case 2:
            playerDeleteAtEnd();
            goto menu8;
        case 3:
            printf("\nENTER THE NAME OF THE PLAYER YOU WANT TO DELETE = ");
            scanf("%s", en_player);
            playerDeleteInterior(en_player);
            goto menu8;
        default:
            printf("\nWRONG INPUT");
            Sleep(1000);
            goto decision8;
        }

    case 9:     //updating informations of a player
        menu9:
        system("cls");
        ShowPlayers();
        printf("\nENTER PLAYER NAME TO UPDATE INFORMATION = ");
        scanf("%s", en_player);
        updatePlayer(en_player);
        decision9:
        printf("\nENTER '0' TO RETURN\nENTER '1' TO UPDATE AGAIN\nENTER YOUR INPUT = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 0:
            goto main_menu;
        case 1:
            goto menu9;
        default:
            printf("\nWRONG INPUT");
            Sleep(1000);
            goto decision9;
        }

    case 10:        //searching a team for informations
        menu10:
        system("cls");
        printf("\nENTER TEAM NAME TO SEARCH = ");
        scanf("%s", en_team);
        SearchTeam(en_team);
        decision10:
        printf("\nENTER '0' TO RETURN\nENTER '1' TO SEARCH AGAIN\nENTER YOUR INPUT = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 0:
            goto main_menu;
        case 1:
            goto menu10;
        default:
            printf("\nWRONG INPUT");
            Sleep(1000);
            goto decision10;
        }

    case 11:        //searching a player for informations
        menu11:
        system("cls");
        printf("\nENTER PLAYER NAME TO SEARCH = ");
        scanf("%s", en_player);
        SearchPlayer(en_player);
        decision11:
        printf("\nENTER '0' TO RETURN\nENTER '1' TO SEARCH AGAIN\nENTER YOUR INPUT = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 0:
            goto main_menu;
        case 1:
            goto menu11;
        default:
            printf("\nWRONG INPUT");
            Sleep(1000);
            goto decision11;
        }

    case 12:        //descending order points sorting for the teams
        menu12:
        system("cls");
        SortingDes(head);
        decision12:
        printf("\nENTER '0' TO RETURN\nENTER YOUR INPUT = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 0:
            goto main_menu;
        default:
            printf("\nWRONG INPUT");
            Sleep(1000);
            goto decision12;
        }

    case 13:        //descending order goals sorting for the players
        menu13:
        system("cls");
        SortingGoal(headPlayer);
        decision13:
        printf("\nENTER '0' TO RETURN\nENTER YOUR INPUT = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 0:
            goto main_menu;
        default:
            printf("\nWRONG INPUT");
            Sleep(1000);
            goto decision13;
        }

    case 14:        //descending order assists sorting for the players
        menu14:
        system("cls");
        SortingAssist(headPlayer);
        decision14:
        printf("\nENTER '0' TO RETURN\nENTER YOUR INPUT = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 0:
            goto main_menu;
        default:
            printf("\nWRONG INPUT");
            Sleep(1000);
            goto decision14;
        }

    case 15:        //logging out / exiting the program
        menu15:
        system("cls");
        printf("\nARE YOU SURE WANT TO LOG OUT ?");     //making double check to prevent unwanted log out
        printf("\n 0. NO");
        printf("\n 1. YES");
        printf("\nENTER YOUR INPUT = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 0:
            goto main_menu;
        case 1:
            system("cls");
            printf("\nTHANK YOU\nGOOD BYE");
            Sleep(1000);
            return 0;
        default:
            printf("\nWRONG INPUT");
            Sleep(1000);
            goto menu15;
        }

    default:
        system("cls");
        printf("\nWRONG INPUT");
        Sleep(1000);
        goto main_menu;
    }
}

//Sports Tournament Database with various data structures by Faysal Hossain Tomal #221002220
