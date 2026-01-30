/*
 * Code for class STATISTICS
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern void F1002_7054(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1002_7055(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7056(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7057(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7058(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7059(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7060(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7061(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7062(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7063(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7064(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7065(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7066(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7067(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7068(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7069(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7070(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7071(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7072(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1002_7073(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F1002_7187(EIF_REFERENCE, int);
extern void EIF_Minit1002(void);

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

/* {STATISTICS}.make */
void F1002_7054 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "make";
	RTEX;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1001, Current, 0, 0, 13871);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13871);
	RTIV(Current, RTAL);
	if (RTAL & CK_ENSURE) {
		RTHOOK(1);
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(2);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
}

/* {STATISTICS}.mean */
EIF_TYPED_VALUE F1002_7055 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "mean";
	RTEX;
	EIF_REAL_64 loc1 = (EIF_REAL_64) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
	EIF_REFERENCE loc3 = (EIF_REFERENCE) 0;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_BOOLEAN tb1;
	EIF_REAL_64 Result = ((EIF_REAL_64) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(4);
	RTLR(0,arg1);
	RTLR(1,loc3);
	RTLR(2,tr1);
	RTLR(3,Current);
	RTLIU(4);
	RTLU (SK_REAL64, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_REAL64, &loc1);
	RTLU(SK_INT32, &loc2);
	RTLU(SK_REF, &loc3);
	
	RTEAA(l_feature_name, 1001, Current, 3, 1, 13872);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13872);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("data_not_empty", EX_PRE);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		RTTE((EIF_BOOLEAN) !tb1, label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(1, 0x20000000, 1, 0); /* loc1 */
	loc1 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	RTHOOK(3);
	RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
	loc2 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 0L);
	RTHOOK(4);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2758, "new_cursor", arg1))(arg1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc3 = (EIF_REFERENCE) RTCCL(tr1);
	for (;;) {
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2707, "after", loc3))(loc3)).it_b);
		if (tb1) break;
		RTHOOK(5);
		RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
		loc2++;
		RTHOOK(6);
		RTDBGAL(1, 0x20000000, 1, 0); /* loc1 */
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc3))(loc3)).it_r8);
		tr8_2 = tr8_1;
		tr8_1 = (EIF_REAL_64) (loc2);
		loc1 += (EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) (tr8_2 - loc1)) /  (EIF_REAL_64) (tr8_1));
		RTHOOK(7);
		(FUNCTION_CAST(void, (EIF_REFERENCE)) RTVF(2708, "forth", loc3))(loc3);
	}
	RTHOOK(8);
	RTDBGAL(0, 0x20000000, 1,0); /* Result */
	Result = (EIF_REAL_64) loc1;
	if (RTAL & CK_ENSURE) {
		RTHOOK(9);
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(10);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(6);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REAL64; r.it_r8 = Result; return r; }
#undef up1
#undef arg1
}

/* {STATISTICS}.median */
EIF_TYPED_VALUE F1002_7056 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "median";
	RTEX;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur8_1x = {{0}, SK_REAL64};
#define ur8_1 ur8_1x.it_r8
	EIF_REAL_64 tr8_1;
	EIF_BOOLEAN tb1;
	EIF_REAL_64 Result = ((EIF_REAL_64) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(3);
	RTLR(0,arg1);
	RTLR(1,ur1);
	RTLR(2,Current);
	RTLIU(3);
	RTLU (SK_REAL64, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1001, Current, 0, 1, 13873);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13873);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("data_not_empty", EX_PRE);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		RTTE((EIF_BOOLEAN) !tb1, label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(0, 0x20000000, 1,0); /* Result */
	ur1 = RTCCL(arg1);
	ur8_1 = (EIF_REAL_64) 50.0;
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(5328, dtype))(Current, ur1x, ur8_1x)).it_r8);
	Result = (EIF_REAL_64) tr8_1;
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
#undef ur1
#undef ur8_1
#undef arg1
}

/* {STATISTICS}.mode */
EIF_TYPED_VALUE F1002_7057 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "mode";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
	EIF_REAL_64 loc3 = (EIF_REAL_64) 0;
	EIF_REFERENCE loc4 = (EIF_REFERENCE) 0;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur8_1x = {{0}, SK_REAL64};
#define ur8_1 ur8_1x.it_r8
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_REAL_64 Result = ((EIF_REAL_64) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(5);
	RTLR(0,arg1);
	RTLR(1,loc1);
	RTLR(2,Current);
	RTLR(3,tr1);
	RTLR(4,loc4);
	RTLIU(5);
	RTLU (SK_REAL64, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	RTLU(SK_INT32, &loc2);
	RTLU(SK_REAL64, &loc3);
	RTLU(SK_REF, &loc4);
	
	RTEAA(l_feature_name, 1001, Current, 4, 1, 13874);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13874);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("data_not_empty", EX_PRE);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		RTTE((EIF_BOOLEAN) !tb1, label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(1, 0xF80003F8, 0, 0); /* loc1 */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,1016,224,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		tr1 = RTLN(typres0.id);
	}
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	ui4_1 = ti4_1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(3496, Dtype(tr1)))(tr1, ui4_1x);
	RTNHOOK(2,1);
	loc1 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
	loc2 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 0L);
	RTHOOK(4);
	RTDBGAL(3, 0x20000000, 1, 0); /* loc3 */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
	ui4_1 = ti4_1;
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)).it_r8);
	loc3 = (EIF_REAL_64) tr8_1;
	RTHOOK(5);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2758, "new_cursor", arg1))(arg1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc4 = (EIF_REFERENCE) RTCCL(tr1);
	for (;;) {
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2707, "after", loc4))(loc4)).it_b);
		if (tb1) break;
		RTHOOK(6);
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc4))(loc4)).it_r8);
		tr8_2 = tr8_1;
		ur8_1 = tr8_2;
		tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2893, "has", loc1))(loc1, ur8_1x)).it_b);
		if (tb2) {
			RTHOOK(7);
			tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc4))(loc4)).it_r8);
			tr8_2 = tr8_1;
			ur8_1 = tr8_2;
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3501, "item", loc1))(loc1, ur8_1x)).it_i4);
			ui4_1 = (EIF_INTEGER_32) (ti4_1 + ((EIF_INTEGER_32) 1L));
			tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc4))(loc4)).it_r8);
			tr8_2 = tr8_1;
			ur8_1 = tr8_2;
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(2895, "force", loc1))(loc1, ui4_1x, ur8_1x);
		} else {
			RTHOOK(8);
			ui4_1 = ((EIF_INTEGER_32) 1L);
			tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc4))(loc4)).it_r8);
			tr8_2 = tr8_1;
			ur8_1 = tr8_2;
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(2895, "force", loc1))(loc1, ui4_1x, ur8_1x);
		}
		RTHOOK(9);
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc4))(loc4)).it_r8);
		tr8_2 = tr8_1;
		ur8_1 = tr8_2;
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3501, "item", loc1))(loc1, ur8_1x)).it_i4);
		if ((EIF_BOOLEAN) (ti4_1 > loc2)) {
			RTHOOK(10);
			RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
			tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc4))(loc4)).it_r8);
			tr8_2 = tr8_1;
			ur8_1 = tr8_2;
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3501, "item", loc1))(loc1, ur8_1x)).it_i4);
			loc2 = (EIF_INTEGER_32) ti4_1;
			RTHOOK(11);
			RTDBGAL(3, 0x20000000, 1, 0); /* loc3 */
			tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc4))(loc4)).it_r8);
			tr8_2 = tr8_1;
			loc3 = (EIF_REAL_64) tr8_2;
		}
		RTHOOK(12);
		(FUNCTION_CAST(void, (EIF_REFERENCE)) RTVF(2708, "forth", loc4))(loc4);
	}
	RTHOOK(13);
	RTDBGAL(0, 0x20000000, 1,0); /* Result */
	Result = (EIF_REAL_64) loc3;
	if (RTAL & CK_ENSURE) {
		RTHOOK(14);
		RTCT("result_in_data", EX_POST);
		ur8_1 = Result;
		tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2853, "has", arg1))(arg1, ur8_1x)).it_b);
		if (tb2) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(15);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(7);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REAL64; r.it_r8 = Result; return r; }
#undef up1
#undef ur8_1
#undef ui4_1
#undef arg1
}

/* {STATISTICS}.variance */
EIF_TYPED_VALUE F1002_7058 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "variance";
	RTEX;
	EIF_REAL_64 loc1 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc2 = (EIF_REAL_64) 0;
	EIF_REFERENCE loc3 = (EIF_REFERENCE) 0;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_REAL_64 tr8_3;
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	EIF_REAL_64 Result = ((EIF_REAL_64) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(5);
	RTLR(0,arg1);
	RTLR(1,ur1);
	RTLR(2,Current);
	RTLR(3,loc3);
	RTLR(4,tr1);
	RTLIU(5);
	RTLU (SK_REAL64, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_REAL64, &loc1);
	RTLU(SK_REAL64, &loc2);
	RTLU(SK_REF, &loc3);
	
	RTEAA(l_feature_name, 1001, Current, 3, 1, 13875);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13875);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("data_not_empty", EX_PRE);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		RTTE((EIF_BOOLEAN) !tb1, label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(1, 0x20000000, 1, 0); /* loc1 */
	ur1 = RTCCL(arg1);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5323, dtype))(Current, ur1x)).it_r8);
	loc1 = (EIF_REAL_64) tr8_1;
	RTHOOK(3);
	RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
	loc2 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	RTHOOK(4);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2758, "new_cursor", arg1))(arg1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc3 = (EIF_REFERENCE) RTCCL(tr1);
	for (;;) {
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2707, "after", loc3))(loc3)).it_b);
		if (tb1) break;
		RTHOOK(5);
		RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc3))(loc3)).it_r8);
		tr8_2 = tr8_1;
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc3))(loc3)).it_r8);
		tr8_3 = tr8_1;
		loc2 += (EIF_REAL_64) ((EIF_REAL_64) (tr8_2 - loc1) * (EIF_REAL_64) (tr8_3 - loc1));
		RTHOOK(6);
		(FUNCTION_CAST(void, (EIF_REFERENCE)) RTVF(2708, "forth", loc3))(loc3);
	}
	RTHOOK(7);
	RTDBGAL(0, 0x20000000, 1,0); /* Result */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	tr8_1 = (EIF_REAL_64) (ti4_1);
	Result = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) (loc2) /  (EIF_REAL_64) (tr8_1));
	if (RTAL & CK_ENSURE) {
		RTHOOK(8);
		RTCT("result_non_negative", EX_POST);
		if ((EIF_BOOLEAN) eif_is_greater_equal_real_64 (Result, (EIF_REAL_64) 0.0)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(9);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(6);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REAL64; r.it_r8 = Result; return r; }
#undef up1
#undef ur1
#undef arg1
}

/* {STATISTICS}.std_dev */
EIF_TYPED_VALUE F1002_7059 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "std_dev";
	RTEX;
	EIF_REAL_64 loc1 = (EIF_REAL_64) 0;
	EIF_REFERENCE loc2 = (EIF_REFERENCE) 0;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur8_1x = {{0}, SK_REAL64};
#define ur8_1 ur8_1x.it_r8
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_BOOLEAN tb1;
	EIF_REAL_64 Result = ((EIF_REAL_64) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(5);
	RTLR(0,arg1);
	RTLR(1,ur1);
	RTLR(2,Current);
	RTLR(3,loc2);
	RTLR(4,tr1);
	RTLIU(5);
	RTLU (SK_REAL64, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_REAL64, &loc1);
	RTLU(SK_REF, &loc2);
	
	RTEAA(l_feature_name, 1001, Current, 2, 1, 13876);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13876);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("data_not_empty", EX_PRE);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		RTTE((EIF_BOOLEAN) !tb1, label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(1, 0x20000000, 1, 0); /* loc1 */
	ur1 = RTCCL(arg1);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5326, dtype))(Current, ur1x)).it_r8);
	loc1 = (EIF_REAL_64) tr8_1;
	RTHOOK(3);
	RTDBGAL(2, 0xF80003E7, 0, 0); /* loc2 */
	tr1 = RTLN(eif_new_type(999, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(5271, Dtype(tr1)))(tr1);
	RTNHOOK(3,1);
	loc2 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(4);
	RTDBGAL(0, 0x20000000, 1,0); /* Result */
	ur8_1 = loc1;
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5299, "sqrt", loc2))(loc2, ur8_1x)).it_r8);
	Result = (EIF_REAL_64) tr8_1;
	if (RTAL & CK_ENSURE) {
		RTHOOK(5);
		RTCT("result_non_negative", EX_POST);
		if ((EIF_BOOLEAN) eif_is_greater_equal_real_64 (Result, (EIF_REAL_64) 0.0)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(6);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(5);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REAL64; r.it_r8 = Result; return r; }
#undef ur1
#undef ur8_1
#undef arg1
}

/* {STATISTICS}.percentile */
EIF_TYPED_VALUE F1002_7060 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "percentile";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
	EIF_REAL_64 loc2 = (EIF_REAL_64) 0;
	EIF_INTEGER_32 loc3 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc4 = (EIF_INTEGER_32) 0;
	EIF_REAL_64 loc5 = (EIF_REAL_64) 0;
	EIF_INTEGER_32 loc6 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc7 = (EIF_INTEGER_32) 0;
	EIF_REAL_64 loc8 = (EIF_REAL_64) 0;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_r8
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur8_1x = {{0}, SK_REAL64};
#define ur8_1 ur8_1x.it_r8
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_INTEGER_32 ti4_4;
	EIF_BOOLEAN tb1;
	EIF_REAL_64 Result = ((EIF_REAL_64) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_r8 = * (EIF_REAL_64 *) arg2x.it_r;
	
	RTLI(5);
	RTLR(0,arg1);
	RTLR(1,loc1);
	RTLR(2,Current);
	RTLR(3,tr1);
	RTLR(4,ur1);
	RTLIU(5);
	RTLU (SK_REAL64, &Result);
	RTLU(SK_REF,&arg1);
	RTLU(SK_REAL64,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	RTLU(SK_REAL64, &loc2);
	RTLU(SK_INT32, &loc3);
	RTLU(SK_INT32, &loc4);
	RTLU(SK_REAL64, &loc5);
	RTLU(SK_INT32, &loc6);
	RTLU(SK_INT32, &loc7);
	RTLU(SK_REAL64, &loc8);
	
	RTEAA(l_feature_name, 1001, Current, 8, 2, 13877);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13877);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("data_not_empty", EX_PRE);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		RTTE((EIF_BOOLEAN) !tb1, label_1);
		RTCK;
		RTHOOK(2);
		RTCT("percentile_valid", EX_PRE);
		RTTE((EIF_BOOLEAN) ((EIF_BOOLEAN) eif_is_greater_equal_real_64 (arg2, (EIF_REAL_64) 0.0) && (EIF_BOOLEAN) eif_is_less_equal_real_64 (arg2, (EIF_REAL_64) 100.0)), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(3);
	RTDBGAL(1, 0xF80001EF, 0, 0); /* loc1 */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		tr1 = RTLN(typres0.id);
	}
	ur1 = RTCCL(arg1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(3167, Dtype(tr1)))(tr1, ur1x);
	RTNHOOK(3,1);
	loc1 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(4);
	RTDBGAL(6, 0x10000000, 1, 0); /* loc6 */
	ti4_1 = *(EIF_INTEGER_32 *)(loc1 + RTVA(3201, "lower", loc1));
	loc6 = (EIF_INTEGER_32) ti4_1;
	for (;;) {
		RTHOOK(5);
		ti4_1 = *(EIF_INTEGER_32 *)(loc1 + RTVA(3200, "upper", loc1));
		if ((EIF_BOOLEAN) (loc6 >= ti4_1)) break;
		RTHOOK(6);
		RTDBGAL(7, 0x10000000, 1, 0); /* loc7 */
		ti4_2 = *(EIF_INTEGER_32 *)(loc1 + RTVA(3201, "lower", loc1));
		loc7 = (EIF_INTEGER_32) ti4_2;
		for (;;) {
			RTHOOK(7);
			ti4_2 = *(EIF_INTEGER_32 *)(loc1 + RTVA(3200, "upper", loc1));
			ti4_3 = *(EIF_INTEGER_32 *)(loc1 + RTVA(3201, "lower", loc1));
			if ((EIF_BOOLEAN) (loc7 >= (EIF_INTEGER_32) (ti4_2 - (EIF_INTEGER_32) (loc6 - ti4_3)))) break;
			RTHOOK(8);
			ui4_1 = loc7;
			tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", loc1))(loc1, ui4_1x)).it_r8);
			ui4_1 = (EIF_INTEGER_32) (loc7 + ((EIF_INTEGER_32) 1L));
			tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", loc1))(loc1, ui4_1x)).it_r8);
			if ((EIF_BOOLEAN) eif_is_greater_real_64 (tr8_1, tr8_2)) {
				RTHOOK(9);
				RTDBGAL(8, 0x20000000, 1, 0); /* loc8 */
				ui4_1 = loc7;
				tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", loc1))(loc1, ui4_1x)).it_r8);
				loc8 = (EIF_REAL_64) tr8_1;
				RTHOOK(10);
				ui4_1 = (EIF_INTEGER_32) (loc7 + ((EIF_INTEGER_32) 1L));
				tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", loc1))(loc1, ui4_1x)).it_r8);
				ur8_1 = tr8_1;
				ui4_1 = loc7;
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(2894, "put", loc1))(loc1, ur8_1x, ui4_1x);
				RTHOOK(11);
				ur8_1 = loc8;
				ui4_1 = (EIF_INTEGER_32) (loc7 + ((EIF_INTEGER_32) 1L));
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(2894, "put", loc1))(loc1, ur8_1x, ui4_1x);
			}
			RTHOOK(12);
			RTDBGAL(7, 0x10000000, 1, 0); /* loc7 */
			loc7++;
		}
		RTHOOK(13);
		RTDBGAL(6, 0x10000000, 1, 0); /* loc6 */
		loc6++;
	}
	RTHOOK(14);
	RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
	ti4_4 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", loc1))(loc1)).it_i4);
	tr8_1 = (EIF_REAL_64) ((EIF_INTEGER_32) (ti4_4 - ((EIF_INTEGER_32) 1L)));
	loc2 = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) (arg2) /  (EIF_REAL_64) ((EIF_REAL_64) 100.0)) * tr8_1);
	RTHOOK(15);
	RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
	tr1 = RTLN(eif_new_type(245, 0x00).id);
	*(EIF_REAL_64 *)tr1 = loc2;
	ti4_4 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(4245, "floor", tr1))(tr1)).it_i4);
	loc3 = (EIF_INTEGER_32) ti4_4;
	RTHOOK(16);
	RTDBGAL(4, 0x10000000, 1, 0); /* loc4 */
	tr1 = RTLN(eif_new_type(245, 0x00).id);
	*(EIF_REAL_64 *)tr1 = loc2;
	ti4_4 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(4244, "ceiling", tr1))(tr1)).it_i4);
	loc4 = (EIF_INTEGER_32) ti4_4;
	RTHOOK(17);
	if ((EIF_BOOLEAN)(loc3 == loc4)) {
		RTHOOK(18);
		RTDBGAL(0, 0x20000000, 1,0); /* Result */
		ti4_4 = *(EIF_INTEGER_32 *)(loc1 + RTVA(3201, "lower", loc1));
		ui4_1 = (EIF_INTEGER_32) (ti4_4 + loc3);
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", loc1))(loc1, ui4_1x)).it_r8);
		Result = (EIF_REAL_64) tr8_1;
	} else {
		RTHOOK(19);
		RTDBGAL(5, 0x20000000, 1, 0); /* loc5 */
		tr1 = RTLN(eif_new_type(245, 0x00).id);
		*(EIF_REAL_64 *)tr1 = loc2;
		ti4_4 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(4245, "floor", tr1))(tr1)).it_i4);
		tr8_1 = (EIF_REAL_64) (ti4_4);
		loc5 = (EIF_REAL_64) (EIF_REAL_64) (loc2 - tr8_1);
		RTHOOK(20);
		RTDBGAL(0, 0x20000000, 1,0); /* Result */
		ti4_4 = *(EIF_INTEGER_32 *)(loc1 + RTVA(3201, "lower", loc1));
		ui4_1 = (EIF_INTEGER_32) (ti4_4 + loc3);
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", loc1))(loc1, ui4_1x)).it_r8);
		ti4_4 = *(EIF_INTEGER_32 *)(loc1 + RTVA(3201, "lower", loc1));
		ui4_1 = (EIF_INTEGER_32) (ti4_4 + loc4);
		tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", loc1))(loc1, ui4_1x)).it_r8);
		Result = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) (tr8_1 * (EIF_REAL_64) ((EIF_REAL_64) 1.0 - loc5)) + (EIF_REAL_64) (tr8_2 * loc5));
	}
	if (RTAL & CK_ENSURE) {
		RTHOOK(21);
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(22);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(12);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REAL64; r.it_r8 = Result; return r; }
#undef ur1
#undef ur8_1
#undef ui4_1
#undef arg2
#undef arg1
}

/* {STATISTICS}.quartiles */
EIF_TYPED_VALUE F1002_7061 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "quartiles";
	RTEX;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur8_1x = {{0}, SK_REAL64};
#define ur8_1 ur8_1x.it_r8
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(5);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLR(2,tr1);
	RTLR(3,Result);
	RTLR(4,ur1);
	RTLIU(5);
	RTLU (SK_REF, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1001, Current, 0, 1, 13878);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13878);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("data_not_empty", EX_PRE);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		RTTE((EIF_BOOLEAN) !tb1, label_1);
		RTCK;
		RTHOOK(2);
		RTCT("sufficient_data", EX_PRE);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		RTTE((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 4L)), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(3);
	RTDBGAL(0, 0xF80001EF, 0,0); /* Result */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		tr1 = RTLN(typres0.id);
	}
	ur8_1 = (EIF_REAL_64) 0.0;
	ui4_1 = ((EIF_INTEGER_32) 1L);
	ui4_2 = ((EIF_INTEGER_32) 3L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWC(3165, Dtype(tr1)))(tr1, ur8_1x, ui4_1x, ui4_2x);
	RTNHOOK(3,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(4);
	ur1 = RTCCL(arg1);
	ur8_1 = (EIF_REAL_64) 25.0;
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(5328, dtype))(Current, ur1x, ur8_1x)).it_r8);
	ur8_1 = tr8_1;
	ui4_1 = ((EIF_INTEGER_32) 1L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(2894, "put", Result))(Result, ur8_1x, ui4_1x);
	RTHOOK(5);
	ur1 = RTCCL(arg1);
	ur8_1 = (EIF_REAL_64) 50.0;
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(5328, dtype))(Current, ur1x, ur8_1x)).it_r8);
	ur8_1 = tr8_1;
	ui4_1 = ((EIF_INTEGER_32) 2L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(2894, "put", Result))(Result, ur8_1x, ui4_1x);
	RTHOOK(6);
	ur1 = RTCCL(arg1);
	ur8_1 = (EIF_REAL_64) 75.0;
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(5328, dtype))(Current, ur1x, ur8_1x)).it_r8);
	ur8_1 = tr8_1;
	ui4_1 = ((EIF_INTEGER_32) 3L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(2894, "put", Result))(Result, ur8_1x, ui4_1x);
	if (RTAL & CK_ENSURE) {
		RTHOOK(7);
		RTCT("result_size", EX_POST);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", Result))(Result)).it_i4);
		if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 3L))) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(8);
		RTCT("ordered", EX_POST);
		tb1 = '\0';
		ui4_1 = ((EIF_INTEGER_32) 1L);
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", Result))(Result, ui4_1x)).it_r8);
		ui4_1 = ((EIF_INTEGER_32) 2L);
		tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", Result))(Result, ui4_1x)).it_r8);
		if ((EIF_BOOLEAN) eif_is_less_equal_real_64 (tr8_1, tr8_2)) {
			ui4_1 = ((EIF_INTEGER_32) 2L);
			tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", Result))(Result, ui4_1x)).it_r8);
			ui4_1 = ((EIF_INTEGER_32) 3L);
			tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", Result))(Result, ui4_1x)).it_r8);
			tb1 = (EIF_BOOLEAN) eif_is_less_equal_real_64 (tr8_1, tr8_2);
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(9);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef ur1
#undef ur8_1
#undef ui4_1
#undef ui4_2
#undef arg1
}

/* {STATISTICS}.min_value */
EIF_TYPED_VALUE F1002_7062 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "min_value";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur8_1x = {{0}, SK_REAL64};
#define ur8_1 ur8_1x.it_r8
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_REAL_64 Result = ((EIF_REAL_64) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(4);
	RTLR(0,arg1);
	RTLR(1,loc1);
	RTLR(2,tr1);
	RTLR(3,Current);
	RTLIU(4);
	RTLU (SK_REAL64, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	
	RTEAA(l_feature_name, 1001, Current, 1, 1, 13879);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13879);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("data_not_empty", EX_PRE);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		RTTE((EIF_BOOLEAN) !tb1, label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(0, 0x20000000, 1,0); /* Result */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
	ui4_1 = ti4_1;
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)).it_r8);
	Result = (EIF_REAL_64) tr8_1;
	RTHOOK(3);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2758, "new_cursor", arg1))(arg1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc1 = (EIF_REFERENCE) RTCCL(tr1);
	for (;;) {
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2707, "after", loc1))(loc1)).it_b);
		if (tb1) break;
		RTHOOK(4);
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc1))(loc1)).it_r8);
		tr8_2 = tr8_1;
		if ((EIF_BOOLEAN) eif_is_less_real_64 (tr8_2, Result)) {
			RTHOOK(5);
			RTDBGAL(0, 0x20000000, 1,0); /* Result */
			tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc1))(loc1)).it_r8);
			tr8_2 = tr8_1;
			Result = (EIF_REAL_64) tr8_2;
		}
		RTHOOK(6);
		(FUNCTION_CAST(void, (EIF_REFERENCE)) RTVF(2708, "forth", loc1))(loc1);
	}
	if (RTAL & CK_ENSURE) {
		RTHOOK(7);
		RTCT("result_in_data", EX_POST);
		ur8_1 = Result;
		tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2853, "has", arg1))(arg1, ur8_1x)).it_b);
		if (tb2) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(8);
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(9);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REAL64; r.it_r8 = Result; return r; }
#undef up1
#undef ur8_1
#undef ui4_1
#undef arg1
}

/* {STATISTICS}.max_value */
EIF_TYPED_VALUE F1002_7063 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "max_value";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur8_1x = {{0}, SK_REAL64};
#define ur8_1 ur8_1x.it_r8
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_REAL_64 Result = ((EIF_REAL_64) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(4);
	RTLR(0,arg1);
	RTLR(1,loc1);
	RTLR(2,tr1);
	RTLR(3,Current);
	RTLIU(4);
	RTLU (SK_REAL64, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	
	RTEAA(l_feature_name, 1001, Current, 1, 1, 13880);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13880);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("data_not_empty", EX_PRE);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		RTTE((EIF_BOOLEAN) !tb1, label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(0, 0x20000000, 1,0); /* Result */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
	ui4_1 = ti4_1;
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)).it_r8);
	Result = (EIF_REAL_64) tr8_1;
	RTHOOK(3);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2758, "new_cursor", arg1))(arg1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc1 = (EIF_REFERENCE) RTCCL(tr1);
	for (;;) {
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2707, "after", loc1))(loc1)).it_b);
		if (tb1) break;
		RTHOOK(4);
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc1))(loc1)).it_r8);
		tr8_2 = tr8_1;
		if ((EIF_BOOLEAN) eif_is_greater_real_64 (tr8_2, Result)) {
			RTHOOK(5);
			RTDBGAL(0, 0x20000000, 1,0); /* Result */
			tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc1))(loc1)).it_r8);
			tr8_2 = tr8_1;
			Result = (EIF_REAL_64) tr8_2;
		}
		RTHOOK(6);
		(FUNCTION_CAST(void, (EIF_REFERENCE)) RTVF(2708, "forth", loc1))(loc1);
	}
	if (RTAL & CK_ENSURE) {
		RTHOOK(7);
		RTCT("result_in_data", EX_POST);
		ur8_1 = Result;
		tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2853, "has", arg1))(arg1, ur8_1x)).it_b);
		if (tb2) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(8);
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(9);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REAL64; r.it_r8 = Result; return r; }
#undef up1
#undef ur8_1
#undef ui4_1
#undef arg1
}

/* {STATISTICS}.range */
EIF_TYPED_VALUE F1002_7064 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "range";
	RTEX;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_BOOLEAN tb1;
	EIF_REAL_64 Result = ((EIF_REAL_64) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(3);
	RTLR(0,arg1);
	RTLR(1,ur1);
	RTLR(2,Current);
	RTLIU(3);
	RTLU (SK_REAL64, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1001, Current, 0, 1, 13881);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13881);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("data_not_empty", EX_PRE);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		RTTE((EIF_BOOLEAN) !tb1, label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(0, 0x20000000, 1,0); /* Result */
	ur1 = RTCCL(arg1);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5331, dtype))(Current, ur1x)).it_r8);
	ur1 = RTCCL(arg1);
	tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5330, dtype))(Current, ur1x)).it_r8);
	Result = (EIF_REAL_64) (EIF_REAL_64) (tr8_1 - tr8_2);
	if (RTAL & CK_ENSURE) {
		RTHOOK(3);
		RTCT("result_non_negative", EX_POST);
		if ((EIF_BOOLEAN) eif_is_greater_equal_real_64 (Result, (EIF_REAL_64) 0.0)) {
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
	{ EIF_TYPED_VALUE r; r.type = SK_REAL64; r.it_r8 = Result; return r; }
#undef ur1
#undef arg1
}

/* {STATISTICS}.sum */
EIF_TYPED_VALUE F1002_7065 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "sum";
	RTEX;
	EIF_REAL_64 loc1 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc2 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc3 = (EIF_REAL_64) 0;
	EIF_REFERENCE loc4 = (EIF_REFERENCE) 0;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_BOOLEAN tb1;
	EIF_REAL_64 Result = ((EIF_REAL_64) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(4);
	RTLR(0,arg1);
	RTLR(1,loc4);
	RTLR(2,tr1);
	RTLR(3,Current);
	RTLIU(4);
	RTLU (SK_REAL64, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_REAL64, &loc1);
	RTLU(SK_REAL64, &loc2);
	RTLU(SK_REAL64, &loc3);
	RTLU(SK_REF, &loc4);
	
	RTEAA(l_feature_name, 1001, Current, 4, 1, 13882);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13882);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("data_not_empty", EX_PRE);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		RTTE((EIF_BOOLEAN) !tb1, label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(1, 0x20000000, 1, 0); /* loc1 */
	loc1 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	RTHOOK(3);
	RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
	loc2 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	RTHOOK(4);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2758, "new_cursor", arg1))(arg1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc4 = (EIF_REFERENCE) RTCCL(tr1);
	for (;;) {
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2707, "after", loc4))(loc4)).it_b);
		if (tb1) break;
		RTHOOK(5);
		RTDBGAL(3, 0x20000000, 1, 0); /* loc3 */
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc4))(loc4)).it_r8);
		tr8_2 = tr8_1;
		loc3 = (EIF_REAL_64) (EIF_REAL_64) (tr8_2 - loc2);
		RTHOOK(6);
		RTDBGAL(1, 0x20000000, 1, 0); /* loc1 */
		loc1 += loc3;
		RTHOOK(7);
		RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2706, "item", loc4))(loc4)).it_r8);
		tr8_2 = tr8_1;
		loc2 = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) (loc1 - tr8_2) - loc3);
		RTHOOK(8);
		(FUNCTION_CAST(void, (EIF_REFERENCE)) RTVF(2708, "forth", loc4))(loc4);
	}
	RTHOOK(9);
	RTDBGAL(0, 0x20000000, 1,0); /* Result */
	Result = (EIF_REAL_64) loc1;
	if (RTAL & CK_ENSURE) {
		RTHOOK(10);
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(11);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(7);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REAL64; r.it_r8 = Result; return r; }
#undef up1
#undef arg1
}

/* {STATISTICS}.correlation */
EIF_TYPED_VALUE F1002_7066 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "correlation";
	RTEX;
	EIF_REAL_64 loc1 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc2 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc3 = (EIF_REAL_64) 0;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur2x = {{0}, SK_REF};
#define ur2 ur2x.it_r
	EIF_REAL_64 tr8_1;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_REAL_64 Result = ((EIF_REAL_64) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(5);
	RTLR(0,arg1);
	RTLR(1,arg2);
	RTLR(2,ur1);
	RTLR(3,ur2);
	RTLR(4,Current);
	RTLIU(5);
	RTLU (SK_REAL64, &Result);
	RTLU(SK_REF,&arg1);
	RTLU(SK_REF,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_REAL64, &loc1);
	RTLU(SK_REAL64, &loc2);
	RTLU(SK_REAL64, &loc3);
	
	RTEAA(l_feature_name, 1001, Current, 3, 2, 13883);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13883);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg2, 1001, l_feature_name, 2, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("same_length", EX_PRE);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg2))(arg2)).it_i4);
		RTTE((EIF_BOOLEAN)(ti4_1 == ti4_2), label_1);
		RTCK;
		RTHOOK(2);
		RTCT("data_valid", EX_PRE);
		tb1 = '\0';
		tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		if ((EIF_BOOLEAN) !tb2) {
			tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg2))(arg2)).it_b);
			tb1 = (EIF_BOOLEAN) !tb2;
		}
		RTTE(tb1, label_1);
		RTCK;
		RTHOOK(3);
		RTCT("sufficient_data", EX_PRE);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		RTTE((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 2L)), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(4);
	RTDBGAL(1, 0x20000000, 1, 0); /* loc1 */
	ur1 = RTCCL(arg1);
	ur2 = RTCCL(arg2);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(5335, dtype))(Current, ur1x, ur2x)).it_r8);
	loc1 = (EIF_REAL_64) tr8_1;
	RTHOOK(5);
	RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
	ur1 = RTCCL(arg1);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5327, dtype))(Current, ur1x)).it_r8);
	loc2 = (EIF_REAL_64) tr8_1;
	RTHOOK(6);
	RTDBGAL(3, 0x20000000, 1, 0); /* loc3 */
	ur1 = RTCCL(arg2);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5327, dtype))(Current, ur1x)).it_r8);
	loc3 = (EIF_REAL_64) tr8_1;
	RTHOOK(7);
	if ((EIF_BOOLEAN) ((EIF_BOOLEAN) eif_is_equal_real_64 (loc2, (EIF_REAL_64) 0.0) || (EIF_BOOLEAN) eif_is_equal_real_64 (loc3, (EIF_REAL_64) 0.0))) {
		RTHOOK(8);
		RTDBGAL(0, 0x20000000, 1,0); /* Result */
		Result = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	} else {
		RTHOOK(9);
		RTDBGAL(0, 0x20000000, 1,0); /* Result */
		Result = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) (loc1) /  (EIF_REAL_64) ((EIF_REAL_64) (loc2 * loc3)));
	}
	if (RTAL & CK_ENSURE) {
		RTHOOK(10);
		RTCT("result_in_range", EX_POST);
		if ((EIF_BOOLEAN) ((EIF_BOOLEAN) eif_is_greater_equal_real_64 (Result, (EIF_REAL_64) -1.0) && (EIF_BOOLEAN) eif_is_less_equal_real_64 (Result, (EIF_REAL_64) 1.0))) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(11);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(7);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REAL64; r.it_r8 = Result; return r; }
#undef ur1
#undef ur2
#undef arg2
#undef arg1
}

/* {STATISTICS}.covariance */
EIF_TYPED_VALUE F1002_7067 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "covariance";
	RTEX;
	EIF_REAL_64 loc1 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc2 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc3 = (EIF_REAL_64) 0;
	EIF_INTEGER_32 loc4 = (EIF_INTEGER_32) 0;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_REAL_64 Result = ((EIF_REAL_64) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(4);
	RTLR(0,arg1);
	RTLR(1,arg2);
	RTLR(2,ur1);
	RTLR(3,Current);
	RTLIU(4);
	RTLU (SK_REAL64, &Result);
	RTLU(SK_REF,&arg1);
	RTLU(SK_REF,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_REAL64, &loc1);
	RTLU(SK_REAL64, &loc2);
	RTLU(SK_REAL64, &loc3);
	RTLU(SK_INT32, &loc4);
	
	RTEAA(l_feature_name, 1001, Current, 4, 2, 13884);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13884);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg2, 1001, l_feature_name, 2, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("same_length", EX_PRE);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg2))(arg2)).it_i4);
		RTTE((EIF_BOOLEAN)(ti4_1 == ti4_2), label_1);
		RTCK;
		RTHOOK(2);
		RTCT("data_valid", EX_PRE);
		tb1 = '\0';
		tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		if ((EIF_BOOLEAN) !tb2) {
			tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg2))(arg2)).it_b);
			tb1 = (EIF_BOOLEAN) !tb2;
		}
		RTTE(tb1, label_1);
		RTCK;
		RTHOOK(3);
		RTCT("sufficient_data", EX_PRE);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		RTTE((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 2L)), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(4);
	RTDBGAL(1, 0x20000000, 1, 0); /* loc1 */
	ur1 = RTCCL(arg1);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5323, dtype))(Current, ur1x)).it_r8);
	loc1 = (EIF_REAL_64) tr8_1;
	RTHOOK(5);
	RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
	ur1 = RTCCL(arg2);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5323, dtype))(Current, ur1x)).it_r8);
	loc2 = (EIF_REAL_64) tr8_1;
	RTHOOK(6);
	RTDBGAL(3, 0x20000000, 1, 0); /* loc3 */
	loc3 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	RTHOOK(7);
	RTDBGAL(4, 0x10000000, 1, 0); /* loc4 */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
	loc4 = (EIF_INTEGER_32) ti4_1;
	for (;;) {
		RTHOOK(8);
		ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3200, "upper", arg1));
		if ((EIF_BOOLEAN) (loc4 > ti4_1)) break;
		RTHOOK(9);
		RTDBGAL(3, 0x20000000, 1, 0); /* loc3 */
		ui4_1 = loc4;
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)).it_r8);
		ti4_2 = *(EIF_INTEGER_32 *)(arg2 + RTVA(3201, "lower", arg2));
		ti4_3 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
		ui4_1 = (EIF_INTEGER_32) (ti4_2 + (EIF_INTEGER_32) (loc4 - ti4_3));
		tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg2))(arg2, ui4_1x)).it_r8);
		loc3 += (EIF_REAL_64) ((EIF_REAL_64) (tr8_1 - loc1) * (EIF_REAL_64) (tr8_2 - loc2));
		RTHOOK(10);
		RTDBGAL(4, 0x10000000, 1, 0); /* loc4 */
		loc4++;
	}
	RTHOOK(11);
	RTDBGAL(0, 0x20000000, 1,0); /* Result */
	ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	tr8_1 = (EIF_REAL_64) (ti4_2);
	Result = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) (loc3) /  (EIF_REAL_64) (tr8_1));
	if (RTAL & CK_ENSURE) {
		RTHOOK(12);
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(13);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(8);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REAL64; r.it_r8 = Result; return r; }
#undef ur1
#undef ui4_1
#undef arg2
#undef arg1
}

/* {STATISTICS}.linear_regression */
EIF_TYPED_VALUE F1002_7068 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "linear_regression";
	RTEX;
	EIF_REAL_64 loc1 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc2 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc3 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc4 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc5 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc6 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc7 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc8 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc9 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc10 = (EIF_REAL_64) 0;
	EIF_INTEGER_32 loc11 = (EIF_INTEGER_32) 0;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur8_1x = {{0}, SK_REAL64};
#define ur8_1 ur8_1x.it_r8
	EIF_TYPED_VALUE ur8_2x = {{0}, SK_REAL64};
#define ur8_2 ur8_2x.it_r8
	EIF_TYPED_VALUE ur8_3x = {{0}, SK_REAL64};
#define ur8_3 ur8_3x.it_r8
	EIF_TYPED_VALUE ur8_4x = {{0}, SK_REAL64};
#define ur8_4 ur8_4x.it_r8
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_INTEGER_32 ti4_4;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(6);
	RTLR(0,arg1);
	RTLR(1,arg2);
	RTLR(2,ur1);
	RTLR(3,Current);
	RTLR(4,tr1);
	RTLR(5,Result);
	RTLIU(6);
	RTLU (SK_REF, &Result);
	RTLU(SK_REF,&arg1);
	RTLU(SK_REF,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_REAL64, &loc1);
	RTLU(SK_REAL64, &loc2);
	RTLU(SK_REAL64, &loc3);
	RTLU(SK_REAL64, &loc4);
	RTLU(SK_REAL64, &loc5);
	RTLU(SK_REAL64, &loc6);
	RTLU(SK_REAL64, &loc7);
	RTLU(SK_REAL64, &loc8);
	RTLU(SK_REAL64, &loc9);
	RTLU(SK_REAL64, &loc10);
	RTLU(SK_INT32, &loc11);
	
	RTEAA(l_feature_name, 1001, Current, 11, 2, 13864);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13864);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg2, 1001, l_feature_name, 2, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("same_length", EX_PRE);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg2))(arg2)).it_i4);
		RTTE((EIF_BOOLEAN)(ti4_1 == ti4_2), label_1);
		RTCK;
		RTHOOK(2);
		RTCT("data_valid", EX_PRE);
		tb1 = '\0';
		tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		if ((EIF_BOOLEAN) !tb2) {
			tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg2))(arg2)).it_b);
			tb1 = (EIF_BOOLEAN) !tb2;
		}
		RTTE(tb1, label_1);
		RTCK;
		RTHOOK(3);
		RTCT("sufficient_data", EX_PRE);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		RTTE((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 3L)), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(4);
	RTDBGAL(1, 0x20000000, 1, 0); /* loc1 */
	ur1 = RTCCL(arg1);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5323, dtype))(Current, ur1x)).it_r8);
	loc1 = (EIF_REAL_64) tr8_1;
	RTHOOK(5);
	RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
	ur1 = RTCCL(arg2);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5323, dtype))(Current, ur1x)).it_r8);
	loc2 = (EIF_REAL_64) tr8_1;
	RTHOOK(6);
	RTDBGAL(3, 0x20000000, 1, 0); /* loc3 */
	loc3 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	RTHOOK(7);
	RTDBGAL(4, 0x20000000, 1, 0); /* loc4 */
	loc4 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	RTHOOK(8);
	RTDBGAL(11, 0x10000000, 1, 0); /* loc11 */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
	loc11 = (EIF_INTEGER_32) ti4_1;
	for (;;) {
		RTHOOK(9);
		ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3200, "upper", arg1));
		if ((EIF_BOOLEAN) (loc11 > ti4_1)) break;
		RTHOOK(10);
		RTDBGAL(3, 0x20000000, 1, 0); /* loc3 */
		ui4_1 = loc11;
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)).it_r8);
		ti4_2 = *(EIF_INTEGER_32 *)(arg2 + RTVA(3201, "lower", arg2));
		ti4_3 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
		ui4_1 = (EIF_INTEGER_32) (ti4_2 + (EIF_INTEGER_32) (loc11 - ti4_3));
		tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg2))(arg2, ui4_1x)).it_r8);
		loc3 += (EIF_REAL_64) ((EIF_REAL_64) (tr8_1 - loc1) * (EIF_REAL_64) (tr8_2 - loc2));
		RTHOOK(11);
		RTDBGAL(4, 0x20000000, 1, 0); /* loc4 */
		ui4_1 = loc11;
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)).it_r8);
		ui4_1 = loc11;
		tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)).it_r8);
		loc4 += (EIF_REAL_64) ((EIF_REAL_64) (tr8_1 - loc1) * (EIF_REAL_64) (tr8_2 - loc1));
		RTHOOK(12);
		RTDBGAL(11, 0x10000000, 1, 0); /* loc11 */
		loc11++;
	}
	RTHOOK(13);
	if ((EIF_BOOLEAN) eif_is_equal_real_64 (loc4, (EIF_REAL_64) 0.0)) {
		RTHOOK(14);
		RTDBGAL(5, 0x20000000, 1, 0); /* loc5 */
		loc5 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	} else {
		RTHOOK(15);
		RTDBGAL(5, 0x20000000, 1, 0); /* loc5 */
		loc5 = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) (loc3) /  (EIF_REAL_64) (loc4));
	}
	RTHOOK(16);
	RTDBGAL(6, 0x20000000, 1, 0); /* loc6 */
	loc6 = (EIF_REAL_64) (EIF_REAL_64) (loc2 - (EIF_REAL_64) (loc5 * loc1));
	RTHOOK(17);
	RTDBGAL(8, 0x20000000, 1, 0); /* loc8 */
	loc8 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	RTHOOK(18);
	RTDBGAL(9, 0x20000000, 1, 0); /* loc9 */
	loc9 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	RTHOOK(19);
	RTDBGAL(11, 0x10000000, 1, 0); /* loc11 */
	ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
	loc11 = (EIF_INTEGER_32) ti4_2;
	for (;;) {
		RTHOOK(20);
		ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3200, "upper", arg1));
		if ((EIF_BOOLEAN) (loc11 > ti4_2)) break;
		RTHOOK(21);
		RTDBGAL(7, 0x20000000, 1, 0); /* loc7 */
		ui4_1 = loc11;
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)).it_r8);
		loc7 = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) (loc5 * tr8_1) + loc6);
		RTHOOK(22);
		RTDBGAL(8, 0x20000000, 1, 0); /* loc8 */
		ti4_3 = *(EIF_INTEGER_32 *)(arg2 + RTVA(3201, "lower", arg2));
		ti4_4 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
		ui4_1 = (EIF_INTEGER_32) (ti4_3 + (EIF_INTEGER_32) (loc11 - ti4_4));
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg2))(arg2, ui4_1x)).it_r8);
		ti4_3 = *(EIF_INTEGER_32 *)(arg2 + RTVA(3201, "lower", arg2));
		ti4_4 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
		ui4_1 = (EIF_INTEGER_32) (ti4_3 + (EIF_INTEGER_32) (loc11 - ti4_4));
		tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg2))(arg2, ui4_1x)).it_r8);
		loc8 += (EIF_REAL_64) ((EIF_REAL_64) (tr8_1 - loc7) * (EIF_REAL_64) (tr8_2 - loc7));
		RTHOOK(23);
		RTDBGAL(9, 0x20000000, 1, 0); /* loc9 */
		ti4_3 = *(EIF_INTEGER_32 *)(arg2 + RTVA(3201, "lower", arg2));
		ti4_4 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
		ui4_1 = (EIF_INTEGER_32) (ti4_3 + (EIF_INTEGER_32) (loc11 - ti4_4));
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg2))(arg2, ui4_1x)).it_r8);
		ti4_3 = *(EIF_INTEGER_32 *)(arg2 + RTVA(3201, "lower", arg2));
		ti4_4 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
		ui4_1 = (EIF_INTEGER_32) (ti4_3 + (EIF_INTEGER_32) (loc11 - ti4_4));
		tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg2))(arg2, ui4_1x)).it_r8);
		loc9 += (EIF_REAL_64) ((EIF_REAL_64) (tr8_1 - loc2) * (EIF_REAL_64) (tr8_2 - loc2));
		RTHOOK(24);
		RTDBGAL(11, 0x10000000, 1, 0); /* loc11 */
		loc11++;
	}
	RTHOOK(25);
	if ((EIF_BOOLEAN) eif_is_equal_real_64 (loc9, (EIF_REAL_64) 0.0)) {
		RTHOOK(26);
		RTDBGAL(10, 0x20000000, 1, 0); /* loc10 */
		loc10 = (EIF_REAL_64) (EIF_REAL_64) 1.0;
	} else {
		RTHOOK(27);
		RTDBGAL(10, 0x20000000, 1, 0); /* loc10 */
		loc10 = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) 1.0 - (EIF_REAL_64) ((EIF_REAL_64) (loc8) /  (EIF_REAL_64) (loc9)));
	}
	RTHOOK(28);
	if ((EIF_BOOLEAN) eif_is_less_real_64 (loc10, (EIF_REAL_64) 0.0)) {
		RTHOOK(29);
		RTDBGAL(10, 0x20000000, 1, 0); /* loc10 */
		loc10 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	} else {
		RTHOOK(30);
		if ((EIF_BOOLEAN) eif_is_greater_real_64 (loc10, (EIF_REAL_64) 1.0)) {
			RTHOOK(31);
			RTDBGAL(10, 0x20000000, 1, 0); /* loc10 */
			loc10 = (EIF_REAL_64) (EIF_REAL_64) 1.0;
		}
	}
	RTHOOK(32);
	RTDBGAL(0, 0xF80003E5, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(997, 0x01).id);
	ur8_1 = loc5;
	ur8_2 = loc6;
	ur8_3 = loc10;
	ur1 = RTCCL(arg1);
	ur8_4 = (EIF_REAL_64) 1.0;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWC(5266, Dtype(tr1)))(tr1, ur8_1x, ur8_2x, ur8_3x, ur1x, ur8_4x);
	RTNHOOK(32,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	if (RTAL & CK_ENSURE) {
		RTHOOK(33);
		RTCT("result_valid", EX_POST);
		if ((EIF_BOOLEAN)(Result != NULL)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(34);
		RTCT("r2_valid", EX_POST);
		tb1 = '\0';
		tr8_1 = *(EIF_REAL_64 *)(Result + RTVA(5261, "r_squared", Result));
		if ((EIF_BOOLEAN) eif_is_greater_equal_real_64 (tr8_1, (EIF_REAL_64) 0.0)) {
			tr8_1 = *(EIF_REAL_64 *)(Result + RTVA(5261, "r_squared", Result));
			tb1 = (EIF_BOOLEAN) eif_is_less_equal_real_64 (tr8_1, (EIF_REAL_64) 1.0);
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(35);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(15);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef ur1
#undef ur8_1
#undef ur8_2
#undef ur8_3
#undef ur8_4
#undef ui4_1
#undef arg2
#undef arg1
}

/* {STATISTICS}.t_test_one_sample */
EIF_TYPED_VALUE F1002_7069 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "t_test_one_sample";
	RTEX;
	EIF_REAL_64 loc1 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc2 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc3 = (EIF_REAL_64) 0;
	EIF_INTEGER_32 loc4 = (EIF_INTEGER_32) 0;
	EIF_REAL_64 loc5 = (EIF_REAL_64) 0;
	EIF_REFERENCE loc6 = (EIF_REFERENCE) 0;
	EIF_REAL_64 loc7 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc8 = (EIF_REAL_64) 0;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_r8
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur8_1x = {{0}, SK_REAL64};
#define ur8_1 ur8_1x.it_r8
	EIF_TYPED_VALUE ur8_2x = {{0}, SK_REAL64};
#define ur8_2 ur8_2x.it_r8
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_BOOLEAN tb1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_r8 = * (EIF_REAL_64 *) arg2x.it_r;
	
	RTLI(7);
	RTLR(0,arg1);
	RTLR(1,ur1);
	RTLR(2,Current);
	RTLR(3,loc6);
	RTLR(4,tr1);
	RTLR(5,tr2);
	RTLR(6,Result);
	RTLIU(7);
	RTLU (SK_REF, &Result);
	RTLU(SK_REF,&arg1);
	RTLU(SK_REAL64,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_REAL64, &loc1);
	RTLU(SK_REAL64, &loc2);
	RTLU(SK_REAL64, &loc3);
	RTLU(SK_INT32, &loc4);
	RTLU(SK_REAL64, &loc5);
	RTLU(SK_REF, &loc6);
	RTLU(SK_REAL64, &loc7);
	RTLU(SK_REAL64, &loc8);
	
	RTEAA(l_feature_name, 1001, Current, 8, 2, 13865);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13865);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("data_not_empty", EX_PRE);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		RTTE((EIF_BOOLEAN) !tb1, label_1);
		RTCK;
		RTHOOK(2);
		RTCT("sufficient_data", EX_PRE);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		RTTE((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 2L)), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(3);
	RTDBGAL(1, 0x20000000, 1, 0); /* loc1 */
	ur1 = RTCCL(arg1);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5323, dtype))(Current, ur1x)).it_r8);
	loc1 = (EIF_REAL_64) tr8_1;
	RTHOOK(4);
	RTDBGAL(6, 0xF80003E7, 0, 0); /* loc6 */
	tr1 = RTLN(eif_new_type(999, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(5271, Dtype(tr1)))(tr1);
	RTNHOOK(4,1);
	loc6 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(5);
	RTDBGAL(8, 0x20000000, 1, 0); /* loc8 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	tr8_1 = (EIF_REAL_64) (ti4_1);
	loc8 = (EIF_REAL_64) tr8_1;
	RTHOOK(6);
	RTDBGAL(7, 0x20000000, 1, 0); /* loc7 */
	ur8_1 = loc8;
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5299, "sqrt", loc6))(loc6, ur8_1x)).it_r8);
	loc7 = (EIF_REAL_64) tr8_1;
	RTHOOK(7);
	RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
	ur1 = RTCCL(arg1);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5327, dtype))(Current, ur1x)).it_r8);
	loc2 = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) (tr8_1) /  (EIF_REAL_64) (loc7));
	RTHOOK(8);
	RTDBGAL(3, 0x20000000, 1, 0); /* loc3 */
	loc3 = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) (loc1 - arg2)) /  (EIF_REAL_64) (loc2));
	RTHOOK(9);
	RTDBGAL(4, 0x10000000, 1, 0); /* loc4 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	loc4 = (EIF_INTEGER_32) (EIF_INTEGER_32) (ti4_1 - ((EIF_INTEGER_32) 1L));
	RTHOOK(10);
	RTDBGAL(5, 0x20000000, 1, 0); /* loc5 */
	loc5 = (EIF_REAL_64) (EIF_REAL_64) 0.5;
	RTHOOK(11);
	RTDBGAL(0, 0xF80003E8, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(1000, 0x01).id);
	ur8_1 = loc3;
	ur8_2 = loc5;
	ui4_1 = loc4;
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,352,0xFF01,998,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		tr2 = RTLN(typres0.id);
	}
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(3164, Dtype(tr2)))(tr2);
	RTNHOOK(11,1);
	ur1 = RTCCL(tr2);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWC(5321, Dtype(tr1)))(tr1, ur8_1x, ur8_2x, ui4_1x, ur1x);
	RTNHOOK(11,2);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	if (RTAL & CK_ENSURE) {
		RTHOOK(12);
		RTCT("result_valid", EX_POST);
		if ((EIF_BOOLEAN)(Result != NULL)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(13);
		RTCT("p_value_valid", EX_POST);
		tb1 = '\0';
		tr8_1 = *(EIF_REAL_64 *)(Result + RTVA(5315, "p_value", Result));
		if ((EIF_BOOLEAN) eif_is_greater_equal_real_64 (tr8_1, (EIF_REAL_64) 0.0)) {
			tr8_1 = *(EIF_REAL_64 *)(Result + RTVA(5315, "p_value", Result));
			tb1 = (EIF_BOOLEAN) eif_is_less_equal_real_64 (tr8_1, (EIF_REAL_64) 1.0);
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(14);
		RTCT("dof_correct", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Result + RTVA(5316, "degrees_of_freedom", Result));
		ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		if ((EIF_BOOLEAN)(ti4_1 == (EIF_INTEGER_32) (ti4_2 - ((EIF_INTEGER_32) 1L)))) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(15);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(12);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef ur1
#undef ur8_1
#undef ur8_2
#undef ui4_1
#undef arg2
#undef arg1
}

/* {STATISTICS}.t_test_two_sample */
EIF_TYPED_VALUE F1002_7070 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "t_test_two_sample";
	RTEX;
	EIF_REAL_64 loc1 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc2 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc3 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc4 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc5 = (EIF_REAL_64) 0;
	EIF_INTEGER_32 loc6 = (EIF_INTEGER_32) 0;
	EIF_REAL_64 loc7 = (EIF_REAL_64) 0;
	EIF_REFERENCE loc8 = (EIF_REFERENCE) 0;
	EIF_REAL_64 loc9 = (EIF_REAL_64) 0;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur8_1x = {{0}, SK_REAL64};
#define ur8_1 ur8_1x.it_r8
	EIF_TYPED_VALUE ur8_2x = {{0}, SK_REAL64};
#define ur8_2 ur8_2x.it_r8
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_REAL_64 tr8_3;
	EIF_REAL_64 tr8_4;
	EIF_REAL_64 tr8_5;
	EIF_REAL_64 tr8_6;
	EIF_REAL_64 tr8_7;
	EIF_REAL_64 tr8_8;
	EIF_REAL_64 tr8_9;
	EIF_REAL_64 tr8_10;
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(8);
	RTLR(0,arg1);
	RTLR(1,arg2);
	RTLR(2,ur1);
	RTLR(3,Current);
	RTLR(4,loc8);
	RTLR(5,tr1);
	RTLR(6,tr2);
	RTLR(7,Result);
	RTLIU(8);
	RTLU (SK_REF, &Result);
	RTLU(SK_REF,&arg1);
	RTLU(SK_REF,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_REAL64, &loc1);
	RTLU(SK_REAL64, &loc2);
	RTLU(SK_REAL64, &loc3);
	RTLU(SK_REAL64, &loc4);
	RTLU(SK_REAL64, &loc5);
	RTLU(SK_INT32, &loc6);
	RTLU(SK_REAL64, &loc7);
	RTLU(SK_REF, &loc8);
	RTLU(SK_REAL64, &loc9);
	
	RTEAA(l_feature_name, 1001, Current, 9, 2, 13866);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13866);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg2, 1001, l_feature_name, 2, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("data_valid", EX_PRE);
		tb1 = '\0';
		tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		if ((EIF_BOOLEAN) !tb2) {
			tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg2))(arg2)).it_b);
			tb1 = (EIF_BOOLEAN) !tb2;
		}
		RTTE(tb1, label_1);
		RTCK;
		RTHOOK(2);
		RTCT("sufficient_data", EX_PRE);
		tb1 = '\0';
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		if ((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 2L))) {
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg2))(arg2)).it_i4);
			tb1 = (EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 2L));
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
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5323, dtype))(Current, ur1x)).it_r8);
	loc1 = (EIF_REAL_64) tr8_1;
	RTHOOK(4);
	RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
	ur1 = RTCCL(arg2);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5323, dtype))(Current, ur1x)).it_r8);
	loc2 = (EIF_REAL_64) tr8_1;
	RTHOOK(5);
	RTDBGAL(3, 0x20000000, 1, 0); /* loc3 */
	ur1 = RTCCL(arg1);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5326, dtype))(Current, ur1x)).it_r8);
	loc3 = (EIF_REAL_64) tr8_1;
	RTHOOK(6);
	RTDBGAL(4, 0x20000000, 1, 0); /* loc4 */
	ur1 = RTCCL(arg2);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5326, dtype))(Current, ur1x)).it_r8);
	loc4 = (EIF_REAL_64) tr8_1;
	RTHOOK(7);
	RTDBGAL(8, 0xF80003E7, 0, 0); /* loc8 */
	tr1 = RTLN(eif_new_type(999, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(5271, Dtype(tr1)))(tr1);
	RTNHOOK(7,1);
	loc8 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(8);
	RTDBGAL(9, 0x20000000, 1, 0); /* loc9 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	tr8_1 = (EIF_REAL_64) (ti4_1);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg2))(arg2)).it_i4);
	tr8_2 = (EIF_REAL_64) (ti4_1);
	ur8_1 = (EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) (loc3) /  (EIF_REAL_64) (tr8_1)) + (EIF_REAL_64) ((EIF_REAL_64) (loc4) /  (EIF_REAL_64) (tr8_2)));
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5299, "sqrt", loc8))(loc8, ur8_1x)).it_r8);
	loc9 = (EIF_REAL_64) tr8_1;
	RTHOOK(9);
	RTDBGAL(5, 0x20000000, 1, 0); /* loc5 */
	loc5 = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) (loc1 - loc2)) /  (EIF_REAL_64) (loc9));
	RTHOOK(10);
	RTDBGAL(6, 0x10000000, 1, 0); /* loc6 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	tr8_1 = (EIF_REAL_64) (ti4_1);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg2))(arg2)).it_i4);
	tr8_2 = (EIF_REAL_64) (ti4_1);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	tr8_3 = (EIF_REAL_64) (ti4_1);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg2))(arg2)).it_i4);
	tr8_4 = (EIF_REAL_64) (ti4_1);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	tr8_5 = (EIF_REAL_64) (ti4_1);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	tr8_6 = (EIF_REAL_64) (ti4_1);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	tr8_7 = (EIF_REAL_64) ((EIF_INTEGER_32) (ti4_1 - ((EIF_INTEGER_32) 1L)));
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg2))(arg2)).it_i4);
	tr8_8 = (EIF_REAL_64) (ti4_1);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg2))(arg2)).it_i4);
	tr8_9 = (EIF_REAL_64) (ti4_1);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg2))(arg2)).it_i4);
	tr8_10 = (EIF_REAL_64) ((EIF_INTEGER_32) (ti4_1 - ((EIF_INTEGER_32) 1L)));
	tr1 = RTLN(eif_new_type(245, 0x00).id);
	*(EIF_REAL_64 *)tr1 = (EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) (loc3) /  (EIF_REAL_64) (tr8_1)) + (EIF_REAL_64) ((EIF_REAL_64) (loc4) /  (EIF_REAL_64) (tr8_2))) * (EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) (loc3) /  (EIF_REAL_64) (tr8_3)) + (EIF_REAL_64) ((EIF_REAL_64) (loc4) /  (EIF_REAL_64) (tr8_4))))) /  (EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) (loc3) /  (EIF_REAL_64) (tr8_5)) * (EIF_REAL_64) ((EIF_REAL_64) (loc3) /  (EIF_REAL_64) (tr8_6)))) /  (EIF_REAL_64) (tr8_7)) + (EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) (loc4) /  (EIF_REAL_64) (tr8_8)) * (EIF_REAL_64) ((EIF_REAL_64) (loc4) /  (EIF_REAL_64) (tr8_9)))) /  (EIF_REAL_64) (tr8_10)))));
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(4245, "floor", tr1))(tr1)).it_i4);
	loc6 = (EIF_INTEGER_32) ti4_1;
	RTHOOK(11);
	RTDBGAL(7, 0x20000000, 1, 0); /* loc7 */
	loc7 = (EIF_REAL_64) (EIF_REAL_64) 0.5;
	RTHOOK(12);
	RTDBGAL(0, 0xF80003E8, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(1000, 0x01).id);
	ur8_1 = loc5;
	ur8_2 = loc7;
	ui4_1 = loc6;
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,352,0xFF01,998,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		tr2 = RTLN(typres0.id);
	}
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(3164, Dtype(tr2)))(tr2);
	RTNHOOK(12,1);
	ur1 = RTCCL(tr2);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWC(5321, Dtype(tr1)))(tr1, ur8_1x, ur8_2x, ui4_1x, ur1x);
	RTNHOOK(12,2);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	if (RTAL & CK_ENSURE) {
		RTHOOK(13);
		RTCT("result_valid", EX_POST);
		if ((EIF_BOOLEAN)(Result != NULL)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(14);
		RTCT("dof_positive", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Result + RTVA(5316, "degrees_of_freedom", Result));
		if ((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 1L))) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(15);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(13);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef ur1
#undef ur8_1
#undef ur8_2
#undef ui4_1
#undef arg2
#undef arg1
}

/* {STATISTICS}.t_test_paired */
EIF_TYPED_VALUE F1002_7071 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "t_test_paired";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
	EIF_REAL_64 loc3 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc4 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc5 = (EIF_REAL_64) 0;
	EIF_INTEGER_32 loc6 = (EIF_INTEGER_32) 0;
	EIF_REAL_64 loc7 = (EIF_REAL_64) 0;
	EIF_REFERENCE loc8 = (EIF_REFERENCE) 0;
	EIF_REAL_64 loc9 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc10 = (EIF_REAL_64) 0;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur8_1x = {{0}, SK_REAL64};
#define ur8_1 ur8_1x.it_r8
	EIF_TYPED_VALUE ur8_2x = {{0}, SK_REAL64};
#define ur8_2 ur8_2x.it_r8
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCFDT;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(9);
	RTLR(0,arg1);
	RTLR(1,arg2);
	RTLR(2,loc1);
	RTLR(3,Current);
	RTLR(4,tr1);
	RTLR(5,ur1);
	RTLR(6,loc8);
	RTLR(7,tr2);
	RTLR(8,Result);
	RTLIU(9);
	RTLU (SK_REF, &Result);
	RTLU(SK_REF,&arg1);
	RTLU(SK_REF,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	RTLU(SK_INT32, &loc2);
	RTLU(SK_REAL64, &loc3);
	RTLU(SK_REAL64, &loc4);
	RTLU(SK_REAL64, &loc5);
	RTLU(SK_INT32, &loc6);
	RTLU(SK_REAL64, &loc7);
	RTLU(SK_REF, &loc8);
	RTLU(SK_REAL64, &loc9);
	RTLU(SK_REAL64, &loc10);
	
	RTEAA(l_feature_name, 1001, Current, 10, 2, 13867);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13867);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		RTCC(arg2, 1001, l_feature_name, 2, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("same_length", EX_PRE);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg2))(arg2)).it_i4);
		RTTE((EIF_BOOLEAN)(ti4_1 == ti4_2), label_1);
		RTCK;
		RTHOOK(2);
		RTCT("data_valid", EX_PRE);
		tb1 = '\0';
		tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		if ((EIF_BOOLEAN) !tb2) {
			tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg2))(arg2)).it_b);
			tb1 = (EIF_BOOLEAN) !tb2;
		}
		RTTE(tb1, label_1);
		RTCK;
		RTHOOK(3);
		RTCT("sufficient_data", EX_PRE);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		RTTE((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 2L)), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(4);
	RTDBGAL(1, 0xF80001EF, 0, 0); /* loc1 */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLN(typres0.id);
	}
	ur8_1 = (EIF_REAL_64) 0.0;
	ui4_1 = ((EIF_INTEGER_32) 1L);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	ui4_2 = ti4_1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWC(3165, Dtype(tr1)))(tr1, ur8_1x, ui4_1x, ui4_2x);
	RTNHOOK(4,1);
	loc1 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(5);
	RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
	loc2 = (EIF_INTEGER_32) ti4_1;
	for (;;) {
		RTHOOK(6);
		ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3200, "upper", arg1));
		if ((EIF_BOOLEAN) (loc2 > ti4_1)) break;
		RTHOOK(7);
		ui4_1 = loc2;
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)).it_r8);
		ti4_2 = *(EIF_INTEGER_32 *)(arg2 + RTVA(3201, "lower", arg2));
		ti4_3 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
		ui4_1 = (EIF_INTEGER_32) (ti4_2 + (EIF_INTEGER_32) (loc2 - ti4_3));
		tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg2))(arg2, ui4_1x)).it_r8);
		ur8_1 = (EIF_REAL_64) (tr8_1 - tr8_2);
		ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
		ui4_1 = (EIF_INTEGER_32) ((EIF_INTEGER_32) (loc2 - ti4_2) + ((EIF_INTEGER_32) 1L));
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(2894, "put", loc1))(loc1, ur8_1x, ui4_1x);
		RTHOOK(8);
		RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
		loc2++;
	}
	RTHOOK(9);
	RTDBGAL(3, 0x20000000, 1, 0); /* loc3 */
	ur1 = RTCCL(loc1);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5323, dtype))(Current, ur1x)).it_r8);
	loc3 = (EIF_REAL_64) tr8_1;
	RTHOOK(10);
	RTDBGAL(8, 0xF80003E7, 0, 0); /* loc8 */
	tr1 = RTLN(eif_new_type(999, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(5271, Dtype(tr1)))(tr1);
	RTNHOOK(10,1);
	loc8 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(11);
	RTDBGAL(10, 0x20000000, 1, 0); /* loc10 */
	ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", loc1))(loc1)).it_i4);
	tr8_1 = (EIF_REAL_64) (ti4_2);
	loc10 = (EIF_REAL_64) tr8_1;
	RTHOOK(12);
	RTDBGAL(9, 0x20000000, 1, 0); /* loc9 */
	ur8_1 = loc10;
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5299, "sqrt", loc8))(loc8, ur8_1x)).it_r8);
	loc9 = (EIF_REAL_64) tr8_1;
	RTHOOK(13);
	RTDBGAL(4, 0x20000000, 1, 0); /* loc4 */
	ur1 = RTCCL(loc1);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5327, dtype))(Current, ur1x)).it_r8);
	loc4 = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) (tr8_1) /  (EIF_REAL_64) (loc9));
	RTHOOK(14);
	RTDBGAL(5, 0x20000000, 1, 0); /* loc5 */
	loc5 = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) (loc3) /  (EIF_REAL_64) (loc4));
	RTHOOK(15);
	RTDBGAL(6, 0x10000000, 1, 0); /* loc6 */
	ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	loc6 = (EIF_INTEGER_32) (EIF_INTEGER_32) (ti4_2 - ((EIF_INTEGER_32) 1L));
	RTHOOK(16);
	RTDBGAL(7, 0x20000000, 1, 0); /* loc7 */
	loc7 = (EIF_REAL_64) (EIF_REAL_64) 0.5;
	RTHOOK(17);
	RTDBGAL(0, 0xF80003E8, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(1000, 0x01).id);
	ur8_1 = loc5;
	ur8_2 = loc7;
	ui4_1 = loc6;
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,352,0xFF01,998,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2 = RTLN(typres0.id);
	}
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(3164, Dtype(tr2)))(tr2);
	RTNHOOK(17,1);
	ur1 = RTCCL(tr2);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWC(5321, Dtype(tr1)))(tr1, ur8_1x, ur8_2x, ui4_1x, ur1x);
	RTNHOOK(17,2);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	if (RTAL & CK_ENSURE) {
		RTHOOK(18);
		RTCT("result_valid", EX_POST);
		if ((EIF_BOOLEAN)(Result != NULL)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(19);
		RTCT("dof_correct", EX_POST);
		ti4_2 = *(EIF_INTEGER_32 *)(Result + RTVA(5316, "degrees_of_freedom", Result));
		ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		if ((EIF_BOOLEAN)(ti4_2 == (EIF_INTEGER_32) (ti4_3 - ((EIF_INTEGER_32) 1L)))) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(20);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(14);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef ur1
#undef ur8_1
#undef ur8_2
#undef ui4_1
#undef ui4_2
#undef arg2
#undef arg1
}

/* {STATISTICS}.chi_square_test */
EIF_TYPED_VALUE F1002_7072 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "chi_square_test";
	RTEX;
	EIF_REAL_64 loc1 = (EIF_REAL_64) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc3 = (EIF_INTEGER_32) 0;
	EIF_REAL_64 loc4 = (EIF_REAL_64) 0;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur8_1x = {{0}, SK_REAL64};
#define ur8_1 ur8_1x.it_r8
	EIF_TYPED_VALUE ur8_2x = {{0}, SK_REAL64};
#define ur8_2 ur8_2x.it_r8
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_REAL_64 tr8_3;
	EIF_REAL_64 tr8_4;
	EIF_REAL_64 tr8_5;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_BOOLEAN tb1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(7);
	RTLR(0,arg1);
	RTLR(1,arg2);
	RTLR(2,tr1);
	RTLR(3,Current);
	RTLR(4,tr2);
	RTLR(5,ur1);
	RTLR(6,Result);
	RTLIU(7);
	RTLU (SK_REF, &Result);
	RTLU(SK_REF,&arg1);
	RTLU(SK_REF,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_REAL64, &loc1);
	RTLU(SK_INT32, &loc2);
	RTLU(SK_INT32, &loc3);
	RTLU(SK_REAL64, &loc4);
	
	RTEAA(l_feature_name, 1001, Current, 4, 2, 13868);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13868);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg2, 1001, l_feature_name, 2, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("same_length", EX_PRE);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg2))(arg2)).it_i4);
		RTTE((EIF_BOOLEAN)(ti4_1 == ti4_2), label_1);
		RTCK;
		RTHOOK(2);
		RTCT("data_valid", EX_PRE);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2854, "is_empty", arg1))(arg1)).it_b);
		RTTE((EIF_BOOLEAN) !tb1, label_1);
		RTCK;
		RTHOOK(3);
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(4);
	RTDBGAL(1, 0x20000000, 1, 0); /* loc1 */
	loc1 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	RTHOOK(5);
	RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
	loc2 = (EIF_INTEGER_32) ti4_1;
	for (;;) {
		RTHOOK(6);
		ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3200, "upper", arg1));
		if ((EIF_BOOLEAN) (loc2 > ti4_1)) break;
		RTHOOK(7);
		RTDBGAL(1, 0x20000000, 1, 0); /* loc1 */
		ui4_1 = loc2;
		tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)).it_r8);
		ui4_1 = loc2;
		tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg2))(arg2, ui4_1x)).it_r8);
		ui4_1 = loc2;
		tr8_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)).it_r8);
		ui4_1 = loc2;
		tr8_4 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg2))(arg2, ui4_1x)).it_r8);
		ui4_1 = loc2;
		tr8_5 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg2))(arg2, ui4_1x)).it_r8);
		loc1 += (EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) (tr8_1 - tr8_2) * (EIF_REAL_64) (tr8_3 - tr8_4))) /  (EIF_REAL_64) (tr8_5));
		RTHOOK(8);
		RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
		loc2++;
	}
	RTHOOK(9);
	RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
	ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	loc3 = (EIF_INTEGER_32) (EIF_INTEGER_32) (ti4_2 - ((EIF_INTEGER_32) 1L));
	RTHOOK(10);
	RTDBGAL(4, 0x20000000, 1, 0); /* loc4 */
	loc4 = (EIF_REAL_64) (EIF_REAL_64) 0.5;
	RTHOOK(11);
	RTDBGAL(0, 0xF80003E8, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(1000, 0x01).id);
	ur8_1 = loc1;
	ur8_2 = loc4;
	ui4_1 = loc3;
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,352,0xFF01,998,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		tr2 = RTLN(typres0.id);
	}
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(3164, Dtype(tr2)))(tr2);
	RTNHOOK(11,1);
	ur1 = RTCCL(tr2);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWC(5321, Dtype(tr1)))(tr1, ur8_1x, ur8_2x, ui4_1x, ur1x);
	RTNHOOK(11,2);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	if (RTAL & CK_ENSURE) {
		RTHOOK(12);
		RTCT("result_valid", EX_POST);
		if ((EIF_BOOLEAN)(Result != NULL)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(13);
		RTCT("p_value_valid", EX_POST);
		tb1 = '\0';
		tr8_1 = *(EIF_REAL_64 *)(Result + RTVA(5315, "p_value", Result));
		if ((EIF_BOOLEAN) eif_is_greater_equal_real_64 (tr8_1, (EIF_REAL_64) 0.0)) {
			tr8_1 = *(EIF_REAL_64 *)(Result + RTVA(5315, "p_value", Result));
			tb1 = (EIF_BOOLEAN) eif_is_less_equal_real_64 (tr8_1, (EIF_REAL_64) 1.0);
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(14);
		RTCT("dof_correct", EX_POST);
		ti4_2 = *(EIF_INTEGER_32 *)(Result + RTVA(5316, "degrees_of_freedom", Result));
		ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		if ((EIF_BOOLEAN)(ti4_2 == (EIF_INTEGER_32) (ti4_3 - ((EIF_INTEGER_32) 1L)))) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(15);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(8);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef ur1
#undef ur8_1
#undef ur8_2
#undef ui4_1
#undef arg2
#undef arg1
}

/* {STATISTICS}.anova */
EIF_TYPED_VALUE F1002_7073 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "anova";
	RTEX;
	EIF_REAL_64 loc1 = (EIF_REAL_64) 0;
	EIF_REFERENCE loc2 = (EIF_REFERENCE) 0;
	EIF_INTEGER_32 loc3 = (EIF_INTEGER_32) 0;
	EIF_REAL_64 loc4 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc5 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc6 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc7 = (EIF_REAL_64) 0;
	EIF_REAL_64 loc8 = (EIF_REAL_64) 0;
	EIF_INTEGER_32 loc9 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc10 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc11 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc12 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc13 = (EIF_INTEGER_32) 0;
	EIF_REAL_64 loc14 = (EIF_REAL_64) 0;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur8_1x = {{0}, SK_REAL64};
#define ur8_1 ur8_1x.it_r8
	EIF_TYPED_VALUE ur8_2x = {{0}, SK_REAL64};
#define ur8_2 ur8_2x.it_r8
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
	EIF_INTEGER_32 ti4_6;
	EIF_INTEGER_32 ti4_7;
	EIF_BOOLEAN tb1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCFDT;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(7);
	RTLR(0,arg1);
	RTLR(1,tr1);
	RTLR(2,loc2);
	RTLR(3,Current);
	RTLR(4,ur1);
	RTLR(5,tr2);
	RTLR(6,Result);
	RTLIU(7);
	RTLU (SK_REF, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_REAL64, &loc1);
	RTLU(SK_REF, &loc2);
	RTLU(SK_INT32, &loc3);
	RTLU(SK_REAL64, &loc4);
	RTLU(SK_REAL64, &loc5);
	RTLU(SK_REAL64, &loc6);
	RTLU(SK_REAL64, &loc7);
	RTLU(SK_REAL64, &loc8);
	RTLU(SK_INT32, &loc9);
	RTLU(SK_INT32, &loc10);
	RTLU(SK_INT32, &loc11);
	RTLU(SK_INT32, &loc12);
	RTLU(SK_INT32, &loc13);
	RTLU(SK_REAL64, &loc14);
	
	RTEAA(l_feature_name, 1001, Current, 14, 1, 13869);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1001, Current, 13869);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,352,0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		RTCC(arg1, 1001, l_feature_name, 1, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("sufficient_groups", EX_PRE);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
		RTTE((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 3L)), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
	loc3 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 0L);
	RTHOOK(3);
	RTDBGAL(11, 0x10000000, 1, 0); /* loc11 */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
	loc11 = (EIF_INTEGER_32) ti4_1;
	for (;;) {
		RTHOOK(4);
		ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3200, "upper", arg1));
		if ((EIF_BOOLEAN) (loc11 > ti4_1)) break;
		RTHOOK(5);
		RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
		ui4_1 = loc11;
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", tr1))(tr1)).it_i4);
		loc3 += ti4_2;
		RTHOOK(6);
		RTDBGAL(11, 0x10000000, 1, 0); /* loc11 */
		loc11++;
	}
	RTHOOK(7);
	RTDBGAL(2, 0xF80001EF, 0, 0); /* loc2 */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,495,245,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLN(typres0.id);
	}
	ur8_1 = (EIF_REAL_64) 0.0;
	ui4_1 = ((EIF_INTEGER_32) 1L);
	ui4_2 = loc3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWC(3165, Dtype(tr1)))(tr1, ur8_1x, ui4_1x, ui4_2x);
	RTNHOOK(7,1);
	loc2 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(8);
	RTDBGAL(13, 0x10000000, 1, 0); /* loc13 */
	loc13 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 1L);
	RTHOOK(9);
	RTDBGAL(11, 0x10000000, 1, 0); /* loc11 */
	ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
	loc11 = (EIF_INTEGER_32) ti4_2;
	for (;;) {
		RTHOOK(10);
		ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3200, "upper", arg1));
		if ((EIF_BOOLEAN) (loc11 > ti4_2)) break;
		RTHOOK(11);
		RTDBGAL(12, 0x10000000, 1, 0); /* loc12 */
		ui4_1 = loc11;
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		ti4_3 = *(EIF_INTEGER_32 *)(tr1 + RTVA(3201, "lower", tr1));
		loc12 = (EIF_INTEGER_32) ti4_3;
		for (;;) {
			RTHOOK(12);
			ui4_1 = loc11;
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			ti4_3 = *(EIF_INTEGER_32 *)(tr1 + RTVA(3200, "upper", tr1));
			if ((EIF_BOOLEAN) (loc12 > ti4_3)) break;
			RTHOOK(13);
			ui4_1 = loc11;
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			ui4_1 = loc12;
			tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", tr1))(tr1, ui4_1x)).it_r8);
			ur8_1 = tr8_1;
			ui4_1 = loc13;
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(2894, "put", loc2))(loc2, ur8_1x, ui4_1x);
			RTHOOK(14);
			RTDBGAL(13, 0x10000000, 1, 0); /* loc13 */
			loc13++;
			RTHOOK(15);
			RTDBGAL(12, 0x10000000, 1, 0); /* loc12 */
			loc12++;
		}
		RTHOOK(16);
		RTDBGAL(11, 0x10000000, 1, 0); /* loc11 */
		loc11++;
	}
	RTHOOK(17);
	RTDBGAL(1, 0x20000000, 1, 0); /* loc1 */
	ur1 = RTCCL(loc2);
	tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5323, dtype))(Current, ur1x)).it_r8);
	loc1 = (EIF_REAL_64) tr8_1;
	RTHOOK(18);
	RTDBGAL(4, 0x20000000, 1, 0); /* loc4 */
	loc4 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	RTHOOK(19);
	RTDBGAL(11, 0x10000000, 1, 0); /* loc11 */
	ti4_4 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
	loc11 = (EIF_INTEGER_32) ti4_4;
	for (;;) {
		RTHOOK(20);
		ti4_4 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3200, "upper", arg1));
		if ((EIF_BOOLEAN) (loc11 > ti4_4)) break;
		RTHOOK(21);
		RTDBGAL(4, 0x20000000, 1, 0); /* loc4 */
		ui4_1 = loc11;
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		ti4_5 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", tr1))(tr1)).it_i4);
		tr8_1 = (EIF_REAL_64) (ti4_5);
		ui4_1 = loc11;
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		ur1 = RTCCL(tr1);
		tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5323, dtype))(Current, ur1x)).it_r8);
		ui4_1 = loc11;
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		ur1 = RTCCL(tr1);
		tr8_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5323, dtype))(Current, ur1x)).it_r8);
		loc4 += (EIF_REAL_64) ((EIF_REAL_64) (tr8_1 * (EIF_REAL_64) (tr8_2 - loc1)) * (EIF_REAL_64) (tr8_3 - loc1));
		RTHOOK(22);
		RTDBGAL(11, 0x10000000, 1, 0); /* loc11 */
		loc11++;
	}
	RTHOOK(23);
	RTDBGAL(5, 0x20000000, 1, 0); /* loc5 */
	loc5 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	RTHOOK(24);
	RTDBGAL(11, 0x10000000, 1, 0); /* loc11 */
	ti4_5 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3201, "lower", arg1));
	loc11 = (EIF_INTEGER_32) ti4_5;
	for (;;) {
		RTHOOK(25);
		ti4_5 = *(EIF_INTEGER_32 *)(arg1 + RTVA(3200, "upper", arg1));
		if ((EIF_BOOLEAN) (loc11 > ti4_5)) break;
		RTHOOK(26);
		RTDBGAL(12, 0x10000000, 1, 0); /* loc12 */
		ui4_1 = loc11;
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		ti4_6 = *(EIF_INTEGER_32 *)(tr1 + RTVA(3201, "lower", tr1));
		loc12 = (EIF_INTEGER_32) ti4_6;
		for (;;) {
			RTHOOK(27);
			ui4_1 = loc11;
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			ti4_6 = *(EIF_INTEGER_32 *)(tr1 + RTVA(3200, "upper", tr1));
			if ((EIF_BOOLEAN) (loc12 > ti4_6)) break;
			RTHOOK(28);
			RTDBGAL(5, 0x20000000, 1, 0); /* loc5 */
			ui4_1 = loc11;
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			ui4_1 = loc12;
			tr8_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", tr1))(tr1, ui4_1x)).it_r8);
			ui4_1 = loc11;
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			ur1 = RTCCL(tr1);
			tr8_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5323, dtype))(Current, ur1x)).it_r8);
			ui4_1 = loc11;
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			ui4_1 = loc12;
			tr8_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", tr1))(tr1, ui4_1x)).it_r8);
			ui4_1 = loc11;
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2891, "item", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			ur1 = RTCCL(tr1);
			tr8_4 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5323, dtype))(Current, ur1x)).it_r8);
			loc5 += (EIF_REAL_64) ((EIF_REAL_64) (tr8_1 - tr8_2) * (EIF_REAL_64) (tr8_3 - tr8_4));
			RTHOOK(29);
			RTDBGAL(12, 0x10000000, 1, 0); /* loc12 */
			loc12++;
		}
		RTHOOK(30);
		RTDBGAL(11, 0x10000000, 1, 0); /* loc11 */
		loc11++;
	}
	RTHOOK(31);
	RTDBGAL(9, 0x10000000, 1, 0); /* loc9 */
	ti4_7 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	loc9 = (EIF_INTEGER_32) (EIF_INTEGER_32) (ti4_7 - ((EIF_INTEGER_32) 1L));
	RTHOOK(32);
	RTDBGAL(10, 0x10000000, 1, 0); /* loc10 */
	ti4_7 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2918, "count", arg1))(arg1)).it_i4);
	loc10 = (EIF_INTEGER_32) (EIF_INTEGER_32) (loc3 - ti4_7);
	RTHOOK(33);
	RTDBGAL(6, 0x20000000, 1, 0); /* loc6 */
	tr8_1 = (EIF_REAL_64) (loc9);
	loc6 = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) (loc4) /  (EIF_REAL_64) (tr8_1));
	RTHOOK(34);
	RTDBGAL(7, 0x20000000, 1, 0); /* loc7 */
	tr8_1 = (EIF_REAL_64) (loc10);
	loc7 = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) (loc5) /  (EIF_REAL_64) (tr8_1));
	RTHOOK(35);
	if ((EIF_BOOLEAN) eif_is_equal_real_64 (loc7, (EIF_REAL_64) 0.0)) {
		RTHOOK(36);
		RTDBGAL(8, 0x20000000, 1, 0); /* loc8 */
		loc8 = (EIF_REAL_64) (EIF_REAL_64) 0.0;
	} else {
		RTHOOK(37);
		RTDBGAL(8, 0x20000000, 1, 0); /* loc8 */
		loc8 = (EIF_REAL_64) (EIF_REAL_64) ((EIF_REAL_64) (loc6) /  (EIF_REAL_64) (loc7));
	}
	RTHOOK(38);
	RTDBGAL(14, 0x20000000, 1, 0); /* loc14 */
	loc14 = (EIF_REAL_64) (EIF_REAL_64) 0.5;
	RTHOOK(39);
	RTDBGAL(0, 0xF80003E8, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(1000, 0x01).id);
	ur8_1 = loc8;
	ur8_2 = loc14;
	ui4_1 = loc9;
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,352,0xFF01,998,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr2 = RTLN(typres0.id);
	}
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(3164, Dtype(tr2)))(tr2);
	RTNHOOK(39,1);
	ur1 = RTCCL(tr2);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWC(5321, Dtype(tr1)))(tr1, ur8_1x, ur8_2x, ui4_1x, ur1x);
	RTNHOOK(39,2);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	if (RTAL & CK_ENSURE) {
		RTHOOK(40);
		RTCT("result_valid", EX_POST);
		if ((EIF_BOOLEAN)(Result != NULL)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(41);
		RTCT("p_value_valid", EX_POST);
		tb1 = '\0';
		tr8_1 = *(EIF_REAL_64 *)(Result + RTVA(5315, "p_value", Result));
		if ((EIF_BOOLEAN) eif_is_greater_equal_real_64 (tr8_1, (EIF_REAL_64) 0.0)) {
			tr8_1 = *(EIF_REAL_64 *)(Result + RTVA(5315, "p_value", Result));
			tb1 = (EIF_BOOLEAN) eif_is_less_equal_real_64 (tr8_1, (EIF_REAL_64) 1.0);
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(42);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(17);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef ur1
#undef ur8_1
#undef ur8_2
#undef ui4_1
#undef ui4_2
#undef arg1
}

/* {STATISTICS}._invariant */
void F1002_7187 (EIF_REFERENCE Current, int where)
{
	GTCX
	char *l_feature_name = "_invariant";
	RTEX;
	RTLD;
	RTDA;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	RTEAINV(l_feature_name, 1001, Current, 0, 7186);
	RTSA(Dtype(Current));
	RTME(Dtype(Current), 0);
	RTLO(2);
	RTMD(0);
	RTLE;
	RTEE;
}

void EIF_Minit1002 (void)
{
	GTCX
}


#ifdef __cplusplus
}
#endif
