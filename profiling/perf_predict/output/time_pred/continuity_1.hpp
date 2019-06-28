std::pair<std::string, double> continuity_1_seconds(int level, int degree)
{
    level -= 1;
    degree -= 2;

    double a = 0.0007142857142969099 * pow(level, 0) + -0.029238662131521206 * pow(level, 1) + 0.07351256613755185 * pow(level, 2) + -0.06756812169309442 * pow(level, 3) + 0.029793320105803718 * pow(level, 4) + -0.0067337962962919365 * pow(level, 5) + 0.0007417328042322673 * pow(level, 6) + -3.084845049128258e-05 * pow(level, 7);
    double b = 0.0008095238095531617 * pow(level, 0) + 0.248706235827687 * pow(level, 1) + -0.62255489417972 * pow(level, 2) + 0.5827789682536665 * pow(level, 3) + -0.26690707671939945 * pow(level, 4) + 0.0640986111110643 * pow(level, 5) + -0.007728505290999547 * pow(level, 6) + 0.00036856575963692076 * pow(level, 7);
    double c = 0.08942857142854671 * pow(level, 0) + 0.13050997732427363 * pow(level, 1) + -0.31292857142849384 * pow(level, 2) + 0.28143875661362094 * pow(level, 3) + -0.12453373015865067 * pow(level, 4) + 0.02907685185183087 * pow(level, 5) + -0.0034424603174577437 * pow(level, 6) + 0.00016489040060456653 * pow(level, 7);

    // return a * pow(degree, 2) + b * degree + c;

    return std::make_pair(
        "(Predicted for e36524bf4cb77630c6925ce1eafe4b50a146422c on Fri Jun 28 10:04:22 2019 -0400s)",
        a * pow(degree, 2) + b * degree + c
    );
}