//
// Created by Kurisu on 1/28/2021.
//

#include "ScientificBook.h"
#include <fmt/format.h>
#include <numeric>
#include <sstream>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <fmt/core.h>

string ScientificBook::getType() const {
    return "Scientific";
}

string ScientificBook::getInfo() const {
    return fmt::format("Book type: {}\nAuthor: {}\nName: {}\nYear: {}\nPublisher: {}\nQuantity: {}\nCourses: {}\nArticle: {}", "Scientific", this->author, this->name, this->year, this->publisher, this->quantity, fmt::join(this->courses, std::string(", ")), this->article);
}

void ScientificBook::changeCourse(const int &index, const string &course) {
    if (index < 0 || index >= 3 || index >= this->courses.size()){
        throw std::out_of_range("Index out of range");
    }
    this->courses[index] = course;
}

void ScientificBook::addCourse(const string& course) {
    if (this->courses.size() >= 3) throw std::out_of_range("Index out of range");
    this->courses.push_back(course);

}

const vector<string> & ScientificBook::getCourses() const {
    return this->courses;
}

void ScientificBook::delCourse(const string& course) {
    if (this->courses.empty()){
        throw std::out_of_range("Trying to delete from empty list");
    }
    this->courses.erase(remove(this->courses.begin(), this->courses.end(), course), this->courses.end());
}

string ScientificBook::getSaveInfo() const {
    return fmt::format("{}\xff{}\xff{}\xff{}\xff{}\xff{}\xff{}\xff{}\n", "Scientific", this->author, this->name, this->year, this->publisher, this->quantity, fmt::join(this->courses, ","), this->article);
}

void ScientificBook::loadInfo(string data) {
    stringstream sdata(data);
    getline(sdata, this->author, '\xff');
    getline(sdata, this->name, '\xff');
    string temp;
    getline(sdata, temp, '\xff');
    this->year = stol(temp);
    getline(sdata, this->publisher, '\xff');
    getline(sdata, temp, '\xff');
    this->quantity = stol(temp);
    getline(sdata, temp, '\xff');
    boost::split(this->courses, temp, boost::is_any_of(","), boost::token_compress_on);
    getline(sdata, temp, '\xff');
    this->article = stoul(temp);
}

ScientificBook::ScientificBook(const unsigned int &article) {
    this->article = article;
    this->name = "None";
    this->author = "None";
    this->year = 1900;
    this->publisher = "None";
    this->quantity = 0;
    this->courses.clear();
}

ScientificBook::ScientificBook(const string &author, const string &name, const int &year, const string &publisher, const int &quantity, const vector<string> &courses, const unsigned int &article) {
    this->article = article;
    this->name = name;
    this->author = author;
    this->year = year;
    this->publisher = publisher;
    this->quantity = quantity;
    this->courses = courses;

}

