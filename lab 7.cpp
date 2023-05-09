#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <string>
#include <iostream>
using namespace std;

class ChessPiece {

public:
	virtual bool isAttacking(string pos) = 0;
	virtual string getPosition() = 0;
};

class Horse : public ChessPiece {
private:
	string position;
public:
	Horse(string pos) : position(pos) {}
	bool isAttacking(string pos) override {
		int dx = abs(position[0] - pos[0]);
		int dy = abs(position[1] - pos[1]);
		return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
	}
	string getPosition() override { return position; }
};

class Elephant : public ChessPiece {
private:
	string position;
public:
	Elephant(string pos) : position(pos) {}
	bool isAttacking(string pos) override {
		int dx = abs(position[0] - pos[0]);
		int dy = abs(position[1] - pos[1]);
		return dx == dy;
	}
	string getPosition()override { return position; }
};

class Rook : public ChessPiece {
private:
	string position;
public:

	Rook(string pos) : position(pos) {}
	bool isAttacking(string pos) override {
		int dx = abs(position[0] - pos[0]);
		int dy = abs(position[1] - pos[1]);
		return dx == 0 || dy == 0;
	}
	string getPosition()override { return position; }
};

class Queen : public ChessPiece {
private:
	string position;
public:
	Queen(string pos) : position(pos) {}
	bool isAttacking(string pos) override {
		int dx = abs(position[0] - pos[0]);
		int dy = abs(position[1] - pos[1]);
		return dx == dy || dx == 0 || dy == 0;
	}
	string getPosition() override { return position; }
};

void checkForCheck(ChessPiece* piece, string kingPos) {
	if (piece->isAttacking(kingPos)) {
		cout << "Шах!\n";
	}
	else {
		cout << "Не шах.\n";
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string kingPos = "a2";
	ChessPiece* pieces[] = { new Horse("g2"), new Elephant("c5"), new Rook("a1"), new Queen("d1") };
	for (int i = 0; i < 4; i++) {
		cout << "Checking piece at position " << pieces[i]->getPosition() << ": ";
		checkForCheck(pieces[i], kingPos);
	}
	return 0;
}