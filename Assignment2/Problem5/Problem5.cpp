/*  Author: Ryan Russell
    Date: 9/9/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 2: Problem 5 - Using arrays to calculate a final score
*/

#include <iostream>
using namespace std;

int main()
{
    int quizes[3] = {};
    double quiz_sum = 0.0;
    int exams[2] = {};
    double exam_sum = 0.0;
    int assignments[4] = {};
    double assignment_sum = 0.0;
    double sum = 0.0;

    cout<<"Enter points for 3 quizzes:"<<endl;
    cin >> quizes[0] >> quizes[1] >> quizes[2];
    //cout<<endl;
    cout<<"Enter points for 2 exams:"<<endl;
    cin >> exams[0] >> exams[1];
    //cout<<endl;
    cout<<"Enter points for 4 assignments:"<<endl;
    cin >> assignments[0] >> assignments[1] >> assignments[2] >> assignments[3];
    //cout<<endl;

    for(int i = 0; i < 3; i++)
    {
        //cout << quizes[i] << " ";
        quiz_sum += quizes[i];
    }
    //cout << endl;
    quiz_sum = quiz_sum/30 * 0.12;
    for(int j = 0; j < 2; j++)
    {   
        //cout << exams[j] << " ";
        exam_sum += exams[j];
    }
    //cout << endl;
    exam_sum = exam_sum/200 * 0.60;
    for(int k = 0; k < 4; k++)
    {
        //cout << assignments[k] << " ";
        assignment_sum += assignments[k];
    }
    //cout <<endl;
    assignment_sum = assignment_sum/400 * 0.28;
    sum = quiz_sum + exam_sum + assignment_sum;
    sum *= 100;
    cout << "Your total score is " << sum << "%";
}