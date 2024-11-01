
#include<stdio.h>

void WaitingTime(int n, int BT[], int REM_BT[], int AT[], int WT[])
{
    int t, count = 0;
    REM_BT[50] = 100;

    for (t = 0 ; count != n ; t++)
    {

        int m = 50;

        for (int i = 0; i < n; i++)
        {
            if (AT[i] <= t &&  REM_BT[i] < REM_BT[m] && REM_BT[i] > 0 )
            {
                m = i ;
            }
        }

        REM_BT[m] = REM_BT[m] - 1;

        if (REM_BT[m] == 0)
        {
            count++;
            WT[m] = t+1 - (BT[m] + AT[m]) ;
        }

    }
}


void TurnArroundTime(int n, int PID[],  int BT[], int WT[], int TAT[])
{
    for (int i = 0; i < n ; i++)
    {
        TAT[i] = BT[i] + WT[i];
    }
}

void printAll(int n ,int PID[], int BT[] ,int AT[], int WT[] , int TAT[])
{
    printf ("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0 ; i<n ;i++)
    {
        printf ("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",PID[i],BT[i],AT[i],WT[i],TAT[i]);
    }
}

void average(int n ,int WT[] , int TAT[])
{
    float TWT = 0 , TTAT = 0 , AWT , ATAT ;
    for(int i=0 ; i<n ; i++)
    {
       TWT += WT[i];
       TTAT += TAT[i];
    }
    AWT = TWT/n;
    ATAT = TTAT/n;

    printf ("\n\nAverage waiting time : %.2f" ,AWT);
    printf ("\nAverage turn around time : %.2f\n\n" ,ATAT);
}

main()
{
    int n;
    printf("Enter the number of process : ");
    scanf ("%d",&n);


    int PID[n] , BT[n] , REM_BT[n], AT[n] , WT[n] , TAT[n] ;
    for(int i=0 ; i < n ; i++)
    {
printf("Enter process id for p%d: ", i);
scanf("%d",&PID[i]);
        printf("Burst time P%d : ",PID[i]);
        scanf("%d",&BT[i]);
        REM_BT[i]= BT[i];
        printf("Arrival time P%d : ",PID[i]);
        scanf("%d",&AT[i]);
    }

    WaitingTime(n , BT , REM_BT , AT , WT);
    TurnArroundTime(n, PID, BT, WT, TAT);
    printAll(n ,PID, BT ,AT ,WT, TAT);
    average(n ,WT, TAT);
}

