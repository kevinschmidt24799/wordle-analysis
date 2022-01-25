#include <iostream>
#include "words_in.hpp"
#include "feedback.hpp"
#include "word_node.hpp"
#include <string>

const int word_count = 0;

int main()
{
    auto w = get_words(word_count);


    WordNode wn {w, w};

    std::ofstream o("wordle-" + std::to_string(word_count) + ".json");
    o << std::setw(4) << wn.get_json() << std::endl;
}

