//
// Created by Kevin Schmidt on 1/23/22.
//

#include "gtest/gtest.h"
#include "feedback.hpp"

TEST(wordle, feedback)
{
    EXPECT_EQ(Feedback("hello","hello").result_[0], Feedback::Result::CORRECT);
    EXPECT_EQ(Feedback("hello","hello").result_[1], Feedback::Result::CORRECT);
    EXPECT_EQ(Feedback("hello","hello").result_[2], Feedback::Result::CORRECT);
    EXPECT_EQ(Feedback("hello","hello").result_[3], Feedback::Result::CORRECT);
    EXPECT_EQ(Feedback("hello","hello").result_[4], Feedback::Result::CORRECT);

    EXPECT_EQ(Feedback("hello","apple").result_[0], Feedback::Result::NONE);
    EXPECT_EQ(Feedback("hello","apple").result_[1], Feedback::Result::NONE);
    EXPECT_EQ(Feedback("hello","apple").result_[2], Feedback::Result::NONE);
    EXPECT_EQ(Feedback("hello","apple").result_[3], Feedback::Result::CORRECT);
    EXPECT_EQ(Feedback("hello","apple").result_[4], Feedback::Result::MISPLACED);

    EXPECT_EQ(Feedback("hello","lohel").result_[0], Feedback::Result::MISPLACED);
    EXPECT_EQ(Feedback("hello","lohel").result_[1], Feedback::Result::MISPLACED);
    EXPECT_EQ(Feedback("hello","lohel").result_[2], Feedback::Result::MISPLACED);
    EXPECT_EQ(Feedback("hello","lohel").result_[3], Feedback::Result::MISPLACED);
    EXPECT_EQ(Feedback("hello","lohel").result_[4], Feedback::Result::MISPLACED);

    EXPECT_EQ(Feedback("abcde","fghij").result_[0], Feedback::Result::NONE);
    EXPECT_EQ(Feedback("abcde","fghij").result_[1], Feedback::Result::NONE);
    EXPECT_EQ(Feedback("abcde","fghij").result_[2], Feedback::Result::NONE);
    EXPECT_EQ(Feedback("abcde","fghij").result_[3], Feedback::Result::NONE);
    EXPECT_EQ(Feedback("abcde","fghij").result_[4], Feedback::Result::NONE);
}

TEST(wordle, feedback_chars)
{
    EXPECT_EQ(Feedback("hello", "zxcvb").to_char(), 0);
    EXPECT_EQ(Feedback("hello", "hello").to_char(), 242);
    EXPECT_EQ(Feedback("hello", "helol").to_char(), 238);
    EXPECT_EQ(Feedback("hello", "apple").to_char(), 7);

    for(int i = 0; i < 243; i++)
    {
        EXPECT_EQ(Feedback(i).to_char(), i);
    }
}