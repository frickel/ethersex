TOPDIR ?= ../..
include $(TOPDIR)/.config

$(ECMD_PARSER_SUPPORT)_SRC += protocols/ecmd/parser.c
$(ALIASCMD_SUPPORT)_SRC += protocols/ecmd/aliascmd.c
$(ECMD_SCRIPT_SUPPORT)_SRC += protocols/ecmd/scripting.c
$(ECMD_SPEED_SUPPORT)_SRC += protocols/ecmd/speed_parser.c

##############################################################################
# generic fluff
include $(TOPDIR)/scripts/rules.mk



##############################################################################
# alias_defs fluff

protocols/ecmd/aliascmd.c: protocols/ecmd/alias_defs.c
protocols/ecmd/alias_defs.c: protocols/ecmd/alias_magic.m4 protocols/ecmd/alias_defs.m4
	$(M4) $^ > $@.tmp
	mv -f $@.tmp $@

CLEAN_FILES += protocols/ecmd/alias_defs.c



##############################################################################
# np_simple cruft

# If (full-featured) portio is disabled, but named_pin enabled, we
# need to do the named_pin simple awk/m4 hackery ...
ifneq ($(PORTIO_SUPPORT),y)
ifeq ($(NAMED_PIN_SUPPORT),y)
named_pin_simple_files=$(TOPDIR)/core/portio/np_simple.m4 $(TOPDIR)/protocols/ecmd/np_simple_glue.m4
endif
endif

protocols/ecmd/np_simple_glue.m4: $(NP_CONFIG) $(TOPDIR)/core/portio/np_simple_glue.awk
	@grep -v -e "^#" < $< | gawk -f $(TOPDIR)/core/portio/np_simple_glue.awk > $@

CLEAN_FILES += protocols/ecmd/np_simple_glue.m4



##############################################################################
# ecmd_defs fluff

protocols/ecmd/parser.c: protocols/ecmd/ecmd_defs.c
protocols/ecmd/ecmd_defs.c: protocols/ecmd/ecmd_magic.m4 protocols/ecmd/ecmd_defs.m4 $(named_pin_simple_files)
	@m4 $^ > $@.tmp
	@mv -f $@.tmp $@

CLEAN_FILES += protocols/ecmd/ecmd_defs.c



##############################################################################
# np_simple cruft

wiki.txt: wiki.m4 ecmd_defs.m4
	@m4 $^ | perl -ne 'unless(m/^\s*$$/){s/^\s+//;s/\s+$$//;print "$$_\n"}' > $@.tmp
	@mv -f $@.tmp $@

CLEAN_FILES += protocols/ecmd/wiki.txt