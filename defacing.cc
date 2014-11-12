#include <iostream>
#include <string>
#include <cstdlib>
#include <boost/algorithm/string.hpp>

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
char max_possible_val (int index, const std::string& score, const std::string& max)
{
    int number = max[index];
    if(score[index] == '~') {
        return (number - 1 + '0');
    }

    for(int i = (number - 1) ; i >= 0 ; i--) {

        if(compatibility[number][i])
            return i+'0';
    }

}
bool compatible(const std::string& score, const std::string& max)
{
    std::string temp = score;
    int score_int, max_int;
    boost::replace_all(temp, "~", "9");
    score_int = atoi(temp.c_str());
    max_int = atoi(max.c_str());
    if (score_int <= max_int)
        return true;
    return false;
}

void maximize (std::string& score, const std::string& max)
{
    for(int i = 0; i < score.length(); i++) {
        score[i] = max[i];
        if(!compatible(score, max)) {
            score[i] = max_possible_val(i, score, max);
        }
    }
    std::cout << score <<"\n";
}

int main(void)
{
    int testcases = 1;
    //std::cin>>testcases;
    while(testcases--) {
        std::string score, max_score;
        std::cin>> score >> max_score;
        while(score.length() <  max_score.length()) {
            score.insert(0,"~");
        }
        maximize(score, max_score);
    }
}
