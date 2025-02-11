#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "funcs.h"

int main(){
	int x, angle, i, player =1, z = 2,a;
	int scorearray[2][5], *temparray;
	// displays the menu screen
	menu();
	getch();
	system("cls");
	
	while (player != 3){
		 a = -1;
		// determines the player inputting the target
		if (player == 2) z =1;
		
		//player inputs the target
		while ((a < 0) or (a> 100)){
			printf("player %i, enter a distance between 1 and 100: ", z);	
			scanf("%i", &x);
			a = x;
			system("cls");}
		x = placeTarget(&x);
		
		
		switch (player){	
		// for player 1
			case 1:
				temparray = play(x, player);
				for (i = 0; i <5; i++) scorearray[0][i] = temparray[i];
				system("cls");
				break;
				
				
		//player 2's turn	
			case 2:
				temparray = play(x, player);
				for (i = 0; i <5; i++) scorearray[1][i] = temparray[i];
				system("cls");	
				break;
				
			default:
				printf("how did that happen");
				break;
		}
		player ++;	
	}
	// for determining the winner
	int p1 = scorearray[0][0], p2 = scorearray[1][0], p1hit, p2hit;
	for (i = 0; i <5; i++){
		if (scorearray[0][i] < p1) p1 = scorearray[0][i];
		if (scorearray[1][i] < p2) p2 = scorearray[1][i];}	
	
	if (p1 < p2) printf("player 1 is the winner!");
	else if (p2 < p1) printf("player 2 is the winner!");
	
	else if ((p1 == 0 ) and (p2 == 0)){
		for (i = 0; i <5; i++){
			if (scorearray[0][i] == p1){
				p1hit = i;
				break;}}
		for (i = 0; i <5; i++){
			if (scorearray[1][i] == p2) {
				p2hit = i;
				break;}}
		if (p1hit < p2hit) printf("player 1 is the winner!");
		else if (p2hit< p1hit) printf("player 2 is the winner!");
		else printf("its a tie!");}
			
	else printf("its a tie!");
}	