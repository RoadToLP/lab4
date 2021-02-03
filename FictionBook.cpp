//
// Created by Kurisu on 1/31/2021.
//

#include "FictionBook.hpp"
#include <numeric>
#include <utility>
#include <fmt/core.h>
#include <sstream>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

const string & FictionBook::getSubject() const {
    return this->subject;
}

void FictionBook::setSubject(const string &subject) {
    this->subject = subject;
}

string FictionBook::getInfo() const {
    return fmt::format("Book type: {}\nAuthor: {}\nName: {}\nYear: {}\nPublisher: {}\nQuantity: {}\nSubject: {}\nArticle: {}", "Fiction", this->author, this->name, this->year, this->publisher, this->quantity, this->subject, this->article);
}

string FictionBook::getType() const {
    return "Fiction";
}

string FictionBook::getSaveInfo() const {
    return fmt::format("{}\xff{}\xff{}\xff{}\xff{}\xff{}\xff{}\xff{}\n", "Fiction", this->author, this->name, this->year, this->publisher, this->quantity, this->subject, this->article);
}

void FictionBook::loadInfo(string data) {
    stringstream sdata(data);
    getline(sdata, this->author, '\xff');
    string temp;
    getline(sdata, this->name, '\xff');
    getline(sdata, temp, '\xff');
    this->year = stol(temp);
    getline(sdata, this->publisher, '\xff');
    getline(sdata, temp, '\xff');
    this->quantity = stol(temp);
    getline(sdata, subject, '\xff');
    getline(sdata, temp, '\xff');
    this->article = stoul(temp);
}
FictionBook::FictionBook(const unsigned int &article) {
    this->article = article;
    this->name = "None";
    this->author = "None";
    this->year = 1900;
    this->publisher = "None";
    this->quantity = 0;
    this->subject = "None";
}

FictionBook::FictionBook(const string &author, const string &name, const int &year, const string &publisher, const int &quantity, const string &subject, const unsigned int &article) {
    this->article = article;
    this->name = name;
    this->author = author;
    this->year = year;
    this->publisher = publisher;
    this->quantity = quantity;
    this->subject = subject;

}
