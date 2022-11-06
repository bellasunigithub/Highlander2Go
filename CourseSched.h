#ifndef COURSESCHED_H
#define COURSESCHED_H

#include <string>
using namespace std;

class CourseScheduleItem {
    private:
    string course;
    string classroom;
    string coordinate;
    string rating;

    CourseScheduleItem* next;
    
    public:
    CourseScheduleItem() {
        this->course = "no course";
        this->classroom = "no classroom";
        this->coordinate = "none";
        this->next = nullptr;
    }
    CourseScheduleItem(string courseName, string classroomGiven);
    string itemRating(){
        return rating;
    }
    string getName(){
        return course;
    }
    string getRating(){
        return rating;
    }
    string findCoordinate(string);
    void setNext(CourseScheduleItem* node){
        next = node;
    }
};

class CourseSchedule{
    private:
    CourseScheduleItem* head = nullptr;
    CourseScheduleItem* tail = nullptr;

    public:
    CourseSchedule();
    //~CourseSchedule();
    void addCourse(CourseScheduleItem* newClass);
    void generateCoordinate(string courseName);
    void showRating(string);
    //void setRating(string)
    string getCoordinate(string);
};

#endif