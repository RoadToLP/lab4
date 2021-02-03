//
// Created by Kurisu on 1/28/2021.
//

#include "EducationalBook.h"
#include <fmt/format.h>
#include <numeric>
#include <sstream>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <iostream>

using namespace std;
const string & EducationalBook::getCourse() const {
    return this->course;
}

void EducationalBook::changeCourse(const string &course) {
    this->course = course;
}

string EducationalBook::getInfo() const {
    return fmt::format("Book type: {}\nAuthor: {}\nName: {}\nYear: {}\nPublisher: {}\nQuantity: {}\nCourse: {}\nGroups: {}\nArticle: {}", "Educational", this->author, this->name, this->year, this->publisher, this->quantity, this->course, fmt::join(this->groups, ", "), this->article);

}

string EducationalBook::getType() const {
    return "Educational";
}

EducationalBook::EducationalBook(const unsigned int &article) {
    this->article = article;
    this->name = "None";
    this->author = "None";
    this->year = 1900;
    this->publisher = "None";
    this->quantity = 0;
    this->course = "None";
    this->groups.clear();
}

EducationalBook::EducationalBook(const string &author, const string &name, const int &year, const string &publisher, const int &quantity, const string &course, const vector<string> &groups, const unsigned int &article) {
    this->article = article;
    this->author = author;
    this->name = name;
    this->year = year;
    this->publisher = publisher;
    this->quantity = quantity;
    this->course = course;
    this->groups = groups;

}
string EducationalBook::getSaveInfo() const {
    return fmt::format("{}\xff{}\xff{}\xff{}\xff{}\xff{}\xff{}\xff{}\xff{}\n", "Educational", this->author, this->name, this->year, this->publisher, this->quantity, this->course, fmt::join(this->groups, ","), this->article);
}

void EducationalBook::loadInfo(string data) {
    stringstream sdata(data);
    getline(sdata, this->author, '\xff');
    getline(sdata, this->name, '\xff');
    string temp;
    getline(sdata, temp, '\xff');
    this->year = stol(temp);
    getline(sdata, this->publisher, '\xff');
    getline(sdata, temp, '\xff');
    this->quantity = stol(temp);
    getline(sdata, this->course, '\xff');
    getline(sdata, temp, '\xff');
    boost::split(this->groups, temp, boost::is_any_of(","), boost::token_compress_on);
    getline(sdata, temp, '\xff');
    this->article = stoul(temp);
}

const vector<string> &EducationalBook::getGroups() const {
    return groups;
}

void EducationalBook::setGroups(const vector<string> &groups) {
    if (groups.size() > 8) throw invalid_argument("Too many groups");
    this->groups = groups;
}
