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
int max_possible_val (int index, const std::string& score, const std::string& max)
{
    int number = stoi(max[index]);
    std::cout<<"Int val: "<< max_int<<std::endl;
    if(score[index] == '~') {
        return (number - 1);
    }

    for(int i = (number - 1) ; i >= 0 ; i--) {

        if(compatibility[number][i])
            return i;
    }

}
bool compatible(const std::string& score, const std::string& max)
{
    std::string temp = score;
    int score_int, max_int;
    boost::replace_all(temp, "~", "9");
    score_int = stoi(temp);
    max_int = stoi(max);
    if (score_int <= max_int)
        return true;
    return false;
}

void maximize (std::string& score, const std::string& max)
{
    score[0] = max[0];
    if(!compatible(score,max)) {
        score[0] = max_possible_val(0, score, max);
    }
    for(int i = 1; i < score.length(); i++) {
        score[i] = max_possible_val(i, score, max);
        std::cout<<"Well: "<<score[i]<<std::endl;
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
