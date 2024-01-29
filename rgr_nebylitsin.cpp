#include <iostream>
#include "controller.h"

int main() {
    Model model;
    View view;
    Controller controller(model, view);
    controller.run();
    return 0;
}