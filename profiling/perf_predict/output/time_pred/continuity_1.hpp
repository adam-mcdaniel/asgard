std::pair<std::string, double> continuity_1_seconds(int level, int degree)
{
    level -= 1;
    degree -= 2;

    double a = -0.0002380952380859905 * pow(level, 0) + -0.035349773242635045 * pow(level, 1) + 0.09371428571426567 * pow(level, 2) + -0.08728538359784697 * pow(level, 3) + 0.0386507936507719 * pow(level, 4) + -0.008752645502639739 * pow(level, 5) + 0.0009682539682532599 * pow(level, 6) + -4.0769085411909576e-05 * pow(level, 7);
    double b = 0.006619047618894539 * pow(level, 0) + 0.2622665532880151 * pow(level, 1) + -0.6774645502643597 * pow(level, 2) + 0.6375244047615735 * pow(level, 3) + -0.29181613756594393 * pow(level, 4) + 0.06985873015867915 * pow(level, 5) + -0.008385978835972582 * pow(level, 6) + 0.0003979308390019765 * pow(level, 7);
    double c = 0.09019047619044097 * pow(level, 0) + 0.13673854875284225 * pow(level, 1) + -0.3406288359787577 * pow(level, 2) + 0.30938941798927594 * pow(level, 3) + -0.13635582010573616 * pow(level, 4) + 0.03150767195764974 * pow(level, 5) + -0.003682010582007851 * pow(level, 6) + 0.00017388510959926806 * pow(level, 7);

    // return a * pow(degree, 2) + b * degree + c;

    return std::make_pair(
        "(Predicted for 4cf2e030fd1a2431953f590f38e4fee9afbca01d on Fri Jun 28 09:32:33 2019 -0400s)",
        a * pow(degree, 2) + b * degree + c
    );
}