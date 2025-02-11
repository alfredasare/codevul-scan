static void calc_matrix(double mat[4][4], const double *const mat_freq, const int *const index)
{
    if (!mat_freq ||!index) {
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (!mat[i]) { // Check for null pointer dereference
            return;
        }
        if (i >= 4 || index[i] >= 4 || mat_freq || mat_freq[2 * index[i]] >= 4 || mat_freq[0] >= 4 || mat_freq[index[i]] >= 4 || mat_freq[index[i] + index[j]] >= 4 || mat_freq[index[j] - index[i]] >= 4) {
            return;
        }
        mat[i][i] = mat_freq[2 * index[i]] + 3 * mat_freq[0] - 4 * mat_freq[index[i]];
        for (int j = i + 1; j < 4; ++j)
            mat[i][j] = mat[j][i] = 
                mat_freq[index[i] + index[j]] + mat_freq[index[j] - index[i]] + 
                2 * (mat_freq[0] - mat_freq[index[i]] - mat_freq[index[j]]);
    }

    for (int k = 0; k < 4; ++k) {
        int ip = k, jp = k;  // pivot
        double z = 1.0 / mat[ip][jp];
        mat[ip][jp] = 1.0;
        for (int i = 0; i < 4; ++i) {
            if (i == ip)
                continue;

            double mul = mat[i][jp] * z;
            mat[i][jp] = 0.0;
            for (int j = 0; j < 4; ++j)
                mat[i][j] -= mat[ip][j] * mul;
        }
        for (int j = 0; j < 4; ++j)
            mat[ip][j] *= z;
    }
}