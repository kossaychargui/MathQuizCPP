#include <iostream>
#include <cstdlib>
using namespace std;
enum enqlevel {easy = 1,med = 2, hard = 3, mix = 4 };
enum enopteype {add = 1, sub = 2, mul = 3, divv = 4, Mixx = 5};
struct stquiz
{
    int first_operand = 0;
    int secnod_operand  = 0;
    char op = '\0';
    int result = 0;
    bool correct = 0;
};
struct stanswers
{
    int q_number = 0;
    string q_level = "";
    string q_type = "";
    int right_answers = 0;
    int wrong_answers = 0;
};
int random_number(int from, int to)
{
    return (rand() % (to - from + 1) + from);
}
int q_number(void)
{
    int q_number;
    cout << "How many question do you want to answer? :";
    cin >> q_number;
    return (q_number);
}
int q_level(void)
{
    int q_level;
    do
    {
    cout << "Enter questions level : [1] Easy, [2] Med, [3] Hard, [4] Mix ?";
    cin >> q_level;
    } while (q_level < 1 || q_level > 4);
    return (q_level);
}
int op_type(void)
{
    int op_type;
    do
    {
        cout << "Enter operation type : [1] Add, [2] Sub, [3] Mul, [4] div, [5] Mix ?";
        cin >> op_type;
    } while (op_type < 1 || op_type > 5);
    return (op_type);
}
bool play_again(void)
{
    char c;
    cout << "do you want to play again? Y/N?";
    cin >> c;
    return (c == 'Y' || c == 'y');
}
void clear_console(void)
{
    system("cls");
    system("color 0F");
}
void evaluate(stquiz& quiz, int q_level, int op_type, stanswers &answers)
{
    string ops;
    ops = { '+', '-', '*', '/' };
    char op;
    switch (q_level)
    {
        case enqlevel::easy:
            quiz.first_operand = random_number(1, 10);
            quiz.secnod_operand = random_number(1, 10);
            answers.q_level = "easy";
            break;
        case enqlevel::med:
            quiz.first_operand = random_number(10, 30);
            quiz.secnod_operand = random_number(10, 30);
            answers.q_level = "med";
            break;
        case enqlevel::hard:
            quiz.first_operand = random_number(30, 100);
            quiz.secnod_operand = random_number(30, 100);
            answers.q_level = "hard";
            break;
        case enqlevel::mix:
            quiz.first_operand = random_number(1, 100);
            quiz.secnod_operand = random_number(1, 100);
            answers.q_level = "mix";
            break;
    }
    switch (op_type)
    {
    case enopteype::add:
        quiz.result = quiz.first_operand + quiz.secnod_operand;
        quiz.op = '+';
        answers.q_type = "add";
        break;
    case enopteype::sub:
        quiz.result = quiz.first_operand - quiz.secnod_operand;
        quiz.op = '-';
        answers.q_type = "sub";
        break;
    case enopteype::mul:
        quiz.result = quiz.first_operand * quiz.secnod_operand;
        quiz.op = '*';
        answers.q_type = "mul";
        break;
    case enopteype::divv:
        quiz.result = quiz.first_operand / quiz.secnod_operand;
        quiz.op = '/';
        answers.q_type = "div";
        break;
    case enopteype::Mixx:
        answers.q_type = "mix";
        switch (random_number(1, 4))
        {
            case 1:
                quiz.result = quiz.first_operand + quiz.secnod_operand;
                quiz.op = '+';
                break;
            case 2:
                quiz.result = quiz.first_operand - quiz.secnod_operand;
                quiz.op = '-';
                break;
            case 3:
                quiz.result = quiz.first_operand * quiz.secnod_operand;
                quiz.op = '*';
                break;
            case 4:
                quiz.result = quiz.first_operand / quiz.secnod_operand;
                quiz.op = '/';
                break;
        }
    }
}
void one_quiz(int count, int q_number, int q_level, int op_type, stanswers &answers)
{
    int player_answer;
    stquiz quiz;
    evaluate(quiz, q_level, op_type, answers);
    cout << "Question [" << count << '/' << q_number << "]\n";
    cout << quiz.first_operand << endl;
    cout << quiz.secnod_operand << ' ' << quiz.op << endl;
    cout << "_________\n";
    cin >> player_answer;
    if (player_answer == quiz.result)
    {
        system("color 02");
        cout << "\nRight answer :-)\n";
        answers.right_answers++;
    }
    else
    {
        system("color 04");
        cout << "\a";
        cout << "\nWrong answer! :-(\n";
        cout << "The right answer is: " << quiz.result;
        cout << endl;
        answers.wrong_answers++;
    }
}
stanswers play_game(int q_number, int q_level, int op_type)
{
    stanswers answers;
    for (int i = 1; i <= q_number; i++)
    {
        one_quiz(i, q_number, q_level, op_type, answers);
    }
    answers.q_number = q_number;
    return (answers);
}
void show_result(stanswers answers)
{
    if (answers.wrong_answers > answers.right_answers)
    {
        system("color 40");
        cout << "\n______________________________\n";
        cout << " Final result is Fail :-(";
        cout << "\n______________________________\n";
    }
    else
    {
        system("color 20");
        cout << "\n______________________________\n";
        cout << " Final result is Pass :-)";
        cout << "\n______________________________\n";
    }
    cout << "Number of questions : " << answers.q_number << endl;
    cout << "Question level is : " << answers.q_level << endl;
    cout << "Op type is : " << answers.q_type << endl;
    cout << "Number of right answers is : " << answers.right_answers << endl;
    cout << "Number of wrong answers is : " << answers.wrong_answers << endl;
 }
int main(void)
{
    srand((unsigned)time(NULL));
    stanswers final_result;
    bool another_game;
    int qnumber = q_number();
    int qlevel = q_level();
    int operation_type = op_type();
    do
    {
        clear_console();
        final_result = play_game(qnumber, qlevel, operation_type);
        show_result(final_result);
        another_game = play_again();

    } while (another_game);
    return (0);
}
