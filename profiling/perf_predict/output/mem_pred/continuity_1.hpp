std::pair<std::string, double> continuity_1_MB(int level, int degree)
{
    level -= 1;
    degree -= 2;

    double a = 2.3624668436557314e-18 * pow(level, 0) + -5.0947256857088135e-33 * pow(level, 1) + 1.2438181357129858e-32 * pow(level, 2) + -1.0328242347003378e-32 * pow(level, 3) + 4.068119815536962e-33 * pow(level, 4) + -8.281375456266318e-34 * pow(level, 5) + 8.436031976036194e-35 * pow(level, 6) + -3.409460385412153e-36 * pow(level, 7);
    double b = 2.533725810203384e-18 * pow(level, 0) + 3.4303943714477074e-33 * pow(level, 1) + -5.155525836224445e-33 * pow(level, 2) + 3.859861246024403e-33 * pow(level, 3) + -1.5879966167580422e-33 * pow(level, 4) + 3.57254575253434e-34 * pow(level, 5) + -4.0477496684330553e-35 * pow(level, 6) + 1.786792246451683e-36 * pow(level, 7);
    double c = 0.07483999999999999 * pow(level, 0) + 1.618584254855161e-16 * pow(level, 1) + -3.4939891503692383e-16 * pow(level, 2) + 2.6775400236209216e-16 * pow(level, 3) + -1.0230701637316097e-16 * pow(level, 4) + 2.078035741085156e-17 * pow(level, 5) + -2.132170577214802e-18 * pow(level, 6) + 8.667677436490747e-20 * pow(level, 7);

    // return a * pow(degree, 2) + b * degree + c;

    return std::make_pair(
        "(Predicted for ad99a1d84abe38598e498b63f17f9ed047d2aa7b on Fri Jun 28 10:22:38 2019 -0400s)",
        a * pow(degree, 2) + b * degree + c
    );
}