//
// Created by Kevin Schmidt on 1/23/22.
//

#include "feedback.hpp"

Feedback::Feedback(std::string const & answer, std::string const & guess)
{
    std::array<bool, 5> used;
    used.fill(false);

    // assume not found
    result_.fill(Result::NONE);

    // find exact matches
    for (int i{0}; i<5; ++i)
    {
        if (guess[i] == answer[i])
        {
            result_[i] = Result::CORRECT;
            used[i] = true;
        }
    }

    // find wrong locations
    for (int i{0}; i<5; ++i)
    {
        if(result_[i] == Result::CORRECT) continue;
        for (int j{0}; j<5; ++j)
        {
            if (!used[j] && answer[j]==guess[i])
            {
                result_[i] = Result::MISPLACED;
                used[j] = true;
                break;
            }
        }
    }
//
//
//    for (int i = 0; i < 5; ++i)
//    {
//        if(guess[i] == answer[i])
//        {
//            result_[i] = Result::CORRECT;
//            used[i] = true;
//            continue;
//        }
//        bool found = false;
//        for(int j = 0; j < 5 && !found; ++j)
//        {
//            if(answer[j] == guess[i] && !used[j])
//            {
//                result_[i] = Result::MISPLACED;
//                used[j] = true;
//                found = true;
//                continue;
//            }
//        }
//        if(!found)
//        {
//            result_[i] = Result::NONE;
//        }
//    }

}

static std::string feedback_prints[3] = {"NONE", "MISPLACED", "CORRECT"};

std::ostream &operator<<(std::ostream &os, const Feedback &feedback)
{
    for(auto i : feedback.result_)
    {
        os << feedback_prints[static_cast<int>(i)] <<" ";
    }
    return os;
}

Feedback::Feedback(unsigned char c)
{
    for(auto i = result_.rbegin(); i!= result_.rend(); ++i)
    {
        *i = static_cast<Result>(c%3);
        c/=3;
    }
}

unsigned char Feedback::to_char()
{
    unsigned char out = 0;
    for(auto r : result_)
    {
        out = 3 * out + static_cast<int>(r);
    }
    return out;
}


std::string Feedback::to_trinary()
{
    std::string out;
    for(auto r : result_)
    {
        out = out + std::to_string(static_cast<int>(r));
    }
    return out;
}



bool consistent(std::string const & answer, std::string const & word1, std::string const & word2)
{
    Feedback f1 {answer, word1};
    Feedback f2 {answer, word2};
    if(f1.to_char() != f2.to_char()) return false;
    for(int i = 0; i < 5; ++i)
    {
        if(f1.result_[i] == Feedback::Result::MISPLACED && word1[i]!=word2[i])
        {
            return false;
        }
    }
    return true;
}

