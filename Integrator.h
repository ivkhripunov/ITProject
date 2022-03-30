#include "Vector.h"
#include "Rockets.h"

// константы
const double g = 9.81;
const double height_max = 9000; // высота в метрах, на которой плотность воздуха падает в е раз
const double rho_max = 1.2; //плотность воздуха на высоте уровня моря

double calc_rho(const double &height) {
    return rho_max * exp(-height / height_max);
}

std::vector<double> compute_heading(Rocket &rocket) {
    auto vector_difference = rocket.get_parameters() - rocket.get_target()->get_parameters();
    std::vector<double> result(2);
    result[0] = vector_difference[0];
    result[1] = vector_difference[1];

    return result / vector_length(result);
}

// вычисление ускорение на каждом шаге для двумерки parameters = [x, y, vx, vy]
std::vector<double>
compute_acceleration(Rocket &rocket, const std::vector<double> &parameters) {
    rocket.set_heading(compute_heading(rocket));
    std::vector<double> coordinates = std::vector<double>(parameters.begin(), parameters.begin() + 1);
    std::vector<double> speed = std::vector<double>(parameters.begin() + 2, parameters.end());

    std::vector<double> acceleration_air =
            -0.5 * rocket.get_Cx_coeff() * calc_rho(coordinates[1]) * rocket.get_area() *
            vector_length(speed) * speed;

    std::vector<double> acceleration_g = {0, -g};


    std::vector<double> acceleration_fuel = {0, 0};
    rocket.get_fuel_consumption() * rocket.get_gas_outflow_speed() / rocket.get_current_mass() *
    rocket.get_heading();

    return sum_of_three_vectors(acceleration_air, acceleration_fuel, acceleration_g);

}

// вычисление приращения для двумерки, возвращает массив [dx, dx, dvx, dvy]
std::vector<double>
compute_differential(Rocket &rocket, const std::vector<double> &parameters) {
    std::vector<double> acceleration = compute_acceleration(rocket, parameters);
    std::vector<double> differential;
    differential.resize(4);
    differential[0] = parameters[2];
    differential[1] = parameters[3];
    differential[2] = acceleration[0];
    differential[3] = acceleration[1];

    return differential;
}

bool hit_control(Rocket &rocket, bool &flag) {
    if (rocket.get_parameters()[1] < 0) flag = false;
    if (vector_length(rocket.get_parameters() - rocket.get_target()->get_parameters()) <= rocket.get_hit_radius())
        flag = false;

    return flag;
}

// делаем шаг по времени
bool
compute_step(Rocket &rocket, const std::vector<double> &parameters, const double &step, bool &flag) {
    hit_control(rocket, flag);
    std::vector<double> k_1 = compute_differential(rocket, parameters);
    std::vector<double> k_2 = compute_differential(rocket, parameters + 0.5 * step * k_1);
    std::vector<double> k_3 = compute_differential(rocket, parameters + 0.5 * step * k_2);
    std::vector<double> k_4 = compute_differential(rocket, parameters + step * k_3);

    rocket.set_current_mass(rocket.get_current_mass() - rocket.get_fuel_consumption() * step);
    rocket.set_parameters(parameters + sum_of_three_vectors(k_1, 2 * (k_2 + k_3), k_4) * step / 6);

    return flag;
}

