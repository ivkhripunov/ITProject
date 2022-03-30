#include <vector>


class Target {
public:
    std::vector<double> get_heading() const {
        return heading;
    }

    void set_parameters(std::vector<double> &new_parameters) {
        for (auto i = 0; i < parameters.size(); ++i) {
            parameters[i] = new_parameters[i];
        }
    };

    std::vector<double> get_parameters() const {
        return parameters;
    }

private:
    std::vector<double> heading;
    std::vector<double> parameters;
};
