#include "board.hpp"


//TO DO:
// knight correct movement
// move length 4+
// pawn promotion
// double queen
// king check
// pawn takes correctly cxcr
// castle
// pause on loading game?
// settings/rules to chess.cpp

void generalRules(){
    std::cout << "Chess is a two-player strategy game. Each side starts with 16 pieces (A king, a queen, two bishops, two knights, two rooks, and eight pawns). The player with the white pieces (represented with capital letters) will go first, while the player with the black pieces (lowercase letters) will go second. The goal of the game is to capture the opponent’s king by using your pieces to create a situation where it has the king has no escape (called checkmate).  Pieces can capture opposing pieces by moving to the same square as the opposing piece" << std::endl << std::endl;
}

void moveNotation(){
    std::cout << "Move Notation:" << std::endl <<

    "Moves are made using a specific notation: (piece)(takes?)(space)(check(mate)?)" << std::endl <<
    "The piece is noted by a letter that corresponds to the type of piece (nothing or the column letter for pawn, b for bishop, n for knight, r for rook, q for queen, k for king)" << std::endl <<
    "If the piece is capturing another piece, it is followed by an x." << std::endl <<
    "The space is represented using its column letter and row number." << std::endl <<
    "If a move puts the king in check, it ends with a +. If it is checkmate, it is instead a #." << std::endl << std::endl <<

    "For example, a pawn moving to the e4 square is just e4. A rook moving to a5 is ra5. a knight taking a piece on c6 is nxc6. A queen delivering a checkmate on d2 is qd2#." << std::endl;
}

void pieceMovement(){
    std::cout << std::endl;
    while(1){
        std::string choice;
        std::cout << "Which piece would you like to learn about?" << std::endl <<
        "1. (P)awn"<< std::endl <<
        "2. (B)ishop"<< std::endl <<
        "3. K(n)ight"<< std::endl <<
        "4. (R)ook"<< std::endl <<
        "5. (Q)ueen"<< std::endl <<
        "6. (K)ing"<< std::endl <<
        "7. Go back" << std::endl <<
        "Choice: ";
        std::cin >> choice;
        std::cout << std::endl;
        if(choice == "7") return;
        else if(choice == "1") std::cout << "Pawn: The pawn moves one space forward. It captures by moving one space diagonally forward It can move two spaces on its first turn. If an opposing pawn moves two spaces forward and ends up next to an opposing pawn, the opposing pawn can capture it by moving diagonally (called en passant). It can not jump over pieces." << std::endl;
        else if(choice == "2") std::cout << "Bishop: Bishops move diagonally as many pieces as you want. They cannot jump over pieces." << std::endl;
        else if(choice == "3") std::cout << "Knight: Knights move in an L shape, one space in one direction and two pieces in another. It is the only piece that can jump over other pieces." << std::endl;
        else if(choice == "4") std::cout << "Rook: Rooks move vertically or horizontally as many spaces as they want. They cannot jump over other pieces" << std::endl;
        else if(choice == "5") std::cout << "Queen: The queen can move as many spaces as it wants in any direction. It cannot jump over other pieces ." << std::endl;
        else if(choice == "6") std::cout << "King: The king can move one space in any direction. If it has not moved yet, and there is a rook that also has not moved with no pieces between them, then the king can move two spaces in the direction of the rook and the rook moves next to the king on the king’s other side (called castling)." << std::endl;
        else std::cout << "Choice should be a number between 1 and 7." << std::endl;
        std::cout << std::endl;
    }    
}


void rules(){
    while(1){    
        int choice;
        std::cout << "Which rules would you like to view?" << std::endl <<
        "1. General Rules" << std::endl <<
        "2. Move Notation" << std::endl <<
        "3. Piece Movement" << std::endl <<
        "4. All" << std::endl << 
        "5. Exit" << std::endl << std::endl <<

        "Select option:" ;
        std::cin >> choice;
        if (choice == 5) break;
        if (choice == 1) generalRules();
        if (choice == 2) moveNotation();
        if (choice == 3) pieceMovement();
        if (choice == 4){
            generalRules();
            moveNotation();
            pieceMovement();
        }
    }
}

std::string toggleSetting(std::string old){
    if(old == "On") return "Off";
    return "On";
}

void benefits(){
    std::cout << "Pros and cons of enabling/disabling different settings:" << std::endl << 
    "1. Undo Moves: Enabling this allows players to avoid mistakes more easily and try new strategies if a previous one doesn’t work. Disabling it makes for a more challenging experience for the user." << std::endl << 
    "2. Enforce Rules: Enabling this forces both players to abide by the rules, making it a “true” game of chess. Disabling it allows for more freedom in how to play. " << std::endl << 
    "3. Time Limit: Enabling this forces players to think quickly, creating a more challenging experience. Disabling it guarantees that users will have time to think through their moves, allowing them to make the best moves they can each turn." << std::endl <<  std::endl;
}

void board::settings(){
    bool changed = false;
    std::string choice;
    int confirm;
    while(1){
        std::cout << "Game settings (select to toggle, preface with e (ex. e1) for explanation of the benefits/drawbacks of each state):" << std::endl << 
        "1. Undo Moves: " << this->undo << std::endl << 
        "2. Enforce Rules: " << this->enforce << std::endl << 
        "3. Time Limit: " << this->time_limit << std::endl << std::endl << 

        "Other Options:" << std::endl <<
        "4. View rules"<< std::endl <<
        "5. Return to Game" << std::endl << std::endl <<
        "Select option: " ;
        std::cin >> choice;
        if (choice[0] == 'e' || choice[0] == 'E') benefits();
        if(choice == "1") {this->undo = toggleSetting(this->undo); changed = true;}
        if(choice == "2") {this->enforce = toggleSetting(this->enforce); changed = true;}
        if(choice == "3") {this->time_limit = toggleSetting(this->time_limit); changed = true;}
        if(choice == "4") rules();
        if(choice == "5"){
            if(changed) {
                std::cout << "Confirm changes? (0 = no, 1 = yes): ";
                std::cin >> confirm;
                if (confirm) break;
            }
            else break;
        };
    }
}


void board::populateBoard(){
    this->square[7][0].letter = 'r';
    this->square[7][1].letter = 'n';
    this->square[7][2].letter = 'b';
    this->square[7][3].letter = 'q';
    this->square[7][4].letter = 'k';
    this->square[7][5].letter = 'b';
    this->square[7][6].letter = 'n';
    this->square[7][7].letter = 'r';
    for (int i = 0; i < 8; i++){
        this->square[6][i].letter = 'p';
    }

    this->square[0][0].letter = 'R';
    this->square[0][1].letter = 'N';
    this->square[0][2].letter = 'B';
    this->square[0][3].letter = 'Q';
    this->square[0][4].letter = 'K';
    this->square[0][5].letter = 'B';
    this->square[0][6].letter = 'N';
    this->square[0][7].letter = 'R';
    for (int i = 0; i < 8; i++){
        this->square[1][i].letter = 'P';
    }
}


void board::printBoard(){
    std::cout << " _________________________________" << std::endl;
    for (int i = 7; i >= 0; i--){
        std::cout << i+1;
        std::cout << "| ";
        for (int j = 0; j < 8; j++){
            std::cout << this->square[i][j].letter << " | "; 
        }
        std::cout << std::endl;
        std::cout << " ---------------------------------" << std::endl;
    }
    std::cout << "   a   b   c   d   e   f   g   h" << std::endl;
}


int convertColumn(char p){
    if (p == 'a') return 0;
    if (p == 'b') return 1;
    if (p == 'c') return 2;
    if (p == 'd') return 3;
    if (p == 'e') return 4;
    if (p == 'f') return 5;
    if (p == 'g') return 6;
    if (p == 'h') return 7;
    else return -1;
}

bool checkColumnLetter(char p){
    if (p == 'a' || p == 'b' || p == 'c' || p == 'd' || p == 'e' || p == 'f' ||p == 'g' || p == 'h') return true;
    else return false;
}

bool checkRowNumber(char p){
    if (p == '1' || p == '2' || p == '3' || p == '4' || p == '5' || p == '6' ||p == '7' || p == '8') return true;
    else return false;
}

bool board::removeOld(char piece, int newRow, int newColumn, std::string color, char oldPiece){
    if(piece == 'P' || piece == 'p'){
        if (color == "white"){
            if(oldPiece != ' '){
                if(this->square[newRow - 1][newColumn - 1].letter == piece){
                    this->square[newRow - 1][newColumn - 1].letter = ' '; return true;}
                else if(this->square[newRow - 1][newColumn + 1].letter == piece){
                    this->square[newRow - 1][newColumn + 1].letter = ' '; return true;}
            }
            for (int i = newRow - 1 ; i != newRow; i--){// start with pawns that could actually get there, then check rest of column
                if(i <= 0) i = 7; //loop around, don"t need to check back row
                if (this->square[i][newColumn].letter == piece){ 
                    this->square[i][newColumn].letter = ' ';
                    return true;
                }
            }
    }
        else{ //black
            if(oldPiece != ' '){
                if(this->square[newRow + 1][newColumn - 1].letter == piece){
                    this->square[newRow + 1][newColumn - 1].letter = ' '; return true;}
                else if(this->square[newRow + 1][newColumn + 1].letter == piece){
                    this->square[newRow + 1][newColumn + 1].letter = ' '; return true;}
            }
            for (int i = newRow + 1 ; i != newRow; i++){// start with pawns that could actually get there, then check rest of column
                if(i == 7) i = 0; //loop around, don"t need to check back row
                if (this->square[i][newColumn].letter == piece){ 
                    this->square[i][newColumn].letter = ' ';
                    return true;
                }
            }
        }
    }
    if(piece == 'R' || piece == 'r'){
        if (color == "white"){
            for (int i = newRow - 1 ; i != newRow; i--){// check columns
                std::cout << newRow << std::endl;
                if (this->square[i][newColumn].letter == piece){ 
                    this->square[i][newColumn].letter = ' ';
                    return true;
                }
                if(i == 0) i = 8; //loop around, don"t need to check back row]
            }
            for (int i = newColumn - 1 ; i != newColumn; i--){// check rows
                if (this->square[newRow][i].letter == piece){ 
                    this->square[newRow][i].letter = ' ';
                    return true;
                }
                if(i == 0) i = 8; //loop around, don"t need to check back row]
            }
        }
        else{
            for (int i = newRow + 1 ; i != newRow; i++){// check columns
                if(i > 7) i = 0; //loop around, don"t need to check back row
                if (this->square[i][newColumn].letter == piece){ 
                    this->square[i][newColumn].letter = ' ';
                    return true;
                }
            }
            for (int i = newColumn + 1 ; i != newColumn; i++){// check rows
                if(i > 7) i = 0; //loop around, don"t need to check back row
                if (this->square[newRow][i].letter == piece){ 
                    this->square[newRow][i].letter = ' ';
                    return true;
                }
            }
        }
    }
    if(piece == 'B' || piece == 'b'){
        for (int i = 1; i < 8; i++){
            if (newRow + i <= 7 && newColumn + i <= 7 && this->square[newRow + i][newColumn + i].letter == piece){ 
                this->square[newRow + i][newColumn + i].letter = ' ';
                return true;
            }
            if (newRow + i <= 7 && newColumn - i >= 0 && this->square[newRow + i][newColumn - i].letter == piece){ 
                this->square[newRow + i][newColumn - i].letter = ' ';
                return true;
            }
            if (newRow - i >= 0 && newColumn + i <= 7 && this->square[newRow - i][newColumn + i].letter == piece){ 
                this->square[newRow - i][newColumn + i].letter = ' ';
                return true;
            }
            if (newRow - i >= 0 && newColumn - i >= 0 && this->square[newRow - i][newColumn - i].letter == piece){ 
                this->square[newRow - i][newColumn - i].letter = ' ';
                return true;
            }
        }
    }
    if(piece == 'N' || piece == 'n'){

    }
    for (int j = 0; j < 8; j++){
        for (int i = 0; i < 8; i++){// just find one. works for all. only one queen and king so no specific checks needed
            if (this->square[i][j].letter == piece){ 
                this->square[i][j].letter = ' ';
                return true;
            }
        }
    }
    return false;
}

char convertToChar(std::string piece){
    if (piece == "P") return 'P';
    if (piece == "p") return 'p';
    if (piece == "R") return 'R';
    if (piece == "r") return 'r';
    if (piece == "B") return 'B';
    if (piece == "b") return 'b';
    if (piece == "N") return 'N';
    if (piece == "n") return 'n';
    if (piece == "Q") return 'Q';
    if (piece == "q") return 'q';
    if (piece == "K") return 'K';
    if (piece == "k") return 'k';
    return 'z';
}

void board::moveToNew(char column, char row, std::string piece, std::string color){
    std::string move;
    char charPiece = convertToChar(piece);
    int newRow, newColumn;
    if(checkColumnLetter(column) && checkRowNumber(row)){
        newColumn = convertColumn(column);
        newRow = row - '0' - 1;
        if(!this->removeOld(charPiece, newRow, newColumn, color, this->square[newRow][newColumn].letter)){ //executes function, asks for new input if no piece found
            std::cout << "Invalid notation. Please enter a new move: ";
            std::cin >> move;
            this->makeMove(move, color);
            return;
        }
        this->square[newRow][newColumn].letter = charPiece;
    }
    else{
        std::cout << "Invalid notation. Please enter a new move: ";
        std::cin >> move;
        this->makeMove(move, color);
        return;
    }
}


std::string board::correctCase(char piece, std::string color){
    if(piece == 'P' || piece == 'p') {
        if (color == "white") return "P";
        else return "p";
    }
    if(piece == 'R' || piece == 'r'){
        if (color == "white") return "R";
        else return "r";
    };
    if(piece == 'B' || piece == 'b'){
        if (color == "white") return "B";
        else return "b";
    };
    if(piece == 'N' || piece == 'n'){
        if (color == "white") return "N";
        else return "n";
    };
    if(piece == 'Q' || piece == 'q'){
        if (color == "white") return "Q";
        else return "q";
    };
    if(piece == 'K' || piece == 'k'){
        if (color == "white") return "K";
        else return "k";
    };
    std::string move;
    std::cout << "Error: piece not valid. Please enter a new move: ";
    std::cin >> move;
    this->makeMove(move, color);
    return "z";
}

void board::makeMove(std::string move, std::string color){
    //int oldRow, newRow, oldColumn, newColumn;
    std::string piece;
    if(move[1] == 'z') return;
    if (move.length() == 2){
        piece = correctCase('p', color);
        moveToNew(move[0], move[1], piece, color); //must be normal pawn move
    }
    if(move.length() == 3){
        piece = correctCase(move[0], color);
        if (move[0] == 'p' || move[0] == 'P') moveToNew(move[1], move[2], piece, color); //preceded with 'p'
        else if (move[2] == '#' || move[2] == '+') {
            piece = correctCase(move[0], color);
            moveToNew(move[1], move[2], piece, color); //pawn check
        }
        else moveToNew(move[1], move[2], piece, color);
    }
    if(move.length() == 4){
        piece = correctCase(move[0], color);
        if(move[0] == 'p' || move[0] == 'P') {
            if (move[1] == 'x') moveToNew(move[2], move[3], piece, color);//pawn takes. might need rework of pawnMove
            else if (move[1] == '#' || move[2] == '+') moveToNew(move[1], move[2], piece, color); //preceded with 'p', check
        }
    }

}

bool board::isGameOver(){
    bool whiteKing = false;
    bool blackKing = false;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(this->square[i][j].letter == 'K')
                whiteKing = true;
            if(this->square[i][j].letter == 'k')
                blackKing = true;
        }
    }
    if ((!whiteKing) || (!blackKing)) return true;
    return false;
}

std::string switchColor(std::string color){
    if (color == "white") return "black";
    else return "white";
}

void board::play(){
    std::string turn = "white";
    std::string move;
    bool over = false;
    //bool valid;
    this->populateBoard();
    while (!over){
        do{
            this->printBoard();
            std::cout << "It is " << turn << "'s turn." << std::endl << "Enter a move, or type m for the menu." << std::endl;
            std::cout << "Move: ";
            std::cin >> move;
            makeMove(move, turn);
            if (move == "m")
                settings();
            /*valid = validateMove();
            if (!valid){
                std::cout << move << " is not a valid move. Please enter a new one." << std::endl;
                std::cout << "Move: ";
                std::cin >> move; 
                if (move == m){
                    menu();
                    printBoard();
                }
                else valid = validateMove();
            }   
                */
        } while(move == "m");
        over = isGameOver();
        if (over){
            std::cout << "Game over, " << turn << " wins!" << std::endl;
        }
        else turn = switchColor(turn);
}
}