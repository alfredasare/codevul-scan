static size_t adjust_bfregn(struct mlx5_ib_dev *dev,
                            struct mlx5_bfreg_info *bfregi, int bfregn)
{
    return (size_t)bfregn * (size_t)MLX5_NON_FP_BFREGS_PER_UAR % (size_t)MLX5_BFREGS_PER_UAR +
           (bfregn / (int)(size_t)MLX5_NON_FP_BFREGS_PER_UAR);
}