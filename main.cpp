#include "player.h" //includes board.h and boatclass.h

int turn = 0;//keeps track of what turn it is
bool gameWon = 0;//1 is game over, 0 is game in progress
player_c p1,p2;//creating two player objects

//prints empty space
void turnPrint(){
    for(int i = 0; i < 101; i++){
        cout << endl;
    }
}

//allows users to switch without seeing each others board
void pass(int i){
    char temp;
    cin >> temp;
    if(temp == 'y'){
        turnPrint();
        cout << "Player " << i << ", press 'y' if youre ready" << endl;
        cin >> temp;
        if(temp == 'y'){
            return;
        }else{
            pass(i);
        }
    }else{
        pass(i);
    }
}

//This is the function that holds the structure of the game, it has the loop as
//well as checking for win conditions and
//allowing players to shoot at each others ships
void mainGame(){
    p1.askForBoats();
    turnPrint();
    cout << "Player two will now place their boats" << endl;
    p2.askForBoats();
    cout << "The game is ready to begin! Press 'y' when you're ready to pass it to player 1: ";
    pass(1);

    //p1.testBoats(); //used to fill the board with boats to test the shooting
    //p2.testBoats(); // and sinking functions

    //telling each player object who they are playing against.
    p1.setEnemy(&p2);
    p2.setEnemy(&p1);

    //printing some more blank space so that the previous player doesnt see player 1's board
    turnPrint();

    do{
            //used odd and even to see who's turn it is, turn 0 is player 1
            if((turn%2) == 0){
                cout << "Player 1, your turn" << endl;
                //if the shot doesnt hit then we have to switch who's turn it is
                if(!p1.fire()){
                        cout << "You Missed!" << endl;
                        cout << "Press 'y' when you're ready to pass it to Player 2" << endl;
                        //prints the empty space to prevent players from peeking
                        pass(2);
                        //passing to player 2
                        turn++;
                }
            }else{
                //player two's turn
                cout << "Player 2, your turn" << endl;
                if(!p2.fire()){
                    cout << "You Missed!" << endl;
                    cout << "Press 'y' when you're ready to pass it to Player 1" << endl;
                    //prints the empty space to prevent players from peeking
                    pass(1);
                    //passing to player 1
                    turn++;
                }
                //player two stuff
            }
            //check to see if we have a winner yet
            if(p1.lost()){
                cout << "Player 2 Wins!" << endl;
                gameWon = 1;
            }else if(p2.lost()){
                cout << "Player 1 Wins!" << endl;
                gameWon = 1;
            }

    }while(!gameWon);//keep looping until the game is won

}


int main(){
    cout << "By: Julian Peters & Julie McKenna" << endl;
    cout << "Welcome to Battleship" << endl << endl;
    cout << "The following program will be a game of battle ship. It is a two player game where your goal is to sink all of the opponents ships." << endl;
    cout << "You will not know the location of your opponents ships and they will not know yours but you must sink them by entering coordinates" << endl;
    cout << "Player one will start by placing their boats" << endl;
    mainGame();
    return 0;

}
