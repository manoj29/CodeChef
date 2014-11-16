#include <iostream>
#include <string>
#include <cstdlib>

const int compatibility [10][10] = {
    1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    1, 1, 0, 1, 1, 0, 0, 1, 1, 1,
    0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 1, 1,
    0, 0, 0, 0, 1, 0, 0, 0, 1, 1,
    0, 0, 0, 0, 0, 1, 1, 0, 1, 1,
    0, 0, 0, 0, 0, 0, 1, 0, 1, 0,
    1, 0, 0, 1, 0, 0, 0, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1
};

class Score
{
    std::string score_str; // Hold the score in string format
    int score_val; // Hold the score as an integer for printing and comparison

    //Converter from int to string
    void setValue()
    {
        score_val = std::stoi (score_str);
    }

    public:
    //Default constructor
    Score()
    {
        score_str = "";
        score_val = 0;
    }

    //Constructor with string argument, the only one used in the program
    Score(std::string val)
    {
        score_str = val;
        this->setValue();
    }

    //Copy Constructor
    Score(const Score& val)
    {
        this->score_val = val.score_val;
        this->score_str = val.score_str;
    }

    //Return integer value, doesn't compute anything.
    //Important to maintain a consistent state between string and integer representation.
    const int value () const
    {
        return this->score_val;
    }

    //Return string length. Use the underlying string.length() function.
    const int length() const
    {
        return this->score_str.length();
    }

    //Return string. Ended up not using it. Thought it might be needed while writing the class.
    const std::string str() const
    {
        return this->score_str;
    }

    //Return a digit specified by the index. O(1)
    int getDigit(int index) const
    {
        if(score_str[index] == '~')
            return -1;
        return (score_str[index])-'0';
    }

    //Set a digit specified by the index. O(string_length)
    void setDigit(int index, int value)
    {
        char val = value + '0';
        this->score_str[index] = val;
        if(score_str.find("~") == std::string::npos)
            this->setValue();
    }

    //Add padding of "~" characters to make string lengths equal. O(string_length)
    void pad(const Score& max)
    {
        while(this->length() < max.length()) {
            this->score_str.insert(0, "~");
        }
    }

    //Find if the mangled score exceeds the max score.
    //Replace pending ~'s with 0's. Best case scenario. O(string_length)
    bool isGreater(const Score& sc)
    {
        std::string temp = this->score_str;
        for(int i=0; i < temp.length(); i++) {
            if(temp[i] == '~')
                temp[i] = '0';
        }
        Score sc_temp(temp);
        if (sc_temp.value() > sc.value()) {
            return true;
        }
        return false;
    }

    // Simple table lookup operation. O(1)
    bool compatible (const int score, const int reference) const
    {
        if(compatibility[score][reference])
            return true;
        return false;
    }

    // Check if the numbers starting from index are compatible. O(string_length)
    bool isCompatible(const Score& sc, int index) const
    {
        for(int i=index; i < sc.length(); i++) {
            const int digit = this->getDigit(i);
            const int sc_digit = sc.getDigit(i);
            if(digit == -1)
                continue;
            if(!compatible(digit, sc_digit))
                return false;
        }

        return true;
    }

};

// Maximize the value of score subject to constraints of max and compatibility. O(1)
int maximize (int score, int max)
{
    if(!(score >=0 && score <=9) || !(max >= 0 && max <=9)) {
        std::cout <<"Dude! Ya messed up again.\n";
        return -1;
    }

    for(int i=max; i > score ; i--) {
        if(compatibility[score][i]){
            return i;
        }
    }
}

// The main function. The algorithm is as follows:
// We consider the digits one at a time being cognizant of not exceeding the max score
// Until we can be sure we don't exceed the max score, maximize against the corresponding digit in max_score
// Afterwards it is just maximizing every digit. O(string_length^2)
void deface (const Score& score, const Score& max_score)
{
    Score mangled_score(score);
    bool CanExceed = true;
    for(int i=0 ; i < score.length(); i++) {
        if(CanExceed) {
            int maxDigit = max_score.getDigit(i);
            int scoreDigit = score.getDigit(i);
            if(scoreDigit == -1)
                mangled_score.setDigit(i, maxDigit);
            else {
                int maxPossible = maximize(scoreDigit, maxDigit);
                mangled_score.setDigit(i, maxPossible);
                if(maxPossible < maxDigit)
                    CanExceed = false;
            }
            if(mangled_score.isGreater(max_score)) {
                if(!mangled_score.isCompatible(max_score, i)){
                    if(scoreDigit == -1)
                        mangled_score.setDigit(i, maxDigit-1);
                    else {
                        int maxPossible = maximize(scoreDigit, maxDigit-1);
                        mangled_score.setDigit(1, maxPossible);
                    }
                    CanExceed = false;
                }
            }
        } else {
            int max_val = maximize (score.getDigit(i), 9);
            mangled_score.setDigit(i, max_val);
        }
    }

    std::cout<<mangled_score.value()<<std::endl;
}
int main(void)
{
    int testcases = 1;
    std::cin>>testcases;
    while(testcases--) {
        std::string val1, val2;
        std::cin>> val1 >> val2;
        Score score(val1);
        Score max(val2);
        score.pad(max);
        deface(score, max);
    }
}
