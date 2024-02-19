//
//  CFastFind.h
//  CFastFind
//
//  Created by Linus Henze.
//  Copyright © 2021/2022 Pinauten GmbH. All rights reserved.
//

#ifndef CFastFind_h
#define CFastFind_h

#include <stdbool.h>
#include <stdint.h>
#include <device/device_types.h>
#include <CoreFoundation/CoreFoundation.h>
#include "iokit.h"

bool CFastFind(const void* __nonnull buffer, size_t bufLen, const uint32_t* __nonnull insts, size_t instLen, size_t* __nonnull offset);

uint64_t aarch64_emulate_adr(uint32_t instruction, uint64_t pc);
uint64_t aarch64_emulate_branch(uint32_t instruction, uint64_t pc);
uint64_t aarch64_emulate_b(uint32_t instr, uint64_t pc);
uint64_t aarch64_emulate_bl(uint32_t instr, uint64_t pc);
uint64_t aarch64_emulate_compare_branch(uint32_t instruction, uint64_t pc);
uint64_t aarch64_emulate_conditional_branch(uint32_t instruction, uint64_t pc);
uint64_t aarch64_emulate_adrp(uint32_t instruction, uint64_t pc);
bool aarch64_emulate_add_imm(uint32_t instruction, uint32_t * __nonnull dst, uint32_t * __nonnull src, uint32_t * __nonnull imm);
uint64_t aarch64_emulate_adrp_add(uint32_t instruction, uint32_t addInstruction, uint64_t pc);
uint64_t aarch64_emulate_adrp_ldr(uint32_t instruction, uint32_t ldrInstruction, uint64_t pc);
uint64_t aarch64_emulate_ldr(uint32_t ldrInstruction, uint64_t pc);
uint64_t aarch64_get_ldr_off(uint32_t ldrInstruction);
uint64_t find_xref_to(const void * __nonnull start, const void * __nonnull end, uint64_t xrefTo, uint64_t pc);
uint64_t find_xref_to_data(const void * __nonnull start, const void * __nonnull end, uint64_t xrefTo, uint64_t pc);
uint64_t find_xref_branch(const void * __nonnull start, const void * __nonnull end, uint64_t xrefTo, uint64_t pc);

// Also define some IOKit stuff...

#endif /* CFastFind_h */
