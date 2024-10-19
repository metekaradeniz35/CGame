#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define cols 30
#define rows 30
#define foods 30

char board[rows * cols];
int score = 0;

void clearScreen() {
	system("cls");
}


void fillBoard() {
    int x,y;
    for(y=0; y<rows; y++) {
        for(x=0; x<cols; x++) {
            if(x==0||y==0||x==cols-1||y==rows-1) {
                board[y*cols + x] = '#';
            }else{
                board[y*cols + x] = ' ';
            }
        }
    }
}


void printBoard() {
    int x,y;
        
        clearScreen();
        
    for(y=0; y<rows; y++) {
        for(x=0; x<cols; x++) {
            putch(board[y*cols + x]);
        }
        putch('\n');
    }    
}

int turretX = 1;
int turretY = 1;


struct Food {
	int x,y;
	int consumed;
};

struct Food food[foods];

void drawFood() {
	int i; 
	for(i = 0;i < foods;i++) {
		if(!food[i].consumed) {
		board[food[i].y * cols + food[i].x] = '+';
	}
}
}

void setupFood() {
	int i;
	for(i = 0;i < foods;i++) {
		food[i].x = 1+rand() % (cols-2);
		food[i].y = 1+rand() % (rows-2);
		food[i].consumed = 0;
	}
}


void drawTurret() {
	board[turretY*cols + turretX] = '@';
} 

void moveTurret(int deltaX, int deltaY) {
	turretX +=deltaX;
	turretY += deltaY;
}

void rules() {
	int i,x,j;
	for(i = 0; i < foods;i++) {
		if(!food[i].consumed) {
			if(board[food[i].y * cols + food[i].x] == board[turretY*cols + turretX]) {
				score++;
				food[i].consumed = 1;
			}
		}
	}

}





void readKey() {
	int ch = getch();
	switch(ch) {
		case 'w': 
			moveTurret(0,-1); break;
		case 's': 
			moveTurret(0,1); break;
		case 'a': 
			moveTurret(-1,0); break;
		case 'd' : 
			moveTurret(1,0); break;
	}
}



int main() {
	srand(time(0));
	setupFood();
	while(1) {
		fillBoard();
		drawFood();
        drawTurret();
        rules();
        clearScreen();
        printBoard();
        readKey();
        printf("Score: %d", score);
	}
	

}
