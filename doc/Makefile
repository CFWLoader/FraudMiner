all:
	pdflatex streaming_graph_partitioning.tex 	&& \
	bibtex	streaming_graph_partitioning	&& \
	pdflatex streaming_graph_partitioning.tex 	&& \
	pdflatex streaming_graph_partitioning.tex

clean:
	rm -rf 	streaming_graph_partitioning.log \
		streaming_graph_partitioning.bbl \
		streaming_graph_partitioning.aux \
		streaming_graph_partitioning.blg \
		streaming_graph_partitioning.toc \
		texput.log

distclean:
	make clean && rm -rf ./streaming_graph_partitioning.pdf
#	rm -rf 	streaming_graph_partitioning.log \
	       	streaming_graph_partitioning.pdf \
		streaming_graph_partitioning.bbl \
		streaming_graph_partitioning.aux \
		streaming_graph_partitioning.blg \
		textput.log
