#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

/*
   Developer : Jnaneshwar B.Tatuskar
*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class BowlingGame {
private:
    vector<int> rolls;

public:
    void roll(int pins) {
        rolls.push_back(pins);
    }

    int score() {
        int totalScore = 0;
        int rollIndex = 0;

        for (int frame = 0; frame < 10; ++frame) {
            if (isStrike(rollIndex)) {
                totalScore += 10 + strikeBonus(rollIndex);
                rollIndex += 1;
            }
            else if (isSpare(rollIndex)) {
                totalScore += 10 + spareBonus(rollIndex);
                rollIndex += 2;
            }
            else {
                totalScore += rolls[rollIndex] + rolls[rollIndex + 1];
                rollIndex += 2;
            }
        }

        return totalScore;
    }

    void printFrameScores() {
        int rollIndex = 0;
        int runningScore = 0;

        cout << "\nFrame-wise Score:\n";
        cout << "+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+\n";
        cout << "| Frame  ";
        for (int f = 1; f <= 10; ++f) cout << "|   " << setw(2) << f << "   ";
        cout << "|\n";
        cout << "+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+\n";
        cout << "| Score  ";

        for (int frame = 0; frame < 10; ++frame) {
            int frameScore = 0;

            if (frame == 9) {  // Special handling for 10th frame
                int r1 = rolls[rollIndex];
                int r2 = rolls[rollIndex + 1];
                int r3 = (rollIndex + 2 < rolls.size()) ? rolls[rollIndex + 2] : 0;
                frameScore = r1 + r2 + r3;
                runningScore += frameScore;
                rollIndex += (r1 == 10 || r1 + r2 == 10) ? 3 : 2;
            }
            else if (isStrike(rollIndex)) {
                frameScore = 10 + strikeBonus(rollIndex);
                rollIndex += 1;
                runningScore += frameScore;
            }
            else if (isSpare(rollIndex)) {
                frameScore = 10 + spareBonus(rollIndex);
                rollIndex += 2;
                runningScore += frameScore;
            }
            else {
                frameScore = rolls[rollIndex] + rolls[rollIndex + 1];
                rollIndex += 2;
                runningScore += frameScore;
            }

            cout << "|  " << setw(4) << runningScore << " ";
        }

        cout << "|\n";
        cout << "+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+\n";
    }

private:
    bool isStrike(int index) {
        return index < rolls.size() && rolls[index] == 10;
    }

    bool isSpare(int index) {
        return index + 1 < rolls.size() && rolls[index] + rolls[index + 1] == 10;
    }

    int strikeBonus(int index) {
        return rolls[index + 1] + rolls[index + 2];
    }

    int spareBonus(int index) {
        return rolls[index + 2];
    }
};

int getValidRoll(string prompt, int maxPins) {
    int pins;
    do {
        cout << prompt << " (0 to " << maxPins << "): ";
        cin >> pins;
        if (pins < 0 || pins > maxPins) {
            cout << "  Invalid! Please enter between 0 and " << maxPins << "." << endl;
        }
    } while (pins < 0 || pins > maxPins);
    return pins;
}

int main() {
    BowlingGame game;

    for (int frame = 1; frame <= 10; ++frame) {
        cout << "\nFrame " << frame << ":" << endl;

        int firstRoll = getValidRoll("  Enter first roll", 10);
        game.roll(firstRoll);

        int secondRoll = 0;
        if (frame < 10) {
            if (firstRoll == 10) {
                cout << "  Strike!" << endl;
                continue;
            }

            secondRoll = getValidRoll("  Enter second roll", 10 - firstRoll);
            game.roll(secondRoll);
        }
        else {
            // 10th frame
            int maxSecond = (firstRoll == 10) ? 10 : 10 - firstRoll;
            secondRoll = getValidRoll("  Enter second roll", maxSecond);
            game.roll(secondRoll);

            // Bonus third roll if strike or spare
            if (firstRoll == 10 || (firstRoll + secondRoll) == 10) {
                int thirdRoll = getValidRoll("  Enter third roll", 10);
                game.roll(thirdRoll);
            }
        }
    }

    cout << "\nTotal score: " << game.score() << endl;
    game.printFrameScores();

    return 0;
}
