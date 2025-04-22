#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    int twoD[25][2] = {
        {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}};
    int me[] = {1, 1};
    int x[2];
    srand(time(NULL));
    x[1] = rand() % 5 + 1, x[0] = rand() % 5 + 1;
    int i = 0;

    while (i < 10 && (me[0] != x[0] || me[1] != x[1]))
    {
        
        cout << "Enter your move" << endl;
        int move = getch(); // Get the first character

        if (move == 224) // Check if it's an arrow key
        {
            move = getch(); // Get the second character to identify the arrow key
            switch (move)
            {
            case 72: // Up arrow
                if (me[0] == 1)
                {
                    cout << "This move is not possible" << endl;
                    i--;
                }
                else
                {
                    me[0]--;
                }
                break;
            case 80: // Down arrow
                if (me[0] == 5)
                {
                    cout << "This move is not possible" << endl;
                    i--;
                }
                else
                {
                    me[0]++;
                }
                break;
            case 75: // Left arrow
                if (me[1] == 1)
                {
                    cout << "This move is not possible" << endl;
                    i--;
                }
                else
                {
                    me[1]--;
                }
                break;
            case 77: // Right arrow
                if (me[1] == 5)
                {
                    cout << "This move is not possible" << endl;
                    i--;
                }
                else
                {
                    me[1]++;
                }
                break;
            default:
                cout << "Incorrect move" << endl;
                i--;
            }
            cout << "You have " << 10 - (i + 1) << " chances left" << endl;
        }
        else
        {
            cout << "Invalid input. Use arrow keys!" << endl;
            i--;
        }
        
        // cout << "You are at " << me[0] << "," << me[1] << endl;
        i++;
        for (int k = 1; k < 6; k++)
        {
            for (int l = 1; l < 6; l++)
            {
                if (me[0]==k && me[1]==l)
                {
                    cout<<"X  ";
                    l++;
                }
                
                cout << "__ ";
            }
            cout << "" << endl;
        }
    }

    if ((me[0] == x[0] && me[1] == x[1]))
    {
        cout << "You win" << endl;
    }
    else
    {
        cout << "You lose " << endl;
        cout << "X was here" << endl;
        for (int k = 1; k < 6; k++)
        {
            for (int l = 1; l < 6; l++)
            {
                if (x[0]==k && x[1]==l)
                {
                    cout<<"X  ";
                    l++;
                }
                
                cout << "__ ";
            }
            cout << "" << endl;
        }
        // cout << x[0] << " " << x[1] << endl;
    }

    return 0;
}