//
// Created by Kurisu on 1/31/2021.
//

#ifndef LAB4_FICTIONBOOK_HPP
#define LAB4_FICTIONBOOK_HPP

#include "Book.h"
/*!
 * \brief Fiction book class
 * \author KuriGohan_And_Kamehameha
 * \version 1.0
 * \date 03.02.2021
 */
class FictionBook : public virtual Book{
private:
    string subject; ///< Subject of a book
public:
    FictionBook(const string &author, const string &name, const int &year, const string &publisher, const int &quantity, const string &subject, const unsigned int &article); //!< Constructor with full information provided.
    explicit FictionBook(const unsigned int &article);//!< Constructor with full information provided.
    const string & getSubject() const; //!< Returns subject of a book;
    void setSubject(const string &subject); //!< Changes subject of a book;
    string getInfo() const override;//!< See Book class definition
    string getType() const override;//!< See Book class definition
    string getSaveInfo() const override;//!< See Book class definition
    void loadInfo(string data) override;//!< See Book class definition
};


#endif //LAB4_FICTIONBOOK_HPP
