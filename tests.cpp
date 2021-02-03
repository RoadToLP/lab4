//
// Created by Kurisu on 12/23/2020.
//

#include <gtest/gtest.h>
#include "Library.hpp"
#include "FictionBook.hpp"
#include "ScientificBook.h"
#include "EducationalBook.h"
TEST(library, Creation){
    Library library;
    ASSERT_EQ(library.getInfo(), "");
}
TEST(EducationalBook, ConstructorNoInfo){
    EducationalBook book(1337);
    ASSERT_EQ(book.getInfo(), "Book type: Educational\nAuthor: None\nName: None\nYear: 1900\nPublisher: None\nQuantity: 0\nCourse: None\nGroups: \nArticle: 1337");
}
TEST(ScientificBook, ConstructorNoInfo){
    ScientificBook book(1337);
    ASSERT_EQ(book.getInfo(), "Book type: Scientific\nAuthor: None\nName: None\nYear: 1900\nPublisher: None\nQuantity: 0\nCourses: \nArticle: 1337");
}
TEST(FictionBook, ConstructorNoInfo){
    FictionBook book(1337);
    ASSERT_EQ(book.getInfo(), "Book type: Fiction\nAuthor: None\nName: None\nYear: 1900\nPublisher: None\nQuantity: 0\nSubject: None\nArticle: 1337");
}

TEST(EducationalBook, ConstructorWithInfo){
    EducationalBook book("author", "name", 2107, "publisher", 1337, "course", vector<string>({"group1", "group2"}), 1337);
    ASSERT_EQ(book.getInfo(), "Book type: Educational\nAuthor: author\nName: name\nYear: 2107\nPublisher: publisher\nQuantity: 1337\nCourse: course\nGroups: group1, group2\nArticle: 1337");
}

TEST(ScientificBook, ConstructorWithInfo){
    ScientificBook book("author", "name", 2107, "publisher", 1337, vector<string>({"course1", "course2"}), 1337);
    ASSERT_EQ(book.getInfo(), "Book type: Scientific\nAuthor: author\nName: name\nYear: 2107\nPublisher: publisher\nQuantity: 1337\nCourses: course1, course2\nArticle: 1337");
}

TEST(FictionBook, ConstructorWithInfo){
    FictionBook book("author", "name", 2107, "publisher", 1337, "subject", 1337);
    ASSERT_EQ(book.getInfo(), "Book type: Fiction\nAuthor: author\nName: name\nYear: 2107\nPublisher: publisher\nQuantity: 1337\nSubject: subject\nArticle: 1337");
}
//Other functions will be tested in library class with it itself

TEST(library, BookAdd){
    Library library;
    EducationalBook* book = new EducationalBook(1337);
    library.addBook(1337, book);
    ASSERT_EQ(library.getType(1337), "Educational");
}

TEST(library, BookDel){
    Library library;
    EducationalBook* book = new EducationalBook(1337);
    library.addBook(1337, book);
    ASSERT_EQ(library.getType(1337), "Educational");
    library.delBook(1337);
    string type;
    ASSERT_THROW(type = library.getType(1337), std::invalid_argument);
}

TEST(library, getsetQuantity){
    Library library;
    EducationalBook* book = new EducationalBook(1337);
    library.addBook(1337, book);
    ASSERT_EQ(library.getType(1337), "Educational");
    library.setQuantity(1337, 228);
    ASSERT_EQ(library.getQuantity(1337), 228);
}

TEST(library, takeBook){
    Library library;
    EducationalBook* book = new EducationalBook(1337);
    library.addBook(1337, book);
    ASSERT_EQ(library.getType(1337), "Educational");
    library.setQuantity(1337, 228);
    ASSERT_EQ(library.getQuantity(1337), 228);
    library.takeBook(1337);
    ASSERT_EQ(library.getQuantity(1337), 229);
}

TEST(library, giveBook){
    Library library;
    EducationalBook* book = new EducationalBook(1337);
    library.addBook(1337, book);
    ASSERT_EQ(library.getType(1337), "Educational");
    library.setQuantity(1337, 228);
    ASSERT_EQ(library.getQuantity(1337), 228);
    library.giveBook(1337);
    ASSERT_EQ(library.getQuantity(1337), 227);
}

TEST(library, getsetName){
    Library library;
    EducationalBook* book = new EducationalBook(1337);
    library.addBook(1337, book);
    ASSERT_EQ(library.getType(1337), "Educational");
    library.setName(1337, "Name");
    ASSERT_EQ(library.getName(1337), "Name");
}

TEST(library, getsetAuthor){
    Library library;
    EducationalBook* book = new EducationalBook(1337);
    library.addBook(1337, book);
    ASSERT_EQ(library.getType(1337), "Educational");
    library.setAuthor(1337, "Author");
    ASSERT_EQ(library.getAuthor(1337), "Author");
}

TEST(library, getsetYear){
    Library library;
    EducationalBook* book = new EducationalBook(1337);
    library.addBook(1337, book);
    ASSERT_EQ(library.getType(1337), "Educational");
    library.setYear(1337, 2107);
    ASSERT_EQ(library.getYear(1337), 2107);
}

TEST(library, getsetPublisher){
    Library library;
    EducationalBook* book = new EducationalBook(1337);
    library.addBook(1337, book);
    ASSERT_EQ(library.getType(1337), "Educational");
    library.setPublisher(1337, "Publisher");
    ASSERT_EQ(library.getPublisher(1337), "Publisher");
}

TEST(library, sciAddGetDelChangeCourse){
    Library library;
    ScientificBook* book = new ScientificBook(1337);
    library.addBook(1337, book);
    ASSERT_EQ(library.getType(1337), "Scientific");
    library.sciAddCourse(1337, "Course");
    ASSERT_EQ(library.sciGetCourses(1337), vector<string>({"Course"}));
    library.sciChangeCourse(1337, 0, "Course2");
    ASSERT_EQ(library.sciGetCourses(1337), vector<string>({"Course2"}));
    library.sciDelCourse(1337, "Course2");
    ASSERT_EQ(library.sciGetCourses(1337), vector<string>());
}

TEST(library, eduGetChangeCourse){
    Library library;
    EducationalBook* book = new EducationalBook(1337);
    library.addBook(1337, book);
    ASSERT_EQ(library.getType(1337), "Educational");
    library.eduChangeCourse(1337, "Course");
    ASSERT_EQ(library.eduGetCourse(1337), "Course");
}

TEST(library, eduGetSetGroups){
    Library library;
    EducationalBook* book = new EducationalBook(1337);
    library.addBook(1337, book);
    ASSERT_EQ(library.getType(1337), "Educational");
    library.eduSetGroups(1337, vector<string>({"group1", "group2"}));
    ASSERT_EQ(library.eduGetGroups(1337), vector<string>({"group1", "group2"}));
}

TEST(library, ficGetSetSubject){
    Library library;
    FictionBook* book = new FictionBook(1337);
    library.addBook(1337, book);
    ASSERT_EQ(library.getType(1337), "Fiction");
    library.ficSetSubject(1337, "Subject");
    ASSERT_EQ(library.ficGetSubject(1337), "Subject");
}