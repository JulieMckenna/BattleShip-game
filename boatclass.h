//boat base class
//Julie McKenna and Jullian Peters
#include <string>
#include <iostream>
using namespace std;
class boat_c {
protected:
    int length, startRow, startCol;
    string direction;
    bool sunk = false;
public:
    boat_c()
    {
    }
    void setLength(int l){
    length = l;}
    void setdirection(string d){
        direction = d;}
    void setStartRow(int sr){
    startRow = sr;}
    void setStartCol(int sc){
    startCol = sc;}
    int getLength(){
        return length;
    }
    int getColumn(){
        return startCol;
    }
    int getRow(){
        return startRow;
    }
    string getDirection(){
        return direction;
    }
    virtual bool hit(int r, int c){
        cout << "this is base class" << endl;
        return false;
    }
    virtual bool isSunk(){
        return sunk;
    }

};


class boat1_c : public boat_c{
    //setLength, setDirection
private:
    int hits[1] = {1};
public:
    boat1_c(int r, int c){
        startRow = r;
        startCol = c;
        setLength(1);
        cout << "Created Boat 1" << endl;
    }
    bool isSunk(){
        return sunk;
    }
    bool hit(int r, int c)
    {
        bool hit;
        if( (startRow == r) && (startCol == c) )
        {
            hits[0] = 0;
            hit = true;
            sunk = true;
            cout << "Boat Sunk" << endl;
        }else{
            hit = false;
            //cout << "Miss" << endl;
        }
        return hit;
    }
};

//boat of size two

class boat2_c : public boat_c{
    //setLength, setDirection
private:
    int hits[2] = {1,1};

public:

    boat2_c(string d, int sr, int sc)
    {
        setLength(2);
        direction = d;
        startRow = sr;
        startCol = sc;

        if(direction == "vertical")
        {
            hits[0] = startRow;
            hits[1] = startRow + 1;
        }
        else
        {
            hits[0] = startCol;
            hits[1] = startCol + 1;
        }
        cout << "Created a boat starting at: " << startRow << ", " << startCol << " in the " << direction << " direction.\n";
    }

    bool isSunk(){
        if( (hits[0] == 0) && (hits[1] == 0) ){
            sunk = true;
            return sunk;
        }else{
            return false;
        }
    }

    bool hit(int r, int c)
    {
        bool hit = 0;
        if(direction == "vertical")
        {
            if(c == startCol)
            {
                for(int i = 0; i < 2; i++)
                {
                    if(r == startRow+i)
                    {
                        hit = true;
                        hits[i] = 0;
                    }
                }

            }
        }
        else
        {
            if(r == startRow)
            {
                for(int i = 0; i < 2; i++)
                {
                    if(c == startCol+i)
                    {
                        hit = true;
                        hits[i] = 0;
                    }
                }

            }
        }
        if(hit){
            cout << "hit" << endl;
            if(isSunk()){
                cout << "Boat Sunk" << endl;
            }
        }else{
            //cout << "miss" << endl;
        }
        return hit;
    }



};

//boat of size three

class boat3_c : public boat_c{
    //setLength, setDirection
private:
    int hits[3] = {1,1,1};
public:

    boat3_c(string d, int sr, int sc)
    {
        setLength(3);
        direction = d;
        startRow = sr;
        startCol = sc;

        if(direction == "vertical")
        {
            hits[0] = startRow;
            for(int i = 1; i < 3; i++)
                hits[i] = startRow + i;
        }
        else
        {
            hits[0] = startCol;
            for(int i = 1; i < 3; i++)
                hits[i] = startCol +i;
        }
        cout << "Created a boat starting at: " << startRow << ", " << startCol << " in the " << direction << " direction.\n";
    }

    bool isSunk(){
        if( (hits[0] == 0) && (hits[1] == 0) && (hits[2] == 0) ){
            sunk = true;
            return sunk;
        }else{
            return false;
        }
    }

    bool hit(int r, int c)
    {
        bool hit = 0;
        if(direction == "vertical")
        {
            if(c == startCol)
            {
                for(int i = 0; i < 3; i++)
                {
                    if(r == startRow+i)
                    {
                        hit = true;
                        hits[i] = 0;
                    }
                }

            }
        }
        else
        {
            if(r == startRow)
            {
                for(int i = 0; i < 3; i++)
                {
                    if(c == startCol+i)
                    {
                        hit = true;
                        hits[i] = 0;
                    }
                }

            }
        }
        if(hit){
            cout << "hit" << endl;
            if(isSunk()){
                cout << "Boat Sunk" << endl;
            }
        }else{
            //cout << "miss" << endl;
        }
        return hit;
    }



};

class boat4_c : public boat_c{
    //setLength, setDirection

private:
    int hits[4] = {1,1,1,1};
public:

    boat4_c(string d, int sr, int sc)
    {
        setLength(4);
        direction = d;
        startRow = sr;
        startCol = sc;

        if(direction == "vertical")
        {
            hits[0] = startRow;
            for(int i = 1; i < 4; i++)
                hits[i] = startRow + i;
        }
        else
        {
            hits[0] = startCol;
            for(int i = 1; i < 4; i++)
                hits[i] = startCol +i;
        }
        cout << "Created a boat starting at: " << startRow << ", " << startCol << " in the " << direction << " direction.\n";
    }
    bool isSunk(){
        if( (hits[0] == 0) && (hits[1] == 0) && (hits[2] == 0) && (hits[3] == 0)){
            sunk = true;
            return sunk;
        }else{
            return false;
        }
    }

    bool hit(int r, int c)
    {
        bool hit = 0;
        if(direction == "vertical")
        {
            if(c == startCol)
            {
                for(int i = 0; i < 4; i++)
                {
                    if(r == startRow+i)
                    {
                        hit = true;
                        hits[i] = 0;
                    }
                }

            }
        }
        else
        {
            if(r == startRow)
            {
                for(int i = 0; i < 4; i++)
                {
                    if(c == startCol+i)
                    {
                        hit = true;
                        hits[i] = 0;
                    }
                }

            }
        }
        if(hit){
            cout << "hit" << endl;
            if(isSunk()){
                cout << "Boat Sunk" << endl;
            }
        }else{
            //cout << "miss" << endl;
        }
        return hit;
    }



};

//boat of size five

class boat5_c : public boat_c{
    //setLength, setDirection
private:
    int hits[5] = {1,1,1,1,1};
public:

    boat5_c(string d, int sr, int sc)
    {
        setLength(5);
        direction = d;
        startRow = sr;
        startCol = sc;

        if(direction == "vertical")
        {
            hits[0] = startRow;
            for(int i = 1; i < 5; i++)
                hits[i] = startRow + i;
        }
        else
        {
            hits[0] = startCol;
            for(int i = 1; i < 5; i++)
                hits[i] = startCol +i;
        }
        cout << "Created a boat starting at: " << startRow << ", " << startCol << " in the " << direction << " direction.\n";
    }
    bool isSunk(){
        if( (hits[0] == 0) && (hits[1] == 0) && (hits[2] == 0) && (hits[3] == 0) && (hits[4] == 0) ){
            sunk = true;
            return sunk;
        }else{
            return false;
        }
    }
    bool hit(int r, int c)
    {
        bool hit = 0;
        if(direction == "vertical")
        {
            if(c == startCol)
            {
                for(int i = 0; i < 5; i++)
                {
                    if(r == startRow+i)
                    {
                        hit = true;
                        hits[i] = 0;
                    }
                }

            }
        }
        else
        {
            if(r == startRow)
            {
                for(int i = 0; i < 5; i++)
                {
                    if(c == startCol+i)
                    {
                        hit = true;
                        hits[i] = 0;
                    }
                }

            }
        }
        if(hit){
            cout << "hit" << endl;
            if(isSunk()){
                cout << "Boat Sunk" << endl;
            }
        }else{
            //cout << "miss" << endl;
        }
        return hit;
    }



};

//boat of size six

class boat6_c : public boat_c{
    //setLength, setDirection, sunk
private:
    int hits[6] = {1,1,1,1,1,1};
public:

    boat6_c(string d, int sr, int sc)
    {
        setLength(6);
        direction = d;
        startRow = sr;
        startCol = sc;

        if(direction == "vertical")
        {
            hits[0] = startRow;
            for(int i = 1; i < 6; i++)
                hits[i] = startRow + i;
        }
        else
        {
            hits[0] = startCol;
            for(int i = 1; i < 6; i++)
                hits[i] = startCol +i;
        }
        cout << "Created a boat starting at: " << startRow << ", " << startCol << " in the " << direction << " direction.\n";
    }

    bool isSunk(){
        if( (hits[0] == 0) && (hits[1] == 0) && (hits[2] == 0) && (hits[3] == 0) && (hits[4] == 0) && (hits[5] == 0) ){
            sunk = true;
            return sunk;
        }else{
            return false;
        }
    }

    bool hit(int r, int c)
    {
        bool hit = 0;
        if(direction == "vertical")
        {
            if(c == startCol)
            {
                for(int i = 0; i < 6; i++)
                {
                    if(r == startRow+i)
                    {
                        hit = true;
                        hits[i] = 0;
                    }
                }

            }
        }
        else
        {
            if(r == startRow)
            {
                for(int i = 0; i < 6; i++)
                {
                    if(c == startCol+i)
                    {
                        hit = true;
                        hits[i] = 0;
                    }
                }

            }
        }
        if(hit){
            cout << "hit" << endl;
            if(isSunk()){
                cout << "Boat Sunk" << endl;
            }
        }else{
            //cout << "miss" << endl;
        }
        return hit;
    }



};
