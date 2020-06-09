# BattleShip-game
Final project for Object Oriented programming

Used inherience and multiple .h files to create a battle ship game. Needs two users to play(no option for a computer generated response.

This program is a BattleShip game, it is set up to have 2 players who each have 5 boats and the first person to sink all of the other player's boats wins. 

In this program, there was a base boat class which all of the boats were derived from. The derived boats were based on the size of the boats, there is a derived boat class for a boat size of 1, 2, 3, 4, and 5. 

There are 4 different classes that all need to talk to each other, the main, player, board and boat. 

The main includes the player.h file which includes the board.h which includes the boat.h file.

The board class stores all of the information about each players board, the board that stores where their ships are placed and the board that stores their shots, the hits, and the misses. In the game, 0 is water, 1 is a boat, 2 is a hit and 3 is a miss. 
Each board is its own object, so each player has 2 board objects and 5 boat objects. 

The game is set up so that once a player sinks the other players 5 ships the game ends. 

In the player class is where all of the comparisons happen and the main hold all of the game aspects, like switching turns between the players and ending the game. The player class, has a function that tests if it is a hit and also asks the user to populate their board with the boats. 

In the main, there is a function that runs the game and in the main itself there is only a print out of the rules and calling to the function that runs the game. 

To keep track of the end of the game, each player has a number representing the number of their boats that have been sunk and when that becomes 5 the game will end.
