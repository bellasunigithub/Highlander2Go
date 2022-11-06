#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "CourseSched.h"

using namespace std;

CourseSchedule::CourseSchedule(): head(nullptr), tail(nullptr){
}

CourseScheduleItem::CourseScheduleItem(string courseName, string classroomGiven){
    this->course = courseName;
    this->classroom = classroomGiven;
    this->coordinate = "no coordinate";
    this->rating = "no rating";
    this->next = nullptr;
}

void CourseSchedule::showRating(string courseName){
    //find course and its rating if no rating
    CourseScheduleItem* node = head;

    while(node != nullptr){
        if(node->getName() == courseName){
            cout << node->getRating() << endl;
        }
    }
}

string CourseSchedule::getCoordinate(string courseName){
    CourseScheduleItem* node = head;

    while(node != nullptr){
        if(node->getName() == courseName){
            return node->findCoordinate(node->getName());
        }
    }
}
string CourseScheduleItem::findCoordinate(string name){
    ifstream inFS;
    inFS.open("classrooms.txt");
    if(!inFS.is_open()){
        cout << "error opening coordinate file" << endl;
        exit(1);
    }
    string classroom;
    while(getline(inFS, classroom)){
        if(classroom == name){
            getline(cin, classroom);
            return classroom;
        }
    }
    return "nothing";
}

void CourseSchedule::addCourse(CourseScheduleItem* newClass)
{
    CourseScheduleItem* node = head;

    if (node == nullptr)
    {
        head = newClass;
        tail = newClass;
    }
    else 
    {
        tail->setNext(newClass);
    }
    
}
