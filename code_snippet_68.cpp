static int adjust_bfregn(struct mlx5_ib_dev *dev,
			 struct mlx5_bfreg_info *bfregi, int bfregn)
{
	if (MLX5_NON_FP_BFREGS_PER_UAR == 0)
		return bfregn;

	return (bfregn + MLX5_NON_FP_BFREGS_PER_UAR - 1) /
		       MLX5_NON_FP_BFREGS_PER_UAR * MLX5_BFREGS_PER_UAR +
		       bfregn % MLX5_NON_FP_BFREGS_PER_UAR;
}