#ifndef Words_hpp
#define Words_cpp

#include <string>
#include <vector>

#include "../../../../VirtualComputer/Utils/UtilTypes.hpp"


namespace HangMan {
    class Words {
        private: Utils::num_t num_of_words;
        private: std::vector<std::string> answer_;
        private: std::vector<std::string> hint_;
        
        public: const static std::string null_word;
    
    public:
        Words();
        ~Words();
        
    public:        
        std::string answer(Utils::index_t idx) const;
        std::string hint(Utils::index_t idx) const;
        void add(std::string answer_, std::string hint_);
        Utils::num_t numOfWords() const;
    };
}

#endif