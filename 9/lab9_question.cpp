/* Given another game to calculate diff of strength b/w players.*/
#include<cstdio>
#include<stdlib.h>

//Declaration of strength for function
class strength{
    public:
    int Diff(int S[],int players);
};

void Dealloc(int *a);//To free allocated memory during runtime

int main(){
    class strength Str;
    int t,players,*S;
    printf("Enter ythe no of test cases:");
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("Enter the no of participants:\n");
        scanf("%d",&players);
        S=(int *)malloc(sizeof(int)*players);
        printf("Enter the strengths of participants\n");
        for(int j=0;j<players;j++){
            scanf("%d",&S[j]);
        }
        Str.Diff(S,players);
        Dealloc(S);
    }
}
// To calculate the diff b/w each participant and the strongest among remaining
int strength::Diff(int S[],int players){
    int max1,max2;
    max2=0;
    max1=S[0];
    for(int i=0;i<players;i++){
        if(S[i]>max1){
            max2=max1;
            max1=S[i];
        }
        else if(S[i]>max2){
            max2=S[i];
        }
    }
    int diff[players];
    for(int i=0;i<players;i++){
        if(S[i]==max1){
            diff[i]=max1-max2;
        }
        else{
            diff[i]=S[i]-max1;
        }
    }
    for(int i=0;i<players;i++){
        printf("%d ",diff[i]);
    }
    printf("\n");
    return 0;
}
//to free allocated memory during runtime
void Dealloc(int *a){
    free(a);
}