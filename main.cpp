#include <iostream>
#include <string>

#include "CourseSched.h"
using namespace std;

//log in includes netid
//button for choosing a course then its direction
//

void menu() {

}

int main(){
    CourseSchedule schedule;

    char input;
    string netID;
    cout << "Login: ";
    cin >> netID;
    cout << endl<< "Receiving input from site..." << endl;

    while (input != 'e'){
        cout << endl << "Select an option:" << endl;
        cout << "CREATE SCHEDULE - enter a" << endl;
        cout << "WHERE IS MY CLASS? - enter b" << endl;
        cout << "CHECK RATING - enter c" << endl;
        cout << "ADD RATING - enter d" << endl;
        cout << "QUIT - enter e" << endl;

        cin >> input;
        cin.ignore();

        if (input == 'a'){
            cout << "How many course are you taking?" << endl;
            int numOfCourses;
            cin >> numOfCourses;
            cin.ignore();

            int i = 0;

            while(i < numOfCourses){

                string course;
                cout << "Course name: ";
                getline(cin, course);

                string location;
                cout << "Course location: ";
                getline(cin, location);

                CourseScheduleItem* Class = new CourseScheduleItem(course,location);
                schedule.addCourse(Class);
                ++i;

            }

        } else if (input == 'b'){

            string course;
            cout << "Which course are you trying to go to?" << endl;
            getline(cin, course);

            cout << schedule.getCoordinate(course) << endl;

        } else if(input == 'c'){

            string course;
            cout << "Which course's rating do you want to see?" << endl;
            getline(cin, course);

            schedule.showRating(course);

        } else if(input == 'd'){

            string course;
            cout << "Which course's rating do you want to add to?" << endl;
            getline(cin, course);

            // schedule.setRating(course);
        }
    }

    return 0;
}

/*examples: Winston Chung Hall 127 coordinates: 33°58'31.0"N 117°19'33.3"W
https://goo.gl/maps/DzGEanGMEUdERqW38 */