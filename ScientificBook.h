//
// Created by Kurisu on 1/28/2021.
//

#ifndef LAB4_SCIENTIFICBOOK_H
#define LAB4_SCIENTIFICBOOK_H
#include "Book.h"
#include <vector>
/*!
 * \brief Scientific book class
 * \author KuriGohan_And_Kamehameha
 * \version 1.0
 * \date 03.02.2021
 */
class ScientificBook : public virtual Book{
private:
    vector<string> courses; ///< Courses that use this book
public:
    const vector<string> & getCourses() const; //!< Returns vector of courses that use this book
    ScientificBook(const string &author, const string &name, const int &year, const string &publisher, const int &quantity, const vector<string> &courses, const unsigned int &article); //!< Constructor with full information provided.
    explicit ScientificBook(const unsigned int &article);//!< Constructor that only fills article. Other fields will be filled with default values.
    void addCourse(const string& course); //!< Adds new course to vector
    /// \throws invalid_argument if courses are full, specifically, if it has 3 or more members. However, you can bypass this limitation if you are loading file that was manually edited.
    void delCourse(const string& course); //!< Deletes course from vector
    /// \throws out_of_range if courses.size() == 0. DOES NOTHING IF COURSE DOESN'T EXIST IN A LIST.
    void changeCourse(const int &index, const string &course);//!< Changes course that uses this book. Index starts with 0, can take up to 2.
    /// \throws invalid_argument when index is out of range, or default limitation of 3 groups exceeded. Groups that have index >= 3 (which can be achieved when editing file) are read/delete only, unless you delete other courses.
    string getInfo() const override;//!< See Book class definition
    string getType() const override;//!< See Book class definition
    string getSaveInfo() const override;//!< See Book class definition
    void loadInfo(string data) override;//!< See Book class definition
};


#endif //LAB4_SCIENTIFICBOOK_H
