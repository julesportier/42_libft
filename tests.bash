#!/bin/bash

of='test.txt'

exe='test.out'

limits=(
'012345678'
$'012345678\n'
'0123456789'
$'0123456789\n'
'01234567890'
$'01234567890\n'
'0123456789012345678'
$'0123456789012345678\n'
'01234567890123456789'
$'01234567890123456789\n'
'012345678901234567890'
$'012345678901234567890\n'
$'012345678\n012345678\n'
$'012345678\n0123456789'
$'012345678\n0123456789\n'
$'0123456789\n01234567\n'
$'0123456789\n012345678'
$'0123456789\n012345678\n'
)

# cc -Wall -Wextra -Werror -g3 -D BUFFER_SIZE=1 *.c -o $exe
# echo "BUFFER_SIZE=1"
# for str in "${limits[@]}"
# do
# 	echo -n "${str}" > $of
# 	echo -n 'test.txt -> \n' ; cat $of | cat -e ; echo '---'
# 	./$exe | cat -e
# 	echo $'\n'
# done

# cc -Wall -Wextra -Werror -g3 -D BUFFER_SIZE=10 *.c -o $exe
# echo "BUFFER_SIZE=10"
# for str in "${limits[@]}"
# do
# 	echo -n "${str}" > $of
# 	echo -n $'test.txt -> \n' ; cat $of | cat -e ; echo '---'
# 	./$exe | cat -e
# 	echo $'\n'
# done

cc -Wall -Wextra -Werror -g3 -D BUFFER_SIZE=1000000 *.c -o $exe
echo "BUFFER_SIZE=1000000"
for str in "${limits[@]}"
do
	echo -n "${str}" > $of
	echo -n $'test.txt -> \n' ; cat $of | cat -e ; echo '---'
	./$exe | cat -e
	echo $'\n'
done

rm $exe
