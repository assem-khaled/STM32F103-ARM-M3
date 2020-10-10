/*********************************/
/* Author   : Assem Khaled       */
/* Date     : 29 JUL 2020        */
/* Version  : V02                */
/*********************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT(VAR,BIT)	VAR |= (1 << (BIT))
#define CLR_BIT(VAR,BIT)	VAR &= ~(1 << (BIT))
#define GET_BIT(VAR,BIT)	((VAR >> BIT) & 1)
#define TOG_BIT(VAR,BIT)	VAR ^= (1 << (BIT))
#define ASSIGN_BIT(Var,BitNo,Val) (Val==0)? CLR_BIT(Var,BitNo):(SET_BIT(Var,BitNo))


#endif
