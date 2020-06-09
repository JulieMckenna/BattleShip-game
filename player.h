#include "board.h"
#include <sstream>
#include <limits>

class player_c{
private:
    //each boat hit they get a point
    int score;
    string name;
    int hitsAgainst;
    vector<string> gueses;
    board myShips;
    board myMoves;
    player_c *enemy;
public:
    player_c(){
        //cout << "Made an empty player please fill it.\n";
    }

    player_c(int sc, string na, int ha){
        score = sc;
        name = na;
        hitsAgainst = ha;
    }

    int getScore(){return score;}
    string getName(){return name;}
    int getHitsAgainst(){return hitsAgainst;}
    void setScore(int newscore){score = newscore;}
    void setName(string newName){name = newName;}
    void setHitsAginst(int ha){hitsAgainst = ha;}

    //used to tell other functions which board to check when shooting
    void setEnemy(player_c *opponent){
        enemy = opponent;
    }

    //to get the user input for the row shot and ensuring they type an integer
    int getUserRow(){
        bool valid = 0;
        int row = -1;
        do{
            cout << "What row?" << endl;
            cin >> row;
            if(cin.good()){
                if(row <= 10 && row >= 1){
                    valid = 1;
                }else{
                    cout << "That is outside of the range of this board, try again" << endl;
                }

            }else{
                //something went wrong, we reset the buffer's state to good
                cin.clear();
                //and empty it
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Invalid Integer, Please re-enter." << endl;
            }
        }while(!valid);
        return row-1;
    }

    //to get the user input for the column shot and ensuring they type a valid letter
    int getUserColumn(){
        bool valid = 0;
        int col = -1;
        char column;
        do{
            cout << "What column?(lowercase letters only)" << endl;
            cin >> column;
            col = myShips.charToNum(column);
            if(cin.good()){
                if(col <= 9 && col >= 0){
                    valid = 1;
                }else{
                    cout << "That is outside of the range of this board (use lowercase)" << endl;
                }

            }else{
                //something went wrong, we reset the buffer's state to good
                cin.clear();
                //and empty it
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Invalid character, Please re-enter (lowercase)." << endl;
            }
        }while(!valid);
        return col;
    }

    //asks the user for a row and column and fires.
    bool fire(){
        cout << endl;
        cout << "Legend:" << endl;
        cout << "1 is where your boats are" << endl;
        cout << "2 is where your boats where hit" << endl;
        cout << "and 3 is where your oponent missed your boats" << endl << endl;
        cout << "Here is the board where you can see your hits and misses" << endl;
        myMoves.printBoard();
        cout << "Here is where your boats are and their condition" << endl;
        myShips.printBoard();
        int row;
        char col;
        int r,c;
        bool repeat = 0;
        bool hit = 0;

        do{
            if(repeat){
                cout << "You already shot there" << endl;
            }
            r = getUserRow();
            c = getUserColumn();
            cout << endl;
            repeat = 1;
        }while(myMoves.getValue(r, c) != EMPTY);


        //check to see if we hit a boat
        if(enemy->myShips.getValue(r, c)){
            //if true, we hit the boat. we put a pin in it and player2's board should update
            myMoves.changeValue(r, c, HIT);
            enemy->myShips.editBoat(r,c);
            hit = 1;
        }else{
            //if false then we need to keep track of this miss
            myMoves.changeValue(r, c, MISS);
            enemy->myShips.changeValue(r,c, MISS);
            hit = 0;
        }

        //returning if we hit the ship or not so we know if we have to switch turns
        return hit;
    }


    //asks a player where they would like to place their boat
    void askForBoats(){
        int size, r, c;//holds info about where the boat should go and how big it is
        string direction;//holds the direction the ship will be oriented
        for(int i = 0; i < 5; ){//loops through boat of size 1-6
            myShips.printBoard();//prints board so the player can see where they want to place
            size = i+1;//we want a boat of size 1-5
            cout << "Now placing boat " << size << endl;
            r = getUserRow();//this function ensures the entered values is an int and returns it
            c = getUserColumn();//this function ensures the user enters a character and converts it to the proper int
            cout << "what direcion will the boat face? (vertical - ship runs down from point, horizontal - ship runs right from point)" <<endl;
            cin >> direction;
            cout << "the direction is " << direction << " at " << r << "," << c << endl;

            //tests to see if the placement of the boat is valid
            if(!myShips.isSpace(size, direction, r, c)){
                //cant place a boat there, dont increment to the next boat
                cout << "not valid" << endl;
            }else{
                //that is a good spot, add the boat and make sure to increment to the next boat
                myShips.addBoat(size, direction, r, c);
                i++;
            }
        }
    }
    //fills the bottom 5 rows with boats of size one for testing
    void testBoats(){
        for(int i = 5; i < 6; i++){
            for(int j =2; j < 7; j++){
                myShips.addBoat(1,"vertical",i,j);
            }
        }
        myShips.printBoard();
    }

    //checks to see if a player has lost 6 boats yet
    bool lost(){
        if(myShips.numBoatsLost() > 4){
            return 1;
        }else{
            return 0;
        }
    }
};
