#include <iostream>
#include <array>

// Function to calculate the mean compressibility factor (2 GASES ONLY)
double mean_comp_factor(const std::array<double, 2>& y_vec, const std::array<double, 2>& Z_vec) {
    return y_vec[0] * Z_vec[0] + y_vec[1] * Z_vec[1];
}

double partial_pressure(double P, double y_i, double Z_i, double Z_m) {
    // std::cout << "Partial pressure of component: " << P * y_i * Z_i / Z_m << std::endl;
    return P * y_i * Z_i / Z_m;
}

int main () {
    // define constant variables
    const double n_hex = 3.0 /86.0;
    const double n_co2 = 3.0 /44.0;
    const double y_hex = n_hex/(n_hex + n_co2);
    const double y_co2 = n_co2/(n_hex + n_co2);
    const double T_cr_hex = 507.6; // K
    const double T_cr_co2 = 304.2; // K
    const double P_cr_hex = 3.03;  // Mpa
    const double P_cr_co2 = 7.39;  // Mpa

    const double R = 8.314; // kJ / kmol*K
    const double T = 548;   // K
    const double P = 5;  // Mpa

    // First Iteration Guesses
    double z_hex = 1.0;
    double z_co2 = 1.0;

    // First Iteration Calculations
    // Find mean compressibility factor and partial pressures of each gas
    double Z_m = mean_comp_factor({y_hex, y_co2}, {z_hex, z_co2});
    double P_hex = partial_pressure(P, y_hex, z_hex, Z_m);
    double P_co2 = partial_pressure(P, y_co2, z_co2, Z_m);

    // Find relative temperature and pressure of each gas
    double T_r_hex = T / T_cr_hex;
    double P_r_hex = P_hex / P_cr_hex;

    double T_r_co2 = T / T_cr_co2;
    double P_r_co2 = P_co2 / P_cr_co2;

    // First Iteration print results
    std::cout << "=== First Iteration ===" << std::endl;
    std::cout << "             Z_m: " << Z_m << std::endl;
    std::cout << "T/T_cr    Hexane: " << T_r_hex << std::endl;
    std::cout << "P_i/P_cr  Hexane: " << P_r_hex << std::endl;
    std::cout << "T/T_cr       CO2: " << T_r_co2 << std::endl;
    std::cout << "P_i/P_cr     CO2: " << P_r_co2 << std::endl;

    // Use charts to find all Z_i to find new Z_m.
    z_hex = 0.845;
    z_co2 = 0.98;

    // Second Iteration
    Z_m = mean_comp_factor({y_hex, y_co2}, {z_hex, z_co2});
    P_hex = partial_pressure(P, y_hex, z_hex, Z_m);
    P_co2 = partial_pressure(P, y_co2, z_co2, Z_m);

    // Find relative temperature and pressure of each gas
    T_r_hex = T / T_cr_hex;
    P_r_hex = P_hex / P_cr_hex;

    T_r_co2 = T / T_cr_co2;
    P_r_co2 = P_co2 / P_cr_co2;

    // Second Iteration print results
    std::cout << "=== Second Iteration ===" << std::endl;
    std::cout << "             Z_m: " << Z_m << std::endl;
    std::cout << "T/T_cr    Hexane: " << T_r_hex << std::endl;
    std::cout << "P_i/P_cr  Hexane: " << P_r_hex << std::endl;
    std::cout << "T/T_cr       CO2: " << T_r_co2 << std::endl;
    std::cout << "P_i/P_cr     CO2: " << P_r_co2 << std::endl;


}