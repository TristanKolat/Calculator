# -*-Makefile-*-
#----------------------------------------------------------------------------
#       Make Workspace
#
# 
#
# This file was generated by MPC.  Any changes made directly to
# this file will be lost the next time it is generated.
#
# MPC Command:
# ../MPC/mwc.pl -type make
#
#----------------------------------------------------------------------------


all: calculator

depend: calculator-depend

clean generated realclean check-syntax $(CUSTOM_TARGETS):
	@"$(MAKE)" -f Makefile.calculator $(@)

.PHONY: calculator
calculator:
	@"$(MAKE)" -f Makefile.calculator all

.PHONY: calculator-depend
calculator-depend:
	@"$(MAKE)" -f Makefile.calculator depend

project_name_list:
	@echo calculator
