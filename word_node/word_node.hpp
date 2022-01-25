//
// Created by Kevin Schmidt on 1/23/22.
//

#ifndef WORDLES_WORD_NODE_HPP
#define WORDLES_WORD_NODE_HPP
#include <nlohmann/json.hpp>
// for convenience
using json = nlohmann::json;
#include <string>
#include <vector>
#include <array>



class WordNode
{
public:

    std::string word_;

    std::array<WordNode *, 242> children_{};

    WordNode(std::vector<std::string> const & all_words, std::vector<std::string> const & viable_words, int depth=0 /* int depth_remaining = std::numeric_limits<int>::max() */);

    void dump(std::size_t depth) const;
    json get_json() const;
};


#endif //WORDLES_WORD_NODE_HPP
