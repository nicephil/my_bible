SOURCE =  docbook.xml
COMPILER = xsltproc

HTML_PARAM = html_param.xsl
HTML_ARG = -o ./html

PDF_PARAM = pdf_param.xsl
BOOK_NAME = docbook
PDF_ARG = $(BOOK_NAME).pdf
FOP_COMPILER = fop
FOP_CONFIG = -c /etc/fop/zhfop.conf
#FOP_CONFIG=

html:$(SOURCE) $(HTML_PARAM)
	$(COMPILER) $(HTML_ARG) $(HTML_PARAM) $(SOURCE)
	cp -rvf images ./html/images

pdf:$(SOURCE) $(PDF_PARAM)
	$(COMPILER) -o $(BOOK_NAME).fo $(PDF_PARAM) $(SOURCE)
	$(FOP_COMPILER) $(FOP_CONFIG) $(BOOK_NAME).fo $(PDF_ARG)

clean:
	rm -rvf ./html *.html *.fo *.pdf

distclean:clean
