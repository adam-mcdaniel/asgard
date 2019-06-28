std::pair<std::string, double> continuity_1_MB(int level, int degree)
{
    level -= 1;
    degree -= 2;

    double a = 0.14285714276419165 * pow(level, 0) + 274.0576530623862 * pow(level, 1) + -668.3053571446568 * pow(level, 2) + 611.0962301599266 * pow(level, 3) + -274.0937500004095 * pow(level, 4) + 64.52390873023452 * pow(level, 5) + -7.636607142864356 * pow(level, 6) + 0.35792233560118314 * pow(level, 7);
    double b = 0.2285714290112808 * pow(level, 0) + -842.0398979626392 * pow(level, 1) + 2046.6461507990243 * pow(level, 2) + -1862.0926984162859 * pow(level, 3) + 829.1409722234531 * pow(level, 4) + -193.13049603197453 * pow(level, 5) + 22.505734127005923 * pow(level, 6) + -1.0297647392298612 * pow(level, 7);
    double c = 110.88571428568802 * pow(level, 0) + 86.07911564668555 * pow(level, 1) + -213.40293650858524 * pow(level, 2) + 200.05690476233144 * pow(level, 3) + -92.95972222236665 * pow(level, 4) + 22.98559523812167 * pow(level, 5) + -2.90876984127233 * pow(level, 6) + 0.14981292517016234 * pow(level, 7);

    // return a * pow(degree, 2) + b * degree + c;

    return std::make_pair(
        "(Predicted for 39299fe631070fb552186cd250af6bc3ac122a34 on Thu Jun 27 16:02:36 2019 -0400s)",
        a * pow(degree, 2) + b * degree + c
    );
}