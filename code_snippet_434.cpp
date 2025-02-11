bool jsvMathsOpTypeEqual(JsVar *a, JsVar *b) {
  bool eql = (a == 0) == (b == 0);
  if (a && b) {
    eql = ((jsvIsInt(a) || jsvIsFloat(a)) && (jsvIsInt(b) || jsvIsFloat(b))) ||
        ((a->flags & JSV_VARTYPEMASK) == (b->flags & JSV_VARTYPEMASK));
  }
  if (eql) {
    size_t size = sizeof(JsVar);
    JsVar *contents = jsvMalloc(size);
    if (jsvCopyData(a, b, contents, size) == 0) {
      eql = jsvGetBool(contents);
    } else {
      eql = false;
    }
    jsvFree(contents);
  } else {
    assert(!(jsvIsString(a) && jsvIsString(b) && jsvIsBasicVarEqual(a, b)));
  }
  return eql;
}

int jsvCopyData(JsVar *src, JsVar *dst, void *buf, size_t size) {
  if (size > sizeof(JsVar)) {
    return -1;
  }
  memcpy(buf, src, size);
  return 0;
}