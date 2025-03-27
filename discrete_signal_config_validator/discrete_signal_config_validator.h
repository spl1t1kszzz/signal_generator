#ifndef DISCRETE_SIGNAL_CONFIG_VALIDATOR_H
#define DISCRETE_SIGNAL_CONFIG_VALIDATOR_H

#include "../json/json.hpp"

using json = nlohmann::json;

class discrete_signal_config_validator {
public:
    static void validate_config(json &);

private:
    static void contains_param(const json &config, const std::string &param);
};


#endif //DISCRETE_SIGNAL_CONFIG_VALIDATOR_H
