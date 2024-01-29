#include <iostream>
#include <fstream>
#include "model.h"
#include "view.h"

using namespace std;

class Controller {
private: 
    Model& model;
    View& view;
public:
    Controller(Model& model, View& view) : model(model), view(view) {}
    void run() {
        model.load_data();
        while (true) {
            try {
                view.save_info();
                view.print_menu();
                string choice;
                getline(cin, choice);
                if (choice == "p") {
                    view.print_projects(model.get_projects());
                    view.press_enter();
                } else if (choice == "n") {
                    Project project = view.input_project_name();
                    model.create_project(project);
                    view.press_enter();
                } else if (choice == "d") {
                    int index = view.input_project_index() - 1;
                    Project project = model.get_project(index);
                    model.delete_project(project, index);
                    view.press_enter();
                } else if (choice == "q") {
                    model.save_data();
                    break;
                } else if (choice == "t") {
                    int index = view.input_project_index() - 1;
                    Project& project = model.get_project(index);
                    if (!project.get_data_loaded()) {
                        project.change_data_loaded();
                        model.load_project_data(project);
                    }
                    view.print_project_details(project);
                    view.press_enter();
                    while (true) {
                        view.save_info_back();
                        view.print_project_menu(project);
                        getline(cin, choice);
                        if (choice == "n") {
                            Project& project = model.get_project(index);
                            Task task = view.input_task();
                            model.create_task(project, task);
                            view.press_enter();
                        } else if (choice == "c") {
                                index = view.input_task_index() - 1;
                                Task& task = project.get_task(index);
                                task.change_status(task.get_status());
                                view.press_enter();
                        } else if (choice == "r") {
                                index = view.input_task_index() - 1;
                                Task& task = project.get_task(index);
                                project.remove_task(task);
                                view.press_enter();
                        } else if (choice == "p") {
                            view.print_project_details(project);
                            view.press_enter();
                        } else if (choice == "b") {
                            model.save_project_data(project);
                            view.press_enter();
                            break;
                        }
                    }
                }
            } catch (...) {
                view.invalid_input();
                view.error();
                view.press_enter();              
            }
        }
    }
};