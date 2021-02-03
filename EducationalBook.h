//
// Created by Kurisu on 1/28/2021.
//

#ifndef LAB4_EDUCATIONALBOOK_H
#define LAB4_EDUCATIONALBOOK_H
#include "Book.h"
#include <vector>

/*!
 * \brief Educational book class
 * \author KuriGohan_And_Kamehameha
 * \version 1.0
 * \date 03.02.2021
 */
class EducationalBook : public virtual Book{
private:
    string course; ///< Course that uses this book. Course is like "Linear algebra", "Physics", etc...
    vector<string> groups; ///< Groups that use this book. Up to 8 groups can use one book.
public:
    explicit EducationalBook(const unsigned int &article); //!< Constructor that only fills article. Other fields will be filled with default values.

    EducationalBook(const string &author, const string &name, const int &year, const string &publisher, const int &quantity, const string &course, const vector<string> &groups, const unsigned int &article); //!< Constructor with full information provided.
    const string & getCourse() const; //!< Returns course that uses this book
    void changeCourse(const string &course); //!< Changes course that uses this book
    string getInfo() const override; //!< See Book class definition
    string getType() const override;//!< See Book class definition

    string getSaveInfo() const override;//!< See Book class definition

    void loadInfo(string data) override;//!< See Book class definition

    const vector<string> &getGroups() const; //!< Returns vector of groups that use this book.

    void setGroups(const vector<string> &groups); //!< Sets groups that use this book.
    /// \throws invalid_argument if groups.size() > 8. However, you can bypass this limitation if you are loading file that was manually edited.
};



#endif //LAB4_EDUCATIONALBOOK_H
