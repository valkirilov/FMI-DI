
# 3 4 5

br=0
br=`expr $br + $2` # br = 4

set 3 5 7
shift # 5 7

echo $1 $2
echo $br
echo $@

for j
do
    for var
    do
        if test $br -lt $2
        then
            br=`expr $br /* $2` # 4*7 = 28
            echo $br
            echo $br $var $j >> file # 28 7 5
        else
            br=`expr $br - $2` # 4 - 7 = -3
            echo $br
            echo $br $var $j >> file # -3 7 5
        fi
    done
    echo $*
done

# echo $1 $2 $3

read a1 a2

until cat file | grep $a1
    grep $1 file
    exit
    echo END
done
echo $3
wc –l < file
echo FINAL