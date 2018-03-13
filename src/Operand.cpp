#include "Operand.hpp"

template<> int Operand<int8_t>::getPrecision(void) const {return 1;}
template<> eOperandType Operand<int8_t>::getType(void) const {return eOperandType::Int8;}

template<> int Operand<int16_t>::getPrecision(void) const {return 2;}
template<> eOperandType Operand<int16_t>::getType(void) const {return eOperandType::Int16;}

template<> int Operand<int32_t>::getPrecision(void) const {return 3;}
template<> eOperandType Operand<int32_t>::getType(void) const {return eOperandType::Int32;}

template<> int Operand<float>::getPrecision(void) const {return 4;}
template<> eOperandType Operand<float>::getType(void) const {return eOperandType::Float;}

template<> int Operand<double>::getPrecision(void) const {return 5;}
template<> eOperandType Operand<double>::getType(void) const {return eOperandType::Double;}
