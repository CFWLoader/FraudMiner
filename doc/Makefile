TARGET_LIST=*.log *.bbl *.aux *.blg *.toc

all: sgp gr tt2 opga

sgp:
	pdflatex streaming_graph_partitioning.tex
	bibtex	streaming_graph_partitioning
	pdflatex streaming_graph_partitioning.tex
	pdflatex streaming_graph_partitioning.tex

gr:
	pdflatex graph_resolver.tex
	bibtex graph_resolver
	pdflatex graph_resolver.tex
	pdflatex graph_resolver.tex

tt2:
	pdflatex test_type02.tex

opga:
	pdflatex overview_of_parallel_graph_algorithms.tex
	bibtex overview_of_parallel_graph_algorithms
	pdflatex overview_of_parallel_graph_algorithms.tex
	pdflatex overview_of_parallel_graph_algorithms.tex

clean:
	@rm -rf ${TARGET_LIST}
#	@rm -rf 	streaming_graph_partitioning.log \
		streaming_graph_partitioning.bbl \
		streaming_graph_partitioning.aux \
		streaming_graph_partitioning.blg \
		streaming_graph_partitioning.toc \
		texput.log

distclean:
	@make clean
	@rm -rf ./streaming_graph_partitioning.pdf ./graph_resolver.pdf ./test_type02.pdf ./overview_of_parallel_graph_algorithms.pdf
#	rm -rf 	streaming_graph_partitioning.log \
	       	streaming_graph_partitioning.pdf \
		streaming_graph_partitioning.bbl \
		streaming_graph_partitioning.aux \
		streaming_graph_partitioning.blg \
		textput.log

list:
	@echo -e "Target Alias:\n \
		spg - streaming_graph_partitioning\n \
		gr - graph_resolver\n \
		cdb - community_detection_base\n \
		opga - overview_of_parallel_graph_algorithms"