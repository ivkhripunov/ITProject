#include <vector>
#include <cmath>
#include "Target.h"

class Rocket {
public:
    Rocket(std::vector<double> &new_parameters, Target *target) {
        //test!
        set_parameters(new_parameters);
        set_target(target);
        gas_outflow_speed = 4000;
        fuel_consumption = 10;
        Cx_coeff = 0.4;
        area = 0.15;
        initial_mass = 100;
        current_mass = 715;
        hit_radius = 30;

    }

    double get_initial_mass() const {
        return initial_mass;
    }

    double get_Cx_coeff() const {
        return Cx_coeff;
    }

    std::vector<double> get_heading() const {
        return heading;
    }

    void set_heading(std::vector<double> new_heading) {
        for (auto i = 0; i < heading.size(); ++i) {
            heading[i] = new_heading[i];
        }
    }

    double get_area() const {
        return area;
    }

    double get_fuel_consumption() const {
        return fuel_consumption;
    }

    double get_gas_outflow_speed() const {
        return gas_outflow_speed;
    }

    double get_current_mass() const {
        return current_mass;
    }

    void set_current_mass(double new_mass) {
        current_mass = new_mass;
    }

    void set_parameters(std::vector<double> new_parameters) {
        parameters.resize(4);
        for (auto i = 0; i < parameters.size(); ++i) {
            parameters[i] = new_parameters[i];
        }
    }

    std::vector<double> get_parameters() const {
        return parameters;
    }

    Target *get_target() const {
        return target;
    }

    void set_target(Target *new_target) {
        target = new_target;
    }

    double get_hit_radius() const {
        return hit_radius;
    }


protected:
    std::vector<double> parameters; // [x, y, vx, vy]
    std::vector<double> heading; // вектор должен быть единичным!
    double gas_outflow_speed;
    double fuel_consumption;
    double Cx_coeff;
    double area;
    double hit_radius;
    double initial_mass;
    double current_mass;
    Target *target;

};
