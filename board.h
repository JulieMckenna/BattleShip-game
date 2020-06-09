#include "boatclass.h"
#include <vector>
#define EMPTY 0
#define BOAT_PRESENT 1
#define HIT 2
#define MISS 3

class board{
private:
    int field[10][10] = {{EMPTY}};//holds the value at each spot on the board
    vector<boat_c*> boat_v;//holds the pointer to each boat on the board


public:
    board(){
        //cout << "board made" << endl;
    };
    //gets the value of a spot on the board
    int getValue(int r, int c){
        return field[r][c];
    }
    //edit the value of a spot on the board
    void changeValue(int r, int c, int value){
        field[r][c] = value;
    }

    //test to see if a boat was hit and change the field accordingly
    void editBoat(int r, int c){
        vector<boat_c*>::iterator it;//used to loop a vector
        for(it = boat_v.begin(); it != boat_v.end(); it++){
            if((*it)->hit(r,c)){
                //if the boat was hit
                field[r][c] = HIT;
                return;
            }
        }
    }

    //loop through the boats and count how many a board has lost
    int numBoatsLost(){
        vector<boat_c*>::iterator it;//used to loop through the vector
        int lost = 0;//keeps track of how many we lost
        for(it = boat_v.begin(); it != boat_v.end(); it++){
            if((*it)->isSunk()){
                //if we lost a boat then increment
                lost++;
                
            }
        }

        return lost;
    }

    //this function adds the boat to the board
    void addToField(){
        int col = boat_v.back()->getColumn(); //getting the most recent boats starting column
        int row = boat_v.back()->getRow(); //getting the most recent boats starting row
        string direction = boat_v.back()->getDirection(); //getting the most recent boats direction
        int length = boat_v.back()->getLength();//getting the most recent boats length
        field[row][col] = BOAT_PRESENT;//setting the initial spot of the boat to having a boat
        if(direction == "vertical")
        {
            //if the boat needs to be placed vertically we will loop through until we hit the length of the boat
            for(int i = 0; i < length ; i++){
                //then we fill those positions with a boat. Boats will run down from their starting position
                field[row+i][col] = BOAT_PRESENT;
            }

        }
        else
        {
            //if the boat needs to be placed horizontally
            for(int i = 0; i < length ; i++){
                //then we fill those positions with a boat. Boats will run right from their starting position
                field[row][col+i] = BOAT_PRESENT;
            }
        }
    }
    //function to check if there is space for the boat to fit where the user specified
    bool isSpace(int size, string direction, int r, int c){
        if(!field[r][c]){
            if(direction == "vertical")
            {
                //steps for vertical direction check
                if((r + size) <= 10){
                    //if it will fit on the board
                    for(int i = 0; i < size-1; i++){
                        //check each space the ship needs to go in
                        if(field[r+i][c]){
                            //if there was a ship in that spot
                            return false;
                        }
                    }
                }else{
                    //if it wont fit on the board
                    return false;
                    }
            }
            else
            {
                //steps for horizontal direction check
                 if((c + size) <= 10){
                     //if the ship will fit on the board
                     for(int i = 0; i < size-1 ; i++){
                         //check each space that the ship needs to go in
                         if(field[r][c+i]){
                             //if there is already a ship in that spot
                             return false;
                         }
                    }
                }else{
                    //if the ship wont fit on the board
                    return false;
                    }
            }
        }else{
            //if there is already a ship in that spot
            return false;
        }
        //if the program makes it this far, we know the value the user entered was fine.
        return true;

    }

    //converts lowercase a-f into numbers 0-10
    int charToNum(char c){
        return ((int)c - 97);
    }

    //adding boat depending on the size
    void addBoat(int size, string direction, int r, int c){
        switch(size){
        case 1:{
            boat1_c *b = new boat1_c(r, c);
            boat_v.push_back(b);
            addToField();
            break;}
        case 2:{
            boat2_c *b = new boat2_c(direction ,r, c);
            boat_v.push_back(b);
            addToField();
            break;}
        case 3:{
            boat3_c *b = new boat3_c(direction ,r, c);
            boat_v.push_back(b);
            addToField();
            break;}
        case 4:{
            boat4_c *b = new boat4_c(direction ,r, c);
            boat_v.push_back(b);
            addToField();
            break;}
        case 5:{
            boat5_c *b = new boat5_c(direction ,r, c);
            boat_v.push_back(b);
            addToField();
            break;}
        case 6:{
            boat6_c *b = new boat6_c(direction ,r, c);
            boat_v.push_back(b);
            addToField();
            break;}
        default:cout<<"not a boat"<<endl;break;
        }
        return;
    }

    //function to show the user the board
    void printBoard(){
        char top[10] = {'a','b','c','d','e','f','g','h','i','j'};//top row characters

        for(int i = 0; i < 50; i++){
            //print out a row of dashes
            cout << "-";
        }

        cout << "\n\t"; //initial tab for spacing
        for(int i = 0; i < 10; i++){
            //print out all the letters
            cout << top[i] << "\t";
        }

        cout << endl;//next line
        for(int i = 0; i < 10; i++){
            //print out all of the numbers for the board
            cout << i+1 << "\t";
            for(int j = 0; j < 10; j++){
                //print out what is in each spot of the board
                cout << field[i][j] << "\t";
            }
            cout << endl;
        }

        for(int i = 0; i < 50; i++){
            //print out a row of dashes
            cout << "-";
            if(i==49){cout<<endl<<endl;}
        }

    }
};
