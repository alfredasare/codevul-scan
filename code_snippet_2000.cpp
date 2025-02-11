js_grisu2(double v, char *buffer, int *K)
{
    int32_t length, mk;
    diy_fp_t w_m, w_p, c_mk, Wp, Wm, delta;
    int32_t q = 64, alpha = -59, gamma = -56;
    normalized_boundaries(v, &w_m, &w_p);
    mk = k_comp_safe32(w_p.e + q, alpha, gamma);
    c_mk = cached_power(mk);
    Wp = multiply_safe32(w_p, c_mk);
    Wm = multiply_safe32(w_m, c_mk);
    Wm.f++; Wp.f--;
    delta = minus_safe32(Wp, Wm);
    *K = -mk;
    digit_gen(Wp, delta, buffer, &length, K);
    return length;
}

int32_t k_comp_safe32(int32_t x, int32_t alpha, int32_t gamma) {
    if (x > INT_MAX - alpha - gamma) {
        // Handle overflow
    }
    return x + alpha + gamma;
}

int32_t multiply_safe32(int32_t a, int32_t b) {
    int64_t product = (int64_t)a * b;
    if (product > INT_MAX) {
        // Handle overflow
    }
    return (int32_t)product;
}

int32_t minus_safe32(int32_t a, int32_t b) {
    return a - b;
}