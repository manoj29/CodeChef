#include <iostream>
#include <string>
#include <cstdlib>

bool compatible()
{
    int compatibility [10][10] = {
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
    return false;
}
void maximize (std::string& score, std::string& max)
{
    std::cout<<score<<std::endl<<max<<std::endl;
    if(compatible()) {
        score = max;
    }
    else {
        int first = atoi(max[0]);
        first--;
        score[0] = std::to_string(first);
        for(int i=1; i <= score.length(); i++) {
            score[i] =
        }
    }
    return;
}
int main(void)
{
    int testcases = 1;
    //std::cin>>testcases;
    while(testcases--) {
        int score, max_score;
        std::string score_str, max_score_str;
        std::cin>> score >> max_score;
        score_str = std::to_string(score);
        max_score_str = std::to_string(max_score);
        int length = score_str.length();
        while(length <  max_score_str.length()) {
            score_str.insert(0,"~");
            length++;
        }
        maximize(score_str, max_score_str);
    }
}
