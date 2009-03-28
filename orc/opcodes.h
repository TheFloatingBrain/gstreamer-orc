UNARY_SB(absb, "ORC_ABS(%s)")
BINARY_SB(addb, "%s + %s")
BINARY_SB(addssb, "ORC_CLAMP_SB(%s + %s)")
BINARY_UB(addusb, "ORC_CLAMP_UB(%s + %s)")
BINARY_SB(andb, "%s & %s")
BINARY_SB(andnb, "%s & (~%s)")
BINARY_SB(avgsb, "(%s + %s + 1)>>1")
BINARY_UB(avgub, "(%s + %s + 1)>>1")
BINARY_SB(cmpeqb, "(%s == %s) ? (~0) : 0")
BINARY_SB(cmpgtsb, "(%s > %s) ? (~0) : 0")
UNARY_SB(copyb, "%s")
BINARY_SB(maxsb, "ORC_MAX(%s, %s)")
BINARY_UB(maxub, "ORC_MAX(%s, %s)")
BINARY_SB(minsb, "ORC_MIN(%s, %s)")
BINARY_UB(minub, "ORC_MIN(%s, %s)")
BINARY_SB(mullb, "(%s * %s) & 0xff")
BINARY_SB(mulhsb, "(%s * %s) >> 8")
BINARY_UB(mulhub, "(%s * %s) >> 8")
BINARY_SB(orb, "%s | %s")
BINARY_SB(shlb, "%s << %s")
BINARY_SB(shrsb, "%s >> %s")
BINARY_UB(shrub, "((uint8_t)%s) >> %s")
UNARY_SB(signb, "ORC_CLAMP(%s,-1,1)")
BINARY_SB(subb, "%s - %s")
BINARY_SB(subssb, "ORC_CLAMP_SB(%s - %s)")
BINARY_UB(subusb, "ORC_CLAMP_UB((uint8_t)%s - (uint8_t)%s)")
BINARY_SB(xorb, "%s ^ %s")

UNARY_SW(absw, "ORC_ABS(%s)")
BINARY_SW(addw, "%s + %s")
BINARY_SW(addssw, "ORC_CLAMP_SW(%s + %s)")
BINARY_UW(addusw, "ORC_CLAMP_UW(%s + %s)")
BINARY_SW(andw, "%s & %s")
BINARY_SW(andnw, "%s & (~%s)")
BINARY_SW(avgsw, "(%s + %s + 1)>>1")
BINARY_UW(avguw, "(%s + %s + 1)>>1")
BINARY_SW(cmpeqw, "(%s == %s) ? (~0) : 0")
BINARY_SW(cmpgtsw, "(%s > %s) ? (~0) : 0")
UNARY_SW(copyw, "%s")
BINARY_SW(maxsw, "ORC_MAX(%s, %s)")
BINARY_UW(maxuw, "ORC_MAX(%s, %s)")
BINARY_SW(minsw, "ORC_MIN(%s, %s)")
BINARY_UW(minuw, "ORC_MIN(%s, %s)")
BINARY_SW(mullw, "(%s * %s) & 0xffff")
BINARY_SW(mulhsw, "(%s * %s) >> 16")
BINARY_UW(mulhuw, "(%s * %s) >> 16")
BINARY_SW(orw, "%s | %s")
BINARY_SW(shlw, "%s << %s")
BINARY_SW(shrsw, "%s >> %s")
BINARY_UW(shruw, "%s >> %s")
UNARY_SW(signw, "ORC_CLAMP(%s,-1,1)")
BINARY_SW(subw, "%s - %s")
BINARY_SW(subssw, "ORC_CLAMP_SW(%s - %s)")
BINARY_UW(subusw, "ORC_CLAMP_UW(%s - %s)")
BINARY_SW(xorw, "%s ^ %s")

UNARY_SL(absl, "ORC_ABS(%s)")
BINARY_SL(addl, "%s + %s")
BINARY_SL(addssl, "ORC_CLAMP_SL((int64_t)%s + (int64_t)%s)")
BINARY_UL(addusl, "ORC_CLAMP_UL((uint64_t)%s + (uint64_t)%s)")
BINARY_SL(andl, "%s & %s")
BINARY_SL(andnl, "%s & (~%s)")
BINARY_SL(avgsl, "(%s + %s + 1)>>1")
BINARY_UL(avgul, "(%s + %s + 1)>>1")
BINARY_SL(cmpeql, "(%s == %s) ? (~0) : 0")
BINARY_SL(cmpgtsl, "(%s > %s) ? (~0) : 0")
UNARY_SL(copyl, "%s")
BINARY_SL(maxsl, "ORC_MAX(%s, %s)")
BINARY_UL(maxul, "ORC_MAX(%s, %s)")
BINARY_SL(minsl, "ORC_MIN(%s, %s)")
BINARY_UL(minul, "ORC_MIN(%s, %s)")
BINARY_SL(mulll, "(%s * %s) & 0xffffffff")
BINARY_SL(mulhsl, "((int64_t)%s * (int64_t)%s) >> 32")
BINARY_UL(mulhul, "((uint64_t)%s * (uint64_t)%s) >> 32")
BINARY_SL(orl, "%s | %s")
BINARY_SL(shll, "%s << %s")
BINARY_SL(shrsl, "%s >> %s")
BINARY_UL(shrul, "%s >> %s")
UNARY_SL(signl, "ORC_CLAMP(%s,-1,1)")
BINARY_SL(subl, "%s - %s")
BINARY_SL(subssl, "ORC_CLAMP_SL((int64_t)%s - (int64_t)%s)")
BINARY_UL(subusl, "ORC_CLAMP_UL((uint64_t)%s - (uint64_t)%s)")
BINARY_SL(xorl, "%s ^ %s")

BINARY_BW(convsbw, "%s")
BINARY_BW(convubw, "(uint8_t)%s")
BINARY_WL(convswl, "%s")
BINARY_WL(convuwl, "(uint16_t)%s")
BINARY_WB(convwb, "%s")
BINARY_WB(convssswb, "ORC_CLAMP_SB(%s)")
BINARY_WB(convsuswb, "ORC_CLAMP_UB(%s)")
BINARY_WB(convusswb, "ORC_CLAMP_SB(%s)")
BINARY_WB(convuuswb, "ORC_CLAMP_UB(%s)")
BINARY_LW(convlw, "%s")
BINARY_LW(convssslw, "ORC_CLAMP_SW(%s)")
BINARY_LW(convsuslw, "ORC_CLAMP_UW(%s)")
BINARY_LW(convusslw, "ORC_CLAMP_SW(%s)")
BINARY_LW(convuuslw, "ORC_CLAMP_UW(%s)")

BINARY_BW(mulsbw, "%s * %s")
BINARY_BW(mulubw, "%s * %s")
BINARY_WL(mulswl, "%s * %s")
BINARY_WL(muluwl, "%s * %s")
