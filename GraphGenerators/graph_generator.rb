require 'set'
# Graph format: [Source_id, source_value, [[dest_id, edge_value], [dest_id, edge_value]...]]
class GraphGenerator

  def gen_graph_to_file file_path, **parameters

    node_limit = nil

    edge_limit = nil

    node_value_limit = Float::INFINITY

    unless parameters[:node_limit].nil?

      node_limit = parameters[:node_limit]

    end

    unless parameters[:edge_limit].nil?

      edge_limit = parameters[:edge_limit]

    end

    unless parameters[:node_value_limit].nil?

      node_value_limit = parameters[:node_value_limit]

    end

    target_file = open(file_path, 'w')

    1.upto(node_limit) { |node_num|

      #print "SRC: #{node_num}, SRC_VAL: #{rand(node_num)}, Edges: #{gen_edges node_num, edge_limit, node_limit}\n"
      target_file.print "[#{node_num},#{rand(node_num)},[#{gen_edges node_num, edge_limit, node_limit}]]\n"

    }

    target_file.close

  end

  def gen_graph **parameters

    node_limit = nil

    edge_limit = nil

    node_value_limit = Float::INFINITY

    unless parameters[:node_limit].nil?

      node_limit = parameters[:node_limit]

    end

    unless parameters[:edge_limit].nil?

      edge_limit = parameters[:edge_limit]

    end

    unless parameters[:node_value_limit].nil?

      node_value_limit = parameters[:node_value_limit]

    end

    1.upto(node_limit) { |node_num|

      #print "SRC: #{node_num}, SRC_VAL: #{rand(node_num)}, Edges: #{gen_edges node_num, edge_limit, node_limit}\n"
      print "[#{node_num},#{rand(node_num)},[#{gen_edges node_num, edge_limit, node_limit}]]\n"

    }

  end

  def gen_edges source_id, edge_limit, id_limit

    edge_counts = if edge_limit.nil? then
                    rand(id_limit)
                  else
                    rand(edge_limit)
                  end

    ret_str = ""

    1.upto(edge_counts) {

      gen_tar_id = rand(id_limit)

      if source_id == gen_tar_id then
        next
      end

      ret_str += "[#{gen_tar_id},#{rand(1..edge_counts)}],"

    }

    ret_str.chop!

  end

  def gen_edge_list_to_file file_path, node_id_limit, edge_quantity_limit

    save_file = open file_path, 'w'

    1.upto(node_id_limit) { |src_node_id|

      edge_num_to_gen = rand edge_quantity_limit

      tagged_nodes = Set.new

      tagged_nodes.add src_node_id

      1.upto(edge_num_to_gen) {

        tag = rand(node_id_limit)

        unless tagged_nodes.include? tag

          save_file.print "#{src_node_id} #{tag}\n"
          # print "#{src_node_id} #{tag}\n"

          tagged_nodes.add tag

        end
      }

    }

    save_file.close

  end

end


def gen_json_graph

  file_path = './test_graph.txt'

  node_limit = 100

  edge_limit = 10

  unless ARGV[1].nil?

    file_path = ARGV[1]

  end

  unless ARGV[2].nil?

    node_limit = ARGV[2].to_i

  end

  unless ARGV[3].nil?

    edge_limit = ARGV[3].to_i

  end

  jgg = GraphGenerator.new

  #jgg.gen_graph node_limit: 20, edge_limit: 20
  jgg.gen_graph_to_file file_path, node_limit: node_limit, edge_limit: edge_limit

end


def gen_edgelist

  file_path = './test_graph.txt'

  node_limit = 100

  edge_limit = 10

  unless ARGV[1].nil?

    file_path = ARGV[1]

  end

  unless ARGV[2].nil?

    node_limit = ARGV[2].to_i

  end

  unless ARGV[3].nil?

    edge_limit = ARGV[3].to_i

  end

  jgg = GraphGenerator.new

  #jgg.gen_graph node_limit: 20, edge_limit: 20
  jgg.gen_edge_list_to_file file_path, node_limit, edge_limit

end


if $0 == __FILE__

  case ARGV[0]

    when 'adjlist' then
      gen_json_graph

    when 'edgelist' then
      gen_edgelist

    else

      print 'Filetype: adjlist, edgelist'

  end

end