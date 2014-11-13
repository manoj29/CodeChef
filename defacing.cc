#include <iostream>
#include <string>
#include <cstdlib>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

const int compatibility [10][10] = {
    1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    1, 1, 0, 1, 1, 0, 0, 1, 1, 1,
    0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 1, 1,
    0, 0, 0, 0, 1, 0, 0, 0, 1, 1,
    0, 0, 0, 0, 0, 1, 1, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 1, 0,
    1, 0, 0, 1, 0, 0, 0, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1
};

std::string max_possible_val (int index, const std::string& score, const std::string& max)
{
    using boost::lexical_cast;

    int max_val  = lexical_cast<int>(max[index]);
    int score_val = lexical_cast<int> (score[index]);
    if(score[index] == '~') {
        return lexical_cast<std::string> (max_val - 1);
    }

    for(int i = max_val ; i > 0 ; i--) {

        if(compatibility[score_val][i]) {
            //std::cout<<"Returning " << i << "\n";
            return lexical_cast<std::string>(i);
        }
    }

}

bool compatible(const std::string& score, const std::string& max)
{
    using boost::lexical_cast;

    std::string temp = score;
    int score_int, max_int;
    for(int i = 0; i <temp.length(); i++) {
        if(temp[i] == '~')
            temp[i] = max[i];
    }
    score_int = lexical_cast<int>(temp);
    max_int = lexical_cast<int> (max);
    if (score_int <= max_int)
        return true;
    return false;
}

void colour (std::string& score, const std::string& max)
{
    using boost::lexical_cast;

    for(int i=0; i < score.length() ; i++) {
        int score_digit = lexical_cast<int> (score[i]);
        int max_digit = lexical_cast<int> (max[i]);
        for(int j= max_digit; j > score_digit; j--) {
            if(compatibility[score_digit][j]) {
                score.replace(i, 1, lexical_cast<std::string>(j));
                break;
		}
        }
    }

}

void maximize (bool padded, std::string& score, const std::string& max)
{
    using boost::lexical_cast;

    if(padded) {
        for(int i = 0; i < score.length() ; i++) {
            if(score[i] == '~')
                score[i] = max[i];
            if(!compatible(score,max)) {
                std::string retval;
                retval = max_possible_val(i, score, max);
                score.replace(i, 1, retval);
            }
        }
    }
    else {
        colour(score, max);
    }
    std::cout << lexical_cast<int>(score) <<"\n";
}

int main(void)
{
    int testcases = 1;
    bool padded = false;
    //std::cin>>testcases;
    while(testcases--) {
        std::string score, max_score;
        std::cin>> score >> max_score;
        while(score.length() <  max_score.length()) {
            score.insert(0,"~");
            padded = true;
        }
        maximize(padded, score, max_score);
    }
}
