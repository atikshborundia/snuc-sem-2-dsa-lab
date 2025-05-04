/*Nene created a game where it kicks out players at a given position for a given numbere of players.
If the no of players is less than that of the position of the player to be kicked out, then that position is skipped.
This is continued till the round none of the players are kicked out.
The remaining players are declared as winners. Only need to return the no of winners.
multiple test cases with multiple games with no fixed no of players.
t->testcases.
res[t]->results of each test case.
k->no of payers to be kicked out in each round.
q->no of games.
a[k]->seq of position of players to be kicked out.
p[q]->no of players for each game.*/
#include<cstdio>
#include<stdlib.h>

//Declaration of Game
class Game{
    public:
    int WinCalc(int seq[],int size,int players);//To calculate no of winners
};
 
void Dealloc(int *a);//To free the allocated memory during runtime

int main(){
    class Game game;
    int t,k,q;
    int *a,*p;
    printf("Enter the no of test cases:");
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("Enter values of k and q:");
        scanf("%d %d",&k,&q);
        a=(int *)malloc(sizeof(int)*k);
        p=(int *)malloc(sizeof(int)*q);
        printf("Enter the sequence:\n");
        for(int j=0;j<k;j++){
            scanf("%d",&a[j]);
        }
        printf("Enter the no of players in each game(%d games):\n",q);
        for(int j=0;j<q;j++){
            scanf("%d",&p[j]);
        }
        int res;
        for(int j=0;j<q;j++){
            res=game.WinCalc(a,k,p[j]);
            printf("%d ",res);
        }
        printf("\n");
        Dealloc(a);
        Dealloc(p);
    }
}
//To calculate the no of winners
int Game::WinCalc(int seq[],int size,int players){
    int kickout;
    while(true){
        kickout=0;
        for(int i=0;i<size;i++){
            if(seq[i]<=players){
                kickout+=1;
            }
        }
        players-=kickout;
        if(kickout==0){
            break;
        }
    }
    return players;
}

void Dealloc(int *a){
    free(a);
}