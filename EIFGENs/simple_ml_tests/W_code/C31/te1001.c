/*
 * Code for class TEST_RESULT
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern EIF_TYPED_VALUE F1001_7046(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1001_7047(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1001_7048(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1001_7049(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1001_7050(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1001_7051(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1001_7052(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F1001_7053(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern void F1001_7186(EIF_REFERENCE, int);
extern void EIF_Minit1001(void);

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

/* {TEST_RESULT}.statistic */
EIF_TYPED_VALUE F1001_7046 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REAL64;
	r.it_r8 = *(EIF_REAL_64 *)(Current + RTWA(5314,Dtype(Current)));
	return r;
}


/* {TEST_RESULT}.p_value */
EIF_TYPED_VALUE F1001_7047 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REAL64;
	r.it_r8 = *(EIF_REAL_64 *)(Current + RTWA(5315,Dtype(Current)));
	return r;
}


/* {TEST_RESULT}.degrees_of_freedom */
EIF_TYPED_VALUE F1001_7048 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(5316,Dtype(Current)));
	return r;
}


/* {TEST_RESULT}.assumption_checks */
EIF_TYPED_VALUE F1001_7049 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(5317,Dtype(Current)));
	return r;
}


/* {TEST_RESULT}.conclusion */
EIF_TYPED_VALUE F1001_7050 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "conclusion";
	RTEX;
#define arg1 arg1x.it_r8
	EIF_REAL_64 tr8_1;
	EIF_BOOLEAN Result = ((EIF_BOOLEAN) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_r8 = * (EIF_REAL_64 *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_BOOL, &Result);
	RTLU(SK_REAL64,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1000, Current, 0, 1, 13859);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1000, Current, 13859);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("alpha_valid", EX_PRE);
		RTTE((EIF_BOOLEAN) ((EIF_BOOLEAN) eif_is_greater_real_64 (arg1, (EIF_REAL_64) 0.0) && (EIF_BOOLEAN) eif_is_less_real_64 (arg1, (EIF_REAL_64) 1.0)), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(0, 0x04000000, 1,0); /* Result */
	tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(5315, dtype));
	Result = (EIF_BOOLEAN) (EIF_BOOLEAN) eif_is_less_real_64 (tr8_1, arg1);
	if (RTAL & CK_ENSURE) {
		RTHOOK(3);
		RTCT("result_defined", EX_POST);
		tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(5315, dtype));
		if ((EIF_BOOLEAN)(Result == (EIF_BOOLEAN) eif_is_less_real_64 (tr8_1, arg1))) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(4);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_BOOL; r.it_b = Result; return r; }
#undef arg1
}

/* {TEST_RESULT}.is_significant */
EIF_TYPED_VALUE F1001_7051 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "is_significant";
	RTEX;
#define arg1 arg1x.it_r8
	EIF_TYPED_VALUE ur8_1x = {{0}, SK_REAL64};
#define ur8_1 ur8_1x.it_r8
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN Result = ((EIF_BOOLEAN) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_r8 = * (EIF_REAL_64 *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_BOOL, &Result);
	RTLU(SK_REAL64,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1000, Current, 0, 1, 13860);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1000, Current, 13860);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("alpha_valid", EX_PRE);
		RTTE((EIF_BOOLEAN) ((EIF_BOOLEAN) eif_is_greater_real_64 (arg1, (EIF_REAL_64) 0.0) && (EIF_BOOLEAN) eif_is_less_real_64 (arg1, (EIF_REAL_64) 1.0)), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(0, 0x04000000, 1,0); /* Result */
	ur8_1 = arg1;
	tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5318, dtype))(Current, ur8_1x)).it_b);
	Result = (EIF_BOOLEAN) tb1;
	if (RTAL & CK_ENSURE) {
		RTHOOK(3);
		RTCT("result_defined", EX_POST);
		ur8_1 = arg1;
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5318, dtype))(Current, ur8_1x)).it_b);
		if ((EIF_BOOLEAN)(Result == tb1)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(4);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_BOOL; r.it_b = Result; return r; }
#undef ur8_1
#undef arg1
}

/* {TEST_RESULT}.format_for_publication */
EIF_TYPED_VALUE F1001_7052 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "format_for_publication";
	RTEX;
#define arg1 arg1x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_BOOLEAN tb1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(4);
	RTLR(0,arg1);
	RTLR(1,tr1);
	RTLR(2,Result);
	RTLR(3,Current);
	RTLIU(4);
	RTLU (SK_REF, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1000, Current, 0, 1, 13861);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1000, Current, 13861);
	RTCC(arg1, 1000, l_feature_name, 1, eif_new_type(267, 0x01), 0x01);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("test_name_valid", EX_PRE);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(4487, "is_empty", arg1))(arg1)).it_b);
		RTTE((EIF_BOOLEAN) !tb1, label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(0, 0xF800010B, 0,0); /* Result */
	tr1 = RTMS_EX_H("",0,0);
	Result = (EIF_REFERENCE) tr1;
	if (RTAL & CK_ENSURE) {
		RTHOOK(3);
		RTCT("result_valid", EX_POST);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(4487, "is_empty", Result))(Result)).it_b);
		if ((EIF_BOOLEAN) !tb1) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(4);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef arg1
}

/* {TEST_RESULT}.make */
void F1001_7053 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x, EIF_TYPED_VALUE arg3x, EIF_TYPED_VALUE arg4x)
{
	GTCX
	char *l_feature_name = "make";
	RTEX;
#define arg1 arg1x.it_r8
#define arg2 arg2x.it_r8
#define arg3 arg3x.it_i4
#define arg4 arg4x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_INTEGER_32 ti4_1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg3x.type & SK_HEAD) == SK_REF) arg3x.it_i4 = * (EIF_INTEGER_32 *) arg3x.it_r;
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
	RTLU(SK_INT32,&arg3);
	RTLU(SK_REF,&arg4);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1000, Current, 0, 4, 13862);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1000, Current, 13862);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,352,0xFF01,998,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg4, 1000, l_feature_name, 4, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("p_valid", EX_PRE);
		RTTE((EIF_BOOLEAN) ((EIF_BOOLEAN) eif_is_greater_equal_real_64 (arg2, (EIF_REAL_64) 0.0) && (EIF_BOOLEAN) eif_is_less_equal_real_64 (arg2, (EIF_REAL_64) 1.0)), label_1);
		RTCK;
		RTHOOK(2);
		RTCT("dof_valid", EX_PRE);
		RTTE((EIF_BOOLEAN) (arg3 >= ((EIF_INTEGER_32) 1L)), label_1);
		RTCK;
		RTHOOK(3);
		RTHOOK(4);
		RTCT("checks_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg4 != NULL), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(5);
	RTDBGAA(Current, dtype, 5314, 0x20000000, 1); /* statistic */
	*(EIF_REAL_64 *)(Current + RTWA(5314, dtype)) = (EIF_REAL_64) arg1;
	RTHOOK(6);
	RTDBGAA(Current, dtype, 5315, 0x20000000, 1); /* p_value */
	*(EIF_REAL_64 *)(Current + RTWA(5315, dtype)) = (EIF_REAL_64) arg2;
	RTHOOK(7);
	RTDBGAA(Current, dtype, 5316, 0x10000000, 1); /* degrees_of_freedom */
	*(EIF_INTEGER_32 *)(Current + RTWA(5316, dtype)) = (EIF_INTEGER_32) arg3;
	RTHOOK(8);
	RTDBGAA(Current, dtype, 5317, 0xF8000160, 0); /* assumption_checks */
	tr1 = RTCCL(arg4);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(5317, dtype)) = (EIF_REFERENCE) tr1;
	if (RTAL & CK_ENSURE) {
		RTHOOK(9);
		RTCT("statistic_set", EX_POST);
		tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(5314, dtype));
		if ((EIF_BOOLEAN) eif_is_equal_real_64 (tr8_1, arg1)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(10);
		RTCT("p_value_set", EX_POST);
		tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(5315, dtype));
		if ((EIF_BOOLEAN) eif_is_equal_real_64 (tr8_1, arg2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(11);
		RTCT("dof_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5316, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg3)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(12);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(6);
	RTEE;
#undef arg4
#undef arg3
#undef arg2
#undef arg1
}

/* {TEST_RESULT}._invariant */
void F1001_7186 (EIF_REFERENCE Current, int where)
{
	GTCX
	char *l_feature_name = "_invariant";
	RTEX;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_INTEGER_32 ti4_1;
	RTCDT;
	RTLD;
	RTDA;
	
	RTLI(2);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLIU(2);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	RTEAINV(l_feature_name, 1000, Current, 0, 7185);
	RTSA(dtype);
	RTME(dtype, 0);
	RTIT("p_value_valid", Current);
	tr8_1 = *(EIF_REAL_64 *)(Current + RTWA(5315, dtype));
	tr8_2 = *(EIF_REAL_64 *)(Current + RTWA(5315, dtype));
	if ((EIF_BOOLEAN) ((EIF_BOOLEAN) eif_is_greater_equal_real_64 (tr8_1, (EIF_REAL_64) 0.0) && (EIF_BOOLEAN) eif_is_less_equal_real_64 (tr8_2, (EIF_REAL_64) 1.0))) {
		RTCK;
	} else {
		RTCF;
	}
	RTIT("dof_valid", Current);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5316, dtype));
	if ((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 1L))) {
		RTCK;
	} else {
		RTCF;
	}
	RTIT("assumption_checks_not_void", Current);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5317, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
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

void EIF_Minit1001 (void)
{
	GTCX
}


#ifdef __cplusplus
}
#endif
