#include <vector>


class Target {
public:
    std::vector<double> get_heading() const {
        return heading;
    }

    void set_heading(std::vector<double> new_heading) {
        for (auto i = 0; i < heading.size(); ++i) {
            heading[i] = new_heading[i];
        }
    }

    void set_parameters(std::vector<double> new_parameters) {
        parameters.resize(4);
        for (auto i = 0; i < parameters.size(); ++i) {
            parameters[i] = new_parameters[i];
        }
    };

    std::vector<double> get_parameters() const {
        return parameters;
    }

    void move(double step) {
        parameters[0] += parameters[2] * step;
        parameters[1] += parameters[3] * step;
    }

private:
    std::vector<double> heading;
    std::vector<double> parameters;
};
