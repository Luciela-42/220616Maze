#include <iostream>
#include <stack>
#include <conio.h>
#define VISITED 2
#define BACKTRACE 3
using namespace std;

//Right, Down, Left, Up
int MAP[10][10] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 1, 0, 1, 1, 1},
	{1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
	{1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
	{1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

class Vector
{
public:
	int X;
	int Y;
};

int main()
{
	stack<Vector> History;
	Vector PlayerPosition;

	PlayerPosition.X = 1;
	PlayerPosition.Y = 1;

	History.push(PlayerPosition);
	MAP[PlayerPosition.Y][PlayerPosition.X] = VISITED;
	while (true)
	{
		
		//���� ����
		if (PlayerPosition.X == 8 && PlayerPosition.Y == 8)
		{
			for (int Y = 0; Y < 10; ++Y)
			{
				for (int X = 0; X < 10; ++X)
				{
					cout << MAP[Y][X] << " ";
				}
				cout << endl;
			}
			break;
		}

		//�����ʿ� ���� �ֳ�?
		if (MAP[PlayerPosition.Y][PlayerPosition.X + 1] == 0)
		{
			PlayerPosition.X++;
			History.push(PlayerPosition);
			MAP[PlayerPosition.Y][PlayerPosition.X] = VISITED;
		}
		//�Ʒ��ʿ� ���� �ֳ�?
		else if (MAP[PlayerPosition.Y + 1][PlayerPosition.X] == 0)
		{
			PlayerPosition.Y++;
			History.push(PlayerPosition);
			MAP[PlayerPosition.Y][PlayerPosition.X] = VISITED;
		}
		//���ʿ� ���� �ֳ�?
		else if (MAP[PlayerPosition.Y][PlayerPosition.X - 1] == 0)
		{
			PlayerPosition.X--;
			History.push(PlayerPosition);
			MAP[PlayerPosition.Y][PlayerPosition.X] = VISITED;
		}
		//���ʿ� ���� �ֳ�?
		else if (MAP[PlayerPosition.Y - 1][PlayerPosition.X] == 0)
		{
			PlayerPosition.Y--;
			History.push(PlayerPosition);
			MAP[PlayerPosition.Y][PlayerPosition.X] = VISITED;
		}
		else
		{
			//���ư� ���� ���ٸ� Ż�� �Ұ�
			if (History.empty())
			{
				cout << "Can't Escape!" << endl;
				break;
			}
			//���ο� ���� ���ٸ� ���ư���
			PlayerPosition.X = History.top().X;
			PlayerPosition.Y = History.top().Y;
			History.pop();
		}
		//cout << PlayerPosition.X << "," << PlayerPosition.Y << endl;

		for (int Y = 0; Y < 10; ++Y)
		{
			for (int X = 0; X < 10; ++X)
			{
				cout << MAP[Y][X] << " ";
			}
			cout << endl;
		}

		_getch();
	}
	return 0;
}