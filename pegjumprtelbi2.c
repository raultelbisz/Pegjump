// pegjumprtelbi2.c
//
// Peg Jumping game where you skip other pegs and remove the pegs that have been jumped over.
// The aim of the game is to get rid of as many pegs as possible.
//
// Author: Raul Telbisz
// Program: 2, Peg Jump
// TA: Moumita Samanta, Tues 11
// Feb 2, 2017
/*
	
	Running the program looks like:

			Author: Raul Telbisz
			Assignment: 2, Peg Jump
			TA : Moumita Samanta, Tues 11
			Feb 2, 2017

			This program represents the peg jumping puzzle.

			The board starts out with a single blank position, represented by
			the 'O'. To make a move, select the letter of the peg to be moved,
			then the letter of the destination position. (e.g. the first move
			might be: d a, meaning we move peg 'd' into blank position 'a'.)
			A peg must be able to jump over an adjacent peg into a blank  for a
			move to be valid. The jumped peg is then removed from the board.
			The game is over when there are no valid moves left to be made, or
			when there is a single peg left.

			At any point enter 'x' to exit the program.

			----------------------------
			  Board         Positions
				o               A
			   + +             B C
			  + + +           D E F
			 + + + +         G H I J
			+ + + + +       K L M N O

			Enter your move:

*/


#include <stdio.h>
#include <ctype.h>            // ctype header needed for toupper() function.
#pragma warning(disable:4996) // Had to include to disable the "scanf" error message. 
							  // Program still compiles and runs without it though.

//----------------------------------------------------------------
void programInformation()
{
	printf("Author: Raul Telbisz\n");
    printf("Assignment: 2, Peg Jump\n");
	printf("TA : Moumita Samanta, Tues 11 \n");
	printf("Feb 2, 2017");
	printf("\n");
	printf("\n");
}


//----------------------------------------------------------------
void programInstructions()
{
	printf("This program represents the peg jumping puzzle.\n");
	printf("\n");
	printf("The board starts out with a single blank position, represented by\n");
	printf("the 'O'. To make a move, select the letter of the peg to be moved,\n");
	printf("then the letter of the destination position. (e.g. the first move\n");
	printf("might be: d a, meaning we move peg 'd' into blank position 'a'.)\n");
	printf("A peg must be able to jump over an adjacent peg into a blank  for a\n");
	printf("move to be valid. The jumped peg is then removed from the board.\n");
	printf("The game is over when there are no valid moves left to be made, or\n");
	printf("when there is a single peg left.\n");
	printf("\n");
	printf("At any point enter 'x' to exit the program.\n");
}


//----------------------------------------------------------------
// Display the peg board. Arguments p1 through p15 are variables for locations on the board.
void displayBoard(
					char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8, char p9, // Locations on the board
	                char p10, char p11, char p12, char p13, char p14, char p15)						 //
{
	printf("                                \n");
	printf("----------------------------    \n");
	printf("  Board         Positions       \n"); 
	printf("    %c               A          \n", p1);             // The letters have been positioned as seen,
	printf("   %c %c             B C        \n", p2, p3);         // so that they show up in a proper triangular
	printf("  %c %c %c           D E F      \n", p4, p5, p6);     // as is required for this game.
	printf(" %c %c %c %c         G H I J    \n", p7, p8, p9, p10);
	printf("%c %c %c %c %c       K L M N O  \n", p11, p12, p13, p14, p15);
}


//-----------------------------------------------------------------
// Moves the peg specified in the moveFrom argument in place of the moveTo argument.
// Also calculates the intermediate peg in between the moveFrom and moveTo locations
// And replaces that peg with an empty spot or 'o' character.
void movePeg( char moveTo, char moveFrom,                                  
	          char *p1, char *p2, char *p3, char *p4, char *p5, 
	          char *p6, char *p7, char *p8, char *p9, char *p10, 
	          char *p11, char *p12, char *p13, char *p14, char *p15)
{

	
	char pegToJumpOver;   // Char declaration for the peg that will be jumped over and replaced with an 'o'.
	pegToJumpOver = (moveFrom + moveTo) / 2; // Calculation to find intermediate ASCII value between From and To.

	// Switch statement to change destination location to a peg or '+'
	switch (moveTo) {
	case 'A': *p1 = '+'; break;
	case 'B': *p2 = '+'; break;
	case 'C': *p3 = '+'; break;
	case 'D': *p4 = '+'; break;
	case 'E': *p5 = '+'; break;
	case 'F': *p6 = '+'; break;
	case 'G': *p7 = '+'; break;
	case 'H': *p8 = '+'; break;
	case 'I': *p9 = '+'; break;
	case 'J': *p10 = '+'; break;
	case 'K': *p11 = '+'; break;
	case 'L': *p12 = '+'; break;
	case 'M': *p13 = '+'; break;
	case 'N': *p14 = '+'; break;
	case 'O': *p15 = '+'; break;
	}

	// Switch statement to change source location to an empty spot or 'o'
	switch (moveFrom) {
	case 'A': *p1 = 'o'; break;
	case 'B': *p2 = 'o'; break;
	case 'C': *p3 = 'o'; break;
	case 'D': *p4 = 'o'; break;
	case 'E': *p5 = 'o'; break;
	case 'F': *p6 = 'o'; break;
	case 'G': *p7 = 'o'; break;
	case 'H': *p8 = 'o'; break;
	case 'I': *p9 = 'o'; break;
	case 'J': *p10 = 'o'; break;
	case 'K': *p11 = 'o'; break;
	case 'L': *p12 = 'o'; break;
	case 'M': *p13 = 'o'; break;
	case 'N': *p14 = 'o'; break;
	case 'O': *p15 = 'o'; break;
	}

	// Switch statement to change the peg being jumped over to an empty spot or 'o'
	switch (pegToJumpOver) {
	case 'A': *p1 = 'o'; break;
	case 'B': *p2 = 'o'; break;
	case 'C': *p3 = 'o'; break;
	case 'D': *p4 = 'o'; break;
	case 'E': *p5 = 'o'; break;
	case 'F': *p6 = 'o'; break;
	case 'G': *p7 = 'o'; break;
	case 'H': *p8 = 'o'; break;
	case 'I': *p9 = 'o'; break;
	case 'J': *p10 = 'o'; break;
	case 'K': *p11 = 'o'; break;
	case 'L': *p12 = 'o'; break;
	case 'M': *p13 = 'o'; break;
	case 'N': *p14 = 'o'; break;
	case 'O': *p15 = 'o'; break;
	}
}//end movePeg()


//-----------------------------------------------------------------
// Check the number of remaining pegs still in play and update the counter accordingly.
// Char arguments are locations on the peg board. If there is an empty spot or 'o' in
// one of the board's locations, then this function subtracts 1 from the counter for each empty spot.
int checkNumberOfPegs( char p1, char p2, char p3, char p4, char p5, 
					   char p6, char p7, char p8, char p9, char p10,
	                   char p11, char p12, char p13, char p14, char p15)
{
	int pegCounter = 15; // Initialized at 15 because the first if statement automatically subtracts 1 from the total count.

	// If statements so that the function counts each and every spot, 
	// subtracting from the total peg count as it investigates each location.
	if (p1 == 'o') {
		pegCounter--;
	}
	if (p2 == 'o') {
		pegCounter--;
	}
	if (p3 == 'o') {
		pegCounter--;
	}
	if (p4 == 'o') {
		pegCounter--;
	}
	if (p5 == 'o') {
		pegCounter--;
	}
	if (p6 == 'o') {
		pegCounter--;
	}
	if (p7 == 'o') {
		pegCounter--;
	}
	if (p8 == 'o') {
		pegCounter--;
	}
	if (p9 == 'o') {
		pegCounter--;
	}
	if (p10 == 'o') {
		pegCounter--;
	}
	if (p11 == 'o') {
		pegCounter--;
	}
	if (p12 == 'o') {
		pegCounter--;
	}
	if (p13 == 'o') {
		pegCounter--;
	}
	if (p14 == 'o') {
		pegCounter--;
	}
	if (p15 == 'o') {
		pegCounter--;
	}

	return pegCounter; // Returns the number of pegs still left on the board.
}//end checkNumberOfPegs()


//-----------------------------------------------------------------
// Get the current piece that is occupying a certain specified position.
// Less nerdy translation: Finds whether there is a '+' or 'o' in a
// specified position and returns that character.
char getPieceAt(char position,
	            char p1, char p2, char p3, char p4, char p5, 
	            char p6, char p7, char p8, char p9, char p10,
	            char p11, char p12, char p13, char p14, char p15)
{

	// Switch statement to determine what character lies in specified position.
	switch (position) {
	case 'A': return p1; break;
	case 'B': return p2; break;
	case 'C': return p3; break;
	case 'D': return p4; break;
	case 'E': return p5; break;
	case 'F': return p6; break;
	case 'G': return p7; break;
	case 'H': return p8; break;
	case 'I': return p9; break;
	case 'J': return p10; break;
	case 'K': return p11; break;
	case 'L': return p12; break;
	case 'M': return p13; break;
	case 'N': return p14; break;
	case 'O': return p15; break;
	}
}//end getPieceAt


//-----------------------------------------------------------------
// Verifies if a user's move is a valid move by checking source, destination, and jumped Pegs.
// Returns 0 or FALSE if any of the criteria for a valid move is violated
// and returns 1 or TRUE if ALL criteria for a valid move is met.
int verifyUsersMove(char moveTo, char moveFrom,
	                char p1, char p2, char p3, char p4, char p5, 
					char p6, char p7, char p8, char p9, char p10,
					char p11, char p12, char p13, char p14, char p15)
{
	char sourcePeg = getPieceAt(moveFrom,         // Finds what char ('+' or 'o') is  at the source location
		p1, p2, p3, p4, p5, p6, p7, p8, p9, p10,  //  and assigns it to sourcePeg.
		p11, p12, p13, p14, p15);
	
	char destinationPeg = getPieceAt(moveTo,	  // Finds what char ('+' or 'o') is  at the destination location
		p1, p2, p3, p4, p5, p6, p7, p8, p9, p10,  // and assigns it to destinationPeg.
		p11, p12, p13, p14, p15);
	
	char jumpedOverPeg = (moveFrom + moveTo) / 2; // Calculation to find the ASCII value of the peg being "jumped" over
												  //
	jumpedOverPeg = getPieceAt(jumpedOverPeg,     // Finds what char ('+' or 'o') is  at the "jumped over" location
		p1, p2, p3, p4, p5, p6, p7, p8, p9, p10,  // and assigns it to jumpedOverPeg.
		p11, p12, p13, p14, p15);

	// Verifies that the moveTo location is within the limits of the board ('a' through 'o')
	if ((moveTo > 'O') || (moveTo < 'A')) {
		printf("*** Invalid destination. Please retry. ***\n");
		return 0;
	}

	// Verifies that the moveFrom location is within the limits of the board ('a' through 'o')
	else if ((moveFrom > 'O') || (moveFrom < 'A')) {
		printf("*** Invalid source. Please retry. ***\n");
		return 0;
	}

	// Verifies that the sourcePeg has a '+' in order to pick up the peg from that location.
	else if (sourcePeg != '+') {
		printf("*** Source must have a piece. Please retry. ***\n");
		return 0;
	}

	// Verifies that the destinationPeg has a 'o' in order to move a peg into that spot.
	else if (destinationPeg != 'o') {
		printf("*** Destination must be empty. Please retry. ***\n");
		return 0;
	}

	// Verifies that the a peg is being jumped over.
	else if (jumpedOverPeg != '+') {
		printf("*** Must jump a piece. Please retry.\n");
		return 0;
	}

	return 1; // If all criteria have been met. Return 1.
}//end verifyUsersMove()


//-----------------------------------------------------------------
// Exit message in case the user presses 'x' at any moment in the game.
void exitMessage() 
{
	printf("\n");
	printf("User pressed 'X'. Exiting game.");

	return 0;
}//end exitMessage()


//-----------------------------------------------------------------
// Display a ratings system based on the number of pegs still left on the board.
// pegCounter argument is passed in from the main function in order to count the pegs.
// If the user inputs 'x' to exit, this ratings table will still appear.
void displayRatings(int pegCounter) 
{

	printf("                     \n");        // Ratings table
	printf("# left       Rating  \n");		  //
	printf("---------------------\n");		  //
	printf("  >4         Dufus   \n");        //
	printf("   4         Poor    \n");		  //
	printf("   3         Mediocre\n");		  //
	printf("   2         Good Job\n");		  //
	printf("   1         Genius! \n");        // End of ratings table


	// Personalized messages based on the number of pegs still left on the board.
	if (pegCounter > 4) {
		printf("You had more than 4 left, dufus! Try again.\n");
		return 0;
	}
	
	else if (pegCounter == 4) {
		printf("You had 4 left, poor job. Try again.\n");
		return 0;
	}
	
	else if (pegCounter == 3) {
		printf("You had 3 left, mediocre at best. Try again.\n");
		return 0;
	}
	
	else if (pegCounter == 2) {
		printf("You had 2 left, hey good job!\n");
		return 0;
	}
	
	else {
		printf("You had one left! You're a genius!\n");
		return 0;
	}

	// Exiting statement
	printf("Thanks for playing. Exiting...");
	
	return 0;
}// end displayRatings()


//-----------------------------------------------------------------
int main()
{
	char p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15; // Declaration of the peg board's variables
	
	char moveFrom, moveTo; // Declaration for the location a user wants to move from (moveFrom) and move to (moveTo).
	                       
	int pegCounter               = 14; // Declaration of the pegs remaining on the board with one spot open.
	int continueOrTerminate      = 0;  // Integer used later in the program to continue running
	                                   // or to terminate the program based on its value of true or false.

	p1 = 'o'; // Initializing the first position on the board to empty or 'o'
	p2 = p3 = p4 = p5 = p6 = p7 = p8 = p9 = p10 = p11 = p12 = p13 = p14 = p15 = '+'; // Filling the rest of the board
																					 // with pegs.

	programInformation();  // Displays information about the program
	programInstructions(); // Displays instructions on how to play the game
	
	displayBoard(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15); // Displays the peg board.
	
	
	// Entire program runs until the while condition is met.
	// That condition being until only 1 peg is left on the board.
	do {
		
		printf("\n");
		
		// Continues prompting the user for a valid input.
		do {

			printf("Enter your move:\n");
			scanf(" %c", &moveFrom);            // Scans the location where the user wishes to move from.
			moveFrom = toupper(moveFrom);       // Capitalizes every input by the user
			
			// If statement that runs before every iteration of the program to verify
			// whether the user inputs an 'x' or not.
			// If the user does input an x, it breaks out of the loop and displays the
			// ratings as well as an exit message.
			if (moveFrom == 'X') {
				exitMessage();
				printf("\n");
				printf("\n");
				displayRatings(pegCounter);
				
				return 0;
			}
			
			scanf(" %c", &moveTo);              // Scans the location where the user wishes to move to.
			moveTo = toupper(moveTo);           // Capitalizes every input by the user


			// Verifies the user's input and checks whether the move is valid or not.
			// If the move is invalid, the loop will terminate.
			continueOrTerminate = verifyUsersMove(moveTo, moveFrom,
				                                  p1, p2, p3, p4, p5, 
				                                  p6, p7, p8, p9, p10, 
				                                  p11, p12, p13, p14, p15);
	
		} while (continueOrTerminate == 0); // If all conditions are met, program continues and we move the peg.

	    // Moves the peg specified by the user into the specified location.
		// Passed arguments with ampersand here because the values on the board must
		// continously be updated.
		movePeg(moveTo, moveFrom, &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9, &p10, &p11, &p12, &p13, &p14, &p15);


		// Display the newly updated peg board.
		displayBoard(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);


		// Counts the number of pegs remaining on the board
		pegCounter = checkNumberOfPegs(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
		

	} while (pegCounter > 1); // Once the user reaches 1 peg left on the board, the loop ends.


	// Displays the rating of the user based on the number of pegs left on the board.
	displayRatings(pegCounter);


    return 0;
}//end main()
