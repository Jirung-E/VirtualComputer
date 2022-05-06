#include "Words.hpp"

using namespace HangMan;
using namespace std;
using namespace Utils;


const string Words::null_word = "NULLWORD";

Words::Words() : num_of_words { 0 } {
    
}

Words::~Words() {
    
}


string Words::answer(index_t idx) const {
    if(idx >= answer_.size()) {
        return null_word;
    }
    
    return answer_.at(idx);
}

string Words::hint(index_t idx) const {
    if(idx >= hint_.size()) {
        return null_word;
    }
    
    return hint_.at(idx);
}

void Words::add(string answer_, string hint_) {
    if(answer_ == null_word) {
        return;
    }
    for(const string& s : this->answer_) {
        if(answer_ == s) {
            return;
        }
    }
    
    num_of_words++;
    this->answer_.push_back(answer_);
    this->hint_.push_back(hint_);
}

num_t Words::numOfWords() const {
    return num_of_words;
}