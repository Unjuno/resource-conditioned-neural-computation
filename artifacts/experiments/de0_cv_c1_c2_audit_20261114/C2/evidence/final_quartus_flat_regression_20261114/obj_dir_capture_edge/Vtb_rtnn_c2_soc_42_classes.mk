# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vtb_rtnn_c2_soc_42.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 1
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 1
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 0
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vtb_rtnn_c2_soc_42 \
	Vtb_rtnn_c2_soc_42___024root__DepSet_h09743073__0 \
	Vtb_rtnn_c2_soc_42___024root__DepSet_h09743073__1 \
	Vtb_rtnn_c2_soc_42___024root__DepSet_h09743073__2 \
	Vtb_rtnn_c2_soc_42___024root__DepSet_h09743073__3 \
	Vtb_rtnn_c2_soc_42___024root__DepSet_h21a8ed6a__0 \
	Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7__DepSet_he675540a__0 \
	Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8__DepSet_hafaac2ef__0 \
	Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8__DepSet_h7c525bf6__0 \
	Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9__DepSet_hfc4e3a2a__0 \
	Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9__DepSet_h4c6ee3b3__0 \
	Vtb_rtnn_c2_soc_42__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vtb_rtnn_c2_soc_42__ConstPool_0 \
	Vtb_rtnn_c2_soc_42___024root__Slow \
	Vtb_rtnn_c2_soc_42___024root__DepSet_h09743073__0__Slow \
	Vtb_rtnn_c2_soc_42___024root__DepSet_h21a8ed6a__0__Slow \
	Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7__Slow \
	Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7__DepSet_he675540a__0__Slow \
	Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7__DepSet_h32a7d1d3__0__Slow \
	Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8__Slow \
	Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8__DepSet_hafaac2ef__0__Slow \
	Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8__DepSet_h7c525bf6__0__Slow \
	Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9__Slow \
	Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9__DepSet_hfc4e3a2a__0__Slow \
	Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9__DepSet_h4c6ee3b3__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vtb_rtnn_c2_soc_42__Syms \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_timing \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
