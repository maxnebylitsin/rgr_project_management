#ifndef TASK_H
#define TASK_H
#include <string>

using namespace std;

class Task {
private:
    string name;
    bool status;
public:
    Task(string name) {
        this->name = name;
        status = false;
    }
    void set_status(bool status) {
        this->status = status;
    }
    void change_status(bool status) {
        this->status = !status;
    }
    bool get_status() {
        return status;
    }
    string get_status_string() {
        if (status) {
            return "done";
        } else {
            return "not done";
        }
    }
    string get_name() {
        return name;
    }
};
#endif