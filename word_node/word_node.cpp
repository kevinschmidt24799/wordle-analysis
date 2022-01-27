//
// Created by Kevin Schmidt on 1/23/22.
//

#include "word_node.hpp"
#include <array>
#include "feedback.hpp"
#include <iostream>

WordNode::WordNode(std::vector<std::string> const & all_words, std::vector<std::string> const & viable_words, bool limited, int depth /* depth_remaining */)
{
    if(viable_words.size()==1)
    {
        word_ = viable_words[0];
        return;
    }

    int min = std::numeric_limits<int>::max();
    std::string min_word;

    for (auto const &wd: all_words)
    {
        int max_ans;
        int max = 0;
        for (int i = 0; i < 243; ++i)
        {
            int count = 0;
            for (auto const &s: viable_words)
            {
                if (Feedback(s, wd).to_char() == i)
                {
                    count++;
                }
            }
            if (count > max)
            {
                max = count;
            }
        }
        if(max < min)
        {
            min = max;
            min_word = wd;
            if(depth == 0) std::cout << "new min word : " << min_word <<' ' << min << '\n';
        }
        if(depth == 0) std::cout << "tested word: " << wd << ' ' << max << '\n';
    }
    // std::cout << "word added: "<< min_word <<'\n';
    word_ = min_word;

    std::array<std::vector<std::string>, 242> partitions_;

    for(auto const & word : viable_words)
    {
        auto f = Feedback(word, word_).to_char();
        if(f != 242)
        {
            partitions_[f].push_back(word);
        }
    }

    for(int i = 0; i < 242; ++i)
    {
        if(!partitions_[i].empty())
        {
            // if(depth_remaining > 1)
            {
                children_[i] = new WordNode{limited ? partitions_[i] : all_words, partitions_[i], limited, depth+1 /* depth_remaining-1 */};
            }
        }
    }

}

void WordNode::dump(std::size_t depth) const
{
    std::cout << std::string(depth,'\t') << word_ <<'\n';
    for(auto const c : children_)
    {
        if(c!= nullptr)
        {
            std::cout << std::string(depth+1,'\t') << Feedback{c->word_, word_} <<'\n';
            c->dump(depth+2);
        }
    }
}

json WordNode::get_json() const
{
    json out;
    out["_word"] = word_;
    json children;
    for(int i = 0; i < 242; ++i)
    {
        if(children_[i] != nullptr)
        {
            children[Feedback(i).to_trinary()] = children_[i]->get_json();
        }
    }
    if(!children.empty())
    {
        out["children"] = children;
    }
    return out;
}

