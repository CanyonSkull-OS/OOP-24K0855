#include <iostream>
using namespace std;


class FitnessTracker{
    string userName;
    int dailyStepGoal;
    int stepsTaken = 0;
    int caloriesBurned = 0;


    public:
        void logSteps(int steps){
            stepsTaken += steps;
            cout << "Steps updated" << endl;
        }

        int calculateCalories(){
            caloriesBurned += stepsTaken*0.013;
            return caloriesBurned;
        }

        void displayProgress(){
            cout << "\t\t Progress \t\t" << endl;
            cout << "Steps taken: " << stepsTaken << endl;
            cout << "Calories Burned: " << caloriesBurned << endl;
        }


};

int main(){
    int steps;
    int goal;
    cout << "What is your goal for today (Calories): ";
    cin >> goal;
    FitnessTracker tracker1;
    cout << "How many steps did you take?" << endl;
    cin >> steps;
    tracker1.logSteps(steps);

    int caloriesBurned = tracker1.calculateCalories();
    if (caloriesBurned > goal){
        cout << "You reached your goal for the day" << endl;
    }
    else{
        cout << "You're such a loser, you should kill yourself at this point" << endl;
    }

    tracker1.displayProgress();

    return 0;
}