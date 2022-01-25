//
// Created by Kevin Schmidt on 1/22/22.
//

#include "words_in.hpp"
#include "random"
std::vector<std::string> get_words()
{
    std::vector<std::string> words;

    std::ifstream inFile;
    std::string temp;

    inFile.open("words/wordle-allowed-guesses.txt");
    while(getline(inFile, temp))
    {
        words.push_back(std::move(temp));
    }
    inFile.close();

    inFile.open("words/wordle-answers-alphabetical.txt");
    while(getline(inFile, temp))
    {
        words.push_back(std::move(temp));
    }

    inFile.close();

    words.erase(std::remove_if(words.begin(), words.end(),
                               [](std::string const & s){
                                    return(s.length() != 5 || std::any_of(s.begin(), s.end(), [](char c){
                                        return (c < 'a' || c > 'z');}));
                               }), words.end());

    return words;
}

std::vector<std::string> get_words(int count)
{
    auto w = get_words();
    if(count == 0) return w;
    assert(count < w.size());
    std::mt19937 g(count);
    std::shuffle(w.begin(), w.end(), g);
    w.erase(w.begin()+count, w.end());
    return w;
}