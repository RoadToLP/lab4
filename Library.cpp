//
// Created by Kurisu on 1/31/2021.
//

#include "Library.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

void Library::saveTo(const string& filename) {
    ofstream file;
    file.open(filename);
    for (int i = 0; i < this->db.size(); i++){
        file << db[i].first << ":" << db[i].second->getSaveInfo();
    }
    file.close();
}

void Library::loadFrom(const string& filename) {
    ifstream file;
    file.open(filename);
    string bookinfo;
    while (getline(file, bookinfo)){
        stringstream data(bookinfo);
        string part;
        getline(data, part, ':');
        unsigned int article = stoul(part);
        string type;
        getline(data, type, '\xff');
        Book* book = nullptr;
        if (type == "Educational") book = new EducationalBook(article);
        else if (type == "Fiction") book = new FictionBook(article);
        else if (type == "Scientific") book = new ScientificBook(article);
        else throw(std::invalid_argument("Save file is broken"));
        string info;
        getline(data, info, '\n');
        book->loadInfo(info);
        this->db.emplace_back(article, book);
    }
    this->normalize();
}

void Library::addBook(unsigned int article, Book *book) {
    for (auto& i : this->db){
        if (i.first == article) {
            throw std::invalid_argument("Book already is in a library");
        }
    }
    this->db.emplace_back(article, book);
    this->normalize();

}

void Library::delBook(unsigned int article) {
    for (int i = 0; i < this->db.size(); i++){
        if (this->db[i].first == article) {
            delete this->db[i].second;
            this->db.erase(this->db.begin() + i);
            this->normalize();
            return;
        }
    }
    throw std::invalid_argument("No such book");
}



void Library::giveBook(unsigned int article) {
    Book* book = getBook(article);
    try {
        book->setQuantity(book->getQuantity() - 1);
    } catch (const std::exception& e){
        throw std::invalid_argument("Not enough books");
    }
}

void Library::takeBook(unsigned int article) {
    Book* book = getBook(article);
    book->setQuantity(book->getQuantity()+1);
}

string Library::getType(unsigned int article) const {
    return getBook(article)->getType();
}

string Library::getInfo() const{
    string out = "";
    for (int i = 0; i < this->db.size(); i++){
        out += this->db[i].second->getInfo() += "\n--------------------------------------------------------------------\n";
    }
    return out;

}

Book *Library::getBook(unsigned int article) const {
    for (const auto & i : this->db){
        if (i.first == article) return i.second;
    }
    throw std::invalid_argument("No such book");
}

Library::Library() {
    this->db.clear();
}

const string &Library::getAuthor(unsigned int article) const {
    return this->getBook(article)->getAuthor();
}

void Library::setAuthor(unsigned int article, const string &author) {
    this->getBook(article)->setAuthor(author);
}

const string &Library::getName(unsigned int article) const {
    return this->getBook(article)->getName();
}

void Library::setName(unsigned int article, const string &name) {
    this->getBook(article)->setName(name);
}

unsigned short Library::getYear(unsigned int article) const {
    return this->getBook(article)->getYear();
}

void Library::setYear(unsigned int article, unsigned short year) {
    this->getBook(article)->setYear(year);

}

const string &Library::getPublisher(unsigned int article) const {
    return this->getBook(article)->getPublisher();
}

void Library::setPublisher(unsigned int article, const string &publisher) {
    this->getBook(article)->setPublisher(publisher);
}

void Library::setQuantity(unsigned int article, int q) {
    this->getBook(article)->setQuantity(q);

}

const unsigned int &Library::getQuantity(unsigned int article) {
    return this->getBook(article)->getQuantity();
}

void Library::sciAddCourse(unsigned int article, const string &course) {
    if (this->getBook(article)->getType() != "Scientific") throw std::invalid_argument("Invalid book");
    dynamic_cast<ScientificBook*>(this->getBook(article))->addCourse(course);
}

void Library::sciDelCourse(unsigned int article, const string &course) {
    if (this->getBook(article)->getType() != "Scientific") throw std::invalid_argument("Invalid book");
    dynamic_cast<ScientificBook*>(this->getBook(article))->delCourse(course);
}

void Library::sciChangeCourse(unsigned int article, const int &index, const string &course) {
    if (this->getBook(article)->getType() != "Scientific") throw std::invalid_argument("Invalid book");
    dynamic_cast<ScientificBook*>(this->getBook(article))->changeCourse(index, course);
}

const vector<string> &Library::sciGetCourses(unsigned int article) const {
    if (this->getBook(article)->getType() != "Scientific") throw std::invalid_argument("Invalid book");
    return dynamic_cast<ScientificBook*>(this->getBook(article))->getCourses();
}

const string &Library::eduGetCourse(unsigned int article) const {
    if (this->getBook(article)->getType() != "Educational") throw std::invalid_argument("Invalid book");
    return dynamic_cast<EducationalBook*>(this->getBook(article))->getCourse();
}

void Library::eduChangeCourse(unsigned int article, const string &course) {
    if (this->getBook(article)->getType() != "Educational") throw std::invalid_argument("Invalid book");
    dynamic_cast<EducationalBook*>(this->getBook(article))->changeCourse(course);
}

const vector<string> &Library::eduGetGroups(unsigned int article) const {
    if (this->getBook(article)->getType() != "Educational") throw std::invalid_argument("Invalid book");
    return dynamic_cast<EducationalBook*>(this->getBook(article))->getGroups();
}

void Library::eduSetGroups(unsigned int article, const vector<string> &groups) {
    if (this->getBook(article)->getType() != "Educational") throw std::invalid_argument("Invalid book");
    dynamic_cast<EducationalBook*>(this->getBook(article))->setGroups(groups);
}

const string &Library::ficGetSubject(unsigned int article) {
    if (this->getBook(article)->getType() != "Fiction") throw std::invalid_argument("Invalid book");
    return dynamic_cast<FictionBook*>(this->getBook(article))->getSubject();
}

void Library::ficSetSubject(unsigned int article, const string &subject) {
    if (this->getBook(article)->getType() != "Fiction") throw std::invalid_argument("Invalid book");
    dynamic_cast<FictionBook*>(this->getBook(article))->setSubject(subject);

}

void Library::normalize() {
    sort(this->db.begin(), this->db.end());
}

Library::~Library() {
    for (auto& i: this->db){
        delete i.second;
    }
}
