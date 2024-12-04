#include<stdio.h>
#include<string.h>
typedef struct Player{
    int ballscore[12];
    char playerName[50];
    int totalScore;
}Player;
int validateScore(int score){
    if(score>=1&&score<=6){
        return 1;
    } return 0;
}
void playGame(Player *player){
    int score;
    (*player).totalScore=0;
    printf("Enter the score of player: %s\n",(*player).playerName);
    
    for(int i=0;i<12;i++){
        printf("Enter the score for ball %d\n",i+1);
        scanf("%d",&score);
        if(validateScore(score)){
            (*player).ballscore[i]=score;
            (*player).totalScore+=score;
        }
        else {
            printf("The ball is counted but no run score,Invalid Score");
            player->ballscore[i]=0;
        }
    }
}
void findWinner(Player player1,Player player2){
    if(player1.totalScore>player2.totalScore){
        printf("The winner is %s\n",player1.playerName);
    }
    else if(player2.totalScore<player1.totalScore){
        printf("The winner is %s\n",player2.playerName);
    }
    else printf("There is a draw\n");
}
void displayMatchScoreboard(Player player1, Player player2){
    printf("\n---Match Score Board---\n");
    printf("%s's Scores: ",player1.playerName);
    for(int i=0;i<12;i++){
        printf("%d ",player1.ballscore[i]);
    }    printf("%d ",player1.totalScore);
    printf("%s's Scores: ",player2.playerName);
    for(int i=0;i<12;i++){
        printf("%d ",player2.ballscore[i]);
    }    printf("%d ",player2.totalScore);
}
int main(){
    Player player1, player2;
    printf("Enter First Player name: \n");
    scanf("%s",player1.playerName);
    printf("Enter second Player name: \n");
    scanf("%s",player2.playerName);
    playGame(&player1);
    playGame(&player2);
    displayMatchScoreboard(player1,player2);
    findWinner(player1,player2);
    return 0;
}
