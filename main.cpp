#include <iostream>
#include <iomanip>   // Required for setw and setfill
#include <string>    // Not strictly needed, but kept for completeness
using namespace std;

class TimeConverter {
public:
    static void secondsToHMS(int totalSeconds, int &hours, int &minutes, int &seconds) {
        hours = totalSeconds / 3600;
        int remainder = totalSeconds % 3600;
        minutes = remainder / 60;
        seconds = remainder % 60;
    }
    
    static int hmsToSeconds(int hours, int minutes, int seconds) {
        return hours * 3600 + minutes * 60 + seconds;
    }

    static void displayHMS(int hours, int minutes, int seconds) {
        cout << hours << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds;
    }
};

int main() {
    int choice;

    do {
        cout << "1. Convert seconds to HH:MM:SS\n";
        cout << "2. Convert HH:MM:SS to seconds\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int totalSeconds;
                cout << "Enter total seconds: ";
                cin >> totalSeconds;

                if (totalSeconds < 0) {
                    cout << "Error: Seconds cannot be negative.\n";
                    break;
                }

                int hours, minutes, seconds;
                TimeConverter::secondsToHMS(totalSeconds, hours, minutes, seconds);

                cout << "HH:MM:SS => ";
                TimeConverter::displayHMS(hours, minutes, seconds);
                cout << endl;
                break;
            }

            case 2: {
                int hours, minutes, seconds;
                cout << "Enter hours: ";
                cin >> hours;
                cout << "Enter minutes: ";
                cin >> minutes;
                cout << "Enter seconds: ";
                cin >> seconds;

                if (minutes < 0 || minutes >= 60 || seconds < 0 || seconds >= 60 || hours < 0) {
                    cout << "Error: Invalid time values. Hours >= 0, minutes/seconds must be 0..59.\n";
                    break;
                }

                int totalSeconds = TimeConverter::hmsToSeconds(hours, minutes, seconds);
                cout << "Total seconds: " << totalSeconds << endl;
                break;
            }

            case 3:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    } while (choice != 3);

    return 0;
}