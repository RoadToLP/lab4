//
// Created by Kurisu on 1/28/2021.
//
#include <string>
#ifndef LAB4_BOOK_H
#define LAB4_BOOK_H
using namespace std;

/*!
    \brief Abstract Book class
    \author KuriGohan_And_Kamehameha
    \version 1.0
    \date 03.02.2021
*/
class Book {
protected:
    string author; ///< Author of a book
    string name; ///< Title of a book
    unsigned short year; ///< Release year
    string publisher; ///< Publisher company
    unsigned int quantity; ///< Quantity in a library now
    unsigned int article; ///< Article (or cipher) of a book
public:
    virtual ~Book() = default; //!< Destructor. What else can i write on 00:48AM
    virtual string getInfo() const = 0; //!< Pure virtual function. Returns overall information about the book, depending on it's type
    virtual string getType() const = 0; //!< Pure virtual function. Returns book type as a string, which can be "Educational", "Scientific" or "Fiction"
    virtual string getSaveInfo() const = 0; //!< Pure virtual function. Returns string of book data(all fields), separated by 0xff char. This function is used in saving/loading databases. loadInfo will consume this string to fill book's information
    virtual void loadInfo(string data) = 0; //!< Pure virtual function. Loads book data from input. data is generated from getSaveInfo().
    const unsigned int& getQuantity() const; //!< Returns number of books in a library now.
    void setQuantity(int q); //!< Sets current number of books
/// \param[in] q - new quantity
    unsigned int getArticle() const; //!< Returns an article of a book
    const string &getAuthor() const; //!< Returns an author of a book
    void setAuthor(const string &author); //!< Sets an author of a book
    const string &getName() const; //!< Returns title of a book
    void setName(const string &name); //!< Sets title of a book
    unsigned short getYear() const; //!< Returns release year
    void setYear(unsigned short year); //!< Sets release year
    const string &getPublisher() const; //!< Returns publisher company of a book
    void setPublisher(const string &publisher); //!< Sets publisher company of a book
};


#endif //LAB4_BOOK_H
