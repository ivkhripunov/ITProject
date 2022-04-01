#include "Integrator.h"

int main() {

    Target *target = new Target;
    std::vector<double> new_parameters = {1000, 1000, 20, -10};
    target->set_parameters(new_parameters);

    std::vector<double> rocket_initial_parameters = {0, 0, 40, 40};
    Rocket rocket(rocket_initial_parameters, target);

    rocket.set_parameters(rocket_initial_parameters);

    std::ofstream output;
    output.open("parameters.txt");

    double step = 0.1;
    unsigned int number_of_steps = 1e5;
    bool flag = true;
    unsigned int counter = 0;

    while (counter <= number_of_steps and flag) {
        output << rocket.get_parameters()[0] << " " << rocket.get_parameters()[1] << " "
               << target->get_parameters()[0] << " " << target->get_parameters()[1] << " " << counter * step
               << std::endl;
        flag = compute_step(rocket, rocket.get_parameters(), step, flag);
        rocket.get_target()->move(step);
        counter += 1;
    }

    output.close();
    delete target;

    std::system("python3 /home/ivankhripunov/CLionProjects/ITproject/rocket_graph.py");

}