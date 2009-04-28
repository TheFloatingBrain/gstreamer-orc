
#include <orc-float/orcfloat.h>
#include <orc/orc.h>
#include <orc/orcdebug.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static OrcStaticOpcode opcodes[];

void orc_float_sse_register_rules (void);

void
orc_float_init (void)
{
  orc_init ();

  orc_opcode_register_static (opcodes, "float");
  orc_float_sse_register_rules ();
}

#define ORC_FLOAT_READ(addr) (*(float *)(addr))
#define ORC_FLOAT_WRITE(addr,value) do{ (*(float *)(addr)) = (value); }while(0)

#define UNARY_F(name,code) \
static void \
name (OrcOpcodeExecutor *ex, void *user) \
{ \
  float a = ORC_FLOAT_READ(&ex->src_values[0]); \
  ORC_FLOAT_WRITE(&ex->dest_values[0], code ); \
}

#define BINARY_F(name,code) \
static void \
name (OrcOpcodeExecutor *ex, void *user) \
{ \
  float a = ORC_FLOAT_READ(&ex->src_values[0]); \
  float b = ORC_FLOAT_READ(&ex->src_values[1]); \
  ORC_FLOAT_WRITE(&ex->dest_values[0], code ); \
}

#define BINARY_FL(name,code) \
static void \
name (OrcOpcodeExecutor *ex, void *user) \
{ \
  float a = ORC_FLOAT_READ(&ex->src_values[0]); \
  float b = ORC_FLOAT_READ(&ex->src_values[1]); \
  ex->dest_values[0] = code ; \
}

BINARY_F(addf, a + b)
BINARY_F(subf, a - b)
BINARY_F(mulf, a * b)
BINARY_F(divf, a / b)
UNARY_F(invf, (1.0f/a) )
UNARY_F(orc_sqrtf, sqrtf(a) )
BINARY_F(maxf, (a>b) ? a : b)
BINARY_F(minf, (a<b) ? a : b)
UNARY_F(invsqrtf, 1.0f/sqrtf(a))

BINARY_FL(cmpeqf, (a == b) ? (~0) : 0)
BINARY_FL(cmpltf, (a < b) ? (~0) : 0)
BINARY_FL(cmplef, (a <= b) ? (~0) : 0)

static void
convfl (OrcOpcodeExecutor *ex, void *user)
{
  ex->dest_values[0] = ORC_FLOAT_READ(&ex->src_values[0]);
}

static void
convlf (OrcOpcodeExecutor *ex, void *user)
{
  ORC_FLOAT_WRITE(&ex->dest_values[0], ex->src_values[0]);
}

#define ORC_DOUBLE_READ(addr) (*(double *)(addr))
#define ORC_DOUBLE_WRITE(addr,value) do{ (*(double *)(addr)) = (value); }while(0)

#define UNARY_G(name,code) \
static void \
name (OrcOpcodeExecutor *ex, void *user) \
{ \
  double a = ORC_DOUBLE_READ(&ex->src_values[0]); \
  ORC_DOUBLE_WRITE(&ex->dest_values[0], code ); \
}

#define BINARY_G(name,code) \
static void \
name (OrcOpcodeExecutor *ex, void *user) \
{ \
  double a = ORC_DOUBLE_READ(&ex->src_values[0]); \
  double b = ORC_DOUBLE_READ(&ex->src_values[1]); \
  ORC_DOUBLE_WRITE(&ex->dest_values[0], code ); \
}

#define BINARY_GQ(name,code) \
static void \
name (OrcOpcodeExecutor *ex, void *user) \
{ \
  double a = ORC_DOUBLE_READ(&ex->src_values[0]); \
  double b = ORC_DOUBLE_READ(&ex->src_values[1]); \
  ex->dest_values[0] = code ; \
}

BINARY_G(addg, a + b)
BINARY_G(subg, a - b)
BINARY_G(mulg, a * b)
BINARY_G(divg, a / b)
UNARY_G(invg, (1.0f/a) )
UNARY_G(sqrtg, sqrt(a) )
BINARY_G(maxg, (a>b) ? a : b)
BINARY_G(ming, (a<b) ? a : b)
UNARY_G(invsqrtg, 1.0f/sqrt(a))

BINARY_GQ(cmpeqg, (a == b) ? (~0) : 0)
BINARY_GQ(cmpltg, (a < b) ? (~0) : 0)
BINARY_GQ(cmpleg, (a <= b) ? (~0) : 0)

static void
convgl (OrcOpcodeExecutor *ex, void *user)
{
  ex->dest_values[0] = ORC_DOUBLE_READ(&ex->src_values[0]);
}

static void
convlg (OrcOpcodeExecutor *ex, void *user)
{
  ORC_DOUBLE_WRITE(&ex->dest_values[0], ex->src_values[0]);
}

static void
convgf (OrcOpcodeExecutor *ex, void *user)
{
  ORC_FLOAT_WRITE(&ex->dest_values[0], ORC_DOUBLE_READ(&ex->src_values[0]));
}

static void
convfg (OrcOpcodeExecutor *ex, void *user)
{
  ORC_DOUBLE_WRITE(&ex->dest_values[0], ORC_FLOAT_READ(&ex->src_values[0]));
}



static OrcStaticOpcode opcodes[] = {
  { "addf", addf, NULL, 0, { 4 }, { 4, 4 } },
  { "subf", subf, NULL, 0, { 4 }, { 4, 4 } },
  { "mulf", mulf, NULL, 0, { 4 }, { 4, 4 } },
  { "divf", divf, NULL, 0, { 4 }, { 4, 4 } },
  { "invf", invf, NULL, 0, { 4 }, { 4 } },
  { "sqrtf", orc_sqrtf, NULL, 0, { 4 }, { 4 } },
  { "maxf", maxf, NULL, 0, { 4 }, { 4, 4 } },
  { "minf", minf, NULL, 0, { 4 }, { 4, 4 } },
  { "invsqrtf", invsqrtf, NULL, 0, { 4 }, { 4 } },

  { "cmpeqf", cmpeqf, NULL, 0, { 4 }, { 4, 4 } },
  { "cmpltf", cmpltf, NULL, 0, { 4 }, { 4, 4 } },
  { "cmplef", cmplef, NULL, 0, { 4 }, { 4, 4 } },

  { "convfl", convfl, NULL, 0, { 4 }, { 4 } },
  { "convlf", convlf, NULL, 0, { 4 }, { 4 } },

  { "addg", addg, NULL, 0, { 8 }, { 8, 8 } },
  { "subg", subg, NULL, 0, { 8 }, { 8, 8 } },
  { "mulg", mulg, NULL, 0, { 8 }, { 8, 8 } },
  { "divg", divg, NULL, 0, { 8 }, { 8, 8 } },
  { "invg", invg, NULL, 0, { 8 }, { 8 } },
  { "sqrtg", sqrtg, NULL, 0, { 8 }, { 8 } },
  { "maxg", maxg, NULL, 0, { 8 }, { 8, 8 } },
  { "ming", ming, NULL, 0, { 8 }, { 8, 8 } },
  { "invsqrtg", invsqrtg, NULL, 0, { 8 }, { 8 } },

  { "cmpeqg", cmpeqg, NULL, 0, { 8 }, { 8, 8 } },
  { "cmpltg", cmpltg, NULL, 0, { 8 }, { 8, 8 } },
  { "cmpleg", cmpleg, NULL, 0, { 8 }, { 8, 8 } },

  { "convgl", convgl, NULL, 0, { 4 }, { 8 } },
  { "convlg", convlg, NULL, 0, { 8 }, { 4 } },

  { "convgf", convgf, NULL, 0, { 4 }, { 8 } },
  { "convfg", convfg, NULL, 0, { 8 }, { 4 } },

  { "" }
};

