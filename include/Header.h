#ifndef HEADER_H
#define HEADER_H

class Header
{
    public:
        short Customers[20];
        float ArrivalTime[20];
        float ServiceTime[20];
        float WaitInQueue[20];
        float ServiceBegin[20];
        float ServiceEnd[20];
        float ServiceIdleTime[20];
        float InterArrivalTime[20];
        float TimeSpendInSysytem[20];
//......................................................................................................................................

        float FillingWaitingQueueArray(float, float, float*); /// Filling Waiting Queue Array.                                           1
        bool CountCustomersWhoWait(float, float, float*);     ///                                                                        2
//......................................................................................................................................

        float avgWaitingTime(float*, short); /// The Average Waiting Time For a Customer.                                                1
        float probWait(float, float); /// The probability That a Customer Has To Wait IN The Queue.                                      2
        float ProbIdleServer(float*, float); /// The Fraction Of Idle Time Of The server.                                                3
        float probBeingBusy(float); /// The Probability Of The Server Being Busy.                                                        4
        float avgTimeBetweenArrivals(float*, short); /// The AVG Between Arrrivals                                                       5
     // void MeanOfServiceTimeDistribution(short, float); /// The Longer Simulation, The Closer The Average Will be To E(S) (LikeAbove). 7
        float avgServiceTime(float*, short); /// The Average Service Time.                                                               6
        float avgWaitingTimeOfThoseWhoWait(float*, short); /// The AVG Waiting Time of Those Who Actually Wait In The Queue.             8
        float avgTimeCustomreSpendsInTheSystem(float*, short); /// The AVG Time A Customer Spends IN The System.                         9
        float avgTimeCustomreSpendsInTheSystem2(float, float); /// The AVG Time A Customer Spends IN The System.                         10
};
//......................................................................................................................................

void print (short*, short, float*, float*);
void printResults(float*, short, float*, float*, float*, float*, float*);
void printLawsResults(float, float, float, float, float, float, float, float, float);

#endif
