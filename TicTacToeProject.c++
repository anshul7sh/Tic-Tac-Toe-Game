//Added last winning or draw board.

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

char set[9]={'1','2','3','4','5','6','7','8','9'};

int menu();
void play();
void board(int );
void choice(int );
int win(int );
void lastBoard(){
	cout<<"     |"<<"     |"<<"     |"<<endl;
    cout<<"  "<<set[0]<<"  |"<<"  "<<set[1]<<"  |"<<"  "<<set[2]<<"  |"<<endl;
    cout<<"_____|"<<"_____|"<<"_____|"<<endl;
    cout<<"     |"<<"     |"<<"     |"<<endl;
    cout<<"  "<<set[3]<<"  |"<<"  "<<set[4]<<"  |"<<"  "<<set[5]<<"  |"<<endl;
    cout<<"_____|"<<"_____|"<<"_____|"<<endl;
    cout<<"     |"<<"     |"<<"     |"<<endl;
    cout<<"  "<<set[6]<<"  |"<<"  "<<set[7]<<"  |"<<"  "<<set[8]<<"  |"<<endl;
    cout<<"_____|"<<"_____|"<<"_____|"<<endl<<endl;
};

int main()
{
    while(1)
    {
        switch(menu())
        {
            case 1:
                    play();
                    break;
            case 2:
                    exit(0);

            default:
                    printf("\nInvalid choice.\nPress again a valid choice number.\n");
                    break;
        }
    }

    return 0;
}

int menu()
{
    cout<<"\nEnter choice number.\n";
    cout<<"1.Play game.\n";
    cout<<"2.Exit.\n";
    int choice;
    cin>>choice;

    return choice;
}

void play()
{
    int n=0;
    while(!win(n)&&n<=8)
    {
        board(n);
        n++;
    }

    //cout << "\033[2J\033[1;1H";     //gibberish deleted.
    if(n<=8)
        if(n%2!=0)
            cout<<"     Congratulations Player 1 Wins."<<endl;
        else
            cout<<"     Congratulations Player 2 Wins."<<endl;

    if(n>8)
        cout<<"         Match Draw."<<endl;
        
        lastBoard();

    set[0]='1';
    set[1]='2';
    set[2]='3';
    set[3]='4';
    set[4]='5';
    set[5]='6';
    set[6]='7';
    set[7]='8';
    set[8]='9';

    return;
}

void board(int n)
{
    
    //cout << "\033[2J\033[1;1H";    //gibberish deleted

    cout<<"         "<<"Tic Tac Toe Game..."<<endl<<endl;
    cout<<"     "<<"Player 1->'X'"<<"        "<<"Player 2->'O'"<<endl<<endl;

    cout<<"     |"<<"     |"<<"     |"<<endl;
    cout<<"  "<<set[0]<<"  |"<<"  "<<set[1]<<"  |"<<"  "<<set[2]<<"  |"<<endl;
    cout<<"_____|"<<"_____|"<<"_____|"<<endl;
    cout<<"     |"<<"     |"<<"     |"<<endl;
    cout<<"  "<<set[3]<<"  |"<<"  "<<set[4]<<"  |"<<"  "<<set[5]<<"  |"<<endl;
    cout<<"_____|"<<"_____|"<<"_____|"<<endl;
    cout<<"     |"<<"     |"<<"     |"<<endl;
    cout<<"  "<<set[6]<<"  |"<<"  "<<set[7]<<"  |"<<"  "<<set[8]<<"  |"<<endl;
    cout<<"_____|"<<"_____|"<<"_____|"<<endl<<endl;

    if(n%2==0)
        cout<<"\nPlayer 1.Enter Poisition Number:";
    else
        cout<<"\nPlayer 2.Enter Poisition Number:";
        
    choice(n);
}

void choice(int turn)
{
    int n;
    cin>>n;

    if(turn%2==0)
        set[n-1]='X';
    else
        set[n-1]='O';
}

int win(int n)
{
    if(n<5)
        return 0;
    else
    {
        if(set[0]==set[1]&&set[1]==set[2])
            return 1;
        else if(set[3]==set[4]&&set[4]==set[5])
             return 1;
            else if(set[6]==set[7]&&set[7]==set[8])
                 return 1;
                 else  if(set[0]==set[3]&&set[3]==set[6])
                       return 1;
                       else if(set[1]==set[4]&&set[4]==set[7])
                             return 1;
                            else if(set[2]==set[5]&&set[5]==set[8])
                                  return 1;
                                  else if(set[0]==set[4]&&set[4]==set[8])
                                        return 1;
                                        else if(set[2]==set[4]&&set[4]==set[6])
                                              return 1;
    }

    return 0;
}
