//Omer Shahid
//24K-0855
#include <iostream>
using namespace std;

//Task 1
void calculateAQI(int AQIarr[][7]){
    int sum = 0;
    float max_avg = 0;
    int worst_AQI;
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter Data for City " << i+1 << ": " << endl;
        for (int j = 0; j < 7; j++)
        {
            cout << "Day " << j+1 << ": ";
            cin >> AQIarr[i][j];
            sum += AQIarr[i][j];
        }
        float avg = (float)sum/7;
        sum = 0;
        cout << endl << "Average of City " << i+1 << ": " << avg << endl;
        if (avg > max_avg){
            max_avg = avg;
            worst_AQI = i+1;
        }
    }
    cout << endl << "Worst AQI City: " << worst_AQI << endl;
}

//Task 2
void displayCritPoll(int AQIarr[][7]){
    for (int i = 0; i < 4; i++)
    {
        cout << endl << "City " << i+1 << ": " << endl;
        for (int j = 0; j < 7; j++)
        {
            if (AQIarr[i][j] > 150){
                cout << "Day " << j+1 << ": " << AQIarr[i][j] << endl;
            }
        }
    }
}


//Task 3
void DataVisualization(int AQIarr[][7]){
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        cout << endl << "City " << i+1 << ": " << endl;
        for (int j = 0; j < 7; j++)
        {
            cout << "Day " << j+1 << ": ";
            while (sum < AQIarr[i][j])
            {
                cout << "*";
                sum += 50;
            }
            cout << endl;
            sum = 0;
        }
    }
}


//Task 4
void calculateMonthlyAQI(int AQIarr2[][4][7]){
    int sum[4] = {0};
    float monthAvg = 0;
    float avg[4] = {0};
    float diff[4] = {0};
    float maxDiff = 0;
    int improvedCity = 0;
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter Data for City " << i+1 << ": " << endl;
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 7; k++){
                cout << "Day " << k+1 << ": ";
                cin >> AQIarr2[i][j][k];
                sum[j] += AQIarr2[i][j][k];
            }
            avg[j] = (float)sum[j]/7;
            sum[j] = 0;
        }
        monthAvg = (avg[0]+avg[1]+avg[2]+avg[3])/4;
        cout << "Monthly average for City " << i+1 << ": " <<
        monthAvg << endl;
        diff[i] = avg[3] - avg[0];
        if (diff[i] > maxDiff){
            maxDiff = diff[i];
            improvedCity = i+1;
        }
    }
    cout << "Most Improved City: " << improvedCity << endl;
}


//Task 5
void generateReport(int AQIarr2[][4][7]) {
    float weeklyAvg[4][4] = {0};
    int maxAQI = 0, minAQI = 9999;
    int criticalDays[4][4][7] = {0};

    cout << endl << "\t===== Monthly Air Quality Report =====\t" << endl;

    for (int city = 0; city < 4; city++) {
        cout << endl << "City " << city + 1 << " Data:" << endl;
        for (int week = 0; week < 4; week++) {
            int sum = 0;
            for (int day = 0; day < 7; day++) {
                int AQI = AQIarr2[city][week][day];
                sum += AQI;

                if (AQI > 150) {
                    criticalDays[city][week][day] = 1; 
                }

                if (AQI > maxAQI) maxAQI = AQI;
                if (AQI < minAQI) minAQI = AQI;
            }
            weeklyAvg[city][week] = (float)sum / 7;
            cout << "  Week " << week + 1 << " Average: " << weeklyAvg[city][week] << endl;
        }
    }

    cout << "\nCritical Pollution Days (AQI > 150):\n";
    for (int city = 0; city < 4; city++) {
        cout << "City " << city + 1 << ":\n";
        for (int week = 0; week < 4; week++) {
            for (int day = 0; day < 7; day++) {
                if (criticalDays[city][week][day] == 1) {
                    cout << "  Week " << week + 1 << " Day " << day + 1
                         << ": AQI " << AQIarr2[city][week][day] << endl;
                }
            }
        }
    }

    cout << endl << "Overall AQI Statistics:" << endl;
    cout << "  Highest AQI Recorded: " << maxAQI << endl;
    cout << "  Lowest AQI Recorded: " << minAQI << endl;
}




//Main
int main(){
    int AQIarr[4][7];
    int AQIarr2[4][4][7];
//    calculateAQI(AQIarr);
//    displayCritPoll(AQIarr);
//    DataVisualization(AQIarr);
    calculateMonthlyAQI(AQIarr2);
    generateReport(AQIarr2);
    return 0;
}