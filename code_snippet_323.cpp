#define PROJECT_X_DX_MIN -1000
#define PROJECT_X_DX_MAX 1000

FT_Pos Project_x(FT_Exec_Operation  op, FT_Pos  dx, FT_Pos  dy) {
    if (dx < PROJECT_X_DX_MIN || dx > PROJECT_X_DX_MAX) {
        return FT_Err_Invalid_Argument;
    }

    FT_UNUSED_EXEC;
    FT_UNUSED(dy);

    return dx;
}