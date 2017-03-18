#include <iostream>
#include "tools.h"
using namespace std;
Tools::Tools() {
}

Tools::~Tools() {
}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
        const vector<VectorXd> &ground_truth) {
    if (estimations.size() == 0 || estimations.size() != ground_truth.size()) {
            throw std::invalid_argument( "CalculateRMSE () - Error: Invalid input values." );
        }

        VectorXd rmse(estimations[0].array().size());
        rmse.fill(0.0d);

        for (int i = 0; i < estimations.size(); ++i) {
            VectorXd res = estimations[i] - ground_truth[i];
            res = res.array() * res.array();
            rmse += res;
        }

        rmse /= estimations.size();
        rmse = rmse.array().sqrt();

        return rmse;
}


