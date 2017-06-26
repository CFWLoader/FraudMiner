class GraphChiPreprocessor

  def renumber_edges src_file_path, target_file_path

    input = open src_file_path

    output = open target_file_path, 'w'

    rehash = {}

    counter = 1

    input.each { |line|

      pair = line.split

      src_node = pair[0].to_i

      tag_node = pair[1].to_i

      unless rehash.has_key? src_node

        rehash[src_node] = counter

        counter += 1

      end

      unless rehash.has_key? tag_node

        rehash[tag_node] = counter

        counter += 1

      end

      output.print "#{rehash[src_node]} #{rehash[tag_node]}\n"

    }

    input.close

    output.close

  end

end


if $0 == __FILE__

  if ARGV[0].nil?

    raise Exception 'Please specify an input.'

  end

  if ARGV[1].nil?

    raise Exception 'Please specify an output.'

  end

  src_file_path = ARGV[0]

  tag_file_path = ARGV[1]

  preprocessor = GraphChiPreprocessor.new

  preprocessor.renumber_edges src_file_path, tag_file_path

end