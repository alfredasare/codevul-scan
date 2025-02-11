void event_change_size(RenderState* state, double delta)
{
    double char_size = state->char_size;

    if (delta < 0 || delta > (300.0 - state->char_size)) {
        printf("Invalid delta value: %f\n");
        return;
    }

    char_size += delta;
    char_size = fmin(fmax(char_size, 6.0), 300.0);

    render_state_set_size(state, char_size);
}