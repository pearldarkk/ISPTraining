#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include "rlutil.h"

using namespace std;

char field[8][8];
char choice, difficulty;
int xPlayerPosition, yPlayerPosition, xTemp, yTemp, xKey, yKey, monsters, smartMonsters = 0,userScore;
int xMonster[40], yMonster[40], xSmartMonster[5], ySmartMonster[5];
bool key = 0, keyExist = 1;
string username;

typedef struct playerInfo {
    int Score;
    string Name;
} playerInfo;

vector<playerInfo> player;

void Intro();
int SelectMode();
void StartLevel();
void Instruction();
bool ChoiceChecker(char);
void Choice();
bool MoveChecker(int, int);
void DrawField();
bool WinConditionChecker(int, int);
bool LoseConditionChecker(int, int);
void MovingMonsters();
void MovingSmartMonsters();
void KeyTeleport();
void CreateRollofHonour();
void ReadRollofHonour();
void UpdateRollofHonour();
void DisplayRollofHonour(int);
void RollofHonour();

int main()
{
    cout << "----DUNGEON ESCAPE----\n" << endl;
    Sleep(500);
    Intro();

    cout << "\n----------------------\nEnter your name so that I could laugh at you when you lose: "; cin >> username;
    system("CLS");
    cout << "START GAME!" << endl;
    Sleep(500);

    for (int i=0;i<8;++i)
    for (int j=0;j<8;++j)
    field[i][j] = '-';

    srand((unsigned) time(NULL));
    StartLevel();

    int teleportKey = rand() % 4 + 3;
    int moves = 0;
    while (true)
    {
        system("CLS");
        cout << "Press W,A,S,D to move, X to stand still, I to see instruction and Q to quit game.\n" << endl;
        DrawField();
        Choice();
        if (choice=='I') continue;
        else
        if (MoveChecker(xTemp,yTemp))
        {
            field[xPlayerPosition][yPlayerPosition] = '-';
            xPlayerPosition = xTemp;
            yPlayerPosition = yTemp;
            ++moves;
            if (WinConditionChecker(xPlayerPosition,yPlayerPosition))
            {
                userScore = moves;
                cout << "\nYou win!" << endl;
                break;
            }
            if (LoseConditionChecker(xPlayerPosition,yPlayerPosition))
            {
                userScore = moves*(-1);
                cout << "\nI knew it. You lose!" << endl;
                break;
            }
            field[xPlayerPosition][yPlayerPosition] = 'P';
            MovingMonsters();
            if (smartMonsters) MovingSmartMonsters();
            if (moves==teleportKey && !key && difficulty!='E')
            {
                KeyTeleport();
                teleportKey = rand() % 4 + moves + 3;
            }
        }
    }
    Sleep(500);
    //RollofHonour();
    return 0;
}

void Intro()
{
    cout << "You are trying to escape this strange room." << endl;
    Sleep(2000);
    cout << "Luckily you have its map." << endl;
    Sleep(2000);
    cout << "You know that there is a key in the room and if you can take it, you can open the exitgate and get out." << endl;
    Sleep(2000);
}

void Instruction()
{
    cout << "\nINSTRUCTION:\n";
    cout << "-----------------------" << endl;
    cout << "Win condition: Find the key and enter the exit." << endl;
    cout << "Lose condition: Enter one monster." << endl;
    cout << "Your map has some symbols. P is your location, K is the key's location, E is the key's location and m,M is the monster's location."<< endl;
    cout << "Press W to move up, A to move left, S to move down and D to move right. You are not allowed to go outside the room. Press X if you don't want to move." << endl;
    cout << "The monsters can move! If they're around you, just stand there and don't breathe!" << endl;
    cout << "Notice that you must find the key BEFORE you enter the exit. Now let's start your game!" << endl;
}

int SelectMode()
{
    while (true)
    {
        cout << "Select difficulty: [E]asy, [M]edium and [I]nsane? "; cin >> difficulty;
        if (difficulty=='E' || difficulty=='M' || difficulty=='I') break;
        else
            cout << "Invalid. Try again.\n";
    }
    switch (difficulty)
    {
        case 'E': return 0;
        case 'M': return (rand() % 10 + 10);//Medium level has 10 - 20 monsters
        case 'I':
            {
                smartMonsters = 5;
                return (rand() % 10 + 15);//Insane level has 15 - 25 monsters
            }
    }
}

void StartLevel()
{
    int x,y;

    //Set location of player
    x = rand() % 8;
    y = rand() % 8;
    field[x][y] = 'P';
    xPlayerPosition = x;
    yPlayerPosition = y;

    //Set location of key
    do {
        x = rand() % 8;
        y = rand() % 8;
    } while (field[x][y]!='-');
    field[x][y] = 'K';
    xKey = x;
    yKey = y;

    //Set location of exitgate
    do {
        x = rand() % 8;
        y = rand() % 8;
    } while (field[x][y]!='-');
    field[x][y] = 'E';

    //Set location of monsters
    monsters = SelectMode();
    for (int i=0;i<monsters;++i)
    {
        do {
            x = rand() % 8;
            y = rand() % 8;
        } while (field[x][y]!='-');
        field[x][y] = 'm';
        xMonster[i] = x;
        yMonster[i] = y;
    }

    //Set location of smart monsters
    for (int i=0;i<smartMonsters;++i)
    {
        do {
            x = rand() % 8;
            y = rand() % 8;
        } while (field[x][y]!='-');
        field[x][y] = 'M';
        xSmartMonster[i] = x;
        ySmartMonster[i] = y;
    }
}

void DrawField()
{
    for (int i=0;i<8;++i)
    {
        for (int j=0;j<8;++j)
        {
            switch (field[i][j])
            {
                case 'P':
                    rlutil::setColor(9);
                    break;

                case 'K':
                    rlutil::setColor(14);
                    break;

                case 'E':
                    rlutil::setColor(10);
                    break;

                case 'M':
                    rlutil::setColor(12);
                    break;

                default:
                    rlutil::setColor(15);
            }
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
    rlutil::setColor(15);
}

bool ChoiceChecker(char choice)
{
    if (choice=='W' || choice=='A' || choice=='S' || choice=='D' || choice=='I' || choice=='Q' || choice=='X')
    return 1;
    else return 0;
}

void Choice()
{
    while (true)
    {
        cout << endl;
        choice = getch();
        if (ChoiceChecker(choice))
        break;
    }

    xTemp = xPlayerPosition;
    yTemp = yPlayerPosition;
    switch (choice)
    {
        case 'W': //Move up
            --xTemp;
            break;
        case 'A': //Move left
            --yTemp;
            break;
        case 'S': //Move down
            ++xTemp;
            break;
        case 'D': //Move right
            ++yTemp;
            break;
        case 'I': //See instruction
            Instruction();
            getch();
            break;
        case 'Q': //Forcequit
            cout << "You really want to give up? Keep trying :( " << endl;
            cout << "[Y]es or [N]o?" << endl;
            cin >> choice;
            if (choice=='Y')
            {
                cout << "Even 3-year-old kids can easily solve this. Baizz you dumbass loser :D" << endl;
                exit(0);
            }
            break;
        default: break;
    }
}

bool MoveChecker(int x, int y)
{
    if (x>=0 && x<8 && y>=0 && y<8)
    {
        if (field[x][y]=='E')
        {
            if (key) return 1;
            else
            {
                cout << "Can't enter. You have to find the key first.\n";
                Sleep(500);
                return 0;
            }
        }
        if (field[x][y]!='E') return 1;
    }
    cout << "\a\aYou're hitting the wall!" << endl;
    Sleep(500);
    return 0;
}

bool WinConditionChecker(int x, int y)
{
    if (field[x][y]=='K')
    {
        cout << "\aKey collected." << endl;
        Sleep(500);
        key = 1;
    }
    if (field[x][y]=='E' && key) return 1;
    return 0;
}

bool LoseConditionChecker(int x, int y)
{
    if (field[x][y]=='M' || field[x][y]=='m')
    {
        cout << "\n\aYou entered a monster!" << endl;
        return 1;
    }
    if (!(keyExist))
    {
        cout << "\nA big monster has got the key. You are too slow! Guess he must be smarter than you: he did the thing you couldn't do." << endl;
        return 1;
    }
    return 0;
}

void MovingMonsters()
{
    int randomMonster,randomMovement;
    int movingNumber = (rand() % 15)< monsters ? (rand() % 15) : monsters;

    //Random monsters  moving random directions
    for (int i=0;i<movingNumber;++i)
    {

        randomMonster = rand() % monsters;
        randomMovement = rand() % 4 + 1;
        switch (randomMovement)
        {
            case 1: //Move up
                if (xMonster[randomMonster]>0 && field[xMonster[randomMonster]-1][yMonster[randomMonster]]=='-')
                {
                    field[xMonster[randomMonster]][yMonster[randomMonster]] = '-';
                    --xMonster[randomMonster];
                    field[xMonster[randomMonster]][yMonster[randomMonster]] = 'm';
                }
                break;
            case 2: //Move left
                if (yMonster[randomMonster]>0 && field[xMonster[randomMonster]][yMonster[randomMonster]-1]=='-')
                {        cout << "Creating your Roll of Honour.. Try restart." << endl;

                    field[xMonster[randomMonster]][yMonster[randomMonster]] = '-';
                    --yMonster[randomMonster];
                    field[xMonster[randomMonster]][yMonster[randomMonster]] = 'm';
                }
                break;
            case 3: //Move down
                if (yMonster[randomMonster]<7 && field[xMonster[randomMonster]+1][yMonster[randomMonster]]=='-')
                {
                    field[xMonster[randomMonster]][yMonster[randomMonster]] = '-';
                    ++xMonster[randomMonster];
                    field[xMonster[randomMonster]][yMonster[randomMonster]] = 'm';
                }
                break;
            case 4: //Move right
                if (xMonster[randomMonster]<7 && field[xMonster[randomMonster]][yMonster[randomMonster]+1]=='-')
                {
                    field[xMonster[randomMonster]][yMonster[randomMonster]] = '-';
                    ++yMonster[randomMonster];
                    field[xMonster[randomMonster]][yMonster[randomMonster]] = 'm';
                }
                break;
            default: break;
        }
    }
}

void MovingSmartMonsters()
{
    //Smart monster moving forward the key to catch the key
    int movement;
    for (int i=0;i<smartMonsters;++i)
    {
        int minDistance = min(abs(xKey-xSmartMonster[i]),abs(yKey-ySmartMonster[i]));
        if (minDistance==xKey-xSmartMonster[i]) movement = 4;
        else
            if (minDistance==xSmartMonster[i]-xKey) movement = 2;
            else
                if (minDistance==yKey-ySmartMonster[i]) movement = 1;
                else movement = 3;
        switch (movement)
        {
            case 1: //Move up
                if (xSmartMonster[i]>0)
                {
                    if (field[xSmartMonster[i]-1][ySmartMonster[i]]=='-')
                    {
                        field[xSmartMonster[i]][ySmartMonster[i]] = '-';
                        --xSmartMonster[i];
                        field[xSmartMonster[i]][ySmartMonster[i]] = 'M';
                    }
                    if (field[xSmartMonster[i]-1][ySmartMonster[i]]=='K')
                    {
                        keyExist = 0;
                        field[xSmartMonster[i]][ySmartMonster[i]] = '-';
                        --xSmartMonster[i];
                        field[xSmartMonster[i]][ySmartMonster[i]] = 'M';
                    }
                }
                break;
            case 2: //Move left
                if (ySmartMonster[i]>0)
                {
                    if (field[xSmartMonster[i]][ySmartMonster[i]-1]=='-')
                    {
                        field[xSmartMonster[i]][ySmartMonster[i]] = '-';
                        --ySmartMonster[i];
                        field[xSmartMonster[i]][ySmartMonster[i]] = 'M';
                    }
                    if (field[xSmartMonster[i]][ySmartMonster[i]-1]=='K')
                    {
                        keyExist = 0;
                        field[xSmartMonster[i]][ySmartMonster[i]] = '-';
                        --ySmartMonster[i];
                        field[xSmartMonster[i]][ySmartMonster[i]] = 'M';
                    }
                }
                break;
            case 3: //Move down
                if (xSmartMonster[i]<7)
                {
                    if (field[xSmartMonster[i]+1][ySmartMonster[i]]=='-')
                    {
                        field[xSmartMonster[i]][ySmartMonster[i]] = '-';
                        ++xSmartMonster[i];
                        field[xSmartMonster[i]][ySmartMonster[i]] = 'M';
                    }
                    if (field[xSmartMonster[i]+1][ySmartMonster[i]]=='K')
                    {
                        keyExist = 0;
                        field[xSmartMonster[i]][ySmartMonster[i]] = '-';
                        ++xSmartMonster[i];
                        field[xSmartMonster[i]][ySmartMonster[i]] = 'M';
                    }
                }
                break;
            case 4: //Move right
                if (ySmartMonster[i]<7)
                {
                    if (field[xSmartMonster[i]][ySmartMonster[i]+1]=='-')
                    {
                        field[xSmartMonster[i]][ySmartMonster[i]] = '-';
                        ++ySmartMonster[i];
                        field[xSmartMonster[i]][ySmartMonster[i]] = 'M';
                    }
                    if (field[xSmartMonster[i]][ySmartMonster[i]+1]=='K')
                    {
                        keyExist = 0;
                        field[xSmartMonster[i]][ySmartMonster[i]] = '-';
                        ++ySmartMonster[i];
                        field[xSmartMonster[i]][ySmartMonster[i]] = 'M';
                    }
                }
                break;
        }
    }
}

void KeyTeleport()
{
    int x, y;
    do {
        x = rand() % 8;
        y = rand() % 8;
    } while (field[x][y]!='-');
    field[xKey][yKey] = '-';
    xKey = x;
    yKey = y;
    field[xKey][yKey] = 'K';
}

fstream file("RollofHonour.txt");

void CreateRollofHonour()
{
    for (int i=0;i<20;++i)
    file << "100 -" << endl;
    file.close();
}

file.open("RollofHonour.txt", fstream::in | fstream::out | fstream::trunc);

void ReadRollofHonour()
{
    int score;
    string name;
    playerInfo user;
    file.open("RollofHonour.txt", fstream::in);
    for (int i = 0;i<20;++i)
    {
        file >> score >> name;
        user.Score = score;
        user.Name = name;
        player.push_back(user);
    }
    file.close();
}

void UpdateRollofHonour()
{
    file.open("RollofHonour.txt",fstream::out);
    for (int i=0;i<20;++i)
    file << player[i].Score << " " << player[i].Name << endl;
    file.close();
}

void DisplayRollofHonour(int x)
{
    char choice;
    cout << "Do you want to see the Roll of Honour of the game?" << endl;
    cout << "[Y]es or [N]o? "; cin >> choice;
    if (choice=='N') cout << "Nah, but you still have to see this because I want." << endl;
    else if (choice!='Y') cout << "Seems like you don't understand what I said, but okay here it is: " << endl;

    cout << "\n\n-----ROLL OF HONOUR-----\n\n" << endl;
    for (int i=0;i<20;++i)
    cout << setw(3) << player[i].Score << setw(7) << player[i].Name << endl;

    cout << "Right above is the memberlist of a club named L053rC1ub..." << endl;
    if (x<20 && x!=0) cout << "Congrat you on just become the new member of the Club!!" << endl;
    else if (x==0) cout << "Congrat you on being the new Chairman!!" << endl;
    else
    cout << "So sad you're not allowed to be the new member. But don't worry, keep tryhard and the Club will accept you one day! Besides, let's congrat to the Chairman of Losers: " << player[0].Name << " for being the most failure in the world!!" << endl;
}

void RollofHonour()
{
    //Create new file if not found
    if (!file)
    {
        CreateRollofHonour();
        fstream file("RollofHonour.txt");
    }

    ReadRollofHonour();

    //Add current player
    playerInfo user;
    user.Score = userScore;
    user.Name = username;
    player.push_back(user);

    //Update player
    int place;
    for (int i=0;i<20;++i)
    if (player[i].Score>user.Score)
    {
        place = i;
        break;
    }
    playerInfo temp;
    for (int i=19;i>=place;--i)
    {
        temp = player[i];
        player[i] = player[i+1];
        player[i+1] = temp;
    }
    player[place] = user;

    UpdateRollofHonour();

    DisplayRollofHonour(place);
}