EXTRA_DIST	+=  \
		doc/man/syslog-ng.8.xml \
		doc/man/syslog-ng.conf.5.xml \
		doc/man/pdbtool.1.xml \
		doc/man/loggen.1.xml \
		doc/man/syslog-ng-ctl.1.xml \
		$(man_MANS) \
		doc/security/bof-2002-09-27.txt \
		doc/security/dos-2000-11-22.txt \
		doc/xsd/patterndb-1.xsd \
		doc/xsd/patterndb-2.xsd \
		doc/xsd/patterndb-3.xsd \
		doc/xsd/patterndb-4.xsd

xsddir		= $(datadir)/xsd
xsd_DATA	= \
		doc/xsd/patterndb-1.xsd \
		doc/xsd/patterndb-2.xsd \
		doc/xsd/patterndb-3.xsd \
		doc/xsd/patterndb-4.xsd

# NOTE: this uses a hard-coded path for the XSL stylesheets, but the
# end-result is also included in the tarball. If so need be, this can
# be overridden from the make command line or via the environment.
XSL_STYLESHEET = /usr/share/xml/docbook/stylesheet/docbook-xsl/manpages/docbook.xsl

sysconfdir_e = $(shell echo "${sysconfdir}" | sed -e "s,-,\\\\\\\\-,g")
prefix_e = $(shell echo "${prefix}" | sed -e "s,-,\\\\\\\\-,g")

manpages	= \
		doc/man/syslog-ng.8 \
		doc/man/syslog-ng.conf.5 \
		doc/man/pdbtool.1 \
		doc/man/loggen.1 \
		doc/man/syslog-ng-ctl.1

if ENABLE_MAN_PAGES
man_MANS	+= ${manpages}

doc/man/%: doc/man/%.xml
	$(AM_V_GEN)$(XSLTPROC) --xinclude --output $@ ${XSL_STYLESHEET} $<
	$(AM_V_at)sed -e 's,/opt/syslog\\*-ng/etc,$(sysconfdir_e),g' -e 's,/opt/syslog\\*-ng/,$(prefix_e)/,g' <$@ >$@.tmp && mv $@.tmp $@
else
EXTRA_DIST	+= ${manpages}
endif
