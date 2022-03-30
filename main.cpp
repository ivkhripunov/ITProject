#include "Integrator.h"

int main() {

    Target *target = new Target;
    std::vector<double> new_parameters = {1000, 1000, 0, 0};
    target->set_parameters(new_parameters);

    std::vector<double> rocket_initial_parameters = {0, 0, 40, 40};
    Rocket rocket(rocket_initial_parameters, target);

    rocket.set_parameters(rocket_initial_parameters);

    std::ofstream output;
    output.open("parameters.txt");

    double step = 0.1;
    unsigned int number_of_steps = 100;
    bool flag = true;
    unsigned int counter = 0;

    while (counter < number_of_steps and flag) {
        output << rocket.get_parameters()[0] << " " << rocket.get_parameters()[1] << std::endl;
        flag = compute_step(rocket, rocket.get_parameters(), step, flag);
    }

    output.close();
    delete target;
}