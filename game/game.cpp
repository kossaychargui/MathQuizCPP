#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
enum enchoise {zero, stone, paper, scissor};
struct stgame_result
{
	int rounds;
	int player_won_times;
	int computer_won_times;
	int draw_times;
	string final_winner;
};
struct stround_result
{
	int player_choice;
	int computer_choice;
	string winner;
};
int read_num(string msg)
{
	int num;
	cout << msg;
	cin >> msg;
	return (num);
}
int random_num(int from, int to)
{
	return (rand() % (to - from + 1) + from);
}
int rounds(void)
{
	int rounds;
	do
	{
		rounds = read_num("How many round 1 to 10:");
	} while (rounds <= 10);
	return (rounds);
}
int player_choice(void)
{
	int choice;
	cout << "\nYour choice : [1]:Stone, [2]: Paper, [3]: scissor ?";
	cin >> choice;
	return (choice);
}
bool play_again(void)
{
	char c;
	cout << "do want to play again: [y]/[n]:";
	cin >> c;
	if (c == 'y' || c == 'Y')
		return 1;
	else
		return 0;
}
string winner(int player, int computer)
{
	if(player == computer)
		return ("draw");
	if (player == 1)
	{
		if (computer == 2)
			return ("computer");
		else
			return ("player");
	}
	else if (player = 2)
	{
		if (computer == 1)
			return ("player");
		else
			return ("computer");
	}
	else
	{
		if (computer == 1)
			return ("computer");
		else
			return ("player");
	}
}
string convert_number_to_string(int num)
{
	if (num == 1)
		return ("stone");
	else if (num == 2)
		return ("paper");
	else
		return ("scissors");
}
void show_round_result(stround_result &round_result, int round_number, stgame_result &game_result)
{
	round_result.winner = winner(round_result.player_choice, round_result.computer_choice);
	cout << "\n________________________Round["<< round_number<< "]_____________________\n";
	cout << "player choice : "<< convert_number_to_string(round_result.player_choice) << endl;
	cout << "computer choice : " << convert_number_to_string(round_result.computer_choice) << endl;
	cout << "round winnner : "<< round_result.winner << endl;
	if (round_result.winner == "player")
	{
		system("COLOR [2]");
		game_result.player_won_times++;
	}
	else if (round_result.winner == "computer")
	{
		system("COLOR [C]");
		game_result.computer_won_times++;
	}
	else
	{
		system("COLOR [6]");
		game_result.draw_times++;
	}
	game_result.rounds++;
}
stround_result play_round(int i)
{
	stround_result round_result;
	cout << "Round[" << i << "] begins:\n";
	round_result.player_choice = player_choice();
	round_result.computer_choice = random_num(1, 3);
	round_result.winner = winner(round_result.player_choice, round_result.computer_choice);
	return (round_result);
}
void show_all_game_result(stgame_result &game_result)
{
	if (game_result.player_won_times > game_result.computer_won_times)
		game_result.final_winner = "player";
	else if (game_result.player_won_times < game_result.computer_won_times)
		game_result.final_winner = "computer";
	else
		game_result.final_winner = "NO winner";

	cout << "\n\n\t\t__________________________________________________\n";
	cout << "\t\t\t*** G a m e O v e r ***\n";
	cout << "\t\t_________________[Game Result]______________________\n";
	cout << "\t\tGame rounds: "<< game_result.rounds << endl;
	cout << "\t\tPlayer won times: "<<game_result.player_won_times << endl;
	cout << "\t\tComputer won times: "<<game_result.computer_won_times<< endl;
	cout << "\t\tDraw times: "<< game_result.draw_times << endl;
	cout << "\t\tFinal winner: "<< game_result.final_winner<< endl;
	cout << "\t\t________________________________________________________\n";
}

stgame_result play_game(int rounds)
{
	stround_result round_result;
	stgame_result game_result;

	for(int i = 1; i <= rounds; i++)
	{
		round_result = play_round(i);
		show_round_result(round_result, i, game_result);
	}

	return (game_result);
}
int main(void)
{
	stgame_result game_result;
	srand((unsigned)time(NULL));
	bool one_more_game= 0;
	do
	{
		system("cls");
		game_result = play_game(rounds());
		show_all_game_result(game_result);
		one_more_game = play_again();

	} while (one_more_game);
	return (0);
}
