#include "Header.h"
#include <iostream>
using namespace std;

float Header::FillingWaitingQueueArray(float CurrentArrivalTime, float TimeOfService, float* NextArrivalTime){
    float result;
    float temp;
    float waiting;
    if(CurrentArrivalTime+TimeOfService <= *NextArrivalTime)
        return 0;

    else if(CurrentArrivalTime+TimeOfService > *NextArrivalTime){
        temp = CurrentArrivalTime+TimeOfService;
        waiting = temp - *NextArrivalTime;
        result = temp - *NextArrivalTime;
        *NextArrivalTime += result;
        return waiting;                                                                                                             /// 1
    }
}
//................................................................................................................................

bool Header::CountCustomersWhoWait(float CurrentArrivalTime, float TimeOfService, float* NextArrivalTime){
   float result;
    float temp;
    if(CurrentArrivalTime+TimeOfService <= *NextArrivalTime)
        return 0;

    else if(CurrentArrivalTime+TimeOfService > *NextArrivalTime){
        temp = CurrentArrivalTime+TimeOfService;
        result = temp - *NextArrivalTime;
        *NextArrivalTime += result;
        return 1;                                                                                                                   /// 2
    }
}
//.....................................................................................................................................

float Header::avgWaitingTime(float* EachCustomerWaitingTime, short TotalCustoemrNubmer){
    float temp = 0;
    for (int i=0; i<TotalCustoemrNubmer; i++){
        temp += *(EachCustomerWaitingTime+i);
    }

    return temp / TotalCustoemrNubmer;                                                                                     /// 1
}
//.....................................................................................................................................

float Header::probWait(float CustomersNumberWhoWait, float TotalCustomers){
    return CustomersNumberWhoWait / TotalCustomers;                                                                         /// 2

}
//.....................................................................................................................................

float Header::ProbIdleServer(float *EachIdleServerTime, float totalSimulationRunTime){
    float temp = 0;
     for (int i=0; i<19; i++)
        temp += *(EachIdleServerTime+i);

     return temp / totalSimulationRunTime;                                                                                  /// 3
}
//......................................................................................................................................

float Header::probBeingBusy(float ProbIdleServer){
    return 1 - ProbIdleServer;                                                                                              /// 4
}
//......................................................................................................................................

float Header::avgTimeBetweenArrivals(float *EachTimeBetweenArrival, short NumberOfArrivals){
    float temp = 0;
    for (short i=0; i< NumberOfArrivals; i++)
        temp += *(EachTimeBetweenArrival + i);

    return temp / (NumberOfArrivals-1);                                                                                     /// 5
}
//......................................................................................................................................

float Header::avgServiceTime(float*EachServiceTime, short totalCustomerNubmer){
    float temp = 0;
    for (short i=0; i<=totalCustomerNubmer; i++)
        temp += *(EachServiceTime+i);

    return temp / totalCustomerNubmer;                                                                                      /// 6
}
//......................................................................................................................................

float Header::avgWaitingTimeOfThoseWhoWait(float* totalTimeOfCustomerWait, short CustomersNumberWhoWait){
    float temp = 0;
    for (short i=0; i<=19; i++)
        temp += *(totalTimeOfCustomerWait+i);

    return temp / CustomersNumberWhoWait;                                                                                    /// 8
}
//......................................................................................................................................

float Header::avgTimeCustomreSpendsInTheSystem(float* totalTimeCustoemrsSpendInSystem, short CustomersNumber){
    float temp = 0;
     for (short i=0; i<=19; i++)
        temp += *(totalTimeCustoemrsSpendInSystem+i);

    return temp / CustomersNumber;                                                                                          /// 9
}
//......................................................................................................................................

float Header::avgTimeCustomreSpendsInTheSystem2(float avgWaitingInQueue, float avgWaitingInService){
    return avgWaitingInQueue + avgWaitingInService;                                                                         /// 10
}
//......................................................................................................................................

void print (short* arr0, short arrLength0, float *arr1, float* arr2){
    float temp = 0;
    cout << "Customers\t" << "ArrivalTime\t" << "ServiceTime\t" << "\n";
    for (short i=0; i<arrLength0; i++){
        cout << arr0[i] << "\t\t";
        cout << *(arr1+i) << "\t\t";
        cout << *(arr2+i) << "\n";
        temp += *(arr2+i);
    }
    cout << "-------------------------------------------------";
    cout << "\nTotal\t\t\t\t" << temp;
    cout << "\n\n\n";
}
//......................................................................................................................................

void printResults(float* A1, short L1, float*A2, float* A3, float* A4, float* A5, float* A6){
    float temp1=0, temp2=0, temp3=0, temp4=0;

    cout << "WaitInQueue\t" << "ServiceBegin\t" << "ServiceEnd\t" << "ServiceIdleTime\t\t" << "InterArrivalTime\t" << "TimeSpendInSystem\n";
    for (short i=0; i<L1; i++){
        cout << "\t" << *(A1 +i) << "\t\t";
        cout << *(A2 +i) << "\t\t";
        cout << *(A3 +i) << "\t\t";
        cout << *(A4 +i) << "\t\t\t";
        cout << *(A5 +i) << "\t\t\t";
        cout << *(A6 +i) << "\n";
        temp1 += *(A1 +i);
        temp2 += *(A4 +i);
        temp3 += *(A5 +i);
        temp4 += *(A6 +i);
    }
    cout << "---------------------------------------------------------------------------------------------------------------";
    cout << "\nTotal\t" << temp1 << "\t\t\t\t\t\t" << temp2 << "\t\t\t" << temp3 << "\t\t\t" << temp4 ;
    cout << "\n\n\n";
}
//......................................................................................................................................

void printLawsResults(float A, float B, float C, float D, float E, float F, float G, float H, float I){
    cout << "Average Waiting Time For A Customer : " << A << "\n\n";
    cout << "Probability That A Customer Has To Wait In The Queue : " << B << "\n\n";
    cout << "Fraction Of Idle Time Of Server : " << C << "\n\n";
    cout << "probability Of Server Being Busy : " << D<< "\n\n";
    cout << "Average Time Between Arrivals : " << E << "\n\n";
    cout << "Average Service Time : " << F << "\n\n";
    cout << "Average Waiting Time Of Those Actually Wait In The Queue : " << G << "\n\n";
    cout << "Average Time A Customer Spends In The System : " << H << "\n\n";
    cout << "Average Time A Customer Spends In The System : " << I << "\n\n";
}
