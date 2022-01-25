//
// Created by Kevin Schmidt on 1/23/22.
//

#ifndef WORDLES_FEEDBACK_HPP
#define WORDLES_FEEDBACK_HPP
#include <array>
#include <string>
#include <ostream>

struct Feedback
{
    enum class Result{NONE=0, MISPLACED=1, CORRECT=2};
    std::array<Result, 5> result_;
    Feedback(std::string const & answer, std::string const & guess);
    Feedback(unsigned char c);
    friend std::ostream &operator<<(std::ostream &os, const Feedback &feedback);
    unsigned char to_char();
    std::string to_trinary();
};

bool consistent(std::string const & answer, std::string const & word1, std::string const & word2);


#endif //WORDLES_FEEDBACK_HPP
