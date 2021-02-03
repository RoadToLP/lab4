//
// Created by Kurisu on 12/22/2020.
//

#include "ui.h"
#include <string>
#include "Book.h"
#include "ScientificBook.h"
#include "EducationalBook.h"
#include "FictionBook.hpp"
#include <iostream>
#include <vector>
#include <readline/readline.h>
#include <readline/history.h>
#include <sstream>
#include "tests.h"
#include <fmt/format.h>

Library ui::library;

void ui::finalize() {
    cout << "Goodbye!" << endl;
}

void ui::help(){
    cout << "- get current radius of circle\n"
            "setRadius [r] - set current radius of circle\n"
            "getDistance [theta] - get distance from center of circle to point of evolvent on current angle THETA\n"
            "getPoint [theta] - get point of evolvent on current angle THETA\n"
            "getLength [theta] - get length of curve up to current angle THETA\n"
            "getCurvature [theta] - get curvature of evolvent on current angle THETA\n"
            "exit - exit application\n"
            "runTests - run google test set\n";

}


void ui::init(){
    cout << "Welcome to library UI!" << endl;
}
void ui::init(const string& hellomsg){
    cout << hellomsg << endl;
}
vector<string> ui::getInput(){
    if (!cin){
        cin.clear();
        cin.sync();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    string input;
    char* cinput = readline("> ");
    input = string(cinput);
    if (!input.empty())
        add_history(cinput);
    free(cinput);
    vector<string> tokens; //Well, we can use dynamicArray
    stringstream sinput(input);
    string part;
    while(getline(sinput, part, ' ')){
        tokens.push_back(part);
    }
    return tokens;
}
int ui::decide(const vector<string>& command){
    if (command.size() > 1) {
        return ui::decideWA(command);
    } else if (command.size() == 1){
        return ui::decideWOA(command);
    }
    return 0;
}
int ui::decideWA(const vector<string>& command){
    if (command[0] == "createBook"){
        Book* book = nullptr;
        unsigned int article = stoul(command[2]);
        if (command[1] == "Edu"){
            book = new EducationalBook(article);
        } else if (command[1] == "Sci"){
            book = new ScientificBook(article);
        } else if (command[1] == "Fic"){
            book = new FictionBook(article);
        } else {
            cerr << "Unknown book type\n";
            return 0;
        }
        library.addBook(article, book);
    } else if (command[0] == "delBook") {
        library.delBook(stoul(command[1]));
    } else if (command[0] == "giveBook"){
        library.giveBook(stoul(command[1]));
    } else if (command[0] == "takeBook"){
        library.takeBook(stoul(command[1]));
    } else if (command[0] == "getType"){
        cout << library.getType(stoul(command[1])) << endl;
    } else if (command[0] == "getInfo"){
        cout << library.getInfo() << endl;
    } else if (command[0] == "changeQuantity"){
        library.setQuantity(stoul(command[1]), stoi(command[2]));
    } else if (command[0] == "saveTo"){
        library.saveTo(command[1]);
    } else if (command[0] == "loadFrom"){
        library.loadFrom(command[1]);
    } else if (command[0] == "getAuthor"){
        cout << library.getAuthor(stoul(command[1])) << endl;
    } else if (command[0] == "setAuthor"){
        library.setAuthor(stoul(command[1]), command[2]);
    } else if (command[0] == "getName"){
        cout << library.getName(stoul(command[1]));
    } else if (command[0] == "setName"){
        library.setName(stoul(command[1]), command[2]);
    } else if (command[0] == "getYear"){
        cout << library.getYear(stoul(command[1]));
    } else if (command[0] == "setYear"){
        library.setYear(stoul(command[1]), stoul(command[2]));
    } else if (command[0] == "getPublisher"){
        cout << library.getPublisher(stoul(command[1]));
    } else if (command[0] == "setPublisher"){
        library.setPublisher(stoul(command[1]), command[2]);
    } else if (command[0] == "getQuantity"){
        cout << library.getQuantity(stoul(command[1])) << endl;
    } else if (command[0] == "sciAddCourse"){
        library.sciAddCourse(stoul(command[1]), command[2]);
    } else if (command[0] == "sciDelCourse"){
        library.sciDelCourse(stoul(command[1]), command[2]);
    } else if (command[0] == "sciChangeCourse"){
        library.sciChangeCourse(stoul(command[1]), stoi(command[2]), command[3]);
    } else if (command[0] == "sciGetCourses"){
        fmt::print("{}\n", fmt::join(library.sciGetCourses(stoul(command[1])), ", "));
    } else if (command[0] == "eduGetCourse"){
        cout << library.eduGetCourse(stoul(command[1])) << endl;
    } else if (command[0] == "eduChangeCourse"){
        library.eduChangeCourse(stoul(command[1]), command[2]);
    } else if (command[0] == "eduGetGroups"){
        fmt::print("{}\n", fmt::join(library.eduGetGroups(stoul(command[1])), ", "));
    } else if (command[0] == "eduSetGroups"){
        library.eduSetGroups(stoul(command[1]), vector<string>(command.begin()+2, command.end()));
    } else if (command[0] == "ficGetSubject"){
        cout << library.ficGetSubject(stoul(command[1])) << endl;
    } else if (command[0] == "ficSetSubject"){
        library.ficSetSubject(stoul(command[1]), command[2]);
    } else if (command[0] == "runTests"){
        runTests();
    } else if (command[0] == "exit"){
        return 1;
    }
    return 0;
}
int ui::decideWOA(const vector<string>& command){
    return 0;
}

