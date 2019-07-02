std::pair<std::string, double> continuity_1_seconds(int level, int degree)
{
    level -= 1;
    degree -= 2;

    double a = 0.0038095238095341133 * pow(level, 0) + -0.08262698412699455 * pow(level, 1) + 0.19790013227508016 * pow(level, 2) + -0.18379794973535843 * pow(level, 3) + 0.08380291005285642 * pow(level, 4) + -0.019896164021149857 * pow(level, 5) + 0.0023445767195749813 * pow(level, 6) + -0.000107473544973464 * pow(level, 7);
    double b = -0.014571428571374093 * pow(level, 0) + 0.44862857142862866 * pow(level, 1) + -1.0906588624335474 * pow(level, 2) + 1.026133002644954 * pow(level, 3) + -0.4751977513224296 * pow(level, 4) + 0.1152828042327193 * pow(level, 5) + -0.014000529100518681 * pow(level, 6) + 0.0006699074074069222 * pow(level, 7);
    double c = 0.10495238095235772 * pow(level, 0) + 0.09753492063492541 * pow(level, 1) + -0.2680904761904279 * pow(level, 2) + 0.23582632275123164 * pow(level, 3) + -0.09871825396819961 * pow(level, 4) + 0.021668783068768627 * pow(level, 5) + -0.0024293650793633013 * pow(level, 6) + 0.00011283068783060484 * pow(level, 7);

    // return a * pow(degree, 2) + b * degree + c;

    return std::make_pair(
        "(Predicted for ad99a1d84abe38598e498b63f17f9ed047d2aa7b on Fri Jun 28 10:22:38 2019 -0400s)",
        a * pow(degree, 2) + b * degree + c
    );
}