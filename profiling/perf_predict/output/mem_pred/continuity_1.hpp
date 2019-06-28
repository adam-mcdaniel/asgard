std::pair<std::string, double> continuity_1_MB(int level, int degree)
{
    level -= 1;
    degree -= 2;

    double a = 1.723216780481756e-15 * pow(level, 0) + -3.721070445873867e-30 * pow(level, 1) + 5.2943997329371216e-30 * pow(level, 2) + -3.3538431132029754e-30 * pow(level, 3) + 1.1458188012960076e-30 * pow(level, 4) + -2.173981939902864e-31 * pow(level, 5) + 2.1549871456723113e-32 * pow(level, 6) + -8.695226987772814e-34 * pow(level, 7);
    double b = -1.5567211377889586e-14 * pow(level, 0) + -2.3534833010409408e-29 * pow(level, 1) + 2.987878590942589e-29 * pow(level, 2) + -1.8275256728734803e-29 * pow(level, 3) + 6.397831667728237e-30 * pow(level, 4) + -1.2663300636675568e-30 * pow(level, 5) + 1.2853875414869416e-31 * pow(level, 6) + -5.128058875681482e-33 * pow(level, 7);
    double c = 111.00000000000003 * pow(level, 0) + -5.2725499390621e-13 * pow(level, 1) + 1.0584685100344708e-12 * pow(level, 2) + -8.13144226418498e-13 * pow(level, 3) + 3.089991620474767e-13 * pow(level, 4) + -6.189393570649567e-14 * pow(level, 5) + 6.2561015066003745e-15 * pow(level, 6) + -2.5129409084378203e-16 * pow(level, 7);

    // return a * pow(degree, 2) + b * degree + c;

    return std::make_pair(
        "(Predicted for 4cf2e030fd1a2431953f590f38e4fee9afbca01d on Fri Jun 28 09:32:33 2019 -0400s)",
        a * pow(degree, 2) + b * degree + c
    );
}