//
// Created by Kurisu on 1/31/2021.
//


#ifndef LAB4_LIBRARY_HPP
#define LAB4_LIBRARY_HPP
using namespace std;
#include <map>
#include "Book.h"
#include "ScientificBook.h"
#include "EducationalBook.h"
#include "FictionBook.hpp"
/*!
  \brief Library class
  \author KuriGohan_And_Kamehameha
  \version 1.0
  \date 03.02.2021
*/
/**
  \brief
  It's highly recommended to use this class, if you are running full library as a proxy to books itself<br>
  As a proxy, it provides nearly full r/w access to a bookshelf, except pointers to a book<br>
  Almost every function requires an article as a FIRST argument<br>
  Some of this functions were defined and described earlier. Names of functions are identical, but some of them have prefixes.<br>
  If function starts with "edu" that means that function will work only with Educational books and will throw invalid_argument if book with this article is not Educational<br>
  If function starts with "sci" that means that function will work only with Scientific books<br>
  "fic" means it takes only Fiction books<br>
  Other functions are common and applicable to any type of book.<br>
 */
class Library {
private:
    vector<pair<unsigned int, Book*>> db; ///< Database that contains pairs: article of a book and pointer to a book
    [[nodiscard]] Book* getBook(unsigned int article) const; //!< Function that returns pointer to a book. This function is private, because there is no need to get pointer to a book, since proxy functions are available
    void normalize(); //!< Function that sorts db in a ascending article order. No need to call this function outside of class, because this function is called after each write to db
public:
    ~Library(); //!< Destructor that has purpose to free all objects in the vector
    Library(); //!< Constructor of a library
    void saveTo(const string& filename); //!< Saves library to file
    void loadFrom(const string& filename); //!< loads library from file
    /// \throws invalid_argument if save file is broken. It happens if you are manually edit a file and make a mistake (I CONDEMN THIS)
    void addBook(unsigned int article, Book* book); //!< Adds book to a library
    void delBook(unsigned int article); //!< Delete book from library
    void giveBook(unsigned int article); //!< Simulates giving book to a student. That means that quantity will decrease by one
    void takeBook(unsigned int article); //!< Simulates taking book from a student. That means that quantity will increase by one
    [[nodiscard]] string getType(unsigned int article) const;
    [[nodiscard]] string getInfo() const;
    [[nodiscard]] const string &getAuthor(unsigned int article) const;
    void setAuthor(unsigned int article, const string &author);
    [[nodiscard]] const string &getName(unsigned int article) const;
    void setName(unsigned int article, const string &name);
    [[nodiscard]] unsigned short getYear(unsigned int article) const;
    void setYear(unsigned int article, unsigned short year);
    [[nodiscard]] const string &getPublisher(unsigned int article) const;
    void setPublisher(unsigned int article, const string &publisher);
    void setQuantity(unsigned int article, int q);
    [[nodiscard]] const unsigned int& getQuantity(unsigned int article);
    void sciAddCourse(unsigned int article, const string& course);
    void sciDelCourse(unsigned int article, const string& course);
    void sciChangeCourse(unsigned int article, const int &index, const string &course);
    [[nodiscard]] const vector<string> & sciGetCourses(unsigned int article) const;
    [[nodiscard]] const string& eduGetCourse(unsigned int article) const;
    void eduChangeCourse(unsigned int article, const string& course);
    [[nodiscard]] const vector<string>& eduGetGroups(unsigned int article) const;
    void eduSetGroups(unsigned int article, const vector<string>& groups);
    [[nodiscard]] const string& ficGetSubject(unsigned int article);
    void ficSetSubject(unsigned int article, const string& subject);
};


#endif //LAB4_LIBRARY_HPP
