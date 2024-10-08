#include <cmath>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

enum enDifficultyQuestions{Easy=1,Normal=2,Hard=3,Mixe=4};
enum enOperation{Add=1,Sustra=2,Multi=3,Divi=4,Mix=5};

struct stQuestion {

    short int NumberOfQuestion;
    float FirstNumber;
    float SecondNumber;
    float AnswerOfQuestion;
    enDifficultyQuestions DifficultyQuestions;
    enOperation Operation;
    char operation;
    short int TrueAnswer;
    short int FalseAnswer;
};

void Numbers(stQuestion& Question , int first , int final) {
    Question.FirstNumber = first + rand() % (final - first + 1);
    Question.SecondNumber = first + rand() % (final - first + 1);
    int k = 0;
    while (k < 1) {
        if (Question.FirstNumber >= Question.SecondNumber) {
            break;
        }
        else{ Numbers(Question, first, final); }
    }
    if(Question.operation == '+'){
        Question.AnswerOfQuestion = Question.FirstNumber + Question.SecondNumber;
    }
    if (Question.operation == '-') {
        Question.AnswerOfQuestion = Question.FirstNumber - Question.SecondNumber;
    }
    if (Question.operation == '*') {
        Question.AnswerOfQuestion = Question.FirstNumber * Question.SecondNumber;
    }
    if (Question.operation == '/') {
        Question.AnswerOfQuestion = Question.FirstNumber / Question.SecondNumber;
    }

}
void operation(stQuestion& Question  , char operatione , int first , int final) {
    
        srand(time(0));
        float AnswerOfTheQuestion;
        Question.operation = operatione;
        Numbers(Question, first, final);
        cout << "\t\t" << Question.FirstNumber << endl;
        cout << "\t" << Question.operation << endl;
        cout << "\t\t" << Question.SecondNumber << endl;
        cout << "\t-------------" << endl << "\t\t";
        cin >> AnswerOfTheQuestion;
        cout << endl;

        if (AnswerOfTheQuestion == Question.AnswerOfQuestion) {
            cout << "\t\tThe answer is true \n\n\n";
            system("color 2F");
            Question.TrueAnswer++;
        }
        else {
            cout << "\t\tThe answer is false \n\n\n\a";
            system("color 4F");
            Question.FalseAnswer++;

        }
    
}
void mixOperation(stQuestion& Question, int first, int final) {
        srand(time(0));
        short int NumberOfOperatoion;
        int j = 0;
        while (j < 1) {
            NumberOfOperatoion = 42 + rand() % (47 - 42 + 1);
            if (NumberOfOperatoion != 44 && NumberOfOperatoion != 46) {
                break;
            }
        }
        char operatione = char(NumberOfOperatoion);
        float AnswerOfTheQuestion;
        Question.operation = operatione;
        Numbers(Question, first, final);
        cout << "\t\t" << Question.FirstNumber << endl;
        cout << "\t" << Question.operation << endl;
        cout << "\t\t" << Question.SecondNumber << endl;
        cout << "\t-------------" << endl << "\t\t";
        cin >> AnswerOfTheQuestion;
        cout << endl;

        if (AnswerOfTheQuestion == Question.AnswerOfQuestion) {
            cout << "\t\tThe answer is true \n\n\n";
            system("color 2F");
            Question.TrueAnswer++;
        }
        else {
            cout << "\t\tThe answer is false \n\n\n\a";
            system("color 4F");
            Question.FalseAnswer++;

        }
    
}
void difficulter(stQuestion& Question , int first , int final) {
    char operatione;
    if (Question.Operation == enOperation::Add) {
        operatione = '+';
        operation(Question, operatione, first, final);
    }
    else if (Question.Operation == enOperation::Sustra) {
        operatione = '-';
        operation(Question, operatione, first, final);
    }
    else if (Question.Operation == enOperation::Multi) {
        operatione = '*';
        operation(Question, operatione, first, final);
    }
    else if (Question.Operation == enOperation::Divi) {
        operatione = '/';
        operation(Question, operatione, first, final);
    }
    else if (Question.Operation == enOperation::Mix) {
        mixOperation(Question, first, final);
    }

}

int main()
{
    stQuestion Question;
    short int Difficulty;
    short int Operations;
 
    Question.TrueAnswer = 0;
    Question.FalseAnswer = 0;
    cout << "How many Question do you want ?  ";
    cin >> Question.NumberOfQuestion;

    cout << "\n\tEasy[1]\t\tNormal[2]\tHard[3]\t\tMix[4]\t\t:  ";
    cin >> Difficulty;
    cout << "\n\n";

    cout << "\tAddition[1]\t\tSustraction[2]\t\tMultiplication[3]\t\tDivision[4]\t\tMix[5]\t\t:  ";
    cin >> Operations;
    cout << "\n\n";

    Question.DifficultyQuestions = static_cast<enDifficultyQuestions>(Difficulty);
    Question.Operation = static_cast<enOperation>(Operations);

    if (Question.DifficultyQuestions == enDifficultyQuestions::Easy) {
        for(int i = 0 ; i < Question.NumberOfQuestion ; i++)
        {
            difficulter(Question, 1, 10);
        }
    }

    if (Question.DifficultyQuestions == enDifficultyQuestions::Normal) {
        for (int i = 0; i < Question.NumberOfQuestion; i++)
        {
            difficulter(Question, 1, 10);
        }
    }

    if (Question.DifficultyQuestions == enDifficultyQuestions::Hard) {
        for (int i = 0; i < Question.NumberOfQuestion; i++)
        {
            difficulter(Question, 1, 10);
        }
    }

    if (Question.DifficultyQuestions == enDifficultyQuestions::Mixe) {
        int k;
        for (int i = 0; i < Question.NumberOfQuestion; i++)
        {
            k = 1 + rand() % 3;
            Question.DifficultyQuestions = (enDifficultyQuestions)k;
            if (Question.DifficultyQuestions == enDifficultyQuestions:: Easy) {
                difficulter(Question, 1, 10);
            }
            if (Question.DifficultyQuestions == enDifficultyQuestions::Normal) {
                difficulter(Question, 10, 100);
            }
            if (Question.DifficultyQuestions == enDifficultyQuestions::Hard) {
                difficulter(Question, 100, 1000);
            }
            
        }
    }

    cout << "\n\n\n\n\t\t\t============================================\n\n\t\t\t\t\tGAME OVER\t\t\t\t\t\n\n\t\t\t============================================\n\n";
    float result = ((float)Question.TrueAnswer / (float)Question.NumberOfQuestion)*100;
    cout << "\t\t\t\tYour note is : " << result << '%'<< endl<<endl;
    cout << "\t\t\t\tNumber of True Answer is : " << Question.TrueAnswer   << endl << endl;
    cout << "\t\t\t\tNumber of False Answer is : " << Question.FalseAnswer << endl << endl;
    if (Question.TrueAnswer >= Question.FalseAnswer) {
        cout << "\t\t\t\tYou\'re successful\n";
    }
    else{ cout << "\t\t\t\tYou\'re Loser\n"; }
    cout << endl << endl;
    system("pause");
    return 0;
}