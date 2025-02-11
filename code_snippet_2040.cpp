int js_toint32(js_State *J, int idx)
{
    js_number num = jsV_tonumber(J, stackidx(J, idx));
    if (jsNumberIsInteger(num) && jsNumberGetDouble(num) <= INT32_MAX && jsNumberGetDouble(num) >= INT32_MIN) {
        return jsNumberToInt32(num);
    } else {
        // Handle the error or limit the maximum value
        return 0; // or any other appropriate error handling
    }
}