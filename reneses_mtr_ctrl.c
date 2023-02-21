#include "Subsystem.h"

#include "rtwtypes.h"

#include <math.h>

#include <float.h>

#include <stddef.h>

#define NumBitsPerChar                 8U

#ifndef rtmIsMajorTimeStep

#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)

#endif



#ifndef rtmIsMinorTimeStep

#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)

#endif



#ifndef rtmSetTPtr

#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))

#endif



#ifndef PORTABLE_WORDSIZES

#ifndef UCHAR_MAX

#include <limits.h>

#endif



#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )

#error Code was generated for compiler with different sized uchar/char. \

Consider adjusting Test hardware word size settings on the \

Hardware Implementation pane to match your compiler word sizes as \

defined in limits.h of the compiler. Alternatively, you can \

select the Test hardware is the same as production hardware option and \

select the Enable portable word sizes option on the Code Generation > \

Verification pane for ERT based targets, which will disable the \

preprocessor word size checks.

#endif



#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )

#error Code was generated for compiler with different sized ushort/short. \

Consider adjusting Test hardware word size settings on the \

Hardware Implementation pane to match your compiler word sizes as \

defined in limits.h of the compiler. Alternatively, you can \

select the Test hardware is the same as production hardware option and \

select the Enable portable word sizes option on the Code Generation > \

Verification pane for ERT based targets, which will disable the \

preprocessor word size checks.

#endif



#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )

#error Code was generated for compiler with different sized uint/int. \

Consider adjusting Test hardware word size settings on the \

Hardware Implementation pane to match your compiler word sizes as \

defined in limits.h of the compiler. Alternatively, you can \

select the Test hardware is the same as production hardware option and \

select the Enable portable word sizes option on the Code Generation > \

Verification pane for ERT based targets, which will disable the \

preprocessor word size checks.

#endif



#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )

#error Code was generated for compiler with different sized ulong/long. \

Consider adjusting Test hardware word size settings on the \

Hardware Implementation pane to match your compiler word sizes as \

defined in limits.h of the compiler. Alternatively, you can \

select the Test hardware is the same as production hardware option and \

select the Enable portable word sizes option on the Code Generation > \

Verification pane for ERT based targets, which will disable the \

preprocessor word size checks.

#endif



/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

#endif                                 /* PORTABLE_WORDSIZES */



/* Block signals and states (default storage) */

DW rtDW;



/* External inputs (root inport signals with default storage) */

ExtU rtU;



/* External outputs (root outports fed by signals with default storage) */

ExtY rtY;



/* Real-time model */

static RT_MODEL rtM_;

RT_MODEL *const rtM = &rtM_;

extern real_T rt_remd_snf(real_T u0, real_T u1);

static real_T look1_pbinlx(real_T u0, const real_T bp0[], const real_T table[],

  uint32_T prevIndex[], uint32_T maxIndex);

static real_T rtGetNaN(void);

static real32_T rtGetNaNF(void);

extern real_T rtInf;

extern real_T rtMinusInf;

extern real_T rtNaN;

extern real32_T rtInfF;

extern real32_T rtMinusInfF;

extern real32_T rtNaNF;

static void rt_InitInfAndNaN(size_t realSize);

static boolean_T rtIsInf(real_T value);

static boolean_T rtIsInfF(real32_T value);

static boolean_T rtIsNaN(real_T value);

static boolean_T rtIsNaNF(real32_T value);

typedef struct {

  struct {

    uint32_T wordH;

    uint32_T wordL;

  } words;

} BigEndianIEEEDouble;



typedef struct {

  struct {

    uint32_T wordL;

    uint32_T wordH;

  } words;

} LittleEndianIEEEDouble;



typedef struct {

  union {

    real32_T wordLreal;

    uint32_T wordLuint;

  } wordL;

} IEEESingle;



real_T rtInf;

real_T rtMinusInf;

real_T rtNaN;

real32_T rtInfF;

real32_T rtMinusInfF;

real32_T rtNaNF;

static real_T rtGetInf(void);

static real32_T rtGetInfF(void);

static real_T rtGetMinusInf(void);

static real32_T rtGetMinusInfF(void);



/*

 * Initialize rtNaN needed by the generated code.

 * NaN is initialized as non-signaling. Assumes IEEE.

 */

static real_T rtGetNaN(void)

{

  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);

  real_T nan = 0.0;

  if (bitsPerReal == 32U) {

    nan = rtGetNaNF();

  } else {

    uint16_T one = 1U;

    enum {

      LittleEndian,

      BigEndian

    } machByteOrder = (*((uint8_T *) &one) == 1U) ? LittleEndian : BigEndian;

    switch (machByteOrder) {

     case LittleEndian:

      {

        union {

          LittleEndianIEEEDouble bitVal;

          real_T fltVal;

        } tmpVal;



        tmpVal.bitVal.words.wordH = 0xFFF80000U;

        tmpVal.bitVal.words.wordL = 0x00000000U;

        nan = tmpVal.fltVal;


     *  RelationalOperator: '<S2>/Compare'

     *  RelationalOperator: '<S3>/Compare'

     *  Switch: '<S1>/Switch1'

     */

    rtY.Out5 = ((((int16_T)rtU.y == 6) || ((int16_T)rtU.y == 2)) &&

                rtb_RelationalOperator4);



    /* Outport: '<Root>/Out6' incorporates:

     *  Constant: '<S1>/Constant1'

     *  Switch: '<S1>/Switch2'

     */

    rtY.Out6 = 0.0;



    /* Outport: '<Root>/Out3' incorporates:

     *  Inport: '<Root>/u1'

     *  Logic: '<S1>/Logical Operator14'

     *  Logic: '<S1>/Logical Operator2'

     *  RelationalOperator: '<S8>/Compare'

     *  RelationalOperator: '<S9>/Compare'

     *  Switch: '<S1>/Switch3'

     */

    rtY.Out3 = ((((int16_T)rtU.y == 3) || ((int16_T)rtU.y == 1)) &&

                rtb_RelationalOperator4);



    /* Outport: '<Root>/Out1' incorporates:

     *  Constant: '<S1>/Constant1'

     *  Switch: '<S1>/Switch4'

     */

    rtY.Out1 = 0.0;



    /* Outport: '<Root>/Out4' incorporates:

     *  Inport: '<Root>/u1'

     *  Logic: '<S1>/Logical Operator12'

     *  Logic: '<S1>/Logical Operator4'

     *  RelationalOperator: '<S12>/Compare'

     *  RelationalOperator: '<S13>/Compare'

     *  Switch: '<S1>/Switch5'

     */

    rtY.Out4 = ((((int16_T)rtU.y == 5) || ((int16_T)rtU.y == 4)) &&

                rtb_RelationalOperator4);

  } else {

    /* Outport: '<Root>/Out2' incorporates:

     *  Inport: '<Root>/u1'

     *  Logic: '<S1>/Logical Operator'

     *  Logic: '<S1>/Logical Operator6'

     *  RelationalOperator: '<S2>/Compare'

     *  RelationalOperator: '<S3>/Compare'

     *  Switch: '<S1>/Switch'

     */

    rtY.Out2 = (real_T)(rtb_RelationalOperator && (((int16_T)rtU.y == 6) ||

      ((int16_T)rtU.y == 2)));



    /* Outport: '<Root>/Out5' incorporates:

     *  Inport: '<Root>/u1'

     *  Logic: '<S1>/Logical Operator1'

     *  Logic: '<S1>/Logical Operator7'

     *  RelationalOperator: '<S6>/Compare'

     *  RelationalOperator: '<S7>/Compare'

     *  Switch: '<S1>/Switch1'

     */

    rtY.Out5 = ((((int16_T)rtU.y == 5) || ((int16_T)rtU.y == 1)) &&

                rtb_RelationalOperator);



    /* Outport: '<Root>/Out6' incorporates:

     *  Inport: '<Root>/u1'

     *  Logic: '<S1>/Logical Operator2'

     *  Logic: '<S1>/Logical Operator8'

     *  RelationalOperator: '<S8>/Compare'

     *  RelationalOperator: '<S9>/Compare'

     *  Switch: '<S1>/Switch2'

     */

    rtY.Out6 = (real_T)((((int16_T)rtU.y == 3) || ((int16_T)rtU.y == 1)) &&

                        rtb_RelationalOperator);



    /* Outport: '<Root>/Out3' incorporates:

     *  Inport: '<Root>/u1'

     *  Logic: '<S1>/Logical Operator3'

     *  Logic: '<S1>/Logical Operator9'

     *  RelationalOperator: '<S10>/Compare'

     *  RelationalOperator: '<S11>/Compare'

     *  Switch: '<S1>/Switch3'

     */

    rtY.Out3 = ((((int16_T)rtU.y == 4) || ((int16_T)rtU.y == 6)) &&

                rtb_RelationalOperator);



    /* Outport: '<Root>/Out1' incorporates:

     *  Inport: '<Root>/u1'

     *  Logic: '<S1>/Logical Operator10'

     *  Logic: '<S1>/Logical Operator4'

     *  RelationalOperator: '<S12>/Compare'

     *  RelationalOperator: '<S13>/Compare'

     *  Switch: '<S1>/Switch4'

     */

    rtY.Out1 = (real_T)(rtb_RelationalOperator && (((int16_T)rtU.y == 5) ||

      ((int16_T)rtU.y == 4)));



    /* Outport: '<Root>/Out4' incorporates:

     *  Inport: '<Root>/u1'

     *  Logic: '<S1>/Logical Operator11'

     *  Logic: '<S1>/Logical Operator5'

     *  RelationalOperator: '<S4>/Compare'

     *  RelationalOperator: '<S5>/Compare'

     *  Switch: '<S1>/Switch5'

     */

    rtY.Out4 = (rtb_RelationalOperator && (((int16_T)rtU.y == 2) || ((int16_T)

      rtU.y == 3)));

  }



  /* End of Switch: '<S1>/Switch' */



  /* Update absolute time for base rate */

  /* The "clockTick0" counts the number of times the code of this task has

   * been executed. The absolute time is the multiplication of "clockTick0"

   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not

   * overflow during the application lifespan selected.

   */

  rtM->Timing.t[0] =

    ((time_T)(++rtM->Timing.clockTick0)) * rtM->Timing.stepSize0;



  {

    /* Update absolute timer for sample time: [6.25E-5s, 0.0s] */

    /* The "clockTick1" counts the number of times the code of this task has

     * been executed. The resolution of this integer timer is 6.25E-5, which is the step size

     * of the task. Size of "clockTick1" ensures timer will not overflow during the

     * application lifespan selected.

     */

    rtM->Timing.clockTick1++;

  }

}



/* Model initialize function */

void Subsystem_initialize(void)

{

  /* Registration code */



  /* initialize non-finites */

  rt_InitInfAndNaN(sizeof(real_T));



  {

    /* Setup solver object */

    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);

    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));

    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);

    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));

    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);

  }



  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);

  rtsiSetSolverName(&rtM->solverInfo,"FixedStepDiscrete");

  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);

  rtM->Timing.stepSize0 = 6.25E-5;

}



