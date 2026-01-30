/*
 * Code for class LOGISTIC_REGRESSION_MODEL
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern void F19_335(EIF_REFERENCE);
extern EIF_TYPED_VALUE F19_336(EIF_REFERENCE);
extern EIF_TYPED_VALUE F19_337(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F19_338(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F19_339(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F19_340(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F19_341(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F19_342(EIF_REFERENCE);
extern EIF_TYPED_VALUE F19_343(EIF_REFERENCE);
extern EIF_TYPED_VALUE F19_344(EIF_REFERENCE);
extern EIF_TYPED_VALUE F19_345(EIF_REFERENCE);
extern EIF_TYPED_VALUE F19_346(EIF_REFERENCE);
extern EIF_TYPED_VALUE F19_347(EIF_REFERENCE);
extern void F19_6778(EIF_REFERENCE, int);
extern void EIF_Minit19(void);

#ifdef __cplusplus
}
#endif

#include "eif_helpers.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* {LOGISTIC_REGRESSION_MODEL}.make */
void F19_335 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "make";
	RTEX;
	EIF_REFERENCE tr1 = NULL;
	EIF_BOOLEAN tb1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(2);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLIU(2);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 18, Current, 0, 0, 341);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(18, Current, 341);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 341, 0x04000000, 1); /* is_trained */
	*(EIF_BOOLEAN *)(Current + RTWA(341, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN) 0;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 345, 0x20000000, 1); /* learning_rate */
	*(EIF_REAL_64 *)(Current + RTWA(345, dtype)) = (EIF_REAL_64) (EIF_REAL_64) 0.01;
	RTHOOK(3);
	RTDBGAA(Current, dtype, 346, 0x10000000, 1); /* max_iterations */
	*(EIF_INTEGER_32 *)(Current + RTWA(346, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 100L);
	RTHOOK(4);
	RTDBGAA(Current, dtype, 342, 0xF80001EF, 0); /* weights */
	tr1 = RTLNSMART(RTWCT(342, dtype, Dftype(Current)).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(3164, Dtype(tr1)))(tr1);
	RTNHOOK(4,1);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(342, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(5);
	RTDBGAA(Current, dtype, 344, 0xF8000179, 0); /* classes */
	tr1 = RTLNSMART(RTWCT(344, dtype, Dftype(Current)).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(3164, Dtype(tr1)))(tr1);
	RTNHOOK(5,1);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(344, dtype)) = (EIF_REFERENCE) tr1;
	if (RTAL & CK_ENSURE) {
		RTHOOK(6);
		RTCT("not_trained", EX_POST);
		tb1 = *(EIF_BOOLEAN *)(Current + RTWA(341, dtype));
		if ((EIF_BOOLEAN) !tb1) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(7);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
}

/* {LOGISTIC_REGRESSION_MODEL}.classes_learned */
EIF_TYPED_VALUE F19_336 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "classes_learned";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE up2x = {{0}, SK_POINTER};
#define up2 up2x.it_p
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_BOOLEAN tb1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(5);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLR(2,Result);
	RTLR(3,loc1);
	RTLR(4,tr2);
	RTLIU(5);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	
	RTEAA(l_feature_name, 18, Current, 1, 0, 342);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(18, Current, 342);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(0, 0xF80003C5, 0,0); /* Result */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,965,224,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		tr1 = RTLN(typres0.id);
	}
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(32, Dtype(tr1)))(tr1);
	RTNHOOK(1,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(2);
	tb1 = *(EIF_BOOLEAN *)(Current + RTWA(341, dtype));
	if (tb1) {
		RTHOOK(3);
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(344, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		tr2 = ((up2x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2758, "new_cursor", tr1))(tr1)), (((up2x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up2x.it_r = RTBU(up2x))), (up2x.type = SK_POINTER), up2x.it_r);
		loc1 = (EIF_REFERENCE) RTCCL(tr2);
		for (;;) {
			tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2707, "after", loc1))(loc1)).it_b);
			if (tb1) break;
			RTHOOK(4);
			RTDBGAL(0, 0xF80003C5, 0,0); /* Result */
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc1))(loc1)).it_i4);
			ti4_2 = ti4_1;
			ui4_1 = ti4_2;
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(760, "extended", Result))(Result, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			Result = (EIF_REFERENCE) RTCCL(tr1);
			RTHOOK(5);
			(FUNCTION_CAST(void, (EIF_REFERENCE)) RTVF(2708, "forth", loc1))(loc1);
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(6);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef up2
#undef ui4_1
}

/* {LOGISTIC_REGRESSION_MODEL}.set_learning_rate */
EIF_TYPED_VALUE F19_337 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "set_learning_rate";
	RTEX;
#define arg1 arg1x.it_r8
	EIF_REAL_64 tr8_1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_r8 = * (EIF_REAL_64 *) arg1x.it_r;
	
	RTLI(2);
	RTLR(0,Current);
	RTLR(1,Result);
	RTLIU(2);
	RTLU (SK_REF, &Result);
	RTLU(SK_REAL64,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 18, Current, 0, 1, 343);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(18, Current, 343);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("positive_rate", EX_PRE);
		RTTE((EIF_BOOLEAN) eif_is_greater_real_64 (arg1, (EIF_REAL_64) 0.0), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 345, 0x20000000, 1); /* learning_rate */
	*(EIF_REAL_64 *)(Current + RTWA(345, dtype)) = (EIF_REAL_64) arg1;
	RTHOOK(3);
	RTDBGAL(0, 0xF8000012, 0,0); /* Result */
	Result = (EIF_REFERENCE) RTCCL(Current);
	if (RTAL & CK_ENSURE) {
		RTHOOK(4);
		RTCT("rate_set", EX_POST);
		tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(345, dtype));
		if ((EIF_BOOLEAN) eif_is_equal_real_64 (tr8_1, arg1)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(5);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef arg1
}

/* {LOGISTIC_REGRESSION_MODEL}.set_max_iterations */
EIF_TYPED_VALUE F19_338 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "set_max_iterations";
	RTEX;
#define arg1 arg1x.it_i4
	EIF_INTEGER_32 ti4_1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(2);
	RTLR(0,Current);
	RTLR(1,Result);
	RTLIU(2);
	RTLU (SK_REF, &Result);
	RTLU(SK_INT32,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 18, Current, 0, 1, 344);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(18, Current, 344);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("positive_max", EX_PRE);
		RTTE((EIF_BOOLEAN) (arg1 > ((EIF_INTEGER_32) 0L)), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 346, 0x10000000, 1); /* max_iterations */
	*(EIF_INTEGER_32 *)(Current + RTWA(346, dtype)) = (EIF_INTEGER_32) arg1;
	RTHOOK(3);
	RTDBGAL(0, 0xF8000012, 0,0); /* Result */
	Result = (EIF_REFERENCE) RTCCL(Current);
	if (RTAL & CK_ENSURE) {
		RTHOOK(4);
		RTCT("max_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(346, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg1)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(5);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef arg1
}

/* {LOGISTIC_REGRESSION_MODEL}.train */
void F19_339 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "train";
	RTEX;
	EIF_INTEGER_32 loc1 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
	EIF_REFERENCE loc3 = (EIF_REFERENCE) 0;
	EIF_INTEGER_32 loc4 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc5 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc6 = (EIF_INTEGER_32) 0;
	EIF_REAL_64 loc7 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc8 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc9 = (EIF_REAL_64) 0;
	EIF_REFERENCE loc10 = (EIF_REFERENCE) 0;
	EIF_REAL_64 loc11 = (EIF_REAL_64) 0;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE up2x = {{0}, SK_POINTER};
#define up2 up2x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur8_1x = {{0}, SK_REAL64};
#define ur8_1 ur8_1x.it_r8
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_REAL_64 tr8_3;
	EIF_REAL_64 tr8_4;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_INTEGER_32 ti4_4;
	EIF_INTEGER_32 ti4_5;
	EIF_BOOLEAN tb1;
	RTCFDT;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(8);
	RTLR(0,arg1);
	RTLR(1,arg2);
	RTLR(2,tr1);
	RTLR(3,Current);
	RTLR(4,loc3);
	RTLR(5,tr2);
	RTLR(6,ur1);
	RTLR(7,loc10);
	RTLIU(8);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU(SK_REF,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_INT32, &loc1);
	RTLU(SK_INT32, &loc2);
	RTLU(SK_REF, &loc3);
	RTLU(SK_INT32, &loc4);
	RTLU(SK_INT32, &loc5);
	RTLU(SK_INT32, &loc6);
	RTLU(SK_REAL64, &loc7);
	RTLU(SK_REAL64, &loc8);
	RTLU(SK_REAL64, &loc9);
	RTLU(SK_REF, &loc10);
	RTLU(SK_REAL64, &loc11);
	
	RTEAA(l_feature_name, 18, Current, 11, 2, 345);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(18, Current, 345);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,352,0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		RTCC(arg1, 18, l_feature_name, 1, typres0, 0x01);
	}
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,377,224,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		RTCC(arg2, 18, l_feature_name, 2, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("x_valid", EX_PRE);
		tb1 = '\0';
		if ((EIF_BOOLEAN)(arg1 != NULL)) {
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
			tb1 = (EIF_BOOLEAN) (ti4_1 > ((EIF_INTEGER_32) 0L));
		}
		RTTE(tb1, label_1);
		RTCK;
		RTHOOK(2);
		RTCT("y_valid", EX_PRE);
		tb1 = '\0';
		if ((EIF_BOOLEAN)(arg2 != NULL)) {
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg2))(arg2)).it_i4);
			tb1 = (EIF_BOOLEAN) (ti4_1 > ((EIF_INTEGER_32) 0L));
		}
		RTTE(tb1, label_1);
		RTCK;
		RTHOOK(3);
		RTCT("same_length", EX_PRE);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg2))(arg2)).it_i4);
		RTTE((EIF_BOOLEAN)(ti4_1 == ti4_2), label_1);
		RTCK;
		RTHOOK(4);
		RTCT("x_not_empty", EX_PRE);
		ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
		ui4_1 = ti4_1;
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", tr1))(tr1)).it_i4);
		RTTE((EIF_BOOLEAN) (ti4_1 > ((EIF_INTEGER_32) 0L)), label_1);
		RTCK;
		RTHOOK(5);
		RTCT("learning_rate_set", EX_PRE);
		tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(345, dtype));
		RTTE((EIF_BOOLEAN) eif_is_greater_real_64 (tr8_1, (EIF_REAL_64) 0.0), label_1);
		RTCK;
		RTHOOK(6);
		RTCT("max_iterations_set", EX_PRE);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(346, dtype));
		RTTE((EIF_BOOLEAN) (ti4_1 > ((EIF_INTEGER_32) 0L)), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(7);
	RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
	ui4_1 = ti4_1;
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", tr1))(tr1)).it_i4);
	loc1 = (EIF_INTEGER_32) ti4_1;
	RTHOOK(8);
	RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	loc2 = (EIF_INTEGER_32) ti4_1;
	RTHOOK(9);
	RTDBGAL(3, 0xF8000174, 0, 0); /* loc3 */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,372,224,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLN(typres0.id);
	}
	ui4_1 = ((EIF_INTEGER_32) 2L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(3452, Dtype(tr1)))(tr1, ui4_1x);
	RTNHOOK(9,1);
	loc3 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(10);
	RTDBGAL(5, 0x10000000, 1, 0); /* loc5 */
	ti4_1 = *(EIF_INTEGER_32 *)(arg2 + RTVA(3201, "lower", arg2));
	loc5 = (EIF_INTEGER_32) ti4_1;
	for (;;) {
		RTHOOK(11);
		ti4_1 = *(EIF_INTEGER_32 *)(arg2 + RTVA(3200, "upper", arg2));
		if ((EIF_BOOLEAN) (loc5 > ti4_1)) break;
		RTHOOK(12);
		ui4_1 = loc5;
		ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg2))(arg2, ui4_1x)).it_i4);
		ui4_1 = ti4_2;
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2853, "has", loc3))(loc3, ui4_1x)).it_b);
		if ((EIF_BOOLEAN) !tb1) {
			RTHOOK(13);
			ui4_1 = loc5;
			ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg2))(arg2, ui4_1x)).it_i4);
			ui4_1 = ti4_2;
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2884, "extend", loc3))(loc3, ui4_1x);
		}
		RTHOOK(14);
		RTDBGAL(5, 0x10000000, 1, 0); /* loc5 */
		loc5++;
	}
	RTHOOK(15);
	RTDBGAA(Current, dtype, 344, 0xF8000179, 0); /* classes */
	tr1 = RTLNSMART(RTWCT(344, dtype, dftype).id);
	tr2 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(3457, "to_array", loc3))(loc3)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ur1 = RTCCL(tr2);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(3167, Dtype(tr1)))(tr1, ur1x);
	RTNHOOK(15,1);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(344, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(16);
	RTDBGAA(Current, dtype, 342, 0xF80001EF, 0); /* weights */
	tr1 = RTLNSMART(RTWCT(342, dtype, dftype).id);
	ur8_1 = (EIF_REAL_64) 0.0;
	ui4_1 = ((EIF_INTEGER_32) 1L);
	ui4_2 = loc1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWC(3165, Dtype(tr1)))(tr1, ur8_1x, ui4_1x, ui4_2x);
	RTNHOOK(16,1);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(342, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(17);
	RTDBGAA(Current, dtype, 343, 0x20000000, 1); /* bias */
	*(EIF_REAL_64 *)(Current + RTWA(343, dtype)) = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	RTHOOK(18);
	RTDBGAL(4, 0x10000000, 1, 0); /* loc4 */
	loc4 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 1L);
	for (;;) {
		RTHOOK(19);
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(346, dtype));
		if ((EIF_BOOLEAN) (loc4 > ti4_2)) break;
		RTHOOK(20);
		RTDBGAL(10, 0xF80001EF, 0, 0); /* loc10 */
		{
			static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
			EIF_TYPE typres0;
			static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
			
			typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
			tr1 = RTLN(typres0.id);
		}
		ur8_1 = (EIF_REAL_64) 0.0;
		ui4_1 = ((EIF_INTEGER_32) 1L);
		ui4_2 = loc1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWC(3165, Dtype(tr1)))(tr1, ur8_1x, ui4_1x, ui4_2x);
		RTNHOOK(20,1);
		loc10 = (EIF_REFERENCE) RTCCL(tr1);
		RTHOOK(21);
		RTDBGAL(11, 0x20000000, 1, 0); /* loc11 */
		loc11 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
		RTHOOK(22);
		RTDBGAL(5, 0x10000000, 1, 0); /* loc5 */
		ti4_3 = *(EIF_INTEGER_32 *)(arg2 + RTVA(3201, "lower", arg2));
		loc5 = (EIF_INTEGER_32) ti4_3;
		for (;;) {
			RTHOOK(23);
			ti4_3 = *(EIF_INTEGER_32 *)(arg2 + RTVA(3200, "upper", arg2));
			if ((EIF_BOOLEAN) (loc5 > ti4_3)) break;
			RTHOOK(24);
			RTDBGAL(7, 0x20000000, 1, 0); /* loc7 */
			tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(343, dtype));
			loc7 = (EIF_REAL_64) tr8_1;
			RTHOOK(25);
			RTDBGAL(6, 0x10000000, 1, 0); /* loc6 */
			loc6 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 1L);
			for (;;) {
				RTHOOK(26);
				if ((EIF_BOOLEAN) (loc6 > loc1)) break;
				RTHOOK(27);
				RTDBGAL(7, 0x20000000, 1, 0); /* loc7 */
				ui4_1 = loc5;
				tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
				ui4_1 = loc6;
				tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", tr1))(tr1, ui4_1x)).it_r8);
				tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(342, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
				RTNHOOK(27,1);
				ui4_1 = loc6;
				tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", tr1))(tr1, ui4_1x)).it_r8);
				loc7 += (EIF_REAL_64) (tr8_1 * tr8_2);
				RTHOOK(28);
				RTDBGAL(6, 0x10000000, 1, 0); /* loc6 */
				loc6++;
			}
			RTHOOK(29);
			if ((EIF_BOOLEAN) eif_is_greater_real_64 (loc7, (EIF_REAL_64) 5.0)) {
				RTHOOK(30);
				RTDBGAL(8, 0x20000000, 1, 0); /* loc8 */
				loc8 = (EIF_REAL_64) (EIF_REAL_64) 1.0;
			} else {
				RTHOOK(31);
				if ((EIF_BOOLEAN) eif_is_less_real_64 (loc7, (EIF_REAL_64) -5.0)) {
					RTHOOK(32);
					RTDBGAL(8, 0x20000000, 1, 0); /* loc8 */
					loc8 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
				} else {
					RTHOOK(33);
					RTDBGAL(8, 0x20000000, 1, 0); /* loc8 */
					loc8 = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) 0.5 + (EIF_REAL_64) ((EIF_REAL_64) 0.125 * loc7));
				}
			}
			RTHOOK(34);
			ui4_1 = loc5;
			ti4_4 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg2))(arg2, ui4_1x)).it_i4);
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(344, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			RTNHOOK(34,1);
			tr2 = ((up2x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(344, dtype))(Current)), (((up2x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up2x.it_r = RTBU(up2x))), (up2x.type = SK_POINTER), up2x.it_r);
			RTNHOOK(34,2);
			ti4_5 = *(EIF_INTEGER_32 *)(tr2 + RTVA(3201, "lower", tr2));
			ui4_1 = ti4_5;
			ti4_5 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", tr1))(tr1, ui4_1x)).it_i4);
			if ((EIF_BOOLEAN)(ti4_4 == ti4_5)) {
				RTHOOK(35);
				RTDBGAL(9, 0x20000000, 1, 0); /* loc9 */
				loc9 = (EIF_REAL_64) (EIF_REAL_64) (loc8 - (EIF_REAL_64) 0.0);
			} else {
				RTHOOK(36);
				RTDBGAL(9, 0x20000000, 1, 0); /* loc9 */
				loc9 = (EIF_REAL_64) (EIF_REAL_64) (loc8 - (EIF_REAL_64) 1.0);
			}
			RTHOOK(37);
			RTDBGAL(6, 0x10000000, 1, 0); /* loc6 */
			loc6 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 1L);
			for (;;) {
				RTHOOK(38);
				if ((EIF_BOOLEAN) (loc6 > loc1)) break;
				RTHOOK(39);
				ui4_1 = loc6;
				tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", loc10))(loc10, ui4_1x)).it_r8);
				ui4_1 = loc5;
				tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
				ui4_1 = loc6;
				tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", tr1))(tr1, ui4_1x)).it_r8);
				ur8_1 = (EIF_REAL_64) (tr8_1 + (EIF_REAL_64) (loc9 * tr8_2));
				ui4_1 = loc6;
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(2894, "put", loc10))(loc10, ur8_1x, ui4_1x);
				RTHOOK(40);
				RTDBGAL(6, 0x10000000, 1, 0); /* loc6 */
				loc6++;
			}
			RTHOOK(41);
			RTDBGAL(11, 0x20000000, 1, 0); /* loc11 */
			loc11 += loc9;
			RTHOOK(42);
			RTDBGAL(5, 0x10000000, 1, 0); /* loc5 */
			loc5++;
		}
		RTHOOK(43);
		RTDBGAL(6, 0x10000000, 1, 0); /* loc6 */
		loc6 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 1L);
		for (;;) {
			RTHOOK(44);
			if ((EIF_BOOLEAN) (loc6 > loc1)) break;
			RTHOOK(45);
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(342, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			RTNHOOK(45,1);
			tr2 = ((up2x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(342, dtype))(Current)), (((up2x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up2x.it_r = RTBU(up2x))), (up2x.type = SK_POINTER), up2x.it_r);
			RTNHOOK(45,2);
			ui4_1 = loc6;
			tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", tr2))(tr2, ui4_1x)).it_r8);
			tr8_2 = *(EIF_REAL_64 *)(Current + RTWA(345, dtype));
			ui4_1 = loc6;
			tr8_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", loc10))(loc10, ui4_1x)).it_r8);
			tr8_4 = (EIF_REAL_64) (loc2);
			ur8_1 = (EIF_REAL_64) (tr8_1 - (EIF_REAL_64) (tr8_2 * (EIF_REAL_64) ((EIF_REAL_64) (tr8_3) /  (EIF_REAL_64) (tr8_4))));
			ui4_1 = loc6;
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(2894, "put", tr1))(tr1, ur8_1x, ui4_1x);
			RTHOOK(46);
			RTDBGAL(6, 0x10000000, 1, 0); /* loc6 */
			loc6++;
		}
		RTHOOK(47);
		RTDBGAA(Current, dtype, 343, 0x20000000, 1); /* bias */
		tr8_2 = *(EIF_REAL_64 *)(Current + RTWA(345, dtype));
		tr8_3 = (EIF_REAL_64) (loc2);
		(*(EIF_REAL_64 *)(Current + RTWA(343, dtype))) -= (EIF_REAL_64) (tr8_2 * (EIF_REAL_64) ((EIF_REAL_64) (loc11) /  (EIF_REAL_64) (tr8_3)));
		RTHOOK(48);
		RTDBGAL(4, 0x10000000, 1, 0); /* loc4 */
		loc4++;
	}
	RTHOOK(49);
	RTDBGAA(Current, dtype, 341, 0x04000000, 1); /* is_trained */
	*(EIF_BOOLEAN *)(Current + RTWA(341, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
	if (RTAL & CK_ENSURE) {
		RTHOOK(50);
		RTCT("is_trained", EX_POST);
		tb1 = *(EIF_BOOLEAN *)(Current + RTWA(341, dtype));
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(51);
		RTCT("weights_initialized", EX_POST);
		tb1 = '\0';
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(342, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		if ((EIF_BOOLEAN)(tr1 != NULL)) {
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(342, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			RTNHOOK(51,1);
			ti4_4 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", tr1))(tr1)).it_i4);
			ti4_5 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
			ui4_1 = ti4_5;
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			ti4_5 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", tr1))(tr1)).it_i4);
			tb1 = (EIF_BOOLEAN)(ti4_4 == ti4_5);
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(52);
		RTCT("classes_learned_valid", EX_POST);
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(335, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		RTNHOOK(52,1);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(752, "is_empty", tr1))(tr1)).it_b);
		if ((EIF_BOOLEAN) !tb1) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(53);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(15);
	RTEE;
#undef up1
#undef up2
#undef ur1
#undef ur8_1
#undef ui4_1
#undef ui4_2
#undef arg2
#undef arg1
}

/* {LOGISTIC_REGRESSION_MODEL}.predict */
EIF_TYPED_VALUE F19_340 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "predict";
	RTEX;
	EIF_REAL_64 loc1 = (EIF_REAL_64) 0;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE up2x = {{0}, SK_POINTER};
#define up2 up2x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_BOOLEAN tb1;
	EIF_INTEGER_32 Result = ((EIF_INTEGER_32) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(5);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLR(2,tr1);
	RTLR(3,ur1);
	RTLR(4,tr2);
	RTLIU(5);
	RTLU (SK_INT32, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_REAL64, &loc1);
	
	RTEAA(l_feature_name, 18, Current, 1, 1, 346);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(18, Current, 346);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 18, l_feature_name, 1, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("trained", EX_PRE);
		tb1 = *(EIF_BOOLEAN *)(Current + RTWA(341, dtype));
		RTTE(tb1, label_1);
		RTCK;
		RTHOOK(2);
		RTCT("x_valid", EX_PRE);
		tb1 = '\0';
		if ((EIF_BOOLEAN)(arg1 != NULL)) {
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(342, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			RTNHOOK(2,1);
			ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", tr1))(tr1)).it_i4);
			tb1 = (EIF_BOOLEAN)(ti4_1 == ti4_2);
		}
		RTTE(tb1, label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(3);
	RTDBGAL(1, 0x20000000, 1, 0); /* loc1 */
	ur1 = RTCCL(arg1);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(340, dtype))(Current, ur1x)).it_r8);
	loc1 = (EIF_REAL_64) tr8_1;
	RTHOOK(4);
	if ((EIF_BOOLEAN) eif_is_less_real_64 (loc1, (EIF_REAL_64) 0.5)) {
		RTHOOK(5);
		RTDBGAL(0, 0x10000000, 1,0); /* Result */
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(344, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		RTNHOOK(5,1);
		tr2 = ((up2x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(344, dtype))(Current)), (((up2x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up2x.it_r = RTBU(up2x))), (up2x.type = SK_POINTER), up2x.it_r);
		RTNHOOK(5,2);
		ti4_1 = *(EIF_INTEGER_32 *)(tr2 + RTVA(3201, "lower", tr2));
		ui4_1 = ti4_1;
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", tr1))(tr1, ui4_1x)).it_i4);
		Result = (EIF_INTEGER_32) ti4_1;
	} else {
		RTHOOK(6);
		RTDBGAL(0, 0x10000000, 1,0); /* Result */
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(344, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		RTNHOOK(6,1);
		tr2 = ((up2x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(344, dtype))(Current)), (((up2x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up2x.it_r = RTBU(up2x))), (up2x.type = SK_POINTER), up2x.it_r);
		RTNHOOK(6,2);
		ti4_1 = *(EIF_INTEGER_32 *)(tr2 + RTVA(3200, "upper", tr2));
		ui4_1 = ti4_1;
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", tr1))(tr1, ui4_1x)).it_i4);
		Result = (EIF_INTEGER_32) ti4_1;
	}
	if (RTAL & CK_ENSURE) {
		RTHOOK(7);
		RTCT("result_valid", EX_POST);
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(335, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		RTNHOOK(7,1);
		ui4_1 = Result;
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(751, "has", tr1))(tr1, ui4_1x)).it_b);
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(8);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_INT32; r.it_i4 = Result; return r; }
#undef up1
#undef up2
#undef ur1
#undef ui4_1
#undef arg1
}

/* {LOGISTIC_REGRESSION_MODEL}.predict_proba */
EIF_TYPED_VALUE F19_341 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "predict_proba";
	RTEX;
	EIF_REAL_64 loc1 = (EIF_REAL_64) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_BOOLEAN tb1;
	EIF_REAL_64 Result = ((EIF_REAL_64) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(3);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLR(2,tr1);
	RTLIU(3);
	RTLU (SK_REAL64, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_REAL64, &loc1);
	RTLU(SK_INT32, &loc2);
	
	RTEAA(l_feature_name, 18, Current, 2, 1, 333);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(18, Current, 333);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 18, l_feature_name, 1, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("trained", EX_PRE);
		tb1 = *(EIF_BOOLEAN *)(Current + RTWA(341, dtype));
		RTTE(tb1, label_1);
		RTCK;
		RTHOOK(2);
		RTCT("x_valid", EX_PRE);
		tb1 = '\0';
		if ((EIF_BOOLEAN)(arg1 != NULL)) {
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(342, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			RTNHOOK(2,1);
			ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", tr1))(tr1)).it_i4);
			tb1 = (EIF_BOOLEAN)(ti4_1 == ti4_2);
		}
		RTTE(tb1, label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(3);
	RTDBGAL(1, 0x20000000, 1, 0); /* loc1 */
	tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(343, dtype));
	loc1 = (EIF_REAL_64) tr8_1;
	RTHOOK(4);
	RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
	loc2 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 1L);
	for (;;) {
		RTHOOK(5);
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(342, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		RTNHOOK(5,1);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", tr1))(tr1)).it_i4);
		if ((EIF_BOOLEAN) (loc2 > ti4_1)) break;
		RTHOOK(6);
		RTDBGAL(1, 0x20000000, 1, 0); /* loc1 */
		ui4_1 = loc2;
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)).it_r8);
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(342, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		RTNHOOK(6,1);
		ui4_1 = loc2;
		tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", tr1))(tr1, ui4_1x)).it_r8);
		loc1 += (EIF_REAL_64) (tr8_1 * tr8_2);
		RTHOOK(7);
		RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
		loc2++;
	}
	RTHOOK(8);
	if ((EIF_BOOLEAN) eif_is_greater_real_64 (loc1, (EIF_REAL_64) 5.0)) {
		RTHOOK(9);
		RTDBGAL(0, 0x20000000, 1,0); /* Result */
		Result = (EIF_REAL_64) (EIF_REAL_64) 1.0;
	} else {
		RTHOOK(10);
		if ((EIF_BOOLEAN) eif_is_less_real_64 (loc1, (EIF_REAL_64) -5.0)) {
			RTHOOK(11);
			RTDBGAL(0, 0x20000000, 1,0); /* Result */
			Result = (EIF_REAL_64) (EIF_REAL_64) 0.0;
		} else {
			RTHOOK(12);
			RTDBGAL(0, 0x20000000, 1,0); /* Result */
			Result = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) 0.5 + (EIF_REAL_64) ((EIF_REAL_64) 0.125 * loc1));
		}
	}
	if (RTAL & CK_ENSURE) {
		RTHOOK(13);
		RTCT("result_in_range", EX_POST);
		if ((EIF_BOOLEAN) ((EIF_BOOLEAN) eif_is_greater_equal_real_64 (Result, (EIF_REAL_64) 0.0) && (EIF_BOOLEAN) eif_is_less_equal_real_64 (Result, (EIF_REAL_64) 1.0))) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(14);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(5);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REAL64; r.it_r8 = Result; return r; }
#undef up1
#undef ui4_1
#undef arg1
}

/* {LOGISTIC_REGRESSION_MODEL}.is_trained */
EIF_TYPED_VALUE F19_342 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_BOOL;
	r.it_b = *(EIF_BOOLEAN *)(Current + RTWA(341,Dtype(Current)));
	return r;
}


/* {LOGISTIC_REGRESSION_MODEL}.weights */
EIF_TYPED_VALUE F19_343 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(342,Dtype(Current)));
	return r;
}


/* {LOGISTIC_REGRESSION_MODEL}.bias */
EIF_TYPED_VALUE F19_344 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REAL64;
	r.it_r8 = *(EIF_REAL_64 *)(Current + RTWA(343,Dtype(Current)));
	return r;
}


/* {LOGISTIC_REGRESSION_MODEL}.classes */
EIF_TYPED_VALUE F19_345 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(344,Dtype(Current)));
	return r;
}


/* {LOGISTIC_REGRESSION_MODEL}.learning_rate */
EIF_TYPED_VALUE F19_346 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REAL64;
	r.it_r8 = *(EIF_REAL_64 *)(Current + RTWA(345,Dtype(Current)));
	return r;
}


/* {LOGISTIC_REGRESSION_MODEL}.max_iterations */
EIF_TYPED_VALUE F19_347 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(346,Dtype(Current)));
	return r;
}


/* {LOGISTIC_REGRESSION_MODEL}._invariant */
void F19_6778 (EIF_REFERENCE Current, int where)
{
	GTCX
	char *l_feature_name = "_invariant";
	RTEX;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	RTCDT;
	RTLD;
	RTDA;
	
	RTLI(2);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLIU(2);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	RTEAINV(l_feature_name, 18, Current, 0, 6777);
	RTSA(dtype);
	RTME(dtype, 0);
	RTIT("weights_valid", Current);
	tb1 = '\01';
	tb2 = *(EIF_BOOLEAN *)(Current + RTWA(341, dtype));
	if (tb2) {
		tb2 = '\0';
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(342, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		if ((EIF_BOOLEAN)(tr1 != NULL)) {
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(342, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", tr1))(tr1)).it_i4);
			tb2 = (EIF_BOOLEAN) (ti4_1 > ((EIF_INTEGER_32) 0L));
		}
		tb1 = tb2;
	}
	if (tb1) {
		RTCK;
	} else {
		RTCF;
	}
	RTIT("classes_valid", Current);
	tb1 = '\01';
	tb2 = *(EIF_BOOLEAN *)(Current + RTWA(341, dtype));
	if (tb2) {
		tb2 = '\0';
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(344, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		if ((EIF_BOOLEAN)(tr1 != NULL)) {
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(344, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", tr1))(tr1)).it_i4);
			tb2 = (EIF_BOOLEAN) (ti4_1 > ((EIF_INTEGER_32) 0L));
		}
		tb1 = tb2;
	}
	if (tb1) {
		RTCK;
	} else {
		RTCF;
	}
	RTIT("learning_rate_positive", Current);
	tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(345, dtype));
	if ((EIF_BOOLEAN) eif_is_greater_real_64 (tr8_1, (EIF_REAL_64) 0.0)) {
		RTCK;
	} else {
		RTCF;
	}
	RTIT("max_iterations_positive", Current);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(346, dtype));
	if ((EIF_BOOLEAN) (ti4_1 > ((EIF_INTEGER_32) 0L))) {
		RTCK;
	} else {
		RTCF;
	}
	RTLO(2);
	RTMD(0);
	RTLE;
	RTEE;
#undef up1
}

void EIF_Minit19 (void)
{
	GTCX
}


#ifdef __cplusplus
}
#endif
