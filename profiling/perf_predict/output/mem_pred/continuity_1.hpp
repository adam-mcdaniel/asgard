std::pair<std::string, double> continuity_1_MB(int level, int degree)
{
    level -= 1;
    degree -= 2;

    double a = 3.946132195762173e-09 * pow(level, 0) + 8.154993188789107e-24 * pow(level, 1) + -7.585886600460164e-24 * pow(level, 2) + 1.87860172219805e-24 * pow(level, 3) + 1.1856341531371155e-25 * pow(level, 4) + -5.238320898723651e-26 * pow(level, 5) + -9.371443067469329e-27 * pow(level, 6) + 1.968132067865863e-27 * pow(level, 7);
    double b = -1.0882269491854628e-08 * pow(level, 0) + 1.7579371828876308e-23 * pow(level, 1) + -1.7426060720976592e-23 * pow(level, 2) + 3.955338609021358e-24 * pow(level, 3) + 2.9450143191696667e-25 * pow(level, 4) + -1.0207643181616046e-25 * pow(level, 5) + -1.9857622443292985e-26 * pow(level, 6) + 3.604789261143792e-27 * pow(level, 7);
    double c = 105608115.99999991 * pow(level, 0) + 4.494411154838581e-08 * pow(level, 1) + -4.895657990389809e-08 * pow(level, 2) + 1.3888500797674574e-08 * pow(level, 3) + 6.448676690287368e-10 * pow(level, 4) + -4.288141619852069e-10 * pow(level, 5) + -6.802987754491843e-11 * pow(level, 6) + 1.7540753929703636e-11 * pow(level, 7);

    // return a * pow(degree, 2) + b * degree + c;

    return std::make_pair(
        "(Predicted for a3d18ed5f69eae6084a9380a8fe206ac6236987f on Tue Jun 25 16:42:21 2019 -0400s)",
        a * pow(degree, 2) + b * degree + c
    );
}