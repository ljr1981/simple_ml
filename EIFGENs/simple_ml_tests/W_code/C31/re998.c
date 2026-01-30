/*
 * Code for class REGRESSION_RESULT
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern EIF_TYPED_VALUE F998_6991(EIF_REFERENCE);
extern EIF_TYPED_VALUE F998_6992(EIF_REFERENCE);
extern EIF_TYPED_VALUE F998_6993(EIF_REFERENCE);
extern EIF_TYPED_VALUE F998_6994(EIF_REFERENCE);
extern EIF_TYPED_VALUE F998_6995(EIF_REFERENCE);
extern EIF_TYPED_VALUE F998_6996(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F998_6997(EIF_REFERENCE);
extern void F998_6998(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern void F998_7184(EIF_REFERENCE, int);
extern void EIF_Minit998(void);

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

/* {REGRESSION_RESULT}.slope */
EIF_TYPED_VALUE F998_6991 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REAL64;
	r.it_r8 = *(EIF_REAL_64 *)(Current + RTWA(5259,Dtype(Current)));
	return r;
}


/* {REGRESSION_RESULT}.intercept */
EIF_TYPED_VALUE F998_6992 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REAL64;
	r.it_r8 = *(EIF_REAL_64 *)(Current + RTWA(5260,Dtype(Current)));
	return r;
}


/* {REGRESSION_RESULT}.r_squared */
EIF_TYPED_VALUE F998_6993 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REAL64;
	r.it_r8 = *(EIF_REAL_64 *)(Current + RTWA(5261,Dtype(Current)));
	return r;
}


/* {REGRESSION_RESULT}.residuals */
EIF_TYPED_VALUE F998_6994 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(5262,Dtype(Current)));
	return r;
}


/* {REGRESSION_RESULT}.condition_number */
EIF_TYPED_VALUE F998_6995 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REAL64;
	r.it_r8 = *(EIF_REAL_64 *)(Current + RTWA(5263,Dtype(Current)));
	return r;
}


/* {REGRESSION_RESULT}.predict */
EIF_TYPED_VALUE F998_6996 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "predict";
	RTEX;
#define arg1 arg1x.it_r8
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_REAL_64 Result = ((EIF_REAL_64) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_r8 = * (EIF_REAL_64 *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_REAL64, &Result);
	RTLU(SK_REAL64,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 997, Current, 0, 1, 13804);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(997, Current, 13804);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(0, 0x20000000, 1,0); /* Result */
	tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(5259, dtype));
	tr8_2 = *(EIF_REAL_64 *)(Current + RTWA(5260, dtype));
	Result = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) (tr8_1 * arg1) + tr8_2);
	if (RTAL & CK_ENSURE) {
		RTHOOK(3);
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(4);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REAL64; r.it_r8 = Result; return r; }
#undef arg1
}

/* {REGRESSION_RESULT}.is_numerically_stable */
EIF_TYPED_VALUE F998_6997 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "is_numerically_stable";
	RTEX;
	EIF_REAL_64 tr8_1;
	EIF_BOOLEAN Result = ((EIF_BOOLEAN) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_BOOL, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 997, Current, 0, 0, 13805);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(997, Current, 13805);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(0, 0x04000000, 1,0); /* Result */
	tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(5263, dtype));
	Result = (EIF_BOOLEAN) (EIF_BOOLEAN) eif_is_less_real_64 (tr8_1, (EIF_REAL_64) 1000000000000.0);
	if (RTAL & CK_ENSURE) {
		RTHOOK(2);
		RTCT("result_defined", EX_POST);
		tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(5263, dtype));
		if ((EIF_BOOLEAN)(Result == (EIF_BOOLEAN) eif_is_less_real_64 (tr8_1, (EIF_REAL_64) 1000000000000.0))) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(3);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_BOOL; r.it_b = Result; return r; }
}

/* {REGRESSION_RESULT}.make */
void F998_6998 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x, EIF_TYPED_VALUE arg3x, EIF_TYPED_VALUE arg4x, EIF_TYPED_VALUE arg5x)
{
	GTCX
	char *l_feature_name = "make";
	RTEX;
#define arg1 arg1x.it_r8
#define arg2 arg2x.it_r8
#define arg3 arg3x.it_r8
#define arg4 arg4x.it_r
#define arg5 arg5x.it_r8
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg5x.type & SK_HEAD) == SK_REF) arg5x.it_r8 = * (EIF_REAL_64 *) arg5x.it_r;
	if ((arg3x.type & SK_HEAD) == SK_REF) arg3x.it_r8 = * (EIF_REAL_64 *) arg3x.it_r;
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_r8 = * (EIF_REAL_64 *) arg2x.it_r;
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_r8 = * (EIF_REAL_64 *) arg1x.it_r;
	
	RTLI(3);
	RTLR(0,arg4);
	RTLR(1,Current);
	RTLR(2,tr1);
	RTLIU(3);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REAL64,&arg1);
	RTLU(SK_REAL64,&arg2);
	RTLU(SK_REAL64,&arg3);
	RTLU(SK_REF,&arg4);
	RTLU(SK_REAL64,&arg5);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 997, Current, 0, 5, 13806);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(997, Current, 13806);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg4, 997, l_feature_name, 4, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("r2_valid", EX_PRE);
		RTTE((EIF_BOOLEAN) ((EIF_BOOLEAN) eif_is_greater_equal_real_64 (arg3, (EIF_REAL_64) 0.0) && (EIF_BOOLEAN) eif_is_less_equal_real_64 (arg3, (EIF_REAL_64) ((EIF_REAL_64) 1.0 + (EIF_REAL_64) 0.0000000001))), label_1);
		RTCK;
		RTHOOK(2);
		RTHOOK(3);
		RTCT("condition_non_negative", EX_PRE);
		RTTE((EIF_BOOLEAN) eif_is_greater_equal_real_64 (arg5, (EIF_REAL_64) 1.0), label_1);
		RTCK;
		RTHOOK(4);
		RTCT("residuals_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg4 != NULL), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(5);
	RTDBGAA(Current, dtype, 5259, 0x20000000, 1); /* slope */
	*(EIF_REAL_64 *)(Current + RTWA(5259, dtype)) = (EIF_REAL_64) arg1;
	RTHOOK(6);
	RTDBGAA(Current, dtype, 5260, 0x20000000, 1); /* intercept */
	*(EIF_REAL_64 *)(Current + RTWA(5260, dtype)) = (EIF_REAL_64) arg2;
	RTHOOK(7);
	RTDBGAA(Current, dtype, 5261, 0x20000000, 1); /* r_squared */
	*(EIF_REAL_64 *)(Current + RTWA(5261, dtype)) = (EIF_REAL_64) arg3;
	RTHOOK(8);
	RTDBGAA(Current, dtype, 5262, 0xF80001EF, 0); /* residuals */
	tr1 = RTCCL(arg4);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(5262, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(9);
	RTDBGAA(Current, dtype, 5263, 0x20000000, 1); /* condition_number */
	*(EIF_REAL_64 *)(Current + RTWA(5263, dtype)) = (EIF_REAL_64) arg5;
	if (RTAL & CK_ENSURE) {
		RTHOOK(10);
		RTCT("slope_set", EX_POST);
		tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(5259, dtype));
		if ((EIF_BOOLEAN) eif_is_equal_real_64 (tr8_1, arg1)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(11);
		RTCT("intercept_set", EX_POST);
		tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(5260, dtype));
		if ((EIF_BOOLEAN) eif_is_equal_real_64 (tr8_1, arg2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(12);
		RTCT("r2_set", EX_POST);
		tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(5261, dtype));
		if ((EIF_BOOLEAN) eif_is_equal_real_64 (tr8_1, arg3)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(13);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(7);
	RTEE;
#undef arg5
#undef arg4
#undef arg3
#undef arg2
#undef arg1
}

/* {REGRESSION_RESULT}._invariant */
void F998_7184 (EIF_REFERENCE Current, int where)
{
	GTCX
	char *l_feature_name = "_invariant";
	RTEX;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	RTCDT;
	RTLD;
	RTDA;
	
	RTLI(2);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLIU(2);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	RTEAINV(l_feature_name, 997, Current, 0, 7183);
	RTSA(dtype);
	RTME(dtype, 0);
	RTIT("r_squared_valid", Current);
	tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(5261, dtype));
	tr8_2 = *(EIF_REAL_64 *)(Current + RTWA(5261, dtype));
	if ((EIF_BOOLEAN) ((EIF_BOOLEAN) eif_is_greater_equal_real_64 (tr8_1, (EIF_REAL_64) 0.0) && (EIF_BOOLEAN) eif_is_less_equal_real_64 (tr8_2, (EIF_REAL_64) ((EIF_REAL_64) 1.0 + (EIF_REAL_64) 0.0000000001)))) {
		RTCK;
	} else {
		RTCF;
	}
	RTIT("condition_positive", Current);
	tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(5263, dtype));
	if ((EIF_BOOLEAN) eif_is_greater_equal_real_64 (tr8_1, (EIF_REAL_64) 1.0)) {
		RTCK;
	} else {
		RTCF;
	}
	RTIT("residuals_not_void", Current);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5262, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	if ((EIF_BOOLEAN)(tr1 != NULL)) {
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

void EIF_Minit998 (void)
{
	GTCX
}


#ifdef __cplusplus
}
#endif
