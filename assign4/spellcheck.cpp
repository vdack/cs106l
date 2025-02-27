#include "spellcheck.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <set>
#include <string>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
  Corpus corpus;
  auto spacePointers = find_all(source.begin(), source.end(), isspace);
  std::transform(spacePointers.begin(), 
                  spacePointers.end() - 1, 
                 spacePointers.begin() + 1, 
                 std::inserter<Corpus>(corpus, corpus.end()),
              [&](auto start, auto end){return Token{source, start, end};});
  std::erase_if(corpus, [](const Token& token){return token.content.empty();});
  return corpus;
}

std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  namespace rv = std::ranges::views;
  auto view =  source 
    | rv::filter([&](Token token){return !dictionary.contains(token.content);})
    | rv::transform(
      [&](Token token){
        return Mispelling{token, {} };
      }
    )
    | rv::transform(
      [&](Mispelling missplled) {
        auto suggestion_view = dictionary| rv::filter([&](std::string word) {return ::levenshtein(missplled.token.content, word) == 1;});
        missplled.suggestions = std::set<std::string> (suggestion_view.begin(), suggestion_view.end());
        return missplled;
      }
    )
    | rv::filter(
      [&](Mispelling missplled) {return missplled.suggestions.size() > 0;}
    );
  return std::set<Mispelling>(view.begin(), view.end());
};

/* Helper methods */
#include "utils.cpp"