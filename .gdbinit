# execute all this commands everytime gdb stops
define hook-stop
	refresh
	# print line number, function name and parameters values
	frame
	# print all locals variables values
	# info locals
end

layout src
start
#b 25
#b 28
#b 40
#b 47
#b 51
#b 59
b 75
continue
display data.buffer
display *line
display data.start
display data.nl_pos
display data.read_ret
