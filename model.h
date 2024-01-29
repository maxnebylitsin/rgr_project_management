#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "project.h"

using namespace std;

class Model {
private:
    vector<Project> projects;
    vector<Task> tasks;
public:
    void create_project(Project project) {
        projects.push_back(project);
        ofstream file(project.get_name() + ".txt");
        if (!file) {
                cout << "Error, project has not created!\n\n"; 
        }
        else {
                cout << "Project created\n\n";
        }
        file.close();
    }
    void delete_project(Project project, int index) {
        auto iter = projects.cbegin();
        projects.erase(iter + index);
        string filename = project.get_name() + ".txt";
        if (remove(filename.c_str()) != 0) {
            cout << "Error deleting project" << endl;
        } else {
            cout << "Project deleted" << endl;
        }
    }
    Project& get_project(int index) {
        return projects.at(index);
    }
    vector<Project>& get_projects() {
        return projects;
    }
    void create_task(Project& project, Task& task) {
        project.add_task(task);
        ofstream file(project.get_name() + ".txt", std::ios::app);
        for (int i = project.get_tasks().size() - 1; i < project.get_tasks().size(); i++) {
            Task task = project.get_task(i);
            cout << i + 1 << ". " << task.get_name() << " (" << task.get_status_string() << ")" << endl;
        }
        file.close();
    }
    void change_status(Project& project, int index) {
        project.get_task(index);
    }
    void load_data() {
        ifstream file("projects.txt");
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                projects.push_back(line);
            }
        } else {
            cout << "ERROR! THE DATA HAS NOT BEEN LOADED" << endl;
        }
        file.close();
    }
    void save_data() {
        ofstream file("projects.txt");
        if (file.is_open()) {
            for (int i = 0; i < projects.size(); i++) {
                file << projects.at(i).get_name() << endl;
            }
        }
        else {
            cout << "ERROR! THE DATA HAS BEEN DELETED" << endl;
        }
        file.close();
    }
    void load_project_data(Project& project) {
        ifstream file(project.get_name() + ".txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                int task_num;
                string task_name, status_str;
                if (sscanf(line.c_str(), "%d. ", &task_num) != 1) {
                    continue;
                }
                size_t name_start = line.find_first_not_of(" ", line.find(". ") + 2);
                size_t name_end = line.find(" (", name_start);
                task_name = line.substr(name_start, name_end - name_start);
                bool status = (line.substr(name_end + 2, 4) == "done");
                project.add_task(task_name);
                project.get_tasks().back().set_status(status);
            }
        } else {
            cout << "ERROR! THE PROJECT DATA HAS NOT BEEN LOADED" << endl;
        }
        file.close();
    }
    void save_project_data(Project& project) {
        ofstream file(project.get_name() + ".txt");
        if (file) {
            for (int i = 0; i < project.get_num_tasks(); i++) {
                Task& task = project.get_task(i);
                string status_str = task.get_status() ? "done" : "not done";
                file << i + 1 << ". " << task.get_name() << " (" << status_str << ")\n";
            }
        } else {
            cout << "ERROR! THE PROJECT DATA HAS BEEN DELETED" << endl;
        }
    }
};
#endif