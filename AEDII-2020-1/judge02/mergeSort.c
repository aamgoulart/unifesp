#include <stdio.h>
#define C 100
#define V 3

float countingFirstTurn(int votes[][V], int cadidateValue, int voters, int couting[]);
float porcentOfCandidate(int couting[], int candidate, int voters, int votesValid);
void porcentOfCandidates(float coutingPorcent[], int candidateValue, int couting[], int voters, float votesValid);
float winnerFirstTurn(float coutingPorcent[], int candidateValue);
float firstTurn(int votes[][V], int candidateValue, int voters, int counting[], float coutingPorcent[], int secondTurn[]);
void clearMemoryArray(int couting[], int candidateValue);
float countingSecondTurnFunction(int votes[][V], int candidateValue, int voters, int coutingSecondTurn[], int secondTurn[]);
float secondTurn(float coutingPorcentSecondTurn[], int votes[][V], int candidateValue, int voters, int coutingSecondTurn[], int secondTurn[]);
void porcentOfCandidatesSecondTurn(float coutingPorcent[], int couting[], int voters, float votesValid);

int main()
{
    int voters, cadidateValue , couting[C], secondTurnArray[1], coutingSecondTurn[C], votes[C][V];
    float coutingPorcent[C], coutingPorcentSecondTurn[C];
    int i, j;
    float isFirstTurn;

    scanf("%d", &voters);
    scanf("%d", &cadidateValue);
    clearMemoryArray(couting, cadidateValue);
    clearMemoryArray(coutingSecondTurn, cadidateValue);
    clearMemoryArray(secondTurnArray, 1);

    for (i = 0; i < voters; i++)
    {
        for (j = 0; j < V; j++)
        {
            scanf("%d", &votes[i][j]);
        }
    }
    isFirstTurn = firstTurn(votes, cadidateValue, voters, couting, coutingPorcent, secondTurnArray);

    if ( isFirstTurn < 50 && isFirstTurn != 0 && isFirstTurn != 50)
    {
        secondTurn(coutingPorcentSecondTurn,votes,cadidateValue, voters, coutingSecondTurn, secondTurnArray);
    } 

}

float countingFirstTurn(int votes[][V], int candidateValue, int voters, int couting[])
{
    int i;
    int candidate;
    float votesValid = 0;

    for (i = 0; i < voters; i++)
    {
        if (votes[i][0] <= candidateValue)
        {
            candidate = votes[i][0];
            couting[candidate]++;
            votesValid++;
        }
    }
    return votesValid;
}

void porcentOfCandidates(float coutingPorcent[], int candidateValue, int couting[], int voters, float votesValid)
{
    int i;
    for (i = 0; i < candidateValue; i++)
    {
        coutingPorcent[i] = (couting[i] * 100) / votesValid;
    }
}

float firstTurn(int votes[][V], int candidateValue, int voters, int counting[], float coutingPorcent[], int secondTurn[])
{
    float winnerPorcent = 0;
    int winnerCandidate = 0;
    int secondPlace = 0;
    int i;
    float votesValid = countingFirstTurn(votes, candidateValue, voters, counting);
    porcentOfCandidates(coutingPorcent, candidateValue, counting, voters, votesValid);

    for (i = 0; i < candidateValue; i++)
    {
        if (coutingPorcent[i] > winnerPorcent)
        {
            winnerCandidate = i;
            secondTurn[0] = i;
            winnerPorcent = coutingPorcent[i];
        }
    }

    for (i = 0; i < candidateValue; i++)
    {
        if (coutingPorcent[i] > secondPlace && coutingPorcent[i] != winnerCandidate)
        {
            secondPlace = i;
            secondTurn[1] = i;
        }
    }
    if (winnerPorcent == 0) {
        printf("0");
    } else {
        printf("%d %.2f\n", winnerCandidate, winnerPorcent);

    }
    return winnerPorcent;
}

void clearMemoryArray(int couting[], int candidateValue)
{
    int i = 0;
    for (i = 0; i < candidateValue; i++)
    {
        couting[i] = 0;
    }
}

void porcentOfCandidatesSecondTurn(float coutingPorcent[], int couting[], int voters, float votesValid)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        coutingPorcent[i] = (couting[i] * 100) / votesValid;
    }
}

float countingSecondTurnFunction(int votes[][V], int candidateValue, int voters, int coutingSecondTurn[], int secondTurn[])
{
    int i, j;
    int candidate;
    float votesValid = 0;

    for (i = 0; i < voters; i++)
    {
        j=0;
        if (votes[i][j] == secondTurn[0] || votes[i][j] == secondTurn[1]){
            candidate = votes[i][j];
            coutingSecondTurn[candidate-1]++;
            votesValid++;
        } else {
            for (j=0; votes[i][j] != secondTurn[0] || votes[i][j] != secondTurn[1], j <2; j++);
                        
            candidate = votes[i][j];
            coutingSecondTurn[candidate-1]++;
            votesValid++;

        }
    }
    return votesValid;
}

float secondTurn(float coutingPorcentSecondTurn[], int votes[][V], int candidateValue, int voters, int coutingSecondTurn[], int secondTurn[]){
    int i;
    float votesValid = countingSecondTurnFunction(votes, candidateValue, voters, coutingSecondTurn, secondTurn);
    float winnerPorcent = 0;
    int winnerCandidate = 0;

    porcentOfCandidatesSecondTurn(coutingPorcentSecondTurn, coutingSecondTurn, voters, votesValid);
    for (i = 0; i <= 1 ; i++)
    {
        if (coutingPorcentSecondTurn[i] > winnerPorcent)
        {
            winnerPorcent = coutingPorcentSecondTurn[i];
            winnerCandidate = i;
        }
    }    

    printf("%d %.2f\n", winnerCandidate+2, winnerPorcent);
    return winnerPorcent;
}