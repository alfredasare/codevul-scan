static void cassignop2(JF, js_Ast *lhs, int postfix)
{
	switch (lhs->type) {
	case EXP_IDENTIFIER:
		emitline(J, F, lhs);
		if (postfix) emit(J, F, OP_ROT2);
		if (lhs->v.id->val == NULL) {
			jsC_error(J, lhs, "invalid l-value in assignment: null pointer");
			return;
		}
		emitlocal(J, F, OP_SETLOCAL, OP_SETVAR, lhs);
		break;
	case EXP_INDEX:
		emitline(J, F, lhs);
		if (postfix) emit(J, F, OP_ROT4);
		if (lhs->v.index->rhs == NULL) {
			jsC_error(J, lhs, "invalid r-value in assignment: null pointer");
			return;
		}
		emit(J, F, OP_SETPROP);
		break;
	case EXP_MEMBER:
		emitline(J, F, lhs);
		if (postfix) emit(J, F, OP_ROT3);
		if (lhs->v.member->rhs == NULL || lhs->v.member->str == NULL) {
			jsC_error(J, lhs, "invalid r-value in assignment: null pointer");
			return;
		}
		emitstring(J, F, OP_SETPROP_S, lhs->v.member->str);
		break;
	default:
		jsC_error(J, lhs, "invalid l-value in assignment");
	}
}