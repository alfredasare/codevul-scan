12 < ay)
{
/* |dx| <<< |dy| means a near-vertical segment */
result = ( dy >= 0 ) ? PSH\_DIR\_UP : PSH\_DIR\_DOWN;
}

return result;
}
}

Note: Error handling (e.g., returning an appropriate value or logging the error) should be added in the specified locations to make the function more robust and secure.