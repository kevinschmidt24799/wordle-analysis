#include <iostream>
#include "words_in.hpp"
#include "feedback.hpp"
#include "word_node.hpp"
#include <string>

const int word_count = 0;
const bool limit_guesses_to_possible = false;

int main()
{
    auto w = get_words(word_count);


    std::cout << w.size() << '\n';
    for(auto const & wd : w) std::cout << wd <<'\n';


    WordNode wn {w, w, limit_guesses_to_possible};
    std::ofstream o(std::string("wordle-") + (limit_guesses_to_possible?"limited-":"unlimited-")+ std::to_string(word_count) + ".json");
    o << std::setw(4) << wn.get_json() << std::endl;

}

