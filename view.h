#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "project.h"
#include "task.h"

using namespace std;

class View {
public:
    void press_enter() {
        cout << "Press Enter to continue..." << endl;
        getchar();
    }
    void invalid_input() {
        cout << "Invalid input" << endl;
    }
    void print_projects(vector<Project>& projects) {
        cout << "Projects:" << endl;
        for (int i = 0; i < projects.size(); i++) {
            cout << i + 1 << ". " << projects.at(i).get_name() << endl;
        }
    }
    int input_project_index() {
        string input;
        cout << "Enter project index: ";
        getline(cin, input);
        return stoi(input);
    }
    void print_project_details(Project& project) {
        cout << "Project: " << project.get_name() << endl;
        cout << "Tasks:" << endl;
        for (int i = 0; i < project.get_tasks().size(); i++) {
            Task task = project.get_task(i);
            cout << i + 1 << ". " << task.get_name() << " (" << task.get_status_string() << ")" << endl;
        }
    }
    int input_task_index() {
        string input;
        cout << "Enter task index: ";
        getline(cin, input);
        return stoi(input);
    }
    Project input_project_name() {
        string name;
        cout << "Enter project name: ";
        getline(cin, name);
        return Project(name);
    }
    Task input_task() {
        string name;
        cout << "Enter task name: ";
        getline(cin, name);
        return Task(name);
    }
    void error() {
        cout << "ERROR! Probably, some of the data was not saved to the file" << endl;
    }
    void save_info() {
        cout << "(the data will be saved in a file after quitting)\n" << endl;
    }
    void save_info_back() {
        cout << "(the data will be saved in a file after go back)\n" << endl;
    }
    void print_menu() {
        cout << "Enter 'p' to print projects, "
            << "or 't' to view project tasks, "
            << "or 'n' to create a new project, "
            << "or 'd' to delete a project, "
            << "or 'q' to quit: ";
    }
    void print_project_menu(Project& project) {
        cout << "Enter 'n' to create a new task, "
            << "or 'c' to change a task status, "
            << "or 'r' to remove a task, "
            << "or 'p' to print tasks, "
            << "or 'b' to go back: ";
    }
};
#endif