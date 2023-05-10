#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    Header init;
    short Customers[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 ,13, 14, 15, 16, 17, 18, 19, 20};
    float ArrivalTime[20] = {0, 8, 14, 15, 23, 26, 34, 41, 43, 46, 47, 48, 53, 59, 62, 70, 71, 73, 77, 82};
    float ServiceTime[20] = {4, 1, 4, 3, 2, 4, 5, 4, 5, 3, 3, 5, 4, 1, 5, 4, 3, 3, 2, 3};
    float avgWaitingTime;                                                                                                   /// 1
    float CustomersNumberWhoWait = 0;                                                                                       /// 2
    float probWait;                                                                                                         /// 2
    float ProbIdleServer;
    float ProbBusyServer;
    float avgTimeBetweenArrivals;
    float avgServiceTime;
    float avgWaitingTimeOfThoseWhoWait;
    float avgTimeCustomersSpendInSystem;
    float AvgTimeCustomersSpendInSystem2;
//.................................................................................................................................

    for(int i=0; i<=19; i++)       /// Customers Initialization
        init.Customers[i] = Customers[i];

    for (int i=0; i<=19; i++)   /// Arrival Time Array Initialization
        init.ArrivalTime[i] = ArrivalTime[i];

     for (int i=0; i<=19; i++) /// Service Time Array Initialization
        init.ServiceTime[i] = ServiceTime[i];
//..................................................................................................................................

     for (int i=0; i<=19; i++){ /// Initializing Inter Arrival Time Array
        if(i == 0){
            init.InterArrivalTime[i] = 0;
            continue;
        }
        init.InterArrivalTime[i] = ArrivalTime[i] - ArrivalTime[i-1];                                                             /// 5
    }
//..................................................................................................................................

    print(&init.Customers[0], 20, &init.ArrivalTime[0], &init.ServiceTime[0]);                                                   /// print
//....................................................................................................................................

    init.WaitInQueue[0] = 0;  /// First Customer Won't Wait.
    for(int i=0; i<=19; i++)  /// Calculate Array Of Waiting Time For Each Customer.
        init.WaitInQueue[i+1] = init.FillingWaitingQueueArray(init.ArrivalTime[i], init.ServiceTime[i], &init.ArrivalTime[i+1]);
   avgWaitingTime = init.avgWaitingTime(&init.WaitInQueue[0], sizeof(init.Customers)/sizeof(init.Customers[0]));                   /// 1
//...................................................................................................................................

    float AT[20] = {0, 8, 14, 15, 23, 26, 34, 41, 43, 46, 47, 48, 53, 59, 62, 70, 71, 73, 77, 82};                                 /// 2
    float ST[20] = {4, 1, 4, 3, 2, 4, 5, 4, 5, 3, 3, 5, 4, 1, 5, 4, 3, 3, 2, 3};
//...................................................................................................................................

    avgServiceTime = init.avgServiceTime(&ST[0], 20);                                                                              /// 6
//...................................................................................................................................

    for (int i=0; i<19; i++)
        CustomersNumberWhoWait += init.CountCustomersWhoWait(AT[i], ST[i], &AT[i+1]);
        probWait = init.probWait(CustomersNumberWhoWait, sizeof(init.Customers)/sizeof(init.Customers[0]));                        /// 2
//....................................................................................................................................

    avgWaitingTimeOfThoseWhoWait = init.avgWaitingTimeOfThoseWhoWait(&init.WaitInQueue[0], CustomersNumberWhoWait);                /// 8
//....................................................................................................................................

   for (short i=0; i<=19; i++)   /// Initializing Service Begin Array
        init.ServiceBegin[i] = AT[i];
   for (short i=0; i<=19; i++)  /// Initializing Service End Array
        init.ServiceEnd[i] = init.ServiceBegin[i] + ST[i];
    for (short i=0; i<=19; i++){    /// Initializing Service idle Time Array
        if (i == 0){
            init.ServiceIdleTime[i] = 0;
            continue;
        }
       init.ServiceIdleTime[i] = init.ServiceBegin[i] - init.ServiceEnd[i-1];
    }
//.....................................................................................................................................

    ProbIdleServer = init.ProbIdleServer(&init.ServiceIdleTime[0], init.ServiceEnd[19]);                                           /// 3
//.....................................................................................................................................

    ProbBusyServer =  init.probBeingBusy(ProbIdleServer);                                                                          /// 4
//.....................................................................................................................................

    avgTimeBetweenArrivals = init.avgTimeBetweenArrivals(&init.InterArrivalTime[0], 20);                                           /// 5
//.....................................................................................................................................

    float AT2[20] = {0, 8, 14, 15, 23, 26, 34, 41, 43, 46, 47, 48, 53, 59, 62, 70, 71, 73, 77, 82};                                /// 9
    for (short i=0; i<=19; i++){
        init.TimeSpendInSysytem[i] = init.ServiceEnd[i] - AT2[i];
    }
    avgTimeCustomersSpendInSystem = init.avgTimeCustomreSpendsInTheSystem(&init.TimeSpendInSysytem[0], 20);                        /// 9
//......................................................................................................................................

    AvgTimeCustomersSpendInSystem2 = init.avgTimeCustomreSpendsInTheSystem2(avgWaitingTime, avgServiceTime);                       /// 10
//......................................................................................................................................

    printResults(&init.WaitInQueue[0], 20, &init.ServiceBegin[0], &init.ServiceEnd[0], &init.ServiceIdleTime[0],
                  &init.InterArrivalTime[0], &init.TimeSpendInSysytem[0]);                                                       /// print
//........................................................................................................................................

    printLawsResults(avgWaitingTime, probWait, ProbIdleServer, ProbBusyServer, avgTimeBetweenArrivals, avgServiceTime,
                      avgWaitingTimeOfThoseWhoWait, avgTimeCustomersSpendInSystem, AvgTimeCustomersSpendInSystem2);              /// print
}
