class SortedGraphGenerator

	def self.gen_graph output, nodes, edge_prob = 0.5

		1.upto(nodes) {|node_num|

			output << node_num

			1.upto(nodes) {|node_num|

				if rand >= 1 - edge_prob
					output << " #{node_num}"
				end

			}

			output.puts

		}

	end

end


if $0 == __FILE__

	file_path = ARGV[0].nil? ? './test_graph.txt' : ARGV[0]

	nodes = ARGV[1].nil? ? 20 : ARGV[1].to_i

	edge_prob = ARGV[2].nil? ? 0.5 : ARGV[2].to_f

	the_graph_file = File.open file_path, 'w'

	SortedGraphGenerator.gen_graph the_graph_file, nodes, edge_prob

	the_graph_file.close

end