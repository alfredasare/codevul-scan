bool jsvMathsOpTypeEqual(JsVar \*a, JsVar \*b) {
bool eql = (a==0) == (b==0);
if (a && b) {
int64_t intA, intB;
if (jsvIsInt(a)) {
intA = jsvIntValue(a);
} else if (jsvIsFloat(a)) {
intA = (int64_t)jsvFloatValue(a);
} else {
intA = 0;
}

if (jsvIsInt(b)) {
intB = jsvIntValue(b);
} else if (jsvIsFloat(b)) {
intB = (int64_t)jsvFloatValue(b);
} else {
intB = 0;
}

eql = (intA == intB);
}
if (eql) {
JsVar \*contents = jsvMathsOp(a,b, LEX\_EQUAL);
if (!jsvGetBool(contents)) eql = false;
jsvUnLock(contents);
} else {
assert(!(jsvIsString(a) && jsvIsString(b) && jsvIsBasicVarEqual(a,b)));
}
return eql;
}