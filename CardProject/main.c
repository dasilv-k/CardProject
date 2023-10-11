//
//  main.c
//  CardProject
//
//  Created by Kevin on 09/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "Header.h"

struct Card {
    char Name[20];
    int Attack;
    int Defense;
    int PV;
    int Cost;
};

void StartApp(void){
    printf("App has been launched !\n");
}

void LoadGame(void){
    printf("Loaded Game");
}

void MainMenu(void){
    enum MenuButtons {
        New_Game = 1,
        Load_Game = 2,
        Quit = 3
    };
    
    int MenuChoice = 1;
    
    enum MenuButtons MyMenuButtons = MenuChoice;
    
    printf("1 : New Game \n"
           "2 : Load Game \n"
           "3 : Quit\n");
    scanf("%d", &MyMenuButtons);
    switch (MyMenuButtons) {
        case New_Game:
            StartGame();
            break;
//            case Load_Game:
//                Load_Game();
//                break;
        case Quit:
            EndApp();
            break;
            
        default:
            MainMenu();
    }
}

void StartGame(void){
    struct Card arr_card[10] = {
        {"pion1", 3, 1, 10, 4},
        {"pion2", 5, 3, 10, 4},
        {"pion3", 2, 5, 10, 4},
        {"pion4", 4, 3, 10, 4},
        {"pion5", 6, 2, 10, 4},
        {"pion6", 7, 0, 10, 4},
        {"pion7", 2, 3, 10, 4},
        {"pion8", 1, 6, 10, 4},
        {"pion9", 4, 2, 10, 4},
        {"pion10", 9, 0, 10, 4}
    };
    int i = 0;
    for (i=0; i<5; i++) {
        int CardPulled = PullCard();
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("Card name : %s\n", arr_card[CardPulled].Name);
        printf("Attack : %d\n", arr_card[CardPulled].Attack);
        printf("Defense : %d\n", arr_card[CardPulled].Defense);
        printf("PV : %d\n", arr_card[CardPulled].PV);
        printf("Cost : %d\n", arr_card[CardPulled].Cost);
    }
    printf("Voici les cartes tirées\n");
}

int PullCard(void){
    int nb_card = 10;
    int random_card_id = rand() % nb_card;
    
    return random_card_id;
}

void EndApp(void){
    exit(0);
}


int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    StartApp();
    MainMenu();
    EndApp();
    return 0;
}
