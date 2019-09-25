#include "pch.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int sd[10][10], op = 0;

void clear(int step);
void input(int step);
void output(int step);
int search0(int step);
int build(int step, int i, int j);
int check(int step, int i, int j, int x);

int main(int argc, char *argv[])
{
	int step = atoi(argv[2]), repeat = atoi(argv[4]);
	FILE *stream1, *stream2;
	freopen_s(&stream1,argv[6], "r", stdin);
	freopen_s(&stream2,argv[8], "w", stdout);
	while (repeat--)
	{
		op = 0;
		clear(step);
		input(step);
		build(step, 0, 0);
		if (search0(step) == -1)
			cout << "error:no answer" << endl << endl;
		else
			output(step);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

void clear(int step)
{
	int i, j;
	for (i = 0; i < step; i++)
		for (j = 0; j < step; j++)
			sd[i][j] = 0;
}

void input(int step)
{
	int i, j;
	for (i = 0; i < step; i++)
		for (j = 0; j < step; j++)
			cin >> sd[i][j];
}

void output(int step)
{
	int i, j;
	for (i = 0; i < step; i++)
	{
		for (j = 0; j < step; j++)
		{
			cout << sd[i][j];
			if (j < step - 1)
				cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int build(int step, int i, int j)
{
	int x;
	if (i > step - 1)
	{
		op = 1;
		return 0;
	}
	else if (sd[i][j] > 0)
	{
		if (j < step - 1)
			build(step, i, j + 1);
		else
			build(step, i + 1, 0);
	}
	else
	{
		for (x = 1; x <= step; x++)
		{
			if (check(step, i, j, x) == 1)
			{
				sd[i][j] = x;
				if (j < step - 1)
					build(step, i, j + 1);
				else
					build(step, i + 1, 0);
				if (op == 1)
					return 0;
				sd[i][j] = 0;
			}
		}
	}
	return 0;
}

int check(int step, int i, int j, int x)
{
	int k, r, c, l;
	for (k = 0; k < step; k++)
	{
		if (sd[i][k] == x || sd[k][j] == x)
			return 0;
	}
	if (step == 4)
	{
		r = i / 2;
		c = j / 2;
		for (k = r * 2; k < r * 2 + 2; k++)
		{
			for (l = c * 2; l < c * 2 + 2; l++)
				if (sd[k][l] == x)
					return 0;
		}
	}
	else if (step == 9)
	{
		r = i / 3;
		c = j / 3;
		for (k = r * 3; k < r * 3 + 3; k++)
		{
			for (l = c * 3; l < c * 3 + 3; l++)
				if (sd[k][l] == x)
					return 0;
		}
	}
	else if (step == 6)
	{
		r = i / 2;
		c = j / 3;
		for (k = r * 2; k < r * 2 + 2; k++)
		{
			for (l = c * 3; l < c * 3 + 3; l++)
				if (sd[k][l] == x)
					return 0;
		}
	}
	else if (step == 8)
	{
		r = i / 4;
		c = j / 2;
		for (k = r * 4; k < r * 4 + 4; k++)
		{
			for (l = c * 2; l < c * 2 + 2; l++)
				if (sd[k][l] == x)
					return 0;
		}
	}
	return 1;
}

int search0(int step)
{
	int i, j;
	for (i = 0; i < step; i++)
	{
		for (j = 0; j < step; j++)
			if (sd[i][j] == 0)
				return -1;
	}
	return 0;
}