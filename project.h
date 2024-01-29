#ifndef PROJECT_H
#define PROJECT_H
#include <string>
#include <vector>
#include <fstream>
#include "task.h"

class Project {
private:
    string name;
    bool data_loaded;
    vector<Task> tasks;
public:
    Project(string name) {
        this->name = name;
        this->data_loaded = false;
    }
    bool get_data_loaded() {
        return data_loaded;
    }
    void change_data_loaded() {
        data_loaded = true;
    }
    void add_task(Task task) {
        tasks.push_back(task);
    }
    Task& get_task(int index) {
        return tasks.at(index);
    }
    vector<Task>& get_tasks() {
        return tasks;
    }
    string get_name() {
        return name;
    }
    int get_num_tasks() {
        return tasks.size();
    }
    void remove_task(Task task) {
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (it->get_name() == task.get_name()) {
                tasks.erase(it);
                break;
            }
        }
    }
};
#endif