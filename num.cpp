#include <iostream>      
#include <sstream>       // For processing strings (stringstream)
#include <unordered_map> 
#include <vector>
#include <cctype>        // For character checks like isalpha, tolower
using namespace std;

// Arrays for number words
string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

// Converts a number under 1000 into words
string chunkToWords(int num) {
    string result = "";

    if (num >= 100) {
        result += ones[num / 100] + string(" hundred ");
        num %= 100;
    }

    if (num >= 20) {
        result += tens[num / 10] + string(" ");
        num %= 10;
    } else if (num >= 10) {
        result += teens[num - 10] + string(" ");
        num = 0;
    }

    if (num > 0) {
        result += ones[num] + string(" ");
    }

    return result;
}



// Converts a full number (like 1234567) into words
string numberToWords(int n) {
    if (n == 0) return "zero"; // just in case that user was that dumb to input 0

    string result = "";
    // Process the number in chunks of 3 digits 

    if (n >= 1000000) {
        result += chunkToWords(n / 1000000);
        result += "million ";
        n %= 1000000;
    }

    if (n >= 1000) {
        result += chunkToWords(n / 1000);
        result += "thousand ";
        n %= 1000;
    }

    result += chunkToWords(n);

    // Remove trailing space if present
    // if the result is empty then result.back() will be undefined
    // to prevent that we check if the result is empty first
    // if the result is not empty and the last character is a space
    if (!result.empty() && result.back() == ' ')
        // pop_back() method removes the last character from the string
        result.pop_back();

    return result;
}

// تبدیل کلمات به اعداد 
int wordsToNumber(const string& str) {
    // Mapping of words to their numeric values
    // note: this is just a simple example u might just use a disctionary or LLM😎 to do this
    unordered_map<string, int> numberWords = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
        {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13},
        {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16},
        {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19},
        {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50},
        {"sixty", 60}, {"seventy", 70}, {"eighty", 80}, {"ninety", 90},
        {"hundred", 100}, {"thousand", 1000}, {"million", 1000000}
    };

    string word, cleaned;
    istringstream ss(str); // To break the string into words more in read.me file


    int result = 0, current = 0;

    while (ss >> word) {
        cleaned = "";

        // Remove non-letter characters and convert to lowercase more in read.me file
        for (char ch : word) {
            if (isalpha(ch) || ch == '-') cleaned += tolower(ch);
        }

        if (cleaned == "hundred") {
            current *= 100;
        } else if (cleaned == "thousand" || cleaned == "million") {
            current *= numberWords[cleaned];
            result += current;
            current = 0;
        } else if (numberWords.count(cleaned)) {
            current += numberWords[cleaned];
        }
    }

    return result + current;
}

// Semply define input type more in read.me file
void convertNumber(const string& input) {
    bool isNumber = true;

    // Check if input is all digits
    for (char ch : input) {
        if (!isdigit(ch)) {
            isNumber = false;
            break;
        }
    }

    if (isNumber) {
        int n = stoi(input);
        cout << numberToWords(n) << endl;
    } else {
        cout << wordsToNumber(input) << endl;
    }
}

int main() {
    string input;
    cout << "Enter a number or number in words: ";
    getline(cin, input); 
    convertNumber(input); 


    return 0;
}

