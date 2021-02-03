//
// Created by Kurisu on 1/28/2021.
//

#include "Book.h"
#include <exception>
#include <stdexcept>

void Book::setQuantity(int q) {
    if (q < 0) {
        throw(std::invalid_argument("Invalid quantity"));
    }
    this->quantity = q;
}

const unsigned int& Book::getQuantity() const {
    return this->quantity;
}

unsigned int Book::getArticle() const {
    return this->article;
}

const string &Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const string &author) {
    Book::author = author;
}

const string &Book::getName() const {
    return name;
}

void Book::setName(const string &name) {
    Book::name = name;
}

unsigned short Book::getYear() const {
    return year;
}

void Book::setYear(unsigned short year) {
    Book::year = year;
}

const string &Book::getPublisher() const {
    return publisher;
}

void Book::setPublisher(const string &publisher) {
    Book::publisher = publisher;
}

