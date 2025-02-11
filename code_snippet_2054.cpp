NO_INLINE JsVar *jspePostfixExpression() {
  JsVar *a;
  if (lex->tk == LEX_PLUSPLUS || lex->tk == LEX_MINUSMINUS) {
    int op = lex->tk;
    JSP_ASSERT_MATCH(op);
    a = jspePostfixExpression();
    if (JSP_SHOULD_EXECUTE) {
      JsVar *one = jsvNewFromInteger(1);
      JsVar *res = jsvMathsOpSkipNames(a, one, op == LEX_PLUSPLUS ? '+' : '-');
      JsVar *utf8Res = jsvConvertToUTF8(res);
      JsVar *latin1Res = jsvConvertToLatin1(res);
      jsvUnLock(utf8Res);
      jsvUnLock(latin1Res);
      jsvReplaceWith(a, utf8Res);
      jsvReplaceWith(a, latin1Res);
    }
  } else
    a = jspeFactorFunctionCall();
  return __jspePostfixExpression(a);
}