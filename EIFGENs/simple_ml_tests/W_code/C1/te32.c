/*
 * Code for class TEST_APP
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern void F32_692(EIF_REFERENCE);
extern void F32_693(EIF_REFERENCE);
extern void F32_694(EIF_REFERENCE);
extern void F32_695(EIF_REFERENCE);
extern void F32_696(EIF_REFERENCE);
extern void F32_697(EIF_REFERENCE);
extern void F32_698(EIF_REFERENCE);
extern EIF_TYPED_VALUE F32_699(EIF_REFERENCE);
extern EIF_TYPED_VALUE F32_700(EIF_REFERENCE);
extern void F32_701(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern void EIF_Minit32(void);
extern EIF_REFERENCE _A190_52();
extern EIF_REFERENCE _A189_53();
extern EIF_REFERENCE _A190_51();
extern EIF_REFERENCE _A192_53();
extern EIF_REFERENCE _A189_52();
extern EIF_REFERENCE _A188_52();
extern EIF_REFERENCE _A192_52();
extern EIF_REFERENCE _A188_53();
extern EIF_REFERENCE _A187_53();
extern EIF_REFERENCE _A189_51();
extern EIF_REFERENCE _A188_51();
extern EIF_REFERENCE _A191_53();
extern EIF_REFERENCE _A192_51();
extern EIF_REFERENCE _A187_52();
extern EIF_REFERENCE _A191_52();
extern EIF_REFERENCE _A187_51();
extern EIF_REFERENCE _A190_53();
extern EIF_REFERENCE _A191_51();

#ifdef __cplusplus
}
#endif

#include "eif_out.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* {TEST_APP}.make */
void F32_692 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "make";
	RTEX;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_INTEGER_32 ti4_1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(4);
	RTLR(0,tr1);
	RTLR(1,ur1);
	RTLR(2,Current);
	RTLR(3,tr2);
	RTLIU(4);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 31, Current, 0, 0, 782);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(31, Current, 782);
	RTIV(Current, RTAL);
	RTHOOK(1);
	tr1 = RTMS_EX_H("Running simple_ml tests...\012\012",28,744325642);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	RTHOOK(2);
	RTDBGAA(Current, dtype, 699, 0x10000000, 1); /* passed */
	*(EIF_INTEGER_32 *)(Current + RTWA(699, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 0L);
	RTHOOK(3);
	RTDBGAA(Current, dtype, 700, 0x10000000, 1); /* failed */
	*(EIF_INTEGER_32 *)(Current + RTWA(700, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 0L);
	RTHOOK(4);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWF(693, dtype))(Current);
	RTHOOK(5);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWF(694, dtype))(Current);
	RTHOOK(6);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWF(695, dtype))(Current);
	RTHOOK(7);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWF(696, dtype))(Current);
	RTHOOK(8);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWF(697, dtype))(Current);
	RTHOOK(9);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWF(698, dtype))(Current);
	RTHOOK(10);
	tr1 = RTMS_EX_H("\012========================\012",26,1020698890);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	RTHOOK(11);
	tr1 = RTMS_EX_H("Results: ",9,501397536);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(699, dtype));
	tr2 = eif_out__i4_s1(ti4_1);
	ur1 = RTCCL(tr2);
	tr2 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4622, "plus", tr1))(tr1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	tr1 = RTMS_EX_H(" passed, ",9,1123470880);
	ur1 = tr1;
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4622, "plus", tr2))(tr2, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(700, dtype));
	tr2 = eif_out__i4_s1(ti4_1);
	ur1 = RTCCL(tr2);
	tr2 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4622, "plus", tr1))(tr1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	tr1 = RTMS_EX_H(" failed\012",8,1816238602);
	ur1 = tr1;
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4622, "plus", tr2))(tr2, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	RTHOOK(12);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(700, dtype));
	if ((EIF_BOOLEAN) (ti4_1 > ((EIF_INTEGER_32) 0L))) {
		RTHOOK(13);
		tr1 = RTMS_EX_H("TESTS FAILED\012",13,1877440778);
		ur1 = tr1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	} else {
		RTHOOK(14);
		tr1 = RTMS_EX_H("ALL TESTS PASSED\012",17,1459221002);
		ur1 = tr1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(15);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
#undef up1
#undef ur1
}

/* {TEST_APP}.run_linear_regression_tests */
void F32_693 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "run_linear_regression_tests";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur2x = {{0}, SK_REF};
#define ur2 ur2x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_REFERENCE tr3 = NULL;
	RTCFDT;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(7);
	RTLR(0,tr1);
	RTLR(1,ur1);
	RTLR(2,Current);
	RTLR(3,loc1);
	RTLR(4,tr2);
	RTLR(5,tr3);
	RTLR(6,ur2);
	RTLIU(7);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	
	RTEAA(l_feature_name, 31, Current, 1, 0, 783);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(31, Current, 783);
	RTIV(Current, RTAL);
	RTHOOK(1);
	tr1 = RTMS_EX_H("Linear Regression Tests:\012",25,6171914);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	RTHOOK(2);
	RTDBGAL(1, 0xF80000BC, 0, 0); /* loc1 */
	tr1 = RTLN(eif_new_type(188, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(32, Dtype(tr1)))(tr1);
	RTNHOOK(2,1);
	loc1 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,188,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A189_51, (EIF_POINTER)(0),2746, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_make_creates_unconfigured_model",36,586260332);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(4);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,188,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A189_52, (EIF_POINTER)(0),2747, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_set_learning_rate_valid",28,788295524);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(5);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,188,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A189_53, (EIF_POINTER)(0),2748, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_set_max_iterations_valid",29,1741623652);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(6);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(7);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef ur1
#undef ur2
}

/* {TEST_APP}.run_logistic_regression_tests */
void F32_694 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "run_logistic_regression_tests";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur2x = {{0}, SK_REF};
#define ur2 ur2x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_REFERENCE tr3 = NULL;
	RTCFDT;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(7);
	RTLR(0,tr1);
	RTLR(1,ur1);
	RTLR(2,Current);
	RTLR(3,loc1);
	RTLR(4,tr2);
	RTLR(5,tr3);
	RTLR(6,ur2);
	RTLIU(7);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	
	RTEAA(l_feature_name, 31, Current, 1, 0, 784);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(31, Current, 784);
	RTIV(Current, RTAL);
	RTHOOK(1);
	tr1 = RTMS_EX_H("Logistic Regression Tests:\012",27,385886218);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	RTHOOK(2);
	RTDBGAL(1, 0xF80000BB, 0, 0); /* loc1 */
	tr1 = RTLN(eif_new_type(187, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(32, Dtype(tr1)))(tr1);
	RTNHOOK(2,1);
	loc1 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,187,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A188_51, (EIF_POINTER)(0),2743, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_make_creates_unconfigured_model",36,586260332);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(4);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,187,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A188_52, (EIF_POINTER)(0),2744, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_set_learning_rate_valid",28,788295524);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(5);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,187,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A188_53, (EIF_POINTER)(0),2745, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_set_max_iterations_valid",29,1741623652);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(6);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(7);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef ur1
#undef ur2
}

/* {TEST_APP}.run_decision_tree_tests */
void F32_695 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "run_decision_tree_tests";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur2x = {{0}, SK_REF};
#define ur2 ur2x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_REFERENCE tr3 = NULL;
	RTCFDT;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(7);
	RTLR(0,tr1);
	RTLR(1,ur1);
	RTLR(2,Current);
	RTLR(3,loc1);
	RTLR(4,tr2);
	RTLR(5,tr3);
	RTLR(6,ur2);
	RTLIU(7);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	
	RTEAA(l_feature_name, 31, Current, 1, 0, 785);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(31, Current, 785);
	RTIV(Current, RTAL);
	RTHOOK(1);
	tr1 = RTMS_EX_H("Decision Tree Tests:\012",21,184111370);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	RTHOOK(2);
	RTDBGAL(1, 0xF80000BA, 0, 0); /* loc1 */
	tr1 = RTLN(eif_new_type(186, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(32, Dtype(tr1)))(tr1);
	RTNHOOK(2,1);
	loc1 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,186,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A187_51, (EIF_POINTER)(0),2740, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_make_creates_unconfigured_model",36,586260332);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(4);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,186,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A187_52, (EIF_POINTER)(0),2741, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_set_max_depth",18,848232296);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(5);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,186,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A187_53, (EIF_POINTER)(0),2742, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_set_min_samples_split",26,126865268);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(6);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(7);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef ur1
#undef ur2
}

/* {TEST_APP}.run_random_forest_tests */
void F32_696 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "run_random_forest_tests";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur2x = {{0}, SK_REF};
#define ur2 ur2x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_REFERENCE tr3 = NULL;
	RTCFDT;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(7);
	RTLR(0,tr1);
	RTLR(1,ur1);
	RTLR(2,Current);
	RTLR(3,loc1);
	RTLR(4,tr2);
	RTLR(5,tr3);
	RTLR(6,ur2);
	RTLIU(7);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	
	RTEAA(l_feature_name, 31, Current, 1, 0, 786);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(31, Current, 786);
	RTIV(Current, RTAL);
	RTHOOK(1);
	tr1 = RTMS_EX_H("Random Forest Tests:\012",21,888359178);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	RTHOOK(2);
	RTDBGAL(1, 0xF80000BF, 0, 0); /* loc1 */
	tr1 = RTLN(eif_new_type(191, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(32, Dtype(tr1)))(tr1);
	RTNHOOK(2,1);
	loc1 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,191,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A192_51, (EIF_POINTER)(0),2755, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_make_creates_unconfigured_model",36,586260332);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(4);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,191,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A192_52, (EIF_POINTER)(0),2756, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_set_num_trees",18,2035282803);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(5);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,191,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A192_53, (EIF_POINTER)(0),2757, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_set_max_depth",18,848232296);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(6);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(7);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef ur1
#undef ur2
}

/* {TEST_APP}.run_svm_tests */
void F32_697 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "run_svm_tests";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur2x = {{0}, SK_REF};
#define ur2 ur2x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_REFERENCE tr3 = NULL;
	RTCFDT;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(7);
	RTLR(0,tr1);
	RTLR(1,ur1);
	RTLR(2,Current);
	RTLR(3,loc1);
	RTLR(4,tr2);
	RTLR(5,tr3);
	RTLR(6,ur2);
	RTLIU(7);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	
	RTEAA(l_feature_name, 31, Current, 1, 0, 787);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(31, Current, 787);
	RTIV(Current, RTAL);
	RTHOOK(1);
	tr1 = RTMS_EX_H("SVM Linear Tests:\012",18,614244874);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	RTHOOK(2);
	RTDBGAL(1, 0xF80000BE, 0, 0); /* loc1 */
	tr1 = RTLN(eif_new_type(190, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(32, Dtype(tr1)))(tr1);
	RTNHOOK(2,1);
	loc1 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,190,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A191_51, (EIF_POINTER)(0),2752, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_make_creates_unconfigured_model",36,586260332);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(4);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,190,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A191_52, (EIF_POINTER)(0),2753, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_set_c_param",16,884184429);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(5);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,190,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A191_53, (EIF_POINTER)(0),2754, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_set_tolerance",18,1611636069);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(6);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(7);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef ur1
#undef ur2
}

/* {TEST_APP}.run_neural_network_tests */
void F32_698 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "run_neural_network_tests";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur2x = {{0}, SK_REF};
#define ur2 ur2x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_REFERENCE tr3 = NULL;
	RTCFDT;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(7);
	RTLR(0,tr1);
	RTLR(1,ur1);
	RTLR(2,Current);
	RTLR(3,loc1);
	RTLR(4,tr2);
	RTLR(5,tr3);
	RTLR(6,ur2);
	RTLIU(7);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	
	RTEAA(l_feature_name, 31, Current, 1, 0, 788);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(31, Current, 788);
	RTIV(Current, RTAL);
	RTHOOK(1);
	tr1 = RTMS_EX_H("Neural Network Tests:\012",22,1400544778);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	RTHOOK(2);
	RTDBGAL(1, 0xF80000BD, 0, 0); /* loc1 */
	tr1 = RTLN(eif_new_type(189, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(32, Dtype(tr1)))(tr1);
	RTNHOOK(2,1);
	loc1 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,189,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A190_51, (EIF_POINTER)(0),2749, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_make_creates_unconfigured_model",36,586260332);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(4);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,189,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A190_52, (EIF_POINTER)(0),2750, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_set_learning_rate",22,185749093);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(5);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFFF9,1,219,0xFF01,189,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = loc1;
	RTAR(tr1,loc1);
	
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2= RTLNRW(typres0.id, 0, (EIF_POINTER) _A190_53, (EIF_POINTER)(0),2751, 0, 0, 1, -1, tr1, 0);
	}
	ur1 = RTCCL(tr2);
	tr3 = RTMS_EX_H("test_set_max_iterations",23,355549555);
	ur2 = tr3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(701, dtype))(Current, ur1x, ur2x);
	RTHOOK(6);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(7);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef ur1
#undef ur2
}

/* {TEST_APP}.passed */
EIF_TYPED_VALUE F32_699 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(699,Dtype(Current)));
	return r;
}


/* {TEST_APP}.failed */
EIF_TYPED_VALUE F32_700 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(700,Dtype(Current)));
	return r;
}


/* {TEST_APP}.run_test */
#undef EIF_VOLATILE
#define EIF_VOLATILE volatile
void F32_701 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "run_test";
	RTEX;
	RTED;
	EIF_BOOLEAN EIF_VOLATILE loc1 = (EIF_BOOLEAN) 0;
	EIF_REFERENCE EIF_VOLATILE saved_except = (EIF_REFERENCE) 0;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_r
	RTS_SDX;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_REFERENCE  EIF_VOLATILE tr1 = NULL;
	EIF_REFERENCE  EIF_VOLATILE tr2 = NULL;
	EIF_INTEGER_32  EIF_VOLATILE ti4_1;
	RTCDT;
	RTSN;
	RTDA;
	RTDT;
	RTLD;
	RTXD;
	RTLXD;
	
	
	RTLI(7);
	RTLR(0,arg1);
	RTLR(1,arg2);
	RTLR(2,ur1);
	RTLR(3,tr1);
	RTLR(4,tr2);
	RTLR(5,Current);
	RTLR(6,saved_except);
	RTLIU(7);
	RTXSLS;
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU(SK_REF,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_BOOL, &loc1);
	RTLXL;
	
	RTEAA(l_feature_name, 31, Current, 1, 2, 791);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(31, Current, 791);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,315,0xFF01,0xFFF9,0,219,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 31, l_feature_name, 1, typres0, 0x01);
	}
	RTCC(arg2, 31, l_feature_name, 2, eif_new_type(267, 0x01), 0x01);
	RTIV(Current, RTAL);
	RTE_T
	RTHOOK(1);
	if ((EIF_BOOLEAN) !loc1) {
		RTHOOK(2);
		ur1 = NULL;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4439, "call", arg1))(arg1, ur1x);
		RTHOOK(3);
		tr1 = RTMS_EX_H("  PASS: ",8,489410592);
		ur1 = RTCCL(arg2);
		tr2 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4622, "plus", tr1))(tr1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		tr1 = RTMS_EX_H("\012",1,10);
		ur1 = tr1;
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4622, "plus", tr2))(tr2, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		ur1 = RTCCL(tr1);
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
		RTHOOK(4);
		RTDBGAA(Current, dtype, 699, 0x10000000, 1); /* passed */
		(*(EIF_INTEGER_32 *)(Current + RTWA(699, dtype)))++;
	}
	RTVI(Current, RTAL);
	RTRS;
	RTE_E
	RTLXE;
	RTXSC;
	RTS_SRR
	RTHOOK(5);
	tr1 = RTMS_EX_H("  FAIL: ",8,301518880);
	ur1 = RTCCL(arg2);
	tr2 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4622, "plus", tr1))(tr1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4622, "plus", tr2))(tr2, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	RTHOOK(6);
	RTDBGAA(Current, dtype, 700, 0x10000000, 1); /* failed */
	(*(EIF_INTEGER_32 *)(Current + RTWA(700, dtype)))++;
	RTHOOK(7);
	RTDBGAL(1, 0x04000000, 1, 0); /* loc1 */
	loc1 = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
	RTHOOK(8);
	RTTS;
	RTPS;
	RTER;
	RTMD(0);
	/* NOTREACHED */
	RTE_EE
	RTHOOK(9);
	RTDBGLE;
	RTMD(0);
	RTEOK;
	RTLE;
	RTLO(5);
#undef up1
#undef ur1
#undef arg2
#undef arg1
}
#undef EIF_VOLATILE
#define EIF_VOLATILE

void EIF_Minit32 (void)
{
	GTCX
}


#ifdef __cplusplus
}
#endif
